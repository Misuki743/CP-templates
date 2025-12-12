---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/phi_array.cpp\"\ntemplate<class T, int32_t C>\n\
    array<T, C> phi_array(linear_sieve<C> &ls) {\n  array<T, C> phi = {};\n  if (C\
    \ > 1) phi[1] = T(1);\n  auto &mpf = ls.mpf;\n  for(int i = 2; i < C; i++)\n \
    \   phi[i] = phi[i / mpf[i]] * (mpf[i] == mpf[i / mpf[i]] ? mpf[i] : T(mpf[i]\
    \ - 1));\n  return phi;\n}\n"
  code: "template<class T, int32_t C>\narray<T, C> phi_array(linear_sieve<C> &ls)\
    \ {\n  array<T, C> phi = {};\n  if (C > 1) phi[1] = T(1);\n  auto &mpf = ls.mpf;\n\
    \  for(int i = 2; i < C; i++)\n    phi[i] = phi[i / mpf[i]] * (mpf[i] == mpf[i\
    \ / mpf[i]] ? mpf[i] : T(mpf[i] - 1));\n  return phi;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/phi_array.cpp
  requiredBy: []
  timestamp: '2025-12-12 18:41:06+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numtheory/phi_array.cpp
layout: document
redirect_from:
- /library/numtheory/phi_array.cpp
- /library/numtheory/phi_array.cpp.html
title: numtheory/phi_array.cpp
---
