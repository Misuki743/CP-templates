---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/shortest_path_dense.test.cpp
    title: test/shortest_path_dense.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/shortest_path_sparse.test.cpp
    title: test/shortest_path_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/shortest_path/Dijkstra.cpp\"\ntemplate<integral T>\n\
    auto Dijkstra_sparse(vvc<pair<int, T>> &g, vi s) {\n  constexpr T INF = numeric_limits<T>::max();\n\
    \  const int n = ssize(g);\n\n  vc<T> dis(n, INF);\n  vi pre(n, -1);\n  auto cmp\
    \ = [](pair<T, int> &a, pair<T, int> &b) { return a.first > b.first; };\n  priority_queue<pair<T,\
    \ int>, vc<pair<T, int>>, decltype(cmp)> pq(cmp, [&]() {\n    vc<pair<T, int>>\
    \ init(size(s));\n    for(int i = 0; int v : s) {\n      dis[v] = 0, pre[v] =\
    \ v;\n      init[i++] = pair(T(0), v);\n    }\n    return init;\n  }());\n\n \
    \ while(!pq.empty()) {\n    auto [d, v] = pq.top(); pq.pop();\n    if (dis[v]\
    \ != d) continue;\n    for(auto [x, w] : g[v]) {\n      if (chmin(dis[x], d +\
    \ w)) {\n        pre[x] = v;\n        pq.emplace(dis[x], x);\n      }\n    }\n\
    \  }\n\n  return pair(dis, pre);\n}\n\ntemplate<integral T>\nauto Dijkstra_dense(vvc<T>\
    \ &adj, vi s) {\n  constexpr T INF = numeric_limits<T>::max();\n  const int n\
    \ = ssize(adj);\n\n  vc<T> dis(n, INF);\n  vi pre(n, -1);\n  for(int v : s)\n\
    \    dis[v] = 0, pre[v] = v;\n\n  vc<bool> vis(n, false);\n  for(int iter = 0;\
    \ iter < n; iter++) {\n    T d = INF;\n    int v = -1;\n    for(int u = 0; u <\
    \ n; u++)\n      if (!vis[u] and chmin(d, dis[u]))\n        v = u;\n    if (v\
    \ == -1) break;\n    vis[v] = true;\n    for(int x = 0; x < n; x++)\n      if\
    \ (adj[v][x] != INF and chmin(dis[x], dis[v] + adj[v][x]))\n        pre[x] = v;\n\
    \  }\n\n  return pair(dis, pre);\n}\n"
  code: "template<integral T>\nauto Dijkstra_sparse(vvc<pair<int, T>> &g, vi s) {\n\
    \  constexpr T INF = numeric_limits<T>::max();\n  const int n = ssize(g);\n\n\
    \  vc<T> dis(n, INF);\n  vi pre(n, -1);\n  auto cmp = [](pair<T, int> &a, pair<T,\
    \ int> &b) { return a.first > b.first; };\n  priority_queue<pair<T, int>, vc<pair<T,\
    \ int>>, decltype(cmp)> pq(cmp, [&]() {\n    vc<pair<T, int>> init(size(s));\n\
    \    for(int i = 0; int v : s) {\n      dis[v] = 0, pre[v] = v;\n      init[i++]\
    \ = pair(T(0), v);\n    }\n    return init;\n  }());\n\n  while(!pq.empty()) {\n\
    \    auto [d, v] = pq.top(); pq.pop();\n    if (dis[v] != d) continue;\n    for(auto\
    \ [x, w] : g[v]) {\n      if (chmin(dis[x], d + w)) {\n        pre[x] = v;\n \
    \       pq.emplace(dis[x], x);\n      }\n    }\n  }\n\n  return pair(dis, pre);\n\
    }\n\ntemplate<integral T>\nauto Dijkstra_dense(vvc<T> &adj, vi s) {\n  constexpr\
    \ T INF = numeric_limits<T>::max();\n  const int n = ssize(adj);\n\n  vc<T> dis(n,\
    \ INF);\n  vi pre(n, -1);\n  for(int v : s)\n    dis[v] = 0, pre[v] = v;\n\n \
    \ vc<bool> vis(n, false);\n  for(int iter = 0; iter < n; iter++) {\n    T d =\
    \ INF;\n    int v = -1;\n    for(int u = 0; u < n; u++)\n      if (!vis[u] and\
    \ chmin(d, dis[u]))\n        v = u;\n    if (v == -1) break;\n    vis[v] = true;\n\
    \    for(int x = 0; x < n; x++)\n      if (adj[v][x] != INF and chmin(dis[x],\
    \ dis[v] + adj[v][x]))\n        pre[x] = v;\n  }\n\n  return pair(dis, pre);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path/Dijkstra.cpp
  requiredBy: []
  timestamp: '2026-01-31 00:52:12+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/shortest_path_sparse.test.cpp
  - test/shortest_path_dense.test.cpp
documentation_of: graph/shortest_path/Dijkstra.cpp
layout: document
redirect_from:
- /library/graph/shortest_path/Dijkstra.cpp
- /library/graph/shortest_path/Dijkstra.cpp.html
title: graph/shortest_path/Dijkstra.cpp
---
