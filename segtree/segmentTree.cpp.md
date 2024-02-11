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
  - icon: ':heavy_check_mark:'
    path: test/vertex_set_path_composite.test.cpp
    title: test/vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segtree/segmentTree.cpp\"\ntemplate<class M, M(*id)(), M(*op)(const\
    \ M&, const M&)>\nstruct segmentTree {\n  vector<M> data;\n  int size;\n\n  segmentTree(int\
    \ _size) : data(2 * _size, id()), size(_size) {}\n\n  segmentTree(vector<M> init)\
    \ : data(2 * ssize(init), id()), size(ssize(init)) {\n    copy(init.begin(), init.end(),\
    \ data.begin() + size);\n    for(int i = size - 1; i > 0; i--)\n      data[i]\
    \ = op(data[i << 1], data[i << 1 | 1]);\n  }\n\n  void set(int i, M x) {\n   \
    \ data[i += size] = x;\n    while(i >>= 1)\n      data[i] = op(data[i << 1], data[i\
    \ << 1 | 1]);\n  }\n\n  M get(int i) { return data[i + size]; }\n\n  M query(int\
    \ l, int r) {\n    M L = id(), R = id();\n    for(l += size, r += size; l < r;\
    \ l >>= 1, r >>= 1) {\n      if (l & 1) L = op(L, data[l++]);\n      if (r & 1)\
    \ R = op(data[--r], R);\n    }\n    return op(L, R);\n  }\n};\n"
  code: "template<class M, M(*id)(), M(*op)(const M&, const M&)>\nstruct segmentTree\
    \ {\n  vector<M> data;\n  int size;\n\n  segmentTree(int _size) : data(2 * _size,\
    \ id()), size(_size) {}\n\n  segmentTree(vector<M> init) : data(2 * ssize(init),\
    \ id()), size(ssize(init)) {\n    copy(init.begin(), init.end(), data.begin()\
    \ + size);\n    for(int i = size - 1; i > 0; i--)\n      data[i] = op(data[i <<\
    \ 1], data[i << 1 | 1]);\n  }\n\n  void set(int i, M x) {\n    data[i += size]\
    \ = x;\n    while(i >>= 1)\n      data[i] = op(data[i << 1], data[i << 1 | 1]);\n\
    \  }\n\n  M get(int i) { return data[i + size]; }\n\n  M query(int l, int r) {\n\
    \    M L = id(), R = id();\n    for(l += size, r += size; l < r; l >>= 1, r >>=\
    \ 1) {\n      if (l & 1) L = op(L, data[l++]);\n      if (r & 1) R = op(data[--r],\
    \ R);\n    }\n    return op(L, R);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/segmentTree.cpp
  requiredBy: []
  timestamp: '2024-02-09 21:58:48+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/vertex_set_path_composite.test.cpp
  - test/vertex_add_subtree_sum.test.cpp
  - test/point_set_range_composite.test.cpp
documentation_of: segtree/segmentTree.cpp
layout: document
redirect_from:
- /library/segtree/segmentTree.cpp
- /library/segtree/segmentTree.cpp.html
title: segtree/segmentTree.cpp
---
