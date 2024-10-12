---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/counting_eulerian_circuits.test.cpp
    title: test/counting_eulerian_circuits.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/counting_spanning_tree_directed.test.cpp
    title: test/counting_spanning_tree_directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/counting_spanning_tree_undirected.test.cpp
    title: test/counting_spanning_tree_undirected.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"combi/countSpanningForest.cpp\"\n//#include \"modint/MontgomeryModInt.cpp\"\
    \n//#include \"linalg/matrixMint.cpp\"\n\ntemplate<class Mint, bool directed =\
    \ false>\nMint countSpanningForest(vector<tuple<int, int, Mint>> e, int n, vector<int>\
    \ r = vector(1, 0)) {\n  vector<int> id(n, 1);\n  for(int x : r) id[x] = 0;\n\
    \  id[0] -= 1;\n  pSum(id);\n  for(int x : r) id[x] = -1;\n\n  matrix<Mint> M(n\
    \ - ssize(r));\n  for(auto [u, v, w] : e) {\n    u = id[u], v = id[v];\n    if\
    \ (u != -1 and v != -1) {\n      M[u][v] -= w;\n      if constexpr (!directed)\
    \ M[v][u] -= w;\n    }\n    if constexpr (!directed) if (u != -1) M[u][u] += w;\n\
    \    if (v != -1) M[v][v] += w;\n  }\n  return M.det();\n}\n"
  code: "//#include \"modint/MontgomeryModInt.cpp\"\n//#include \"linalg/matrixMint.cpp\"\
    \n\ntemplate<class Mint, bool directed = false>\nMint countSpanningForest(vector<tuple<int,\
    \ int, Mint>> e, int n, vector<int> r = vector(1, 0)) {\n  vector<int> id(n, 1);\n\
    \  for(int x : r) id[x] = 0;\n  id[0] -= 1;\n  pSum(id);\n  for(int x : r) id[x]\
    \ = -1;\n\n  matrix<Mint> M(n - ssize(r));\n  for(auto [u, v, w] : e) {\n    u\
    \ = id[u], v = id[v];\n    if (u != -1 and v != -1) {\n      M[u][v] -= w;\n \
    \     if constexpr (!directed) M[v][u] -= w;\n    }\n    if constexpr (!directed)\
    \ if (u != -1) M[u][u] += w;\n    if (v != -1) M[v][v] += w;\n  }\n  return M.det();\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/countSpanningForest.cpp
  requiredBy: []
  timestamp: '2024-06-29 17:34:40+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/counting_eulerian_circuits.test.cpp
  - test/counting_spanning_tree_directed.test.cpp
  - test/counting_spanning_tree_undirected.test.cpp
documentation_of: combi/countSpanningForest.cpp
layout: document
redirect_from:
- /library/combi/countSpanningForest.cpp
- /library/combi/countSpanningForest.cpp.html
title: combi/countSpanningForest.cpp
---
