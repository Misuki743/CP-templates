---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: graph/MCMF.cpp
    title: graph/MCMF.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/assignment
    links:
    - https://judge.yosupo.jp/problem/assignment
  bundledCode: "#line 1 \"test/assignment.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\
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
    \ \"graph/MCMF.cpp\"\ntemplate<class capT, class cosT>\nstruct MCMF {\n  struct\
    \ edge {\n    int to, rev;\n    capT cap;\n    cosT cos;\n    edge(int _to, capT\
    \ _cap, cosT _cos, int _rev) :\n        to(_to), rev(_rev), cap(_cap), cos(_cos)\
    \ {}\n  };\n\n  int n;\n  const capT CAP_MAX = numeric_limits<capT>::max();\n\
    \  const cosT COS_MAX = numeric_limits<cosT>::max();\n  vector<vector<edge>> g;\n\
    \  vector<int> par, idx;\n  vector<capT> f;\n  vector<cosT> pot, dis;\n\n  MCMF(int\
    \ _n) : n(_n), g(n), par(n),\n    idx(n), f(n), pot(n), dis(n) {}\n\n  void addEdge(int\
    \ from, int to, capT cap, cosT cos) {\n    g[from].emplace_back(to, cap, cos,\
    \ ssize(g[to]));\n    g[to].emplace_back(from, 0, -cos, ssize(g[from]) - 1);\n\
    \  }\n\n  void initPotential(int s) {\n    fill(dis.begin(), dis.end(), COS_MAX);\n\
    \    dis[s] = 0;\n    for(int i = 1; i < n; i++) {\n      for(int v = 0; v < n;\
    \ v++) {\n        if (dis[v] == COS_MAX) continue;\n        for(edge e : g[v])\n\
    \          if (e.cap != 0 and dis[v] + e.cos < dis[e.to])\n            dis[e.to]\
    \ = dis[v] + e.cos;\n      }\n    }\n    pot.swap(dis);\n  }\n\n  pair<capT, cosT>\
    \ runFlow(int s, int t, bool dense = false) {\n    cosT cost = 0;\n    capT flow\
    \ = 0;\n    while(true) {\n      fill(dis.begin(), dis.end(), COS_MAX);\n    \
    \  dis[s] = 0, f[s] = CAP_MAX;\n      if (dense) {\n        vector<bool> vis(n,\
    \ false);\n        for(int i = 0; i < n; i++) {\n          int v = -1;\n     \
    \     for(int j = 0; j < n; j++)\n            if (!vis[j] and (v == -1 or dis[j]\
    \ < dis[v]))\n              v = j;\n          if (v == -1 or dis[v] == COS_MAX)\
    \ break;\n          vis[v] = true;\n          for(edge e : g[v]) {\n         \
    \   if (e.cap == 0) continue;\n            if (cosT x = dis[v] + e.cos + pot[v]\
    \ - pot[e.to]; x < dis[e.to]) {\n              dis[e.to] = x, f[e.to] = min(f[v],\
    \ e.cap);\n              par[e.to] = v, idx[e.to] = g[e.to][e.rev].rev;\n    \
    \        }\n          }\n        }\n      } else {\n        using T = pair<cosT,\
    \ int>;\n        priority_queue<T, vector<T>, greater<T>> pq;\n        pq.push(make_pair(dis[s],\
    \ s));\n        while(!pq.empty()) {\n          auto [d, v] = pq.top(); pq.pop();\n\
    \          if (dis[v] != d) continue;\n          for(edge e : g[v]) {\n      \
    \      if (e.cap == 0) continue;\n            if (cosT x = dis[v] + e.cos + pot[v]\
    \ - pot[e.to]; x < dis[e.to]) {\n              dis[e.to] = x, f[e.to] = min(f[v],\
    \ e.cap);\n              par[e.to] = v, idx[e.to] = g[e.to][e.rev].rev;\n    \
    \          pq.push(make_pair(dis[e.to], e.to));\n            }\n          }\n\
    \        }\n      }\n\n      if (dis[t] == COS_MAX) break;\n\n      int v = t;\n\
    \      while(v != s) {\n        edge &e = g[par[v]][idx[v]];\n        e.cap -=\
    \ f[t], g[v][e.rev].cap += f[t];\n        v = par[v];\n      }\n      flow +=\
    \ f[t], cost += f[t] * (dis[t] - pot[s] + pot[t]);\n      for(int i = 0; i < n;\
    \ i++)\n        if (dis[i] != COS_MAX)\n          dis[i] += pot[i] - pot[s];\n\
    \      pot.swap(dis);\n    }\n\n    return {flow, cost};\n  }\n};\n#line 5 \"\
    test/assignment.test.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n; cin >> n;\n  vector a(n, vector<int>(n));\n  for(auto\
    \ &v : a)\n    for(int &x : v)\n      cin >> x;\n\n  const int s = 2 * n, t =\
    \ 2 * n + 1;\n  MCMF<int, ll> mcmf(2 * n + 2);\n  for(int v = 0; v < n; v++) {\n\
    \    mcmf.addEdge(s, v, 1, 0);\n    mcmf.addEdge(v + n, t, 1, 0);\n  }\n  for(int\
    \ u = 0; u < n; u++)\n    for(int v = 0; v < n; v++)\n      mcmf.addEdge(u, v\
    \ + n, 1, a[u][v]);\n\n  mcmf.initPotential(s);\n  cout << mcmf.runFlow(s, t,\
    \ true).second << '\\n';\n  for(int v = 0; v < n; v++)\n    for(auto e : mcmf.g[v])\n\
    \      if (e.cap == 0 and e.to != s)\n        cout << e.to - n << \" \\n\"[v +\
    \ 1 == n];\n\n  return 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n\n#include\
    \ \"../default/t.cpp\"\n#include \"../graph/MCMF.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n; cin >> n;\n  vector a(n, vector<int>(n));\n  for(auto\
    \ &v : a)\n    for(int &x : v)\n      cin >> x;\n\n  const int s = 2 * n, t =\
    \ 2 * n + 1;\n  MCMF<int, ll> mcmf(2 * n + 2);\n  for(int v = 0; v < n; v++) {\n\
    \    mcmf.addEdge(s, v, 1, 0);\n    mcmf.addEdge(v + n, t, 1, 0);\n  }\n  for(int\
    \ u = 0; u < n; u++)\n    for(int v = 0; v < n; v++)\n      mcmf.addEdge(u, v\
    \ + n, 1, a[u][v]);\n\n  mcmf.initPotential(s);\n  cout << mcmf.runFlow(s, t,\
    \ true).second << '\\n';\n  for(int v = 0; v < n; v++)\n    for(auto e : mcmf.g[v])\n\
    \      if (e.cap == 0 and e.to != s)\n        cout << e.to - n << \" \\n\"[v +\
    \ 1 == n];\n\n  return 0;\n}\n\n"
  dependsOn:
  - default/t.cpp
  - graph/MCMF.cpp
  isVerificationFile: true
  path: test/assignment.test.cpp
  requiredBy: []
  timestamp: '2024-05-14 23:51:19+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/assignment.test.cpp
layout: document
redirect_from:
- /verify/test/assignment.test.cpp
- /verify/test/assignment.test.cpp.html
title: test/assignment.test.cpp
---
