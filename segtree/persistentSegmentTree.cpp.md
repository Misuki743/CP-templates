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
  bundledCode: "#line 1 \"segtree/persistentSegmentTree.cpp\"\ntemplate<class T>\n\
    struct persistentSegmentTree {\n  struct node {\n    int lc, rc;\n    T monoid;\n\
    \    node(T _monoid, int _lc = -1, int _rc = -1) : monoid(_monoid), lc(_lc), rc(_rc)\
    \ {}\n    node() {}\n  };\n\n  static const int MAXSZ = 4500000; //use about 2N\
    \ + QlgN nodes\n  function<T(const T&, const T&)> combine;\n  T UNIT;\n  vector<node>\
    \ arr;\n  vector<T> init;\n  int ptr = 0;\n\n  persistentSegmentTree(T _UNIT,\
    \ function<T(const T&, const T&)> _combine, vector<T> _init = vector<T>(0)) {\n\
    \    UNIT = _UNIT;\n    combine = _combine;\n    init = _init;\n    arr.resize(MAXSZ,\
    \ UNIT);\n  }\n\n  int build(int l, int r) {\n    int now = ptr;\n    arr[ptr++]\
    \ = node(UNIT);\n    if (l + 1 == r) {\n      if (!init.empty())\n        arr[now]\
    \ = node(init[l]);\n    } else {\n      int mid = (l + r) / 2;\n      arr[now].lc\
    \ = build(l, mid);\n      arr[now].rc = build(mid, r);\n    }\n    return now;\n\
    \  }\n\n  int set(int now, int l, int r, int idx, T val) {  \n    int tmp = ptr;\n\
    \    arr[ptr++] = node(UNIT);\n    if (l + 1 == r) {\n      arr[tmp] = node(val);\
    \    \n      return tmp;\n    }\n    int mid = (l + r) / 2;\n    if (idx < mid)\
    \ {\n      arr[tmp].lc = set(arr[now].lc, l, mid, idx, val); \n      arr[tmp].rc\
    \ = arr[now].rc; \n    } else {\n      arr[tmp].lc = arr[now].lc;\n      arr[tmp].rc\
    \ = set(arr[now].rc, mid, r, idx, val);\n    }\n    arr[tmp].monoid = combine(arr[arr[tmp].lc].monoid,\
    \ arr[arr[tmp].rc].monoid);\n    return tmp;\n  }\n\n  T query(int now, int l,\
    \ int r, int ql, int qr) {\n    if (ql == qr or now == -1 or r <= ql or l >= qr)\n\
    \      return UNIT;\n    if (ql <= l and r <= qr)\n      return arr[now].monoid;\n\
    \    int mid = (l + r) / 2;\n    return combine(query(arr[now].lc, l, mid, ql,\
    \ qr), query(arr[now].rc, mid, r, ql, qr));\n  }\n};\n"
  code: "template<class T>\nstruct persistentSegmentTree {\n  struct node {\n    int\
    \ lc, rc;\n    T monoid;\n    node(T _monoid, int _lc = -1, int _rc = -1) : monoid(_monoid),\
    \ lc(_lc), rc(_rc) {}\n    node() {}\n  };\n\n  static const int MAXSZ = 4500000;\
    \ //use about 2N + QlgN nodes\n  function<T(const T&, const T&)> combine;\n  T\
    \ UNIT;\n  vector<node> arr;\n  vector<T> init;\n  int ptr = 0;\n\n  persistentSegmentTree(T\
    \ _UNIT, function<T(const T&, const T&)> _combine, vector<T> _init = vector<T>(0))\
    \ {\n    UNIT = _UNIT;\n    combine = _combine;\n    init = _init;\n    arr.resize(MAXSZ,\
    \ UNIT);\n  }\n\n  int build(int l, int r) {\n    int now = ptr;\n    arr[ptr++]\
    \ = node(UNIT);\n    if (l + 1 == r) {\n      if (!init.empty())\n        arr[now]\
    \ = node(init[l]);\n    } else {\n      int mid = (l + r) / 2;\n      arr[now].lc\
    \ = build(l, mid);\n      arr[now].rc = build(mid, r);\n    }\n    return now;\n\
    \  }\n\n  int set(int now, int l, int r, int idx, T val) {  \n    int tmp = ptr;\n\
    \    arr[ptr++] = node(UNIT);\n    if (l + 1 == r) {\n      arr[tmp] = node(val);\
    \    \n      return tmp;\n    }\n    int mid = (l + r) / 2;\n    if (idx < mid)\
    \ {\n      arr[tmp].lc = set(arr[now].lc, l, mid, idx, val); \n      arr[tmp].rc\
    \ = arr[now].rc; \n    } else {\n      arr[tmp].lc = arr[now].lc;\n      arr[tmp].rc\
    \ = set(arr[now].rc, mid, r, idx, val);\n    }\n    arr[tmp].monoid = combine(arr[arr[tmp].lc].monoid,\
    \ arr[arr[tmp].rc].monoid);\n    return tmp;\n  }\n\n  T query(int now, int l,\
    \ int r, int ql, int qr) {\n    if (ql == qr or now == -1 or r <= ql or l >= qr)\n\
    \      return UNIT;\n    if (ql <= l and r <= qr)\n      return arr[now].monoid;\n\
    \    int mid = (l + r) / 2;\n    return combine(query(arr[now].lc, l, mid, ql,\
    \ qr), query(arr[now].rc, mid, r, ql, qr));\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/persistentSegmentTree.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segtree/persistentSegmentTree.cpp
layout: document
redirect_from:
- /library/segtree/persistentSegmentTree.cpp
- /library/segtree/persistentSegmentTree.cpp.html
title: segtree/persistentSegmentTree.cpp
---
