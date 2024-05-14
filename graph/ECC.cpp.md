---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/two_edge_connected_components.test.cpp
    title: test/two_edge_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/ECC.cpp\"\nstruct ECC {\n  vector<int> vb, gv, vid;\n\
    \  vector<array<int, 2>> e;\n  int size = -1;\n\n  ECC(vector<array<int, 2>> &_e,\
    \ int n) : vid(n), e(_e) {\n    auto newComp = [&]() { vb.emplace_back(ssize(gv)),\
    \ size++; };\n\n    vector<vector<int>> g(n);\n    for(int i = 0; auto [u, v]\
    \ : e) {\n      g[u].emplace_back(i);\n      g[v].emplace_back(i++);\n    }\n\n\
    \    int t = 0, root;\n    vector<int> tin(n, -1), low(n), s;\n    vector<bool>\
    \ vis(ssize(e), false);\n\n    auto extract = [&](int v) {\n      newComp();\n\
    \      do {\n        int u = s.back(); s.pop_back();\n        vid[u] = size;\n\
    \        gv.emplace_back(u);\n      } while(gv.back() != v);\n    };\n\n    auto\
    \ dfs = [&](int v, auto &&self) -> void {\n      tin[v] = low[v] = t++;\n    \
    \  s.emplace_back(v);\n      for(int i : g[v]) if (!vis[i]) {\n        int x =\
    \ e[i][0] ^ e[i][1] ^ v;\n        vis[i] = true;\n        if (tin[x] != -1) {\n\
    \          low[v] = min(low[v], tin[x]);\n        } else {\n          self(x,\
    \ self);\n          low[v] = min(low[v], low[x]);\n          if (low[x] > tin[v])\
    \ extract(x);\n        }\n      }\n      if (v == root) extract(root);\n    };\n\
    \n    for(int v = 0; v < n; v++)\n      if (tin[v] == -1)\n        dfs(root =\
    \ v, dfs);\n\n    newComp();\n  }\n\n  vector<int> vertexGroup(int id) {\n   \
    \ return {gv.begin() + vb[id], gv.begin() + vb[id + 1]};\n  }\n  bool isBridge(int\
    \ id) { return vid[e[id][0]] != vid[e[id][1]]; }\n  vector<vector<int>> bridgeTree()\
    \ {\n    vector<vector<int>> g(size);\n    for(auto [u, v] : e) {\n      if ((u\
    \ = vid[u]) != (v = vid[v])) {\n        g[u].emplace_back(v);\n        g[v].emplace_back(u);\n\
    \      }\n    }\n    return g;\n  }\n};\n"
  code: "struct ECC {\n  vector<int> vb, gv, vid;\n  vector<array<int, 2>> e;\n  int\
    \ size = -1;\n\n  ECC(vector<array<int, 2>> &_e, int n) : vid(n), e(_e) {\n  \
    \  auto newComp = [&]() { vb.emplace_back(ssize(gv)), size++; };\n\n    vector<vector<int>>\
    \ g(n);\n    for(int i = 0; auto [u, v] : e) {\n      g[u].emplace_back(i);\n\
    \      g[v].emplace_back(i++);\n    }\n\n    int t = 0, root;\n    vector<int>\
    \ tin(n, -1), low(n), s;\n    vector<bool> vis(ssize(e), false);\n\n    auto extract\
    \ = [&](int v) {\n      newComp();\n      do {\n        int u = s.back(); s.pop_back();\n\
    \        vid[u] = size;\n        gv.emplace_back(u);\n      } while(gv.back()\
    \ != v);\n    };\n\n    auto dfs = [&](int v, auto &&self) -> void {\n      tin[v]\
    \ = low[v] = t++;\n      s.emplace_back(v);\n      for(int i : g[v]) if (!vis[i])\
    \ {\n        int x = e[i][0] ^ e[i][1] ^ v;\n        vis[i] = true;\n        if\
    \ (tin[x] != -1) {\n          low[v] = min(low[v], tin[x]);\n        } else {\n\
    \          self(x, self);\n          low[v] = min(low[v], low[x]);\n         \
    \ if (low[x] > tin[v]) extract(x);\n        }\n      }\n      if (v == root) extract(root);\n\
    \    };\n\n    for(int v = 0; v < n; v++)\n      if (tin[v] == -1)\n        dfs(root\
    \ = v, dfs);\n\n    newComp();\n  }\n\n  vector<int> vertexGroup(int id) {\n \
    \   return {gv.begin() + vb[id], gv.begin() + vb[id + 1]};\n  }\n  bool isBridge(int\
    \ id) { return vid[e[id][0]] != vid[e[id][1]]; }\n  vector<vector<int>> bridgeTree()\
    \ {\n    vector<vector<int>> g(size);\n    for(auto [u, v] : e) {\n      if ((u\
    \ = vid[u]) != (v = vid[v])) {\n        g[u].emplace_back(v);\n        g[v].emplace_back(u);\n\
    \      }\n    }\n    return g;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/ECC.cpp
  requiredBy: []
  timestamp: '2024-05-14 17:31:22+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/two_edge_connected_components.test.cpp
documentation_of: graph/ECC.cpp
layout: document
redirect_from:
- /library/graph/ECC.cpp
- /library/graph/ECC.cpp.html
title: graph/ECC.cpp
---
