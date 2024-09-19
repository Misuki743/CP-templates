---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cycle_detection_directed.test.cpp
    title: test/cycle_detection_directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/cycle_detection_undirected.test.cpp
    title: test/cycle_detection_undirected.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/cycleDetection.cpp\"\ntemplate<bool directed = false>\n\
    array<vector<int>, 2> cycleDetection(vector<array<int, 2>> &e) {\n  int n = 0;\n\
    \  for(auto [u, v] : e) n = max({n, u + 1, v + 1});\n  vector<vector<int>> g(n);\n\
    \  for(int i = 0; auto [u, v] : e) {\n    if (u == v) return {{{u}, {i}}};\n \
    \   if constexpr (!directed)\n      g[v].emplace_back(i);\n    g[u].emplace_back(i++);\n\
    \  }\n\n  vector<bool> vis(n, false), inStack(n, false);\n  vector<int> vs, es;\n\
    \  auto dfs = [&](int v, int p, auto self) -> bool {\n    vis[v] = inStack[v]\
    \ = true;\n    vs.emplace_back(v);\n    for(int i : g[v]) {\n      if (i == p)\
    \ continue;\n      int x = v ^ e[i][0] ^ e[i][1];\n      es.emplace_back(i);\n\
    \      if (inStack[x]) {\n        vs = vector<int>(ranges::find(vs, x), vs.end());\n\
    \        es = vector<int>(es.end() - ssize(vs), es.end());\n        return true;\n\
    \      } else if (!vis[x] and self(x, i, self)) {\n        return true;\n    \
    \  }\n      es.pop_back();\n    }\n    vs.pop_back();\n    inStack[v] = false;\n\
    \    return false;\n  };\n\n  for(int v = 0; v < n; v++)\n    if (!vis[v] and\
    \ dfs(v, -1, dfs))\n      return {vs, es};\n\n  return {};\n}\n"
  code: "template<bool directed = false>\narray<vector<int>, 2> cycleDetection(vector<array<int,\
    \ 2>> &e) {\n  int n = 0;\n  for(auto [u, v] : e) n = max({n, u + 1, v + 1});\n\
    \  vector<vector<int>> g(n);\n  for(int i = 0; auto [u, v] : e) {\n    if (u ==\
    \ v) return {{{u}, {i}}};\n    if constexpr (!directed)\n      g[v].emplace_back(i);\n\
    \    g[u].emplace_back(i++);\n  }\n\n  vector<bool> vis(n, false), inStack(n,\
    \ false);\n  vector<int> vs, es;\n  auto dfs = [&](int v, int p, auto self) ->\
    \ bool {\n    vis[v] = inStack[v] = true;\n    vs.emplace_back(v);\n    for(int\
    \ i : g[v]) {\n      if (i == p) continue;\n      int x = v ^ e[i][0] ^ e[i][1];\n\
    \      es.emplace_back(i);\n      if (inStack[x]) {\n        vs = vector<int>(ranges::find(vs,\
    \ x), vs.end());\n        es = vector<int>(es.end() - ssize(vs), es.end());\n\
    \        return true;\n      } else if (!vis[x] and self(x, i, self)) {\n    \
    \    return true;\n      }\n      es.pop_back();\n    }\n    vs.pop_back();\n\
    \    inStack[v] = false;\n    return false;\n  };\n\n  for(int v = 0; v < n; v++)\n\
    \    if (!vis[v] and dfs(v, -1, dfs))\n      return {vs, es};\n\n  return {};\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/cycleDetection.cpp
  requiredBy: []
  timestamp: '2024-04-05 18:02:52+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cycle_detection_directed.test.cpp
  - test/cycle_detection_undirected.test.cpp
documentation_of: graph/cycleDetection.cpp
layout: document
redirect_from:
- /library/graph/cycleDetection.cpp
- /library/graph/cycleDetection.cpp.html
title: graph/cycleDetection.cpp
---
