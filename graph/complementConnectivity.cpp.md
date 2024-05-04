---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/connected_components_of_complement_graph.test.cpp
    title: test/connected_components_of_complement_graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/complementConnectivity.cpp\"\npair<vector<vector<int>>,\
    \ vector<int>> complementConnectivity(vector<vector<int>> &g) {\n  int n = ssize(g);\n\
    \  vector<bool> vis(n, false), adj(n, false);\n  vector<int> unvis(n);\n  iota(unvis.begin(),\
    \ unvis.end(), 0);\n\n  auto bfs = [&]() -> vector<int> {\n    vector<int> cc;\n\
    \    queue<int> q;\n    q.push(unvis.back());\n    vis[unvis.back()] = true;\n\
    \    unvis.pop_back();\n    while(!q.empty()) {\n      int v = q.front(); q.pop();\n\
    \      cc.emplace_back(v);\n      vector<int> nxt;\n      for(int x : g[v]) adj[x]\
    \ = true;\n      for(int x : unvis) {\n        if (adj[x]) {\n          nxt.emplace_back(x);\n\
    \        } else {\n          q.push(x);\n          vis[x] = true;\n        }\n\
    \      }\n      for(int x : g[v]) adj[x] = false;\n      unvis.swap(nxt);\n  \
    \  }\n\n    return cc;\n  };\n\n  vector<int> group(n, -1);\n  vector<vector<int>>\
    \ ccs;\n  while(!unvis.empty()) {\n    auto vs = bfs();\n    for(int x : vs) group[x]\
    \ = ssize(ccs);\n    ccs.emplace_back(vs);\n  }\n\n  return make_pair(ccs, group);\n\
    }\n"
  code: "pair<vector<vector<int>>, vector<int>> complementConnectivity(vector<vector<int>>\
    \ &g) {\n  int n = ssize(g);\n  vector<bool> vis(n, false), adj(n, false);\n \
    \ vector<int> unvis(n);\n  iota(unvis.begin(), unvis.end(), 0);\n\n  auto bfs\
    \ = [&]() -> vector<int> {\n    vector<int> cc;\n    queue<int> q;\n    q.push(unvis.back());\n\
    \    vis[unvis.back()] = true;\n    unvis.pop_back();\n    while(!q.empty()) {\n\
    \      int v = q.front(); q.pop();\n      cc.emplace_back(v);\n      vector<int>\
    \ nxt;\n      for(int x : g[v]) adj[x] = true;\n      for(int x : unvis) {\n \
    \       if (adj[x]) {\n          nxt.emplace_back(x);\n        } else {\n    \
    \      q.push(x);\n          vis[x] = true;\n        }\n      }\n      for(int\
    \ x : g[v]) adj[x] = false;\n      unvis.swap(nxt);\n    }\n\n    return cc;\n\
    \  };\n\n  vector<int> group(n, -1);\n  vector<vector<int>> ccs;\n  while(!unvis.empty())\
    \ {\n    auto vs = bfs();\n    for(int x : vs) group[x] = ssize(ccs);\n    ccs.emplace_back(vs);\n\
    \  }\n\n  return make_pair(ccs, group);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/complementConnectivity.cpp
  requiredBy: []
  timestamp: '2024-05-04 14:16:48+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/connected_components_of_complement_graph.test.cpp
documentation_of: graph/complementConnectivity.cpp
layout: document
redirect_from:
- /library/graph/complementConnectivity.cpp
- /library/graph/complementConnectivity.cpp.html
title: graph/complementConnectivity.cpp
---
