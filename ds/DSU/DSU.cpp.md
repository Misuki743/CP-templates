---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/incremental_scc.test.cpp
    title: test/incremental_scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/minimum_spanning_tree_Kruskal.test.cpp
    title: test/minimum_spanning_tree_Kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/minimum_spanning_tree_Prim.test.cpp
    title: test/minimum_spanning_tree_Prim.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unionfind.test.cpp
    title: test/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unionfind.test.cpp
  - test/incremental_scc.test.cpp
  - test/minimum_spanning_tree_Prim.test.cpp
  - test/minimum_spanning_tree_Kruskal.test.cpp
documentation_of: ds/DSU/DSU.cpp
layout: document
title: ds/DSU/DSU.cpp
---

## constructor

`DSU(int n)`: create a disjoint set of size $\text{n}$ without additional data attacted

`DSU(vector<T> init, F f(T &larger_set, T &smaller_set) -> void)`: create a disjoint set where $\text{i}$-th set is attached with $\text{init[i]}$. when calling merge, data would be merged from smaller set to larger set using function $\text{f}$.

## example usage:

standard DSU: https://judge.yosupo.jp/submission/349238

DSU attach with $O(1)$ data: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/submission/360830642

DSU attach with $O(\text{size})$ data and use small-to-large style merge: https://codeforces.com/contest/600/submission/360850419
