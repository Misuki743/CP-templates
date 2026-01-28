---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/minimum_steiner_tree.test.cpp
    title: test/minimum_steiner_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/steinerTree.cpp\"\ntemplate<class T>\npair<T, vector<int>>\
    \ steiner_tree(int n, vector<int> s, vector<tuple<int, int, T>> e) {\n  int k\
    \ = 0;\n  {\n    vector<bool> in_s(n, false);\n    for(int x : s) in_s[x] = true;\n\
    \    for(int v = 0; v < n; v++) k += in_s[v];\n    vector<int> f(n);\n    int\
    \ nxt = 0;\n    for(bool x : {true, false})\n      for(int v = 0; v < n; v++)\n\
    \        if (in_s[v] == x)\n          f[v] = nxt++;\n    for(auto &[u, v, _] :\
    \ e)\n      u = f[u], v = f[v];\n  }\n\n  vector<vector<tuple<int, int, T>>> g(n);\n\
    \  for(int i = 0; auto [u, v, w] : e) {\n    g[u].emplace_back(v, i, w);\n   \
    \ g[v].emplace_back(u, i++, w);\n  }\n\n  vector dp(1 << k, vector<T>(n, numeric_limits<T>::max()));\n\
    \  vector pre(1 << k, vector<array<int, 2>>(n, {-1, -1}));\n\n  for(unsigned x\
    \ = 1; x < (1 << k); x++) {\n    if (popcount(x) == 1) {\n      dp[x][countr_zero(x)]\
    \ = 0;\n    } else {\n      for(int r = 0; r < n; r++)\n        for(int y = (x\
    \ - 1) & x; y > 0; y = (y - 1) & x)\n          if (T tmp = dp[y][r] + dp[x^y][r];\
    \ tmp < dp[x][r])\n            dp[x][r] = tmp, pre[x][r] = {y, -1};\n    }\n \
    \   priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>>\
    \ pq;\n    for(int r = 0; r < n; r++)\n      pq.emplace(dp[x][r], r);\n    while(!pq.empty())\
    \ {\n      auto [d, v] = pq.top(); pq.pop();\n      if (d != dp[x][v]) continue;\n\
    \      for(auto [to, i, w] : g[v]) {\n        if (d + w < dp[x][to]) {\n     \
    \     dp[x][to] = d + w, pre[x][to] = {v, i};\n          pq.emplace(d + w, to);\n\
    \        }\n      }\n    }\n  }\n\n  vector<bool> in_t(size(e));\n  auto dfs =\
    \ [&](int x, int r, auto &&self) -> void {\n    auto [a, b] = pre[x][r];\n   \
    \ if (a == -1) return;\n    if (b == -1) {\n      self(a, r, self);\n      self(x\
    \ ^ a, r, self);\n    } else {\n      in_t[b] = true;\n      self(x, a, self);\n\
    \    }\n  };\n\n  int r = ranges::min_element(dp.back()) - dp.back().begin();\n\
    \  dfs((1 << k) - 1, r, dfs);\n\n  vector<int> t;\n  for(int i = 0; i < ssize(e);\
    \ i++)\n    if (in_t[i])\n      t.emplace_back(i);\n\n  return make_pair(dp.back()[r],\
    \ t);\n}\n"
  code: "template<class T>\npair<T, vector<int>> steiner_tree(int n, vector<int> s,\
    \ vector<tuple<int, int, T>> e) {\n  int k = 0;\n  {\n    vector<bool> in_s(n,\
    \ false);\n    for(int x : s) in_s[x] = true;\n    for(int v = 0; v < n; v++)\
    \ k += in_s[v];\n    vector<int> f(n);\n    int nxt = 0;\n    for(bool x : {true,\
    \ false})\n      for(int v = 0; v < n; v++)\n        if (in_s[v] == x)\n     \
    \     f[v] = nxt++;\n    for(auto &[u, v, _] : e)\n      u = f[u], v = f[v];\n\
    \  }\n\n  vector<vector<tuple<int, int, T>>> g(n);\n  for(int i = 0; auto [u,\
    \ v, w] : e) {\n    g[u].emplace_back(v, i, w);\n    g[v].emplace_back(u, i++,\
    \ w);\n  }\n\n  vector dp(1 << k, vector<T>(n, numeric_limits<T>::max()));\n \
    \ vector pre(1 << k, vector<array<int, 2>>(n, {-1, -1}));\n\n  for(unsigned x\
    \ = 1; x < (1 << k); x++) {\n    if (popcount(x) == 1) {\n      dp[x][countr_zero(x)]\
    \ = 0;\n    } else {\n      for(int r = 0; r < n; r++)\n        for(int y = (x\
    \ - 1) & x; y > 0; y = (y - 1) & x)\n          if (T tmp = dp[y][r] + dp[x^y][r];\
    \ tmp < dp[x][r])\n            dp[x][r] = tmp, pre[x][r] = {y, -1};\n    }\n \
    \   priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>>\
    \ pq;\n    for(int r = 0; r < n; r++)\n      pq.emplace(dp[x][r], r);\n    while(!pq.empty())\
    \ {\n      auto [d, v] = pq.top(); pq.pop();\n      if (d != dp[x][v]) continue;\n\
    \      for(auto [to, i, w] : g[v]) {\n        if (d + w < dp[x][to]) {\n     \
    \     dp[x][to] = d + w, pre[x][to] = {v, i};\n          pq.emplace(d + w, to);\n\
    \        }\n      }\n    }\n  }\n\n  vector<bool> in_t(size(e));\n  auto dfs =\
    \ [&](int x, int r, auto &&self) -> void {\n    auto [a, b] = pre[x][r];\n   \
    \ if (a == -1) return;\n    if (b == -1) {\n      self(a, r, self);\n      self(x\
    \ ^ a, r, self);\n    } else {\n      in_t[b] = true;\n      self(x, a, self);\n\
    \    }\n  };\n\n  int r = ranges::min_element(dp.back()) - dp.back().begin();\n\
    \  dfs((1 << k) - 1, r, dfs);\n\n  vector<int> t;\n  for(int i = 0; i < ssize(e);\
    \ i++)\n    if (in_t[i])\n      t.emplace_back(i);\n\n  return make_pair(dp.back()[r],\
    \ t);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/steinerTree.cpp
  requiredBy: []
  timestamp: '2025-11-14 17:40:41+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/minimum_steiner_tree.test.cpp
documentation_of: graph/steinerTree.cpp
layout: document
redirect_from:
- /library/graph/steinerTree.cpp
- /library/graph/steinerTree.cpp.html
title: graph/steinerTree.cpp
---
