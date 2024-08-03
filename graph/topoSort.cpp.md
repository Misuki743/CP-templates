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
  bundledCode: "#line 1 \"graph/topoSort.cpp\"\nvector<int> topoSort(vector<vector<int>>\
    \ g) {\n  int n = ssize(g);\n  vector<int> deg(n);\n  for(auto &e : g)\n    for(int\
    \ x : e)\n      deg[x]++;\n  vector<int> topo;\n  topo.reserve(n);\n  for(int\
    \ i = 0; i < n; i++)\n    if (deg[i] == 0)\n      topo.emplace_back(i);\n  for(int\
    \ i = 0; i < ssize(topo); i++)\n    for(int x : g[topo[i]])\n      if (--deg[x]\
    \ == 0)\n        topo.emplace_back(x);\n  return ssize(topo) != n ? vector<int>()\
    \ : topo;\n}\n"
  code: "vector<int> topoSort(vector<vector<int>> g) {\n  int n = ssize(g);\n  vector<int>\
    \ deg(n);\n  for(auto &e : g)\n    for(int x : e)\n      deg[x]++;\n  vector<int>\
    \ topo;\n  topo.reserve(n);\n  for(int i = 0; i < n; i++)\n    if (deg[i] == 0)\n\
    \      topo.emplace_back(i);\n  for(int i = 0; i < ssize(topo); i++)\n    for(int\
    \ x : g[topo[i]])\n      if (--deg[x] == 0)\n        topo.emplace_back(x);\n \
    \ return ssize(topo) != n ? vector<int>() : topo;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/topoSort.cpp
  requiredBy: []
  timestamp: '2024-08-04 01:36:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/topoSort.cpp
layout: document
redirect_from:
- /library/graph/topoSort.cpp
- /library/graph/topoSort.cpp.html
title: graph/topoSort.cpp
---
