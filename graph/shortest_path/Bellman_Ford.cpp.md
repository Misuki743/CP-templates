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
  bundledCode: "#line 1 \"graph/shortest_path/Bellman_Ford.cpp\"\ntemplate<integral\
    \ T>\nauto Bellman_Ford(const int n, vc<tuple<int, int, T>> &e, vi s) {\n  constexpr\
    \ T INF = numeric_limits<T>::max();\n  constexpr T NINF = numeric_limits<T>::min();\n\
    \n  vc<T> dis(n, INF);\n  vi pre(n, -1);\n  for(int v : s)\n    dis[v] = 0, pre[v]\
    \ = v;\n\n  for(int iter = 0; ; iter++) {\n    bool done = true;\n    for(auto\
    \ [u, v, w] : e) {\n      if (dis[u] == INF) continue;\n      if (dis[u] == NINF\
    \ and dis[v] != NINF) {\n        pre[v] = u, dis[v] = NINF, done = false;\n  \
    \    } else if (chmin(dis[v], dis[u] + w)) {\n        pre[v] = u, done = false;\n\
    \        if (iter >= n) dis[v] = NINF;\n      }\n    }\n    if (done) break;\n\
    \  }\n\n  return pair(dis, pre);\n}\n"
  code: "template<integral T>\nauto Bellman_Ford(const int n, vc<tuple<int, int, T>>\
    \ &e, vi s) {\n  constexpr T INF = numeric_limits<T>::max();\n  constexpr T NINF\
    \ = numeric_limits<T>::min();\n\n  vc<T> dis(n, INF);\n  vi pre(n, -1);\n  for(int\
    \ v : s)\n    dis[v] = 0, pre[v] = v;\n\n  for(int iter = 0; ; iter++) {\n   \
    \ bool done = true;\n    for(auto [u, v, w] : e) {\n      if (dis[u] == INF) continue;\n\
    \      if (dis[u] == NINF and dis[v] != NINF) {\n        pre[v] = u, dis[v] =\
    \ NINF, done = false;\n      } else if (chmin(dis[v], dis[u] + w)) {\n       \
    \ pre[v] = u, done = false;\n        if (iter >= n) dis[v] = NINF;\n      }\n\
    \    }\n    if (done) break;\n  }\n\n  return pair(dis, pre);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path/Bellman_Ford.cpp
  requiredBy: []
  timestamp: '2026-01-31 00:52:12+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/shortest_path/Bellman_Ford.cpp
layout: document
redirect_from:
- /library/graph/shortest_path/Bellman_Ford.cpp
- /library/graph/shortest_path/Bellman_Ford.cpp.html
title: graph/shortest_path/Bellman_Ford.cpp
---
