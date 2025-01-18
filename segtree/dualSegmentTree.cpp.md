---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/range_affine_point_get.test.cpp
    title: test/range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/vertex_add_path_sum.test.cpp
    title: test/vertex_add_path_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segtree/dualSegmentTree.cpp\"\ntemplate<class M, M(*Mid)(),\
    \ class T, T(*Tid)(), T(*Top)(const T&, const T&), M(*act)(const M&, const T&)>\n\
    struct dualSegmentTree {\n  vector<M> data;\n  vector<T> tag;\n  int size;\n\n\
    \  dualSegmentTree(int _size) : data(_size, Mid()), tag(_size, Tid()), size(_size)\
    \ {}\n  dualSegmentTree(vector<M> init) : data(init), tag(ssize(init), Tid()),\
    \ size(ssize(init)) {}\n\n  void apply(int i, T x) {\n    if (i < size)\n    \
    \  tag[i] = Top(tag[i], x);\n    else\n      data[i - size] = act(data[i - size],\
    \ x);\n  }\n\n  int trunc(unsigned i) { return i >> countr_zero(i); }\n\n  void\
    \ push(int i) {\n    for(int s = (int)bit_width((unsigned)i) - 1; s > 0; s--)\
    \ {\n      if (tag[i >> s] != Tid()) {\n        apply(i >> (s - 1), tag[i >> s]);\n\
    \        apply(i >> (s - 1) ^ 1, tag[i >> s]);\n        tag[i >> s] = Tid();\n\
    \      }\n    }\n  }\n\n  void set(int i, M x) {\n    push(i + size);\n    data[i]\
    \ = x;\n  }\n\n  M get(int i) {\n    push(i + size);\n    return data[i];\n  }\n\
    \n  void modify(int l, int r, T x) {\n    if (l >= r or x == Tid()) return;\n\
    \    push(trunc(l + size)), push(trunc(r + size) - 1);\n    for(l += size, r +=\
    \ size; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) apply(l++, x);\n      if\
    \ (r & 1) apply(--r, x);\n    }\n  }\n};\n"
  code: "template<class M, M(*Mid)(), class T, T(*Tid)(), T(*Top)(const T&, const\
    \ T&), M(*act)(const M&, const T&)>\nstruct dualSegmentTree {\n  vector<M> data;\n\
    \  vector<T> tag;\n  int size;\n\n  dualSegmentTree(int _size) : data(_size, Mid()),\
    \ tag(_size, Tid()), size(_size) {}\n  dualSegmentTree(vector<M> init) : data(init),\
    \ tag(ssize(init), Tid()), size(ssize(init)) {}\n\n  void apply(int i, T x) {\n\
    \    if (i < size)\n      tag[i] = Top(tag[i], x);\n    else\n      data[i - size]\
    \ = act(data[i - size], x);\n  }\n\n  int trunc(unsigned i) { return i >> countr_zero(i);\
    \ }\n\n  void push(int i) {\n    for(int s = (int)bit_width((unsigned)i) - 1;\
    \ s > 0; s--) {\n      if (tag[i >> s] != Tid()) {\n        apply(i >> (s - 1),\
    \ tag[i >> s]);\n        apply(i >> (s - 1) ^ 1, tag[i >> s]);\n        tag[i\
    \ >> s] = Tid();\n      }\n    }\n  }\n\n  void set(int i, M x) {\n    push(i\
    \ + size);\n    data[i] = x;\n  }\n\n  M get(int i) {\n    push(i + size);\n \
    \   return data[i];\n  }\n\n  void modify(int l, int r, T x) {\n    if (l >= r\
    \ or x == Tid()) return;\n    push(trunc(l + size)), push(trunc(r + size) - 1);\n\
    \    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) apply(l++,\
    \ x);\n      if (r & 1) apply(--r, x);\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/dualSegmentTree.cpp
  requiredBy: []
  timestamp: '2024-08-31 23:11:05+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/vertex_add_path_sum.test.cpp
  - test/range_affine_point_get.test.cpp
documentation_of: segtree/dualSegmentTree.cpp
layout: document
redirect_from:
- /library/segtree/dualSegmentTree.cpp
- /library/segtree/dualSegmentTree.cpp.html
title: segtree/dualSegmentTree.cpp
---
