---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yuki_1344.test.cpp
    title: test/yuki_1344.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/shortest_path/Floyd_Warshall.cpp\"\ntemplate<integral\
    \ T>\nvvc<T> Floyd_Warshall(vvc<T> adj) {\n  const int n = ssize(adj);\n  constexpr\
    \ T INF = numeric_limits<T>::max();\n\n  for(int y = 0; y < n; y++)\n    for(int\
    \ x = 0; x < n; x++)\n      if (adj[x][y] != INF)\n        for(int z = 0; z <\
    \ n; z++)\n          if (adj[y][z] != INF)\n            chmin(adj[x][z], adj[x][y]\
    \ + adj[y][z]);\n\n  return adj;\n}\n\ntemplate<bool directed, integral T>\nvvc<T>\
    \ Floyd_Warshall(int n, vc<tuple<int, int, T>> &e) {\n  constexpr T INF = numeric_limits<T>::max();\n\
    \n  vvc adj(n, vc<T>(n, INF));\n  for(int v = 0; v < n; v++) adj[v][v] = 0;\n\
    \  for(auto [u, v, w] : e) {\n    chmin(adj[u][v], w);\n    if constexpr (!directed)\n\
    \      chmin(adj[v][u], w);\n  }\n\n  return Floyd_Warshall(std::move(adj));\n\
    }\n"
  code: "template<integral T>\nvvc<T> Floyd_Warshall(vvc<T> adj) {\n  const int n\
    \ = ssize(adj);\n  constexpr T INF = numeric_limits<T>::max();\n\n  for(int y\
    \ = 0; y < n; y++)\n    for(int x = 0; x < n; x++)\n      if (adj[x][y] != INF)\n\
    \        for(int z = 0; z < n; z++)\n          if (adj[y][z] != INF)\n       \
    \     chmin(adj[x][z], adj[x][y] + adj[y][z]);\n\n  return adj;\n}\n\ntemplate<bool\
    \ directed, integral T>\nvvc<T> Floyd_Warshall(int n, vc<tuple<int, int, T>> &e)\
    \ {\n  constexpr T INF = numeric_limits<T>::max();\n\n  vvc adj(n, vc<T>(n, INF));\n\
    \  for(int v = 0; v < n; v++) adj[v][v] = 0;\n  for(auto [u, v, w] : e) {\n  \
    \  chmin(adj[u][v], w);\n    if constexpr (!directed)\n      chmin(adj[v][u],\
    \ w);\n  }\n\n  return Floyd_Warshall(std::move(adj));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path/Floyd_Warshall.cpp
  requiredBy: []
  timestamp: '2026-01-31 00:52:12+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yuki_1344.test.cpp
documentation_of: graph/shortest_path/Floyd_Warshall.cpp
layout: document
redirect_from:
- /library/graph/shortest_path/Floyd_Warshall.cpp
- /library/graph/shortest_path/Floyd_Warshall.cpp.html
title: graph/shortest_path/Floyd_Warshall.cpp
---
