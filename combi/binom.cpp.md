---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/bell_number.test.cpp
    title: test/bell_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/binomial_coefficient_prime_mod.test.cpp
    title: test/binomial_coefficient_prime_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/counting_eulerian_circuits.test.cpp
    title: test/counting_eulerian_circuits.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/exp_of_formal_power_series_sparse.test.cpp
    title: test/exp_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/inv_of_formal_power_series_sparse.test.cpp
    title: test/inv_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/log_of_formal_power_series_sparse.test.cpp
    title: test/log_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial_taylor_shift.test.cpp
    title: test/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/pow_of_formal_power_series_sparse.test.cpp
    title: test/pow_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/sqrt_of_formal_power_series_sparse.test.cpp
    title: test/sqrt_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/stirling_number_of_the_second_kind.test.cpp
    title: test/stirling_number_of_the_second_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki_2544.test.cpp
    title: test/yuki_2544.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"combi/binom.cpp\"\n//#include<modint/MontgomeryModInt.cpp>\n\
    \ntemplate<class Mint>\nstruct binomial {\n  vector<Mint> _fac, _facInv;\n  binomial(int\
    \ size) : _fac(size), _facInv(size) {\n    _fac[0] = 1;\n    for(int i = 1; i\
    \ < size; i++)\n      _fac[i] = _fac[i - 1] * i;\n    if (size > 0)\n      _facInv.back()\
    \ = 1 / _fac.back();\n    for(int i = size - 2; i >= 0; i--)\n      _facInv[i]\
    \ = _facInv[i + 1] * (i + 1);\n  }\n\n  Mint fac(int i) { return i < 0 ? 0 : _fac[i];\
    \ }\n  Mint faci(int i) { return i < 0 ? 0 : _facInv[i]; }\n  Mint inv(int i)\
    \ { return _facInv[i] * _fac[i - 1]; }\n  Mint binom(int n, int r) { return r\
    \ < 0 or n < r ? 0 : fac(n) * faci(r) * faci(n - r); }\n  Mint catalan(int i)\
    \ { return binom(2 * i, i) - binom(2 * i, i + 1); }\n  Mint excatalan(int n, int\
    \ m, int k) { //(+1) * n, (-1) * m, prefix sum > -k\n    if (k > m) return binom(n\
    \ + m, m);\n    else if (k > m - n) return binom(n + m, m) - binom(n + m, m -\
    \ k);\n    else return Mint(0);\n  }\n};\n"
  code: "//#include<modint/MontgomeryModInt.cpp>\n\ntemplate<class Mint>\nstruct binomial\
    \ {\n  vector<Mint> _fac, _facInv;\n  binomial(int size) : _fac(size), _facInv(size)\
    \ {\n    _fac[0] = 1;\n    for(int i = 1; i < size; i++)\n      _fac[i] = _fac[i\
    \ - 1] * i;\n    if (size > 0)\n      _facInv.back() = 1 / _fac.back();\n    for(int\
    \ i = size - 2; i >= 0; i--)\n      _facInv[i] = _facInv[i + 1] * (i + 1);\n \
    \ }\n\n  Mint fac(int i) { return i < 0 ? 0 : _fac[i]; }\n  Mint faci(int i) {\
    \ return i < 0 ? 0 : _facInv[i]; }\n  Mint inv(int i) { return _facInv[i] * _fac[i\
    \ - 1]; }\n  Mint binom(int n, int r) { return r < 0 or n < r ? 0 : fac(n) * faci(r)\
    \ * faci(n - r); }\n  Mint catalan(int i) { return binom(2 * i, i) - binom(2 *\
    \ i, i + 1); }\n  Mint excatalan(int n, int m, int k) { //(+1) * n, (-1) * m,\
    \ prefix sum > -k\n    if (k > m) return binom(n + m, m);\n    else if (k > m\
    \ - n) return binom(n + m, m) - binom(n + m, m - k);\n    else return Mint(0);\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/binom.cpp
  requiredBy: []
  timestamp: '2024-04-05 17:40:38+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/counting_eulerian_circuits.test.cpp
  - test/stirling_number_of_the_second_kind.test.cpp
  - test/bell_number.test.cpp
  - test/inv_of_formal_power_series_sparse.test.cpp
  - test/log_of_formal_power_series_sparse.test.cpp
  - test/pow_of_formal_power_series_sparse.test.cpp
  - test/binomial_coefficient_prime_mod.test.cpp
  - test/sqrt_of_formal_power_series_sparse.test.cpp
  - test/exp_of_formal_power_series_sparse.test.cpp
  - test/yuki_2544.test.cpp
  - test/polynomial_taylor_shift.test.cpp
documentation_of: combi/binom.cpp
layout: document
redirect_from:
- /library/combi/binom.cpp
- /library/combi/binom.cpp.html
title: combi/binom.cpp
---
