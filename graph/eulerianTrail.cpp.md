---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/eulerian_trail_directed.test.cpp
    title: test/eulerian_trail_directed.test.cpp
  - icon: ':x:'
    path: test/eulerian_trail_undirected.test.cpp
    title: test/eulerian_trail_undirected.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/eulerianTrail.cpp\"\ntemplate<bool directed = false,\
    \ bool circuit = false>\narray<vector<int>, 2> eulerianTrail(int n, vector<array<int,\
    \ 2>> &e) {\n  vector<int> indeg(n), outdeg(n);\n  vector<vector<int>> g(n);\n\
    \  for(int i = 0; auto [u, v] : e) {\n    outdeg[u] += 1, indeg[v] += 1;\n   \
    \ if constexpr (!directed)\n      g[v].emplace_back(i);\n    g[u].emplace_back(i++);\n\
    \  }\n\n  int s = -1;\n  if constexpr (directed) {\n    for(int v = 0; v < n;\
    \ v++) {\n      if (abs(indeg[v] - outdeg[v]) >= 2) return {};\n      if (outdeg[v]\
    \ <= indeg[v]) continue;\n      if (s != -1) return {};\n      s = v;\n    }\n\
    \  } else {\n    for(int v = 0, t = -1; v < n; v++) {\n      if ((indeg[v] + outdeg[v])\
    \ % 2 == 0) continue;\n      if (s != -1 and t != -1) return {};\n      if (s\
    \ == -1) s = v;\n      else t = v;\n    }\n  }\n\n  if constexpr (circuit)\n \
    \   if (s != -1) \n      return {};\n\n  if (s == -1)\n    for(int v = 0; v <\
    \ n; v++)\n      if (indeg[v] | outdeg[v])\n        s = v;\n\n  if (s == -1)\n\
    \    s = 0;\n\n  vector<int> vid, eid, ptr(n);\n  vector<bool> visE(ssize(e),\
    \ false);\n  auto dfs = [&](int v, auto self) -> void {\n    for(int &i = ptr[v];\
    \ i < ssize(g[v]); i++) {\n      if (visE[g[v][i]]) continue;\n      int tmp =\
    \ g[v][i];\n      int x = v ^ e[tmp][0] ^ e[tmp][1];\n      visE[tmp] = true;\n\
    \      self(x, self);\n      vid.emplace_back(x);\n      eid.emplace_back(tmp);\n\
    \    }\n  };\n\n  dfs(s, dfs);\n  vid.emplace_back(s);\n\n  R::reverse(vid);\n\
    \  R::reverse(eid);\n\n  if (ssize(eid) != ssize(e))\n    return {};\n  else\n\
    \    return {vid, eid};\n}\n"
  code: "template<bool directed = false, bool circuit = false>\narray<vector<int>,\
    \ 2> eulerianTrail(int n, vector<array<int, 2>> &e) {\n  vector<int> indeg(n),\
    \ outdeg(n);\n  vector<vector<int>> g(n);\n  for(int i = 0; auto [u, v] : e) {\n\
    \    outdeg[u] += 1, indeg[v] += 1;\n    if constexpr (!directed)\n      g[v].emplace_back(i);\n\
    \    g[u].emplace_back(i++);\n  }\n\n  int s = -1;\n  if constexpr (directed)\
    \ {\n    for(int v = 0; v < n; v++) {\n      if (abs(indeg[v] - outdeg[v]) >=\
    \ 2) return {};\n      if (outdeg[v] <= indeg[v]) continue;\n      if (s != -1)\
    \ return {};\n      s = v;\n    }\n  } else {\n    for(int v = 0, t = -1; v <\
    \ n; v++) {\n      if ((indeg[v] + outdeg[v]) % 2 == 0) continue;\n      if (s\
    \ != -1 and t != -1) return {};\n      if (s == -1) s = v;\n      else t = v;\n\
    \    }\n  }\n\n  if constexpr (circuit)\n    if (s != -1) \n      return {};\n\
    \n  if (s == -1)\n    for(int v = 0; v < n; v++)\n      if (indeg[v] | outdeg[v])\n\
    \        s = v;\n\n  if (s == -1)\n    s = 0;\n\n  vector<int> vid, eid, ptr(n);\n\
    \  vector<bool> visE(ssize(e), false);\n  auto dfs = [&](int v, auto self) ->\
    \ void {\n    for(int &i = ptr[v]; i < ssize(g[v]); i++) {\n      if (visE[g[v][i]])\
    \ continue;\n      int tmp = g[v][i];\n      int x = v ^ e[tmp][0] ^ e[tmp][1];\n\
    \      visE[tmp] = true;\n      self(x, self);\n      vid.emplace_back(x);\n \
    \     eid.emplace_back(tmp);\n    }\n  };\n\n  dfs(s, dfs);\n  vid.emplace_back(s);\n\
    \n  R::reverse(vid);\n  R::reverse(eid);\n\n  if (ssize(eid) != ssize(e))\n  \
    \  return {};\n  else\n    return {vid, eid};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/eulerianTrail.cpp
  requiredBy: []
  timestamp: '2024-01-28 22:59:51+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/eulerian_trail_directed.test.cpp
  - test/eulerian_trail_undirected.test.cpp
documentation_of: graph/eulerianTrail.cpp
layout: document
redirect_from:
- /library/graph/eulerianTrail.cpp
- /library/graph/eulerianTrail.cpp.html
title: graph/eulerianTrail.cpp
---
