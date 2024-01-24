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
  bundledCode: "#line 1 \"linalg/xorBasis.cpp\"\n// note: querying whether x can be\
    \ represented as linear combination of some\n//       vector with label >= lb\n\
    \ntemplate<int size>\nstruct xorBasis {\n  bitset<size> basis[size] = {};\n  int\
    \ mxIdx[size] = {};\n  void insert(bitset<size> x, int idx) {\n    for(int i =\
    \ 0; i < size; i++) {\n      if (x[i]) {\n        if (basis[i].none()) {\n   \
    \       basis[i] = x, mxIdx[i] = idx;\n          return;\n        }\n        if\
    \ (mxIdx[i] < idx) {\n          swap(basis[i], x);\n          swap(mxIdx[i], idx);\n\
    \        }\n        x ^= basis[i];\n      }\n    }\n  }\n  bool query(bitset<size>\
    \ x, int lb = -1) {\n    int mn = INT_MAX;\n    for(int i = 0; i < size; i++)\n\
    \      if (x[i])\n        x ^= basis[i], mn = min(mn, mxIdx[i]);\n    return x.none()\
    \ and mn >= lb;\n  }\n};\n"
  code: "// note: querying whether x can be represented as linear combination of some\n\
    //       vector with label >= lb\n\ntemplate<int size>\nstruct xorBasis {\n  bitset<size>\
    \ basis[size] = {};\n  int mxIdx[size] = {};\n  void insert(bitset<size> x, int\
    \ idx) {\n    for(int i = 0; i < size; i++) {\n      if (x[i]) {\n        if (basis[i].none())\
    \ {\n          basis[i] = x, mxIdx[i] = idx;\n          return;\n        }\n \
    \       if (mxIdx[i] < idx) {\n          swap(basis[i], x);\n          swap(mxIdx[i],\
    \ idx);\n        }\n        x ^= basis[i];\n      }\n    }\n  }\n  bool query(bitset<size>\
    \ x, int lb = -1) {\n    int mn = INT_MAX;\n    for(int i = 0; i < size; i++)\n\
    \      if (x[i])\n        x ^= basis[i], mn = min(mn, mxIdx[i]);\n    return x.none()\
    \ and mn >= lb;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/xorBasis.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/xorBasis.cpp
layout: document
redirect_from:
- /library/linalg/xorBasis.cpp
- /library/linalg/xorBasis.cpp.html
title: linalg/xorBasis.cpp
---
