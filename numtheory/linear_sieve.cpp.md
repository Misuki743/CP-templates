---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/gcd_convolution.test.cpp
    title: test/gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lcm_convolution.test.cpp
    title: test/lcm_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest_linear_sieve.test.cpp
    title: test/mytest_linear_sieve.test.cpp
  - icon: ':x:'
    path: test/mytest_phi_table.test.cpp
    title: test/mytest_phi_table.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/linear_sieve.cpp\"\ntemplate<int32_t C>\nstruct\
    \ linear_sieve {\n  array<int, C> mpf = {};\n  vi prime;\n  linear_sieve() {\n\
    \    if (C > 2)\n      iota(mpf.begin() + 2, mpf.end(), 2);\n    for(int i = 2;\
    \ i < C; i++) {\n      if (mpf[i] == i)\n        prime.emplace_back(i);\n    \
    \  for(int64_t p : prime) {\n        if (p > mpf[i] or p * i >= C)\n         \
    \ break;\n        mpf[p * i] = p;\n      }\n    }\n  }\n\n  vc<pii> prime_factorize(int\
    \ x) {\n    vc<pii> r;\n    while(mpf[x]) {\n      r.emplace_back(mpf[x], 0);\n\
    \      while(x % r.back().first == 0)\n        x /= r.back().first, r.back().second++;\n\
    \    }\n    return r;\n  }\n\n  vi prime_factor(int x) {\n    vi r;\n    while(mpf[x])\
    \ {\n      r.emplace_back(mpf[x]);\n      while(x % r.back() == 0)\n        x\
    \ /= r.back();\n    }\n    return r;\n  }\n\n  vi divisor(int x, bool sorted =\
    \ true) {\n    vi divisor = {1};\n    for(auto [p, f] : prime_factorize(x)) {\n\
    \      vi nxt;\n      nxt.reserve(ssize(divisor) * (f + 1));\n      for(int64_t\
    \ i = 0, q = 1; i <= f; i++, q *= p)\n        for(int d : divisor)\n         \
    \ nxt.emplace_back(d * q);\n      divisor.swap(nxt);\n    }\n    if (sorted)\n\
    \      ranges::sort(divisor);\n    return divisor;\n  }\n};\n"
  code: "template<int32_t C>\nstruct linear_sieve {\n  array<int, C> mpf = {};\n \
    \ vi prime;\n  linear_sieve() {\n    if (C > 2)\n      iota(mpf.begin() + 2, mpf.end(),\
    \ 2);\n    for(int i = 2; i < C; i++) {\n      if (mpf[i] == i)\n        prime.emplace_back(i);\n\
    \      for(int64_t p : prime) {\n        if (p > mpf[i] or p * i >= C)\n     \
    \     break;\n        mpf[p * i] = p;\n      }\n    }\n  }\n\n  vc<pii> prime_factorize(int\
    \ x) {\n    vc<pii> r;\n    while(mpf[x]) {\n      r.emplace_back(mpf[x], 0);\n\
    \      while(x % r.back().first == 0)\n        x /= r.back().first, r.back().second++;\n\
    \    }\n    return r;\n  }\n\n  vi prime_factor(int x) {\n    vi r;\n    while(mpf[x])\
    \ {\n      r.emplace_back(mpf[x]);\n      while(x % r.back() == 0)\n        x\
    \ /= r.back();\n    }\n    return r;\n  }\n\n  vi divisor(int x, bool sorted =\
    \ true) {\n    vi divisor = {1};\n    for(auto [p, f] : prime_factorize(x)) {\n\
    \      vi nxt;\n      nxt.reserve(ssize(divisor) * (f + 1));\n      for(int64_t\
    \ i = 0, q = 1; i <= f; i++, q *= p)\n        for(int d : divisor)\n         \
    \ nxt.emplace_back(d * q);\n      divisor.swap(nxt);\n    }\n    if (sorted)\n\
    \      ranges::sort(divisor);\n    return divisor;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/linear_sieve.cpp
  requiredBy: []
  timestamp: '2026-02-08 01:19:23+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest_linear_sieve.test.cpp
  - test/mytest_phi_table.test.cpp
  - test/lcm_convolution.test.cpp
  - test/gcd_convolution.test.cpp
documentation_of: numtheory/linear_sieve.cpp
layout: document
redirect_from:
- /library/numtheory/linear_sieve.cpp
- /library/numtheory/linear_sieve.cpp.html
title: numtheory/linear_sieve.cpp
---
