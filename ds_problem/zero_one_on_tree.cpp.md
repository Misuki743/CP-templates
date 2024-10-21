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
  bundledCode: "#line 1 \"ds_problem/zero_one_on_tree.cpp\"\n//#include<ds/monoidDSU>\n\
    \nstruct min_monoid {\n  using M = array<int, 2>;\n  static M id() { return {INT_MAX,\
    \ -1}; }\n  static M op(const M& a, const M& b) {\n    return min(a, b);\n  }\n\
    };\n\ntemplate<class T>\nT zero_one_on_tree(vector<vector<int>> g, vector<T> l,\
    \ vector<T> a, int r = 0) {\n  int n = ssize(g);\n\n  vector<int> p(n, -1), d(n);\n\
    \  {\n    auto dfs = [&](int v, auto &&self) -> void {\n      for(int x : g[v])\
    \ {\n        if (x == p[v]) continue;\n        d[x] = d[v] + 1, p[x] = v;\n  \
    \      self(x, self);\n      }\n    };\n    dfs(r, dfs);\n  }\n\n  DSU<min_monoid::M,\
    \ min_monoid::id, min_monoid::op> dsu([&]() {\n    vector<min_monoid::M> init(n);\n\
    \    for(int i = 0; i < n; i++)\n      init[i] = {d[i], i};\n    return init;\n\
    \  }());\n\n  using D = tuple<T, T, int>; //(l_v, a_v, v)\n  auto cmp = [](D a,\
    \ D b) {\n    return get<1>(a) * get<0>(b) < get<0>(a) * get<1>(b);\n  };\n  priority_queue<D,\
    \ vector<D>, decltype(cmp)> pq;\n  for(int i = 0; i < n; i++)\n    pq.push({l[i],\
    \ a[i], i});\n\n  T cost = 0, lsum = 0;\n  vector<bool> vis(n, false);\n  while(!pq.empty())\
    \ {\n    auto [l_v, a_v, v] = pq.top(); pq.pop();\n    if (l[v] != l_v or a[v]\
    \ != a_v) continue;\n    if (p[v] != -1 and !vis[dsu.get(p[v])[1]]) {\n      dsu.merge(v,\
    \ p[v]);\n      int b = dsu.get(v)[1];\n      cost += l[b] * a[v];\n      l[b]\
    \ += l[v], a[b] += a[v];\n      pq.push({l[b], a[b], b});\n    } else {\n    \
    \  vis[v] = true, cost += lsum * a[v], lsum += l[v];\n    }\n  }\n\n  return cost;\n\
    }\n"
  code: "//#include<ds/monoidDSU>\n\nstruct min_monoid {\n  using M = array<int, 2>;\n\
    \  static M id() { return {INT_MAX, -1}; }\n  static M op(const M& a, const M&\
    \ b) {\n    return min(a, b);\n  }\n};\n\ntemplate<class T>\nT zero_one_on_tree(vector<vector<int>>\
    \ g, vector<T> l, vector<T> a, int r = 0) {\n  int n = ssize(g);\n\n  vector<int>\
    \ p(n, -1), d(n);\n  {\n    auto dfs = [&](int v, auto &&self) -> void {\n   \
    \   for(int x : g[v]) {\n        if (x == p[v]) continue;\n        d[x] = d[v]\
    \ + 1, p[x] = v;\n        self(x, self);\n      }\n    };\n    dfs(r, dfs);\n\
    \  }\n\n  DSU<min_monoid::M, min_monoid::id, min_monoid::op> dsu([&]() {\n   \
    \ vector<min_monoid::M> init(n);\n    for(int i = 0; i < n; i++)\n      init[i]\
    \ = {d[i], i};\n    return init;\n  }());\n\n  using D = tuple<T, T, int>; //(l_v,\
    \ a_v, v)\n  auto cmp = [](D a, D b) {\n    return get<1>(a) * get<0>(b) < get<0>(a)\
    \ * get<1>(b);\n  };\n  priority_queue<D, vector<D>, decltype(cmp)> pq;\n  for(int\
    \ i = 0; i < n; i++)\n    pq.push({l[i], a[i], i});\n\n  T cost = 0, lsum = 0;\n\
    \  vector<bool> vis(n, false);\n  while(!pq.empty()) {\n    auto [l_v, a_v, v]\
    \ = pq.top(); pq.pop();\n    if (l[v] != l_v or a[v] != a_v) continue;\n    if\
    \ (p[v] != -1 and !vis[dsu.get(p[v])[1]]) {\n      dsu.merge(v, p[v]);\n     \
    \ int b = dsu.get(v)[1];\n      cost += l[b] * a[v];\n      l[b] += l[v], a[b]\
    \ += a[v];\n      pq.push({l[b], a[b], b});\n    } else {\n      vis[v] = true,\
    \ cost += lsum * a[v], lsum += l[v];\n    }\n  }\n\n  return cost;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: ds_problem/zero_one_on_tree.cpp
  requiredBy: []
  timestamp: '2024-10-21 21:31:03+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds_problem/zero_one_on_tree.cpp
layout: document
redirect_from:
- /library/ds_problem/zero_one_on_tree.cpp
- /library/ds_problem/zero_one_on_tree.cpp.html
title: ds_problem/zero_one_on_tree.cpp
---
