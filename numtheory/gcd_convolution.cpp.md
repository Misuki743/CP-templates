---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/gcd_convolution.test.cpp
    title: test/gcd_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/gcd_convolution.cpp\"\n//#include \"numtheory/linear_sieve.cpp\"\
    \n//#include \"numtheory/zeta_mobius_on_divisibility_lattice.cpp\"\n\ntemplate<class\
    \ T, int32_t C>\nvector<T> gcd_convolution(linear_sieve<C> &ls, vector<T> a, vector<T>\
    \ b) {\n  assert(ssize(a) == ssize(b));\n  a = zeta_transform_on_multiple(ls,\
    \ a);\n  b = zeta_transform_on_multiple(ls, b);\n  for(int i = 0; i < ssize(a);\
    \ i++)\n    a[i] *= b[i];\n  return mobius_transform_on_multiple(ls, a);\n}\n"
  code: "//#include \"numtheory/linear_sieve.cpp\"\n//#include \"numtheory/zeta_mobius_on_divisibility_lattice.cpp\"\
    \n\ntemplate<class T, int32_t C>\nvector<T> gcd_convolution(linear_sieve<C> &ls,\
    \ vector<T> a, vector<T> b) {\n  assert(ssize(a) == ssize(b));\n  a = zeta_transform_on_multiple(ls,\
    \ a);\n  b = zeta_transform_on_multiple(ls, b);\n  for(int i = 0; i < ssize(a);\
    \ i++)\n    a[i] *= b[i];\n  return mobius_transform_on_multiple(ls, a);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/gcd_convolution.cpp
  requiredBy: []
  timestamp: '2026-01-29 23:44:49+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/gcd_convolution.test.cpp
documentation_of: numtheory/gcd_convolution.cpp
layout: document
redirect_from:
- /library/numtheory/gcd_convolution.cpp
- /library/numtheory/gcd_convolution.cpp.html
title: numtheory/gcd_convolution.cpp
---
