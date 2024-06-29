---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/counting_eulerian_circuits.test.cpp
    title: test/counting_eulerian_circuits.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"combi/countEulerianCircuit.cpp\"\n//#include \"modint/MontgomeryModInt.cpp\"\
    \n//#include \"linalg/matrixMint.cpp\"\n//#include \"combi/countSpanningForest.cpp\"\
    \n\ntemplate<class Mint>\nMint countEulerianCircuit(vector<array<int, 2>> e, int\
    \ n) {\n  vector<int> deg(n);\n  vector<vector<int>> g(n);\n  for(auto [u, v]\
    \ : e) {\n    deg[v]++;\n    g[u].emplace_back(v);\n  }\n\n  for(int v = 0; v\
    \ < n; v++)\n    if (deg[v] != ssize(g[v]))\n      return Mint(0);\n\n  vector<bool>\
    \ vis(n, false);\n  auto dfs = [&](int v, auto &&self) -> void {\n    vis[v] =\
    \ true;\n    for(int x : g[v])\n      if (!vis[x])\n        self(x, self);\n \
    \ };\n\n  int s = 0;\n  while(s < n and deg[s] == 0) s++;\n  s %= n;\n  dfs(s,\
    \ dfs);\n\n  vector<int> r(1, s);\n  for(int v = 0; v < n; v++) if (!vis[v]) {\n\
    \    if (deg[v] != 0) return Mint(0);\n    else r.emplace_back(v);\n  }\n\n  vector<tuple<int,\
    \ int, Mint>> ep(ssize(e));\n  for(int i = 0; auto [u, v] : e)\n    ep[i++] =\
    \ {u, v, Mint(1)};\n  \n  Mint c = 1;\n  binomial<Mint> bn(ssize(e));\n  for(int\
    \ v = 0; v < n; v++)\n    c *= bn.fac(max(deg[v] - 1, 0));\n\n  return c * countSpanningForest<Mint,\
    \ true>(ep, n, r);\n}\n"
  code: "//#include \"modint/MontgomeryModInt.cpp\"\n//#include \"linalg/matrixMint.cpp\"\
    \n//#include \"combi/countSpanningForest.cpp\"\n\ntemplate<class Mint>\nMint countEulerianCircuit(vector<array<int,\
    \ 2>> e, int n) {\n  vector<int> deg(n);\n  vector<vector<int>> g(n);\n  for(auto\
    \ [u, v] : e) {\n    deg[v]++;\n    g[u].emplace_back(v);\n  }\n\n  for(int v\
    \ = 0; v < n; v++)\n    if (deg[v] != ssize(g[v]))\n      return Mint(0);\n\n\
    \  vector<bool> vis(n, false);\n  auto dfs = [&](int v, auto &&self) -> void {\n\
    \    vis[v] = true;\n    for(int x : g[v])\n      if (!vis[x])\n        self(x,\
    \ self);\n  };\n\n  int s = 0;\n  while(s < n and deg[s] == 0) s++;\n  s %= n;\n\
    \  dfs(s, dfs);\n\n  vector<int> r(1, s);\n  for(int v = 0; v < n; v++) if (!vis[v])\
    \ {\n    if (deg[v] != 0) return Mint(0);\n    else r.emplace_back(v);\n  }\n\n\
    \  vector<tuple<int, int, Mint>> ep(ssize(e));\n  for(int i = 0; auto [u, v] :\
    \ e)\n    ep[i++] = {u, v, Mint(1)};\n  \n  Mint c = 1;\n  binomial<Mint> bn(ssize(e));\n\
    \  for(int v = 0; v < n; v++)\n    c *= bn.fac(max(deg[v] - 1, 0));\n\n  return\
    \ c * countSpanningForest<Mint, true>(ep, n, r);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/countEulerianCircuit.cpp
  requiredBy: []
  timestamp: '2024-06-29 17:34:40+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/counting_eulerian_circuits.test.cpp
documentation_of: combi/countEulerianCircuit.cpp
layout: document
redirect_from:
- /library/combi/countEulerianCircuit.cpp
- /library/combi/countEulerianCircuit.cpp.html
title: combi/countEulerianCircuit.cpp
---
