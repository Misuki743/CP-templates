---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest_tree_diameter.test.cpp
    title: test/mytest_tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/tree_diameter.cpp\"\n//#include \"graph/tree.cpp\"\n\
    \nauto tree_diameter(vc<pii> e) {\n  auto d0 = tree(e).dep;\n  int u = max_element(d0.begin(),\
    \ d0.end()) - d0.begin();\n  tree t(e, u);\n  int v = max_element(t.dep.begin(),\
    \ t.dep.end()) - t.dep.begin();\n  vi path = {v};\n  for(int i = t.dep[v]; i >\
    \ 0; i--)\n    path.emplace_back(t.p[path.back()]);\n  return pair((int)(ssize(path)\
    \ - 1), path);\n}\n"
  code: "//#include \"graph/tree.cpp\"\n\nauto tree_diameter(vc<pii> e) {\n  auto\
    \ d0 = tree(e).dep;\n  int u = max_element(d0.begin(), d0.end()) - d0.begin();\n\
    \  tree t(e, u);\n  int v = max_element(t.dep.begin(), t.dep.end()) - t.dep.begin();\n\
    \  vi path = {v};\n  for(int i = t.dep[v]; i > 0; i--)\n    path.emplace_back(t.p[path.back()]);\n\
    \  return pair((int)(ssize(path) - 1), path);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/tree_diameter.cpp
  requiredBy: []
  timestamp: '2026-02-02 01:08:31+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest_tree_diameter.test.cpp
documentation_of: tree/tree_diameter.cpp
layout: document
redirect_from:
- /library/tree/tree_diameter.cpp
- /library/tree/tree_diameter.cpp.html
title: tree/tree_diameter.cpp
---
