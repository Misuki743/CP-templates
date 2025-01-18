---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/range_set_range_composite.test.cpp
    title: test/range_set_range_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segtree/rangeSetSegmentTree.cpp\"\ntemplate<class M, M(*id)(),\
    \ M(*op)(const M&, const M&)>\nstruct rangeSetSegmentTree {\n  vector<M> data,\
    \ pre;\n  vector<int> tagId;\n  int size, nxt;\n\n  rangeSetSegmentTree(int _size)\
    \ : data(2 * _size, id()), pre(_size), tagId(_size, -1), size(_size), nxt(0) {}\n\
    \n  rangeSetSegmentTree(vector<M> init) : data(2 * ssize(init), id()), pre(ssize(init)),\
    \ tagId(ssize(init), -1), size(ssize(init)), nxt(0) {\n    copy(init.begin(),\
    \ init.end(), data.begin() + size);\n    for(int i = size - 1; i > 0; i--)\n \
    \     data[i] = op(data[i << 1], data[i << 1 | 1]);\n  }\n\n  void apply(int i,\
    \ int tId) {\n    data[i] = pre[tId];\n    if (i < size) tagId[i] = tId;\n  }\n\
    \n  void push(int i) {\n    for(int s = (int)bit_width((unsigned)i) - 1; s > 0;\
    \ s--) {\n      if (tagId[i >> s] != -1) {\n        apply(i >> (s - 1), tagId[i\
    \ >> s] - 1);\n        apply(i >> (s - 1) ^ 1, tagId[i >> s] - 1);\n        tagId[i\
    \ >> s] = -1;\n      }\n    }\n  }\n\n  void pull(int i) {\n    while(i >>= 1)\
    \ data[i] = op(data[i << 1], data[i << 1 | 1]);\n  }\n\n  int trunc(unsigned i)\
    \ { return i >> countr_zero(i); }\n\n  void set(int i, M x) {\n    push(i + size);\n\
    \    data[i + size] = x;\n    pull(i + size);\n  }\n\n  M get(int i) {\n    push(i\
    \ + size);\n    return data[i + size];\n  }\n\n  void set(int l, int r, M x) {\n\
    \    if (l >= r or x == id()) return;\n    if (nxt + bit_width((unsigned)size)\
    \ > size) {\n      for(int i = 1; i < size; i++) {\n        if (tagId[i] != -1)\
    \ {\n          apply(i << 1, tagId[i] - 1);\n          apply(i << 1 | 1, tagId[i]\
    \ - 1);\n          tagId[i] = -1;\n        }\n      }\n      nxt = 0;\n    }\n\
    \    for(int i = 0; i < bit_width((unsigned)size); i++, x = op(x, x))\n      pre[nxt++]\
    \ = x;\n    push(trunc(l += size)), push(trunc(r += size) - 1);\n    int l0 =\
    \ l, r0 = r;\n    for(int tId = nxt - (int)bit_width((unsigned)size); l < r; l\
    \ >>= 1, r >>= 1, tId++) {\n      if (l & 1) apply(l++, tId);\n      if (r & 1)\
    \ apply(--r, tId);\n    }\n    pull(trunc(l0)), pull(trunc(r0) - 1);\n  }\n\n\
    \  M query(int l, int r) {\n    if (l >= r) return id();\n    M L = id(), R =\
    \ id();\n    push(trunc(l += size)), push(trunc(r += size) - 1);\n    for(; l\
    \ < r; l >>= 1, r >>= 1) {\n      if (l & 1) L = op(L, data[l++]);\n      if (r\
    \ & 1) R = op(data[--r], R);\n    }\n    return op(L, R);\n  }\n};\n"
  code: "template<class M, M(*id)(), M(*op)(const M&, const M&)>\nstruct rangeSetSegmentTree\
    \ {\n  vector<M> data, pre;\n  vector<int> tagId;\n  int size, nxt;\n\n  rangeSetSegmentTree(int\
    \ _size) : data(2 * _size, id()), pre(_size), tagId(_size, -1), size(_size), nxt(0)\
    \ {}\n\n  rangeSetSegmentTree(vector<M> init) : data(2 * ssize(init), id()), pre(ssize(init)),\
    \ tagId(ssize(init), -1), size(ssize(init)), nxt(0) {\n    copy(init.begin(),\
    \ init.end(), data.begin() + size);\n    for(int i = size - 1; i > 0; i--)\n \
    \     data[i] = op(data[i << 1], data[i << 1 | 1]);\n  }\n\n  void apply(int i,\
    \ int tId) {\n    data[i] = pre[tId];\n    if (i < size) tagId[i] = tId;\n  }\n\
    \n  void push(int i) {\n    for(int s = (int)bit_width((unsigned)i) - 1; s > 0;\
    \ s--) {\n      if (tagId[i >> s] != -1) {\n        apply(i >> (s - 1), tagId[i\
    \ >> s] - 1);\n        apply(i >> (s - 1) ^ 1, tagId[i >> s] - 1);\n        tagId[i\
    \ >> s] = -1;\n      }\n    }\n  }\n\n  void pull(int i) {\n    while(i >>= 1)\
    \ data[i] = op(data[i << 1], data[i << 1 | 1]);\n  }\n\n  int trunc(unsigned i)\
    \ { return i >> countr_zero(i); }\n\n  void set(int i, M x) {\n    push(i + size);\n\
    \    data[i + size] = x;\n    pull(i + size);\n  }\n\n  M get(int i) {\n    push(i\
    \ + size);\n    return data[i + size];\n  }\n\n  void set(int l, int r, M x) {\n\
    \    if (l >= r or x == id()) return;\n    if (nxt + bit_width((unsigned)size)\
    \ > size) {\n      for(int i = 1; i < size; i++) {\n        if (tagId[i] != -1)\
    \ {\n          apply(i << 1, tagId[i] - 1);\n          apply(i << 1 | 1, tagId[i]\
    \ - 1);\n          tagId[i] = -1;\n        }\n      }\n      nxt = 0;\n    }\n\
    \    for(int i = 0; i < bit_width((unsigned)size); i++, x = op(x, x))\n      pre[nxt++]\
    \ = x;\n    push(trunc(l += size)), push(trunc(r += size) - 1);\n    int l0 =\
    \ l, r0 = r;\n    for(int tId = nxt - (int)bit_width((unsigned)size); l < r; l\
    \ >>= 1, r >>= 1, tId++) {\n      if (l & 1) apply(l++, tId);\n      if (r & 1)\
    \ apply(--r, tId);\n    }\n    pull(trunc(l0)), pull(trunc(r0) - 1);\n  }\n\n\
    \  M query(int l, int r) {\n    if (l >= r) return id();\n    M L = id(), R =\
    \ id();\n    push(trunc(l += size)), push(trunc(r += size) - 1);\n    for(; l\
    \ < r; l >>= 1, r >>= 1) {\n      if (l & 1) L = op(L, data[l++]);\n      if (r\
    \ & 1) R = op(data[--r], R);\n    }\n    return op(L, R);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/rangeSetSegmentTree.cpp
  requiredBy: []
  timestamp: '2024-08-31 23:11:05+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/range_set_range_composite.test.cpp
documentation_of: segtree/rangeSetSegmentTree.cpp
layout: document
redirect_from:
- /library/segtree/rangeSetSegmentTree.cpp
- /library/segtree/rangeSetSegmentTree.cpp.html
title: segtree/rangeSetSegmentTree.cpp
---
