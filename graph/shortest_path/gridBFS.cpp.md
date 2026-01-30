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
  bundledCode: "#line 1 \"graph/shortest_path/gridBFS.cpp\"\ntemplate<class T>\nvector<vector<int>>\
    \ gridBFS(vector<T> &g, int sx, int sy, T wall, int mxD) {\n  int n = ssize(g),\
    \ m = ssize(g[0]);\n  auto inside = [&](int x, int y) { return 0 <= x and x <\
    \ n and 0 <= y and y < m; };\n  vector dis(n, vector<int>(m, INT_MAX));\n  queue<array<int,\
    \ 2>> q;\n  q.push({sx, sy});\n  dis[sx][sy] = 0;\n  const array<int, 8> dx =\
    \ {-1, 1, 0, 0, -1, -1, 1, 1};\n  const array<int, 8> dy = {0, 0, -1, 1, -1, 1,\
    \ -1, 1};\n  while(!q.empty()) {\n    auto [x, y] = q.front(); q.pop();\n    for(int\
    \ i = 0; i < mxD; i++) {\n      int xp = x + dx[i], yp = y + dy[i];\n      if\
    \ (inside(xp, yp) and dis[xp][yp] == INT_MAX\n          and ranges::find(wall,\
    \ g[xp][yp]) == wall.end()) {\n        q.push({xp, yp});\n        dis[xp][yp]\
    \ = dis[x][y] + 1;\n      }\n    }\n  }\n  return dis;\n}\n"
  code: "template<class T>\nvector<vector<int>> gridBFS(vector<T> &g, int sx, int\
    \ sy, T wall, int mxD) {\n  int n = ssize(g), m = ssize(g[0]);\n  auto inside\
    \ = [&](int x, int y) { return 0 <= x and x < n and 0 <= y and y < m; };\n  vector\
    \ dis(n, vector<int>(m, INT_MAX));\n  queue<array<int, 2>> q;\n  q.push({sx, sy});\n\
    \  dis[sx][sy] = 0;\n  const array<int, 8> dx = {-1, 1, 0, 0, -1, -1, 1, 1};\n\
    \  const array<int, 8> dy = {0, 0, -1, 1, -1, 1, -1, 1};\n  while(!q.empty())\
    \ {\n    auto [x, y] = q.front(); q.pop();\n    for(int i = 0; i < mxD; i++) {\n\
    \      int xp = x + dx[i], yp = y + dy[i];\n      if (inside(xp, yp) and dis[xp][yp]\
    \ == INT_MAX\n          and ranges::find(wall, g[xp][yp]) == wall.end()) {\n \
    \       q.push({xp, yp});\n        dis[xp][yp] = dis[x][y] + 1;\n      }\n   \
    \ }\n  }\n  return dis;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path/gridBFS.cpp
  requiredBy: []
  timestamp: '2026-01-30 20:10:19+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/shortest_path/gridBFS.cpp
layout: document
redirect_from:
- /library/graph/shortest_path/gridBFS.cpp
- /library/graph/shortest_path/gridBFS.cpp.html
title: graph/shortest_path/gridBFS.cpp
---
