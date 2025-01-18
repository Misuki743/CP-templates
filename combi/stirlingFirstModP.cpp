//#include<modint/MontgomeryModInt.cpp>

template<class Mint>
struct stirlingFirstModP {
  const int p;
  vector<vector<Mint>> _s, _c;
  stirlingFirstModP() : p(Mint::get_mod()),
    _s(p, vector<Mint>(p)), _c(p, vector<Mint>(p)) {
    for(int i = 0; i < p; i++) {
      for(int j = 1; j < i; j++)
        _s[i][j] = _s[i - 1][j - 1] + _s[i - 1][j] * -(i - 1);
      _s[i][i] = 1;
    }
    for(int i = 0; i < p; i++) {
      _c[i][0] = 1;
      for(int j = 1; j < i; j++)
        _c[i][j] = _c[i - 1][j - 1] + _c[i - 1][j];
      _c[i][i] = 1;
    }
  }

  Mint binom(int64_t n, int64_t k) {
    if (k < 0 or n < k) return Mint(0);
    Mint r = 1;
    while(n)
      r *= _c[n % p][k % p], n /= p, k /= p;
    return r;
  }

  Mint s(int64_t n, int64_t k) {
    int64_t i = n / p, j = n % p;
    int64_t b = ((k - i) % (p - 1) + (p - 1)) % (p - 1);
    int64_t a = (k - i - b) / (p - 1);
    mint r = binom(i, a) * ((i - a) % 2 == 1 ? -1 : 1) * _s[j][b];
    if (b == 0 and a > 0)
      r += binom(i, a - 1) * ((i - a + 1) % 2 == 1 ? -1 : 1) * _s[j][p - 1];
    return r;
  }
};
