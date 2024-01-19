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
  bundledCode: "#line 1 \"ds/eulerTour.cpp\"\n/**\n * template name: eulerTour\n *\
    \ author: Misuki\n * last update: 2024/01/06\n * include: sparseTable, lazySegmentTree\n\
    \ * verify: Library Checker - Vertex Add Path Sum\n * verify: Library Checker\
    \ - Vertex Add Subtree Sum\n * note: monoid should be commutative, otherwise use\
    \ HLD\n */\n\ntemplate<class M, class T, M(*Munit)(), T(*Tunit)(), M(*Mope)(const\
    \ M&, const M&), T(*Tope)(const T&, const T&), M(*comp)(const M&, const T&), M(*inv)(const\
    \ M&)>\nstruct eulerTour {\n  using segTree = lazySegmentTree<M, T, Munit, Tunit,\
    \ Mope, Tope, comp>;\n\n  vector<int> tin, tout, p;\n  sparseTable<array<int,\
    \ 2>> st;\n  segTree seg;\n\n  vector<array<int, 2>> precalc(vector<vector<int>>\
    \ &g, int root = 0) {\n    vector<int> dep(ssize(g));\n    vector<array<int, 2>>\
    \ res;\n    res.reserve(2 * ssize(g) - 1);\n    auto dfs = [&](int v, auto self)\
    \ -> void {\n      tin[v] = ssize(res);\n      res.push_back({dep[v], v});\n \
    \     for(int x : g[v]) {\n        if (x == p[v]) continue;\n        dep[x] =\
    \ dep[v] + 1, p[x] = v;\n        self(x, self);\n        res.push_back({dep[v],\
    \ v});\n      }\n      tout[v] = ssize(res);\n    };\n\n    dfs(root, dfs);\n\n\
    \    return res;\n  }\n\n  eulerTour(vector<vector<int>> &g, int root = 0) : tin(ssize(g)),\
    \ tout(ssize(g)), p(ssize(g), -1),\n  st(precalc(g, root), [](const array<int,\
    \ 2> &l, const array<int, 2> &r) { return min(l, r); }), seg(2 * ssize(g) - 1)\
    \ {}\n\n  int lca(int u, int v) { return st.query(min(tin[u], tin[v]), max(tout[u],\
    \ tout[v]))[1]; }\n\n  //for point modify, path query, inversion of monoid is\
    \ needed\n  void modify(int v, T x) { seg.modify(tin[v], tout[v], x); }\n  M query(int\
    \ u, int v) {\n    int tmp = lca(u, v);\n    M res = Mope(seg.get(tin[u]), seg.get(tin[v]));\n\
    \    res = Mope(res, inv(seg.get(tin[tmp])));\n    if (p[tmp] != -1)\n      res\
    \ = Mope(res, inv(seg.get(tin[p[tmp]])));\n    return res;\n  }\n\n  //for point\
    \ modify, subtree query\n  void modify2(int v, T x) { seg.modify(tin[v], tin[v]\
    \ + 1, x); }\n  M query2(int v) { return seg.query(tin[v], tout[v]); }\n};\n"
  code: "/**\n * template name: eulerTour\n * author: Misuki\n * last update: 2024/01/06\n\
    \ * include: sparseTable, lazySegmentTree\n * verify: Library Checker - Vertex\
    \ Add Path Sum\n * verify: Library Checker - Vertex Add Subtree Sum\n * note:\
    \ monoid should be commutative, otherwise use HLD\n */\n\ntemplate<class M, class\
    \ T, M(*Munit)(), T(*Tunit)(), M(*Mope)(const M&, const M&), T(*Tope)(const T&,\
    \ const T&), M(*comp)(const M&, const T&), M(*inv)(const M&)>\nstruct eulerTour\
    \ {\n  using segTree = lazySegmentTree<M, T, Munit, Tunit, Mope, Tope, comp>;\n\
    \n  vector<int> tin, tout, p;\n  sparseTable<array<int, 2>> st;\n  segTree seg;\n\
    \n  vector<array<int, 2>> precalc(vector<vector<int>> &g, int root = 0) {\n  \
    \  vector<int> dep(ssize(g));\n    vector<array<int, 2>> res;\n    res.reserve(2\
    \ * ssize(g) - 1);\n    auto dfs = [&](int v, auto self) -> void {\n      tin[v]\
    \ = ssize(res);\n      res.push_back({dep[v], v});\n      for(int x : g[v]) {\n\
    \        if (x == p[v]) continue;\n        dep[x] = dep[v] + 1, p[x] = v;\n  \
    \      self(x, self);\n        res.push_back({dep[v], v});\n      }\n      tout[v]\
    \ = ssize(res);\n    };\n\n    dfs(root, dfs);\n\n    return res;\n  }\n\n  eulerTour(vector<vector<int>>\
    \ &g, int root = 0) : tin(ssize(g)), tout(ssize(g)), p(ssize(g), -1),\n  st(precalc(g,\
    \ root), [](const array<int, 2> &l, const array<int, 2> &r) { return min(l, r);\
    \ }), seg(2 * ssize(g) - 1) {}\n\n  int lca(int u, int v) { return st.query(min(tin[u],\
    \ tin[v]), max(tout[u], tout[v]))[1]; }\n\n  //for point modify, path query, inversion\
    \ of monoid is needed\n  void modify(int v, T x) { seg.modify(tin[v], tout[v],\
    \ x); }\n  M query(int u, int v) {\n    int tmp = lca(u, v);\n    M res = Mope(seg.get(tin[u]),\
    \ seg.get(tin[v]));\n    res = Mope(res, inv(seg.get(tin[tmp])));\n    if (p[tmp]\
    \ != -1)\n      res = Mope(res, inv(seg.get(tin[p[tmp]])));\n    return res;\n\
    \  }\n\n  //for point modify, subtree query\n  void modify2(int v, T x) { seg.modify(tin[v],\
    \ tin[v] + 1, x); }\n  M query2(int v) { return seg.query(tin[v], tout[v]); }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/eulerTour.cpp
  requiredBy: []
  timestamp: '2024-01-20 02:52:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/eulerTour.cpp
layout: document
redirect_from:
- /library/ds/eulerTour.cpp
- /library/ds/eulerTour.cpp.html
title: ds/eulerTour.cpp
---
