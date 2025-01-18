//#include<modint/MontgomeryModInt.cpp>

template<class Mint>
struct stirlingSecondModP {
  const int p;
  vector<vector<Mint>> _S, _c;
  stirlingSecondModP() : p(Mint::get_mod()),
    _S(p, vector<Mint>(p)), _c(p, vector<Mint>(p)) {
    for(int i = 0; i < p; i++) {
      for(int j = 1; j < i; j++)
        _S[i][j] = _S[i - 1][j - 1] + _S[i - 1][j] * j;
      _S[i][i] = 1;
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

  Mint S(int64_t n, int64_t k) {
    if (n == 0 and k == 0) return Mint(1);
    int64_t i = k / p, j = k % p;
    int64_t a = (n - i) / (p - 1);
    int64_t b = (n - i) - (p - 1) * a;
    if (b == 0) b += p - 1, a--;
    if (b < p - 1)
      return binom(a, i) * _S[b][j];
    else if (j == 0)
      return binom(a, i - 1);
    else
      return binom(a, i) * _S[p - 1][j];
  }
};
