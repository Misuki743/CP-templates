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
  bundledCode: "#line 1 \"numtheory/MillerRabin.cpp\"\nbool isPrime(ull n) {\n  if\
    \ (n <= 1 or n % 6 % 4 != 1) return n == 2 or n == 3;\n  for(unsigned __int128\
    \ a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {\n    if (a % n ==\
    \ 0) continue;\n    ull d = (n - 1) >> countr_zero(n - 1);\n    unsigned __int128\
    \ b = 1;\n    while(d) {\n      if (d & 1) b = b * a % n;\n      a = a * a % n,\
    \ d >>= 1;\n    }\n    if (b == 1) continue;\n    for(int i = 0; i < countr_zero(n\
    \ - 1) and b != n - 1; i++)\n      b = b * b % n;\n    if (b != n - 1)\n     \
    \ return false;\n  }\n\n  return true;\n}\n"
  code: "bool isPrime(ull n) {\n  if (n <= 1 or n % 6 % 4 != 1) return n == 2 or n\
    \ == 3;\n  for(unsigned __int128 a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022})\
    \ {\n    if (a % n == 0) continue;\n    ull d = (n - 1) >> countr_zero(n - 1);\n\
    \    unsigned __int128 b = 1;\n    while(d) {\n      if (d & 1) b = b * a % n;\n\
    \      a = a * a % n, d >>= 1;\n    }\n    if (b == 1) continue;\n    for(int\
    \ i = 0; i < countr_zero(n - 1) and b != n - 1; i++)\n      b = b * b % n;\n \
    \   if (b != n - 1)\n      return false;\n  }\n\n  return true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/MillerRabin.cpp
  requiredBy: []
  timestamp: '2024-01-23 02:14:10+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numtheory/MillerRabin.cpp
layout: document
redirect_from:
- /library/numtheory/MillerRabin.cpp
- /library/numtheory/MillerRabin.cpp.html
title: numtheory/MillerRabin.cpp
---
