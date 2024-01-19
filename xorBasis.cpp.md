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
  bundledCode: "#line 1 \"xorBasis.cpp\"\n/**\n * template name: xorBasis\n * author:\
    \ Misuki\n * last update: 2023/01/01\n * note: querying whether x can be represented\
    \ as linear combination of some\n *       vector with label >= lb\n * verify:\
    \ CF1902F - Trees and XOR Queries Again\n */\n\ntemplate<int size>\nstruct xorBasis\
    \ {\n  bitset<size> basis[size] = {};\n  int mxIdx[size] = {};\n  void insert(bitset<size>\
    \ x, int idx) {\n    for(int i = 0; i < size; i++) {\n      if (x[i]) {\n    \
    \    if (basis[i].none()) {\n          basis[i] = x, mxIdx[i] = idx;\n       \
    \   return;\n        }\n        if (mxIdx[i] < idx) {\n          swap(basis[i],\
    \ x);\n          swap(mxIdx[i], idx);\n        }\n        x ^= basis[i];\n   \
    \   }\n    }\n  }\n  bool query(bitset<size> x, int lb = -1) {\n    int mn = INT_MAX;\n\
    \    for(int i = 0; i < size; i++)\n      if (x[i])\n        x ^= basis[i], mn\
    \ = min(mn, mxIdx[i]);\n    return x.none() and mn >= lb;\n  }\n};\n"
  code: "/**\n * template name: xorBasis\n * author: Misuki\n * last update: 2023/01/01\n\
    \ * note: querying whether x can be represented as linear combination of some\n\
    \ *       vector with label >= lb\n * verify: CF1902F - Trees and XOR Queries\
    \ Again\n */\n\ntemplate<int size>\nstruct xorBasis {\n  bitset<size> basis[size]\
    \ = {};\n  int mxIdx[size] = {};\n  void insert(bitset<size> x, int idx) {\n \
    \   for(int i = 0; i < size; i++) {\n      if (x[i]) {\n        if (basis[i].none())\
    \ {\n          basis[i] = x, mxIdx[i] = idx;\n          return;\n        }\n \
    \       if (mxIdx[i] < idx) {\n          swap(basis[i], x);\n          swap(mxIdx[i],\
    \ idx);\n        }\n        x ^= basis[i];\n      }\n    }\n  }\n  bool query(bitset<size>\
    \ x, int lb = -1) {\n    int mn = INT_MAX;\n    for(int i = 0; i < size; i++)\n\
    \      if (x[i])\n        x ^= basis[i], mn = min(mn, mxIdx[i]);\n    return x.none()\
    \ and mn >= lb;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: xorBasis.cpp
  requiredBy: []
  timestamp: '2024-01-06 18:21:41+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: xorBasis.cpp
layout: document
redirect_from:
- /library/xorBasis.cpp
- /library/xorBasis.cpp.html
title: xorBasis.cpp
---
