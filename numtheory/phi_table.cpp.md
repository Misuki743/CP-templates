---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest_phi_table.test.cpp
    title: test/mytest_phi_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/phi_table.cpp\"\ntemplate<class T, int32_t C>\n\
    array<T, C> phi_table(linear_sieve<C> &ls) {\n  array<T, C> phi = {};\n  if (C\
    \ > 1) phi[1] = T(1);\n  auto &mpf = ls.mpf;\n  for(int i = 2; i < C; i++)\n \
    \   phi[i] = phi[i / mpf[i]] * (mpf[i] == mpf[i / mpf[i]] ? mpf[i] : T(mpf[i]\
    \ - 1));\n  return phi;\n}\n"
  code: "template<class T, int32_t C>\narray<T, C> phi_table(linear_sieve<C> &ls)\
    \ {\n  array<T, C> phi = {};\n  if (C > 1) phi[1] = T(1);\n  auto &mpf = ls.mpf;\n\
    \  for(int i = 2; i < C; i++)\n    phi[i] = phi[i / mpf[i]] * (mpf[i] == mpf[i\
    \ / mpf[i]] ? mpf[i] : T(mpf[i] - 1));\n  return phi;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/phi_table.cpp
  requiredBy: []
  timestamp: '2026-02-08 01:19:23+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest_phi_table.test.cpp
documentation_of: numtheory/phi_table.cpp
layout: document
redirect_from:
- /library/numtheory/phi_table.cpp
- /library/numtheory/phi_table.cpp.html
title: numtheory/phi_table.cpp
---
