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
  bundledCode: "#line 1 \"icpc/lazySegtree.cpp\"\n/**\n * Author: Misuki\n * Date:\
    \ 2024/01/01\n * Description: 0-indexed, range update, range query segment tree.\n\
    \ * Usage:\n *\\ M/T: type of monoid/tag\n *  Mope(M, M): return result of combining\
    \ two monoid\n *  Tope(T f, T g): return result of g(f)\n *  comp(M, T): return\
    \ result of T(M)\n *  modify(l, r, x): add tag to [l, r)\n *  query(l, r): query\
    \ result of [l, r)\n *\n * Status: tested on library checker - range affine range\
    \ sum\n */\n\ntemplate<class M, M(*Mid)(), M(*Mop)(const M&, const M&),\nclass\
    \ T, T(*Tid)(), T(*Top)(const T&, const T&),\nM(*act)(const M&, const T&)>\nstruct\
    \ lazySegmentTree {\n  int size;\n  vector<M> data;\n  vector<T> tag;\n\n  lazySegmentTree(int\
    \ _size) : size(_size),\n  data(2 * size, Mid()), tag(size, Tid()) {}\n\n  lazySegmentTree(vector<M>\
    \ init) : size(ssize(init)),\n  data(2 * size, Mid()), tag(size, Tid()) {\n  \
    \  ranges::copy(init, data.begin() + size);\n    for(int i = size - 1; i > 0;\
    \ i--)\n      data[i] = Mop(data[i << 1], data[i << 1 | 1]);\n  }\n\n  void apply(int\
    \ i, T x) {\n    data[i] = act(data[i], x);\n    if (i < size) tag[i] = Top(tag[i],\
    \ x);\n  }\n\n  void push(unsigned i) {\n    for(int s = (int)bit_width(i) - 1;\
    \ s > 0; s--) {\n      if (tag[i >> s] != Tid()) {\n        apply(i >> (s - 1),\
    \ tag[i >> s]);\n        apply(i >> (s - 1) ^ 1, tag[i >> s]);\n        tag[i\
    \ >> s] = Tid();\n      }\n    }\n  }\n\n  void pull(int i) {\n    while(i >>=\
    \ 1) \n      data[i] = Mop(data[i << 1], data[i << 1 | 1]);\n  }\n\n  int trunc(unsigned\
    \ i) { return i >> countr_zero(i); }\n\n  void set(int i, M x) {\n    push(i +=\
    \ size);\n    data[i] = x;\n    pull(i);\n  }\n\n  M get(int i) { push(i += size);\
    \ return data[i]; }\n\n  void modify(int l, int r, T x) {\n    if (l >= r or x\
    \ == Tid()) return;\n    push(trunc(l += size)), push(trunc(r += size) - 1);\n\
    \    int l0 = l, r0 = r;\n    for(; l < r; l >>= 1, r >>= 1) {\n      if (l &\
    \ 1) apply(l++, x);\n      if (r & 1) apply(--r, x);\n    }\n    pull(trunc(l0)),\
    \ pull(trunc(r0) - 1);\n  }\n\n  M query(int l, int r) {\n    if (l >= r) return\
    \ Mid();\n    M L = Mid(), R = Mid();\n    push(trunc(l += size)), push(trunc(r\
    \ += size) - 1);\n    for(; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) L = Mop(L,\
    \ data[l++]);\n      if (r & 1) R = Mop(data[--r], R);\n    }\n    return Mop(L,\
    \ R);\n  }\n};\n"
  code: "/**\n * Author: Misuki\n * Date: 2024/01/01\n * Description: 0-indexed, range\
    \ update, range query segment tree.\n * Usage:\n *\\ M/T: type of monoid/tag\n\
    \ *  Mope(M, M): return result of combining two monoid\n *  Tope(T f, T g): return\
    \ result of g(f)\n *  comp(M, T): return result of T(M)\n *  modify(l, r, x):\
    \ add tag to [l, r)\n *  query(l, r): query result of [l, r)\n *\n * Status: tested\
    \ on library checker - range affine range sum\n */\n\ntemplate<class M, M(*Mid)(),\
    \ M(*Mop)(const M&, const M&),\nclass T, T(*Tid)(), T(*Top)(const T&, const T&),\n\
    M(*act)(const M&, const T&)>\nstruct lazySegmentTree {\n  int size;\n  vector<M>\
    \ data;\n  vector<T> tag;\n\n  lazySegmentTree(int _size) : size(_size),\n  data(2\
    \ * size, Mid()), tag(size, Tid()) {}\n\n  lazySegmentTree(vector<M> init) : size(ssize(init)),\n\
    \  data(2 * size, Mid()), tag(size, Tid()) {\n    ranges::copy(init, data.begin()\
    \ + size);\n    for(int i = size - 1; i > 0; i--)\n      data[i] = Mop(data[i\
    \ << 1], data[i << 1 | 1]);\n  }\n\n  void apply(int i, T x) {\n    data[i] =\
    \ act(data[i], x);\n    if (i < size) tag[i] = Top(tag[i], x);\n  }\n\n  void\
    \ push(unsigned i) {\n    for(int s = (int)bit_width(i) - 1; s > 0; s--) {\n \
    \     if (tag[i >> s] != Tid()) {\n        apply(i >> (s - 1), tag[i >> s]);\n\
    \        apply(i >> (s - 1) ^ 1, tag[i >> s]);\n        tag[i >> s] = Tid();\n\
    \      }\n    }\n  }\n\n  void pull(int i) {\n    while(i >>= 1) \n      data[i]\
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
    \      if (r & 1) R = Mop(data[--r], R);\n    }\n    return Mop(L, R);\n  }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: icpc/lazySegtree.cpp
  requiredBy: []
  timestamp: '2025-03-16 13:08:04+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc/lazySegtree.cpp
layout: document
redirect_from:
- /library/icpc/lazySegtree.cpp
- /library/icpc/lazySegtree.cpp.html
title: icpc/lazySegtree.cpp
---
