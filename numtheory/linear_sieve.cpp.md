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
  bundledCode: "#line 1 \"numtheory/linear_sieve.cpp\"\ntemplate<int32_t C>\nstruct\
    \ linear_sieve {\n  array<int, C> mpf = {};\n  vector<int> prime;\n  linear_sieve()\
    \ {\n    if (C > 2)\n      iota(mpf.begin() + 2, mpf.end(), 2);\n    for(int i\
    \ = 2; i < C; i++) {\n      if (mpf[i] == i)\n        prime.emplace_back(i);\n\
    \      for(int64_t p : prime) {\n        if (p > mpf[i] or p * i >= C)\n     \
    \     break;\n        mpf[p * i] = p;\n      }\n    }\n  }\n\n  vector<pair<int,\
    \ int>> prime_factorize(int x) {\n    vector<pair<int, int>> r;\n    while(mpf[x])\
    \ {\n      r.emplace_back(mpf[x], 0);\n      while(x % r.back().first == 0)\n\
    \        x /= r.back().first, r.back().second++;\n    }\n    return r;\n  }\n\n\
    \  vector<int> prime_factor_enumerate(int x) {\n    vector<int> r;\n    while(mpf[x])\
    \ {\n      r.emplace_back(mpf[x]);\n      while(x % r.back() == 0)\n        x\
    \ /= r.back();\n    }\n    return r;\n  }\n\n  vector<int> divisor_enumerate(int\
    \ x, bool sorted = true) {\n    vector<int> divisor = {1};\n    for(auto [p, f]\
    \ : prime_factorize(x)) {\n      vector<int> nxt;\n      nxt.reserve(ssize(divisor)\
    \ * (f + 1));\n      for(int64_t i = 0, q = 1; i <= f; i++, q *= p)\n        for(int\
    \ d : divisor)\n          nxt.emplace_back(d * q);\n      divisor.swap(nxt);\n\
    \    }\n    if (sorted)\n      ranges::sort(divisor);\n    return divisor;\n \
    \ }\n};\n"
  code: "template<int32_t C>\nstruct linear_sieve {\n  array<int, C> mpf = {};\n \
    \ vector<int> prime;\n  linear_sieve() {\n    if (C > 2)\n      iota(mpf.begin()\
    \ + 2, mpf.end(), 2);\n    for(int i = 2; i < C; i++) {\n      if (mpf[i] == i)\n\
    \        prime.emplace_back(i);\n      for(int64_t p : prime) {\n        if (p\
    \ > mpf[i] or p * i >= C)\n          break;\n        mpf[p * i] = p;\n      }\n\
    \    }\n  }\n\n  vector<pair<int, int>> prime_factorize(int x) {\n    vector<pair<int,\
    \ int>> r;\n    while(mpf[x]) {\n      r.emplace_back(mpf[x], 0);\n      while(x\
    \ % r.back().first == 0)\n        x /= r.back().first, r.back().second++;\n  \
    \  }\n    return r;\n  }\n\n  vector<int> prime_factor_enumerate(int x) {\n  \
    \  vector<int> r;\n    while(mpf[x]) {\n      r.emplace_back(mpf[x]);\n      while(x\
    \ % r.back() == 0)\n        x /= r.back();\n    }\n    return r;\n  }\n\n  vector<int>\
    \ divisor_enumerate(int x, bool sorted = true) {\n    vector<int> divisor = {1};\n\
    \    for(auto [p, f] : prime_factorize(x)) {\n      vector<int> nxt;\n      nxt.reserve(ssize(divisor)\
    \ * (f + 1));\n      for(int64_t i = 0, q = 1; i <= f; i++, q *= p)\n        for(int\
    \ d : divisor)\n          nxt.emplace_back(d * q);\n      divisor.swap(nxt);\n\
    \    }\n    if (sorted)\n      ranges::sort(divisor);\n    return divisor;\n \
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/linear_sieve.cpp
  requiredBy: []
  timestamp: '2025-12-12 21:00:17+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numtheory/linear_sieve.cpp
layout: document
redirect_from:
- /library/numtheory/linear_sieve.cpp
- /library/numtheory/linear_sieve.cpp.html
title: numtheory/linear_sieve.cpp
---
