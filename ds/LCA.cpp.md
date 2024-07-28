---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/lowest_common_ancestor_2.test.cpp
    title: test/lowest_common_ancestor_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/vertex_add_path_sum.test.cpp
    title: test/vertex_add_path_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/LCA.cpp\"\n//#include \"ds/RMQ.cpp\"\n\nstruct LCA {\n\
    \  vector<int> dep, tin, tout, mp;\n  RMQ<int> rmq;\n\n  LCA(vector<vector<int>>\
    \ g, int root = 0)\n  : dep(size(g)), tin(size(g)), tout(size(g)), mp(size(g)),\
    \ rmq(vector<int>(1)) {\n\n    int t = 0;\n    vector<int> init(2 * ssize(g) -\
    \ 1);\n    auto dfs = [&](int v, int p, auto &&self) -> void {\n      init[t]\
    \ = v;\n      tin[v] = t++;\n      for(int x : g[v]) {\n        if (x == p) continue;\n\
    \        dep[x] = dep[v] + 1;\n        self(x, v, self);\n        init[t++] =\
    \ v;\n      }\n      tout[v] = t;\n    };\n\n    dfs(root, -1, dfs);\n\n    vector<int>\
    \ f(size(g));\n    for(int x : dep) f[x]++;\n    for(int i = 1; i < ssize(g);\
    \ i++)\n      f[i] += f[i - 1];\n    vector<int> toOrd(size(g));\n    for(int\
    \ i = 0; i < ssize(g); i++) {\n      toOrd[i] = --f[dep[i]];\n      mp[f[dep[i]]]\
    \ = i;\n    }\n    for(int &x : init) x = toOrd[x];\n    rmq = RMQ(init);\n  }\n\
    \n  int lca(int u, int v) {\n    if (tin[u] > tin[v]) swap(u, v);\n    return\
    \ mp[rmq.query(tin[u], tout[v])];\n  }\n\n  int dis(int u, int v) {\n    return\
    \ dep[u] + dep[v] - 2 * dep[lca(u, v)];\n  }\n};\n"
  code: "//#include \"ds/RMQ.cpp\"\n\nstruct LCA {\n  vector<int> dep, tin, tout,\
    \ mp;\n  RMQ<int> rmq;\n\n  LCA(vector<vector<int>> g, int root = 0)\n  : dep(size(g)),\
    \ tin(size(g)), tout(size(g)), mp(size(g)), rmq(vector<int>(1)) {\n\n    int t\
    \ = 0;\n    vector<int> init(2 * ssize(g) - 1);\n    auto dfs = [&](int v, int\
    \ p, auto &&self) -> void {\n      init[t] = v;\n      tin[v] = t++;\n      for(int\
    \ x : g[v]) {\n        if (x == p) continue;\n        dep[x] = dep[v] + 1;\n \
    \       self(x, v, self);\n        init[t++] = v;\n      }\n      tout[v] = t;\n\
    \    };\n\n    dfs(root, -1, dfs);\n\n    vector<int> f(size(g));\n    for(int\
    \ x : dep) f[x]++;\n    for(int i = 1; i < ssize(g); i++)\n      f[i] += f[i -\
    \ 1];\n    vector<int> toOrd(size(g));\n    for(int i = 0; i < ssize(g); i++)\
    \ {\n      toOrd[i] = --f[dep[i]];\n      mp[f[dep[i]]] = i;\n    }\n    for(int\
    \ &x : init) x = toOrd[x];\n    rmq = RMQ(init);\n  }\n\n  int lca(int u, int\
    \ v) {\n    if (tin[u] > tin[v]) swap(u, v);\n    return mp[rmq.query(tin[u],\
    \ tout[v])];\n  }\n\n  int dis(int u, int v) {\n    return dep[u] + dep[v] - 2\
    \ * dep[lca(u, v)];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/LCA.cpp
  requiredBy: []
  timestamp: '2024-07-24 13:33:23+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lowest_common_ancestor_2.test.cpp
  - test/vertex_add_path_sum.test.cpp
documentation_of: ds/LCA.cpp
layout: document
redirect_from:
- /library/ds/LCA.cpp
- /library/ds/LCA.cpp.html
title: ds/LCA.cpp
---
