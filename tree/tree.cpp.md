---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/jump_on_tree.test.cpp
    title: test/jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lca.test.cpp
    title: test/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest_tree.test.cpp
    title: test/mytest_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/tree.cpp\"\nclass tree {\n  using i32 = int32_t;\n\n\
    \  vc<i32> ord;\n\n  public:\n\n  int n, root;\n  vc<int> p, sz, dep, jp;\n\n\
    \  void calc(vc<i32> d, vc<i32> adj) {\n    sz = vi(n, 1);\n    p = dep = jp =\
    \ vi(n);\n\n    ord.reserve(n - 1);\n    for(int i = 0; i < n; i++) {\n      int\
    \ v = i;\n      while(d[v] == 1) {\n        ord.emplace_back(v);\n        p[v]\
    \ = adj[v], sz[p[v]] += sz[v];\n        d[v] = 0, d[p[v]]--, adj[p[v]] ^= v;\n\
    \        v = p[v];\n      }\n    }\n\n    assert(ssize(ord) == n - 1);\n\n   \
    \ p[root] = jp[root] = root;\n    for(i32 v : ord | views::reverse) {\n      dep[v]\
    \ = dep[p[v]] + 1;\n      if (dep[p[v]] + dep[jp[jp[p[v]]]] == 2 * dep[jp[p[v]]])\n\
    \        jp[v] = jp[jp[p[v]]];\n      else\n        jp[v] = p[v];\n    }\n  }\n\
    \n  tree(vc<pii> e, int _root = 0) : n(size(e) + 1), root(_root) {\n    vc<i32>\
    \ d(n), adj(n);\n    for(auto [u, v] : e)\n      d[u]++, d[v]++, adj[u] ^= v,\
    \ adj[v] ^= u;\n    d[root] = 0;\n    calc(d, adj);\n  }\n\n  tree(vi pa) : n(size(pa))\
    \ {\n    root = ranges::find(pa, -1) - pa.begin();\n    vc<i32> d(n), adj(n);\n\
    \    for(int v = 0; v < n; v++)\n      if (pa[v] != -1)\n        d[v]++, d[pa[v]]++,\
    \ adj[v] ^= pa[v], adj[pa[v]] ^= v;\n    d[root] = 0;\n    calc(d, adj);\n  }\n\
    \n  int jump(int v, int k) {\n    k = min(k, dep[v]);\n    while(k) {\n      if\
    \ (int d = dep[v] - dep[jp[v]]; d <= k)\n        v = jp[v], k -= d;\n      else\n\
    \        v = p[v], k -= 1;\n    }\n    return v;\n  }\n\n  int lca(int u, int\
    \ v) {\n    if (dep[u] < dep[v])\n      swap(u, v);\n    u = jump(u, dep[u] -\
    \ dep[v]);\n    if (u == v) return u;\n    while(p[u] != p[v]) {\n      if (jp[u]\
    \ != jp[v]) u = jp[u], v = jp[v];\n      else u = p[u], v = p[v];\n    }\n   \
    \ return p[u];\n  }\n\n  int kth(int s, int t, int k) {\n    int m = lca(s, t);\n\
    \    if (dep[s] + dep[t] - 2 * dep[m] < k)\n      return -1;\n    else if (dep[s]\
    \ - dep[m] >= k)\n      return jump(s, k);\n    else\n      return jump(t, dep[s]\
    \ + dep[t] - 2 * dep[m] - k);\n  }\n\n  int dis(int u, int v) {\n    return dep[u]\
    \ + dep[v] - 2 * dep[lca(u, v)];\n  }\n\n  int median(int u, int v, int w) {\n\
    \    return lca(u, v) ^ lca(u, w) ^ lca(v, w);\n  }\n\n  auto centroid() {\n \
    \   array<int, 2> r = {-1, -1};\n    vector<bool> ok(n, true);\n    for(int v\
    \ = 0; v < n; v++) {\n      if (2 * (n - sz[v]) > n)\n        ok[v] = false;\n\
    \      if (v != root and 2 * sz[v] > n)\n        ok[p[v]] = false;\n    }\n  \
    \  for(int v = 0; v < n; v++)\n      if (ok[v])\n        r[1] = v, swap(r[0],\
    \ r[1]);\n    return r;\n  }\n};\n"
  code: "class tree {\n  using i32 = int32_t;\n\n  vc<i32> ord;\n\n  public:\n\n \
    \ int n, root;\n  vc<int> p, sz, dep, jp;\n\n  void calc(vc<i32> d, vc<i32> adj)\
    \ {\n    sz = vi(n, 1);\n    p = dep = jp = vi(n);\n\n    ord.reserve(n - 1);\n\
    \    for(int i = 0; i < n; i++) {\n      int v = i;\n      while(d[v] == 1) {\n\
    \        ord.emplace_back(v);\n        p[v] = adj[v], sz[p[v]] += sz[v];\n   \
    \     d[v] = 0, d[p[v]]--, adj[p[v]] ^= v;\n        v = p[v];\n      }\n    }\n\
    \n    assert(ssize(ord) == n - 1);\n\n    p[root] = jp[root] = root;\n    for(i32\
    \ v : ord | views::reverse) {\n      dep[v] = dep[p[v]] + 1;\n      if (dep[p[v]]\
    \ + dep[jp[jp[p[v]]]] == 2 * dep[jp[p[v]]])\n        jp[v] = jp[jp[p[v]]];\n \
    \     else\n        jp[v] = p[v];\n    }\n  }\n\n  tree(vc<pii> e, int _root =\
    \ 0) : n(size(e) + 1), root(_root) {\n    vc<i32> d(n), adj(n);\n    for(auto\
    \ [u, v] : e)\n      d[u]++, d[v]++, adj[u] ^= v, adj[v] ^= u;\n    d[root] =\
    \ 0;\n    calc(d, adj);\n  }\n\n  tree(vi pa) : n(size(pa)) {\n    root = ranges::find(pa,\
    \ -1) - pa.begin();\n    vc<i32> d(n), adj(n);\n    for(int v = 0; v < n; v++)\n\
    \      if (pa[v] != -1)\n        d[v]++, d[pa[v]]++, adj[v] ^= pa[v], adj[pa[v]]\
    \ ^= v;\n    d[root] = 0;\n    calc(d, adj);\n  }\n\n  int jump(int v, int k)\
    \ {\n    k = min(k, dep[v]);\n    while(k) {\n      if (int d = dep[v] - dep[jp[v]];\
    \ d <= k)\n        v = jp[v], k -= d;\n      else\n        v = p[v], k -= 1;\n\
    \    }\n    return v;\n  }\n\n  int lca(int u, int v) {\n    if (dep[u] < dep[v])\n\
    \      swap(u, v);\n    u = jump(u, dep[u] - dep[v]);\n    if (u == v) return\
    \ u;\n    while(p[u] != p[v]) {\n      if (jp[u] != jp[v]) u = jp[u], v = jp[v];\n\
    \      else u = p[u], v = p[v];\n    }\n    return p[u];\n  }\n\n  int kth(int\
    \ s, int t, int k) {\n    int m = lca(s, t);\n    if (dep[s] + dep[t] - 2 * dep[m]\
    \ < k)\n      return -1;\n    else if (dep[s] - dep[m] >= k)\n      return jump(s,\
    \ k);\n    else\n      return jump(t, dep[s] + dep[t] - 2 * dep[m] - k);\n  }\n\
    \n  int dis(int u, int v) {\n    return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n\
    \  }\n\n  int median(int u, int v, int w) {\n    return lca(u, v) ^ lca(u, w)\
    \ ^ lca(v, w);\n  }\n\n  auto centroid() {\n    array<int, 2> r = {-1, -1};\n\
    \    vector<bool> ok(n, true);\n    for(int v = 0; v < n; v++) {\n      if (2\
    \ * (n - sz[v]) > n)\n        ok[v] = false;\n      if (v != root and 2 * sz[v]\
    \ > n)\n        ok[p[v]] = false;\n    }\n    for(int v = 0; v < n; v++)\n   \
    \   if (ok[v])\n        r[1] = v, swap(r[0], r[1]);\n    return r;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/tree.cpp
  requiredBy: []
  timestamp: '2026-02-02 01:08:31+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lca.test.cpp
  - test/jump_on_tree.test.cpp
  - test/mytest_tree.test.cpp
documentation_of: tree/tree.cpp
layout: document
redirect_from:
- /library/tree/tree.cpp
- /library/tree/tree.cpp.html
title: tree/tree.cpp
---
