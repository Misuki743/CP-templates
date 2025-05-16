---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: test/point_set_tree_path_composite_sum_fixed_root.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/dynamicTreeDP.cpp\"\n//#include \"ds/staticTopTree.cpp\"\
    \ntemplate<class M, M(*rake)(const M&, const M&), M(*compress)(const M&, const\
    \ M&)>\nstruct dynamic_tree_dp {\n  vector<M> dp;\n  static_top_tree stt;\n\n\
    \  void pull(int v) {\n    if (stt.rake[v]) dp[v] = rake(dp[stt.lc[v]], dp[stt.rc[v]]);\n\
    \    else dp[v] = compress(dp[stt.lc[v]], dp[stt.rc[v]]);\n  }\n\n  dynamic_tree_dp(vector<vector<int>>\
    \ &g, vector<M> &init)\n    : dp(2 * ssize(g) - 1), stt(g) {\n    for(int i =\
    \ 0; i < ssize(g); i++)\n      dp[i] = init[i];\n    for(int i = ssize(g); i <\
    \ 2 * ssize(g) - 1; i++)\n      pull(i);\n  }\n\n  void set(int v, M x) {\n  \
    \  dp[v] = x;\n    while((v = stt.pa[v]) != -1) pull(v);\n  }\n\n  M query() {\
    \ return dp.back(); }\n};\n"
  code: "//#include \"ds/staticTopTree.cpp\"\ntemplate<class M, M(*rake)(const M&,\
    \ const M&), M(*compress)(const M&, const M&)>\nstruct dynamic_tree_dp {\n  vector<M>\
    \ dp;\n  static_top_tree stt;\n\n  void pull(int v) {\n    if (stt.rake[v]) dp[v]\
    \ = rake(dp[stt.lc[v]], dp[stt.rc[v]]);\n    else dp[v] = compress(dp[stt.lc[v]],\
    \ dp[stt.rc[v]]);\n  }\n\n  dynamic_tree_dp(vector<vector<int>> &g, vector<M>\
    \ &init)\n    : dp(2 * ssize(g) - 1), stt(g) {\n    for(int i = 0; i < ssize(g);\
    \ i++)\n      dp[i] = init[i];\n    for(int i = ssize(g); i < 2 * ssize(g) - 1;\
    \ i++)\n      pull(i);\n  }\n\n  void set(int v, M x) {\n    dp[v] = x;\n    while((v\
    \ = stt.pa[v]) != -1) pull(v);\n  }\n\n  M query() { return dp.back(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/dynamicTreeDP.cpp
  requiredBy: []
  timestamp: '2025-05-16 21:27:50+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/point_set_tree_path_composite_sum_fixed_root.test.cpp
documentation_of: dp/dynamicTreeDP.cpp
layout: document
redirect_from:
- /library/dp/dynamicTreeDP.cpp
- /library/dp/dynamicTreeDP.cpp.html
title: dp/dynamicTreeDP.cpp
---
