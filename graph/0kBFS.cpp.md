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
  bundledCode: "#line 1 \"graph/0kBFS.cpp\"\npair<vector<int>, vector<int>> BFS01(vector<vector<pair<int,\
    \ bool>>> &g, int s) {\n  int n = ssize(g);\n  vector<int> dis(n, INT_MAX), pre(n,\
    \ -1);\n  deque<int> dq;\n\n  dis[s] = 0;\n  dq.push_back(s);\n\n  while(!dq.empty())\
    \ {\n    int v = dq.front(); dq.pop_front();\n    for(auto [x, w] : g[v]) {\n\
    \      if (dis[v] + w < dis[x]) {\n        dis[x] = dis[v] + w, pre[x] = v;\n\
    \        if (w) dq.push_back(x);\n        else dq.push_front(x);\n      }\n  \
    \  }\n  }\n\n  return make_pair(dis, pre);\n}\n"
  code: "pair<vector<int>, vector<int>> BFS01(vector<vector<pair<int, bool>>> &g,\
    \ int s) {\n  int n = ssize(g);\n  vector<int> dis(n, INT_MAX), pre(n, -1);\n\
    \  deque<int> dq;\n\n  dis[s] = 0;\n  dq.push_back(s);\n\n  while(!dq.empty())\
    \ {\n    int v = dq.front(); dq.pop_front();\n    for(auto [x, w] : g[v]) {\n\
    \      if (dis[v] + w < dis[x]) {\n        dis[x] = dis[v] + w, pre[x] = v;\n\
    \        if (w) dq.push_back(x);\n        else dq.push_front(x);\n      }\n  \
    \  }\n  }\n\n  return make_pair(dis, pre);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/0kBFS.cpp
  requiredBy: []
  timestamp: '2025-08-23 17:38:12+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/0kBFS.cpp
layout: document
redirect_from:
- /library/graph/0kBFS.cpp
- /library/graph/0kBFS.cpp.html
title: graph/0kBFS.cpp
---
