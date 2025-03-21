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
  bundledCode: "#line 1 \"icpc/aux_tree.cpp\"\n//#include<short_lca.cpp>\n\nauto aux_tree(vector<vector<int>>\
    \ g, vector<int> c) {\n  int n = ssize(g);\n  LCA fj(g);\n  vector<int> p(n <<\
    \ 1), top(n, -1), mp(n << 1);\n  vector<vector<int>> h((n << 1) - 1);\n  auto\
    \ add = [&](int u, int v) {\n    h[u].emplace_back(v), h[v].emplace_back(u);\n\
    \  };\n  auto dfs = [&](int v, auto &self) -> void {\n    if (top[c[v]] != -1)\
    \ {\n      int t = fj.lca(mp[top[c[v]]], v), s;\n      if (t != mp[top[c[v]]])\
    \ {\n        while((s = p[top[c[v]]]) != -1 and fj.d[mp[s]] >= fj.d[t])\n    \
    \      add(top[c[v]], s), top[c[v]] = s;\n        if (mp[top[c[v]]] != t) {\n\
    \          add(top[c[v]], n);\n          p[n] = s, top[c[v]] = n, mp[n++] = t;\n\
    \        }\n      }\n    }\n    p[v] = top[c[v]], top[c[v]] = v;\n    for(int\
    \ x : g[v]) if (x != fj.p[v]) self(x, self);\n  };\n\n  iota(mp.begin(), mp.end(),\
    \ 0);\n  dfs(0, dfs);\n\n  for(int &x : top)\n    while(x != -1 and p[x] != -1)\n\
    \      add(x, p[x]), x = p[x];\n\n  return pair(h, top);\n}\n"
  code: "//#include<short_lca.cpp>\n\nauto aux_tree(vector<vector<int>> g, vector<int>\
    \ c) {\n  int n = ssize(g);\n  LCA fj(g);\n  vector<int> p(n << 1), top(n, -1),\
    \ mp(n << 1);\n  vector<vector<int>> h((n << 1) - 1);\n  auto add = [&](int u,\
    \ int v) {\n    h[u].emplace_back(v), h[v].emplace_back(u);\n  };\n  auto dfs\
    \ = [&](int v, auto &self) -> void {\n    if (top[c[v]] != -1) {\n      int t\
    \ = fj.lca(mp[top[c[v]]], v), s;\n      if (t != mp[top[c[v]]]) {\n        while((s\
    \ = p[top[c[v]]]) != -1 and fj.d[mp[s]] >= fj.d[t])\n          add(top[c[v]],\
    \ s), top[c[v]] = s;\n        if (mp[top[c[v]]] != t) {\n          add(top[c[v]],\
    \ n);\n          p[n] = s, top[c[v]] = n, mp[n++] = t;\n        }\n      }\n \
    \   }\n    p[v] = top[c[v]], top[c[v]] = v;\n    for(int x : g[v]) if (x != fj.p[v])\
    \ self(x, self);\n  };\n\n  iota(mp.begin(), mp.end(), 0);\n  dfs(0, dfs);\n\n\
    \  for(int &x : top)\n    while(x != -1 and p[x] != -1)\n      add(x, p[x]), x\
    \ = p[x];\n\n  return pair(h, top);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: icpc/aux_tree.cpp
  requiredBy: []
  timestamp: '2025-03-21 23:27:46+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc/aux_tree.cpp
layout: document
redirect_from:
- /library/icpc/aux_tree.cpp
- /library/icpc/aux_tree.cpp.html
title: icpc/aux_tree.cpp
---
