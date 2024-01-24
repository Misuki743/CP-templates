//note: inversion only works when MOD is a prime

struct mint {
  static const long long MOD = 998244353;
  long long _val;

  mint(long long init = 0) {
    _val = init % MOD;
    (*this).norm();
  }

  mint POW(long long index) {
    if (index == 0)
      return mint(1ll);
    mint base = *this;
    mint res = (base == 0ll ? 0ll : 1ll);
    while(index) {
      if (index & 1)
        res *= base;
      base *= base, index >>= 1;
    }
    return res;
  }

  mint inv() { return (*this).POW(MOD - 2); }

  mint& norm() {
    if (_val >= MOD)
      _val -= MOD;
    if (_val < 0)
      _val += MOD;
    return *this;
  }

  mint& operator+=(mint b) {
    _val += b._val;
    return (*this).norm();
  }
  mint& operator-=(mint b) {
    _val -= b._val;
    return (*this).norm();
  }
  mint& operator*=(mint b) {
    _val = (_val * b._val) % MOD;
    return *this;
  }
  mint& operator/=(mint b) {
    _val = (_val * b.inv()._val) % MOD;
    return *this;
  }

  mint& operator++() {
    _val += 1;
    return (*this).norm();
  }
  mint& operator--() {
    _val -= 1;
    return (*this).norm();
  }
  mint operator++(signed) {
    mint tmp = *this;
    ++(*this);
    return tmp;
  }
  mint operator--(signed) {
    mint tmp = *this;
    --(*this);
    return tmp;
  }

  mint operator-() { return mint(-_val); }
  bool operator==(mint b) { return _val == b._val; }
  bool operator!=(mint b) { return _val != b._val; }
  
  friend mint operator+(mint a, mint b) { return a += b; }
  friend mint operator-(mint a, mint b) { return a -= b; }
  friend mint operator*(mint a, mint b) { return a *= b; }
  friend mint operator/(mint a, mint b) { return a /= b; }

  friend ostream& operator<<(ostream& os, const mint& b) {
    return os << b._val;
  }
  friend istream& operator>>(istream& is, mint& b) {
    long long val;
    is >> val;
    b = mint(val);
    return is;
  }
};
