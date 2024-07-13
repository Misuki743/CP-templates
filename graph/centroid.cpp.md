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
  bundledCode: "#line 1 \"graph/centroid.cpp\"\narray<int, 2> centroid(vector<vector<int>>\
    \ &g) {\n  int n = ssize(g);\n  vector<int> sz(n, 1);\n  auto dfs = [&](int v,\
    \ int p, auto &&self) -> void {\n    for(int x : g[v]) {\n      if (x == p) continue;\n\
    \      self(x, v, self);\n      sz[v] += sz[x];\n    }\n  };\n  dfs(0, -1, dfs);\n\
    \  bool done = false;\n  int c = 0, p = -1;\n  while(!done) {\n    done = true;\n\
    \    for(int x : g[c]) {\n      if (x == p or 2 * sz[x] <= n) continue;\n    \
    \  p = c, c = x, done = false;\n      break;\n    }\n  }\n  int c2 = -1;\n  for(int\
    \ x : g[c])\n    if (x != p and 2 * sz[x] == n)\n      c2 = x;\n  return {c, c2};\n\
    }\n"
  code: "array<int, 2> centroid(vector<vector<int>> &g) {\n  int n = ssize(g);\n \
    \ vector<int> sz(n, 1);\n  auto dfs = [&](int v, int p, auto &&self) -> void {\n\
    \    for(int x : g[v]) {\n      if (x == p) continue;\n      self(x, v, self);\n\
    \      sz[v] += sz[x];\n    }\n  };\n  dfs(0, -1, dfs);\n  bool done = false;\n\
    \  int c = 0, p = -1;\n  while(!done) {\n    done = true;\n    for(int x : g[c])\
    \ {\n      if (x == p or 2 * sz[x] <= n) continue;\n      p = c, c = x, done =\
    \ false;\n      break;\n    }\n  }\n  int c2 = -1;\n  for(int x : g[c])\n    if\
    \ (x != p and 2 * sz[x] == n)\n      c2 = x;\n  return {c, c2};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/centroid.cpp
  requiredBy: []
  timestamp: '2024-07-13 22:34:20+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/centroid.cpp
layout: document
redirect_from:
- /library/graph/centroid.cpp
- /library/graph/centroid.cpp.html
title: graph/centroid.cpp
---
