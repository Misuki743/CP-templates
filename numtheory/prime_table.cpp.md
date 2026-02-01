---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/enumerate_primes.test.cpp
    title: test/enumerate_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest_prime_table.test.cpp
    title: test/mytest_prime_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/prime_table.cpp\"\ntemplate<int32_t C>\nclass\
    \ prime_table {\n  static constexpr int32_t D = (C + 29) / 30 * 30;\n  bitset<D\
    \ / 2> table = {};\n\n  public:\n\n  vi prime;\n\n  prime_table() : prime({2,\
    \ 3, 5}) {\n    table[3 / 2] = table[5 / 2] = true;\n    for(int i = 0; i < D;\
    \ i += 30) {\n      table[(i + 01) / 2] = table[(i + 07) / 2] =\n      table[(i\
    \ + 11) / 2] = table[(i + 13) / 2] =\n      table[(i + 17) / 2] = table[(i + 19)\
    \ / 2] =\n      table[(i + 23) / 2] = table[(i + 29) / 2] = true;\n    }\n   \
    \ table[1 / 2] = false;\n\n    const int32_t S = sqrtl(D) + 10;\n    for(int i\
    \ = 7, j = 4; i < S; i += j, j ^= 6) {\n      if (table[i / 2]) {\n        for(int\
    \ k = ((i + 4) / 6 * 6 + 1) * i; k < D; k += 6 * i)\n          table[k / 2] =\
    \ false;\n        for(int k = (i / 6 * 6 + 5) * i; k < D; k += 6 * i)\n      \
    \    table[k / 2] = false;\n      }\n    }\n\n    prime.reserve(1.1 * D / log(D));\n\
    \    for(int i = 0; i < D; i += 30) {\n      if (table[(i + 01) / 2]) prime.emplace_back(i\
    \ + 01);\n      if (table[(i + 07) / 2]) prime.emplace_back(i + 07);\n      if\
    \ (table[(i + 11) / 2]) prime.emplace_back(i + 11);\n      if (table[(i + 13)\
    \ / 2]) prime.emplace_back(i + 13);\n      if (table[(i + 17) / 2]) prime.emplace_back(i\
    \ + 17);\n      if (table[(i + 19) / 2]) prime.emplace_back(i + 19);\n      if\
    \ (table[(i + 23) / 2]) prime.emplace_back(i + 23);\n      if (table[(i + 29)\
    \ / 2]) prime.emplace_back(i + 29);\n    }\n\n    int n = ssize(prime) - 1;\n\
    \    while(n >= 0 and prime[n] >= C) n--;\n    prime.resize(n + 1);\n  }\n\n \
    \ bool is_prime(int x) { return x == 2 or ((x & 1) and table[x / 2]); }\n  //make\
    \ sure to not copy the array by using &x = prime_array()\n  const vi& prime_array()\
    \ { return prime; }\n};\n"
  code: "template<int32_t C>\nclass prime_table {\n  static constexpr int32_t D =\
    \ (C + 29) / 30 * 30;\n  bitset<D / 2> table = {};\n\n  public:\n\n  vi prime;\n\
    \n  prime_table() : prime({2, 3, 5}) {\n    table[3 / 2] = table[5 / 2] = true;\n\
    \    for(int i = 0; i < D; i += 30) {\n      table[(i + 01) / 2] = table[(i +\
    \ 07) / 2] =\n      table[(i + 11) / 2] = table[(i + 13) / 2] =\n      table[(i\
    \ + 17) / 2] = table[(i + 19) / 2] =\n      table[(i + 23) / 2] = table[(i + 29)\
    \ / 2] = true;\n    }\n    table[1 / 2] = false;\n\n    const int32_t S = sqrtl(D)\
    \ + 10;\n    for(int i = 7, j = 4; i < S; i += j, j ^= 6) {\n      if (table[i\
    \ / 2]) {\n        for(int k = ((i + 4) / 6 * 6 + 1) * i; k < D; k += 6 * i)\n\
    \          table[k / 2] = false;\n        for(int k = (i / 6 * 6 + 5) * i; k <\
    \ D; k += 6 * i)\n          table[k / 2] = false;\n      }\n    }\n\n    prime.reserve(1.1\
    \ * D / log(D));\n    for(int i = 0; i < D; i += 30) {\n      if (table[(i + 01)\
    \ / 2]) prime.emplace_back(i + 01);\n      if (table[(i + 07) / 2]) prime.emplace_back(i\
    \ + 07);\n      if (table[(i + 11) / 2]) prime.emplace_back(i + 11);\n      if\
    \ (table[(i + 13) / 2]) prime.emplace_back(i + 13);\n      if (table[(i + 17)\
    \ / 2]) prime.emplace_back(i + 17);\n      if (table[(i + 19) / 2]) prime.emplace_back(i\
    \ + 19);\n      if (table[(i + 23) / 2]) prime.emplace_back(i + 23);\n      if\
    \ (table[(i + 29) / 2]) prime.emplace_back(i + 29);\n    }\n\n    int n = ssize(prime)\
    \ - 1;\n    while(n >= 0 and prime[n] >= C) n--;\n    prime.resize(n + 1);\n \
    \ }\n\n  bool is_prime(int x) { return x == 2 or ((x & 1) and table[x / 2]); }\n\
    \  //make sure to not copy the array by using &x = prime_array()\n  const vi&\
    \ prime_array() { return prime; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/prime_table.cpp
  requiredBy: []
  timestamp: '2026-02-01 21:09:59+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest_prime_table.test.cpp
  - test/enumerate_primes.test.cpp
documentation_of: numtheory/prime_table.cpp
layout: document
redirect_from:
- /library/numtheory/prime_table.cpp
- /library/numtheory/prime_table.cpp.html
title: numtheory/prime_table.cpp
---
