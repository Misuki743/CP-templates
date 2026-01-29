---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/tree_path_composite_sum.test.cpp
    title: test/tree_path_composite_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/rerooting_DP.cpp\"\ntemplate<class V, class E, typename\
    \ BASE, typename ADD_EDGE, typename OP, typename ADD_VERTEX>\nrequires\n  R_invocable<V,\
    \ BASE, int> &&\n  R_invocable<E, ADD_EDGE, const V, int> &&\n  R_invocable<E,\
    \ OP, const E, const E> &&\n  R_invocable<V, ADD_VERTEX, const E, int>\nvector<V>\
    \ rerooting_DP(vector<array<int, 2>> e, BASE base, ADD_EDGE add_edge, OP op, ADD_VERTEX\
    \ add_vertex) {\n  int n = ssize(e) + 1;\n  vector<vector<int>> g(n);\n  for(int\
    \ i = 0; auto [u, v] : e)\n    g[u].emplace_back(i), g[v].emplace_back(i++);\n\
    \n  vector<V> data(n);\n  for(int v = 0; v < n; v++) data[v] = base(v);\n  auto\
    \ precalc = [&](int v, int p, auto &&self) -> void {\n    bool leaf = true;\n\
    \    E prod;\n    for(int eid : g[v]) {\n      int x = e[eid][0] ^ e[eid][1] ^\
    \ v;\n      if (x == p) continue;\n      self(x, v, self);\n      if (leaf)\n\
    \        prod = add_edge(data[x], eid), leaf = false;\n      else\n        prod\
    \ = op(prod, add_edge(data[x], eid));\n    }\n    if (!leaf) data[v] = add_vertex(prod,\
    \ v);\n  };\n\n  precalc(0, -1, precalc);\n\n  vector<V> ret(n);\n  auto reroot\
    \ = [&](int v, int p, auto &&self) -> void {\n    int deg = ssize(g[v]);\n   \
    \ vector<E> pre(deg), suf(deg);\n    for(int i = 0; int eid : g[v]) {\n      int\
    \ x = e[eid][0] ^ e[eid][1] ^ v;\n      pre[i] = suf[i] = add_edge(data[x], eid),\
    \ i++;\n    }\n    for(int i = 1; i < deg; i++) pre[i] = op(pre[i - 1], pre[i]);\n\
    \    for(int i = deg - 2; i >= 0; i--) suf[i] = op(suf[i], suf[i + 1]);\n    V\
    \ tmp = data[v];\n    ret[v] = data[v] = (deg ? add_vertex(suf[0], v) : base(v));\n\
    \    for(int i = 0; int eid : g[v]) {\n      int x = e[eid][0] ^ e[eid][1] ^ v;\n\
    \      if (x != p) {\n        bool leaf = true;\n        E prod;\n        if (i\
    \ > 0) prod = pre[i - 1], leaf = false;\n        if (i + 1 < deg) prod = (leaf\
    \ ? suf[i + 1] : op(prod, suf[i + 1])), leaf = false;\n        V tmp2 = data[v];\n\
    \        data[v] = (leaf ? base(v) : add_vertex(prod, v));\n        self(x, v,\
    \ self);\n        data[v] = tmp2;\n      }\n      i++;\n    }\n    data[v] = tmp;\n\
    \  };\n\n  reroot(0, -1, reroot);\n\n  return ret;\n}\n"
  code: "template<class V, class E, typename BASE, typename ADD_EDGE, typename OP,\
    \ typename ADD_VERTEX>\nrequires\n  R_invocable<V, BASE, int> &&\n  R_invocable<E,\
    \ ADD_EDGE, const V, int> &&\n  R_invocable<E, OP, const E, const E> &&\n  R_invocable<V,\
    \ ADD_VERTEX, const E, int>\nvector<V> rerooting_DP(vector<array<int, 2>> e, BASE\
    \ base, ADD_EDGE add_edge, OP op, ADD_VERTEX add_vertex) {\n  int n = ssize(e)\
    \ + 1;\n  vector<vector<int>> g(n);\n  for(int i = 0; auto [u, v] : e)\n    g[u].emplace_back(i),\
    \ g[v].emplace_back(i++);\n\n  vector<V> data(n);\n  for(int v = 0; v < n; v++)\
    \ data[v] = base(v);\n  auto precalc = [&](int v, int p, auto &&self) -> void\
    \ {\n    bool leaf = true;\n    E prod;\n    for(int eid : g[v]) {\n      int\
    \ x = e[eid][0] ^ e[eid][1] ^ v;\n      if (x == p) continue;\n      self(x, v,\
    \ self);\n      if (leaf)\n        prod = add_edge(data[x], eid), leaf = false;\n\
    \      else\n        prod = op(prod, add_edge(data[x], eid));\n    }\n    if (!leaf)\
    \ data[v] = add_vertex(prod, v);\n  };\n\n  precalc(0, -1, precalc);\n\n  vector<V>\
    \ ret(n);\n  auto reroot = [&](int v, int p, auto &&self) -> void {\n    int deg\
    \ = ssize(g[v]);\n    vector<E> pre(deg), suf(deg);\n    for(int i = 0; int eid\
    \ : g[v]) {\n      int x = e[eid][0] ^ e[eid][1] ^ v;\n      pre[i] = suf[i] =\
    \ add_edge(data[x], eid), i++;\n    }\n    for(int i = 1; i < deg; i++) pre[i]\
    \ = op(pre[i - 1], pre[i]);\n    for(int i = deg - 2; i >= 0; i--) suf[i] = op(suf[i],\
    \ suf[i + 1]);\n    V tmp = data[v];\n    ret[v] = data[v] = (deg ? add_vertex(suf[0],\
    \ v) : base(v));\n    for(int i = 0; int eid : g[v]) {\n      int x = e[eid][0]\
    \ ^ e[eid][1] ^ v;\n      if (x != p) {\n        bool leaf = true;\n        E\
    \ prod;\n        if (i > 0) prod = pre[i - 1], leaf = false;\n        if (i +\
    \ 1 < deg) prod = (leaf ? suf[i + 1] : op(prod, suf[i + 1])), leaf = false;\n\
    \        V tmp2 = data[v];\n        data[v] = (leaf ? base(v) : add_vertex(prod,\
    \ v));\n        self(x, v, self);\n        data[v] = tmp2;\n      }\n      i++;\n\
    \    }\n    data[v] = tmp;\n  };\n\n  reroot(0, -1, reroot);\n\n  return ret;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/rerooting_DP.cpp
  requiredBy: []
  timestamp: '2026-01-30 01:25:42+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree_path_composite_sum.test.cpp
documentation_of: dp/rerooting_DP.cpp
layout: document
redirect_from:
- /library/dp/rerooting_DP.cpp
- /library/dp/rerooting_DP.cpp.html
title: dp/rerooting_DP.cpp
---
