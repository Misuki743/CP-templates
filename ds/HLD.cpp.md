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
  bundledCode: "#line 1 \"ds/HLD.cpp\"\nconst int MAXN = 200000;\nvector<int> G[MAXN];\n\
    int mxChild[MAXN], dep[MAXN], sz[MAXN], fa[MAXN];\nint head[MAXN], idx[MAXN];\n\
    //int tout[MAXN];\n//for subtree query/modify\n\nstruct HLD {\n  void addEdge(int\
    \ u, int v) {\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n  }\n\n \
    \ void build(vector<int> root = vector<int>(1, 0)) {\n    fill(mxChild, mxChild\
    \ + MAXN, -1);\n    fill(fa, fa + MAXN, -1);\n    for(int X : root) {\n      DFS(X,\
    \ -1);\n      cut(X, X);\n    }\n  }\n\n  void DFS(int V, int P) {\n    sz[V]\
    \ = 1;\n    for(int X : G[V]) {\n      if (X != P) {\n        fa[X] = V, dep[X]\
    \ = dep[V] + 1;\n        DFS(X, V);\n        sz[V] += sz[X];\n        if (mxChild[V]\
    \ == -1 or sz[X] > sz[mxChild[V]])\n          mxChild[V] = X;\n      }\n    }\n\
    \  }\n\n  int t = 0;\n  void cut(int V, int H) {\n    idx[V] = t++, head[V] =\
    \ H;\n    if (mxChild[V] == -1)\n      return;\n\n    cut(mxChild[V], H);\n  \
    \  for(int X : G[V]) \n      if (X != mxChild[V] and X != fa[V])\n        cut(X,\
    \ X);\n  }\n\n  vector<pii> query(int u, int v, bool edge = false) {\n    vector<pii>\
    \ res;\n    while(head[u] != head[v]) {\n      if (dep[head[u]] > dep[head[v]])\n\
    \        swap(u, v);\n      res.emplace_back(idx[head[v]], idx[v]);\n      v =\
    \ fa[head[v]];\n    }\n    if (idx[u] > idx[v])\n      swap(u, v);\n    if (idx[u]\
    \ + edge <= idx[v])\n      res.emplace_back(idx[u] + edge, idx[v]);\n\n    return\
    \ res;\n  }\n\n  int LCA(int u, int v) {\n    while(head[u] != head[v]) {\n  \
    \    if (dep[head[u]] > dep[head[v]])\n        swap(u, v);\n      v = fa[head[v]];\n\
    \    }\n    return dep[u] > dep[v] ? v : u;\n  }\n};\n"
  code: "const int MAXN = 200000;\nvector<int> G[MAXN];\nint mxChild[MAXN], dep[MAXN],\
    \ sz[MAXN], fa[MAXN];\nint head[MAXN], idx[MAXN];\n//int tout[MAXN];\n//for subtree\
    \ query/modify\n\nstruct HLD {\n  void addEdge(int u, int v) {\n    G[u].emplace_back(v);\n\
    \    G[v].emplace_back(u);\n  }\n\n  void build(vector<int> root = vector<int>(1,\
    \ 0)) {\n    fill(mxChild, mxChild + MAXN, -1);\n    fill(fa, fa + MAXN, -1);\n\
    \    for(int X : root) {\n      DFS(X, -1);\n      cut(X, X);\n    }\n  }\n\n\
    \  void DFS(int V, int P) {\n    sz[V] = 1;\n    for(int X : G[V]) {\n      if\
    \ (X != P) {\n        fa[X] = V, dep[X] = dep[V] + 1;\n        DFS(X, V);\n  \
    \      sz[V] += sz[X];\n        if (mxChild[V] == -1 or sz[X] > sz[mxChild[V]])\n\
    \          mxChild[V] = X;\n      }\n    }\n  }\n\n  int t = 0;\n  void cut(int\
    \ V, int H) {\n    idx[V] = t++, head[V] = H;\n    if (mxChild[V] == -1)\n   \
    \   return;\n\n    cut(mxChild[V], H);\n    for(int X : G[V]) \n      if (X !=\
    \ mxChild[V] and X != fa[V])\n        cut(X, X);\n  }\n\n  vector<pii> query(int\
    \ u, int v, bool edge = false) {\n    vector<pii> res;\n    while(head[u] != head[v])\
    \ {\n      if (dep[head[u]] > dep[head[v]])\n        swap(u, v);\n      res.emplace_back(idx[head[v]],\
    \ idx[v]);\n      v = fa[head[v]];\n    }\n    if (idx[u] > idx[v])\n      swap(u,\
    \ v);\n    if (idx[u] + edge <= idx[v])\n      res.emplace_back(idx[u] + edge,\
    \ idx[v]);\n\n    return res;\n  }\n\n  int LCA(int u, int v) {\n    while(head[u]\
    \ != head[v]) {\n      if (dep[head[u]] > dep[head[v]])\n        swap(u, v);\n\
    \      v = fa[head[v]];\n    }\n    return dep[u] > dep[v] ? v : u;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/HLD.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/HLD.cpp
layout: document
redirect_from:
- /library/ds/HLD.cpp
- /library/ds/HLD.cpp.html
title: ds/HLD.cpp
---
