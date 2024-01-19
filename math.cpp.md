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
  bundledCode: "#line 1 \"math.cpp\"\n/**\n * template name: math\n * author: Misuki\n\
    \ * last update: 2022/03/21\n */\n\nconst long long MOD = 1e9 + 7;\n\nint POW(long\
    \ long base, long long index) {\n  if (index == 0)\n    return 1ll;\n  long long\
    \ res = (base == 0ll ? 0ll : 1ll);\n  while(index) {\n    if (index & 1)\n   \
    \   res = (res * base) % MOD;\n    base = (base * base) % MOD;\n    index >>=\
    \ 1;\n  }\n\n  return res;\n}\n\nint inv(int val) {\n  return POW(val, MOD - 2);\n\
    }\n"
  code: "/**\n * template name: math\n * author: Misuki\n * last update: 2022/03/21\n\
    \ */\n\nconst long long MOD = 1e9 + 7;\n\nint POW(long long base, long long index)\
    \ {\n  if (index == 0)\n    return 1ll;\n  long long res = (base == 0ll ? 0ll\
    \ : 1ll);\n  while(index) {\n    if (index & 1)\n      res = (res * base) % MOD;\n\
    \    base = (base * base) % MOD;\n    index >>= 1;\n  }\n\n  return res;\n}\n\n\
    int inv(int val) {\n  return POW(val, MOD - 2);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math.cpp
  requiredBy: []
  timestamp: '2023-06-16 02:10:58+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math.cpp
layout: document
redirect_from:
- /library/math.cpp
- /library/math.cpp.html
title: math.cpp
---
