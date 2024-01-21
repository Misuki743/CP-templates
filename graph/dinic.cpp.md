---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/matching_on_bipartite_graph.test.cpp
    title: test/matching_on_bipartite_graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/dinic.cpp\"\ntemplate<class T, T MAX>\nstruct Dinic\
    \ {\n  const int N;\n  struct Edge {\n    int to, rev;\n    T cap;\n    Edge(int\
    \ _to, T _cap, int _rev) : to(_to), rev(_rev), cap(_cap) {}\n  };\n  vector<vector<Edge>>\
    \ G;\n  Dinic(int _N) : N(_N), G(_N), level(_N), iter(_N) {}\n  void addEdge(int\
    \ from, int to, T cap) {\n    G[from].emplace_back(Edge(to, cap, G[to].size()));\n\
    \    G[to].emplace_back(Edge(from, 0, (int)G[from].size() - 1));\n  }\n  int n,\
    \ s, t;\n  void init(int _n, int _s, int _t) {\n    n = _n, s = _s, t = _t;\n\
    \    for(int i = 0; i < n; i++)\n      G[i].clear();\n  }\n  vector<int> level,\
    \ iter;\n  void BFS() {\n    fill(level.begin(), level.end(), INT_MAX);\n    level[s]\
    \ = 0;\n    queue<int> q;\n    q.push(s);\n    while(!q.empty()) {\n      int\
    \ now = q.front(); q.pop();\n      for(Edge &E : G[now]) {\n        if (E.cap\
    \ > 0 and level[E.to] == INT_MAX) {\n          level[E.to] = level[now] + 1;\n\
    \          q.push(E.to);\n        }\n      }\n    }\n  }\n  T DFS(int V, T flow)\
    \ {\n    if (V == s)\n      return flow;\n\n    for(int &i = iter[V]; i < ssize(G[V]);\
    \ i++) {\n      Edge &E = G[V][i];\n      if (T tmp; level[E.to] == level[V] -\
    \ 1 and G[E.to][E.rev].cap > 0) {\n        if ((tmp = DFS(E.to, min(flow, G[E.to][E.rev].cap)))\
    \ > 0) {\n          E.cap += tmp, G[E.to][E.rev].cap -= tmp;\n          return\
    \ tmp;\n        }\n      }\n    }\n\n    return 0;\n  }\n\n  T flow() {\n    T\
    \ res = 0;\n    while(true) {\n      BFS();\n      if (level[t] == INT_MAX)\n\
    \        break;\n      fill(iter.begin(), iter.end(), 0);\n      T del;\n    \
    \  while((del = DFS(t, MAX)) > 0) {\n        res += del;\n      }\n    }\n\n \
    \   return res;\n  }\n\n  bool left(int idx) {\n    return level[idx] != INT_MAX;\n\
    \  }\n};\n"
  code: "template<class T, T MAX>\nstruct Dinic {\n  const int N;\n  struct Edge {\n\
    \    int to, rev;\n    T cap;\n    Edge(int _to, T _cap, int _rev) : to(_to),\
    \ rev(_rev), cap(_cap) {}\n  };\n  vector<vector<Edge>> G;\n  Dinic(int _N) :\
    \ N(_N), G(_N), level(_N), iter(_N) {}\n  void addEdge(int from, int to, T cap)\
    \ {\n    G[from].emplace_back(Edge(to, cap, G[to].size()));\n    G[to].emplace_back(Edge(from,\
    \ 0, (int)G[from].size() - 1));\n  }\n  int n, s, t;\n  void init(int _n, int\
    \ _s, int _t) {\n    n = _n, s = _s, t = _t;\n    for(int i = 0; i < n; i++)\n\
    \      G[i].clear();\n  }\n  vector<int> level, iter;\n  void BFS() {\n    fill(level.begin(),\
    \ level.end(), INT_MAX);\n    level[s] = 0;\n    queue<int> q;\n    q.push(s);\n\
    \    while(!q.empty()) {\n      int now = q.front(); q.pop();\n      for(Edge\
    \ &E : G[now]) {\n        if (E.cap > 0 and level[E.to] == INT_MAX) {\n      \
    \    level[E.to] = level[now] + 1;\n          q.push(E.to);\n        }\n     \
    \ }\n    }\n  }\n  T DFS(int V, T flow) {\n    if (V == s)\n      return flow;\n\
    \n    for(int &i = iter[V]; i < ssize(G[V]); i++) {\n      Edge &E = G[V][i];\n\
    \      if (T tmp; level[E.to] == level[V] - 1 and G[E.to][E.rev].cap > 0) {\n\
    \        if ((tmp = DFS(E.to, min(flow, G[E.to][E.rev].cap))) > 0) {\n       \
    \   E.cap += tmp, G[E.to][E.rev].cap -= tmp;\n          return tmp;\n        }\n\
    \      }\n    }\n\n    return 0;\n  }\n\n  T flow() {\n    T res = 0;\n    while(true)\
    \ {\n      BFS();\n      if (level[t] == INT_MAX)\n        break;\n      fill(iter.begin(),\
    \ iter.end(), 0);\n      T del;\n      while((del = DFS(t, MAX)) > 0) {\n    \
    \    res += del;\n      }\n    }\n\n    return res;\n  }\n\n  bool left(int idx)\
    \ {\n    return level[idx] != INT_MAX;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dinic.cpp
  requiredBy: []
  timestamp: '2024-01-21 19:52:41+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/matching_on_bipartite_graph.test.cpp
documentation_of: graph/dinic.cpp
layout: document
redirect_from:
- /library/graph/dinic.cpp
- /library/graph/dinic.cpp.html
title: graph/dinic.cpp
---
