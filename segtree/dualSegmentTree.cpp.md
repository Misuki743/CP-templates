---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/range_affine_point_get.test.cpp
    title: test/range_affine_point_get.test.cpp
  - icon: ':x:'
    path: test/vertex_add_path_sum.test.cpp
    title: test/vertex_add_path_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segtree/dualSegmentTree.cpp\"\ntemplate<class M, class T,\
    \ M(*Munit)(), T(*Tunit)(), T(*Tope)(const T&, const T&), M(*comp)(const M&, const\
    \ T&)>\nstruct dualSegmentTree {\n  vector<M> data;\n  vector<T> tag;\n  int size;\n\
    \n  dualSegmentTree(int _size) : data(_size, Munit()), tag(_size, Tunit()), size(_size)\
    \ {}\n  dualSegmentTree(vector<M> init) : data(init), tag(ssize(init), Tunit()),\
    \ size(ssize(init)) {}\n\n  void apply(int i, T x) {\n    if (i < size)\n    \
    \  tag[i] = Tope(tag[i], x);\n    else\n      data[i - size] = comp(data[i - size],\
    \ x);\n  }\n\n  int trunc(unsigned i) { return i >> countr_zero(i); }\n\n  void\
    \ push(int i) {\n    for(int s = bit_width((unsigned)i) - 1; s > 0; s--) {\n \
    \     if (tag[i >> s] != Tunit()) {\n        apply(i >> (s - 1), tag[i >> s]);\n\
    \        apply(i >> (s - 1) ^ 1, tag[i >> s]);\n        tag[i >> s] = Tunit();\n\
    \      }\n    }\n  }\n\n  void set(int i, M x) {\n    push(i + size);\n    data[i]\
    \ = x;\n  }\n\n  M get(int i) {\n    push(i + size);\n    return data[i];\n  }\n\
    \n  void modify(int l, int r, T x) {\n    if (x == Tunit()) return;\n    push(trunc(l\
    \ + size)), push(trunc(r + size) - 1);\n    for(l += size, r += size; l < r; l\
    \ >>= 1, r >>= 1) {\n      if (l & 1) apply(l++, x);\n      if (r & 1) apply(--r,\
    \ x);\n    }\n  }\n};\n"
  code: "template<class M, class T, M(*Munit)(), T(*Tunit)(), T(*Tope)(const T&, const\
    \ T&), M(*comp)(const M&, const T&)>\nstruct dualSegmentTree {\n  vector<M> data;\n\
    \  vector<T> tag;\n  int size;\n\n  dualSegmentTree(int _size) : data(_size, Munit()),\
    \ tag(_size, Tunit()), size(_size) {}\n  dualSegmentTree(vector<M> init) : data(init),\
    \ tag(ssize(init), Tunit()), size(ssize(init)) {}\n\n  void apply(int i, T x)\
    \ {\n    if (i < size)\n      tag[i] = Tope(tag[i], x);\n    else\n      data[i\
    \ - size] = comp(data[i - size], x);\n  }\n\n  int trunc(unsigned i) { return\
    \ i >> countr_zero(i); }\n\n  void push(int i) {\n    for(int s = bit_width((unsigned)i)\
    \ - 1; s > 0; s--) {\n      if (tag[i >> s] != Tunit()) {\n        apply(i >>\
    \ (s - 1), tag[i >> s]);\n        apply(i >> (s - 1) ^ 1, tag[i >> s]);\n    \
    \    tag[i >> s] = Tunit();\n      }\n    }\n  }\n\n  void set(int i, M x) {\n\
    \    push(i + size);\n    data[i] = x;\n  }\n\n  M get(int i) {\n    push(i +\
    \ size);\n    return data[i];\n  }\n\n  void modify(int l, int r, T x) {\n   \
    \ if (x == Tunit()) return;\n    push(trunc(l + size)), push(trunc(r + size) -\
    \ 1);\n    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {\n      if (l &\
    \ 1) apply(l++, x);\n      if (r & 1) apply(--r, x);\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/dualSegmentTree.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/range_affine_point_get.test.cpp
  - test/vertex_add_path_sum.test.cpp
documentation_of: segtree/dualSegmentTree.cpp
layout: document
redirect_from:
- /library/segtree/dualSegmentTree.cpp
- /library/segtree/dualSegmentTree.cpp.html
title: segtree/dualSegmentTree.cpp
---
