---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/jump_on_tree.test.cpp
    title: test/jump_on_tree.test.cpp
  - icon: ':x:'
    path: test/lowest_common_ancestor.test.cpp
    title: test/lowest_common_ancestor.test.cpp
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
  bundledCode: "#line 1 \"ds/fastJump.cpp\"\nstruct fastJump {\n  vector<int> p, jp,\
    \ dep;\n\n  fastJump(vector<vector<int>> g, int root = 0) : p(ssize(g)), jp(ssize(g)),\
    \ dep(ssize(g)) {\n    auto dfs = [&](int v, auto self) -> void {\n      if (dep[p[v]]\
    \ + dep[jp[jp[p[v]]]] == 2 * dep[jp[p[v]]])\n        jp[v] = jp[jp[p[v]]];\n \
    \     else\n        jp[v] = p[v];\n\n      for(int x : g[v]) {\n        if (x\
    \ == p[v]) continue;\n        p[x] = v, dep[x] = dep[v] + 1;\n        self(x,\
    \ self);\n      }\n    };\n\n    p[root] = jp[root] = root;\n    dfs(root, dfs);\n\
    \  }\n\n  int jump(int v, int k) {\n    k = min(k, dep[v]);\n    while(k) {\n\
    \      if (int d = dep[v] - dep[jp[v]]; d <= k)\n        v = jp[v], k -= d;\n\
    \      else\n        v = p[v], k -= 1;\n    }\n    return v;\n  }\n\n  int lca(int\
    \ u, int v) {\n    if (dep[u] < dep[v])\n      swap(u, v);\n    u = jump(u, dep[u]\
    \ - dep[v]);\n    if (u == v) return u;\n    while(p[u] != p[v]) {\n      if (jp[u]\
    \ != jp[v]) u = jp[u], v = jp[v];\n      else u = p[u], v = p[v];\n    }\n   \
    \ return p[u];\n  }\n\n  int kth(int s, int t, int k) {\n    int m = lca(s, t);\n\
    \    if (dep[s] + dep[t] - 2 * dep[m] < k)\n      return -1;\n    else if (dep[s]\
    \ - dep[m] >= k)\n      return jump(s, k);\n    else\n      return jump(t, dep[s]\
    \ + dep[t] - 2 * dep[m] - k);\n  }\n\n  int dis(int u, int v) {\n    return dep[u]\
    \ + dep[v] - 2 * dep[lca(u, v)];\n  }\n};\n"
  code: "struct fastJump {\n  vector<int> p, jp, dep;\n\n  fastJump(vector<vector<int>>\
    \ g, int root = 0) : p(ssize(g)), jp(ssize(g)), dep(ssize(g)) {\n    auto dfs\
    \ = [&](int v, auto self) -> void {\n      if (dep[p[v]] + dep[jp[jp[p[v]]]] ==\
    \ 2 * dep[jp[p[v]]])\n        jp[v] = jp[jp[p[v]]];\n      else\n        jp[v]\
    \ = p[v];\n\n      for(int x : g[v]) {\n        if (x == p[v]) continue;\n   \
    \     p[x] = v, dep[x] = dep[v] + 1;\n        self(x, self);\n      }\n    };\n\
    \n    p[root] = jp[root] = root;\n    dfs(root, dfs);\n  }\n\n  int jump(int v,\
    \ int k) {\n    k = min(k, dep[v]);\n    while(k) {\n      if (int d = dep[v]\
    \ - dep[jp[v]]; d <= k)\n        v = jp[v], k -= d;\n      else\n        v = p[v],\
    \ k -= 1;\n    }\n    return v;\n  }\n\n  int lca(int u, int v) {\n    if (dep[u]\
    \ < dep[v])\n      swap(u, v);\n    u = jump(u, dep[u] - dep[v]);\n    if (u ==\
    \ v) return u;\n    while(p[u] != p[v]) {\n      if (jp[u] != jp[v]) u = jp[u],\
    \ v = jp[v];\n      else u = p[u], v = p[v];\n    }\n    return p[u];\n  }\n\n\
    \  int kth(int s, int t, int k) {\n    int m = lca(s, t);\n    if (dep[s] + dep[t]\
    \ - 2 * dep[m] < k)\n      return -1;\n    else if (dep[s] - dep[m] >= k)\n  \
    \    return jump(s, k);\n    else\n      return jump(t, dep[s] + dep[t] - 2 *\
    \ dep[m] - k);\n  }\n\n  int dis(int u, int v) {\n    return dep[u] + dep[v] -\
    \ 2 * dep[lca(u, v)];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/fastJump.cpp
  requiredBy: []
  timestamp: '2024-02-11 12:51:49+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/vertex_add_range_contour_sum_on_tree.test.cpp
  - test/vertex_get_range_contour_add_on_tree.test.cpp
  - test/lowest_common_ancestor.test.cpp
  - test/jump_on_tree.test.cpp
documentation_of: ds/fastJump.cpp
layout: document
redirect_from:
- /library/ds/fastJump.cpp
- /library/ds/fastJump.cpp.html
title: ds/fastJump.cpp
---
