//#include<modint/MontgomeryModInt.cpp>
//#include<poly/NTTmint.cpp>

template<bool fast_mul = true>
struct bigint {
  int sgn;
  vector<int> val;
  static constexpr int LOG = fast_mul ? 1 : 9;
  static constexpr int W = fast_mul ? 10 : 1'000'000'000;

  bigint(string s = "0") {
    if (!s.empty() and s[0] == '-') {
      sgn = -1;
      s.erase(s.begin());
    } else {
      sgn = 1;
    }
    s.insert(0, (LOG - ssize(s) % LOG) % LOG, '0');
    if (s.empty()) s = string(LOG, '0');
    val.resize(size(s) / LOG);
    ranges::reverse(s);
    for(int i = ssize(s) - 1; i >= 0; i--)
      val[i / LOG] = val[i / LOG] * 10 + (s[i] - '0');
  }

  int log10() {
    assert(sgn == 1);
    int x = LOG * (ssize(val) - 1), y = val.back();
    while(y) x++, y /= 10;
    return x - 1;
  }

  void norm() {
    if (sgn == -1 and ssize(val) == 1 and val[0] == 0)
      sgn = 1;
  }

  bool abs_less(const bigint &b) const {
    if (size(val) != size(b.val))
      return size(val) < size(b.val);
    for(int i = ssize(val) - 1; i >= 0; i--)
      if (val[i] != b.val[i])
        return val[i] < b.val[i];
    return false;
  }

  bigint& operator+=(const bigint &b) {
    if (sgn != b.sgn) {
      *this -= -b;
    } else if (abs_less(b)) {
      *this = b + *this;
    } else {
      for(int i = 0; i < min(ssize(val), ssize(b.val)); i++) {
        val[i] += b.val[i];
        if (int q = val[i] / W; q > 0) {
          if (i + 1 == ssize(val)) val.emplace_back();
          val[i] -= q * W, val[i + 1] += q;
        }
      }
      int j = min(ssize(val), ssize(b.val));
      while(j < ssize(val) and val[j] >= W) {
        int q = val[j] / W;
        if (j + 1 == ssize(val)) val.emplace_back();
        val[j] -= q * W, val[j + 1] += q, j++;
      }
    }
    norm();
    return *this;
  }

  bigint& operator-=(const bigint &b) {
    if (sgn != b.sgn) {
      *this += -b;
    } else if (abs_less(b)) {
      *this = b - *this, sgn = -sgn;
    } else {
      for(int i = 0; i < min(ssize(val), ssize(b.val)); i++) {
        val[i] -= b.val[i];
        if (val[i] < 0)
          val[i] += W, val[i + 1] -= 1;
      }
      int j = min(ssize(val), ssize(b.val));
      while(j < ssize(val) and val[j] < 0)
        val[j] += W, val[j + 1] -= 1, j++;
      while(ssize(val) > 1 and val.back() == 0) val.pop_back();
    }
    norm();
    return *this;
  }

  bigint& operator*=(const bigint &b) {
    if constexpr (LOG == 1) {
      static NTT ntt;
      vector<mint> c(size(val)), d(size(b.val));
      for(int i = 0; i < ssize(c); i++) c[i] = val[i];
      for(int i = 0; i < ssize(d); i++) d[i] = b.val[i];
      c = ntt.conv(c, d);
      vector<int> tmp(ssize(c));
      for(int i = 0; i < ssize(c); i++)
        tmp[i] = c[i].get();
      for(int i = 0; i < ssize(tmp); i++) {
        if (int q = tmp[i] / W; q > 0) {
          if (i + 1 == ssize(tmp)) tmp.emplace_back();
          tmp[i] -= q * W, tmp[i + 1] += q;
        }
      }
      val.swap(tmp);
    } else {
      vector<int> tmp(ssize(val) + ssize(b.val) + 1);
      for(int i = 0; i < ssize(val); i++) {
        for(int j = 0; j < ssize(b.val); j++) {
          if (int q = tmp[i + j] / W; q > 0)
            tmp[i + j] -= q * W, tmp[i + j + 1] += q;
          ll x = (ll)val[i] * b.val[j];
          tmp[i + j] += x % W, tmp[i + j + 1] += x / W;
          if (int q = tmp[i + j] / W; q > 0)
            tmp[i + j] -= q * W, tmp[i + j + 1] += q;
        }
      }
      val.swap(tmp);
    }
    while(ssize(val) > 1 and val.back() == 0) val.pop_back();
    sgn *= b.sgn;
    norm();
    return *this;
  }

  bool operator<(const bigint &b) {
    if (sgn != b.sgn) return sgn == -1;
    else if (sgn == 1) return abs_less(b);
    else return b.abs_less(*this);
  }
  bool operator>(const bigint &b) { return b < *this; }
  bool operator<=(const bigint &b) { return !(*this > b); }
  bool operator>=(const bigint &b) { return !(*this < b); }
  bool operator==(const bigint &b) { return sgn == b.sgn and val == b.val; }
  friend bigint operator+(bigint a, bigint b) { return a += b; }
  friend bigint operator-(bigint a, bigint b) { return a -= b; }
  friend bigint operator*(bigint a, bigint b) { return a *= b; }

  bigint operator-() const {
    bigint b = *this;
    b.sgn = -b.sgn;
    return b;
  }

  string to_string() const {
    string s;
    for(int i = 0; i < ssize(val); i++) {
      int x = val[i];
      for(int j = 0; j < LOG; j++)
        s += '0' + (x % 10), x /= 10;
    }
    while(ssize(s) > 1 and s.back() == '0') s.pop_back();
    if (sgn == -1) s += '-';
    ranges::reverse(s);
    return s;
  }

  friend ostream& operator<<(ostream& os, const bigint& b) {
    return os << b.to_string();
  }
};
