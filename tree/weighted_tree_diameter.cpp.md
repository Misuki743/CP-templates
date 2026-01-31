---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree_diameter.test.cpp
    title: test/tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/weighted_tree_diameter.cpp\"\ntemplate<integral T>\n\
    auto weighted_tree_diameter(vc<tuple<int, int, T>> &e) {\n  const int n = ssize(e)\
    \ + 1;\n  constexpr T NINF = numeric_limits<T>::min();\n\n  vi adj0(n), d0(n);\n\
    \  vc<T> w0(n);\n  for(auto [u, v, w] : e) {\n    adj0[u] ^= v, adj0[v] ^= u;\n\
    \    d0[u]++, d0[v]++;\n    w0[u] ^= w, w0[v] ^= w;\n  }\n\n  auto xor_link_traversal\
    \ = [&](int s) {\n    vi adj = adj0, d = d0, p(n, -1), ord;\n    vc<T> w = w0;\n\
    \n    d[s] = 0;\n    ord.reserve(n);\n    for(int i = 0; i < n; i++) {\n     \
    \ int v = i;\n      while(d[v] == 1) {\n        ord.emplace_back(v);\n       \
    \ p[v] = adj[v], d[v] = 0, d[p[v]]--;\n        adj[p[v]] ^= v, w[p[v]] ^= w[v];\n\
    \        v = p[v];\n      }\n    }\n\n    auto far = pair(NINF, -1);\n    for(int\
    \ v : ord | views::reverse) {\n      w[v] += w[p[v]];\n      if (w[v] > far.first)\n\
    \        far = pair(w[v], v);\n    }\n\n    return pair(far, p);\n  };\n\n  int\
    \ u = xor_link_traversal(0).first.second;\n  auto [far, p] = xor_link_traversal(u);\n\
    \  auto [diameter, v] = far;\n  vi path = {v};\n  while(path.back() != u)\n  \
    \  path.emplace_back(p[path.back()]);\n\n  return pair(diameter, path);\n}\n"
  code: "template<integral T>\nauto weighted_tree_diameter(vc<tuple<int, int, T>>\
    \ &e) {\n  const int n = ssize(e) + 1;\n  constexpr T NINF = numeric_limits<T>::min();\n\
    \n  vi adj0(n), d0(n);\n  vc<T> w0(n);\n  for(auto [u, v, w] : e) {\n    adj0[u]\
    \ ^= v, adj0[v] ^= u;\n    d0[u]++, d0[v]++;\n    w0[u] ^= w, w0[v] ^= w;\n  }\n\
    \n  auto xor_link_traversal = [&](int s) {\n    vi adj = adj0, d = d0, p(n, -1),\
    \ ord;\n    vc<T> w = w0;\n\n    d[s] = 0;\n    ord.reserve(n);\n    for(int i\
    \ = 0; i < n; i++) {\n      int v = i;\n      while(d[v] == 1) {\n        ord.emplace_back(v);\n\
    \        p[v] = adj[v], d[v] = 0, d[p[v]]--;\n        adj[p[v]] ^= v, w[p[v]]\
    \ ^= w[v];\n        v = p[v];\n      }\n    }\n\n    auto far = pair(NINF, -1);\n\
    \    for(int v : ord | views::reverse) {\n      w[v] += w[p[v]];\n      if (w[v]\
    \ > far.first)\n        far = pair(w[v], v);\n    }\n\n    return pair(far, p);\n\
    \  };\n\n  int u = xor_link_traversal(0).first.second;\n  auto [far, p] = xor_link_traversal(u);\n\
    \  auto [diameter, v] = far;\n  vi path = {v};\n  while(path.back() != u)\n  \
    \  path.emplace_back(p[path.back()]);\n\n  return pair(diameter, path);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/weighted_tree_diameter.cpp
  requiredBy: []
  timestamp: '2026-02-01 03:02:17+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree_diameter.test.cpp
documentation_of: tree/weighted_tree_diameter.cpp
layout: document
redirect_from:
- /library/tree/weighted_tree_diameter.cpp
- /library/tree/weighted_tree_diameter.cpp.html
title: tree/weighted_tree_diameter.cpp
---
