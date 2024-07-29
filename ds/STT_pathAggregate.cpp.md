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
  bundledCode: "#line 1 \"ds/STT_pathAggregate.cpp\"\n//#include \"ds/staticTopTree2.cpp\"\
    \n\ntemplate<class M, M(*id)(), M(*op)(const M&, const M&)>\nstruct STT_pathAggregate\
    \ : staticTopTree {\n  vector<M> data;\n  vector<int> dep, head;\n\n  STT_pathAggregate(vector<vector<int>>\
    \ g, vector<M> init = vector<M>())\n  : staticTopTree(g), data(nxt, id()), dep(nxt),\
    \ head(nxt) {\n    head[nxt - 1] = nxt - 1;\n    dfs(nxt - 1);\n    if (!init.empty())\
    \ {\n      for(int v = 0; v < n; v++)\n        data[mp[v]] = init[v];\n      for(int\
    \ v = 0; v < nxt; v++)\n        if (vt[v] == type::Compress)\n          recalc(v);\n\
    \    }\n  }\n\n  void dfs(int v) {\n    if (lc[v] != -1) {\n      dep[lc[v]] =\
    \ dep[v] + 1;\n      head[lc[v]] = vt[v] == type::AddVertex or (vt[v] == type::Rake\
    \ and vt[lc[v]] != type::Rake) ? lc[v] : head[v];\n      dfs(lc[v]);\n    }\n\
    \    if (rc[v] != -1) {\n      dep[rc[v]] = dep[v] + 1;\n      head[rc[v]] = vt[v]\
    \ == type::AddVertex or (vt[v] == type::Rake and vt[rc[v]] != type::Rake) ? rc[v]\
    \ : head[v];\n      dfs(rc[v]);\n    }\n  }\n\n  void recalc(int v) {\n    if\
    \ (rc[v] != -1) data[v] = op(data[lc[v]], data[rc[v]]);\n    else if (lc[v] !=\
    \ -1) data[v] = op(data[lc[v]], data[v]);\n  }\n\n  void pull(int v) {\n    v\
    \ = p[v];\n    while(v != -1 and vt[v] == type::Compress) {\n      data[v] = op(data[lc[v]],\
    \ data[rc[v]]);\n      v = p[v];\n    }\n  }\n\n  void set(int v, M x) { data[mp[v]]\
    \ = x, pull(mp[v]); }\n\n  M levelAggregate(int v) {\n    int x = head[v];\n \
    \   M ret = data[v];\n    while(v != x) {\n      int w = p[v];\n      if (vt[w]\
    \ == type::Compress and rc[w] == v)\n        ret = op(ret, data[lc[w]]);\n   \
    \   v = w;\n    }\n    return ret;\n  }\n\n  M query(int u, int v) {\n    u =\
    \ mp[u], v = mp[v];\n    M ret = id();\n    while(head[u] != head[v]) {\n    \
    \  if (dep[head[u]] > dep[head[v]])\n        ret = op(ret, levelAggregate(u)),\
    \ u = p[head[u]];\n      else\n        ret = op(ret, levelAggregate(v)), v = p[head[v]];\n\
    \    }\n    if (vt[head[u]] == type::Rake) return op(ret, data[p[head[u]]]);\n\
    \    if (u == v) return op(ret, data[u]);\n    if (u > v) swap(u, v);\n    ret\
    \ = op(ret, op(data[u], data[v]));\n    while(p[u] != p[v]) {\n      if (dep[u]\
    \ > dep[v]) {\n        int w = p[u];\n        if (lc[w] == u and rc[w] != -1)\n\
    \          ret = op(ret, data[rc[w]]);\n        u = w;\n      } else {\n     \
    \   int w = p[v];\n        if (rc[w] == v)\n          ret = op(ret, data[lc[w]]);\n\
    \        v = w;\n      }\n    }\n    return ret;\n  }\n};\n"
  code: "//#include \"ds/staticTopTree2.cpp\"\n\ntemplate<class M, M(*id)(), M(*op)(const\
    \ M&, const M&)>\nstruct STT_pathAggregate : staticTopTree {\n  vector<M> data;\n\
    \  vector<int> dep, head;\n\n  STT_pathAggregate(vector<vector<int>> g, vector<M>\
    \ init = vector<M>())\n  : staticTopTree(g), data(nxt, id()), dep(nxt), head(nxt)\
    \ {\n    head[nxt - 1] = nxt - 1;\n    dfs(nxt - 1);\n    if (!init.empty()) {\n\
    \      for(int v = 0; v < n; v++)\n        data[mp[v]] = init[v];\n      for(int\
    \ v = 0; v < nxt; v++)\n        if (vt[v] == type::Compress)\n          recalc(v);\n\
    \    }\n  }\n\n  void dfs(int v) {\n    if (lc[v] != -1) {\n      dep[lc[v]] =\
    \ dep[v] + 1;\n      head[lc[v]] = vt[v] == type::AddVertex or (vt[v] == type::Rake\
    \ and vt[lc[v]] != type::Rake) ? lc[v] : head[v];\n      dfs(lc[v]);\n    }\n\
    \    if (rc[v] != -1) {\n      dep[rc[v]] = dep[v] + 1;\n      head[rc[v]] = vt[v]\
    \ == type::AddVertex or (vt[v] == type::Rake and vt[rc[v]] != type::Rake) ? rc[v]\
    \ : head[v];\n      dfs(rc[v]);\n    }\n  }\n\n  void recalc(int v) {\n    if\
    \ (rc[v] != -1) data[v] = op(data[lc[v]], data[rc[v]]);\n    else if (lc[v] !=\
    \ -1) data[v] = op(data[lc[v]], data[v]);\n  }\n\n  void pull(int v) {\n    v\
    \ = p[v];\n    while(v != -1 and vt[v] == type::Compress) {\n      data[v] = op(data[lc[v]],\
    \ data[rc[v]]);\n      v = p[v];\n    }\n  }\n\n  void set(int v, M x) { data[mp[v]]\
    \ = x, pull(mp[v]); }\n\n  M levelAggregate(int v) {\n    int x = head[v];\n \
    \   M ret = data[v];\n    while(v != x) {\n      int w = p[v];\n      if (vt[w]\
    \ == type::Compress and rc[w] == v)\n        ret = op(ret, data[lc[w]]);\n   \
    \   v = w;\n    }\n    return ret;\n  }\n\n  M query(int u, int v) {\n    u =\
    \ mp[u], v = mp[v];\n    M ret = id();\n    while(head[u] != head[v]) {\n    \
    \  if (dep[head[u]] > dep[head[v]])\n        ret = op(ret, levelAggregate(u)),\
    \ u = p[head[u]];\n      else\n        ret = op(ret, levelAggregate(v)), v = p[head[v]];\n\
    \    }\n    if (vt[head[u]] == type::Rake) return op(ret, data[p[head[u]]]);\n\
    \    if (u == v) return op(ret, data[u]);\n    if (u > v) swap(u, v);\n    ret\
    \ = op(ret, op(data[u], data[v]));\n    while(p[u] != p[v]) {\n      if (dep[u]\
    \ > dep[v]) {\n        int w = p[u];\n        if (lc[w] == u and rc[w] != -1)\n\
    \          ret = op(ret, data[rc[w]]);\n        u = w;\n      } else {\n     \
    \   int w = p[v];\n        if (rc[w] == v)\n          ret = op(ret, data[lc[w]]);\n\
    \        v = w;\n      }\n    }\n    return ret;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/STT_pathAggregate.cpp
  requiredBy: []
  timestamp: '2024-07-30 00:39:06+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/vertex_add_path_sum_2.test.cpp
documentation_of: ds/STT_pathAggregate.cpp
layout: document
redirect_from:
- /library/ds/STT_pathAggregate.cpp
- /library/ds/STT_pathAggregate.cpp.html
title: ds/STT_pathAggregate.cpp
---
