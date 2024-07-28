---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: test/point_set_tree_path_composite_sum_fixed_root.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/staticTopTree.cpp\"\nstruct staticTopTree {\n  enum type\
    \ { Vertex, Compress, Rake, AddEdge, AddVertex};\n\n  vector<vector<int>> g;\n\
    \  int stt_rt, n;\n  vector<int> lc, rc, p, ord;\n  vector<type> vt;\n  int nxt;\n\
    \n  staticTopTree(vector<vector<int>> _g, int root = 0) : n(size(_g)),\n  lc(4\
    \ * n, -1), rc(4 * n, -1), p(4 * n, -1), vt(4 * n, type::Vertex), nxt(2 * n) {\n\
    \    g.swap(_g);\n    dfs(root, -1);\n    stt_rt = rake(root).first;\n    g.swap(_g);\n\
    \  }\n\n  int dfs(int v, int p) {\n    int sz = 1, pid = -1;\n    pii heavy(-1,\
    \ -1);\n    for(int i = -1; int x : g[v]) {\n      i++;\n      if (x == p) {\n\
    \        pid = i;\n        continue;\n      }\n      int tmp = dfs(x, v);\n  \
    \    chmax(heavy, pii(tmp, i));\n      sz += tmp;\n    }\n    if (heavy.second\
    \ != -1) swap(g[v][heavy.second], g[v][0]);\n    if (pid != -1) g[v].erase(g[v].begin()\
    \ + (pid == 0 and heavy.second != -1 ? heavy.second : pid));\n    return sz;\n\
    \  }\n\n  void newVertex(int l, int r, type t) {\n    if (l != -1) p[l] = nxt,\
    \ lc[nxt] = l;\n    if (r != -1) p[r] = nxt, rc[nxt] = r;\n    ord.emplace_back(nxt);\n\
    \    vt[nxt++] = t;\n  }\n\n  void setVertex(int l, int r, int v, type t) {\n\
    \    if (l != -1) p[l] = v, lc[v] = l;\n    if (r != -1) p[r] = v, rc[v] = r;\n\
    \    ord.emplace_back(v);\n    vt[v] = t;\n  }\n\n  pii merge(vector<pii> &vs,\
    \ type t, int v = -1) {\n    if (size(vs) == 1) return vs[0];\n    int szSum =\
    \ 0;\n    for(auto [_, sz] : vs) szSum += sz;\n    int i = 0, pre = 0;\n    while(i\
    \ + 1 < ssize(vs) and 2 * pre <= szSum) pre += vs[i++].second;\n    vector<pii>\
    \ lv(vs.begin(), vs.begin() + i), rv(vs.begin() + i, vs.end());\n    auto [l,\
    \ lsz] = merge(lv, t);\n    auto [r, rsz] = merge(rv, t);\n    if (v == -1) {\n\
    \      newVertex(l, r, t);\n      return {nxt - 1, lsz + rsz + 1};\n    } else\
    \ {\n      setVertex(l, r, v, t);\n      return {v, lsz + rsz + 1};\n    }\n \
    \ }\n\n  pii rake(int v) {\n    vector<pii> vs(1, addEdge(v));\n    while(!g[v].empty())\
    \ \n      vs.emplace_back(addEdge(v = g[v][0]));\n    return merge(vs, type::Rake);\n\
    \  }\n\n  pii addEdge(int v) {\n    auto [l, lsz] = addVertex(v);\n    setVertex(l,\
    \ -1, v + n, type::AddEdge);\n    return {v + n, lsz + 1};\n  }\n\n  pii addVertex(int\
    \ v) {\n    if (ssize(g[v]) <= 1) {\n      setVertex(-1, -1, v, type::Vertex);\n\
    \      return {v, 1};\n    } else {\n      auto [l, lsz] = compress(v);\n    \
    \  setVertex(l, -1, v, type::AddVertex);\n      return {v, lsz + 1};\n    }\n\
    \  }\n\n  pii compress(int v) {\n    vector<pii> vs;\n    for(int x : g[v] | views::drop(1))\n\
    \      vs.emplace_back(rake(x));\n    return merge(vs, type::Compress);\n  }\n\
    };\n"
  code: "struct staticTopTree {\n  enum type { Vertex, Compress, Rake, AddEdge, AddVertex};\n\
    \n  vector<vector<int>> g;\n  int stt_rt, n;\n  vector<int> lc, rc, p, ord;\n\
    \  vector<type> vt;\n  int nxt;\n\n  staticTopTree(vector<vector<int>> _g, int\
    \ root = 0) : n(size(_g)),\n  lc(4 * n, -1), rc(4 * n, -1), p(4 * n, -1), vt(4\
    \ * n, type::Vertex), nxt(2 * n) {\n    g.swap(_g);\n    dfs(root, -1);\n    stt_rt\
    \ = rake(root).first;\n    g.swap(_g);\n  }\n\n  int dfs(int v, int p) {\n   \
    \ int sz = 1, pid = -1;\n    pii heavy(-1, -1);\n    for(int i = -1; int x : g[v])\
    \ {\n      i++;\n      if (x == p) {\n        pid = i;\n        continue;\n  \
    \    }\n      int tmp = dfs(x, v);\n      chmax(heavy, pii(tmp, i));\n      sz\
    \ += tmp;\n    }\n    if (heavy.second != -1) swap(g[v][heavy.second], g[v][0]);\n\
    \    if (pid != -1) g[v].erase(g[v].begin() + (pid == 0 and heavy.second != -1\
    \ ? heavy.second : pid));\n    return sz;\n  }\n\n  void newVertex(int l, int\
    \ r, type t) {\n    if (l != -1) p[l] = nxt, lc[nxt] = l;\n    if (r != -1) p[r]\
    \ = nxt, rc[nxt] = r;\n    ord.emplace_back(nxt);\n    vt[nxt++] = t;\n  }\n\n\
    \  void setVertex(int l, int r, int v, type t) {\n    if (l != -1) p[l] = v, lc[v]\
    \ = l;\n    if (r != -1) p[r] = v, rc[v] = r;\n    ord.emplace_back(v);\n    vt[v]\
    \ = t;\n  }\n\n  pii merge(vector<pii> &vs, type t, int v = -1) {\n    if (size(vs)\
    \ == 1) return vs[0];\n    int szSum = 0;\n    for(auto [_, sz] : vs) szSum +=\
    \ sz;\n    int i = 0, pre = 0;\n    while(i + 1 < ssize(vs) and 2 * pre <= szSum)\
    \ pre += vs[i++].second;\n    vector<pii> lv(vs.begin(), vs.begin() + i), rv(vs.begin()\
    \ + i, vs.end());\n    auto [l, lsz] = merge(lv, t);\n    auto [r, rsz] = merge(rv,\
    \ t);\n    if (v == -1) {\n      newVertex(l, r, t);\n      return {nxt - 1, lsz\
    \ + rsz + 1};\n    } else {\n      setVertex(l, r, v, t);\n      return {v, lsz\
    \ + rsz + 1};\n    }\n  }\n\n  pii rake(int v) {\n    vector<pii> vs(1, addEdge(v));\n\
    \    while(!g[v].empty()) \n      vs.emplace_back(addEdge(v = g[v][0]));\n   \
    \ return merge(vs, type::Rake);\n  }\n\n  pii addEdge(int v) {\n    auto [l, lsz]\
    \ = addVertex(v);\n    setVertex(l, -1, v + n, type::AddEdge);\n    return {v\
    \ + n, lsz + 1};\n  }\n\n  pii addVertex(int v) {\n    if (ssize(g[v]) <= 1) {\n\
    \      setVertex(-1, -1, v, type::Vertex);\n      return {v, 1};\n    } else {\n\
    \      auto [l, lsz] = compress(v);\n      setVertex(l, -1, v, type::AddVertex);\n\
    \      return {v, lsz + 1};\n    }\n  }\n\n  pii compress(int v) {\n    vector<pii>\
    \ vs;\n    for(int x : g[v] | views::drop(1))\n      vs.emplace_back(rake(x));\n\
    \    return merge(vs, type::Compress);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/staticTopTree.cpp
  requiredBy: []
  timestamp: '2024-07-28 21:04:51+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/point_set_tree_path_composite_sum_fixed_root.test.cpp
documentation_of: ds/staticTopTree.cpp
layout: document
redirect_from:
- /library/ds/staticTopTree.cpp
- /library/ds/staticTopTree.cpp.html
title: ds/staticTopTree.cpp
---
