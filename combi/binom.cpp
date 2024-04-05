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
  Mint inv(int i) { return _facInv[i] * _fac[i - 1]; }
  Mint binom(int n, int r) { return r < 0 or n < r ? 0 : fac(n) * faci(r) * faci(n - r); }
  Mint catalan(int i) { return binom(2 * i, i) - binom(2 * i, i + 1); }
  Mint excatalan(int n, int m, int k) { //(+1) * n, (-1) * m, prefix sum > -k
    if (k > m) return binom(n + m, m);
    else if (k > m - n) return binom(n + m, m) - binom(n + m, m - k);
    else return Mint(0);
  }
};
