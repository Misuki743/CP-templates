---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: graph/Dijkstra.cpp
    title: graph/Dijkstra.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/shortest_path.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\
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
    \ntemplate<ranges::forward_range rng, class T = ranges::range_value_t<rng>, class\
    \ OP = plus<T>>\nvoid pSum(rng &&v) {\n  if (!v.empty())\n    for(T p = v[0];\
    \ T &x : v | views::drop(1))\n      x = p = OP()(p, x);\n}\ntemplate<ranges::forward_range\
    \ rng, class T = ranges::range_value_t<rng>, class OP>\nvoid pSum(rng &&v, OP\
    \ op) {\n  if (!v.empty())\n    for(T p = v[0]; T &x : v | views::drop(1))\n \
    \     x = p = op(p, x);\n}\ntemplate<class T>\nT floorDiv(T a, T b) {\n  if (b\
    \ < 0) a *= -1, b *= -1;\n  return a >= 0 ? a / b : (a - b + 1) / b;\n}\ntemplate<class\
    \ T>\nT ceilDiv(T a, T b) {\n  if (b < 0) a *= -1, b *= -1;\n  return a >= 0 ?\
    \ (a + b - 1) / b : a / b;\n}\ntemplate<class T>\nostream& operator<<(ostream&\
    \ os, const pair<T, T> pr) {\n  return os << pr.first << ' ' << pr.second;\n}\n\
    template<class T, size_t N>\nostream& operator<<(ostream& os, const array<T, N>\
    \ &arr) {\n  for(const T &X : arr)\n    os << X << ' ';\n  return os;\n}\ntemplate<class\
    \ T>\nostream& operator<<(ostream& os, const vector<T> &vec) {\n  for(const T\
    \ &X : vec)\n    os << X << ' ';\n  return os;\n}\ntemplate<class T>\nostream&\
    \ operator<<(ostream& os, const set<T> &s) {\n  for(const T &x : s)\n    os <<\
    \ x << ' ';\n  return os;\n}\n#line 1 \"graph/Dijkstra.cpp\"\ntemplate<class T>\n\
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
    \ path;\n}\n#line 5 \"test/shortest_path.test.cpp\"\n\nint main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(0);\n\n  int n, m, s, t; cin >> n >> m >> s >> t;\n  vector<vector<pair<int,\
    \ ll>>> g(n);\n  while(m--) {\n    int a, b, c; cin >> a >> b >> c;\n    g[a].emplace_back(b,\
    \ c);\n  }\n\n  auto [dis, pre] = Dijkstra(g, s);\n  auto path = recover(pre,\
    \ t);\n\n  if (dis[t] == -1) {\n    cout << -1 << '\\n';\n  } else {\n    cout\
    \ << dis[t] << ' ' << ssize(path) - 1 << '\\n';\n    for(int i = 0; i + 1 < ssize(path);\
    \ i++)\n      cout << path[i] << ' ' << path[i + 1] << '\\n';\n  }\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ \"../default/t.cpp\"\n#include \"../graph/Dijkstra.cpp\"\n\nint main() {\n \
    \ ios::sync_with_stdio(false), cin.tie(0);\n\n  int n, m, s, t; cin >> n >> m\
    \ >> s >> t;\n  vector<vector<pair<int, ll>>> g(n);\n  while(m--) {\n    int a,\
    \ b, c; cin >> a >> b >> c;\n    g[a].emplace_back(b, c);\n  }\n\n  auto [dis,\
    \ pre] = Dijkstra(g, s);\n  auto path = recover(pre, t);\n\n  if (dis[t] == -1)\
    \ {\n    cout << -1 << '\\n';\n  } else {\n    cout << dis[t] << ' ' << ssize(path)\
    \ - 1 << '\\n';\n    for(int i = 0; i + 1 < ssize(path); i++)\n      cout << path[i]\
    \ << ' ' << path[i + 1] << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - graph/Dijkstra.cpp
  isVerificationFile: true
  path: test/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2024-06-29 18:02:37+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/test/shortest_path.test.cpp
- /verify/test/shortest_path.test.cpp.html
title: test/shortest_path.test.cpp
---
