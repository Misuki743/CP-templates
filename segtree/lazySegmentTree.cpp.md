---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/area_of_union_of_rectangles.test.cpp
    title: test/area_of_union_of_rectangles.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/range_affine_range_sum.test.cpp
    title: test/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segtree/lazySegmentTree.cpp\"\ntemplate<class M, class T,\
    \ M(*Munit)(), T(*Tunit)(), M(*Mope)(const M&, const M&), T(*Tope)(const T&, const\
    \ T&), M(*comp)(const M&, const T&)>\nstruct lazySegmentTree {\n  vector<M> data;\n\
    \  vector<T> tag;\n  int size;\n\n  lazySegmentTree(int _size) : data(2 * _size,\
    \ Munit()), tag(_size, Tunit()), size(_size) {}\n\n  lazySegmentTree(vector<M>\
    \ init) : data(2 * ssize(init), Munit()), tag(ssize(init), Tunit()), size(ssize(init))\
    \ {\n    copy(init.begin(), init.end(), data.begin() + size);\n    for(int i =\
    \ size - 1; i > 0; i--)\n      data[i] = Mope(data[i << 1], data[i << 1 | 1]);\n\
    \  }\n\n  void apply(int i, T x) {\n    data[i] = comp(data[i], x);\n    if (i\
    \ < size) tag[i] = Tope(tag[i], x);\n  }\n\n  void push(int i) {\n    for(int\
    \ s = bit_width((unsigned)i) - 1; s > 0; s--) {\n      if (tag[i >> s] != Tunit())\
    \ {\n        apply(i >> (s - 1), tag[i >> s]);\n        apply(i >> (s - 1) ^ 1,\
    \ tag[i >> s]);\n        tag[i >> s] = Tunit();\n      }\n    }\n  }\n\n  void\
    \ pull(int i) {\n    while(i >>= 1) data[i] = Mope(data[i << 1], data[i << 1 |\
    \ 1]);\n  }\n\n  int trunc(unsigned i) { return i >> countr_zero(i); }\n\n  void\
    \ set(int i, M x) {\n    push(i + size);\n    data[i + size] = x;\n    pull(i\
    \ + size);\n  }\n\n  M get(int i) {\n    push(i + size);\n    return data[i +\
    \ size];\n  }\n\n  void modify(int l, int r, T x) {\n    if (l >= r or x == Tunit())\
    \ return;\n    push(trunc(l += size)), push(trunc(r += size) - 1);\n    int l0\
    \ = l, r0 = r;\n    for(; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) apply(l++,\
    \ x);\n      if (r & 1) apply(--r, x);\n    }\n    pull(trunc(l0)), pull(trunc(r0)\
    \ - 1);\n  }\n\n  M query(int l, int r) {\n    if (l >= r) return Munit();\n \
    \   M L = Munit(), R = Munit();\n    push(trunc(l += size)), push(trunc(r += size)\
    \ - 1);\n    for(; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) L = Mope(L, data[l++]);\n\
    \      if (r & 1) R = Mope(data[--r], R);\n    }\n    return Mope(L, R);\n  }\n\
    \n  int firstTrue(int l, int r, function<bool(const M&)> f) {\n    vector<int>\
    \ idL, idR;\n    int r0 = r;\n    push(trunc(l + size)), push(trunc(r + size)\
    \ - 1);\n    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {\n      if (l\
    \ & 1) idL.emplace_back(l++);\n      if (r & 1) idR.emplace_back(--r);\n    }\n\
    \    while(!idR.empty()) {\n      idL.emplace_back(idR.back());\n      idR.pop_back();\n\
    \    }\n    M pre = Munit();\n    int v = -1;\n    for(int i : idL) {\n      if\
    \ (f(Mope(pre, data[i]))) {\n        v = i;\n        break;\n      } else {\n\
    \        pre = Mope(pre, data[i]);\n      }\n    }\n    if (v == -1)\n      return\
    \ r0;\n    while(v < size) {\n      if (tag[v] != Tunit()) {\n        apply(v\
    \ << 1, tag[v]);\n        apply(v << 1 | 1, tag[v]);\n        tag[v] = Tunit();\n\
    \      }\n      if (f(Mope(pre, data[v << 1])))\n        v = v << 1;\n      else\n\
    \        pre = Mope(pre, data[v << 1]), v = v << 1 | 1;\n    }\n    return v -\
    \ size;\n  }\n};\n"
  code: "template<class M, class T, M(*Munit)(), T(*Tunit)(), M(*Mope)(const M&, const\
    \ M&), T(*Tope)(const T&, const T&), M(*comp)(const M&, const T&)>\nstruct lazySegmentTree\
    \ {\n  vector<M> data;\n  vector<T> tag;\n  int size;\n\n  lazySegmentTree(int\
    \ _size) : data(2 * _size, Munit()), tag(_size, Tunit()), size(_size) {}\n\n \
    \ lazySegmentTree(vector<M> init) : data(2 * ssize(init), Munit()), tag(ssize(init),\
    \ Tunit()), size(ssize(init)) {\n    copy(init.begin(), init.end(), data.begin()\
    \ + size);\n    for(int i = size - 1; i > 0; i--)\n      data[i] = Mope(data[i\
    \ << 1], data[i << 1 | 1]);\n  }\n\n  void apply(int i, T x) {\n    data[i] =\
    \ comp(data[i], x);\n    if (i < size) tag[i] = Tope(tag[i], x);\n  }\n\n  void\
    \ push(int i) {\n    for(int s = bit_width((unsigned)i) - 1; s > 0; s--) {\n \
    \     if (tag[i >> s] != Tunit()) {\n        apply(i >> (s - 1), tag[i >> s]);\n\
    \        apply(i >> (s - 1) ^ 1, tag[i >> s]);\n        tag[i >> s] = Tunit();\n\
    \      }\n    }\n  }\n\n  void pull(int i) {\n    while(i >>= 1) data[i] = Mope(data[i\
    \ << 1], data[i << 1 | 1]);\n  }\n\n  int trunc(unsigned i) { return i >> countr_zero(i);\
    \ }\n\n  void set(int i, M x) {\n    push(i + size);\n    data[i + size] = x;\n\
    \    pull(i + size);\n  }\n\n  M get(int i) {\n    push(i + size);\n    return\
    \ data[i + size];\n  }\n\n  void modify(int l, int r, T x) {\n    if (l >= r or\
    \ x == Tunit()) return;\n    push(trunc(l += size)), push(trunc(r += size) - 1);\n\
    \    int l0 = l, r0 = r;\n    for(; l < r; l >>= 1, r >>= 1) {\n      if (l &\
    \ 1) apply(l++, x);\n      if (r & 1) apply(--r, x);\n    }\n    pull(trunc(l0)),\
    \ pull(trunc(r0) - 1);\n  }\n\n  M query(int l, int r) {\n    if (l >= r) return\
    \ Munit();\n    M L = Munit(), R = Munit();\n    push(trunc(l += size)), push(trunc(r\
    \ += size) - 1);\n    for(; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) L = Mope(L,\
    \ data[l++]);\n      if (r & 1) R = Mope(data[--r], R);\n    }\n    return Mope(L,\
    \ R);\n  }\n\n  int firstTrue(int l, int r, function<bool(const M&)> f) {\n  \
    \  vector<int> idL, idR;\n    int r0 = r;\n    push(trunc(l + size)), push(trunc(r\
    \ + size) - 1);\n    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {\n  \
    \    if (l & 1) idL.emplace_back(l++);\n      if (r & 1) idR.emplace_back(--r);\n\
    \    }\n    while(!idR.empty()) {\n      idL.emplace_back(idR.back());\n     \
    \ idR.pop_back();\n    }\n    M pre = Munit();\n    int v = -1;\n    for(int i\
    \ : idL) {\n      if (f(Mope(pre, data[i]))) {\n        v = i;\n        break;\n\
    \      } else {\n        pre = Mope(pre, data[i]);\n      }\n    }\n    if (v\
    \ == -1)\n      return r0;\n    while(v < size) {\n      if (tag[v] != Tunit())\
    \ {\n        apply(v << 1, tag[v]);\n        apply(v << 1 | 1, tag[v]);\n    \
    \    tag[v] = Tunit();\n      }\n      if (f(Mope(pre, data[v << 1])))\n     \
    \   v = v << 1;\n      else\n        pre = Mope(pre, data[v << 1]), v = v << 1\
    \ | 1;\n    }\n    return v - size;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/lazySegmentTree.cpp
  requiredBy: []
  timestamp: '2024-01-27 18:42:26+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/range_affine_range_sum.test.cpp
  - test/area_of_union_of_rectangles.test.cpp
documentation_of: segtree/lazySegmentTree.cpp
layout: document
redirect_from:
- /library/segtree/lazySegmentTree.cpp
- /library/segtree/lazySegmentTree.cpp.html
title: segtree/lazySegmentTree.cpp
---
