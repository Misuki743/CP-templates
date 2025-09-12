---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/biconnected_components.test.cpp
    title: test/biconnected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/BCC.cpp\"\nstruct BCC {\n  vector<int> f, vb, eb,\
    \ gv, ge, eid, vid;\n  int size = -1;\n\n  BCC(vector<array<int, 2>> &e, int n)\n\
    \  : f(n), eid(ssize(e)), vid(n, -1) {\n\n    auto newComp = [&]() {\n      vb.emplace_back(ssize(gv));\n\
    \      eb.emplace_back(ssize(ge));\n      size++;\n    };\n\n    vector<vector<int>>\
    \ g(n);\n    for(int i = 0; auto [u, v] : e) {\n      g[u].emplace_back(i);\n\
    \      g[v].emplace_back(i++);\n    }\n\n    int t = 0;\n    vector<int> tin(n,\
    \ -1), low(n), cnt(n), s;\n    vector<bool> vis(ssize(e), false);\n    auto dfs\
    \ = [&](int v, auto &&self) -> void {\n      tin[v] = low[v] = t++;\n      for(int\
    \ i : g[v]) if (!vis[i]) {\n        int x = e[i][0] ^ e[i][1] ^ v;\n        vis[i]\
    \ = true, s.emplace_back(i);\n        if (tin[x] != -1) {\n          low[v] =\
    \ min(low[v], tin[x]);\n        } else {\n          self(x, self);\n         \
    \ low[v] = min(low[v], low[x]);\n          if (low[x] >= tin[v]) {\n         \
    \   newComp();\n            do {\n              int j = s.back(); s.pop_back();\n\
    \              for(int u : e[j])\n                if (++cnt[u] == 1)\n       \
    \           gv.emplace_back(u);\n              eid[j] = size;\n              ge.emplace_back(j);\n\
    \            } while(ge.back() != i);\n            for(int u : gv | views::drop(vb.back()))\n\
    \              cnt[u] = 0, f[u]++, vid[u] = size;\n          }\n        }\n  \
    \    }\n      if (g[v].empty()) newComp(), gv.emplace_back(v), vid[v] = size;\n\
    \    };\n\n    for(int v = 0; v < n; v++)\n      if (tin[v] == -1)\n        dfs(v,\
    \ dfs);\n    newComp();\n  }\n\n  vector<int> vertexGroup(int id) {\n    return\
    \ {gv.begin() + vb[id], gv.begin() + vb[id + 1]};\n  }\n  vector<int> edgeGroup(int\
    \ id) {\n    return {ge.begin() + eb[id], ge.begin() + eb[id + 1]};\n  }\n  bool\
    \ isCutVertex(int v) { return f[v] > 1; }\n  pair<vector<vector<int>>, vector<int>>\
    \ blockCutTree() {\n    int n = ssize(f);\n    vector<vector<int>> g(n + size);\n\
    \    vector<int> mp = vid;\n    for(int &x : mp) x += n;\n    for(int i = 0; i\
    \ < size; i++)\n      for(int v : vertexGroup(i))\n        if (isCutVertex(v))\
    \ {\n          g[i + n].emplace_back(v);\n          g[v].emplace_back(i + n);\n\
    \          mp[v] = v;\n        }\n    return make_pair(g, mp);\n  }\n};\n"
  code: "struct BCC {\n  vector<int> f, vb, eb, gv, ge, eid, vid;\n  int size = -1;\n\
    \n  BCC(vector<array<int, 2>> &e, int n)\n  : f(n), eid(ssize(e)), vid(n, -1)\
    \ {\n\n    auto newComp = [&]() {\n      vb.emplace_back(ssize(gv));\n      eb.emplace_back(ssize(ge));\n\
    \      size++;\n    };\n\n    vector<vector<int>> g(n);\n    for(int i = 0; auto\
    \ [u, v] : e) {\n      g[u].emplace_back(i);\n      g[v].emplace_back(i++);\n\
    \    }\n\n    int t = 0;\n    vector<int> tin(n, -1), low(n), cnt(n), s;\n   \
    \ vector<bool> vis(ssize(e), false);\n    auto dfs = [&](int v, auto &&self) ->\
    \ void {\n      tin[v] = low[v] = t++;\n      for(int i : g[v]) if (!vis[i]) {\n\
    \        int x = e[i][0] ^ e[i][1] ^ v;\n        vis[i] = true, s.emplace_back(i);\n\
    \        if (tin[x] != -1) {\n          low[v] = min(low[v], tin[x]);\n      \
    \  } else {\n          self(x, self);\n          low[v] = min(low[v], low[x]);\n\
    \          if (low[x] >= tin[v]) {\n            newComp();\n            do {\n\
    \              int j = s.back(); s.pop_back();\n              for(int u : e[j])\n\
    \                if (++cnt[u] == 1)\n                  gv.emplace_back(u);\n \
    \             eid[j] = size;\n              ge.emplace_back(j);\n            }\
    \ while(ge.back() != i);\n            for(int u : gv | views::drop(vb.back()))\n\
    \              cnt[u] = 0, f[u]++, vid[u] = size;\n          }\n        }\n  \
    \    }\n      if (g[v].empty()) newComp(), gv.emplace_back(v), vid[v] = size;\n\
    \    };\n\n    for(int v = 0; v < n; v++)\n      if (tin[v] == -1)\n        dfs(v,\
    \ dfs);\n    newComp();\n  }\n\n  vector<int> vertexGroup(int id) {\n    return\
    \ {gv.begin() + vb[id], gv.begin() + vb[id + 1]};\n  }\n  vector<int> edgeGroup(int\
    \ id) {\n    return {ge.begin() + eb[id], ge.begin() + eb[id + 1]};\n  }\n  bool\
    \ isCutVertex(int v) { return f[v] > 1; }\n  pair<vector<vector<int>>, vector<int>>\
    \ blockCutTree() {\n    int n = ssize(f);\n    vector<vector<int>> g(n + size);\n\
    \    vector<int> mp = vid;\n    for(int &x : mp) x += n;\n    for(int i = 0; i\
    \ < size; i++)\n      for(int v : vertexGroup(i))\n        if (isCutVertex(v))\
    \ {\n          g[i + n].emplace_back(v);\n          g[v].emplace_back(i + n);\n\
    \          mp[v] = v;\n        }\n    return make_pair(g, mp);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/BCC.cpp
  requiredBy: []
  timestamp: '2025-09-12 22:22:52+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/biconnected_components.test.cpp
documentation_of: graph/BCC.cpp
layout: document
redirect_from:
- /library/graph/BCC.cpp
- /library/graph/BCC.cpp.html
title: graph/BCC.cpp
---
