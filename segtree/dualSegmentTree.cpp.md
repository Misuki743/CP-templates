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
  bundledCode: "#line 1 \"segtree/dualSegmentTree.cpp\"\n/**\n * template name: dualSegmentTree\n\
    \ * author: Misuki\n * last update: 2024/01/11\n * verify: Library Checker - Range\
    \ Affine Point Get\n */\n\ntemplate<class M, class T, M(*Munit)(), T(*Tunit)(),\
    \ T(*Tope)(const T&, const T&), M(*comp)(const M&, const T&)>\nstruct dualSegmentTree\
    \ {\n  vector<M> data;\n  vector<T> tag;\n  int size, h;\n\n  dualSegmentTree(int\
    \ _size) : data(_size, Munit()), tag(_size, Tunit()), size(_size), h(bit_width((unsigned)_size))\
    \ {}\n  dualSegmentTree(vector<M> init) : data(init), tag(ssize(init), Tunit()),\
    \ size(ssize(init)), h(bit_width(init.size())) {}\n\n  void apply(int i, T x)\
    \ {\n    if (i < size)\n      tag[i] = Tope(tag[i], x);\n    else\n      data[i\
    \ - size] = comp(data[i - size], x);\n  }\n\n  void push(int i) {\n    if (i <\
    \ size or i >= 2 * size) return;\n    for(int s = h - 1; s > 0; s--) {\n     \
    \ if (tag[i >> s] != Tunit()) {\n        apply(i >> (s - 1), tag[i >> s]);\n \
    \       apply(i >> (s - 1) ^ 1, tag[i >> s]);\n        tag[i >> s] = Tunit();\n\
    \      }\n    }\n  }\n\n  void set(int i, M x) {\n    push(i + size);\n    data[i]\
    \ = x;\n  }\n\n  M get(int i) {\n    push(i + size);\n    return data[i];\n  }\n\
    \n  void modify(int l, int r, T x) {\n    if (x == Tunit()) return;\n    push(l\
    \ + size), push(r + size - 1);\n    for(l += size, r += size; l < r; l >>= 1,\
    \ r >>= 1) {\n      if (l & 1) apply(l++, x);\n      if (r & 1) apply(--r, x);\n\
    \    }\n  }\n};\n"
  code: "/**\n * template name: dualSegmentTree\n * author: Misuki\n * last update:\
    \ 2024/01/11\n * verify: Library Checker - Range Affine Point Get\n */\n\ntemplate<class\
    \ M, class T, M(*Munit)(), T(*Tunit)(), T(*Tope)(const T&, const T&), M(*comp)(const\
    \ M&, const T&)>\nstruct dualSegmentTree {\n  vector<M> data;\n  vector<T> tag;\n\
    \  int size, h;\n\n  dualSegmentTree(int _size) : data(_size, Munit()), tag(_size,\
    \ Tunit()), size(_size), h(bit_width((unsigned)_size)) {}\n  dualSegmentTree(vector<M>\
    \ init) : data(init), tag(ssize(init), Tunit()), size(ssize(init)), h(bit_width(init.size()))\
    \ {}\n\n  void apply(int i, T x) {\n    if (i < size)\n      tag[i] = Tope(tag[i],\
    \ x);\n    else\n      data[i - size] = comp(data[i - size], x);\n  }\n\n  void\
    \ push(int i) {\n    if (i < size or i >= 2 * size) return;\n    for(int s = h\
    \ - 1; s > 0; s--) {\n      if (tag[i >> s] != Tunit()) {\n        apply(i >>\
    \ (s - 1), tag[i >> s]);\n        apply(i >> (s - 1) ^ 1, tag[i >> s]);\n    \
    \    tag[i >> s] = Tunit();\n      }\n    }\n  }\n\n  void set(int i, M x) {\n\
    \    push(i + size);\n    data[i] = x;\n  }\n\n  M get(int i) {\n    push(i +\
    \ size);\n    return data[i];\n  }\n\n  void modify(int l, int r, T x) {\n   \
    \ if (x == Tunit()) return;\n    push(l + size), push(r + size - 1);\n    for(l\
    \ += size, r += size; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) apply(l++,\
    \ x);\n      if (r & 1) apply(--r, x);\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/dualSegmentTree.cpp
  requiredBy: []
  timestamp: '2024-01-20 02:52:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segtree/dualSegmentTree.cpp
layout: document
redirect_from:
- /library/segtree/dualSegmentTree.cpp
- /library/segtree/dualSegmentTree.cpp.html
title: segtree/dualSegmentTree.cpp
---
