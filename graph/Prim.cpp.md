---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/minimum_spanning_tree.test.cpp
    title: test/minimum_spanning_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/Prim.cpp\"\ntemplate<class T>\npair<T, vector<int>>\
    \ Prim(vector<array<T, 3>> &e, int n) {\n  vector id(n, vector<int>(n, -1));\n\
    \  for(int i = 0; auto [u, v, w] : e) {\n    if (id[u][v] == -1 or w < e[id[u][v]][2])\n\
    \      id[u][v] = id[v][u] = i;\n    i++;\n  }\n\n  T cost = 0;\n  vector<bool>\
    \ inT(n, false);\n  vector<int> eid, mn = id[0];\n  inT[0] = true;\n  for(int\
    \ i = 0; i < n - 1; i++) {\n    int v = -1;\n    for(int x = 0; x < n; x++)\n\
    \      if (!inT[x] and mn[x] != -1 and (v == -1 or e[mn[x]][2] < e[mn[v]][2]))\n\
    \        v = x;\n    if (v == -1) break;\n    inT[v] = true, cost += e[mn[v]][2];\n\
    \    eid.emplace_back(mn[v]);\n    for(int x = 0; x < n; x++)\n      if (id[v][x]\
    \ != -1 and (mn[x] == -1 or e[id[v][x]][2] < e[mn[x]][2]))\n        mn[x] = id[v][x];\n\
    \  }\n\n  if (ssize(eid) == n - 1)\n    return make_pair(cost, eid);\n  else\n\
    \    return make_pair(numeric_limits<T>::max(), vector<int>());\n}\n"
  code: "template<class T>\npair<T, vector<int>> Prim(vector<array<T, 3>> &e, int\
    \ n) {\n  vector id(n, vector<int>(n, -1));\n  for(int i = 0; auto [u, v, w] :\
    \ e) {\n    if (id[u][v] == -1 or w < e[id[u][v]][2])\n      id[u][v] = id[v][u]\
    \ = i;\n    i++;\n  }\n\n  T cost = 0;\n  vector<bool> inT(n, false);\n  vector<int>\
    \ eid, mn = id[0];\n  inT[0] = true;\n  for(int i = 0; i < n - 1; i++) {\n   \
    \ int v = -1;\n    for(int x = 0; x < n; x++)\n      if (!inT[x] and mn[x] !=\
    \ -1 and (v == -1 or e[mn[x]][2] < e[mn[v]][2]))\n        v = x;\n    if (v ==\
    \ -1) break;\n    inT[v] = true, cost += e[mn[v]][2];\n    eid.emplace_back(mn[v]);\n\
    \    for(int x = 0; x < n; x++)\n      if (id[v][x] != -1 and (mn[x] == -1 or\
    \ e[id[v][x]][2] < e[mn[x]][2]))\n        mn[x] = id[v][x];\n  }\n\n  if (ssize(eid)\
    \ == n - 1)\n    return make_pair(cost, eid);\n  else\n    return make_pair(numeric_limits<T>::max(),\
    \ vector<int>());\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/Prim.cpp
  requiredBy: []
  timestamp: '2024-03-16 14:24:11+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/minimum_spanning_tree.test.cpp
documentation_of: graph/Prim.cpp
layout: document
redirect_from:
- /library/graph/Prim.cpp
- /library/graph/Prim.cpp.html
title: graph/Prim.cpp
---
