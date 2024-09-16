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
  bundledCode: "#line 1 \"linalg/xorBasis2.cpp\"\ntemplate<int size>\nstruct xorBasis\
    \ {\n  int nxt = 0;\n  bitset<size> *basis[size] = {}, *ids[size] = {};\n  bool\
    \ insert(bitset<size> x) {\n    if (query(x).first) return false;\n    bitset<size>\
    \ v;\n    v[nxt++] = true;\n    for(int i = 0; i < size; i++) {\n      if (x[i])\
    \ {\n        if (!basis[i]) {\n          basis[i] = new bitset<size>(x);\n   \
    \       ids[i] = new bitset<size>(v);\n          return true;\n        }\n   \
    \     x ^= *basis[i], v ^= *ids[i];\n      }\n    }\n    return false;\n  }\n\n\
    \  pair<bool, bitset<size>> query(bitset<size> x) {\n    bitset<size> v;\n   \
    \ for(int i = 0; i < size; i++)\n      if (basis[i] and x[i])\n        x ^= *basis[i],\
    \ v ^= *ids[i];\n    return make_pair(x.none(), v);\n  }\n};\n"
  code: "template<int size>\nstruct xorBasis {\n  int nxt = 0;\n  bitset<size> *basis[size]\
    \ = {}, *ids[size] = {};\n  bool insert(bitset<size> x) {\n    if (query(x).first)\
    \ return false;\n    bitset<size> v;\n    v[nxt++] = true;\n    for(int i = 0;\
    \ i < size; i++) {\n      if (x[i]) {\n        if (!basis[i]) {\n          basis[i]\
    \ = new bitset<size>(x);\n          ids[i] = new bitset<size>(v);\n          return\
    \ true;\n        }\n        x ^= *basis[i], v ^= *ids[i];\n      }\n    }\n  \
    \  return false;\n  }\n\n  pair<bool, bitset<size>> query(bitset<size> x) {\n\
    \    bitset<size> v;\n    for(int i = 0; i < size; i++)\n      if (basis[i] and\
    \ x[i])\n        x ^= *basis[i], v ^= *ids[i];\n    return make_pair(x.none(),\
    \ v);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/xorBasis2.cpp
  requiredBy: []
  timestamp: '2024-09-04 22:19:12+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/xorBasis2.cpp
layout: document
redirect_from:
- /library/linalg/xorBasis2.cpp
- /library/linalg/xorBasis2.cpp.html
title: linalg/xorBasis2.cpp
---
