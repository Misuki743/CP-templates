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
  bundledCode: "#line 1 \"graph/shortest_path/Dijkstra.cpp\"\ntemplate<class T>\n\
    pair<vector<T>, vector<int>> Dijkstra(vector<vector<pair<int, T>>> &g, int s)\
    \ {\n  int n = ssize(g);\n  vector<T> dis(n, -1);\n  vector<int> pre(n, -1);\n\
    \  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;\n\
    \n  dis[s] = 0;\n  pq.push({0, s});\n\n  while(!pq.empty()) {\n    auto [d, v]\
    \ = pq.top(); pq.pop();\n    if (dis[v] != d) continue;\n    for(auto [x, w] :\
    \ g[v]) {\n      if (dis[x] != -1 and d + w >= dis[x]) continue;\n      dis[x]\
    \ = d + w, pre[x] = v;\n      pq.push(make_pair(d + w, x));\n    }\n  }\n\n  return\
    \ make_pair(dis, pre);\n}\n\nvector<int> recover(vector<int> &pre, int t) {\n\
    \  if (pre[t] == -1) return {};\n  vector<int> path(1, t);\n  while(pre[t] !=\
    \ -1)\n    path.emplace_back(t = pre[t]);\n  ranges::reverse(path);\n  return\
    \ path;\n}\n"
  code: "template<class T>\npair<vector<T>, vector<int>> Dijkstra(vector<vector<pair<int,\
    \ T>>> &g, int s) {\n  int n = ssize(g);\n  vector<T> dis(n, -1);\n  vector<int>\
    \ pre(n, -1);\n  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T,\
    \ int>>> pq;\n\n  dis[s] = 0;\n  pq.push({0, s});\n\n  while(!pq.empty()) {\n\
    \    auto [d, v] = pq.top(); pq.pop();\n    if (dis[v] != d) continue;\n    for(auto\
    \ [x, w] : g[v]) {\n      if (dis[x] != -1 and d + w >= dis[x]) continue;\n  \
    \    dis[x] = d + w, pre[x] = v;\n      pq.push(make_pair(d + w, x));\n    }\n\
    \  }\n\n  return make_pair(dis, pre);\n}\n\nvector<int> recover(vector<int> &pre,\
    \ int t) {\n  if (pre[t] == -1) return {};\n  vector<int> path(1, t);\n  while(pre[t]\
    \ != -1)\n    path.emplace_back(t = pre[t]);\n  ranges::reverse(path);\n  return\
    \ path;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path/Dijkstra.cpp
  requiredBy: []
  timestamp: '2026-01-30 20:10:19+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/shortest_path/Dijkstra.cpp
layout: document
redirect_from:
- /library/graph/shortest_path/Dijkstra.cpp
- /library/graph/shortest_path/Dijkstra.cpp.html
title: graph/shortest_path/Dijkstra.cpp
---
