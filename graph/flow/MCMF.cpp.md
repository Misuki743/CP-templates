---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/assignment.test.cpp
    title: test/assignment.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/flow/MCMF.cpp\"\ntemplate<class capT, class cosT>\n\
    struct MCMF {\n  struct edge {\n    int to, rev;\n    capT cap;\n    cosT cos;\n\
    \    edge(int _to, capT _cap, cosT _cos, int _rev) :\n        to(_to), rev(_rev),\
    \ cap(_cap), cos(_cos) {}\n  };\n\n  int n;\n  const capT CAP_MAX = numeric_limits<capT>::max();\n\
    \  const cosT COS_MAX = numeric_limits<cosT>::max();\n  vector<vector<edge>> g;\n\
    \  vector<int> par, idx;\n  vector<capT> f;\n  vector<cosT> pot, dis;\n\n  MCMF(int\
    \ _n) : n(_n), g(n), par(n),\n    idx(n), f(n), pot(n), dis(n) {}\n\n  void addEdge(int\
    \ from, int to, capT cap, cosT cos) {\n    g[from].emplace_back(to, cap, cos,\
    \ ssize(g[to]));\n    g[to].emplace_back(from, 0, -cos, ssize(g[from]) - 1);\n\
    \  }\n\n  void initPotential(int s) {\n    fill(dis.begin(), dis.end(), COS_MAX);\n\
    \    dis[s] = 0;\n    for(int i = 1; i < n; i++) {\n      for(int v = 0; v < n;\
    \ v++) {\n        if (dis[v] == COS_MAX) continue;\n        for(edge e : g[v])\n\
    \          if (e.cap != 0 and dis[v] + e.cos < dis[e.to])\n            dis[e.to]\
    \ = dis[v] + e.cos;\n      }\n    }\n    pot.swap(dis);\n  }\n\n  void initPotentialDAG(int\
    \ s) {\n    fill(dis.begin(), dis.end(), COS_MAX);\n    dis[s] = 0;\n    vector<int>\
    \ topo = [&]() {\n      vector<int> topo;\n      vector<bool> vis(n, false);\n\
    \      auto dfs = [&](int v, auto &&self) -> void {\n        vis[v] = true;\n\
    \        for(edge e : g[v])\n          if (e.cap != 0 and !vis[e.to])\n      \
    \      self(e.to, self);\n        topo.emplace_back(v);\n      };\n      for(int\
    \ v = 0; v < n; v++)\n        if (!vis[v])\n          dfs(v, dfs);\n      return\
    \ topo;\n    }();\n    for(int v : topo | views::reverse)\n      if (dis[v] !=\
    \ COS_MAX)\n        for(edge e : g[v])\n          if (e.cap != 0)\n          \
    \  chmin(dis[e.to], dis[v] + e.cos);\n    pot.swap(dis);\n  }\n\n  pair<capT,\
    \ cosT> runFlow(int s, int t, bool dense = false) {\n    cosT cost = 0;\n    capT\
    \ flow = 0;\n    while(true) {\n      fill(dis.begin(), dis.end(), COS_MAX);\n\
    \      dis[s] = 0, f[s] = CAP_MAX;\n      if (dense) {\n        vector<bool> vis(n,\
    \ false);\n        for(int i = 0; i < n; i++) {\n          int v = -1;\n     \
    \     for(int j = 0; j < n; j++)\n            if (!vis[j] and (v == -1 or dis[j]\
    \ < dis[v]))\n              v = j;\n          if (v == -1 or dis[v] == COS_MAX)\
    \ break;\n          vis[v] = true;\n          for(edge e : g[v]) {\n         \
    \   if (e.cap == 0) continue;\n            if (cosT x = dis[v] + e.cos + pot[v]\
    \ - pot[e.to]; x < dis[e.to]) {\n              dis[e.to] = x, f[e.to] = min(f[v],\
    \ e.cap);\n              par[e.to] = v, idx[e.to] = g[e.to][e.rev].rev;\n    \
    \        }\n          }\n        }\n      } else {\n        using T = pair<cosT,\
    \ int>;\n        priority_queue<T, vector<T>, greater<T>> pq;\n        pq.push(make_pair(dis[s],\
    \ s));\n        while(!pq.empty()) {\n          auto [d, v] = pq.top(); pq.pop();\n\
    \          if (dis[v] != d) continue;\n          for(edge e : g[v]) {\n      \
    \      if (e.cap == 0) continue;\n            if (cosT x = dis[v] + e.cos + pot[v]\
    \ - pot[e.to]; x < dis[e.to]) {\n              dis[e.to] = x, f[e.to] = min(f[v],\
    \ e.cap);\n              par[e.to] = v, idx[e.to] = g[e.to][e.rev].rev;\n    \
    \          pq.push(make_pair(dis[e.to], e.to));\n            }\n          }\n\
    \        }\n      }\n\n      if (dis[t] == COS_MAX) break;\n\n      int v = t;\n\
    \      while(v != s) {\n        edge &e = g[par[v]][idx[v]];\n        e.cap -=\
    \ f[t], g[v][e.rev].cap += f[t];\n        v = par[v];\n      }\n      flow +=\
    \ f[t], cost += f[t] * (dis[t] - pot[s] + pot[t]);\n      for(int i = 0; i < n;\
    \ i++)\n        if (dis[i] != COS_MAX)\n          dis[i] += pot[i] - pot[s];\n\
    \      pot.swap(dis);\n    }\n\n    return {flow, cost};\n  }\n};\n"
  code: "template<class capT, class cosT>\nstruct MCMF {\n  struct edge {\n    int\
    \ to, rev;\n    capT cap;\n    cosT cos;\n    edge(int _to, capT _cap, cosT _cos,\
    \ int _rev) :\n        to(_to), rev(_rev), cap(_cap), cos(_cos) {}\n  };\n\n \
    \ int n;\n  const capT CAP_MAX = numeric_limits<capT>::max();\n  const cosT COS_MAX\
    \ = numeric_limits<cosT>::max();\n  vector<vector<edge>> g;\n  vector<int> par,\
    \ idx;\n  vector<capT> f;\n  vector<cosT> pot, dis;\n\n  MCMF(int _n) : n(_n),\
    \ g(n), par(n),\n    idx(n), f(n), pot(n), dis(n) {}\n\n  void addEdge(int from,\
    \ int to, capT cap, cosT cos) {\n    g[from].emplace_back(to, cap, cos, ssize(g[to]));\n\
    \    g[to].emplace_back(from, 0, -cos, ssize(g[from]) - 1);\n  }\n\n  void initPotential(int\
    \ s) {\n    fill(dis.begin(), dis.end(), COS_MAX);\n    dis[s] = 0;\n    for(int\
    \ i = 1; i < n; i++) {\n      for(int v = 0; v < n; v++) {\n        if (dis[v]\
    \ == COS_MAX) continue;\n        for(edge e : g[v])\n          if (e.cap != 0\
    \ and dis[v] + e.cos < dis[e.to])\n            dis[e.to] = dis[v] + e.cos;\n \
    \     }\n    }\n    pot.swap(dis);\n  }\n\n  void initPotentialDAG(int s) {\n\
    \    fill(dis.begin(), dis.end(), COS_MAX);\n    dis[s] = 0;\n    vector<int>\
    \ topo = [&]() {\n      vector<int> topo;\n      vector<bool> vis(n, false);\n\
    \      auto dfs = [&](int v, auto &&self) -> void {\n        vis[v] = true;\n\
    \        for(edge e : g[v])\n          if (e.cap != 0 and !vis[e.to])\n      \
    \      self(e.to, self);\n        topo.emplace_back(v);\n      };\n      for(int\
    \ v = 0; v < n; v++)\n        if (!vis[v])\n          dfs(v, dfs);\n      return\
    \ topo;\n    }();\n    for(int v : topo | views::reverse)\n      if (dis[v] !=\
    \ COS_MAX)\n        for(edge e : g[v])\n          if (e.cap != 0)\n          \
    \  chmin(dis[e.to], dis[v] + e.cos);\n    pot.swap(dis);\n  }\n\n  pair<capT,\
    \ cosT> runFlow(int s, int t, bool dense = false) {\n    cosT cost = 0;\n    capT\
    \ flow = 0;\n    while(true) {\n      fill(dis.begin(), dis.end(), COS_MAX);\n\
    \      dis[s] = 0, f[s] = CAP_MAX;\n      if (dense) {\n        vector<bool> vis(n,\
    \ false);\n        for(int i = 0; i < n; i++) {\n          int v = -1;\n     \
    \     for(int j = 0; j < n; j++)\n            if (!vis[j] and (v == -1 or dis[j]\
    \ < dis[v]))\n              v = j;\n          if (v == -1 or dis[v] == COS_MAX)\
    \ break;\n          vis[v] = true;\n          for(edge e : g[v]) {\n         \
    \   if (e.cap == 0) continue;\n            if (cosT x = dis[v] + e.cos + pot[v]\
    \ - pot[e.to]; x < dis[e.to]) {\n              dis[e.to] = x, f[e.to] = min(f[v],\
    \ e.cap);\n              par[e.to] = v, idx[e.to] = g[e.to][e.rev].rev;\n    \
    \        }\n          }\n        }\n      } else {\n        using T = pair<cosT,\
    \ int>;\n        priority_queue<T, vector<T>, greater<T>> pq;\n        pq.push(make_pair(dis[s],\
    \ s));\n        while(!pq.empty()) {\n          auto [d, v] = pq.top(); pq.pop();\n\
    \          if (dis[v] != d) continue;\n          for(edge e : g[v]) {\n      \
    \      if (e.cap == 0) continue;\n            if (cosT x = dis[v] + e.cos + pot[v]\
    \ - pot[e.to]; x < dis[e.to]) {\n              dis[e.to] = x, f[e.to] = min(f[v],\
    \ e.cap);\n              par[e.to] = v, idx[e.to] = g[e.to][e.rev].rev;\n    \
    \          pq.push(make_pair(dis[e.to], e.to));\n            }\n          }\n\
    \        }\n      }\n\n      if (dis[t] == COS_MAX) break;\n\n      int v = t;\n\
    \      while(v != s) {\n        edge &e = g[par[v]][idx[v]];\n        e.cap -=\
    \ f[t], g[v][e.rev].cap += f[t];\n        v = par[v];\n      }\n      flow +=\
    \ f[t], cost += f[t] * (dis[t] - pot[s] + pot[t]);\n      for(int i = 0; i < n;\
    \ i++)\n        if (dis[i] != COS_MAX)\n          dis[i] += pot[i] - pot[s];\n\
    \      pot.swap(dis);\n    }\n\n    return {flow, cost};\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/flow/MCMF.cpp
  requiredBy: []
  timestamp: '2026-01-30 20:10:19+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/assignment.test.cpp
documentation_of: graph/flow/MCMF.cpp
layout: document
redirect_from:
- /library/graph/flow/MCMF.cpp
- /library/graph/flow/MCMF.cpp.html
title: graph/flow/MCMF.cpp
---
