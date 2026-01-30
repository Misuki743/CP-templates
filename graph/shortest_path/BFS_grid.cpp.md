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
  bundledCode: "#line 1 \"graph/shortest_path/BFS_grid.cpp\"\ntemplate<class T>\n\
    vvi BFS_grid(vc<T> &g, vc<pii> s, T wall, vc<pii> dxy) {\n  const int n = ssize(g);\n\
    \  constexpr int INF = numeric_limits<int>::max();\n\n  vvi dis(n);\n  for(int\
    \ i = 0; i < n; i++)\n    dis[i] = vi(size(g[i]), INF);\n\n  for(auto [x, y] :\
    \ s)\n    dis[x][y] = 0;\n\n  for(int i = 0; i < ssize(s); i++) {\n    auto [x,\
    \ y] = s[i];\n    for(auto [dx, dy] : dxy) {\n      int xp = x + dx, yp = y +\
    \ dy;\n      if ((0 <= xp and xp < n) and\n          (0 <= yp and yp < ssize(g[xp]))\
    \ and \n          dis[xp][yp] == INF and\n          ranges::find(wall, g[xp][yp])\
    \ == wall.end()) {\n        s.emplace_back(xp, yp);\n        dis[xp][yp] = dis[x][y]\
    \ + 1;\n      }\n    }\n  }\n\n  return dis;\n}\n\ntemplate<class T>\nvvi BFS_grid_4_side(vc<T>\
    \ &g, vc<pii> s, T wall) {\n  vc<pii> dxy = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};\n\
    \  return BFS_grid(g, s, wall, dxy);\n}\ntemplate<class T>\nvvi BFS_grid_8_side(vc<T>\
    \ &g, vc<pii> s, T wall) {\n  vc<pii> dxy = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},\n\
    \                 {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};\n  return BFS_grid(g,\
    \ s, wall, dxy);\n}\n"
  code: "template<class T>\nvvi BFS_grid(vc<T> &g, vc<pii> s, T wall, vc<pii> dxy)\
    \ {\n  const int n = ssize(g);\n  constexpr int INF = numeric_limits<int>::max();\n\
    \n  vvi dis(n);\n  for(int i = 0; i < n; i++)\n    dis[i] = vi(size(g[i]), INF);\n\
    \n  for(auto [x, y] : s)\n    dis[x][y] = 0;\n\n  for(int i = 0; i < ssize(s);\
    \ i++) {\n    auto [x, y] = s[i];\n    for(auto [dx, dy] : dxy) {\n      int xp\
    \ = x + dx, yp = y + dy;\n      if ((0 <= xp and xp < n) and\n          (0 <=\
    \ yp and yp < ssize(g[xp])) and \n          dis[xp][yp] == INF and\n         \
    \ ranges::find(wall, g[xp][yp]) == wall.end()) {\n        s.emplace_back(xp, yp);\n\
    \        dis[xp][yp] = dis[x][y] + 1;\n      }\n    }\n  }\n\n  return dis;\n\
    }\n\ntemplate<class T>\nvvi BFS_grid_4_side(vc<T> &g, vc<pii> s, T wall) {\n \
    \ vc<pii> dxy = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};\n  return BFS_grid(g, s, wall,\
    \ dxy);\n}\ntemplate<class T>\nvvi BFS_grid_8_side(vc<T> &g, vc<pii> s, T wall)\
    \ {\n  vc<pii> dxy = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},\n                 {0,\
    \ 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};\n  return BFS_grid(g, s, wall, dxy);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path/BFS_grid.cpp
  requiredBy: []
  timestamp: '2026-01-31 00:52:12+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/shortest_path/BFS_grid.cpp
layout: document
redirect_from:
- /library/graph/shortest_path/BFS_grid.cpp
- /library/graph/shortest_path/BFS_grid.cpp.html
title: graph/shortest_path/BFS_grid.cpp
---
