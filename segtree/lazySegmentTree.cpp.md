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
  bundledCode: "#line 1 \"segtree/lazySegmentTree.cpp\"\ntemplate<class M, M(*Mid)(),\
    \ M(*Mop)(const M&, const M&), class T, T(*Tid)(), T(*Top)(const T&, const T&),\
    \ M(*act)(const M&, const T&)>\nstruct lazySegmentTree {\n  int size;\n  vector<M>\
    \ data;\n  vector<T> tag;\n\n  lazySegmentTree(int _size) : size(_size), data(2\
    \ * size, Mid()), tag(size, Tid()) {}\n\n  lazySegmentTree(vector<M> init) : size(ssize(init)),\
    \ data(2 * size, Mid()), tag(size, Tid()) {\n    ranges::copy(init, data.begin()\
    \ + size);\n    for(int i = size - 1; i > 0; i--)\n      data[i] = Mop(data[i\
    \ << 1], data[i << 1 | 1]);\n  }\n\n  void apply(int i, T x) {\n    data[i] =\
    \ act(data[i], x);\n    if (i < size) tag[i] = Top(tag[i], x);\n  }\n\n  void\
    \ push(unsigned i) {\n    for(int s = (int)bit_width(i) - 1; s > 0; s--) {\n \
    \     if (tag[i >> s] != Tid()) {\n        apply(i >> (s - 1), tag[i >> s]);\n\
    \        apply(i >> (s - 1) ^ 1, tag[i >> s]);\n        tag[i >> s] = Tid();\n\
    \      }\n    }\n  }\n\n  void pull(int i) {\n    while(i >>= 1) data[i] = Mop(data[i\
    \ << 1], data[i << 1 | 1]);\n  }\n\n  int trunc(unsigned i) { return i >> countr_zero(i);\
    \ }\n\n  void set(int i, M x) {\n    push(i += size);\n    data[i] = x;\n    pull(i);\n\
    \  }\n\n  M get(int i) { push(i += size); return data[i]; }\n\n  void modify(int\
    \ l, int r, T x) {\n    if (l >= r or x == Tid()) return;\n    push(trunc(l +=\
    \ size)), push(trunc(r += size) - 1);\n    int l0 = l, r0 = r;\n    for(; l <\
    \ r; l >>= 1, r >>= 1) {\n      if (l & 1) apply(l++, x);\n      if (r & 1) apply(--r,\
    \ x);\n    }\n    pull(trunc(l0)), pull(trunc(r0) - 1);\n  }\n\n  M query(int\
    \ l, int r) {\n    if (l >= r) return Mid();\n    M L = Mid(), R = Mid();\n  \
    \  push(trunc(l += size)), push(trunc(r += size) - 1);\n    for(; l < r; l >>=\
    \ 1, r >>= 1) {\n      if (l & 1) L = Mop(L, data[l++]);\n      if (r & 1) R =\
    \ Mop(data[--r], R);\n    }\n    return Mop(L, R);\n  }\n\n  int firstTrue(int\
    \ i, function<bool(const M&)> f) {\n    vector<int> idL, idR;\n    push(trunc(i\
    \ + size)), push(trunc(size << 1) - 1);\n    for(int l = i + size, r = size <<\
    \ 1; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) idL.emplace_back(l++);\n   \
    \   if (r & 1) idR.emplace_back(--r);\n    }\n    idL.insert(idL.end(), idR.rbegin(),\
    \ idR.rend());\n    M pre = Mid();\n    int v = -1;\n    for(int j : idL) {\n\
    \      if (f(Mop(pre, data[j]))) {\n        v = j;\n        break;\n      } else\
    \ {\n        pre = Mop(pre, data[j]);\n      }\n    }\n    if (v == -1) return\
    \ size;\n    while(v < size) {\n      if (tag[v] != Tid()) {\n        apply(v\
    \ << 1, tag[v]);\n        apply(v << 1 | 1, tag[v]);\n        tag[v] = Tid();\n\
    \      }\n      if (f(Mop(pre, data[v << 1])))\n        v = v << 1;\n      else\n\
    \        pre = Mop(pre, data[v << 1]), v = v << 1 | 1;\n    }\n    return v -\
    \ size;\n  }\n\n  int lastTrue(int i, function<bool(const M&)> f) {\n    vector<int>\
    \ idL, idR;\n    push(trunc(size)), push(trunc((i + 1) + size) - 1);\n    for(int\
    \ l = size, r = (i + 1) + size; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) idL.emplace_back(l++);\n\
    \      if (r & 1) idR.emplace_back(--r);\n    }\n    idR.insert(idR.end(), idL.rbegin(),\
    \ idL.rend());\n    M suf = Mid();\n    int v = -1;\n    for(int j : idR) {\n\
    \      if (f(Mop(data[j], suf))) {\n        v = j;\n        break;\n      } else\
    \ {\n        suf = Mop(data[j], suf);\n      }\n    }\n    if (v == -1) return\
    \ -1;\n    while(v < size) {\n      if (tag[v] != Tid()) {\n        apply(v <<\
    \ 1, tag[v]);\n        apply(v << 1 | 1, tag[v]);\n        tag[v] = Tid();\n \
    \     }\n      if (f(Mop(data[v << 1 | 1], suf)))\n        v = v << 1 | 1;\n \
    \     else\n        suf = Mop(data[v << 1 | 1], suf), v = v << 1;\n    }\n   \
    \ return v - size;\n  }\n};\n"
  code: "template<class M, M(*Mid)(), M(*Mop)(const M&, const M&), class T, T(*Tid)(),\
    \ T(*Top)(const T&, const T&), M(*act)(const M&, const T&)>\nstruct lazySegmentTree\
    \ {\n  int size;\n  vector<M> data;\n  vector<T> tag;\n\n  lazySegmentTree(int\
    \ _size) : size(_size), data(2 * size, Mid()), tag(size, Tid()) {}\n\n  lazySegmentTree(vector<M>\
    \ init) : size(ssize(init)), data(2 * size, Mid()), tag(size, Tid()) {\n    ranges::copy(init,\
    \ data.begin() + size);\n    for(int i = size - 1; i > 0; i--)\n      data[i]\
    \ = Mop(data[i << 1], data[i << 1 | 1]);\n  }\n\n  void apply(int i, T x) {\n\
    \    data[i] = act(data[i], x);\n    if (i < size) tag[i] = Top(tag[i], x);\n\
    \  }\n\n  void push(unsigned i) {\n    for(int s = (int)bit_width(i) - 1; s >\
    \ 0; s--) {\n      if (tag[i >> s] != Tid()) {\n        apply(i >> (s - 1), tag[i\
    \ >> s]);\n        apply(i >> (s - 1) ^ 1, tag[i >> s]);\n        tag[i >> s]\
    \ = Tid();\n      }\n    }\n  }\n\n  void pull(int i) {\n    while(i >>= 1) data[i]\
    \ = Mop(data[i << 1], data[i << 1 | 1]);\n  }\n\n  int trunc(unsigned i) { return\
    \ i >> countr_zero(i); }\n\n  void set(int i, M x) {\n    push(i += size);\n \
    \   data[i] = x;\n    pull(i);\n  }\n\n  M get(int i) { push(i += size); return\
    \ data[i]; }\n\n  void modify(int l, int r, T x) {\n    if (l >= r or x == Tid())\
    \ return;\n    push(trunc(l += size)), push(trunc(r += size) - 1);\n    int l0\
    \ = l, r0 = r;\n    for(; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) apply(l++,\
    \ x);\n      if (r & 1) apply(--r, x);\n    }\n    pull(trunc(l0)), pull(trunc(r0)\
    \ - 1);\n  }\n\n  M query(int l, int r) {\n    if (l >= r) return Mid();\n   \
    \ M L = Mid(), R = Mid();\n    push(trunc(l += size)), push(trunc(r += size) -\
    \ 1);\n    for(; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) L = Mop(L, data[l++]);\n\
    \      if (r & 1) R = Mop(data[--r], R);\n    }\n    return Mop(L, R);\n  }\n\n\
    \  int firstTrue(int i, function<bool(const M&)> f) {\n    vector<int> idL, idR;\n\
    \    push(trunc(i + size)), push(trunc(size << 1) - 1);\n    for(int l = i + size,\
    \ r = size << 1; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) idL.emplace_back(l++);\n\
    \      if (r & 1) idR.emplace_back(--r);\n    }\n    idL.insert(idL.end(), idR.rbegin(),\
    \ idR.rend());\n    M pre = Mid();\n    int v = -1;\n    for(int j : idL) {\n\
    \      if (f(Mop(pre, data[j]))) {\n        v = j;\n        break;\n      } else\
    \ {\n        pre = Mop(pre, data[j]);\n      }\n    }\n    if (v == -1) return\
    \ size;\n    while(v < size) {\n      if (tag[v] != Tid()) {\n        apply(v\
    \ << 1, tag[v]);\n        apply(v << 1 | 1, tag[v]);\n        tag[v] = Tid();\n\
    \      }\n      if (f(Mop(pre, data[v << 1])))\n        v = v << 1;\n      else\n\
    \        pre = Mop(pre, data[v << 1]), v = v << 1 | 1;\n    }\n    return v -\
    \ size;\n  }\n\n  int lastTrue(int i, function<bool(const M&)> f) {\n    vector<int>\
    \ idL, idR;\n    push(trunc(size)), push(trunc((i + 1) + size) - 1);\n    for(int\
    \ l = size, r = (i + 1) + size; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) idL.emplace_back(l++);\n\
    \      if (r & 1) idR.emplace_back(--r);\n    }\n    idR.insert(idR.end(), idL.rbegin(),\
    \ idL.rend());\n    M suf = Mid();\n    int v = -1;\n    for(int j : idR) {\n\
    \      if (f(Mop(data[j], suf))) {\n        v = j;\n        break;\n      } else\
    \ {\n        suf = Mop(data[j], suf);\n      }\n    }\n    if (v == -1) return\
    \ -1;\n    while(v < size) {\n      if (tag[v] != Tid()) {\n        apply(v <<\
    \ 1, tag[v]);\n        apply(v << 1 | 1, tag[v]);\n        tag[v] = Tid();\n \
    \     }\n      if (f(Mop(data[v << 1 | 1], suf)))\n        v = v << 1 | 1;\n \
    \     else\n        suf = Mop(data[v << 1 | 1], suf), v = v << 1;\n    }\n   \
    \ return v - size;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/lazySegmentTree.cpp
  requiredBy: []
  timestamp: '2024-08-31 23:11:05+08:00'
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
