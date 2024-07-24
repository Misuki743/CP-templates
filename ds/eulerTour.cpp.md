---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/vertex_add_path_sum.test.cpp
    title: test/vertex_add_path_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/eulerTour.cpp\"\n//#include<ds/RMQ.cpp>\n//#include<ds/LCA.cpp>\n\
    //#include<segtree/dualSegmentTree.cpp>\n\ntemplate<class M, M(*Mid)(), M(*Mop)(const\
    \ M&, const M&), M(*Minv)(const M&), \nclass T, T(*Tid)(), T(*Top)(const T&, const\
    \ T&), M(*act)(const M&, const T&)>\nstruct eulerTour {\n  vector<int> tin, tout,\
    \ p;\n  dualSegmentTree<M, Mid, T, Tid, Top, act> st;\n  LCA lc;\n\n  eulerTour(vector<vector<int>>\
    \ g, int root = 0) : tin(ssize(g)), tout(ssize(g)), p(ssize(g), -1), st(ssize(g)),\
    \ lc(g, root) {\n    int t = 0;\n    auto dfs = [&](int v, auto self) -> void\
    \ {\n      tin[v] = t++;\n      for(int x : g[v]) {\n        if (x == p[v]) continue;\n\
    \        p[x] = v;\n        self(x, self);\n      }\n      tout[v] = t;\n    };\n\
    \n    dfs(root, dfs);\n  }\n\n  //for point modify, path query, inversion of monoid\
    \ is needed\n  void modify(int v, T x) { st.modify(tin[v], tout[v], x); }\n  M\
    \ query(int u, int v) {\n    int Lca = lc.lca(u, v);\n    M res = Mop(st.get(tin[u]),\
    \ st.get(tin[v]));\n    res = Mop(res, Minv(st.get(tin[Lca])));\n    if (p[Lca]\
    \ != -1)\n      res = Mop(res, Minv(st.get(tin[p[Lca]])));\n    return res;\n\
    \  }\n};\n"
  code: "//#include<ds/RMQ.cpp>\n//#include<ds/LCA.cpp>\n//#include<segtree/dualSegmentTree.cpp>\n\
    \ntemplate<class M, M(*Mid)(), M(*Mop)(const M&, const M&), M(*Minv)(const M&),\
    \ \nclass T, T(*Tid)(), T(*Top)(const T&, const T&), M(*act)(const M&, const T&)>\n\
    struct eulerTour {\n  vector<int> tin, tout, p;\n  dualSegmentTree<M, Mid, T,\
    \ Tid, Top, act> st;\n  LCA lc;\n\n  eulerTour(vector<vector<int>> g, int root\
    \ = 0) : tin(ssize(g)), tout(ssize(g)), p(ssize(g), -1), st(ssize(g)), lc(g, root)\
    \ {\n    int t = 0;\n    auto dfs = [&](int v, auto self) -> void {\n      tin[v]\
    \ = t++;\n      for(int x : g[v]) {\n        if (x == p[v]) continue;\n      \
    \  p[x] = v;\n        self(x, self);\n      }\n      tout[v] = t;\n    };\n\n\
    \    dfs(root, dfs);\n  }\n\n  //for point modify, path query, inversion of monoid\
    \ is needed\n  void modify(int v, T x) { st.modify(tin[v], tout[v], x); }\n  M\
    \ query(int u, int v) {\n    int Lca = lc.lca(u, v);\n    M res = Mop(st.get(tin[u]),\
    \ st.get(tin[v]));\n    res = Mop(res, Minv(st.get(tin[Lca])));\n    if (p[Lca]\
    \ != -1)\n      res = Mop(res, Minv(st.get(tin[p[Lca]])));\n    return res;\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/eulerTour.cpp
  requiredBy: []
  timestamp: '2024-07-24 13:33:23+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/vertex_add_path_sum.test.cpp
documentation_of: ds/eulerTour.cpp
layout: document
redirect_from:
- /library/ds/eulerTour.cpp
- /library/ds/eulerTour.cpp.html
title: ds/eulerTour.cpp
---
