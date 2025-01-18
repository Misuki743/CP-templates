---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/stirling_number_of_second_kind_small_p_large_n.test.cpp
    title: test/stirling_number_of_second_kind_small_p_large_n.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"combi/stirlingSecondModP.cpp\"\n//#include<modint/MontgomeryModInt.cpp>\n\
    \ntemplate<class Mint>\nstruct stirlingSecondModP {\n  const int p;\n  vector<vector<Mint>>\
    \ _S, _c;\n  stirlingSecondModP() : p(Mint::get_mod()),\n    _S(p, vector<Mint>(p)),\
    \ _c(p, vector<Mint>(p)) {\n    for(int i = 0; i < p; i++) {\n      for(int j\
    \ = 1; j < i; j++)\n        _S[i][j] = _S[i - 1][j - 1] + _S[i - 1][j] * j;\n\
    \      _S[i][i] = 1;\n    }\n    for(int i = 0; i < p; i++) {\n      _c[i][0]\
    \ = 1;\n      for(int j = 1; j < i; j++)\n        _c[i][j] = _c[i - 1][j - 1]\
    \ + _c[i - 1][j];\n      _c[i][i] = 1;\n    }\n  }\n\n  Mint binom(int64_t n,\
    \ int64_t k) {\n    if (k < 0 or n < k) return Mint(0);\n    Mint r = 1;\n   \
    \ while(n)\n      r *= _c[n % p][k % p], n /= p, k /= p;\n    return r;\n  }\n\
    \n  Mint S(int64_t n, int64_t k) {\n    if (n == 0 and k == 0) return Mint(1);\n\
    \    int64_t i = k / p, j = k % p;\n    int64_t a = (n - i) / (p - 1);\n    int64_t\
    \ b = (n - i) - (p - 1) * a;\n    if (b == 0) b += p - 1, a--;\n    if (b < p\
    \ - 1)\n      return binom(a, i) * _S[b][j];\n    else if (j == 0)\n      return\
    \ binom(a, i - 1);\n    else\n      return binom(a, i) * _S[p - 1][j];\n  }\n\
    };\n"
  code: "//#include<modint/MontgomeryModInt.cpp>\n\ntemplate<class Mint>\nstruct stirlingSecondModP\
    \ {\n  const int p;\n  vector<vector<Mint>> _S, _c;\n  stirlingSecondModP() :\
    \ p(Mint::get_mod()),\n    _S(p, vector<Mint>(p)), _c(p, vector<Mint>(p)) {\n\
    \    for(int i = 0; i < p; i++) {\n      for(int j = 1; j < i; j++)\n        _S[i][j]\
    \ = _S[i - 1][j - 1] + _S[i - 1][j] * j;\n      _S[i][i] = 1;\n    }\n    for(int\
    \ i = 0; i < p; i++) {\n      _c[i][0] = 1;\n      for(int j = 1; j < i; j++)\n\
    \        _c[i][j] = _c[i - 1][j - 1] + _c[i - 1][j];\n      _c[i][i] = 1;\n  \
    \  }\n  }\n\n  Mint binom(int64_t n, int64_t k) {\n    if (k < 0 or n < k) return\
    \ Mint(0);\n    Mint r = 1;\n    while(n)\n      r *= _c[n % p][k % p], n /= p,\
    \ k /= p;\n    return r;\n  }\n\n  Mint S(int64_t n, int64_t k) {\n    if (n ==\
    \ 0 and k == 0) return Mint(1);\n    int64_t i = k / p, j = k % p;\n    int64_t\
    \ a = (n - i) / (p - 1);\n    int64_t b = (n - i) - (p - 1) * a;\n    if (b ==\
    \ 0) b += p - 1, a--;\n    if (b < p - 1)\n      return binom(a, i) * _S[b][j];\n\
    \    else if (j == 0)\n      return binom(a, i - 1);\n    else\n      return binom(a,\
    \ i) * _S[p - 1][j];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/stirlingSecondModP.cpp
  requiredBy: []
  timestamp: '2025-01-18 17:35:28+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/stirling_number_of_second_kind_small_p_large_n.test.cpp
documentation_of: combi/stirlingSecondModP.cpp
layout: document
redirect_from:
- /library/combi/stirlingSecondModP.cpp
- /library/combi/stirlingSecondModP.cpp.html
title: combi/stirlingSecondModP.cpp
---
