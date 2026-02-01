---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/frequency_table_of_tree_distance.test.cpp
    title: test/frequency_table_of_tree_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/vertex_add_range_contour_sum_on_tree.test.cpp
    title: test/vertex_add_range_contour_sum_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/vertex_get_range_contour_add_on_tree.test.cpp
    title: test/vertex_get_range_contour_add_on_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/centroid_tree.cpp\"\nauto centroid_tree(vvi &g) {\n\
    \  int n = ssize(g);\n  vvi tr(n);\n  vi sz(n);\n  vc<bool> block(n, false);\n\
    \n  auto calc = [&](int v, int p, auto &self) -> void {\n    sz[v] = 1;\n    for(int\
    \ x : g[v]) {\n      if (x == p or block[x]) continue;\n      self(x, v, self);\n\
    \      sz[v] += sz[x];\n    }\n  };\n\n  auto dfs = [&](int v, auto &self) ->\
    \ int {\n    calc(v, -1, calc);\n\n    int c = v, p = -1;\n    bool move;\n  \
    \  do {\n      move = false;\n      for(int x : g[c]) {\n        if (x == p or\
    \ block[x] or 2 * sz[x] <= sz[v]) continue;\n        move = true, p = c, c = x;\n\
    \        break;\n      }\n    } while(move);\n\n    block[c] = true;\n    for(int\
    \ x : g[c]) {\n      if (block[x]) continue;\n      x = self(x, self);\n     \
    \ tr[c].emplace_back(x);\n      tr[x].emplace_back(c);\n    }\n\n    return c;\n\
    \  };\n\n  int root = dfs(0, dfs);\n\n  return pair(tr, root);\n}\n"
  code: "auto centroid_tree(vvi &g) {\n  int n = ssize(g);\n  vvi tr(n);\n  vi sz(n);\n\
    \  vc<bool> block(n, false);\n\n  auto calc = [&](int v, int p, auto &self) ->\
    \ void {\n    sz[v] = 1;\n    for(int x : g[v]) {\n      if (x == p or block[x])\
    \ continue;\n      self(x, v, self);\n      sz[v] += sz[x];\n    }\n  };\n\n \
    \ auto dfs = [&](int v, auto &self) -> int {\n    calc(v, -1, calc);\n\n    int\
    \ c = v, p = -1;\n    bool move;\n    do {\n      move = false;\n      for(int\
    \ x : g[c]) {\n        if (x == p or block[x] or 2 * sz[x] <= sz[v]) continue;\n\
    \        move = true, p = c, c = x;\n        break;\n      }\n    } while(move);\n\
    \n    block[c] = true;\n    for(int x : g[c]) {\n      if (block[x]) continue;\n\
    \      x = self(x, self);\n      tr[c].emplace_back(x);\n      tr[x].emplace_back(c);\n\
    \    }\n\n    return c;\n  };\n\n  int root = dfs(0, dfs);\n\n  return pair(tr,\
    \ root);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/centroid_tree.cpp
  requiredBy: []
  timestamp: '2026-02-02 01:08:31+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/frequency_table_of_tree_distance.test.cpp
  - test/vertex_add_range_contour_sum_on_tree.test.cpp
  - test/vertex_get_range_contour_add_on_tree.test.cpp
documentation_of: tree/centroid_tree.cpp
layout: document
redirect_from:
- /library/tree/centroid_tree.cpp
- /library/tree/centroid_tree.cpp.html
title: tree/centroid_tree.cpp
---
