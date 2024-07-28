---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/line_add_get_min.test.cpp
    title: test/line_add_get_min.test.cpp
  - icon: ':x:'
    path: test/segment_add_get_min.test.cpp
    title: test/segment_add_get_min.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segtree/lichaoSegmentTree.cpp\"\n//note: size should be\
    \ power of 2, finding min line in default\n\ntemplate<class M, M unit>\nstruct\
    \ lichaoSegmentTree {\n  vector<array<M, 2>> data;\n  vector<M> xMid;\n  unsigned\
    \ size;\n\n  lichaoSegmentTree(unsigned _size, vector<M> x = vector<M>()) : data(2\
    \ * _size, {0, unit}), xMid(2 * _size), size(_size) {\n    assert(popcount(size)\
    \ == 1);\n    if (x.empty()) {\n      iota(xMid.begin() + size, xMid.end(), 0);\n\
    \    } else {\n      copy(x.begin(), x.end(), xMid.begin() + size);\n      fill(xMid.begin()\
    \ + size + ssize(x), xMid.end(), x.back());\n    }\n    vector<int> r(2 * size);\n\
    \    iota(r.begin() + size, r.end(), size);\n    for(int i = size - 1; i > 0;\
    \ i--)\n      r[i] = r[i << 1 | 1];\n    for(int i = size - 1; i > 0; i--)\n \
    \     xMid[i] = (xMid[r[i << 1]] + xMid[r[i << 1] + 1]) / 2;\n  }\n\n  M eval(M\
    \ a, M b, M x) { return a * x + b; }\n\n  void insert(int v, M a, M b) {\n   \
    \ if (a > data[v][0]) {\n      swap(a, data[v][0]);\n      swap(b, data[v][1]);\n\
    \    }\n\n    if (v >= size) {\n      if (eval(a, b, xMid[v]) < eval(data[v][0],\
    \ data[v][1], xMid[v])) {\n        swap(a, data[v][0]);\n        swap(b, data[v][1]);\n\
    \      }\n      return;\n    }\n\n    if (eval(a, b, xMid[v]) > eval(data[v][0],\
    \ data[v][1], xMid[v])) {\n      insert(v << 1 | 1, a, b);\n    } else {\n   \
    \   swap(a, data[v][0]);\n      swap(b, data[v][1]);\n      insert(v << 1, a,\
    \ b);\n    }\n  }\n\n  M query(int v) {\n    v += size;\n    M ans = unit;\n \
    \   int x = xMid[v];\n    while(v >= 1)\n      ans = min(ans, eval(data[v][0],\
    \ data[v][1], x)), v >>= 1;\n    return ans;\n  }\n\n  void insertRange(int l,\
    \ int r, M a, M b) {\n    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {\n\
    \      if (l & 1) insert(l++, a, b);\n      if (r & 1) insert(--r, a, b);\n  \
    \  }\n  }\n};\n"
  code: "//note: size should be power of 2, finding min line in default\n\ntemplate<class\
    \ M, M unit>\nstruct lichaoSegmentTree {\n  vector<array<M, 2>> data;\n  vector<M>\
    \ xMid;\n  unsigned size;\n\n  lichaoSegmentTree(unsigned _size, vector<M> x =\
    \ vector<M>()) : data(2 * _size, {0, unit}), xMid(2 * _size), size(_size) {\n\
    \    assert(popcount(size) == 1);\n    if (x.empty()) {\n      iota(xMid.begin()\
    \ + size, xMid.end(), 0);\n    } else {\n      copy(x.begin(), x.end(), xMid.begin()\
    \ + size);\n      fill(xMid.begin() + size + ssize(x), xMid.end(), x.back());\n\
    \    }\n    vector<int> r(2 * size);\n    iota(r.begin() + size, r.end(), size);\n\
    \    for(int i = size - 1; i > 0; i--)\n      r[i] = r[i << 1 | 1];\n    for(int\
    \ i = size - 1; i > 0; i--)\n      xMid[i] = (xMid[r[i << 1]] + xMid[r[i << 1]\
    \ + 1]) / 2;\n  }\n\n  M eval(M a, M b, M x) { return a * x + b; }\n\n  void insert(int\
    \ v, M a, M b) {\n    if (a > data[v][0]) {\n      swap(a, data[v][0]);\n    \
    \  swap(b, data[v][1]);\n    }\n\n    if (v >= size) {\n      if (eval(a, b, xMid[v])\
    \ < eval(data[v][0], data[v][1], xMid[v])) {\n        swap(a, data[v][0]);\n \
    \       swap(b, data[v][1]);\n      }\n      return;\n    }\n\n    if (eval(a,\
    \ b, xMid[v]) > eval(data[v][0], data[v][1], xMid[v])) {\n      insert(v << 1\
    \ | 1, a, b);\n    } else {\n      swap(a, data[v][0]);\n      swap(b, data[v][1]);\n\
    \      insert(v << 1, a, b);\n    }\n  }\n\n  M query(int v) {\n    v += size;\n\
    \    M ans = unit;\n    int x = xMid[v];\n    while(v >= 1)\n      ans = min(ans,\
    \ eval(data[v][0], data[v][1], x)), v >>= 1;\n    return ans;\n  }\n\n  void insertRange(int\
    \ l, int r, M a, M b) {\n    for(l += size, r += size; l < r; l >>= 1, r >>= 1)\
    \ {\n      if (l & 1) insert(l++, a, b);\n      if (r & 1) insert(--r, a, b);\n\
    \    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/lichaoSegmentTree.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/segment_add_get_min.test.cpp
  - test/line_add_get_min.test.cpp
documentation_of: segtree/lichaoSegmentTree.cpp
layout: document
redirect_from:
- /library/segtree/lichaoSegmentTree.cpp
- /library/segtree/lichaoSegmentTree.cpp.html
title: segtree/lichaoSegmentTree.cpp
---
