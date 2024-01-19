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
  bundledCode: "#line 1 \"CD.cpp\"\n/**\n * template name: CentroidDecomposition\n\
    \ * author: Misuki\n * last update: 2023/07/23\n */\n\nstruct CentroidDecomposition\
    \ {\n  vector<bool> vis;\n  vector<int> sz;\n  vector<vector<int>> G;\n\n  CentroidDecomposition(vector<vector<int>>\
    \ &g) : G(g), sz(g.size()), vis(g.size(), false) {}\n\n  int calc(int V, int P)\
    \ {\n    sz[V] = 1;\n    for(int X : G[V])\n      if (X != P and !vis[X])\n  \
    \      sz[V] += calc(X, V);\n    return sz[V];\n  }\n\n  void dfs(int V, int P,\
    \ int dep, vector<int> &cnt) {\n    if (dep >= (int)cnt.size())\n      cnt.emplace_back();\n\
    \    cnt[dep] += 1;\n    for(int X : G[V])\n      if (X != P and !vis[X])\n  \
    \      dfs(X, V, dep + 1, cnt);\n  }\n\n  void CD(int V) {\n    calc(V, -1);\n\
    \n    int C = V, P = -1;\n    bool move = true;\n    do {\n      move = false;\n\
    \      for(int X : G[C]) {\n        if (X != P and !vis[X] and sz[X] * 2 > sz[V])\
    \ {\n          move = true, P = C, C = X;\n          break;\n        }\n     \
    \ }\n    } while(move);\n\n    vis[C] = true;\n\n    for(int X : G[C])\n     \
    \ if (!vis[X])\n        CD(X);\n  }\n};\n"
  code: "/**\n * template name: CentroidDecomposition\n * author: Misuki\n * last\
    \ update: 2023/07/23\n */\n\nstruct CentroidDecomposition {\n  vector<bool> vis;\n\
    \  vector<int> sz;\n  vector<vector<int>> G;\n\n  CentroidDecomposition(vector<vector<int>>\
    \ &g) : G(g), sz(g.size()), vis(g.size(), false) {}\n\n  int calc(int V, int P)\
    \ {\n    sz[V] = 1;\n    for(int X : G[V])\n      if (X != P and !vis[X])\n  \
    \      sz[V] += calc(X, V);\n    return sz[V];\n  }\n\n  void dfs(int V, int P,\
    \ int dep, vector<int> &cnt) {\n    if (dep >= (int)cnt.size())\n      cnt.emplace_back();\n\
    \    cnt[dep] += 1;\n    for(int X : G[V])\n      if (X != P and !vis[X])\n  \
    \      dfs(X, V, dep + 1, cnt);\n  }\n\n  void CD(int V) {\n    calc(V, -1);\n\
    \n    int C = V, P = -1;\n    bool move = true;\n    do {\n      move = false;\n\
    \      for(int X : G[C]) {\n        if (X != P and !vis[X] and sz[X] * 2 > sz[V])\
    \ {\n          move = true, P = C, C = X;\n          break;\n        }\n     \
    \ }\n    } while(move);\n\n    vis[C] = true;\n\n    for(int X : G[C])\n     \
    \ if (!vis[X])\n        CD(X);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: CD.cpp
  requiredBy: []
  timestamp: '2023-08-13 00:44:41+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: CD.cpp
layout: document
redirect_from:
- /library/CD.cpp
- /library/CD.cpp.html
title: CD.cpp
---
