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
  bundledCode: "#line 1 \"MCMF.cpp\"\n/**\n * template name: MCMF\n * author: Misuki\n\
    \ * last update: 2021/11/11\n */\n\nstruct MCMF {\n  struct Edge {\n    int to,\
    \ rev;\n    long long cap, cos;\n    Edge(int _to, long long _cap, long long _cos,\
    \ int _rev) :\n        to(_to), cap(_cap), cos(_cos), rev(_rev) {}\n  };\n\n \
    \ static const int SIZE = 3502;\n  int n, s, t;\n  vector<Edge> G[SIZE];\n  array<int,\
    \ SIZE> par, idx;\n  array<long long, SIZE> pot, dis, f; \n\n  void init(int _n,\
    \ int _s, int _t) {\n    n = _n, s = _s, t = _t;\n    for(int i = 0; i < n; i++)\n\
    \      G[i].clear();\n  }\n\n  void addEdge(int from, int to, long long cap, long\
    \ long cos) {\n    G[from].emplace_back(Edge(to, cap, cos, G[to].size()));\n \
    \   G[to].emplace_back(Edge(from, 0, -cos, (int)G[from].size() - 1));\n  }\n\n\
    \  void initPotential() {\n    fill(dis.begin(), dis.end(), LLONG_MAX);\n    dis[s]\
    \ = 0;\n    for(int i = 1; i < n; i++) {\n      for(int j = 0; j < n; j++) {\n\
    \        if (dis[j] == LLONG_MAX)\n          continue;\n        for(Edge E : G[j])\
    \ {\n          if (E.cap == 0)\n            continue;\n          if (dis[j] +\
    \ E.cos < dis[E.to])\n            dis[E.to] = dis[j] + E.cos;\n        }\n   \
    \   }\n    }\n    pot.swap(dis);\n  }\n\n  pll flow() {\n    long long Cost =\
    \ 0, Flow = 0;\n    while(true) {\n      priority_queue<pii, vector<pii>, greater<pii>\
    \ > pq;\n      fill(dis.begin(), dis.end(), LLONG_MAX);\n      dis[s] = 0, f[s]\
    \ = LLONG_MAX;\n      pq.push(make_pair(0, s));\n      while(!pq.empty()) {\n\
    \        pii now = pq.top(); pq.pop();\n        if (dis[now.second] != now.first)\n\
    \          continue;\n\n        int V = now.second;\n        for(Edge E : G[V])\
    \ {\n          if (E.cap == 0)\n            continue;\n          if (dis[V] +\
    \ E.cos + pot[V] - pot[E.to] < dis[E.to]) {\n            dis[E.to] = dis[V] +\
    \ E.cos + pot[V] - pot[E.to];\n            f[E.to] = min(f[V], E.cap);\n     \
    \       par[E.to] = V;\n            idx[E.to] = G[E.to][E.rev].rev;\n        \
    \    pq.push(make_pair(dis[E.to], E.to));\n          }\n        }\n      }\n\n\
    \      if (dis[t] == LLONG_MAX)\n        break;\n\n      long long bot = f[t];\n\
    \      int now = t;\n      while(now != s) {\n        Edge &E = G[par[now]][idx[now]];\n\
    \        E.cap -= bot;\n        G[now][E.rev].cap += bot;\n        now = par[now];\n\
    \      }\n      Flow += bot, Cost += bot * (dis[t] - pot[s] + pot[t]);\n\n   \
    \   for(int i = 0; i < n; i++) {\n        dis[i] += pot[i] - pot[s];\n      }\n\
    \      pot.swap(dis);\n    }\n\n    return make_pair(Flow, Cost);\n  }\n};\n"
  code: "/**\n * template name: MCMF\n * author: Misuki\n * last update: 2021/11/11\n\
    \ */\n\nstruct MCMF {\n  struct Edge {\n    int to, rev;\n    long long cap, cos;\n\
    \    Edge(int _to, long long _cap, long long _cos, int _rev) :\n        to(_to),\
    \ cap(_cap), cos(_cos), rev(_rev) {}\n  };\n\n  static const int SIZE = 3502;\n\
    \  int n, s, t;\n  vector<Edge> G[SIZE];\n  array<int, SIZE> par, idx;\n  array<long\
    \ long, SIZE> pot, dis, f; \n\n  void init(int _n, int _s, int _t) {\n    n =\
    \ _n, s = _s, t = _t;\n    for(int i = 0; i < n; i++)\n      G[i].clear();\n \
    \ }\n\n  void addEdge(int from, int to, long long cap, long long cos) {\n    G[from].emplace_back(Edge(to,\
    \ cap, cos, G[to].size()));\n    G[to].emplace_back(Edge(from, 0, -cos, (int)G[from].size()\
    \ - 1));\n  }\n\n  void initPotential() {\n    fill(dis.begin(), dis.end(), LLONG_MAX);\n\
    \    dis[s] = 0;\n    for(int i = 1; i < n; i++) {\n      for(int j = 0; j < n;\
    \ j++) {\n        if (dis[j] == LLONG_MAX)\n          continue;\n        for(Edge\
    \ E : G[j]) {\n          if (E.cap == 0)\n            continue;\n          if\
    \ (dis[j] + E.cos < dis[E.to])\n            dis[E.to] = dis[j] + E.cos;\n    \
    \    }\n      }\n    }\n    pot.swap(dis);\n  }\n\n  pll flow() {\n    long long\
    \ Cost = 0, Flow = 0;\n    while(true) {\n      priority_queue<pii, vector<pii>,\
    \ greater<pii> > pq;\n      fill(dis.begin(), dis.end(), LLONG_MAX);\n      dis[s]\
    \ = 0, f[s] = LLONG_MAX;\n      pq.push(make_pair(0, s));\n      while(!pq.empty())\
    \ {\n        pii now = pq.top(); pq.pop();\n        if (dis[now.second] != now.first)\n\
    \          continue;\n\n        int V = now.second;\n        for(Edge E : G[V])\
    \ {\n          if (E.cap == 0)\n            continue;\n          if (dis[V] +\
    \ E.cos + pot[V] - pot[E.to] < dis[E.to]) {\n            dis[E.to] = dis[V] +\
    \ E.cos + pot[V] - pot[E.to];\n            f[E.to] = min(f[V], E.cap);\n     \
    \       par[E.to] = V;\n            idx[E.to] = G[E.to][E.rev].rev;\n        \
    \    pq.push(make_pair(dis[E.to], E.to));\n          }\n        }\n      }\n\n\
    \      if (dis[t] == LLONG_MAX)\n        break;\n\n      long long bot = f[t];\n\
    \      int now = t;\n      while(now != s) {\n        Edge &E = G[par[now]][idx[now]];\n\
    \        E.cap -= bot;\n        G[now][E.rev].cap += bot;\n        now = par[now];\n\
    \      }\n      Flow += bot, Cost += bot * (dis[t] - pot[s] + pot[t]);\n\n   \
    \   for(int i = 0; i < n; i++) {\n        dis[i] += pot[i] - pot[s];\n      }\n\
    \      pot.swap(dis);\n    }\n\n    return make_pair(Flow, Cost);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: MCMF.cpp
  requiredBy: []
  timestamp: '2023-06-16 02:10:58+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: MCMF.cpp
layout: document
redirect_from:
- /library/MCMF.cpp
- /library/MCMF.cpp.html
title: MCMF.cpp
---
