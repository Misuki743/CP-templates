---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree_diameter.test.cpp
    title: test/tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/treeDiameter.cpp\"\ntemplate<class T, T inf>\npair<T,\
    \ vector<int>> treeDiameter(vector<vector<pair<int, T>>> &g) {\n  const int n\
    \ = ssize(g);\n  auto bfs = [&](int s) {\n    vector<T> dis(n, inf);\n    vector<int>\
    \ pre(n, -1);\n    queue<int> q;\n    dis[s] = 0;\n    q.push(s);\n    while(!q.empty())\
    \ {\n      int v = q.front(); q.pop();\n      for(auto [x, w] : g[v]) {\n    \
    \    if (dis[x] != inf) continue;\n        pre[x] = v, dis[x] = dis[v] + w;\n\
    \        q.push(x);\n      }\n    }\n    return make_pair(dis, pre);\n  };\n\n\
    \  auto dis0 = bfs(0).first;\n  int u = ranges::max_element(dis0) - dis0.begin();\n\
    \  auto [dis1, pre1] = bfs(u);\n  int v = ranges::max_element(dis1) - dis1.begin();\n\
    \  T d = dis1[v];\n\n  vector<int> diameter(1, v);\n  while(pre1[v] != -1)\n \
    \   diameter.emplace_back(v = pre1[v]);\n\n  return make_pair(d, diameter);\n\
    }\n"
  code: "template<class T, T inf>\npair<T, vector<int>> treeDiameter(vector<vector<pair<int,\
    \ T>>> &g) {\n  const int n = ssize(g);\n  auto bfs = [&](int s) {\n    vector<T>\
    \ dis(n, inf);\n    vector<int> pre(n, -1);\n    queue<int> q;\n    dis[s] = 0;\n\
    \    q.push(s);\n    while(!q.empty()) {\n      int v = q.front(); q.pop();\n\
    \      for(auto [x, w] : g[v]) {\n        if (dis[x] != inf) continue;\n     \
    \   pre[x] = v, dis[x] = dis[v] + w;\n        q.push(x);\n      }\n    }\n   \
    \ return make_pair(dis, pre);\n  };\n\n  auto dis0 = bfs(0).first;\n  int u =\
    \ ranges::max_element(dis0) - dis0.begin();\n  auto [dis1, pre1] = bfs(u);\n \
    \ int v = ranges::max_element(dis1) - dis1.begin();\n  T d = dis1[v];\n\n  vector<int>\
    \ diameter(1, v);\n  while(pre1[v] != -1)\n    diameter.emplace_back(v = pre1[v]);\n\
    \n  return make_pair(d, diameter);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/treeDiameter.cpp
  requiredBy: []
  timestamp: '2024-04-05 19:44:35+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree_diameter.test.cpp
documentation_of: graph/treeDiameter.cpp
layout: document
redirect_from:
- /library/graph/treeDiameter.cpp
- /library/graph/treeDiameter.cpp.html
title: graph/treeDiameter.cpp
---
