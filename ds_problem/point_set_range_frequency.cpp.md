---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/point_set_range_frequency.test.cpp
    title: test/point_set_range_frequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds_problem/point_set_range_frequency.cpp\"\n//#include<ds/fenwickTree.cpp>\n\
    \ntemplate<class T>\nstruct point_set_range_frequency {\n  vector<T> a;\n  int\
    \ n, now = 0;\n  struct Query {\n    T x;\n    int t, l, r, id;\n  };\n  vector<Query>\
    \ q;\n  struct Modification {\n    T x;\n    int t, i;\n    bool add;\n  };\n\
    \  vector<Modification> m;\n\n  point_set_range_frequency(vector<T> &_a)\n   \
    \ : a(_a), n(ssize(a)), m(n) {\n    for(int i = 0; i < n; i++)\n      m[i] = {a[i],\
    \ 0, i, true};\n  };\n\n  void modify(int i, T x) {\n    m.push_back({a[i], now,\
    \ i, false});\n    m.push_back({a[i] = x, now, i, true});\n  }\n\n  void query(int\
    \ l, int r, T x) {\n    q.push_back({x, now++, l, r, (int)size(q)});\n  }\n\n\
    \  vector<int> solve() {\n    for(int i = 0; i < n; i++)\n      m.push_back({a[i],\
    \ now, i, false});\n    ranges::sort(q, {}, [&](auto &e) { return pair(e.x, e.t);\
    \ });\n    ranges::sort(m, {}, [&](auto &e) { return pair(e.x, e.t); });\n   \
    \ vector<int> ans(ssize(q));\n    fenwickTree<int> ft(n);\n    for(int i = 0;\
    \ auto [x, t, l, r, id] : q) {\n      while(i < ssize(m) and pair(m[i].x, m[i].t)\
    \ <= pair(x, t))\n        ft.add(m[i].i, m[i].add ? 1 : -1), i++;\n      ans[id]\
    \ = ft.query(l, r);\n    }\n    return ans;\n  }\n};\n"
  code: "//#include<ds/fenwickTree.cpp>\n\ntemplate<class T>\nstruct point_set_range_frequency\
    \ {\n  vector<T> a;\n  int n, now = 0;\n  struct Query {\n    T x;\n    int t,\
    \ l, r, id;\n  };\n  vector<Query> q;\n  struct Modification {\n    T x;\n   \
    \ int t, i;\n    bool add;\n  };\n  vector<Modification> m;\n\n  point_set_range_frequency(vector<T>\
    \ &_a)\n    : a(_a), n(ssize(a)), m(n) {\n    for(int i = 0; i < n; i++)\n   \
    \   m[i] = {a[i], 0, i, true};\n  };\n\n  void modify(int i, T x) {\n    m.push_back({a[i],\
    \ now, i, false});\n    m.push_back({a[i] = x, now, i, true});\n  }\n\n  void\
    \ query(int l, int r, T x) {\n    q.push_back({x, now++, l, r, (int)size(q)});\n\
    \  }\n\n  vector<int> solve() {\n    for(int i = 0; i < n; i++)\n      m.push_back({a[i],\
    \ now, i, false});\n    ranges::sort(q, {}, [&](auto &e) { return pair(e.x, e.t);\
    \ });\n    ranges::sort(m, {}, [&](auto &e) { return pair(e.x, e.t); });\n   \
    \ vector<int> ans(ssize(q));\n    fenwickTree<int> ft(n);\n    for(int i = 0;\
    \ auto [x, t, l, r, id] : q) {\n      while(i < ssize(m) and pair(m[i].x, m[i].t)\
    \ <= pair(x, t))\n        ft.add(m[i].i, m[i].add ? 1 : -1), i++;\n      ans[id]\
    \ = ft.query(l, r);\n    }\n    return ans;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds_problem/point_set_range_frequency.cpp
  requiredBy: []
  timestamp: '2025-06-10 23:00:40+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/point_set_range_frequency.test.cpp
documentation_of: ds_problem/point_set_range_frequency.cpp
layout: document
redirect_from:
- /library/ds_problem/point_set_range_frequency.cpp
- /library/ds_problem/point_set_range_frequency.cpp.html
title: ds_problem/point_set_range_frequency.cpp
---
