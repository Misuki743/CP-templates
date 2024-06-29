---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/range_kth_smallest2.test.cpp
    title: test/range_kth_smallest2.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segtree/persistentSegmentTree.cpp\"\ntemplate<class M, M(*id)(),\
    \ M(*op)(const M&, const M&)>\nstruct persistentSegmentTree {\n  vector<int> lc,\
    \ rc;\n  vector<M> data, init;\n  int nxt = 0;\n\n  //sz >= (2n - 1) + q * (bit_width(n)\
    \ + 1) should be satisfied\n  persistentSegmentTree(int sz, vector<M> _init =\
    \ vector<M>())\n  : lc(sz, -1), rc(sz, -1), data(sz, id()), init(_init) {}\n\n\
    \  int build(int l, int r) {\n    int i = nxt++;\n    if (l + 1 == r) {\n    \
    \  if (!init.empty()) data[i] = init[l];\n    } else {\n      int mid = (l + r)\
    \ / 2;\n      lc[i] = build(l, mid), rc[i] = build(mid, r);\n      data[i] = op(data[lc[i]],\
    \ data[rc[i]]);\n    }\n    return i;\n  }\n\n  int set(int v, int l, int r, int\
    \ i, M x) {  \n    int vv = nxt++;\n    if (l + 1 == r) {\n      data[vv] = x;\n\
    \    } else {\n      if (int mid = (l + r) / 2; i < mid)\n        lc[vv] = set(lc[v],\
    \ l, mid, i, x), rc[vv] = rc[v];\n      else\n        lc[vv] = lc[v], rc[vv] =\
    \ set(rc[v], mid, r, i, x);\n      data[vv] = op(data[lc[vv]], data[rc[vv]]);\n\
    \    }\n    return vv;\n  }\n\n  M query(int i, int l, int r, int ql, int qr)\
    \ {\n    if (ql == qr or i == -1 or r <= ql or l >= qr) return id();\n    if (ql\
    \ <= l and r <= qr) return data[i];\n    return op(query(lc[i], l, (l + r) / 2,\
    \ ql, qr), \n              query(rc[i], (l + r) / 2, r, ql, qr));\n  }\n};\n"
  code: "template<class M, M(*id)(), M(*op)(const M&, const M&)>\nstruct persistentSegmentTree\
    \ {\n  vector<int> lc, rc;\n  vector<M> data, init;\n  int nxt = 0;\n\n  //sz\
    \ >= (2n - 1) + q * (bit_width(n) + 1) should be satisfied\n  persistentSegmentTree(int\
    \ sz, vector<M> _init = vector<M>())\n  : lc(sz, -1), rc(sz, -1), data(sz, id()),\
    \ init(_init) {}\n\n  int build(int l, int r) {\n    int i = nxt++;\n    if (l\
    \ + 1 == r) {\n      if (!init.empty()) data[i] = init[l];\n    } else {\n   \
    \   int mid = (l + r) / 2;\n      lc[i] = build(l, mid), rc[i] = build(mid, r);\n\
    \      data[i] = op(data[lc[i]], data[rc[i]]);\n    }\n    return i;\n  }\n\n\
    \  int set(int v, int l, int r, int i, M x) {  \n    int vv = nxt++;\n    if (l\
    \ + 1 == r) {\n      data[vv] = x;\n    } else {\n      if (int mid = (l + r)\
    \ / 2; i < mid)\n        lc[vv] = set(lc[v], l, mid, i, x), rc[vv] = rc[v];\n\
    \      else\n        lc[vv] = lc[v], rc[vv] = set(rc[v], mid, r, i, x);\n    \
    \  data[vv] = op(data[lc[vv]], data[rc[vv]]);\n    }\n    return vv;\n  }\n\n\
    \  M query(int i, int l, int r, int ql, int qr) {\n    if (ql == qr or i == -1\
    \ or r <= ql or l >= qr) return id();\n    if (ql <= l and r <= qr) return data[i];\n\
    \    return op(query(lc[i], l, (l + r) / 2, ql, qr), \n              query(rc[i],\
    \ (l + r) / 2, r, ql, qr));\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/persistentSegmentTree.cpp
  requiredBy: []
  timestamp: '2024-05-04 14:16:48+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/range_kth_smallest2.test.cpp
documentation_of: segtree/persistentSegmentTree.cpp
layout: document
redirect_from:
- /library/segtree/persistentSegmentTree.cpp
- /library/segtree/persistentSegmentTree.cpp.html
title: segtree/persistentSegmentTree.cpp
---
