---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/incremental_scc.test.cpp
    title: test/incremental_scc.test.cpp
  - icon: ':x:'
    path: test/minimum_spanning_tree_Kruskal.test.cpp
    title: test/minimum_spanning_tree_Kruskal.test.cpp
  - icon: ':x:'
    path: test/minimum_spanning_tree_Prim.test.cpp
    title: test/minimum_spanning_tree_Prim.test.cpp
  - icon: ':x:'
    path: test/unionfind.test.cpp
    title: test/unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/DSU/DSU.cpp\"\ntemplate<class T = int, typename F = void*>\n\
    struct DSU {\n  vi sz_par;\n  vc<T> data;\n  F op;\n\n  DSU(int n) requires same_as<F,\
    \ void*> : sz_par(n, -1), op(nullptr) {}\n\n  DSU(vc<T> init, F f) requires invocable<F,\
    \ T&, T&> &&\n    (!invocable<F, T, T&>) && (!invocable<F, T&, T>)\n    : sz_par(std::size(init),\
    \ -1), data(std::move(init)), op(f) {}\n\n  int query(int v) {\n    int r = v;\n\
    \    while(sz_par[r] >= 0) r = sz_par[r];\n    while(v != r) {\n      int nxt\
    \ = sz_par[v];\n      sz_par[v] = r, v = nxt;\n    }\n    return r;\n  }\n\n \
    \ bool merge(int v1, int v2) {\n    int b1 = query(v1), b2 = query(v2);\n\n  \
    \  if (b1 == b2)\n      return false;\n\n    if (-sz_par[b1] > -sz_par[b2])\n\
    \      swap(b1, b2);\n\n    sz_par[b2] += sz_par[b1];\n    sz_par[b1] = b2;\n\
    \    if constexpr (!same_as<F, void*>)\n      op(data[b2], data[b1]);\n\n    return\
    \ true;\n  }\n\n  int size(int v) { return v = query(v), -sz_par[v]; }\n  const\
    \ T& get(int v) requires (!same_as<F, void*>) {\n    return data[query(v)];\n\
    \  }\n};\n"
  code: "template<class T = int, typename F = void*>\nstruct DSU {\n  vi sz_par;\n\
    \  vc<T> data;\n  F op;\n\n  DSU(int n) requires same_as<F, void*> : sz_par(n,\
    \ -1), op(nullptr) {}\n\n  DSU(vc<T> init, F f) requires invocable<F, T&, T&>\
    \ &&\n    (!invocable<F, T, T&>) && (!invocable<F, T&, T>)\n    : sz_par(std::size(init),\
    \ -1), data(std::move(init)), op(f) {}\n\n  int query(int v) {\n    int r = v;\n\
    \    while(sz_par[r] >= 0) r = sz_par[r];\n    while(v != r) {\n      int nxt\
    \ = sz_par[v];\n      sz_par[v] = r, v = nxt;\n    }\n    return r;\n  }\n\n \
    \ bool merge(int v1, int v2) {\n    int b1 = query(v1), b2 = query(v2);\n\n  \
    \  if (b1 == b2)\n      return false;\n\n    if (-sz_par[b1] > -sz_par[b2])\n\
    \      swap(b1, b2);\n\n    sz_par[b2] += sz_par[b1];\n    sz_par[b1] = b2;\n\
    \    if constexpr (!same_as<F, void*>)\n      op(data[b2], data[b1]);\n\n    return\
    \ true;\n  }\n\n  int size(int v) { return v = query(v), -sz_par[v]; }\n  const\
    \ T& get(int v) requires (!same_as<F, void*>) {\n    return data[query(v)];\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/DSU/DSU.cpp
  requiredBy: []
  timestamp: '2026-01-31 18:57:43+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/unionfind.test.cpp
  - test/incremental_scc.test.cpp
  - test/minimum_spanning_tree_Prim.test.cpp
  - test/minimum_spanning_tree_Kruskal.test.cpp
documentation_of: ds/DSU/DSU.cpp
layout: document
redirect_from:
- /library/ds/DSU/DSU.cpp
- /library/ds/DSU/DSU.cpp.html
title: ds/DSU/DSU.cpp
---
