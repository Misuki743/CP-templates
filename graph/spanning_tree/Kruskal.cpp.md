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
  bundledCode: "#line 1 \"graph/spanning_tree/Kruskal.cpp\"\n//#include \"ds/DSU.cpp\"\
    \n\ntemplate<class T, bool sorted = false>\npair<T, vector<int>> Kruskal(vector<array<T,\
    \ 3>> &e, int n) {\n  vector<int> id(ssize(e));\n  iota(id.begin(), id.end(),\
    \ 0);\n  if constexpr (!sorted)\n    ranges::sort(id, {}, [&e](int i) { return\
    \ e[i][2]; });\n\n  T cost = 0;\n  DSU dsu(n);\n  vector<int> res;\n  for(int\
    \ i : id) {\n    auto [u, v, w] = e[i];\n    if (dsu.merge(u, v)) {\n      cost\
    \ += w;\n      res.emplace_back(i);\n    }\n  }\n  return make_pair(cost, res);\n\
    }\n"
  code: "//#include \"ds/DSU.cpp\"\n\ntemplate<class T, bool sorted = false>\npair<T,\
    \ vector<int>> Kruskal(vector<array<T, 3>> &e, int n) {\n  vector<int> id(ssize(e));\n\
    \  iota(id.begin(), id.end(), 0);\n  if constexpr (!sorted)\n    ranges::sort(id,\
    \ {}, [&e](int i) { return e[i][2]; });\n\n  T cost = 0;\n  DSU dsu(n);\n  vector<int>\
    \ res;\n  for(int i : id) {\n    auto [u, v, w] = e[i];\n    if (dsu.merge(u,\
    \ v)) {\n      cost += w;\n      res.emplace_back(i);\n    }\n  }\n  return make_pair(cost,\
    \ res);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/spanning_tree/Kruskal.cpp
  requiredBy: []
  timestamp: '2026-01-30 20:10:19+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/spanning_tree/Kruskal.cpp
layout: document
redirect_from:
- /library/graph/spanning_tree/Kruskal.cpp
- /library/graph/spanning_tree/Kruskal.cpp.html
title: graph/spanning_tree/Kruskal.cpp
---
