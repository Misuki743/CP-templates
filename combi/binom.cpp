//#include<modint/MontgomeryModInt.cpp>

template<class Mint>
struct binomial {
  vector<Mint> _fac, _facInv;
  binomial(int size) : _fac(size), _facInv(size) {
    _fac[0] = 1;
    for(int i = 1; i < size; i++)
      _fac[i] = _fac[i - 1] * i;
    if (size > 0)
      _facInv.back() = 1 / _fac.back();
    for(int i = size - 2; i >= 0; i--)
      _facInv[i] = _facInv[i + 1] * (i + 1);
  }

  Mint fac(int i) { return i < 0 ? 0 : _fac[i]; }
  Mint faci(int i) { return i < 0 ? 0 : _facInv[i]; }
  Mint binom(int n, int r) { return r < 0 or n < r ? 0 : fac(n) * faci(r) * faci(n - r); }
  Mint inv(int i) { return _facInv[i] * _fac[i - 1]; }
};
