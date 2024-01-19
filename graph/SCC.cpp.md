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
  bundledCode: "#line 1 \"graph/SCC.cpp\"\n/**\n * template name: SCC\n * author:\
    \ Misuki\n * last update: 2024/01/11\n * verify: Library Checker - Strongly Connected\
    \ Components\n */\n\nstruct SCC {\n  vector<int> groupId;\n  vector<vector<int>>\
    \ group, G;\n  int size;\n\n  SCC(vector<vector<int>> &g) : groupId(ssize(g)),\
    \ size(0) {\n    vector<vector<int>> gr(g.size());\n    for(int u = 0; u < ssize(g);\
    \ u++)\n      for(int v : g[u])\n        gr[v].emplace_back(u);\n\n    int t =\
    \ 0;\n    vector<bool> vis(ssize(g), false);\n    vector<int> tout(ssize(g));\n\
    \    auto dfs = [&](int v, auto self) -> void {\n      vis[v] = true;\n      for(int\
    \ x : gr[v])\n        if (!vis[x])\n          self(x, self);\n      tout[t++]\
    \ = v;\n    };\n\n    for(int v = 0; v < ssize(g); v++)\n      if (!vis[v])\n\
    \        dfs(v, dfs);\n\n    auto dfs2 = [&](int v, auto self) -> void {\n   \
    \   vis[v] = true;\n      for(int x : g[v])\n        if (!vis[x])\n          self(x,\
    \ self);\n      groupId[v] = size;\n    };\n    fill(vis.begin(), vis.end(), false);\n\
    \    for(int v = ssize(g) - 1; v >= 0; v--) {\n      if (!vis[tout[v]]) {\n  \
    \      dfs2(tout[v], dfs2);\n        size += 1;\n      }\n    }\n\n    for(int\
    \ &x : groupId)\n      x = size - x - 1;\n\n    group.resize(size);\n    for(int\
    \ v = 0; v < ssize(g); v++)\n      group[groupId[v]].emplace_back(v);\n\n    G.resize(size);\n\
    \    for(int v = 0; v < ssize(g); v++)\n      for(int x : g[v])\n        if (groupId[v]\
    \ != groupId[x])\n          G[groupId[v]].emplace_back(groupId[x]);\n  }\n};\n"
  code: "/**\n * template name: SCC\n * author: Misuki\n * last update: 2024/01/11\n\
    \ * verify: Library Checker - Strongly Connected Components\n */\n\nstruct SCC\
    \ {\n  vector<int> groupId;\n  vector<vector<int>> group, G;\n  int size;\n\n\
    \  SCC(vector<vector<int>> &g) : groupId(ssize(g)), size(0) {\n    vector<vector<int>>\
    \ gr(g.size());\n    for(int u = 0; u < ssize(g); u++)\n      for(int v : g[u])\n\
    \        gr[v].emplace_back(u);\n\n    int t = 0;\n    vector<bool> vis(ssize(g),\
    \ false);\n    vector<int> tout(ssize(g));\n    auto dfs = [&](int v, auto self)\
    \ -> void {\n      vis[v] = true;\n      for(int x : gr[v])\n        if (!vis[x])\n\
    \          self(x, self);\n      tout[t++] = v;\n    };\n\n    for(int v = 0;\
    \ v < ssize(g); v++)\n      if (!vis[v])\n        dfs(v, dfs);\n\n    auto dfs2\
    \ = [&](int v, auto self) -> void {\n      vis[v] = true;\n      for(int x : g[v])\n\
    \        if (!vis[x])\n          self(x, self);\n      groupId[v] = size;\n  \
    \  };\n    fill(vis.begin(), vis.end(), false);\n    for(int v = ssize(g) - 1;\
    \ v >= 0; v--) {\n      if (!vis[tout[v]]) {\n        dfs2(tout[v], dfs2);\n \
    \       size += 1;\n      }\n    }\n\n    for(int &x : groupId)\n      x = size\
    \ - x - 1;\n\n    group.resize(size);\n    for(int v = 0; v < ssize(g); v++)\n\
    \      group[groupId[v]].emplace_back(v);\n\n    G.resize(size);\n    for(int\
    \ v = 0; v < ssize(g); v++)\n      for(int x : g[v])\n        if (groupId[v] !=\
    \ groupId[x])\n          G[groupId[v]].emplace_back(groupId[x]);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/SCC.cpp
  requiredBy: []
  timestamp: '2024-01-20 02:52:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/SCC.cpp
layout: document
redirect_from:
- /library/graph/SCC.cpp
- /library/graph/SCC.cpp.html
title: graph/SCC.cpp
---
