---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Point_Set_Range_Composite.test.cpp
    title: Point_Set_Range_Composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segmentTree.cpp\"\n/**\n * template name: segmentTree\n\
    \ * author: Misuki\n * last update: 2024/01/01\n * verify: library checker - Point\
    \ Add Range Sum, Static RMQ\n */\n\ntemplate<class M, M(*unit)(), M(*combine)(const\
    \ M&, const M&)>\nstruct segmentTree {\n  vector<M> data;\n  int size;\n\n  segmentTree(int\
    \ _size) : data(2 * _size, unit()), size(_size) {}\n\n  segmentTree(vector<M>\
    \ init) : data(2 * ssize(init), unit()), size(ssize(init)) {\n    copy(init.begin(),\
    \ init.end(), data.begin() + size);\n    for(int i = size - 1; i > 0; i--)\n \
    \     data[i] = combine(data[i << 1], data[i << 1 | 1]);\n  }\n\n\n  void set(int\
    \ i, M x) {\n    i += size, data[i] = x, i >>= 1;\n    while(i)\n      data[i]\
    \ = combine(data[i << 1], data[i << 1 | 1]), i >>= 1;\n  }\n\n  M get(int i) {\
    \ return data[i + size]; }\n\n  M query(int l, int r) {\n    M L = unit(), R =\
    \ unit();\n    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {\n      if\
    \ (l & 1) L = combine(L, data[l++]);\n      if (r & 1) R = combine(data[--r],\
    \ R);\n    }\n    return combine(L, R);\n  }\n};\n"
  code: "/**\n * template name: segmentTree\n * author: Misuki\n * last update: 2024/01/01\n\
    \ * verify: library checker - Point Add Range Sum, Static RMQ\n */\n\ntemplate<class\
    \ M, M(*unit)(), M(*combine)(const M&, const M&)>\nstruct segmentTree {\n  vector<M>\
    \ data;\n  int size;\n\n  segmentTree(int _size) : data(2 * _size, unit()), size(_size)\
    \ {}\n\n  segmentTree(vector<M> init) : data(2 * ssize(init), unit()), size(ssize(init))\
    \ {\n    copy(init.begin(), init.end(), data.begin() + size);\n    for(int i =\
    \ size - 1; i > 0; i--)\n      data[i] = combine(data[i << 1], data[i << 1 | 1]);\n\
    \  }\n\n\n  void set(int i, M x) {\n    i += size, data[i] = x, i >>= 1;\n   \
    \ while(i)\n      data[i] = combine(data[i << 1], data[i << 1 | 1]), i >>= 1;\n\
    \  }\n\n  M get(int i) { return data[i + size]; }\n\n  M query(int l, int r) {\n\
    \    M L = unit(), R = unit();\n    for(l += size, r += size; l < r; l >>= 1,\
    \ r >>= 1) {\n      if (l & 1) L = combine(L, data[l++]);\n      if (r & 1) R\
    \ = combine(data[--r], R);\n    }\n    return combine(L, R);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segmentTree.cpp
  requiredBy: []
  timestamp: '2024-01-06 18:21:41+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Point_Set_Range_Composite.test.cpp
documentation_of: segmentTree.cpp
layout: document
redirect_from:
- /library/segmentTree.cpp
- /library/segmentTree.cpp.html
title: segmentTree.cpp
---
