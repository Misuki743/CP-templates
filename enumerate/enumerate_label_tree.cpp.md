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
  bundledCode: "#line 1 \"enumerate/enumerate_label_tree.cpp\"\n//#include \"graph/prufer_recover.cpp\"\
    \n\ntemplate<typename F>\nrequires invocable<F, vector<vector<int>>>\nvoid enumerate_label_tree(int\
    \ n, F f) {\n  assert(n > 0);\n  if (n == 1) {\n    f(vector<vector<int>>(1));\n\
    \  } else {\n    enumerate_cartesian_product(vector<int>(n - 2, n), [n, f](vector<int>\
    \ a) {\n      f(adjacency_list<false>(n, prufer_recover(a), 0));\n    });\n  }\n\
    }\n"
  code: "//#include \"graph/prufer_recover.cpp\"\n\ntemplate<typename F>\nrequires\
    \ invocable<F, vector<vector<int>>>\nvoid enumerate_label_tree(int n, F f) {\n\
    \  assert(n > 0);\n  if (n == 1) {\n    f(vector<vector<int>>(1));\n  } else {\n\
    \    enumerate_cartesian_product(vector<int>(n - 2, n), [n, f](vector<int> a)\
    \ {\n      f(adjacency_list<false>(n, prufer_recover(a), 0));\n    });\n  }\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/enumerate_label_tree.cpp
  requiredBy: []
  timestamp: '2026-01-29 02:59:39+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: enumerate/enumerate_label_tree.cpp
layout: document
redirect_from:
- /library/enumerate/enumerate_label_tree.cpp
- /library/enumerate/enumerate_label_tree.cpp.html
title: enumerate/enumerate_label_tree.cpp
---
