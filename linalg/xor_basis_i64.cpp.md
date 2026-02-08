---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki_2895.test.cpp
    title: test/yuki_2895.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/xor_basis_i64.cpp\"\nstruct xor_basis {\n  static\
    \ constexpr int W = 64;\n\n  using i64 = int64_t;\n\n  int nxt = 0;\n  i64 B[W]\
    \ = {}, ids[W] = {};\n\n  pair<bool, i64> insert(i64 x) {\n    i64 v = 0;\n  \
    \  for(int i = 0; i < W; i++) {\n      if (x >> i & 1) {\n        if (!B[i]) {\n\
    \          B[i] = x, ids[i] = v | (1ll << (nxt++));\n          return pair(true,\
    \ 0);\n        }\n        x ^= B[i], v ^= ids[i];\n      }\n    }\n    return\
    \ pair(false, v);\n  }\n\n  pair<bool, i64> query(i64 x) {\n    i64 v = 0;\n \
    \   for(int i = 0; i < W; i++)\n      if (B[i] and (x >> i & 1))\n        x ^=\
    \ B[i], v ^= ids[i];\n    return pair(x == 0, x == 0 ? v : 0);\n  }\n};\n"
  code: "struct xor_basis {\n  static constexpr int W = 64;\n\n  using i64 = int64_t;\n\
    \n  int nxt = 0;\n  i64 B[W] = {}, ids[W] = {};\n\n  pair<bool, i64> insert(i64\
    \ x) {\n    i64 v = 0;\n    for(int i = 0; i < W; i++) {\n      if (x >> i & 1)\
    \ {\n        if (!B[i]) {\n          B[i] = x, ids[i] = v | (1ll << (nxt++));\n\
    \          return pair(true, 0);\n        }\n        x ^= B[i], v ^= ids[i];\n\
    \      }\n    }\n    return pair(false, v);\n  }\n\n  pair<bool, i64> query(i64\
    \ x) {\n    i64 v = 0;\n    for(int i = 0; i < W; i++)\n      if (B[i] and (x\
    \ >> i & 1))\n        x ^= B[i], v ^= ids[i];\n    return pair(x == 0, x == 0\
    \ ? v : 0);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/xor_basis_i64.cpp
  requiredBy: []
  timestamp: '2026-02-08 17:49:55+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki_2895.test.cpp
documentation_of: linalg/xor_basis_i64.cpp
layout: document
redirect_from:
- /library/linalg/xor_basis_i64.cpp
- /library/linalg/xor_basis_i64.cpp.html
title: linalg/xor_basis_i64.cpp
---
