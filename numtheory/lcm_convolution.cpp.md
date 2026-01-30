---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/lcm_convolution.test.cpp
    title: test/lcm_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/lcm_convolution.cpp\"\n//#include \"numtheory/linear_sieve.cpp\"\
    \n//#include \"numtheory/zeta_mobius_on_divisibility_lattice.cpp\"\n\ntemplate<class\
    \ T, int32_t C>\nvector<T> lcm_convolution(linear_sieve<C> &ls, vector<T> a, vector<T>\
    \ b) {\n  assert(ssize(a) == ssize(b));\n  a = zeta_transform_on_divisor(ls, a);\n\
    \  b = zeta_transform_on_divisor(ls, b);\n  for(int i = 0; i < ssize(a); i++)\n\
    \    a[i] *= b[i];\n  return mobius_transform_on_divisor(ls, a);\n}\n"
  code: "//#include \"numtheory/linear_sieve.cpp\"\n//#include \"numtheory/zeta_mobius_on_divisibility_lattice.cpp\"\
    \n\ntemplate<class T, int32_t C>\nvector<T> lcm_convolution(linear_sieve<C> &ls,\
    \ vector<T> a, vector<T> b) {\n  assert(ssize(a) == ssize(b));\n  a = zeta_transform_on_divisor(ls,\
    \ a);\n  b = zeta_transform_on_divisor(ls, b);\n  for(int i = 0; i < ssize(a);\
    \ i++)\n    a[i] *= b[i];\n  return mobius_transform_on_divisor(ls, a);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/lcm_convolution.cpp
  requiredBy: []
  timestamp: '2026-01-29 23:44:49+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/lcm_convolution.test.cpp
documentation_of: numtheory/lcm_convolution.cpp
layout: document
redirect_from:
- /library/numtheory/lcm_convolution.cpp
- /library/numtheory/lcm_convolution.cpp.html
title: numtheory/lcm_convolution.cpp
---
