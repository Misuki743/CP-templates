---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest_tree.test.cpp
    title: test/mytest_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest_tree_diameter.test.cpp
    title: test/mytest_tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/enumerate_label_tree.cpp\"\n//#include \"graph/prufer_recover.cpp\"\
    \n//#include \"enumerate/enumerate_bit.cpp\"\n//#include \"enumerate/enumerate_twelvefold.cpp\"\
    \n\ntemplate<typename F>\nrequires invocable<F, vector<vector<int>>>\nvoid enumerate_label_tree(int\
    \ n, F f) {\n  assert(n > 0);\n  if (n == 1) {\n    f(vector<vector<int>>(1));\n\
    \  } else {\n    enumerate_cartesian_power(n, n - 2, [n, f](vector<int> a) {\n\
    \      f(adjacency_list<false>(n, prufer_recover(a), 0));\n    });\n  }\n}\n"
  code: "//#include \"graph/prufer_recover.cpp\"\n//#include \"enumerate/enumerate_bit.cpp\"\
    \n//#include \"enumerate/enumerate_twelvefold.cpp\"\n\ntemplate<typename F>\n\
    requires invocable<F, vector<vector<int>>>\nvoid enumerate_label_tree(int n, F\
    \ f) {\n  assert(n > 0);\n  if (n == 1) {\n    f(vector<vector<int>>(1));\n  }\
    \ else {\n    enumerate_cartesian_power(n, n - 2, [n, f](vector<int> a) {\n  \
    \    f(adjacency_list<false>(n, prufer_recover(a), 0));\n    });\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/enumerate_label_tree.cpp
  requiredBy: []
  timestamp: '2026-01-29 19:35:43+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest_tree_diameter.test.cpp
  - test/mytest_tree.test.cpp
documentation_of: enumerate/enumerate_label_tree.cpp
layout: document
redirect_from:
- /library/enumerate/enumerate_label_tree.cpp
- /library/enumerate/enumerate_label_tree.cpp.html
title: enumerate/enumerate_label_tree.cpp
---
