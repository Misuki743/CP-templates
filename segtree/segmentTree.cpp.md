---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/point_set_range_composite.test.cpp
    title: test/point_set_range_composite.test.cpp
  - icon: ':x:'
    path: test/vertex_add_subtree_sum.test.cpp
    title: test/vertex_add_subtree_sum.test.cpp
  - icon: ':x:'
    path: test/vertex_set_path_composite.test.cpp
    title: test/vertex_set_path_composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segtree/segmentTree.cpp\"\ntemplate<class M, M(*id)(), M(*op)(const\
    \ M&, const M&)>\nstruct segmentTree {\n  int size;\n  vector<M> data;\n\n  segmentTree(int\
    \ _size) : size(_size), data(2 * size, id()) {}\n  segmentTree(vector<M> init)\
    \ : size(ssize(init)), data(2 * size, id()) {\n    ranges::copy(init, data.begin()\
    \ + size);\n    for(int i = size - 1; i > 0; i--)\n      data[i] = op(data[i <<\
    \ 1], data[i << 1 | 1]);\n  }\n\n  void set(int i, M x) {\n    data[i += size]\
    \ = x;\n    while(i >>= 1)\n      data[i] = op(data[i << 1], data[i << 1 | 1]);\n\
    \  }\n\n  M get(int i) { return data[i + size]; }\n\n  M query(int l, int r) {\n\
    \    M L = id(), R = id();\n    for(l += size, r += size; l < r; l >>= 1, r >>=\
    \ 1) {\n      if (l & 1) L = op(L, data[l++]);\n      if (r & 1) R = op(data[--r],\
    \ R);\n    }\n    return op(L, R);\n  }\n\n  //return first j in [i, size) s.t.\
    \ f(op([l, j])) is true,\n  //assume f(id()) is false.\n  int firstTrue(int i,\
    \ function<bool(const M&)> f) {\n    vector<int> idL, idR;\n    for(int l = i\
    \ + size, r = size << 1; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) idL.emplace_back(l++);\n\
    \      if (r & 1) idR.emplace_back(--r);\n    }\n    idL.insert(idL.end(), idR.rbegin(),\
    \ idR.rend());\n    M pre = id();\n    int v = -1;\n    for(int j : idL) {\n \
    \     if (f(op(pre, data[j]))) {\n        v = j;\n        break;\n      } else\
    \ {\n        pre = op(pre, data[j]);\n      }\n    }\n    if (v == -1) return\
    \ size;\n    while(v < size) {\n      if (f(op(pre, data[v << 1])))\n        v\
    \ = v << 1;\n      else\n        pre = op(pre, data[v << 1]), v = v << 1 | 1;\n\
    \    }\n    return v - size;\n  }\n\n  int lastTrue(int i, function<bool(const\
    \ M&)> f) {\n    vector<int> idL, idR;\n    for(int l = size, r = (i + 1) + size;\
    \ l < r; l >>= 1, r >>= 1) {\n      if (l & 1) idL.emplace_back(l++);\n      if\
    \ (r & 1) idR.emplace_back(--r);\n    }\n    idR.insert(idR.end(), idL.rbegin(),\
    \ idL.rend());\n    M suf = id();\n    int v = -1;\n    for(int j : idR) {\n \
    \     if (f(op(data[j], suf))) {\n        v = j;\n        break;\n      } else\
    \ {\n        suf = op(data[j], suf);\n      }\n    }\n    if (v == -1) return\
    \ -1;\n    while(v < size) {\n      if (f(op(data[v << 1 | 1], suf)))\n      \
    \  v = v << 1 | 1;\n      else\n        suf = op(data[v << 1 | 1], suf), v = v\
    \ << 1;\n    }\n    return v - size;\n  }\n};\n"
  code: "template<class M, M(*id)(), M(*op)(const M&, const M&)>\nstruct segmentTree\
    \ {\n  int size;\n  vector<M> data;\n\n  segmentTree(int _size) : size(_size),\
    \ data(2 * size, id()) {}\n  segmentTree(vector<M> init) : size(ssize(init)),\
    \ data(2 * size, id()) {\n    ranges::copy(init, data.begin() + size);\n    for(int\
    \ i = size - 1; i > 0; i--)\n      data[i] = op(data[i << 1], data[i << 1 | 1]);\n\
    \  }\n\n  void set(int i, M x) {\n    data[i += size] = x;\n    while(i >>= 1)\n\
    \      data[i] = op(data[i << 1], data[i << 1 | 1]);\n  }\n\n  M get(int i) {\
    \ return data[i + size]; }\n\n  M query(int l, int r) {\n    M L = id(), R = id();\n\
    \    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) L\
    \ = op(L, data[l++]);\n      if (r & 1) R = op(data[--r], R);\n    }\n    return\
    \ op(L, R);\n  }\n\n  //return first j in [i, size) s.t. f(op([l, j])) is true,\n\
    \  //assume f(id()) is false.\n  int firstTrue(int i, function<bool(const M&)>\
    \ f) {\n    vector<int> idL, idR;\n    for(int l = i + size, r = size << 1; l\
    \ < r; l >>= 1, r >>= 1) {\n      if (l & 1) idL.emplace_back(l++);\n      if\
    \ (r & 1) idR.emplace_back(--r);\n    }\n    idL.insert(idL.end(), idR.rbegin(),\
    \ idR.rend());\n    M pre = id();\n    int v = -1;\n    for(int j : idL) {\n \
    \     if (f(op(pre, data[j]))) {\n        v = j;\n        break;\n      } else\
    \ {\n        pre = op(pre, data[j]);\n      }\n    }\n    if (v == -1) return\
    \ size;\n    while(v < size) {\n      if (f(op(pre, data[v << 1])))\n        v\
    \ = v << 1;\n      else\n        pre = op(pre, data[v << 1]), v = v << 1 | 1;\n\
    \    }\n    return v - size;\n  }\n\n  int lastTrue(int i, function<bool(const\
    \ M&)> f) {\n    vector<int> idL, idR;\n    for(int l = size, r = (i + 1) + size;\
    \ l < r; l >>= 1, r >>= 1) {\n      if (l & 1) idL.emplace_back(l++);\n      if\
    \ (r & 1) idR.emplace_back(--r);\n    }\n    idR.insert(idR.end(), idL.rbegin(),\
    \ idL.rend());\n    M suf = id();\n    int v = -1;\n    for(int j : idR) {\n \
    \     if (f(op(data[j], suf))) {\n        v = j;\n        break;\n      } else\
    \ {\n        suf = op(data[j], suf);\n      }\n    }\n    if (v == -1) return\
    \ -1;\n    while(v < size) {\n      if (f(op(data[v << 1 | 1], suf)))\n      \
    \  v = v << 1 | 1;\n      else\n        suf = op(data[v << 1 | 1], suf), v = v\
    \ << 1;\n    }\n    return v - size;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/segmentTree.cpp
  requiredBy: []
  timestamp: '2024-08-02 18:14:24+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/point_set_range_composite.test.cpp
  - test/vertex_add_subtree_sum.test.cpp
  - test/vertex_set_path_composite.test.cpp
documentation_of: segtree/segmentTree.cpp
layout: document
redirect_from:
- /library/segtree/segmentTree.cpp
- /library/segtree/segmentTree.cpp.html
title: segtree/segmentTree.cpp
---
