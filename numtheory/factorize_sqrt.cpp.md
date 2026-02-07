---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest_factorize_sqrt.test.cpp
    title: test/mytest_factorize_sqrt.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/factorize_sqrt.cpp\"\nvc<pair<int64_t, int64_t>>\
    \ prime_factorize_sqrt(int64_t x) {\n  using i64 = int64_t;\n  vc<pair<i64, i64>>\
    \ res;\n  for(i64 d = 2; d * d <= x; d++) {\n    if (x % d != 0) continue;\n \
    \   res.emplace_back(d, 0ll);\n    while(x % d == 0)\n      x /= d, res.back().second++;\n\
    \  }\n  if (x != 1) res.emplace_back(x, 1);\n  return res;\n}\n\nvc<int64_t> prime_factor_sqrt(int64_t\
    \ x) {\n  using i64 = int64_t;\n  vc<i64> res;\n  for(i64 d = 2; d * d <= x; d++)\
    \ {\n    if (x % d != 0) continue;\n    res.emplace_back(d);\n    while(x % d\
    \ == 0)\n      x /= d;\n  }\n  if (x != 1) res.emplace_back(x);\n  return res;\n\
    }\n\nvc<int64_t> divisor_sqrt(int64_t x, bool sorted = true) {\n  using i64 =\
    \ int64_t;\n  vc<i64> divisor = {1};\n  for(auto [p, f] : prime_factorize_sqrt(x))\
    \ {\n    vc<i64> nxt;\n    nxt.reserve(ssize(divisor) * (f + 1));\n    uint64_t\
    \ q = 1;\n    for(int i = 0; i <= f; i++, q *= p)\n      for(i64 d : divisor)\n\
    \        nxt.emplace_back(d * q);\n    divisor.swap(nxt);\n  }\n  if (sorted)\n\
    \    ranges::sort(divisor);\n  return divisor;\n}\n"
  code: "vc<pair<int64_t, int64_t>> prime_factorize_sqrt(int64_t x) {\n  using i64\
    \ = int64_t;\n  vc<pair<i64, i64>> res;\n  for(i64 d = 2; d * d <= x; d++) {\n\
    \    if (x % d != 0) continue;\n    res.emplace_back(d, 0ll);\n    while(x % d\
    \ == 0)\n      x /= d, res.back().second++;\n  }\n  if (x != 1) res.emplace_back(x,\
    \ 1);\n  return res;\n}\n\nvc<int64_t> prime_factor_sqrt(int64_t x) {\n  using\
    \ i64 = int64_t;\n  vc<i64> res;\n  for(i64 d = 2; d * d <= x; d++) {\n    if\
    \ (x % d != 0) continue;\n    res.emplace_back(d);\n    while(x % d == 0)\n  \
    \    x /= d;\n  }\n  if (x != 1) res.emplace_back(x);\n  return res;\n}\n\nvc<int64_t>\
    \ divisor_sqrt(int64_t x, bool sorted = true) {\n  using i64 = int64_t;\n  vc<i64>\
    \ divisor = {1};\n  for(auto [p, f] : prime_factorize_sqrt(x)) {\n    vc<i64>\
    \ nxt;\n    nxt.reserve(ssize(divisor) * (f + 1));\n    uint64_t q = 1;\n    for(int\
    \ i = 0; i <= f; i++, q *= p)\n      for(i64 d : divisor)\n        nxt.emplace_back(d\
    \ * q);\n    divisor.swap(nxt);\n  }\n  if (sorted)\n    ranges::sort(divisor);\n\
    \  return divisor;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/factorize_sqrt.cpp
  requiredBy: []
  timestamp: '2026-02-08 01:19:23+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest_factorize_sqrt.test.cpp
documentation_of: numtheory/factorize_sqrt.cpp
layout: document
redirect_from:
- /library/numtheory/factorize_sqrt.cpp
- /library/numtheory/factorize_sqrt.cpp.html
title: numtheory/factorize_sqrt.cpp
---
