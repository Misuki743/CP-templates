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
  bundledCode: "#line 1 \"tree/STT_pathAggregate.cpp\"\n//#include \"ds/staticTopTree2.cpp\"\
    \n\ntemplate<class M, M(*id)(), M(*op)(const M&, const M&)>\nstruct STT_pathAggregate\
    \ : staticTopTree {\n  vector<M> data;\n  vector<int> dep, head;\n\n  STT_pathAggregate(vector<vector<int>>\
    \ g, vector<M> init = vector<M>())\n  : staticTopTree(g), data(nxt, id()), dep(nxt),\
    \ head(nxt) {\n    head[nxt - 1] = nxt - 1;\n    dfs(nxt - 1);\n    if (!init.empty())\
    \ {\n      for(int v = 0; v < n; v++)\n        data[mp[v]] = init[v];\n      for(int\
    \ v = 0; v < nxt; v++)\n        if (vt[v] == type::Compress)\n          data[v]\
    \ = op(data[lc[v]], data[rc[v]]);\n    }\n  }\n\n  void dfs(int v) {\n    for(int\
    \ c : {lc[v], rc[v]}) if (c != -1) {\n      dep[c] = dep[v] + 1;\n      head[c]\
    \ = vt[v] == type::AddVertex or (vt[v] == type::Rake and vt[c] != type::Rake)\
    \ ? c : head[v];\n      dfs(c);\n    }\n  }\n\n  void pull(int v) {\n    v = p[v];\n\
    \    while(v != -1 and vt[v] == type::Compress) {\n      data[v] = op(data[lc[v]],\
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
    \ v = 0; v < nxt; v++)\n        if (vt[v] == type::Compress)\n          data[v]\
    \ = op(data[lc[v]], data[rc[v]]);\n    }\n  }\n\n  void dfs(int v) {\n    for(int\
    \ c : {lc[v], rc[v]}) if (c != -1) {\n      dep[c] = dep[v] + 1;\n      head[c]\
    \ = vt[v] == type::AddVertex or (vt[v] == type::Rake and vt[c] != type::Rake)\
    \ ? c : head[v];\n      dfs(c);\n    }\n  }\n\n  void pull(int v) {\n    v = p[v];\n\
    \    while(v != -1 and vt[v] == type::Compress) {\n      data[v] = op(data[lc[v]],\
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
  path: tree/STT_pathAggregate.cpp
  requiredBy: []
  timestamp: '2026-01-30 20:10:19+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/STT_pathAggregate.cpp
layout: document
redirect_from:
- /library/tree/STT_pathAggregate.cpp
- /library/tree/STT_pathAggregate.cpp.html
title: tree/STT_pathAggregate.cpp
---
