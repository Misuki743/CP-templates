---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/lca_2.test.cpp
    title: test/lca_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lca_3.test.cpp
    title: test/lca_3.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/LCA.cpp\"\n//#include \"ds/RMQ.cpp\"\n\nstruct LCA\
    \ {\n  vi dep, tin, tout, mp;\n  RMQ<int> rmq;\n\n  vi precomp(vc<pii> &e, int\
    \ root) {\n    const int n = ssize(e) + 1;\n\n    dep = tin = tout = mp = vi(n);\n\
    \n    vi sz(n, 1), p(n), ord;\n    {\n      vi adj(n), d(n);\n      for(auto &[u,\
    \ v] : e)\n        adj[u] ^= v, adj[v] ^= u, d[u]++, d[v]++;\n\n      d[root]\
    \ = 0, p[root] = root;\n      ord.reserve(n - 1);\n      for(int i = 0; i < n;\
    \ i++) {\n        int v = i;\n        while(d[v] == 1) {\n          ord.emplace_back(v);\n\
    \          p[v] = adj[v], sz[p[v]] += sz[v];\n          d[v] = 0, d[p[v]]--, adj[p[v]]\
    \ ^= v;\n          v = p[v];\n        }\n      }\n    }\n\n    vi dfn(n);\n  \
    \  {\n      vi nxt(n, 1);\n      for(int v : ord | views::reverse) {\n       \
    \ dfn[v] = nxt[p[v]], nxt[p[v]] += sz[v];\n        nxt[v] = dfn[v] + 1;\n    \
    \    dep[v] = dep[p[v]] + 1;\n      }\n      vi().swap(ord);\n      vi().swap(sz);\n\
    \    }\n\n    vi init(2 * n - 1);\n    {\n      vi dfn_ord = invPerm(std::move(dfn));\n\
    \n      int nxt = 0, pre = root;\n      for(int v : dfn_ord) {\n        while(pre\
    \ != p[v]) {\n          pre = p[pre], tout[pre] = nxt;\n          init[nxt++]\
    \ = pre;\n        }\n        tin[v] = tout[v] = nxt;\n        init[nxt++] = pre\
    \ = v;\n      }\n\n      while(pre != root) {\n        pre = p[pre], tout[pre]\
    \ = nxt;\n        init[nxt++] = pre;\n      }\n    }\n\n    {\n      vi f(n);\n\
    \      for(int x : dep) f[x]++;\n      pSum(f);\n\n      vi rank(n);\n      for(int\
    \ v = 0; v < n; v++) {\n        rank[v] = --f[dep[v]];\n        mp[rank[v]] =\
    \ v;\n      }\n      for(int &v : init) v = rank[v];\n    }\n\n    return init;\n\
    \  }\n\n  LCA(vc<pii> e, int root = 0) : rmq(precomp(e, root)) {}\n\n  int lca(int\
    \ u, int v) {\n    if (tin[u] > tin[v]) swap(u, v);\n    return mp[rmq.query(tin[u],\
    \ tout[v] + 1)];\n  }\n\n  int dis(int u, int v) {\n    return dep[u] + dep[v]\
    \ - 2 * dep[lca(u, v)];\n  }\n};\n"
  code: "//#include \"ds/RMQ.cpp\"\n\nstruct LCA {\n  vi dep, tin, tout, mp;\n  RMQ<int>\
    \ rmq;\n\n  vi precomp(vc<pii> &e, int root) {\n    const int n = ssize(e) + 1;\n\
    \n    dep = tin = tout = mp = vi(n);\n\n    vi sz(n, 1), p(n), ord;\n    {\n \
    \     vi adj(n), d(n);\n      for(auto &[u, v] : e)\n        adj[u] ^= v, adj[v]\
    \ ^= u, d[u]++, d[v]++;\n\n      d[root] = 0, p[root] = root;\n      ord.reserve(n\
    \ - 1);\n      for(int i = 0; i < n; i++) {\n        int v = i;\n        while(d[v]\
    \ == 1) {\n          ord.emplace_back(v);\n          p[v] = adj[v], sz[p[v]] +=\
    \ sz[v];\n          d[v] = 0, d[p[v]]--, adj[p[v]] ^= v;\n          v = p[v];\n\
    \        }\n      }\n    }\n\n    vi dfn(n);\n    {\n      vi nxt(n, 1);\n   \
    \   for(int v : ord | views::reverse) {\n        dfn[v] = nxt[p[v]], nxt[p[v]]\
    \ += sz[v];\n        nxt[v] = dfn[v] + 1;\n        dep[v] = dep[p[v]] + 1;\n \
    \     }\n      vi().swap(ord);\n      vi().swap(sz);\n    }\n\n    vi init(2 *\
    \ n - 1);\n    {\n      vi dfn_ord = invPerm(std::move(dfn));\n\n      int nxt\
    \ = 0, pre = root;\n      for(int v : dfn_ord) {\n        while(pre != p[v]) {\n\
    \          pre = p[pre], tout[pre] = nxt;\n          init[nxt++] = pre;\n    \
    \    }\n        tin[v] = tout[v] = nxt;\n        init[nxt++] = pre = v;\n    \
    \  }\n\n      while(pre != root) {\n        pre = p[pre], tout[pre] = nxt;\n \
    \       init[nxt++] = pre;\n      }\n    }\n\n    {\n      vi f(n);\n      for(int\
    \ x : dep) f[x]++;\n      pSum(f);\n\n      vi rank(n);\n      for(int v = 0;\
    \ v < n; v++) {\n        rank[v] = --f[dep[v]];\n        mp[rank[v]] = v;\n  \
    \    }\n      for(int &v : init) v = rank[v];\n    }\n\n    return init;\n  }\n\
    \n  LCA(vc<pii> e, int root = 0) : rmq(precomp(e, root)) {}\n\n  int lca(int u,\
    \ int v) {\n    if (tin[u] > tin[v]) swap(u, v);\n    return mp[rmq.query(tin[u],\
    \ tout[v] + 1)];\n  }\n\n  int dis(int u, int v) {\n    return dep[u] + dep[v]\
    \ - 2 * dep[lca(u, v)];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/LCA.cpp
  requiredBy: []
  timestamp: '2026-02-02 00:52:21+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lca_2.test.cpp
  - test/lca_3.test.cpp
documentation_of: tree/LCA.cpp
layout: document
redirect_from:
- /library/tree/LCA.cpp
- /library/tree/LCA.cpp.html
title: tree/LCA.cpp
---
