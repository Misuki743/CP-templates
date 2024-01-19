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
  bundledCode: "#line 1 \"dinic.cpp\"\n/**\n * template name: dinic\n * author: Misuki\n\
    \ * last update: 2022/05/02\n * verify: ABC239 pG - Builder Takahashi\n */\n\n\
    template<class T, T MAX>\nstruct Dinic {\n  const static int N = 202;\n  struct\
    \ Edge {\n    int to, rev;\n    T cap;\n    Edge(int _to, T _cap, int _rev) :\
    \ to(_to), cap(_cap), rev(_rev) {}\n  };\n  vector<Edge> G[N];\n  void addEdge(int\
    \ from, int to, T cap) {\n    G[from].emplace_back(Edge(to, cap, G[to].size()));\n\
    \    G[to].emplace_back(Edge(from, 0, (int)G[from].size() - 1));\n  }\n  int n,\
    \ s, t;\n  void init(int _n, int _s, int _t) {\n    n = _n, s = _s, t = _t;\n\
    \    for(int i = 0; i < n; i++)\n      G[i].clear();\n  }\n  int level[N], iter[N];\n\
    \  void BFS() {\n    fill(level, level + n, INT_MAX);\n    level[s] = 0;\n   \
    \ queue<int> q;\n    q.push(s);\n    while(!q.empty()) {\n      int now = q.front();\
    \ q.pop();\n      for(Edge &E : G[now]) {\n        if (E.cap > 0 and level[E.to]\
    \ == INT_MAX) {\n          level[E.to] = level[now] + 1;\n          q.push(E.to);\n\
    \        }\n      }\n    }\n  }\n  T DFS(int V, T flow) {\n    if (V == s)\n \
    \     return flow;\n\n    for(int &i = iter[V]; i < G[V].size(); i++) {\n    \
    \  Edge &E = G[V][i];\n      if (T tmp; level[E.to] == level[V] - 1 and G[E.to][E.rev].cap\
    \ > 0) {\n        if ((tmp = DFS(E.to, min(flow, G[E.to][E.rev].cap))) > 0) {\n\
    \          E.cap += tmp, G[E.to][E.rev].cap -= tmp;\n          return tmp;\n \
    \       }\n      }\n    }\n\n    return 0;\n  }\n\n  T flow() {\n    T res = 0;\n\
    \    while(true) {\n      BFS();\n      if (level[t] == INT_MAX)\n        break;\n\
    \      fill(iter, iter + n, 0);\n      T del;\n      while((del = DFS(t, MAX))\
    \ > 0) {\n        res += del;\n      }\n    }\n\n    return res;\n  }\n\n  bool\
    \ left(int idx) {\n    return level[idx] != INT_MAX;\n  }\n};\n"
  code: "/**\n * template name: dinic\n * author: Misuki\n * last update: 2022/05/02\n\
    \ * verify: ABC239 pG - Builder Takahashi\n */\n\ntemplate<class T, T MAX>\nstruct\
    \ Dinic {\n  const static int N = 202;\n  struct Edge {\n    int to, rev;\n  \
    \  T cap;\n    Edge(int _to, T _cap, int _rev) : to(_to), cap(_cap), rev(_rev)\
    \ {}\n  };\n  vector<Edge> G[N];\n  void addEdge(int from, int to, T cap) {\n\
    \    G[from].emplace_back(Edge(to, cap, G[to].size()));\n    G[to].emplace_back(Edge(from,\
    \ 0, (int)G[from].size() - 1));\n  }\n  int n, s, t;\n  void init(int _n, int\
    \ _s, int _t) {\n    n = _n, s = _s, t = _t;\n    for(int i = 0; i < n; i++)\n\
    \      G[i].clear();\n  }\n  int level[N], iter[N];\n  void BFS() {\n    fill(level,\
    \ level + n, INT_MAX);\n    level[s] = 0;\n    queue<int> q;\n    q.push(s);\n\
    \    while(!q.empty()) {\n      int now = q.front(); q.pop();\n      for(Edge\
    \ &E : G[now]) {\n        if (E.cap > 0 and level[E.to] == INT_MAX) {\n      \
    \    level[E.to] = level[now] + 1;\n          q.push(E.to);\n        }\n     \
    \ }\n    }\n  }\n  T DFS(int V, T flow) {\n    if (V == s)\n      return flow;\n\
    \n    for(int &i = iter[V]; i < G[V].size(); i++) {\n      Edge &E = G[V][i];\n\
    \      if (T tmp; level[E.to] == level[V] - 1 and G[E.to][E.rev].cap > 0) {\n\
    \        if ((tmp = DFS(E.to, min(flow, G[E.to][E.rev].cap))) > 0) {\n       \
    \   E.cap += tmp, G[E.to][E.rev].cap -= tmp;\n          return tmp;\n        }\n\
    \      }\n    }\n\n    return 0;\n  }\n\n  T flow() {\n    T res = 0;\n    while(true)\
    \ {\n      BFS();\n      if (level[t] == INT_MAX)\n        break;\n      fill(iter,\
    \ iter + n, 0);\n      T del;\n      while((del = DFS(t, MAX)) > 0) {\n      \
    \  res += del;\n      }\n    }\n\n    return res;\n  }\n\n  bool left(int idx)\
    \ {\n    return level[idx] != INT_MAX;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: dinic.cpp
  requiredBy: []
  timestamp: '2023-06-16 02:10:58+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dinic.cpp
layout: document
redirect_from:
- /library/dinic.cpp
- /library/dinic.cpp.html
title: dinic.cpp
---
