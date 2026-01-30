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
  bundledCode: "#line 1 \"graph/shortest_path/BFS.cpp\"\narray<vector<int>, 2> BFS(vector<vector<int>>\
    \ &g, int s) {\n  int n = ssize(g);\n  vector<int> dis(n, -1), pre(n, -1);\n \
    \ queue<int> q;\n\n  dis[s] = 0;\n  q.push(s);\n\n  while(!q.empty()) {\n    int\
    \ v = q.front(); q.pop();\n    for(int x : g[v]) {\n      if (dis[x] != -1) continue;\n\
    \      dis[x] = dis[v] + 1, pre[x] = v;\n      q.push(x);\n    }\n  }\n\n  return\
    \ {dis, pre};\n}\n"
  code: "array<vector<int>, 2> BFS(vector<vector<int>> &g, int s) {\n  int n = ssize(g);\n\
    \  vector<int> dis(n, -1), pre(n, -1);\n  queue<int> q;\n\n  dis[s] = 0;\n  q.push(s);\n\
    \n  while(!q.empty()) {\n    int v = q.front(); q.pop();\n    for(int x : g[v])\
    \ {\n      if (dis[x] != -1) continue;\n      dis[x] = dis[v] + 1, pre[x] = v;\n\
    \      q.push(x);\n    }\n  }\n\n  return {dis, pre};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path/BFS.cpp
  requiredBy: []
  timestamp: '2026-01-30 20:10:19+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/shortest_path/BFS.cpp
layout: document
redirect_from:
- /library/graph/shortest_path/BFS.cpp
- /library/graph/shortest_path/BFS.cpp.html
title: graph/shortest_path/BFS.cpp
---
