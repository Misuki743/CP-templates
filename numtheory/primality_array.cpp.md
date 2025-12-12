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
  bundledCode: "#line 1 \"numtheory/primality_array.cpp\"\ntemplate<int32_t C>\nbitset<C>\
    \ primality_array() {\n  bitset<C> is_prime;\n  is_prime.set();\n  for(int i :\
    \ {0, 1})\n    if (i < C)\n      is_prime[i] = false;\n  for(int i = 2; i < C;\
    \ i++)\n    if (is_prime[i])\n      for(int j = 2 * i; j < C; j += i)\n      \
    \  is_prime[j] = false;\n  return is_prime;\n}\n"
  code: "template<int32_t C>\nbitset<C> primality_array() {\n  bitset<C> is_prime;\n\
    \  is_prime.set();\n  for(int i : {0, 1})\n    if (i < C)\n      is_prime[i] =\
    \ false;\n  for(int i = 2; i < C; i++)\n    if (is_prime[i])\n      for(int j\
    \ = 2 * i; j < C; j += i)\n        is_prime[j] = false;\n  return is_prime;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/primality_array.cpp
  requiredBy: []
  timestamp: '2025-12-12 18:41:06+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numtheory/primality_array.cpp
layout: document
redirect_from:
- /library/numtheory/primality_array.cpp
- /library/numtheory/primality_array.cpp.html
title: numtheory/primality_array.cpp
---
