---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: test/point_set_tree_path_composite_sum_fixed_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/staticTopTree.cpp\"\n//rake keep left child as exposed\
    \ path\n//compress keep left child as higher path\nstruct static_top_tree {\n\
    \  vector<vector<int>> g;\n  int n;\n  vector<int> l, r, lc, rc, pa;\n  vector<bool>\
    \ rake;\n\n  using a2 = array<int, 2>;\n\n  static_top_tree(vector<vector<int>>\
    \ &_g, int R = 0)\n    : g(_g), n(size(g)), l(n, -1), r(l), lc(l), rc(l), pa(l),\
    \ rake(n) {\n    vector<int> sz(n, 1);\n    auto dfs = [&](int v, int p, auto\
    \ &self) -> void {\n      l[v] = v, r[v] = p;\n      int mx_c = -1;\n      for(int\
    \ x : g[v]) {\n        if (x == p) continue;\n        self(x, v, self);\n    \
    \    sz[v] += sz[x];\n        if (mx_c == -1 or sz[x] > sz[mx_c])\n          mx_c\
    \ = x;\n      }\n      if (auto ite = ranges::find(g[v], p); ite != g[v].end())\n\
    \        g[v].erase(ite);\n      if (mx_c != -1)\n        swap(g[v][0], *ranges::find(g[v],\
    \ mx_c));\n    };\n\n    dfs(R, -1, dfs);\n    build(R);\n  }\n\n  int new_node(int\
    \ _lc, int _rc, int _l, int _r, bool _rake) {\n    lc.eb(_lc), rc.eb(_rc), l.eb(_l),\
    \ r.eb(_r), pa.eb(-1), rake.eb(_rake);\n    return pa[_lc] = pa[_rc] = ssize(lc)\
    \ - 1;\n  }\n\n  a2 build(int s) {\n    vector<int> path = {s};\n    while(!g[path.back()].empty())\n\
    \      path.eb(g[path.back()][0]);\n    vector<a2> exposed = {{0, s}};\n    for(int\
    \ i = 0; int v : path | views::drop(1)) {\n      priority_queue<a2, vector<a2>,\
    \ greater<a2>> pq;\n      pq.push({0, v});\n      for(int x : g[path[i++]] | views::drop(1))\n\
    \        pq.push(build(x));\n      while(ssize(pq) > 1) {\n        auto [h1, v1]\
    \ = pq.top(); pq.pop();\n        auto [h2, v2] = pq.top(); pq.pop();\n       \
    \ if (v2 == v) swap(v1, v2);\n        int v3 = new_node(v1, v2, l[v1], r[v1],\
    \ true);\n        pq.push({max(h1, h2) + 1, v3});\n        if (v1 == v) v = v3;\n\
    \      }\n      exposed.eb(pq.top());\n    }\n    auto dc = [&](int ql, int qr,\
    \ auto &self) -> a2 {\n      if (ql + 1 == qr) return exposed[ql];\n      int\
    \ mid = (ql + qr) / 2;\n      auto [hl, vl] = self(ql, mid, self);\n      auto\
    \ [hr, vr] = self(mid, qr, self);\n      int v = new_node(vl, vr, l[vr], r[vl],\
    \ false);\n      return {max(hl, hr) + 1, v};\n    };\n    return dc(0, ssize(exposed),\
    \ dc);\n  }\n};\n"
  code: "//rake keep left child as exposed path\n//compress keep left child as higher\
    \ path\nstruct static_top_tree {\n  vector<vector<int>> g;\n  int n;\n  vector<int>\
    \ l, r, lc, rc, pa;\n  vector<bool> rake;\n\n  using a2 = array<int, 2>;\n\n \
    \ static_top_tree(vector<vector<int>> &_g, int R = 0)\n    : g(_g), n(size(g)),\
    \ l(n, -1), r(l), lc(l), rc(l), pa(l), rake(n) {\n    vector<int> sz(n, 1);\n\
    \    auto dfs = [&](int v, int p, auto &self) -> void {\n      l[v] = v, r[v]\
    \ = p;\n      int mx_c = -1;\n      for(int x : g[v]) {\n        if (x == p) continue;\n\
    \        self(x, v, self);\n        sz[v] += sz[x];\n        if (mx_c == -1 or\
    \ sz[x] > sz[mx_c])\n          mx_c = x;\n      }\n      if (auto ite = ranges::find(g[v],\
    \ p); ite != g[v].end())\n        g[v].erase(ite);\n      if (mx_c != -1)\n  \
    \      swap(g[v][0], *ranges::find(g[v], mx_c));\n    };\n\n    dfs(R, -1, dfs);\n\
    \    build(R);\n  }\n\n  int new_node(int _lc, int _rc, int _l, int _r, bool _rake)\
    \ {\n    lc.eb(_lc), rc.eb(_rc), l.eb(_l), r.eb(_r), pa.eb(-1), rake.eb(_rake);\n\
    \    return pa[_lc] = pa[_rc] = ssize(lc) - 1;\n  }\n\n  a2 build(int s) {\n \
    \   vector<int> path = {s};\n    while(!g[path.back()].empty())\n      path.eb(g[path.back()][0]);\n\
    \    vector<a2> exposed = {{0, s}};\n    for(int i = 0; int v : path | views::drop(1))\
    \ {\n      priority_queue<a2, vector<a2>, greater<a2>> pq;\n      pq.push({0,\
    \ v});\n      for(int x : g[path[i++]] | views::drop(1))\n        pq.push(build(x));\n\
    \      while(ssize(pq) > 1) {\n        auto [h1, v1] = pq.top(); pq.pop();\n \
    \       auto [h2, v2] = pq.top(); pq.pop();\n        if (v2 == v) swap(v1, v2);\n\
    \        int v3 = new_node(v1, v2, l[v1], r[v1], true);\n        pq.push({max(h1,\
    \ h2) + 1, v3});\n        if (v1 == v) v = v3;\n      }\n      exposed.eb(pq.top());\n\
    \    }\n    auto dc = [&](int ql, int qr, auto &self) -> a2 {\n      if (ql +\
    \ 1 == qr) return exposed[ql];\n      int mid = (ql + qr) / 2;\n      auto [hl,\
    \ vl] = self(ql, mid, self);\n      auto [hr, vr] = self(mid, qr, self);\n   \
    \   int v = new_node(vl, vr, l[vr], r[vl], false);\n      return {max(hl, hr)\
    \ + 1, v};\n    };\n    return dc(0, ssize(exposed), dc);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/staticTopTree.cpp
  requiredBy: []
  timestamp: '2026-01-30 20:10:19+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/point_set_tree_path_composite_sum_fixed_root.test.cpp
documentation_of: tree/staticTopTree.cpp
layout: document
redirect_from:
- /library/tree/staticTopTree.cpp
- /library/tree/staticTopTree.cpp.html
title: tree/staticTopTree.cpp
---
