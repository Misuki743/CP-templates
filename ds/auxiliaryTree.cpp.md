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
  bundledCode: "#line 1 \"ds/auxiliaryTree.cpp\"\n//#include<ds/fastJump.cpp>\n\n\
    pair<vector<vector<int>>, vector<int>> virtualTree(vector<vector<int>> g, vector<int>\
    \ c) {\n  int n = ssize(g), nxt = ssize(g);\n  fastJump fj(g);\n  vector<vector<int>>\
    \ stk(n), res(2 * n - 1);\n  vector<int> mp(2 * n - 1);\n  iota(mp.begin(), mp.begin()\
    \ + n, 0);\n  auto addEdge = [&](int u, int v) {\n    res[u].emplace_back(v);\n\
    \    res[v].emplace_back(u);\n  };\n  auto dfs = [&](int v, int p, auto self)\
    \ -> void {\n    if (auto &stkV = stk[c[v]]; stkV.empty() or fj.lca(mp[stkV.back()],\
    \ v) == mp[stkV.back()]) {\n      stkV.emplace_back(v);\n    } else {\n      int\
    \ x = fj.lca(mp[stkV.back()], v);\n      while(ssize(stkV) > 1 and fj.dep[mp[end(stkV)[-2]]]\
    \ >= fj.dep[x]) {\n        addEdge(stkV.back(), end(stkV)[-2]);\n        stkV.pop_back();\n\
    \      }\n      if (mp[stkV.back()] != x) {\n        addEdge(stkV.back(), nxt);\n\
    \        stkV.back() = nxt, mp[nxt++] = x;\n      }\n      stkV.emplace_back(v);\n\
    \    }\n    for(int x : g[v])\n      if (x != p)\n        self(x, v, self);\n\
    \  };\n\n  dfs(0, -1, dfs);\n\n  vector<int> root(n, -1);\n  for(int i = 0; i\
    \ < n; i++) {\n    while(ssize(stk[i]) > 1) {\n      addEdge(stk[i].back(), end(stk[i])[-2]);\n\
    \      stk[i].pop_back();\n    }\n    if (!stk[i].empty())\n      root[i] = stk[i][0];\n\
    \  }\n\n  return make_pair(res, root);\n}\n"
  code: "//#include<ds/fastJump.cpp>\n\npair<vector<vector<int>>, vector<int>> virtualTree(vector<vector<int>>\
    \ g, vector<int> c) {\n  int n = ssize(g), nxt = ssize(g);\n  fastJump fj(g);\n\
    \  vector<vector<int>> stk(n), res(2 * n - 1);\n  vector<int> mp(2 * n - 1);\n\
    \  iota(mp.begin(), mp.begin() + n, 0);\n  auto addEdge = [&](int u, int v) {\n\
    \    res[u].emplace_back(v);\n    res[v].emplace_back(u);\n  };\n  auto dfs =\
    \ [&](int v, int p, auto self) -> void {\n    if (auto &stkV = stk[c[v]]; stkV.empty()\
    \ or fj.lca(mp[stkV.back()], v) == mp[stkV.back()]) {\n      stkV.emplace_back(v);\n\
    \    } else {\n      int x = fj.lca(mp[stkV.back()], v);\n      while(ssize(stkV)\
    \ > 1 and fj.dep[mp[end(stkV)[-2]]] >= fj.dep[x]) {\n        addEdge(stkV.back(),\
    \ end(stkV)[-2]);\n        stkV.pop_back();\n      }\n      if (mp[stkV.back()]\
    \ != x) {\n        addEdge(stkV.back(), nxt);\n        stkV.back() = nxt, mp[nxt++]\
    \ = x;\n      }\n      stkV.emplace_back(v);\n    }\n    for(int x : g[v])\n \
    \     if (x != p)\n        self(x, v, self);\n  };\n\n  dfs(0, -1, dfs);\n\n \
    \ vector<int> root(n, -1);\n  for(int i = 0; i < n; i++) {\n    while(ssize(stk[i])\
    \ > 1) {\n      addEdge(stk[i].back(), end(stk[i])[-2]);\n      stk[i].pop_back();\n\
    \    }\n    if (!stk[i].empty())\n      root[i] = stk[i][0];\n  }\n\n  return\
    \ make_pair(res, root);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/auxiliaryTree.cpp
  requiredBy: []
  timestamp: '2024-02-15 21:38:49+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/auxiliaryTree.cpp
layout: document
redirect_from:
- /library/ds/auxiliaryTree.cpp
- /library/ds/auxiliaryTree.cpp.html
title: ds/auxiliaryTree.cpp
---
