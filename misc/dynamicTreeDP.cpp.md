---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: test/point_set_tree_path_composite_sum_fixed_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/dynamicTreeDP.cpp\"\n//#include \"ds/staticTopTree.cpp\"\
    \n\ntemplate<class V, V(*base)(int), class E, E(*addEdge)(const V&, int eid),\n\
    E(*op)(const E&, const E&), V(*addVertex)(const E&, int vid), E(*compress)(const\
    \ E&, const E&)>\nstruct dynamicTreeDP {\n  int n;\n  staticTopTree stt;\n  vector<V>\
    \ dpV;\n  vector<E> dpE;\n\n  dynamicTreeDP(vector<vector<int>> &g)\n  : n(size(g)),stt(g),\
    \ dpV(n), dpE(3 * n) {\n    for(int v : stt.ord)\n      update(v);\n  }\n\n  void\
    \ update(int v) {\n    if (auto type = stt.vt[v]; type == 0)\n      dpV[v] = base(v);\n\
    \    else if (type == 1)\n      dpE[v - n] = op(dpE[stt.lc[v] - n], dpE[stt.rc[v]\
    \ - n]);\n    else if (type == 2)\n      dpE[v - n] = compress(dpE[stt.rc[v] -\
    \ n], dpE[stt.lc[v] - n]);\n    else if (type == 3)\n      dpE[v - n] = addEdge(dpV[stt.lc[v]],\
    \ v - n);\n    else if (type == 4)\n      dpV[v] = addVertex(dpE[stt.lc[v] - n],\
    \ v);\n  }\n\n  void pull(int v) {\n    while(v != -1) {\n      update(v);\n \
    \     v = stt.p[v];\n    }\n  }\n\n  void updateVertex(int v) { pull(v); }\n \
    \ void updateEdge(int e) { pull(e + n); }\n  E get() { return dpE[stt.stt_rt -\
    \ n]; }\n};\n"
  code: "//#include \"ds/staticTopTree.cpp\"\n\ntemplate<class V, V(*base)(int), class\
    \ E, E(*addEdge)(const V&, int eid),\nE(*op)(const E&, const E&), V(*addVertex)(const\
    \ E&, int vid), E(*compress)(const E&, const E&)>\nstruct dynamicTreeDP {\n  int\
    \ n;\n  staticTopTree stt;\n  vector<V> dpV;\n  vector<E> dpE;\n\n  dynamicTreeDP(vector<vector<int>>\
    \ &g)\n  : n(size(g)),stt(g), dpV(n), dpE(3 * n) {\n    for(int v : stt.ord)\n\
    \      update(v);\n  }\n\n  void update(int v) {\n    if (auto type = stt.vt[v];\
    \ type == 0)\n      dpV[v] = base(v);\n    else if (type == 1)\n      dpE[v -\
    \ n] = op(dpE[stt.lc[v] - n], dpE[stt.rc[v] - n]);\n    else if (type == 2)\n\
    \      dpE[v - n] = compress(dpE[stt.rc[v] - n], dpE[stt.lc[v] - n]);\n    else\
    \ if (type == 3)\n      dpE[v - n] = addEdge(dpV[stt.lc[v]], v - n);\n    else\
    \ if (type == 4)\n      dpV[v] = addVertex(dpE[stt.lc[v] - n], v);\n  }\n\n  void\
    \ pull(int v) {\n    while(v != -1) {\n      update(v);\n      v = stt.p[v];\n\
    \    }\n  }\n\n  void updateVertex(int v) { pull(v); }\n  void updateEdge(int\
    \ e) { pull(e + n); }\n  E get() { return dpE[stt.stt_rt - n]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/dynamicTreeDP.cpp
  requiredBy: []
  timestamp: '2024-07-28 21:57:55+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/point_set_tree_path_composite_sum_fixed_root.test.cpp
documentation_of: misc/dynamicTreeDP.cpp
layout: document
redirect_from:
- /library/misc/dynamicTreeDP.cpp
- /library/misc/dynamicTreeDP.cpp.html
title: misc/dynamicTreeDP.cpp
---
