---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/bipartitematching.test.cpp
    title: test/bipartitematching.test.cpp
  - icon: ':x:'
    path: test/matching_on_bipartite_graph.test.cpp
    title: test/matching_on_bipartite_graph.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/flow/Dinic.cpp\"\ntemplate<class T>\nstruct Dinic\
    \ {\n  struct edge {\n    int to, rev;\n    T cap;\n    edge(int _to, T _cap,\
    \ int _rev)\n     : to(_to), rev(_rev), cap(_cap) {}\n  };\n\n  int n;\n  const\
    \ T CAP_MAX = numeric_limits<T>::max();\n  vector<vector<edge>> g;\n  vector<int>\
    \ lev, iter;\n\n  Dinic(int _n) : n(_n), g(n), lev(n), iter(n) {}\n\n  void addEdge(int\
    \ from, int to, T cap) {\n    g[from].emplace_back(to, cap, ssize(g[to]));\n \
    \   g[to].emplace_back(from, 0, ssize(g[from]) - 1);\n  }\n\n  bool bfs(int s,\
    \ int t) {\n    fill(lev.begin(), lev.end(), INT_MAX);\n    lev[s] = 0;\n    queue<int>\
    \ q;\n    q.push(s);\n    while(!q.empty()) {\n      int v = q.front(); q.pop();\n\
    \      for(edge &e : g[v]) if (e.cap > 0 and lev[e.to] == INT_MAX) {\n       \
    \ lev[e.to] = lev[v] + 1;\n        q.push(e.to);\n      }\n    }\n    return lev[t]\
    \ != INT_MAX;\n  }\n\n  T runFlow(int s, int t) {\n    auto dfs = [&](int v, T\
    \ f, auto &&self) -> T {\n      if (v == s) return f;\n      for(int &i = iter[v];\
    \ i < ssize(g[v]); i++) {\n        edge &e = g[v][i];\n        if (T tmp; lev[e.to]\
    \ == lev[v] - 1 and g[e.to][e.rev].cap > 0) {\n          if ((tmp = self(e.to,\
    \ min(f, g[e.to][e.rev].cap), self)) > 0) {\n            e.cap += tmp, g[e.to][e.rev].cap\
    \ -= tmp;\n            return tmp;\n          }\n        }\n      }\n      return\
    \ 0;\n    };\n    T flow = 0, del;\n    while(bfs(s, t)) {\n      fill(iter.begin(),\
    \ iter.end(), 0);\n      while((del = dfs(t, CAP_MAX, dfs)) > 0)\n        flow\
    \ = (flow >= CAP_MAX - del ? CAP_MAX : flow + del);\n    }\n\n    return flow;\n\
    \  }\n\n  bool left(int idx) { return lev[idx] != INT_MAX; }\n};\n"
  code: "template<class T>\nstruct Dinic {\n  struct edge {\n    int to, rev;\n  \
    \  T cap;\n    edge(int _to, T _cap, int _rev)\n     : to(_to), rev(_rev), cap(_cap)\
    \ {}\n  };\n\n  int n;\n  const T CAP_MAX = numeric_limits<T>::max();\n  vector<vector<edge>>\
    \ g;\n  vector<int> lev, iter;\n\n  Dinic(int _n) : n(_n), g(n), lev(n), iter(n)\
    \ {}\n\n  void addEdge(int from, int to, T cap) {\n    g[from].emplace_back(to,\
    \ cap, ssize(g[to]));\n    g[to].emplace_back(from, 0, ssize(g[from]) - 1);\n\
    \  }\n\n  bool bfs(int s, int t) {\n    fill(lev.begin(), lev.end(), INT_MAX);\n\
    \    lev[s] = 0;\n    queue<int> q;\n    q.push(s);\n    while(!q.empty()) {\n\
    \      int v = q.front(); q.pop();\n      for(edge &e : g[v]) if (e.cap > 0 and\
    \ lev[e.to] == INT_MAX) {\n        lev[e.to] = lev[v] + 1;\n        q.push(e.to);\n\
    \      }\n    }\n    return lev[t] != INT_MAX;\n  }\n\n  T runFlow(int s, int\
    \ t) {\n    auto dfs = [&](int v, T f, auto &&self) -> T {\n      if (v == s)\
    \ return f;\n      for(int &i = iter[v]; i < ssize(g[v]); i++) {\n        edge\
    \ &e = g[v][i];\n        if (T tmp; lev[e.to] == lev[v] - 1 and g[e.to][e.rev].cap\
    \ > 0) {\n          if ((tmp = self(e.to, min(f, g[e.to][e.rev].cap), self)) >\
    \ 0) {\n            e.cap += tmp, g[e.to][e.rev].cap -= tmp;\n            return\
    \ tmp;\n          }\n        }\n      }\n      return 0;\n    };\n    T flow =\
    \ 0, del;\n    while(bfs(s, t)) {\n      fill(iter.begin(), iter.end(), 0);\n\
    \      while((del = dfs(t, CAP_MAX, dfs)) > 0)\n        flow = (flow >= CAP_MAX\
    \ - del ? CAP_MAX : flow + del);\n    }\n\n    return flow;\n  }\n\n  bool left(int\
    \ idx) { return lev[idx] != INT_MAX; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/flow/Dinic.cpp
  requiredBy: []
  timestamp: '2026-01-30 20:10:19+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/bipartitematching.test.cpp
  - test/matching_on_bipartite_graph.test.cpp
documentation_of: graph/flow/Dinic.cpp
layout: document
redirect_from:
- /library/graph/flow/Dinic.cpp
- /library/graph/flow/Dinic.cpp.html
title: graph/flow/Dinic.cpp
---
