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
  bundledCode: "#line 1 \"graph/minimumVertexCover.cpp\"\n//#include<graph/hopcroftKarp.cpp>\n\
    \narray<vector<int>, 2> MVC(vector<vi> &g, vi& btoa) {\n  int n1 = sz(g), n2 =\
    \ sz(btoa);\n  vector<bool> ml(n1, false);\n  for(int i = 0; i < n2; i++)\n  \
    \  if (btoa[i] != -1)\n      ml[btoa[i]] = true;\n\n  vector<bool> vis(n1 + n2,\
    \ false);\n  vector<vector<int>> g2(n1 + n2);\n  for(int u = 0; u < n1; u++) {\n\
    \    for(int v : g[u]) {\n      if (btoa[v] == u)\n        g2[v + n1].emplace_back(u);\n\
    \      else\n        g2[u].emplace_back(v + n1);\n    }\n  }\n  auto dfs = [&](int\
    \ v, auto self) -> void {\n    vis[v] = true;\n    for(int x : g2[v])\n      if\
    \ (!vis[x])\n        self(x, self);\n  };\n  for(int i = 0; i < n1; i++)\n   \
    \ if (!ml[i] and !vis[i])\n      dfs(i, dfs);\n\n  array<vector<int>, 2> vc;\n\
    \  for(int i = 0; i < n1; i++)\n    if (!vis[i])\n      vc[0].push_back(i);\n\
    \  for(int i = 0; i < n2; i++)\n    if (vis[i + n1])\n      vc[1].push_back(i);\n\
    \n  return vc;\n}\n"
  code: "//#include<graph/hopcroftKarp.cpp>\n\narray<vector<int>, 2> MVC(vector<vi>\
    \ &g, vi& btoa) {\n  int n1 = sz(g), n2 = sz(btoa);\n  vector<bool> ml(n1, false);\n\
    \  for(int i = 0; i < n2; i++)\n    if (btoa[i] != -1)\n      ml[btoa[i]] = true;\n\
    \n  vector<bool> vis(n1 + n2, false);\n  vector<vector<int>> g2(n1 + n2);\n  for(int\
    \ u = 0; u < n1; u++) {\n    for(int v : g[u]) {\n      if (btoa[v] == u)\n  \
    \      g2[v + n1].emplace_back(u);\n      else\n        g2[u].emplace_back(v +\
    \ n1);\n    }\n  }\n  auto dfs = [&](int v, auto self) -> void {\n    vis[v] =\
    \ true;\n    for(int x : g2[v])\n      if (!vis[x])\n        self(x, self);\n\
    \  };\n  for(int i = 0; i < n1; i++)\n    if (!ml[i] and !vis[i])\n      dfs(i,\
    \ dfs);\n\n  array<vector<int>, 2> vc;\n  for(int i = 0; i < n1; i++)\n    if\
    \ (!vis[i])\n      vc[0].push_back(i);\n  for(int i = 0; i < n2; i++)\n    if\
    \ (vis[i + n1])\n      vc[1].push_back(i);\n\n  return vc;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/minimumVertexCover.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/minimumVertexCover.cpp
layout: document
redirect_from:
- /library/graph/minimumVertexCover.cpp
- /library/graph/minimumVertexCover.cpp.html
title: graph/minimumVertexCover.cpp
---