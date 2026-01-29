---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/gcd_convolution.test.cpp
    title: test/gcd_convolution.test.cpp
  - icon: ':x:'
    path: test/lcm_convolution.test.cpp
    title: test/lcm_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/zeta_mobius_on_divisibility_lattice.cpp\"\n//#include\
    \ \"numtheory/linear_sieve\"\n\ntemplate<class T, int32_t C>\nvector<T> zeta_transform_on_divisor(linear_sieve<C>\
    \ &ls, vector<T> f) {\n  assert(ssize(f) <= C);\n  for(int64_t p : ls.prime) {\n\
    \    if (p >= ssize(f)) break;\n    for(int i = 1; i * p < ssize(f); i++)\n  \
    \    f[i * p] += f[i];\n  }\n  return f;\n}\n\ntemplate<class T, int32_t C>\n\
    vector<T> mobius_transform_on_divisor(linear_sieve<C> &ls, vector<T> f) {\n  assert(ssize(f)\
    \ <= C);\n  for(int64_t p : ls.prime) {\n    if (p >= ssize(f)) break;\n    for(int\
    \ i = (ssize(f) - 1) / p; i > 0; i--)\n      f[i * p] -= f[i];\n  }\n  return\
    \ f;\n}\n\ntemplate<class T, int32_t C>\nvector<T> zeta_transform_on_multiple(linear_sieve<C>\
    \ &ls, vector<T> f) {\n  assert(ssize(f) <= C);\n  for(int64_t p : ls.prime) {\n\
    \    if (p >= ssize(f)) break;\n    for(int i = (ssize(f) - 1) / p; i > 0; i--)\n\
    \      f[i] += f[i * p];\n  }\n  return f;\n}\n\ntemplate<class T, int32_t C>\n\
    vector<T> mobius_transform_on_multiple(linear_sieve<C> &ls, vector<T> f) {\n \
    \ assert(ssize(f) <= C);\n  for(int64_t p : ls.prime) {\n    if (p >= ssize(f))\
    \ break;\n    for(int i = 1; i * p < ssize(f); i++)\n      f[i] -= f[i * p];\n\
    \  }\n  return f;\n}\n"
  code: "//#include \"numtheory/linear_sieve\"\n\ntemplate<class T, int32_t C>\nvector<T>\
    \ zeta_transform_on_divisor(linear_sieve<C> &ls, vector<T> f) {\n  assert(ssize(f)\
    \ <= C);\n  for(int64_t p : ls.prime) {\n    if (p >= ssize(f)) break;\n    for(int\
    \ i = 1; i * p < ssize(f); i++)\n      f[i * p] += f[i];\n  }\n  return f;\n}\n\
    \ntemplate<class T, int32_t C>\nvector<T> mobius_transform_on_divisor(linear_sieve<C>\
    \ &ls, vector<T> f) {\n  assert(ssize(f) <= C);\n  for(int64_t p : ls.prime) {\n\
    \    if (p >= ssize(f)) break;\n    for(int i = (ssize(f) - 1) / p; i > 0; i--)\n\
    \      f[i * p] -= f[i];\n  }\n  return f;\n}\n\ntemplate<class T, int32_t C>\n\
    vector<T> zeta_transform_on_multiple(linear_sieve<C> &ls, vector<T> f) {\n  assert(ssize(f)\
    \ <= C);\n  for(int64_t p : ls.prime) {\n    if (p >= ssize(f)) break;\n    for(int\
    \ i = (ssize(f) - 1) / p; i > 0; i--)\n      f[i] += f[i * p];\n  }\n  return\
    \ f;\n}\n\ntemplate<class T, int32_t C>\nvector<T> mobius_transform_on_multiple(linear_sieve<C>\
    \ &ls, vector<T> f) {\n  assert(ssize(f) <= C);\n  for(int64_t p : ls.prime) {\n\
    \    if (p >= ssize(f)) break;\n    for(int i = 1; i * p < ssize(f); i++)\n  \
    \    f[i] -= f[i * p];\n  }\n  return f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/zeta_mobius_on_divisibility_lattice.cpp
  requiredBy: []
  timestamp: '2026-01-29 23:44:49+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/lcm_convolution.test.cpp
  - test/gcd_convolution.test.cpp
documentation_of: numtheory/zeta_mobius_on_divisibility_lattice.cpp
layout: document
redirect_from:
- /library/numtheory/zeta_mobius_on_divisibility_lattice.cpp
- /library/numtheory/zeta_mobius_on_divisibility_lattice.cpp.html
title: numtheory/zeta_mobius_on_divisibility_lattice.cpp
---
