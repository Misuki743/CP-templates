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
  bundledCode: "#line 1 \"graph/Kruskal.cpp\"\n//#include \"ds/DSU.cpp\"\n\ntemplate<class\
    \ T, bool sorted = false>\npair<T, vector<int>> Kruskal(vector<array<T, 3>> &e,\
    \ int n) {\n  vector<int> id(ssize(e));\n  iota(id.begin(), id.end(), 0);\n  if\
    \ constexpr (!sorted)\n    ranges::sort(id, {}, [&e](int i) { return e[i][2];\
    \ });\n\n  T cost = 0;\n  DSU dsu(n);\n  vector<int> res;\n  for(int i : id) {\n\
    \    auto [u, v, w] = e[i];\n    if (dsu.merge(u, v)) {\n      cost += w;\n  \
    \    res.emplace_back(i);\n    }\n  }\n  return make_pair(cost, res);\n}\n"
  code: "//#include \"ds/DSU.cpp\"\n\ntemplate<class T, bool sorted = false>\npair<T,\
    \ vector<int>> Kruskal(vector<array<T, 3>> &e, int n) {\n  vector<int> id(ssize(e));\n\
    \  iota(id.begin(), id.end(), 0);\n  if constexpr (!sorted)\n    ranges::sort(id,\
    \ {}, [&e](int i) { return e[i][2]; });\n\n  T cost = 0;\n  DSU dsu(n);\n  vector<int>\
    \ res;\n  for(int i : id) {\n    auto [u, v, w] = e[i];\n    if (dsu.merge(u,\
    \ v)) {\n      cost += w;\n      res.emplace_back(i);\n    }\n  }\n  return make_pair(cost,\
    \ res);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/Kruskal.cpp
  requiredBy: []
  timestamp: '2024-06-29 17:34:40+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/minimum_spanning_tree.test.cpp
documentation_of: graph/Kruskal.cpp
layout: document
redirect_from:
- /library/graph/Kruskal.cpp
- /library/graph/Kruskal.cpp.html
title: graph/Kruskal.cpp
---
