---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/vertex_add_path_sum_2.test.cpp
    title: test/vertex_add_path_sum_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/staticTopTree2.cpp\"\nstruct staticTopTree {\n  enum\
    \ type { AddVertex, Rake, Compress };\n\n  vector<vector<int>> g;\n  int n, nxt;\n\
    \  vector<int> lc, rc, p, vt, mp;\n\n  staticTopTree(vector<vector<int>> _g) :\
    \ n(size(_g)), nxt(0),\n  lc(2 * n, -1), rc(2 * n, -1), p(2 * n, -1), vt(2 * n),\
    \ mp(n) {\n    g.swap(_g);\n    dfs(0, -1);\n    compress(0);\n    g.swap(_g);\n\
    \  }\n\n  int dfs(int v, int p) {\n    int sz = 1, mx = 0;\n    for(int &x : g[v])\
    \ {\n      if (x == p) swap(x, g[v].back());\n      if (x == p) continue;\n  \
    \    int c = dfs(x, v);\n      sz += c;\n      if (chmax(mx, c)) swap(x, g[v][0]);\n\
    \    }\n    if (!g[v].empty() and g[v].back() == p) g[v].pop_back();\n    return\
    \ sz;\n  }\n\n  void allocate(int v, int l, int r, type t) {\n    if (l != -1)\
    \ p[l] = v, lc[v] = l;\n    if (r != -1) p[r] = v, rc[v] = r;\n    vt[v] = t;\n\
    \  }\n\n  pii merge(vector<pii> &vs, type t) {\n    if (size(vs) == 1) return\
    \ vs[0];\n    int szSum = 0, i = 0, pre = 0;\n    for(auto [_, sz] : vs) szSum\
    \ += sz;\n    while(i + 1 < ssize(vs) and 2 * pre <= szSum) pre += vs[i++].second;\n\
    \    vector lv(vs.begin(), vs.begin() + i), rv(vs.begin() + i, vs.end());\n  \
    \  auto [l, lsz] = merge(lv, t);\n    auto [r, rsz] = merge(rv, t);\n    allocate(nxt,\
    \ l, r, t);\n    return {nxt++, lsz + rsz + 1};\n  }\n\n  pii compress(int v)\
    \ {\n    vector vs(1, addVertex(v));\n    while(!g[v].empty())\n      vs.emplace_back(addVertex(v\
    \ = g[v][0]));\n    return merge(vs, type::Compress);\n  }\n\n  pii addVertex(int\
    \ v) {\n    auto [l, lsz] = rake(v);\n    allocate(nxt, l, -1, type::AddVertex);\n\
    \    mp[v] = nxt;\n    return {nxt++, lsz + 1};\n  }\n\n  pii rake(int v) {\n\
    \    if (ssize(g[v]) <= 1) return {-1, 0};\n    vector<pii> vs;\n    for(int x\
    \ : g[v] | views::drop(1))\n      vs.emplace_back(compress(x));\n    return merge(vs,\
    \ type::Rake);\n  }\n};\n"
  code: "struct staticTopTree {\n  enum type { AddVertex, Rake, Compress };\n\n  vector<vector<int>>\
    \ g;\n  int n, nxt;\n  vector<int> lc, rc, p, vt, mp;\n\n  staticTopTree(vector<vector<int>>\
    \ _g) : n(size(_g)), nxt(0),\n  lc(2 * n, -1), rc(2 * n, -1), p(2 * n, -1), vt(2\
    \ * n), mp(n) {\n    g.swap(_g);\n    dfs(0, -1);\n    compress(0);\n    g.swap(_g);\n\
    \  }\n\n  int dfs(int v, int p) {\n    int sz = 1, mx = 0;\n    for(int &x : g[v])\
    \ {\n      if (x == p) swap(x, g[v].back());\n      if (x == p) continue;\n  \
    \    int c = dfs(x, v);\n      sz += c;\n      if (chmax(mx, c)) swap(x, g[v][0]);\n\
    \    }\n    if (!g[v].empty() and g[v].back() == p) g[v].pop_back();\n    return\
    \ sz;\n  }\n\n  void allocate(int v, int l, int r, type t) {\n    if (l != -1)\
    \ p[l] = v, lc[v] = l;\n    if (r != -1) p[r] = v, rc[v] = r;\n    vt[v] = t;\n\
    \  }\n\n  pii merge(vector<pii> &vs, type t) {\n    if (size(vs) == 1) return\
    \ vs[0];\n    int szSum = 0, i = 0, pre = 0;\n    for(auto [_, sz] : vs) szSum\
    \ += sz;\n    while(i + 1 < ssize(vs) and 2 * pre <= szSum) pre += vs[i++].second;\n\
    \    vector lv(vs.begin(), vs.begin() + i), rv(vs.begin() + i, vs.end());\n  \
    \  auto [l, lsz] = merge(lv, t);\n    auto [r, rsz] = merge(rv, t);\n    allocate(nxt,\
    \ l, r, t);\n    return {nxt++, lsz + rsz + 1};\n  }\n\n  pii compress(int v)\
    \ {\n    vector vs(1, addVertex(v));\n    while(!g[v].empty())\n      vs.emplace_back(addVertex(v\
    \ = g[v][0]));\n    return merge(vs, type::Compress);\n  }\n\n  pii addVertex(int\
    \ v) {\n    auto [l, lsz] = rake(v);\n    allocate(nxt, l, -1, type::AddVertex);\n\
    \    mp[v] = nxt;\n    return {nxt++, lsz + 1};\n  }\n\n  pii rake(int v) {\n\
    \    if (ssize(g[v]) <= 1) return {-1, 0};\n    vector<pii> vs;\n    for(int x\
    \ : g[v] | views::drop(1))\n      vs.emplace_back(compress(x));\n    return merge(vs,\
    \ type::Rake);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/staticTopTree2.cpp
  requiredBy: []
  timestamp: '2024-07-30 15:37:30+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/vertex_add_path_sum_2.test.cpp
documentation_of: ds/staticTopTree2.cpp
layout: document
redirect_from:
- /library/ds/staticTopTree2.cpp
- /library/ds/staticTopTree2.cpp.html
title: ds/staticTopTree2.cpp
---
