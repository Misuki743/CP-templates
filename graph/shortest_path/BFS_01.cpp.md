---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yuki_1868.test.cpp
    title: test/yuki_1868.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/shortest_path/BFS_01.cpp\"\ntemplate<integral T>\n\
    auto BFS_01(vvc<pair<int, T>> &g, vi s) {\n  const int n = ssize(g);\n  constexpr\
    \ T INF = numeric_limits<T>::max();\n\n  vc<T> dis(n, INF);\n  vi pre(n, -1);\n\
    \  deque<int> dq(s.begin(), s.end());\n  for(int v : s)\n    dis[v] = 0, pre[v]\
    \ = v;\n\n  while(!dq.empty()) {\n    int v = dq.front(); dq.pop_front();\n  \
    \  for(auto [x, w] : g[v]) {\n      if (chmin(dis[x], dis[v] + w)) {\n       \
    \ pre[x] = v;\n        if (w) dq.push_back(x);\n        else dq.push_front(x);\n\
    \      }\n    }\n  }\n\n  return pair(dis, pre);\n}\n\nvi recover(vi &pre, int\
    \ t) {\n  if (pre[t] == -1) return {};\n  vi path = {t};\n  while(pre[path.back()]\
    \ != path.back())\n    path.emplace_back(pre[path.back()]);\n  ranges::reverse(path);\n\
    \  return path;\n}\n"
  code: "template<integral T>\nauto BFS_01(vvc<pair<int, T>> &g, vi s) {\n  const\
    \ int n = ssize(g);\n  constexpr T INF = numeric_limits<T>::max();\n\n  vc<T>\
    \ dis(n, INF);\n  vi pre(n, -1);\n  deque<int> dq(s.begin(), s.end());\n  for(int\
    \ v : s)\n    dis[v] = 0, pre[v] = v;\n\n  while(!dq.empty()) {\n    int v = dq.front();\
    \ dq.pop_front();\n    for(auto [x, w] : g[v]) {\n      if (chmin(dis[x], dis[v]\
    \ + w)) {\n        pre[x] = v;\n        if (w) dq.push_back(x);\n        else\
    \ dq.push_front(x);\n      }\n    }\n  }\n\n  return pair(dis, pre);\n}\n\nvi\
    \ recover(vi &pre, int t) {\n  if (pre[t] == -1) return {};\n  vi path = {t};\n\
    \  while(pre[path.back()] != path.back())\n    path.emplace_back(pre[path.back()]);\n\
    \  ranges::reverse(path);\n  return path;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path/BFS_01.cpp
  requiredBy: []
  timestamp: '2026-01-31 00:52:12+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yuki_1868.test.cpp
documentation_of: graph/shortest_path/BFS_01.cpp
layout: document
redirect_from:
- /library/graph/shortest_path/BFS_01.cpp
- /library/graph/shortest_path/BFS_01.cpp.html
title: graph/shortest_path/BFS_01.cpp
---
