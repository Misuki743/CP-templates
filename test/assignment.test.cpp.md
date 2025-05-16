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
    \ <bitset>\n#include <cassert>\n#include <cctype>\n#include <cfenv>\n#include\
    \ <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include <climits>\n#include\
    \ <cmath>\n#include <complex>\n#include <cstdarg>\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <initializer_list>\n\
    #include <iomanip>\n#include <ios>\n#include <iostream>\n#include <istream>\n\
    #include <iterator>\n#include <limits>\n#include <list>\n#include <map>\n#include\
    \ <memory>\n#include <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n\
    #include <random>\n#include <set>\n#include <sstream>\n#include <stack>\n#include\
    \ <streambuf>\n#include <string>\n#include <tuple>\n#include <type_traits>\n#include\
    \ <variant>\n#include <bit>\n#include <compare>\n#include <concepts>\n#include\
    \ <numbers>\n#include <ranges>\n#include <span>\n\n#define INT128_MAX (__int128)(((unsigned\
    \ __int128) 1 << ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN\
    \ (-INT128_MAX - 1)\n\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
    \nusing namespace std;\n\ntemplate<class T1, class T2>\nostream& operator<<(ostream&\
    \ os, const pair<T1, T2> pr) {\n  return os << pr.first << ' ' << pr.second;\n\
    }\ntemplate<class T, size_t N>\nostream& operator<<(ostream& os, const array<T,\
    \ N> &arr) {\n  for(size_t i = 0; T x : arr) {\n    os << x;\n    if (++i != N)\
    \ os << ' ';\n  }\n  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream&\
    \ os, const vector<T> &vec) {\n  for(size_t i = 0; T x : vec) {\n    os << x;\n\
    \    if (++i != size(vec)) os << ' ';\n  }\n  return os;\n}\ntemplate<class T>\n\
    ostream& operator<<(ostream& os, const set<T> &s) {\n  for(size_t i = 0; T x :\
    \ s) {\n    os << x;\n    if (++i != size(s)) os << ' ';\n  }\n  return os;\n\
    }\ntemplate<class T1, class T2>\nostream& operator<<(ostream& os, const map<T1,\
    \ T2> &m) {\n  for(size_t i = 0; pair<T1, T2> x : m) {\n    os << x;\n    if (++i\
    \ != size(m)) os << ' ';\n  }\n  return os;\n}\n\n#ifdef DEBUG\n#define dbg(...)\
    \ cerr << '(', _do(#__VA_ARGS__), cerr << \") = \", _do2(__VA_ARGS__)\ntemplate<typename\
    \ T> void _do(T &&x) { cerr << x; }\ntemplate<typename T, typename ...S> void\
    \ _do(T &&x, S&&...y) { cerr << x << \", \"; _do(y...); }\ntemplate<typename T>\
    \ void _do2(T &&x) { cerr << x << endl; }\ntemplate<typename T, typename ...S>\
    \ void _do2(T &&x, S&&...y) { cerr << x << \", \"; _do2(y...); }\n#else\n#define\
    \ dbg(...)\n#endif\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ldb = long double;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\
    \ntemplate<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;\n\
    template<typename T> using max_heap = priority_queue<T>;\n\ntemplate<ranges::forward_range\
    \ rng, class T = ranges::range_value_t<rng>, class OP = plus<T>>\nvoid pSum(rng\
    \ &v) {\n  if (!v.empty())\n    for(T p = v[0]; T &x : v | views::drop(1))\n \
    \     x = p = OP()(p, x);\n}\ntemplate<ranges::forward_range rng, class T = ranges::range_value_t<rng>,\
    \ class OP>\nvoid pSum(rng &v, OP op) {\n  if (!v.empty())\n    for(T p = v[0];\
    \ T &x : v | views::drop(1))\n      x = p = op(p, x);\n}\n\ntemplate<ranges::forward_range\
    \ rng>\nvoid Unique(rng &v) {\n  ranges::sort(v);\n  v.resize(unique(v.begin(),\
    \ v.end()) - v.begin());\n}\n\ntemplate<ranges::random_access_range rng>\nrng\
    \ invPerm(rng p) {\n  rng ret = p;\n  for(int i = 0; i < ssize(p); i++)\n    ret[p[i]]\
    \ = i;\n  return ret;\n}\n\ntemplate<ranges::random_access_range rng, ranges::random_access_range\
    \ rng2>\nrng Permute(rng v, rng2 p) {\n  rng ret = v;\n  for(int i = 0; i < ssize(p);\
    \ i++)\n    ret[p[i]] = v[i];\n  return ret;\n}\n\ntemplate<bool directed>\nvector<vector<int>>\
    \ readGraph(int n, int m, int base) {\n  vector<vector<int>> g(n);\n  for(int\
    \ i = 0; i < m; i++) {\n    int u, v; cin >> u >> v;\n    u -= base, v -= base;\n\
    \    g[u].emplace_back(v);\n    if constexpr (!directed)\n      g[v].emplace_back(u);\n\
    \  }\n  return g;\n}\n\ntemplate<class T>\nvoid setBit(T &msk, int bit, bool x)\
    \ {\n  msk = (msk & ~(T(1) << bit)) | (T(x) << bit);\n}\ntemplate<class T> void\
    \ flipBit(T &msk, int bit) { msk ^= T(1) << bit; }\ntemplate<class T> bool getBit(T\
    \ msk, int bit) { return msk >> bit & T(1); }\n\ntemplate<class T>\nT floorDiv(T\
    \ a, T b) {\n  if (b < 0) a *= -1, b *= -1;\n  return a >= 0 ? a / b : (a - b\
    \ + 1) / b;\n}\ntemplate<class T>\nT ceilDiv(T a, T b) {\n  if (b < 0) a *= -1,\
    \ b *= -1;\n  return a >= 0 ? (a + b - 1) / b : a / b;\n}\n\ntemplate<class T>\
    \ bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }\ntemplate<class T> bool\
    \ chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"graph/MCMF.cpp\"\
    \ntemplate<class capT, class cosT>\nstruct MCMF {\n  struct edge {\n    int to,\
    \ rev;\n    capT cap;\n    cosT cos;\n    edge(int _to, capT _cap, cosT _cos,\
    \ int _rev) :\n        to(_to), rev(_rev), cap(_cap), cos(_cos) {}\n  };\n\n \
    \ int n;\n  const capT CAP_MAX = numeric_limits<capT>::max();\n  const cosT COS_MAX\
    \ = numeric_limits<cosT>::max();\n  vector<vector<edge>> g;\n  vector<int> par,\
    \ idx;\n  vector<capT> f;\n  vector<cosT> pot, dis;\n\n  MCMF(int _n) : n(_n),\
    \ g(n), par(n),\n    idx(n), f(n), pot(n), dis(n) {}\n\n  void addEdge(int from,\
    \ int to, capT cap, cosT cos) {\n    g[from].emplace_back(to, cap, cos, ssize(g[to]));\n\
    \    g[to].emplace_back(from, 0, -cos, ssize(g[from]) - 1);\n  }\n\n  void initPotential(int\
    \ s) {\n    fill(dis.begin(), dis.end(), COS_MAX);\n    dis[s] = 0;\n    for(int\
    \ i = 1; i < n; i++) {\n      for(int v = 0; v < n; v++) {\n        if (dis[v]\
    \ == COS_MAX) continue;\n        for(edge e : g[v])\n          if (e.cap != 0\
    \ and dis[v] + e.cos < dis[e.to])\n            dis[e.to] = dis[v] + e.cos;\n \
    \     }\n    }\n    pot.swap(dis);\n  }\n\n  void initPotentialDAG(int s) {\n\
    \    fill(dis.begin(), dis.end(), COS_MAX);\n    dis[s] = 0;\n    vector<int>\
    \ topo = [&]() {\n      vector<int> topo;\n      vector<bool> vis(n, false);\n\
    \      auto dfs = [&](int v, auto &&self) -> void {\n        vis[v] = true;\n\
    \        for(edge e : g[v])\n          if (e.cap != 0 and !vis[e.to])\n      \
    \      self(e.to, self);\n        topo.emplace_back(v);\n      };\n      for(int\
    \ v = 0; v < n; v++)\n        if (!vis[v])\n          dfs(v, dfs);\n      return\
    \ topo;\n    }();\n    for(int v : topo | views::reverse)\n      if (dis[v] !=\
    \ COS_MAX)\n        for(edge e : g[v])\n          if (e.cap != 0)\n          \
    \  chmin(dis[e.to], dis[v] + e.cos);\n    pot.swap(dis);\n  }\n\n  pair<capT,\
    \ cosT> runFlow(int s, int t, bool dense = false) {\n    cosT cost = 0;\n    capT\
    \ flow = 0;\n    while(true) {\n      fill(dis.begin(), dis.end(), COS_MAX);\n\
    \      dis[s] = 0, f[s] = CAP_MAX;\n      if (dense) {\n        vector<bool> vis(n,\
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
  timestamp: '2024-09-15 11:33:45+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/assignment.test.cpp
layout: document
redirect_from:
- /verify/test/assignment.test.cpp
- /verify/test/assignment.test.cpp.html
title: test/assignment.test.cpp
---
