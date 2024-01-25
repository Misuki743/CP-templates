---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/point_set_range_composite.test.cpp
    title: test/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/vertex_add_subtree_sum.test.cpp
    title: test/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segtree/segmentTree.cpp\"\ntemplate<class M, M(*unit)(),\
    \ M(*combine)(const M&, const M&)>\nstruct segmentTree {\n  vector<M> data;\n\
    \  int size;\n\n  segmentTree(int _size) : data(2 * _size, unit()), size(_size)\
    \ {}\n\n  segmentTree(vector<M> init) : data(2 * ssize(init), unit()), size(ssize(init))\
    \ {\n    copy(init.begin(), init.end(), data.begin() + size);\n    for(int i =\
    \ size - 1; i > 0; i--)\n      data[i] = combine(data[i << 1], data[i << 1 | 1]);\n\
    \  }\n\n  void set(int i, M x) {\n    data[i += size] = x;\n    while(i >>= 1)\n\
    \      data[i] = combine(data[i << 1], data[i << 1 | 1]);\n  }\n\n  M get(int\
    \ i) { return data[i + size]; }\n\n  M query(int l, int r) {\n    M L = unit(),\
    \ R = unit();\n    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {\n    \
    \  if (l & 1) L = combine(L, data[l++]);\n      if (r & 1) R = combine(data[--r],\
    \ R);\n    }\n    return combine(L, R);\n  }\n};\n"
  code: "template<class M, M(*unit)(), M(*combine)(const M&, const M&)>\nstruct segmentTree\
    \ {\n  vector<M> data;\n  int size;\n\n  segmentTree(int _size) : data(2 * _size,\
    \ unit()), size(_size) {}\n\n  segmentTree(vector<M> init) : data(2 * ssize(init),\
    \ unit()), size(ssize(init)) {\n    copy(init.begin(), init.end(), data.begin()\
    \ + size);\n    for(int i = size - 1; i > 0; i--)\n      data[i] = combine(data[i\
    \ << 1], data[i << 1 | 1]);\n  }\n\n  void set(int i, M x) {\n    data[i += size]\
    \ = x;\n    while(i >>= 1)\n      data[i] = combine(data[i << 1], data[i << 1\
    \ | 1]);\n  }\n\n  M get(int i) { return data[i + size]; }\n\n  M query(int l,\
    \ int r) {\n    M L = unit(), R = unit();\n    for(l += size, r += size; l < r;\
    \ l >>= 1, r >>= 1) {\n      if (l & 1) L = combine(L, data[l++]);\n      if (r\
    \ & 1) R = combine(data[--r], R);\n    }\n    return combine(L, R);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/segmentTree.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/vertex_add_subtree_sum.test.cpp
  - test/point_set_range_composite.test.cpp
documentation_of: segtree/segmentTree.cpp
layout: document
redirect_from:
- /library/segtree/segmentTree.cpp
- /library/segtree/segmentTree.cpp.html
title: segtree/segmentTree.cpp
---
