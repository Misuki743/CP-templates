---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/tree_diameter.test.cpp
    title: test/tree_diameter.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/treeDiameter.cpp\"\ntemplate<class T>\ntuple<T, T,\
    \ T, vector<int>> treeDiameter(vector<vector<pair<int, T>>> &g) {\n  const T inf\
    \ = numeric_limits<T>::max();\n  const int n = ssize(g);\n  auto bfs = [&](int\
    \ s) {\n    vector<T> dis(n, inf);\n    vector<int> pre(n, -1);\n    queue<int>\
    \ q;\n    dis[s] = 0;\n    q.push(s);\n    while(!q.empty()) {\n      int v =\
    \ q.front(); q.pop();\n      for(auto [x, w] : g[v]) {\n        if (dis[x] !=\
    \ inf) continue;\n        pre[x] = v, dis[x] = dis[v] + w;\n        q.push(x);\n\
    \      }\n    }\n    return make_pair(dis, pre);\n  };\n\n  auto dis0 = bfs(0).first;\n\
    \  int u = ranges::max_element(dis0) - dis0.begin();\n  auto [dis1, pre1] = bfs(u);\n\
    \  int v = ranges::max_element(dis1) - dis1.begin();\n  T d = dis1[v];\n\n  vector<int>\
    \ diameter(1, v);\n  while(pre1[v] != -1)\n    diameter.emplace_back(v = pre1[v]);\n\
    \n  int radius = inf, center = -1;\n  for(int y : diameter)\n    if (int x = max(dis1[y],\
    \ d - dis1[y]); x < radius)\n      radius = x, center = y;\n\n  return make_tuple(d,\
    \ radius, center, diameter);\n}\n"
  code: "template<class T>\ntuple<T, T, T, vector<int>> treeDiameter(vector<vector<pair<int,\
    \ T>>> &g) {\n  const T inf = numeric_limits<T>::max();\n  const int n = ssize(g);\n\
    \  auto bfs = [&](int s) {\n    vector<T> dis(n, inf);\n    vector<int> pre(n,\
    \ -1);\n    queue<int> q;\n    dis[s] = 0;\n    q.push(s);\n    while(!q.empty())\
    \ {\n      int v = q.front(); q.pop();\n      for(auto [x, w] : g[v]) {\n    \
    \    if (dis[x] != inf) continue;\n        pre[x] = v, dis[x] = dis[v] + w;\n\
    \        q.push(x);\n      }\n    }\n    return make_pair(dis, pre);\n  };\n\n\
    \  auto dis0 = bfs(0).first;\n  int u = ranges::max_element(dis0) - dis0.begin();\n\
    \  auto [dis1, pre1] = bfs(u);\n  int v = ranges::max_element(dis1) - dis1.begin();\n\
    \  T d = dis1[v];\n\n  vector<int> diameter(1, v);\n  while(pre1[v] != -1)\n \
    \   diameter.emplace_back(v = pre1[v]);\n\n  int radius = inf, center = -1;\n\
    \  for(int y : diameter)\n    if (int x = max(dis1[y], d - dis1[y]); x < radius)\n\
    \      radius = x, center = y;\n\n  return make_tuple(d, radius, center, diameter);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/treeDiameter.cpp
  requiredBy: []
  timestamp: '2025-08-05 20:50:02+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree_diameter.test.cpp
documentation_of: graph/treeDiameter.cpp
layout: document
redirect_from:
- /library/graph/treeDiameter.cpp
- /library/graph/treeDiameter.cpp.html
title: graph/treeDiameter.cpp
---
