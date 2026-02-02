---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/jump_on_tree_2.test.cpp
    title: test/jump_on_tree_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/jump_on_tree_3.test.cpp
    title: test/jump_on_tree_3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lca_4.test.cpp
    title: test/lca_4.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/vertex_add_path_sum.test.cpp
    title: test/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/vertex_add_subtree_sum.test.cpp
    title: test/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/vertex_set_path_composite.test.cpp
    title: test/vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/HLD.cpp\"\nstruct HLD {\n  static const int MSK = (1\
    \ << 30);\n  vi dep, p_head, tin, tout, inv_tin;\n\n  inline int head(int v) const\
    \ { return (p_head[v] & MSK) ? v : p_head[v]; }\n  inline int head_parent(int\
    \ v) const { return p_head[head(v)] & (MSK - 1); }\n\n  HLD(vvi g, int root =\
    \ 0) {\n    dep = p_head = tin = tout = inv_tin = vi(size(g));\n\n    vi sz(size(g),\
    \ 1);\n    auto dfs = [&](int v, auto &self) -> void {\n      int mx_id = -1,\
    \ p_id = -1;\n      for(int i = -1; int x : g[v]) {\n        i++;\n        if\
    \ ((x | MSK) == p_head[v]) {\n          p_id = i;\n        } else {\n        \
    \  p_head[x] = (v | MSK), dep[x] = dep[v] + 1;\n          self(x, self);\n   \
    \       sz[v] += sz[x];\n          if (mx_id == -1 or sz[x] > sz[g[v][mx_id]])\n\
    \            mx_id = i;\n        }\n      }\n      if (mx_id != -1) swap(g[v][p_id\
    \ == 0], g[v][mx_id]);\n      if (p_id != -1) g[v].erase(g[v].begin() + p_id);\n\
    \    };\n\n    p_head[root] = (root | MSK);\n    dfs(root, dfs);\n\n    int nxt\
    \ = 0;\n    auto dfs2 = [&](int v, auto &self) -> void {\n      tin[v] = nxt++;\n\
    \      if (!g[v].empty())\n        p_head[g[v][0]] = head(v);\n      if (!g[v].empty())\
    \ {\n        vi sz_seq;\n        for(int x : g[v]) sz_seq.eb(sz[x]);\n       \
    \ assert(ranges::max(sz_seq) == sz_seq[0]);\n      }\n      for(int x : g[v])\n\
    \        self(x, self);\n      tout[v] = nxt;\n    };\n\n    dfs2(root, dfs2);\n\
    \n    inv_tin = invPerm(tin);\n  }\n\n  auto query_path(int u, int v, bool edge\
    \ = false) {\n    vc<pii> lr;\n    while(head(u) != head(v)) {\n      if (dep[head(u)]\
    \ > dep[head(v)])\n        swap(u, v);\n      lr.emplace_back(tin[head(v)], tin[v]\
    \ + 1);\n      v = head_parent(v);\n    }\n\n    if (tin[u] > tin[v]) swap(u,\
    \ v);\n    if (tin[u] + edge <= tin[v])\n      lr.emplace_back(tin[u] + edge,\
    \ tin[v] + 1);\n\n    return lr;\n  }\n\n  //l < r: op(l, op(l + 1, ...))\n  //l\
    \ > r: op(r - 1, op(r - 2, ...))\n  auto query_path_non_commutative(int u, int\
    \ v, bool edge = false) {\n    vc<pii> lr1, lr2;\n    while(head(u) != head(v))\
    \ {\n      if (dep[head(u)] > dep[head(v)]) {\n        lr1.emplace_back(tin[u]\
    \ + 1, tin[head(u)]);\n        u = head_parent(u);\n      } else {\n        lr2.emplace_back(tin[head(v)],\
    \ tin[v] + 1);\n        v = head_parent(v);\n      }\n    }\n\n    if (tin[u]\
    \ + edge <= tin[v])\n      lr2.emplace_back(tin[u] + edge, tin[v] + 1);\n    else\
    \ if (tin[v] + edge <= tin[u])\n      lr1.emplace_back(tin[u] + 1, tin[v] + edge);\n\
    \n    lr1.insert(end(lr1), lr2.rbegin(), lr2.rend());\n\n    return lr1;\n  }\n\
    \n  auto query_subtree(int v) { return pii(tin[v], tout[v]); }\n\n  int query_point(int\
    \ v) { return tin[v]; }\n\n  int lca(int u, int v) {\n    while(head(u) != head(v))\
    \ {\n      if (dep[head(u)] > dep[head(v)])\n        swap(u, v);\n      v = head_parent(v);\n\
    \    }\n    return tin[u] < tin[v] ? u : v;\n  }\n\n  int kth(int s, int t, int\
    \ k) {\n    int l = lca(s, t);\n    if (int d = dep[s] + dep[t] - 2 * dep[l];\
    \ k > d)\n      return -1;\n    else if (k > dep[s] - dep[l])\n      k = d - k,\
    \ swap(s, t);\n    while(k > dep[s] - dep[head(s)]) {\n      k -= dep[s] - dep[head(s)]\
    \ + 1;\n      s = head_parent(s);\n    }\n    return inv_tin[tin[s] - k];\n  }\n\
    \n  template<class M>\n  vc<M> reorder_init(vc<M> init) {\n    assert(ssize(init)\
    \ == ssize(dep));\n    auto r = init;\n    for(int i = 0; i < ssize(init); i++)\n\
    \      r[tin[i]] = init[i];\n    return r;\n  }\n};\n"
  code: "struct HLD {\n  static const int MSK = (1 << 30);\n  vi dep, p_head, tin,\
    \ tout, inv_tin;\n\n  inline int head(int v) const { return (p_head[v] & MSK)\
    \ ? v : p_head[v]; }\n  inline int head_parent(int v) const { return p_head[head(v)]\
    \ & (MSK - 1); }\n\n  HLD(vvi g, int root = 0) {\n    dep = p_head = tin = tout\
    \ = inv_tin = vi(size(g));\n\n    vi sz(size(g), 1);\n    auto dfs = [&](int v,\
    \ auto &self) -> void {\n      int mx_id = -1, p_id = -1;\n      for(int i = -1;\
    \ int x : g[v]) {\n        i++;\n        if ((x | MSK) == p_head[v]) {\n     \
    \     p_id = i;\n        } else {\n          p_head[x] = (v | MSK), dep[x] = dep[v]\
    \ + 1;\n          self(x, self);\n          sz[v] += sz[x];\n          if (mx_id\
    \ == -1 or sz[x] > sz[g[v][mx_id]])\n            mx_id = i;\n        }\n     \
    \ }\n      if (mx_id != -1) swap(g[v][p_id == 0], g[v][mx_id]);\n      if (p_id\
    \ != -1) g[v].erase(g[v].begin() + p_id);\n    };\n\n    p_head[root] = (root\
    \ | MSK);\n    dfs(root, dfs);\n\n    int nxt = 0;\n    auto dfs2 = [&](int v,\
    \ auto &self) -> void {\n      tin[v] = nxt++;\n      if (!g[v].empty())\n   \
    \     p_head[g[v][0]] = head(v);\n      if (!g[v].empty()) {\n        vi sz_seq;\n\
    \        for(int x : g[v]) sz_seq.eb(sz[x]);\n        assert(ranges::max(sz_seq)\
    \ == sz_seq[0]);\n      }\n      for(int x : g[v])\n        self(x, self);\n \
    \     tout[v] = nxt;\n    };\n\n    dfs2(root, dfs2);\n\n    inv_tin = invPerm(tin);\n\
    \  }\n\n  auto query_path(int u, int v, bool edge = false) {\n    vc<pii> lr;\n\
    \    while(head(u) != head(v)) {\n      if (dep[head(u)] > dep[head(v)])\n   \
    \     swap(u, v);\n      lr.emplace_back(tin[head(v)], tin[v] + 1);\n      v =\
    \ head_parent(v);\n    }\n\n    if (tin[u] > tin[v]) swap(u, v);\n    if (tin[u]\
    \ + edge <= tin[v])\n      lr.emplace_back(tin[u] + edge, tin[v] + 1);\n\n   \
    \ return lr;\n  }\n\n  //l < r: op(l, op(l + 1, ...))\n  //l > r: op(r - 1, op(r\
    \ - 2, ...))\n  auto query_path_non_commutative(int u, int v, bool edge = false)\
    \ {\n    vc<pii> lr1, lr2;\n    while(head(u) != head(v)) {\n      if (dep[head(u)]\
    \ > dep[head(v)]) {\n        lr1.emplace_back(tin[u] + 1, tin[head(u)]);\n   \
    \     u = head_parent(u);\n      } else {\n        lr2.emplace_back(tin[head(v)],\
    \ tin[v] + 1);\n        v = head_parent(v);\n      }\n    }\n\n    if (tin[u]\
    \ + edge <= tin[v])\n      lr2.emplace_back(tin[u] + edge, tin[v] + 1);\n    else\
    \ if (tin[v] + edge <= tin[u])\n      lr1.emplace_back(tin[u] + 1, tin[v] + edge);\n\
    \n    lr1.insert(end(lr1), lr2.rbegin(), lr2.rend());\n\n    return lr1;\n  }\n\
    \n  auto query_subtree(int v) { return pii(tin[v], tout[v]); }\n\n  int query_point(int\
    \ v) { return tin[v]; }\n\n  int lca(int u, int v) {\n    while(head(u) != head(v))\
    \ {\n      if (dep[head(u)] > dep[head(v)])\n        swap(u, v);\n      v = head_parent(v);\n\
    \    }\n    return tin[u] < tin[v] ? u : v;\n  }\n\n  int kth(int s, int t, int\
    \ k) {\n    int l = lca(s, t);\n    if (int d = dep[s] + dep[t] - 2 * dep[l];\
    \ k > d)\n      return -1;\n    else if (k > dep[s] - dep[l])\n      k = d - k,\
    \ swap(s, t);\n    while(k > dep[s] - dep[head(s)]) {\n      k -= dep[s] - dep[head(s)]\
    \ + 1;\n      s = head_parent(s);\n    }\n    return inv_tin[tin[s] - k];\n  }\n\
    \n  template<class M>\n  vc<M> reorder_init(vc<M> init) {\n    assert(ssize(init)\
    \ == ssize(dep));\n    auto r = init;\n    for(int i = 0; i < ssize(init); i++)\n\
    \      r[tin[i]] = init[i];\n    return r;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/HLD.cpp
  requiredBy: []
  timestamp: '2026-02-02 22:55:43+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/jump_on_tree_3.test.cpp
  - test/vertex_add_path_sum.test.cpp
  - test/lca_4.test.cpp
  - test/vertex_add_subtree_sum.test.cpp
  - test/jump_on_tree_2.test.cpp
  - test/vertex_set_path_composite.test.cpp
documentation_of: tree/HLD.cpp
layout: document
redirect_from:
- /library/tree/HLD.cpp
- /library/tree/HLD.cpp.html
title: tree/HLD.cpp
---
