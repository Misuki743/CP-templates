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
  bundledCode: "#line 1 \"linalg/suffix_xor_basis_bitset.cpp\"\ntemplate<int W>\n\
    struct suffix_xor_basis {\n  static constexpr int UINF = numeric_limits<int>::min();\n\
    \  static constexpr int INF = numeric_limits<int>::max();\n\n  bitset<W> *B[W]\
    \ = {};\n  int mn_id[W] = {};\n\n  void insert(bitset<W> x, int id) {\n    for(int\
    \ i = 0; i < W; i++) {\n      if (x[i]) {\n        if (!B[i]) {\n          B[i]\
    \ = new bitset<W>(x), mn_id[i] = id;\n          return;\n        }\n        if\
    \ (id > mn_id[i])\n          swap(x, *B[i]), swap(id, mn_id[i]);\n        x ^=\
    \ *B[i];\n      }\n    }\n  }\n\n  int query(bitset<W> x) {\n    int mn = INF;\n\
    \    for(int i = 0; i < W; i++)\n      if (B[i] and x[i])\n        x ^= *B[i],\
    \ chmin(mn, mn_id[i]);\n    return x.none() ? mn : UINF;\n  }\n\n  ~suffix_xor_basis()\
    \ {\n    for(int i = 0; i < W; i++)\n      if (B[i])\n        delete B[i];\n \
    \ }\n};\n"
  code: "template<int W>\nstruct suffix_xor_basis {\n  static constexpr int UINF =\
    \ numeric_limits<int>::min();\n  static constexpr int INF = numeric_limits<int>::max();\n\
    \n  bitset<W> *B[W] = {};\n  int mn_id[W] = {};\n\n  void insert(bitset<W> x,\
    \ int id) {\n    for(int i = 0; i < W; i++) {\n      if (x[i]) {\n        if (!B[i])\
    \ {\n          B[i] = new bitset<W>(x), mn_id[i] = id;\n          return;\n  \
    \      }\n        if (id > mn_id[i])\n          swap(x, *B[i]), swap(id, mn_id[i]);\n\
    \        x ^= *B[i];\n      }\n    }\n  }\n\n  int query(bitset<W> x) {\n    int\
    \ mn = INF;\n    for(int i = 0; i < W; i++)\n      if (B[i] and x[i])\n      \
    \  x ^= *B[i], chmin(mn, mn_id[i]);\n    return x.none() ? mn : UINF;\n  }\n\n\
    \  ~suffix_xor_basis() {\n    for(int i = 0; i < W; i++)\n      if (B[i])\n  \
    \      delete B[i];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/suffix_xor_basis_bitset.cpp
  requiredBy: []
  timestamp: '2026-02-08 17:49:55+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/suffix_xor_basis_bitset.cpp
layout: document
redirect_from:
- /library/linalg/suffix_xor_basis_bitset.cpp
- /library/linalg/suffix_xor_basis_bitset.cpp.html
title: linalg/suffix_xor_basis_bitset.cpp
---
