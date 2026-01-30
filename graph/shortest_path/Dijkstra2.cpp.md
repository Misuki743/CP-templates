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
  bundledCode: "#line 1 \"graph/shortest_path/Dijkstra2.cpp\"\ntemplate<class T>\n\
    vector<T> Dijkstra2(vector<vector<T>> &g, int s) {\n  int n = ssize(g);\n  vector<bool>\
    \ vis(n, false);\n  vector<T> dis(n, numeric_limits<T>::max());\n  dis[s] = 0;\n\
    \  while(true) {\n    array<int, 2> dv = {numeric_limits<T>::max(), -1};\n   \
    \ for(int v = 0; v < n; v++)\n      if (!vis[v])\n        chmin(dv, {dis[v], v});\n\
    \    int v = dv[1];\n    if (v == -1) break;\n    vis[v] = true;\n    for(int\
    \ x = 0; x < n; x++)\n      if (g[v][x] != numeric_limits<T>::max())\n       \
    \ chmin(dis[x], dis[v] + g[v][x]);\n  }\n  return dis;\n}\n"
  code: "template<class T>\nvector<T> Dijkstra2(vector<vector<T>> &g, int s) {\n \
    \ int n = ssize(g);\n  vector<bool> vis(n, false);\n  vector<T> dis(n, numeric_limits<T>::max());\n\
    \  dis[s] = 0;\n  while(true) {\n    array<int, 2> dv = {numeric_limits<T>::max(),\
    \ -1};\n    for(int v = 0; v < n; v++)\n      if (!vis[v])\n        chmin(dv,\
    \ {dis[v], v});\n    int v = dv[1];\n    if (v == -1) break;\n    vis[v] = true;\n\
    \    for(int x = 0; x < n; x++)\n      if (g[v][x] != numeric_limits<T>::max())\n\
    \        chmin(dis[x], dis[v] + g[v][x]);\n  }\n  return dis;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path/Dijkstra2.cpp
  requiredBy: []
  timestamp: '2026-01-30 20:10:19+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/shortest_path/Dijkstra2.cpp
layout: document
redirect_from:
- /library/graph/shortest_path/Dijkstra2.cpp
- /library/graph/shortest_path/Dijkstra2.cpp.html
title: graph/shortest_path/Dijkstra2.cpp
---
