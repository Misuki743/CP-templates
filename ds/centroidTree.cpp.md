---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/frequency_table_of_tree_distance.test.cpp
    title: test/frequency_table_of_tree_distance.test.cpp
  - icon: ':x:'
    path: test/vertex_add_range_contour_sum_on_tree.test.cpp
    title: test/vertex_add_range_contour_sum_on_tree.test.cpp
  - icon: ':x:'
    path: test/vertex_get_range_contour_add_on_tree.test.cpp
    title: test/vertex_get_range_contour_add_on_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/centroidTree.cpp\"\npair<vector<vector<int>>, int> centroidTree(vector<vector<int>>\
    \ &g) {\n  int n = ssize(g);\n  vector<vector<int>> g2(n);\n  vector<int> sz(n);\n\
    \  vector<bool> block(n, false);\n\n  auto calc = [&](int v, int p, auto self)\
    \ -> void {\n    sz[v] = 1;\n    for(int x : g[v]) {\n      if (x == p or block[x])\
    \ continue;\n      self(x, v, self);\n      sz[v] += sz[x];\n    }\n  };\n\n \
    \ auto dfs = [&](int v, auto self) -> int {\n    calc(v, -1, calc);\n\n    int\
    \ c = v, p = -1;\n    bool move;\n    do {\n      move = false;\n      for(int\
    \ x : g[c]) {\n        if (x == p or block[x] or 2 * sz[x] <= sz[v]) continue;\n\
    \        move = true, p = c, c = x;\n        break;\n      }\n    } while(move);\n\
    \n    block[c] = true;\n    for(int x : g[c]) {\n      if (block[x]) continue;\n\
    \      x = self(x, self);\n      g2[c].emplace_back(x);\n      g2[x].emplace_back(c);\n\
    \    }\n\n    return c;\n  };\n\n  int root = dfs(0, dfs);\n\n  return make_pair(g2,\
    \ root);\n}\n"
  code: "pair<vector<vector<int>>, int> centroidTree(vector<vector<int>> &g) {\n \
    \ int n = ssize(g);\n  vector<vector<int>> g2(n);\n  vector<int> sz(n);\n  vector<bool>\
    \ block(n, false);\n\n  auto calc = [&](int v, int p, auto self) -> void {\n \
    \   sz[v] = 1;\n    for(int x : g[v]) {\n      if (x == p or block[x]) continue;\n\
    \      self(x, v, self);\n      sz[v] += sz[x];\n    }\n  };\n\n  auto dfs = [&](int\
    \ v, auto self) -> int {\n    calc(v, -1, calc);\n\n    int c = v, p = -1;\n \
    \   bool move;\n    do {\n      move = false;\n      for(int x : g[c]) {\n   \
    \     if (x == p or block[x] or 2 * sz[x] <= sz[v]) continue;\n        move =\
    \ true, p = c, c = x;\n        break;\n      }\n    } while(move);\n\n    block[c]\
    \ = true;\n    for(int x : g[c]) {\n      if (block[x]) continue;\n      x = self(x,\
    \ self);\n      g2[c].emplace_back(x);\n      g2[x].emplace_back(c);\n    }\n\n\
    \    return c;\n  };\n\n  int root = dfs(0, dfs);\n\n  return make_pair(g2, root);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/centroidTree.cpp
  requiredBy: []
  timestamp: '2024-02-10 22:33:36+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/frequency_table_of_tree_distance.test.cpp
  - test/vertex_add_range_contour_sum_on_tree.test.cpp
  - test/vertex_get_range_contour_add_on_tree.test.cpp
documentation_of: ds/centroidTree.cpp
layout: document
redirect_from:
- /library/ds/centroidTree.cpp
- /library/ds/centroidTree.cpp.html
title: ds/centroidTree.cpp
---
