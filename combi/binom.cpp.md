---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/binomial_coefficient_prime_mod.test.cpp
    title: test/binomial_coefficient_prime_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki_2544.test.cpp
    title: test/yuki_2544.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"combi/binom.cpp\"\ntemplate<class Mint>\nstruct binomial\
    \ {\n  vector<Mint> _fac, _facInv;\n  binomial(int size) : _fac(size), _facInv(size)\
    \ {\n    _fac[0] = 1;\n    for(int i = 1; i < size; i++)\n      _fac[i] = _fac[i\
    \ - 1] * i;\n    if (size > 0)\n      _facInv.back() = 1 / _fac.back();\n    for(int\
    \ i = size - 2; i >= 0; i--)\n      _facInv[i] = _facInv[i + 1] * (i + 1);\n \
    \ }\n\n  Mint fac(int i) { return i < 0 ? 0 : _fac[i]; }\n  Mint faci(int i) {\
    \ return i < 0 ? 0 : _facInv[i]; }\n  Mint binom(int n, int r) { return r < 0\
    \ or n < r ? 0 : fac(n) * faci(r) * faci(n - r); }\n};\n"
  code: "template<class Mint>\nstruct binomial {\n  vector<Mint> _fac, _facInv;\n\
    \  binomial(int size) : _fac(size), _facInv(size) {\n    _fac[0] = 1;\n    for(int\
    \ i = 1; i < size; i++)\n      _fac[i] = _fac[i - 1] * i;\n    if (size > 0)\n\
    \      _facInv.back() = 1 / _fac.back();\n    for(int i = size - 2; i >= 0; i--)\n\
    \      _facInv[i] = _facInv[i + 1] * (i + 1);\n  }\n\n  Mint fac(int i) { return\
    \ i < 0 ? 0 : _fac[i]; }\n  Mint faci(int i) { return i < 0 ? 0 : _facInv[i];\
    \ }\n  Mint binom(int n, int r) { return r < 0 or n < r ? 0 : fac(n) * faci(r)\
    \ * faci(n - r); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/binom.cpp
  requiredBy: []
  timestamp: '2024-03-02 01:56:40+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki_2544.test.cpp
  - test/binomial_coefficient_prime_mod.test.cpp
documentation_of: combi/binom.cpp
layout: document
redirect_from:
- /library/combi/binom.cpp
- /library/combi/binom.cpp.html
title: combi/binom.cpp
---
