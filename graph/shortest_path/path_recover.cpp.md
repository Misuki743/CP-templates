---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/shortest_path_dense.test.cpp
    title: test/shortest_path_dense.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/shortest_path_sparse.test.cpp
    title: test/shortest_path_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/shortest_path/path_recover.cpp\"\nvi recover(vi &pre,\
    \ int t) {\n  if (pre[t] == -1) return {};\n  vi path = {t};\n  while(pre[path.back()]\
    \ != path.back())\n    path.emplace_back(pre[path.back()]);\n  ranges::reverse(path);\n\
    \  return path;\n}\n"
  code: "vi recover(vi &pre, int t) {\n  if (pre[t] == -1) return {};\n  vi path =\
    \ {t};\n  while(pre[path.back()] != path.back())\n    path.emplace_back(pre[path.back()]);\n\
    \  ranges::reverse(path);\n  return path;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path/path_recover.cpp
  requiredBy: []
  timestamp: '2026-01-31 00:52:12+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/shortest_path_sparse.test.cpp
  - test/shortest_path_dense.test.cpp
documentation_of: graph/shortest_path/path_recover.cpp
layout: document
redirect_from:
- /library/graph/shortest_path/path_recover.cpp
- /library/graph/shortest_path/path_recover.cpp.html
title: graph/shortest_path/path_recover.cpp
---
