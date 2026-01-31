---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/minimum_spanning_tree_Prim.test.cpp
    title: test/minimum_spanning_tree_Prim.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/minimum_spanning_tree/Prim.cpp\"\ntemplate<integral\
    \ T>\nauto Prim(int n, vector<tuple<int, int, T>> e, int s = 0) {\n  constexpr\
    \ T INF = numeric_limits<T>::max();\n  auto weight = [&](int id) { return get<2>(e[id]);\
    \ };\n\n  e.emplace_back(0, 0, INF);\n\n  vvi id(n, vi(n, ssize(e) - 1));\n  for(int\
    \ i = -1; auto [u, v, w] : e) {\n    i++;\n    if (w < weight(id[u][v]))\n   \
    \   id[u][v] = id[v][u] = i;\n  }\n\n  T cost = 0;\n  vc<bool> vis(n, false);\n\
    \  vi eid, mn_id = id[s];\n  vis[s] = true;\n  for(int i = 0; i < n - 1; i++)\
    \ {\n    int v = -1;\n    T mn = INF;\n    for(int x = 0; x < n; x++)\n      if\
    \ (!vis[x] and chmin(mn, weight(mn_id[x])))\n        v = x;\n    if (v == -1)\
    \ break;\n    vis[v] = true, cost += weight(mn_id[v]);\n    eid.emplace_back(mn_id[v]);\n\
    \    for(int x = 0; x < n; x++)\n      if (weight(id[v][x]) < weight(mn_id[x]))\n\
    \        mn_id[x] = id[v][x];\n  }\n\n  return pair(cost, eid);\n}\n"
  code: "template<integral T>\nauto Prim(int n, vector<tuple<int, int, T>> e, int\
    \ s = 0) {\n  constexpr T INF = numeric_limits<T>::max();\n  auto weight = [&](int\
    \ id) { return get<2>(e[id]); };\n\n  e.emplace_back(0, 0, INF);\n\n  vvi id(n,\
    \ vi(n, ssize(e) - 1));\n  for(int i = -1; auto [u, v, w] : e) {\n    i++;\n \
    \   if (w < weight(id[u][v]))\n      id[u][v] = id[v][u] = i;\n  }\n\n  T cost\
    \ = 0;\n  vc<bool> vis(n, false);\n  vi eid, mn_id = id[s];\n  vis[s] = true;\n\
    \  for(int i = 0; i < n - 1; i++) {\n    int v = -1;\n    T mn = INF;\n    for(int\
    \ x = 0; x < n; x++)\n      if (!vis[x] and chmin(mn, weight(mn_id[x])))\n   \
    \     v = x;\n    if (v == -1) break;\n    vis[v] = true, cost += weight(mn_id[v]);\n\
    \    eid.emplace_back(mn_id[v]);\n    for(int x = 0; x < n; x++)\n      if (weight(id[v][x])\
    \ < weight(mn_id[x]))\n        mn_id[x] = id[v][x];\n  }\n\n  return pair(cost,\
    \ eid);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/minimum_spanning_tree/Prim.cpp
  requiredBy: []
  timestamp: '2026-01-31 03:10:37+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/minimum_spanning_tree_Prim.test.cpp
documentation_of: graph/minimum_spanning_tree/Prim.cpp
layout: document
redirect_from:
- /library/graph/minimum_spanning_tree/Prim.cpp
- /library/graph/minimum_spanning_tree/Prim.cpp.html
title: graph/minimum_spanning_tree/Prim.cpp
---
