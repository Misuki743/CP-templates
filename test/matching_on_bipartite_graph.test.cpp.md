---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: graph/Dinic.cpp
    title: graph/Dinic.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/matching_on_bipartite_graph.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n#line 1 \"default/t.cpp\"\
    \n#include <algorithm>\n#include <array>\n#include <bit>\n#include <bitset>\n\
    #include <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <compare>\n#include <complex>\n#include <concepts>\n#include <cstdarg>\n#include\
    \ <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include\
    \ <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
    \ <initializer_list>\n#include <iomanip>\n#include <ios>\n#include <iostream>\n\
    #include <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n\
    #include <map>\n#include <memory>\n#include <new>\n#include <numbers>\n#include\
    \ <numeric>\n#include <ostream>\n#include <queue>\n#include <random>\n#include\
    \ <ranges>\n#include <set>\n#include <span>\n#include <sstream>\n#include <stack>\n\
    #include <streambuf>\n#include <string>\n#include <tuple>\n#include <type_traits>\n\
    #include <variant>\n\n#define INT128_MAX (__int128)(((unsigned __int128) 1 <<\
    \ ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN (-INT128_MAX\
    \ - 1)\n\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ldb = long double;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\
    \ntemplate<class T>\nostream& operator<<(ostream& os, const pair<T, T> pr) {\n\
    \  return os << pr.first << ' ' << pr.second;\n}\ntemplate<class T, size_t N>\n\
    ostream& operator<<(ostream& os, const array<T, N> &arr) {\n  for(const T &X :\
    \ arr)\n    os << X << ' ';\n  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream&\
    \ os, const vector<T> &vec) {\n  for(const T &X : vec)\n    os << X << ' ';\n\
    \  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const set<T>\
    \ &s) {\n  for(const T &x : s)\n    os << x << ' ';\n  return os;\n}\n#line 1\
    \ \"graph/Dinic.cpp\"\ntemplate<class T>\nstruct Dinic {\n  struct edge {\n  \
    \  int to, rev;\n    T cap;\n    edge(int _to, T _cap, int _rev)\n     : to(_to),\
    \ rev(_rev), cap(_cap) {}\n  };\n\n  int n;\n  const T CAP_MAX = numeric_limits<T>::max();\n\
    \  vector<vector<edge>> g;\n  vector<int> lev, iter;\n\n  Dinic(int _n) : n(_n),\
    \ g(n), lev(n), iter(n) {}\n\n  void addEdge(int from, int to, T cap) {\n    g[from].emplace_back(to,\
    \ cap, ssize(g[to]));\n    g[to].emplace_back(from, 0, ssize(g[from]) - 1);\n\
    \  }\n\n  bool bfs(int s, int t) {\n    fill(lev.begin(), lev.end(), INT_MAX);\n\
    \    lev[s] = 0;\n    queue<int> q;\n    q.push(s);\n    while(!q.empty()) {\n\
    \      int v = q.front(); q.pop();\n      for(edge &e : g[v]) if (e.cap > 0 and\
    \ lev[e.to] == INT_MAX) {\n        lev[e.to] = lev[v] + 1;\n        q.push(e.to);\n\
    \      }\n    }\n    return lev[t] != INT_MAX;\n  }\n\n  T runFlow(int s, int\
    \ t) {\n    auto dfs = [&](int v, T f, auto &&self) -> T {\n      if (v == s)\
    \ return f;\n      for(int &i = iter[v]; i < ssize(g[v]); i++) {\n        edge\
    \ &e = g[v][i];\n        if (T tmp; lev[e.to] == lev[v] - 1 and g[e.to][e.rev].cap\
    \ > 0) {\n          if ((tmp = self(e.to, min(f, g[e.to][e.rev].cap), self)) >\
    \ 0) {\n            e.cap += tmp, g[e.to][e.rev].cap -= tmp;\n            return\
    \ tmp;\n          }\n        }\n      }\n      return 0;\n    };\n    T flow =\
    \ 0, del;\n    while(bfs(s, t)) {\n      fill(iter.begin(), iter.end(), 0);\n\
    \      while((del = dfs(t, CAP_MAX, dfs)) > 0)\n        flow = (flow >= CAP_MAX\
    \ - del ? CAP_MAX : flow + del);\n    }\n\n    return flow;\n  }\n\n  bool left(int\
    \ idx) { return lev[idx] != INT_MAX; }\n};\n#line 5 \"test/matching_on_bipartite_graph.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int l,\
    \ r, m; cin >> l >> r >> m;\n  const int s = l + r, t = l + r + 1;\n  Dinic<int>\
    \ dinic(l + r + 2);\n  for(int i = 0; i < l; i++) dinic.addEdge(s, i, 1);\n  for(int\
    \ i = l; i < l + r; i++) dinic.addEdge(i, t, 1);\n  for(int i = 0; i < m; i++)\
    \ {\n    int u, v; cin >> u >> v;\n    dinic.addEdge(u, v + l, 1);\n  }\n\n  cout\
    \ << dinic.runFlow(s, t) << '\\n';\n  for(int v = 0; v < l; v++)\n    for(auto\
    \ &e : dinic.g[v])\n      if (e.cap == 0 and e.to != s)\n        cout << v <<\
    \ ' ' << e.to - l << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include \"../default/t.cpp\"\n#include \"../graph/Dinic.cpp\"\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int l, r, m; cin >> l\
    \ >> r >> m;\n  const int s = l + r, t = l + r + 1;\n  Dinic<int> dinic(l + r\
    \ + 2);\n  for(int i = 0; i < l; i++) dinic.addEdge(s, i, 1);\n  for(int i = l;\
    \ i < l + r; i++) dinic.addEdge(i, t, 1);\n  for(int i = 0; i < m; i++) {\n  \
    \  int u, v; cin >> u >> v;\n    dinic.addEdge(u, v + l, 1);\n  }\n\n  cout <<\
    \ dinic.runFlow(s, t) << '\\n';\n  for(int v = 0; v < l; v++)\n    for(auto &e\
    \ : dinic.g[v])\n      if (e.cap == 0 and e.to != s)\n        cout << v << ' '\
    \ << e.to - l << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - graph/Dinic.cpp
  isVerificationFile: true
  path: test/matching_on_bipartite_graph.test.cpp
  requiredBy: []
  timestamp: '2024-05-15 00:03:32+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/matching_on_bipartite_graph.test.cpp
layout: document
redirect_from:
- /verify/test/matching_on_bipartite_graph.test.cpp
- /verify/test/matching_on_bipartite_graph.test.cpp.html
title: test/matching_on_bipartite_graph.test.cpp
---
