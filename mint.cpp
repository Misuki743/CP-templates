//////////////////////////////////////////////////
//template name: mint
//author: __Shioko(Misuki)
//last update: 2022/06/01
//note: inversion only works when MOD is a prime
struct mint {
  static const long long MOD = 1e9 + 7;
  long long _val;

  mint() : _val(0) {}
  mint(long long init) {
    init %= MOD;
    if (init < 0)
      init += MOD;
    _val = init;
  }

  mint POW(long long index) {
    long long base = _val;
    if (index == 0)
      return mint(1ll);
    long long res = (base == 0ll ? 0ll : 1ll);
    while(index) {
      if (index & 1)
        res = (res * base) % MOD;
      base = (base * base) % MOD;
      index >>= 1;
    }

    return mint(res);
  }

  mint inv() {
    return (*this).POW(MOD - 2);
  }

  mint& operator+=(mint b) {
    _val += b._val;
    if (_val >= MOD)
      _val -= MOD;
    return *this;
  }
  mint& operator-=(mint b) {
    _val -= b._val;
    if (_val < 0)
      _val += MOD;
    return *this;
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
    if (_val == MOD)
      _val -= MOD;
    return *this;
  }
  mint operator++(signed) {
    mint tmp = *this;
    ++(*this);
    return tmp;
  }
  mint& operator--() {
    _val -= 1;
    if (_val == -1)
      _val += MOD;
    return *this;
  }
  mint operator--(signed) {
    mint tmp = *this;
    --(*this);
    return tmp;
  }

  mint operator-() {
    long long res = -_val;
    if (res < 0)
      res += MOD;
    return mint(res);
  }
  
  mint operator+(mint b) {
    long long res = _val + b._val;
    if (res >= MOD)
      res -= MOD;
    return mint(res);
  }
  mint operator-(mint b) {
    long long res = _val - b._val;
    if (res < 0)
      res += MOD;
    return mint(res);
  }
  mint operator*(mint b) {
    return mint(_val * b._val);
  }
  mint operator/(mint b) {
    return mint(_val * b.inv()._val);
  }

  bool operator==(mint b) {
    return _val == b._val;
  }
  bool operator!=(mint b) {
    return _val != b._val;
  }
};

ostream& operator<<(ostream& os, const mint& b) {
  os << b._val;
  return os;
}
istream& operator>>(istream& is, mint& b) {
  is >> b._val;
  return is;
}
//////////////////////////////////////////////////
