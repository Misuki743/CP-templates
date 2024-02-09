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
  bundledCode: "#line 1 \"ds/eulerTour.cpp\"\n//#include<ds/fastJump.cpp>\n//#include<segtree/dualSegmentTree.cpp>\n\
    \ntemplate<class M, class T, M(*Mid)(), T(*Tid)(), M(*Mop)(const M&, const M&),\
    \ \nT(*Top)(const T&, const T&), M(*comp)(const M&, const T&), M(*Minv)(const\
    \ M&)>\nstruct eulerTour {\n  vector<int> tin, tout, p;\n  dualSegmentTree<M,\
    \ Mid, T, Tid, Top, comp> st;\n  fastJump jp;\n\n  eulerTour(vector<vector<int>>\
    \ g, int root = 0) : tin(ssize(g)), tout(ssize(g)), p(ssize(g), -1), st(ssize(g)),\
    \ jp(g, root) {\n    int t = 0;\n    auto dfs = [&](int v, auto self) -> void\
    \ {\n      tin[v] = t++;\n      for(int x : g[v]) {\n        if (x == p[v]) continue;\n\
    \        p[x] = v;\n        self(x, self);\n      }\n      tout[v] = t;\n    };\n\
    \n    dfs(root, dfs);\n  }\n\n  //for point modify, path query, inversion of monoid\
    \ is needed\n  void modify(int v, T x) { st.modify(tin[v], tout[v], x); }\n  M\
    \ query(int u, int v) {\n    int lca = jp.lca(u, v);\n    M res = Mop(st.get(tin[u]),\
    \ st.get(tin[v]));\n    res = Mop(res, Minv(st.get(tin[lca])));\n    if (p[lca]\
    \ != -1)\n      res = Mop(res, Minv(st.get(tin[p[lca]])));\n    return res;\n\
    \  }\n};\n"
  code: "//#include<ds/fastJump.cpp>\n//#include<segtree/dualSegmentTree.cpp>\n\n\
    template<class M, class T, M(*Mid)(), T(*Tid)(), M(*Mop)(const M&, const M&),\
    \ \nT(*Top)(const T&, const T&), M(*comp)(const M&, const T&), M(*Minv)(const\
    \ M&)>\nstruct eulerTour {\n  vector<int> tin, tout, p;\n  dualSegmentTree<M,\
    \ Mid, T, Tid, Top, comp> st;\n  fastJump jp;\n\n  eulerTour(vector<vector<int>>\
    \ g, int root = 0) : tin(ssize(g)), tout(ssize(g)), p(ssize(g), -1), st(ssize(g)),\
    \ jp(g, root) {\n    int t = 0;\n    auto dfs = [&](int v, auto self) -> void\
    \ {\n      tin[v] = t++;\n      for(int x : g[v]) {\n        if (x == p[v]) continue;\n\
    \        p[x] = v;\n        self(x, self);\n      }\n      tout[v] = t;\n    };\n\
    \n    dfs(root, dfs);\n  }\n\n  //for point modify, path query, inversion of monoid\
    \ is needed\n  void modify(int v, T x) { st.modify(tin[v], tout[v], x); }\n  M\
    \ query(int u, int v) {\n    int lca = jp.lca(u, v);\n    M res = Mop(st.get(tin[u]),\
    \ st.get(tin[v]));\n    res = Mop(res, Minv(st.get(tin[lca])));\n    if (p[lca]\
    \ != -1)\n      res = Mop(res, Minv(st.get(tin[p[lca]])));\n    return res;\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/eulerTour.cpp
  requiredBy: []
  timestamp: '2024-02-09 22:11:02+08:00'
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
