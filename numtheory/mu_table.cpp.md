---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest_mu_table.test.cpp
    title: test/mytest_mu_table.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/mu_table.cpp\"\ntemplate<class T, int32_t C>\n\
    array<T, C> mu_table(linear_sieve<C> &ls) {\n  array<T, C> mu = {};\n  if (C >\
    \ 1) mu[1] = T(1);\n  auto &mpf = ls.mpf;\n  for(int i = 2; i < C; i++)\n    mu[i]\
    \ = (mpf[i] == mpf[i / mpf[i]] ? T(0) : -mu[i / mpf[i]]);\n  return mu;\n}\n"
  code: "template<class T, int32_t C>\narray<T, C> mu_table(linear_sieve<C> &ls) {\n\
    \  array<T, C> mu = {};\n  if (C > 1) mu[1] = T(1);\n  auto &mpf = ls.mpf;\n \
    \ for(int i = 2; i < C; i++)\n    mu[i] = (mpf[i] == mpf[i / mpf[i]] ? T(0) :\
    \ -mu[i / mpf[i]]);\n  return mu;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/mu_table.cpp
  requiredBy: []
  timestamp: '2026-02-08 01:19:23+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest_mu_table.test.cpp
documentation_of: numtheory/mu_table.cpp
layout: document
redirect_from:
- /library/numtheory/mu_table.cpp
- /library/numtheory/mu_table.cpp.html
title: numtheory/mu_table.cpp
---
