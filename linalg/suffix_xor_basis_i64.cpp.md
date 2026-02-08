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
  bundledCode: "#line 1 \"linalg/suffix_xor_basis_i64.cpp\"\nstruct suffix_xor_basis\
    \ {\n  static constexpr int W = 64;\n  static constexpr int UINF = numeric_limits<int>::min();\n\
    \  static constexpr int INF = numeric_limits<int>::max();\n\n  using i64 = int64_t;\n\
    \n  i64 B[W] = {};\n  int mn_id[W] = {};\n  \n  void insert(i64 x, int id) {\n\
    \    for(int i = 0; i < W; i++) {\n      if (x >> i & 1) {\n        if (!B[i])\
    \ {\n          B[i] = x, mn_id[i] = id;\n          return;\n        }\n      \
    \  if (id > mn_id[i])\n          swap(x, B[i]), swap(id, mn_id[i]);\n        x\
    \ ^= B[i];\n      }\n    }\n  }\n\n  int query(i64 x) {\n    int mn = INF;\n \
    \   for(int i = 0; i < W; i++)\n      if (B[i] and (x >> i & 1))\n        x ^=\
    \ B[i], chmin(mn, mn_id[i]);\n    return x == 0 ? mn : UINF;\n  }\n};\n"
  code: "struct suffix_xor_basis {\n  static constexpr int W = 64;\n  static constexpr\
    \ int UINF = numeric_limits<int>::min();\n  static constexpr int INF = numeric_limits<int>::max();\n\
    \n  using i64 = int64_t;\n\n  i64 B[W] = {};\n  int mn_id[W] = {};\n  \n  void\
    \ insert(i64 x, int id) {\n    for(int i = 0; i < W; i++) {\n      if (x >> i\
    \ & 1) {\n        if (!B[i]) {\n          B[i] = x, mn_id[i] = id;\n         \
    \ return;\n        }\n        if (id > mn_id[i])\n          swap(x, B[i]), swap(id,\
    \ mn_id[i]);\n        x ^= B[i];\n      }\n    }\n  }\n\n  int query(i64 x) {\n\
    \    int mn = INF;\n    for(int i = 0; i < W; i++)\n      if (B[i] and (x >> i\
    \ & 1))\n        x ^= B[i], chmin(mn, mn_id[i]);\n    return x == 0 ? mn : UINF;\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/suffix_xor_basis_i64.cpp
  requiredBy: []
  timestamp: '2026-02-08 17:49:55+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/suffix_xor_basis_i64.cpp
layout: document
redirect_from:
- /library/linalg/suffix_xor_basis_i64.cpp
- /library/linalg/suffix_xor_basis_i64.cpp.html
title: linalg/suffix_xor_basis_i64.cpp
---
