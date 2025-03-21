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
  bundledCode: "#line 1 \"icpc/short_lca.cpp\"\nstruct LCA {\n  vector<int> p, j,\
    \ d;\n\n  LCA(vector<vector<int>> g, int r = 0)\n  : p(size(g), r), j(size(g),\
    \ r), d(size(g)) {\n    auto dfs = [&](int v, auto &self) -> void {\n      if\
    \ (d[p[v]] + d[j[j[p[v]]]] == 2 * d[j[p[v]]])\n        j[v] = j[j[p[v]]];\n  \
    \    for(int x : g[v]) if (x != p[v]) {\n        j[x] = p[x] = v, d[x] = d[v]\
    \ + 1;\n        self(x, self);\n      }\n    };\n    dfs(r, dfs);\n  }\n\n  int\
    \ lca(int u, int v) {\n    if (d[u] < d[v]) swap(u, v);\n    while(d[u] > d[v])\
    \ u = d[j[u]] < d[v] ? p[u] :j[u];\n    while(p[u] != p[v])\n      tie(u, v) =\
    \ j[u] != j[v] ? \n                  tie(j[u], j[v]) : tie(p[u], p[v]);\n    return\
    \ u == v ? u : p[u];\n  }\n};\n"
  code: "struct LCA {\n  vector<int> p, j, d;\n\n  LCA(vector<vector<int>> g, int\
    \ r = 0)\n  : p(size(g), r), j(size(g), r), d(size(g)) {\n    auto dfs = [&](int\
    \ v, auto &self) -> void {\n      if (d[p[v]] + d[j[j[p[v]]]] == 2 * d[j[p[v]]])\n\
    \        j[v] = j[j[p[v]]];\n      for(int x : g[v]) if (x != p[v]) {\n      \
    \  j[x] = p[x] = v, d[x] = d[v] + 1;\n        self(x, self);\n      }\n    };\n\
    \    dfs(r, dfs);\n  }\n\n  int lca(int u, int v) {\n    if (d[u] < d[v]) swap(u,\
    \ v);\n    while(d[u] > d[v]) u = d[j[u]] < d[v] ? p[u] :j[u];\n    while(p[u]\
    \ != p[v])\n      tie(u, v) = j[u] != j[v] ? \n                  tie(j[u], j[v])\
    \ : tie(p[u], p[v]);\n    return u == v ? u : p[u];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: icpc/short_lca.cpp
  requiredBy: []
  timestamp: '2025-03-21 23:27:46+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc/short_lca.cpp
layout: document
redirect_from:
- /library/icpc/short_lca.cpp
- /library/icpc/short_lca.cpp.html
title: icpc/short_lca.cpp
---
