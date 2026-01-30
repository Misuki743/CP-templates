---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/vertex_set_path_composite.test.cpp
    title: test/vertex_set_path_composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/heavyLightDecomposition.cpp\"\nstruct HLD {\n  int\
    \ n;\n  vector<int> dep, p, head, id;\n\n  HLD(vector<vector<int>> &g, vector<int>\
    \ root = vector<int>(1, 0))\n  : n(ssize(g)), dep(n), p(n, -1), head(n), id(n)\
    \ {\n    vector<int> sz(n, 1);\n\n    auto dfs = [&](int v, auto self) -> void\
    \ {\n      int mx = -1;\n      for(int i = -1; int x : g[v]) {\n        i++;\n\
    \        if (x == p[v]) continue;\n        p[x] = v, dep[x] = dep[v] + 1;\n  \
    \      self(x, self);\n        sz[v] += sz[x];\n        if (mx == -1 or sz[x]\
    \ > sz[g[v][mx]]) mx = i;\n      }\n      if (mx != -1) swap(g[v][0], g[v][mx]);\n\
    \    };\n\n    int nxt = 0;\n    auto cut = [&](int v, int h, auto self) -> void\
    \ {\n      id[v] = nxt++, head[v] = h;\n      if (!g[v].empty() and g[v][0] !=\
    \ p[v])\n        self(g[v][0], h, self);\n      for(int x : g[v] | views::drop(1))\
    \ if (x != p[v])\n          self(x, x, self);\n    };\n\n    for(int x : root)\
    \ {\n      dfs(x, dfs);\n      cut(x, x, cut);\n    }\n  }\n\n  //(l, r, rev)\n\
    \  vector<tuple<int, int, bool>> query(int u, int v, bool edge = false) {\n  \
    \  vector<array<int, 2>> resL, resR;\n    while(head[u] != head[v]) {\n      if\
    \ (dep[head[u]] >= dep[head[v]]) {\n        resL.push_back({id[head[u]], id[u]\
    \ + 1});\n        u = p[head[u]];\n      } else {\n        resR.push_back({id[head[v]],\
    \ id[v] + 1});\n        v = p[head[v]];\n      }\n    }\n    if (id[v] + edge\
    \ <= id[u])\n      resL.push_back({id[v] + edge, id[u] + 1});\n    else if (id[u]\
    \ + edge <= id[v])\n      resR.push_back({id[u] + edge, id[v] + 1});\n    vector<tuple<int,\
    \ int, bool>> res;\n    for(auto [l, r] : resL)\n      res.push_back({l, r, true});\n\
    \    for(auto [l, r] : resR | views::reverse)\n      res.push_back({l, r, false});\n\
    \    return res;\n  }\n};\n"
  code: "struct HLD {\n  int n;\n  vector<int> dep, p, head, id;\n\n  HLD(vector<vector<int>>\
    \ &g, vector<int> root = vector<int>(1, 0))\n  : n(ssize(g)), dep(n), p(n, -1),\
    \ head(n), id(n) {\n    vector<int> sz(n, 1);\n\n    auto dfs = [&](int v, auto\
    \ self) -> void {\n      int mx = -1;\n      for(int i = -1; int x : g[v]) {\n\
    \        i++;\n        if (x == p[v]) continue;\n        p[x] = v, dep[x] = dep[v]\
    \ + 1;\n        self(x, self);\n        sz[v] += sz[x];\n        if (mx == -1\
    \ or sz[x] > sz[g[v][mx]]) mx = i;\n      }\n      if (mx != -1) swap(g[v][0],\
    \ g[v][mx]);\n    };\n\n    int nxt = 0;\n    auto cut = [&](int v, int h, auto\
    \ self) -> void {\n      id[v] = nxt++, head[v] = h;\n      if (!g[v].empty()\
    \ and g[v][0] != p[v])\n        self(g[v][0], h, self);\n      for(int x : g[v]\
    \ | views::drop(1)) if (x != p[v])\n          self(x, x, self);\n    };\n\n  \
    \  for(int x : root) {\n      dfs(x, dfs);\n      cut(x, x, cut);\n    }\n  }\n\
    \n  //(l, r, rev)\n  vector<tuple<int, int, bool>> query(int u, int v, bool edge\
    \ = false) {\n    vector<array<int, 2>> resL, resR;\n    while(head[u] != head[v])\
    \ {\n      if (dep[head[u]] >= dep[head[v]]) {\n        resL.push_back({id[head[u]],\
    \ id[u] + 1});\n        u = p[head[u]];\n      } else {\n        resR.push_back({id[head[v]],\
    \ id[v] + 1});\n        v = p[head[v]];\n      }\n    }\n    if (id[v] + edge\
    \ <= id[u])\n      resL.push_back({id[v] + edge, id[u] + 1});\n    else if (id[u]\
    \ + edge <= id[v])\n      resR.push_back({id[u] + edge, id[v] + 1});\n    vector<tuple<int,\
    \ int, bool>> res;\n    for(auto [l, r] : resL)\n      res.push_back({l, r, true});\n\
    \    for(auto [l, r] : resR | views::reverse)\n      res.push_back({l, r, false});\n\
    \    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/heavyLightDecomposition.cpp
  requiredBy: []
  timestamp: '2026-01-30 20:10:19+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/vertex_set_path_composite.test.cpp
documentation_of: tree/heavyLightDecomposition.cpp
layout: document
redirect_from:
- /library/tree/heavyLightDecomposition.cpp
- /library/tree/heavyLightDecomposition.cpp.html
title: tree/heavyLightDecomposition.cpp
---
