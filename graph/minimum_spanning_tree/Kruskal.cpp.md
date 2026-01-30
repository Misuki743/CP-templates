---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/minimum_spanning_tree_Kruskal.test.cpp
    title: test/minimum_spanning_tree_Kruskal.test.cpp
  - icon: ':x:'
    path: test/minimum_spanning_tree_Prim.test.cpp
    title: test/minimum_spanning_tree_Prim.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/minimum_spanning_tree/Kruskal.cpp\"\n//#include \"\
    ds/DSU/DSU.cpp\"\n\ntemplate<bool sorted, integral T>\nauto Kruskal(int n, vector<tuple<int,\
    \ int, T>> &e) {\n  vi ord;\n  if constexpr (sorted) {\n    ord.resize(n);\n \
    \   iota(ord.begin(), ord.end(), 0ll);\n  } else {\n    ord = argSort(e, [](tuple<int,\
    \ int, T> &t) { return get<2>(t); });\n  }\n\n  T cost = 0;\n  vi eid;\n  DSU\
    \ dsu(n);\n  for(int i : ord) {\n    auto [u, v, w] = e[i];\n    if (dsu.merge(u,\
    \ v))\n      cost += w, eid.emplace_back(i);\n  }\n\n  return pair(cost, eid);\n\
    }\n"
  code: "//#include \"ds/DSU/DSU.cpp\"\n\ntemplate<bool sorted, integral T>\nauto\
    \ Kruskal(int n, vector<tuple<int, int, T>> &e) {\n  vi ord;\n  if constexpr (sorted)\
    \ {\n    ord.resize(n);\n    iota(ord.begin(), ord.end(), 0ll);\n  } else {\n\
    \    ord = argSort(e, [](tuple<int, int, T> &t) { return get<2>(t); });\n  }\n\
    \n  T cost = 0;\n  vi eid;\n  DSU dsu(n);\n  for(int i : ord) {\n    auto [u,\
    \ v, w] = e[i];\n    if (dsu.merge(u, v))\n      cost += w, eid.emplace_back(i);\n\
    \  }\n\n  return pair(cost, eid);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/minimum_spanning_tree/Kruskal.cpp
  requiredBy: []
  timestamp: '2026-01-31 03:10:37+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/minimum_spanning_tree_Prim.test.cpp
  - test/minimum_spanning_tree_Kruskal.test.cpp
documentation_of: graph/minimum_spanning_tree/Kruskal.cpp
layout: document
redirect_from:
- /library/graph/minimum_spanning_tree/Kruskal.cpp
- /library/graph/minimum_spanning_tree/Kruskal.cpp.html
title: graph/minimum_spanning_tree/Kruskal.cpp
---
