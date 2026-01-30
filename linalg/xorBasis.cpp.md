---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/matrix_rank_mod_2.test.cpp
    title: test/matrix_rank_mod_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/xorBasis.cpp\"\n// note: querying whether x can be\
    \ represented as linear combination of some\n//       vector with label >= lb\n\
    \ntemplate<int size>\nstruct xorBasis {\n  bitset<size> *basis[size] = {};\n \
    \ int mxIdx[size] = {};\n  void insert(bitset<size> x, int idx) {\n    for(int\
    \ i = 0; i < size; i++) {\n      if (x[i]) {\n        if (!basis[i]) {\n     \
    \     basis[i] = new bitset<size>(x);\n          mxIdx[i] = idx;\n          return;\n\
    \        }\n        if (mxIdx[i] < idx) {\n          swap(*basis[i], x);\n   \
    \       swap(mxIdx[i], idx);\n        }\n        x ^= *basis[i];\n      }\n  \
    \  }\n  }\n  bool query(bitset<size> x, int lb = -1) {\n    int mn = INT_MAX;\n\
    \    for(int i = 0; i < size; i++)\n      if (basis[i] and x[i])\n        x ^=\
    \ *basis[i], mn = min(mn, mxIdx[i]);\n    return x.none() and mn >= lb;\n  }\n\
    \  ~xorBasis() {\n    for(int i = 0; i < size; i++)\n      if (basis[i])\n   \
    \     delete basis[i];\n  }\n};\n"
  code: "// note: querying whether x can be represented as linear combination of some\n\
    //       vector with label >= lb\n\ntemplate<int size>\nstruct xorBasis {\n  bitset<size>\
    \ *basis[size] = {};\n  int mxIdx[size] = {};\n  void insert(bitset<size> x, int\
    \ idx) {\n    for(int i = 0; i < size; i++) {\n      if (x[i]) {\n        if (!basis[i])\
    \ {\n          basis[i] = new bitset<size>(x);\n          mxIdx[i] = idx;\n  \
    \        return;\n        }\n        if (mxIdx[i] < idx) {\n          swap(*basis[i],\
    \ x);\n          swap(mxIdx[i], idx);\n        }\n        x ^= *basis[i];\n  \
    \    }\n    }\n  }\n  bool query(bitset<size> x, int lb = -1) {\n    int mn =\
    \ INT_MAX;\n    for(int i = 0; i < size; i++)\n      if (basis[i] and x[i])\n\
    \        x ^= *basis[i], mn = min(mn, mxIdx[i]);\n    return x.none() and mn >=\
    \ lb;\n  }\n  ~xorBasis() {\n    for(int i = 0; i < size; i++)\n      if (basis[i])\n\
    \        delete basis[i];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/xorBasis.cpp
  requiredBy: []
  timestamp: '2024-07-30 05:00:40+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/matrix_rank_mod_2.test.cpp
documentation_of: linalg/xorBasis.cpp
layout: document
redirect_from:
- /library/linalg/xorBasis.cpp
- /library/linalg/xorBasis.cpp.html
title: linalg/xorBasis.cpp
---
