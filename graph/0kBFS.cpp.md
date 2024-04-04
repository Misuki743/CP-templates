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
  bundledCode: "#line 1 \"graph/0kBFS.cpp\"\ntemplate<class T>\npair<vector<T>, vector<int>>\
    \ BFS0k(vector<vector<pair<int, bool>>> &g, T k, int s) {\n  int n = ssize(g);\n\
    \  vector<T> dis(n, -1);\n  vector<int> pre(n, -1);\n  vector<bool> vis(n, false);\n\
    \  deque<int> dq;\n\n  dis[s] = 0;\n  dq.push_back(s);\n\n  while(!dq.empty())\
    \ {\n    int v = dq.front(); dq.pop_front();\n    if (vis[v]) continue;\n    vis[v]\
    \ = true;\n    for(auto [x, w] : g[v]) {\n      if (dis[x] == -1 or dis[v] + (w\
    \ ? k : T(0)) < dis[x]) {\n        dis[x] = dis[v] + (w ? k : T(0)), pre[x] =\
    \ v;\n        if (w) dq.push_back(x);\n        else dq.push_front(x);\n      }\n\
    \    }\n  }\n\n  return make_pair(dis, pre);\n}\n"
  code: "template<class T>\npair<vector<T>, vector<int>> BFS0k(vector<vector<pair<int,\
    \ bool>>> &g, T k, int s) {\n  int n = ssize(g);\n  vector<T> dis(n, -1);\n  vector<int>\
    \ pre(n, -1);\n  vector<bool> vis(n, false);\n  deque<int> dq;\n\n  dis[s] = 0;\n\
    \  dq.push_back(s);\n\n  while(!dq.empty()) {\n    int v = dq.front(); dq.pop_front();\n\
    \    if (vis[v]) continue;\n    vis[v] = true;\n    for(auto [x, w] : g[v]) {\n\
    \      if (dis[x] == -1 or dis[v] + (w ? k : T(0)) < dis[x]) {\n        dis[x]\
    \ = dis[v] + (w ? k : T(0)), pre[x] = v;\n        if (w) dq.push_back(x);\n  \
    \      else dq.push_front(x);\n      }\n    }\n  }\n\n  return make_pair(dis,\
    \ pre);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/0kBFS.cpp
  requiredBy: []
  timestamp: '2024-04-04 16:33:52+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/0kBFS.cpp
layout: document
redirect_from:
- /library/graph/0kBFS.cpp
- /library/graph/0kBFS.cpp.html
title: graph/0kBFS.cpp
---
