---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/vertex_add_subtree_sum.test.cpp
    title: test/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/eulerTour2.cpp\"\n//#include<segtree/segmentTree.cpp>\n\
    \ntemplate<class M, M(*id)(), M(*op)(const M&, const M&)>\nstruct eulerTour2 {\n\
    \  vector<int> tin, tout, p;\n  segmentTree<M, id, op> st;\n\n  eulerTour2(vector<vector<int>>\
    \ g, int root = 0) : tin(ssize(g)), tout(ssize(g)), p(ssize(g), -1), st(ssize(g))\
    \ {\n    int t = 0;\n    auto dfs = [&](int v, auto self) -> void {\n      tin[v]\
    \ = t++;\n      for(int x : g[v]) {\n        if (x == p[v]) continue;\n      \
    \  p[x] = v;\n        self(x, self);\n      }\n      tout[v] = t;\n    };\n\n\
    \    dfs(root, dfs);\n  }\n\n  void set(int v, M x) { st.set(tin[v], x); }\n \
    \ M get(int v) { return st.get(tin[v]); }\n  M query(int v) { return st.query(tin[v],\
    \ tout[v]); }\n};\n"
  code: "//#include<segtree/segmentTree.cpp>\n\ntemplate<class M, M(*id)(), M(*op)(const\
    \ M&, const M&)>\nstruct eulerTour2 {\n  vector<int> tin, tout, p;\n  segmentTree<M,\
    \ id, op> st;\n\n  eulerTour2(vector<vector<int>> g, int root = 0) : tin(ssize(g)),\
    \ tout(ssize(g)), p(ssize(g), -1), st(ssize(g)) {\n    int t = 0;\n    auto dfs\
    \ = [&](int v, auto self) -> void {\n      tin[v] = t++;\n      for(int x : g[v])\
    \ {\n        if (x == p[v]) continue;\n        p[x] = v;\n        self(x, self);\n\
    \      }\n      tout[v] = t;\n    };\n\n    dfs(root, dfs);\n  }\n\n  void set(int\
    \ v, M x) { st.set(tin[v], x); }\n  M get(int v) { return st.get(tin[v]); }\n\
    \  M query(int v) { return st.query(tin[v], tout[v]); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/eulerTour2.cpp
  requiredBy: []
  timestamp: '2024-02-09 22:57:04+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/vertex_add_subtree_sum.test.cpp
documentation_of: ds/eulerTour2.cpp
layout: document
redirect_from:
- /library/ds/eulerTour2.cpp
- /library/ds/eulerTour2.cpp.html
title: ds/eulerTour2.cpp
---
