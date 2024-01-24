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
  bundledCode: "#line 1 \"ds/CD.cpp\"\nstruct CentroidDecomposition {\n  vector<bool>\
    \ vis;\n  vector<int> sz;\n  vector<vector<int>> G;\n\n  CentroidDecomposition(vector<vector<int>>\
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
  code: "struct CentroidDecomposition {\n  vector<bool> vis;\n  vector<int> sz;\n\
    \  vector<vector<int>> G;\n\n  CentroidDecomposition(vector<vector<int>> &g) :\
    \ G(g), sz(g.size()), vis(g.size(), false) {}\n\n  int calc(int V, int P) {\n\
    \    sz[V] = 1;\n    for(int X : G[V])\n      if (X != P and !vis[X])\n      \
    \  sz[V] += calc(X, V);\n    return sz[V];\n  }\n\n  void dfs(int V, int P, int\
    \ dep, vector<int> &cnt) {\n    if (dep >= (int)cnt.size())\n      cnt.emplace_back();\n\
    \    cnt[dep] += 1;\n    for(int X : G[V])\n      if (X != P and !vis[X])\n  \
    \      dfs(X, V, dep + 1, cnt);\n  }\n\n  void CD(int V) {\n    calc(V, -1);\n\
    \n    int C = V, P = -1;\n    bool move = true;\n    do {\n      move = false;\n\
    \      for(int X : G[C]) {\n        if (X != P and !vis[X] and sz[X] * 2 > sz[V])\
    \ {\n          move = true, P = C, C = X;\n          break;\n        }\n     \
    \ }\n    } while(move);\n\n    vis[C] = true;\n\n    for(int X : G[C])\n     \
    \ if (!vis[X])\n        CD(X);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/CD.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/CD.cpp
layout: document
redirect_from:
- /library/ds/CD.cpp
- /library/ds/CD.cpp.html
title: ds/CD.cpp
---
