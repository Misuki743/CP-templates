---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: graph/complementConnectivity.cpp
    title: graph/complementConnectivity.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/connected_components_of_complement_graph
    links:
    - https://judge.yosupo.jp/problem/connected_components_of_complement_graph
  bundledCode: "#line 1 \"test/connected_components_of_complement_graph.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/connected_components_of_complement_graph\"\
    \n\n#line 1 \"default/t.cpp\"\n#include <algorithm>\n#include <array>\n#include\
    \ <bit>\n#include <bitset>\n#include <cassert>\n#include <cctype>\n#include <cfenv>\n\
    #include <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include <climits>\n\
    #include <cmath>\n#include <compare>\n#include <complex>\n#include <concepts>\n\
    #include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include <cstdio>\n\
    #include <cstdlib>\n#include <cstring>\n#include <deque>\n#include <fstream>\n\
    #include <functional>\n#include <initializer_list>\n#include <iomanip>\n#include\
    \ <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n#include\
    \ <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include <new>\n\
    #include <numbers>\n#include <numeric>\n#include <ostream>\n#include <queue>\n\
    #include <random>\n#include <ranges>\n#include <set>\n#include <span>\n#include\
    \ <sstream>\n#include <stack>\n#include <streambuf>\n#include <string>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <variant>\n\n#define INT128_MAX (__int128)(((unsigned\
    \ __int128) 1 << ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN\
    \ (-INT128_MAX - 1)\n\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ldb = long double;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\
    \ntemplate<class T>\nostream& operator<<(ostream& os, const pair<T, T> pr) {\n\
    \  return os << pr.first << ' ' << pr.second;\n}\ntemplate<class T, size_t N>\n\
    ostream& operator<<(ostream& os, const array<T, N> &arr) {\n  for(const T &X :\
    \ arr)\n    os << X << ' ';\n  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream&\
    \ os, const vector<T> &vec) {\n  for(const T &X : vec)\n    os << X << ' ';\n\
    \  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const set<T>\
    \ &s) {\n  for(const T &x : s)\n    os << x << ' ';\n  return os;\n}\n#line 1\
    \ \"graph/complementConnectivity.cpp\"\npair<vector<vector<int>>, vector<int>>\
    \ complementConnectivity(vector<vector<int>> &g) {\n  int n = ssize(g);\n  vector<bool>\
    \ vis(n, false), adj(n, false);\n  vector<int> unvis(n);\n  iota(unvis.begin(),\
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
    }\n#line 5 \"test/connected_components_of_complement_graph.test.cpp\"\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, m; cin >>\
    \ n >> m;\n  vector<vector<int>> g(n);\n  for(int i = 0; i < m; i++) {\n    int\
    \ u, v; cin >> u >> v;\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n\
    \  }\n\n  auto [ccs, _] = complementConnectivity(g);\n  cout << ssize(ccs) <<\
    \ '\\n';\n  for(auto &v : ccs) {\n    cout << ssize(v) << ' ';\n    for(int i\
    \ = 0; i < ssize(v); i++)\n      cout << v[i] << \" \\n\"[i + 1 == ssize(v)];\n\
    \  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/connected_components_of_complement_graph\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../graph/complementConnectivity.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ m; cin >> n >> m;\n  vector<vector<int>> g(n);\n  for(int i = 0; i < m; i++)\
    \ {\n    int u, v; cin >> u >> v;\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n\
    \  }\n\n  auto [ccs, _] = complementConnectivity(g);\n  cout << ssize(ccs) <<\
    \ '\\n';\n  for(auto &v : ccs) {\n    cout << ssize(v) << ' ';\n    for(int i\
    \ = 0; i < ssize(v); i++)\n      cout << v[i] << \" \\n\"[i + 1 == ssize(v)];\n\
    \  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - graph/complementConnectivity.cpp
  isVerificationFile: true
  path: test/connected_components_of_complement_graph.test.cpp
  requiredBy: []
  timestamp: '2024-05-04 14:16:48+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/connected_components_of_complement_graph.test.cpp
layout: document
redirect_from:
- /verify/test/connected_components_of_complement_graph.test.cpp
- /verify/test/connected_components_of_complement_graph.test.cpp.html
title: test/connected_components_of_complement_graph.test.cpp
---
