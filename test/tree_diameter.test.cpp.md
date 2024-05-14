---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: graph/treeDiameter.cpp
    title: graph/treeDiameter.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/tree_diameter.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\
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
    \ \"graph/treeDiameter.cpp\"\ntemplate<class T>\ntuple<T, T, T, vector<int>> treeDiameter(vector<vector<pair<int,\
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
    \  for(int v : diameter)\n    if (int x = max(dis1[v], d - dis1[v]); x < radius)\n\
    \      radius = x, center = v;\n\n  return make_tuple(d, radius, center, diameter);\n\
    }\n#line 5 \"test/tree_diameter.test.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n; cin >> n;\n  vector<vector<pair<int, ll>>> g(n);\n\
    \  for(int i = 1; i < n; i++) {\n    int u, v, w; cin >> u >> v >> w;\n    g[u].emplace_back(v,\
    \ w);\n    g[v].emplace_back(u, w);\n  }\n\n  auto [d, _, __, vs] = treeDiameter<ll>(g);\n\
    \  cout << d << ' ' << ssize(vs) << '\\n';\n  cout << vs << '\\n';\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ \"../default/t.cpp\"\n#include \"../graph/treeDiameter.cpp\"\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n; cin >> n;\n  vector<vector<pair<int,\
    \ ll>>> g(n);\n  for(int i = 1; i < n; i++) {\n    int u, v, w; cin >> u >> v\
    \ >> w;\n    g[u].emplace_back(v, w);\n    g[v].emplace_back(u, w);\n  }\n\n \
    \ auto [d, _, __, vs] = treeDiameter<ll>(g);\n  cout << d << ' ' << ssize(vs)\
    \ << '\\n';\n  cout << vs << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - graph/treeDiameter.cpp
  isVerificationFile: true
  path: test/tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2024-05-04 14:34:04+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/test/tree_diameter.test.cpp
- /verify/test/tree_diameter.test.cpp.html
title: test/tree_diameter.test.cpp
---
