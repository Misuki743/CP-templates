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
    \n\ntemplate<class T, T(*vertex)(int), T(*addEdge)(const T&, int eid),\nT(*rake)(const\
    \ T&, const T&), T(*addVertex)(const T&, int vid), T(*compress)(const T&, const\
    \ T&)>\nstruct dynamicTreeDP {\n  int n;\n  staticTopTree stt;\n  vector<T> dp;\n\
    \n  dynamicTreeDP(vector<vector<int>> &g)\n  : n(size(g)),stt(g), dp(4 * n) {\n\
    \    for(int v : stt.ord)\n      update(v);\n  }\n\n  void update(int v) {\n \
    \   if (auto type = stt.vt[v]; type == 0)\n      dp[v] = vertex(v);\n    else\
    \ if (type == 1)\n      dp[v] = rake(dp[stt.lc[v]], dp[stt.rc[v]]);\n    else\
    \ if (type == 2)\n      dp[v] = compress(dp[stt.rc[v]], dp[stt.lc[v]]);\n    else\
    \ if (type == 3)\n      dp[v] = addEdge(dp[stt.lc[v]], v - n);\n    else if (type\
    \ == 4)\n      dp[v] = addVertex(dp[stt.lc[v]], v);\n  }\n\n  void pull(int v)\
    \ {\n    while(v != -1) {\n      update(v);\n      v = stt.p[v];\n    }\n  }\n\
    \n  void updateVertex(int v) { pull(v); }\n  void updateEdge(int e) { pull(e +\
    \ n); }\n  T get() { return dp[stt.stt_rt]; }\n};\n"
  code: "//#include \"ds/staticTopTree.cpp\"\n\ntemplate<class T, T(*vertex)(int),\
    \ T(*addEdge)(const T&, int eid),\nT(*rake)(const T&, const T&), T(*addVertex)(const\
    \ T&, int vid), T(*compress)(const T&, const T&)>\nstruct dynamicTreeDP {\n  int\
    \ n;\n  staticTopTree stt;\n  vector<T> dp;\n\n  dynamicTreeDP(vector<vector<int>>\
    \ &g)\n  : n(size(g)),stt(g), dp(4 * n) {\n    for(int v : stt.ord)\n      update(v);\n\
    \  }\n\n  void update(int v) {\n    if (auto type = stt.vt[v]; type == 0)\n  \
    \    dp[v] = vertex(v);\n    else if (type == 1)\n      dp[v] = rake(dp[stt.lc[v]],\
    \ dp[stt.rc[v]]);\n    else if (type == 2)\n      dp[v] = compress(dp[stt.rc[v]],\
    \ dp[stt.lc[v]]);\n    else if (type == 3)\n      dp[v] = addEdge(dp[stt.lc[v]],\
    \ v - n);\n    else if (type == 4)\n      dp[v] = addVertex(dp[stt.lc[v]], v);\n\
    \  }\n\n  void pull(int v) {\n    while(v != -1) {\n      update(v);\n      v\
    \ = stt.p[v];\n    }\n  }\n\n  void updateVertex(int v) { pull(v); }\n  void updateEdge(int\
    \ e) { pull(e + n); }\n  T get() { return dp[stt.stt_rt]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/dynamicTreeDP.cpp
  requiredBy: []
  timestamp: '2024-08-04 01:36:11+08:00'
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
