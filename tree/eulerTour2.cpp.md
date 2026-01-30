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
  bundledCode: "#line 1 \"tree/eulerTour2.cpp\"\n//#include<segtree/segmentTree.cpp>\n\
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
  path: tree/eulerTour2.cpp
  requiredBy: []
  timestamp: '2026-01-30 20:10:19+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/eulerTour2.cpp
layout: document
redirect_from:
- /library/tree/eulerTour2.cpp
- /library/tree/eulerTour2.cpp.html
title: tree/eulerTour2.cpp
---
