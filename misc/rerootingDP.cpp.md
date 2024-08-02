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
  bundledCode: "#line 1 \"misc/rerootingDP.cpp\"\ntemplate<class V, V(*base)(int),\
    \ class E, E(*addEdge)(const V&, int eid),\nE(*op)(const E&, const E&), V(*addVertex)(const\
    \ E&, int vid)>\nvector<V> rerootingDP(vector<array<int, 2>> e) {\n  int n = ssize(e)\
    \ + 1;\n  vector<vector<int>> g(n);\n  for(int i = 0; auto [u, v] : e)\n    g[u].emplace_back(i),\
    \ g[v].emplace_back(i++);\n\n  vector<V> data(n);\n  for(int v = 0; v < n; v++)\
    \ data[v] = base(v);\n  auto precalc = [&](int v, int p, auto &&self) -> void\
    \ {\n    bool leaf = true;\n    E prod;\n    for(int eid : g[v]) {\n      int\
    \ x = e[eid][0] ^ e[eid][1] ^ v;\n      if (x == p) continue;\n      self(x, v,\
    \ self);\n      if (leaf)\n        prod = addEdge(data[x], eid), leaf = false;\n\
    \      else\n        prod = op(prod, addEdge(data[x], eid));\n    }\n    if (!leaf)\
    \ data[v] = addVertex(prod, v);\n  };\n\n  precalc(0, -1, precalc);\n\n  vector<V>\
    \ ret(n);\n  auto reroot = [&](int v, int p, auto &&self) -> void {\n    int deg\
    \ = ssize(g[v]);\n    vector<E> pre(deg), suf(deg);\n    for(int i = 0; int eid\
    \ : g[v]) {\n      int x = e[eid][0] ^ e[eid][1] ^ v;\n      pre[i] = suf[i] =\
    \ addEdge(data[x], eid), i++;\n    }\n    for(int i = 1; i < deg; i++) pre[i]\
    \ = op(pre[i - 1], pre[i]);\n    for(int i = deg - 2; i >= 0; i--) suf[i] = op(suf[i],\
    \ suf[i + 1]);\n    V tmp = data[v];\n    ret[v] = data[v] = (deg ? addVertex(suf[0],\
    \ v) : base(v));\n    for(int i = 0; int eid : g[v]) {\n      int x = e[eid][0]\
    \ ^ e[eid][1] ^ v;\n      if (x != p) {\n        bool leaf = true;\n        E\
    \ prod;\n        if (i > 0) prod = pre[i - 1], leaf = false;\n        if (i +\
    \ 1 < deg) prod = (leaf ? suf[i + 1] : op(prod, suf[i + 1])), leaf = false;\n\
    \        V tmp2 = data[v];\n        data[v] = (leaf ? base(v) : addVertex(prod,\
    \ v));\n        self(x, v, self);\n        data[v] = tmp2;\n      }\n      i++;\n\
    \    }\n    data[v] = tmp;\n  };\n\n  reroot(0, -1, reroot);\n\n  return ret;\n\
    }\n"
  code: "template<class V, V(*base)(int), class E, E(*addEdge)(const V&, int eid),\n\
    E(*op)(const E&, const E&), V(*addVertex)(const E&, int vid)>\nvector<V> rerootingDP(vector<array<int,\
    \ 2>> e) {\n  int n = ssize(e) + 1;\n  vector<vector<int>> g(n);\n  for(int i\
    \ = 0; auto [u, v] : e)\n    g[u].emplace_back(i), g[v].emplace_back(i++);\n\n\
    \  vector<V> data(n);\n  for(int v = 0; v < n; v++) data[v] = base(v);\n  auto\
    \ precalc = [&](int v, int p, auto &&self) -> void {\n    bool leaf = true;\n\
    \    E prod;\n    for(int eid : g[v]) {\n      int x = e[eid][0] ^ e[eid][1] ^\
    \ v;\n      if (x == p) continue;\n      self(x, v, self);\n      if (leaf)\n\
    \        prod = addEdge(data[x], eid), leaf = false;\n      else\n        prod\
    \ = op(prod, addEdge(data[x], eid));\n    }\n    if (!leaf) data[v] = addVertex(prod,\
    \ v);\n  };\n\n  precalc(0, -1, precalc);\n\n  vector<V> ret(n);\n  auto reroot\
    \ = [&](int v, int p, auto &&self) -> void {\n    int deg = ssize(g[v]);\n   \
    \ vector<E> pre(deg), suf(deg);\n    for(int i = 0; int eid : g[v]) {\n      int\
    \ x = e[eid][0] ^ e[eid][1] ^ v;\n      pre[i] = suf[i] = addEdge(data[x], eid),\
    \ i++;\n    }\n    for(int i = 1; i < deg; i++) pre[i] = op(pre[i - 1], pre[i]);\n\
    \    for(int i = deg - 2; i >= 0; i--) suf[i] = op(suf[i], suf[i + 1]);\n    V\
    \ tmp = data[v];\n    ret[v] = data[v] = (deg ? addVertex(suf[0], v) : base(v));\n\
    \    for(int i = 0; int eid : g[v]) {\n      int x = e[eid][0] ^ e[eid][1] ^ v;\n\
    \      if (x != p) {\n        bool leaf = true;\n        E prod;\n        if (i\
    \ > 0) prod = pre[i - 1], leaf = false;\n        if (i + 1 < deg) prod = (leaf\
    \ ? suf[i + 1] : op(prod, suf[i + 1])), leaf = false;\n        V tmp2 = data[v];\n\
    \        data[v] = (leaf ? base(v) : addVertex(prod, v));\n        self(x, v,\
    \ self);\n        data[v] = tmp2;\n      }\n      i++;\n    }\n    data[v] = tmp;\n\
    \  };\n\n  reroot(0, -1, reroot);\n\n  return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/rerootingDP.cpp
  requiredBy: []
  timestamp: '2024-06-04 00:24:06+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree_path_composite_sum.test.cpp
documentation_of: misc/rerootingDP.cpp
layout: document
redirect_from:
- /library/misc/rerootingDP.cpp
- /library/misc/rerootingDP.cpp.html
title: misc/rerootingDP.cpp
---
