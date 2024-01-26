---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: graph/dinic.cpp
    title: graph/dinic.cpp
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
    \nnamespace R = std::ranges;\nnamespace V = std::views;\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing ull = unsigned long long;\nusing ldb = long double;\n\
    using pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate<class T>\n\
    ostream& operator<<(ostream& os, const pair<T, T> pr) {\n  return os << pr.first\
    \ << ' ' << pr.second;\n}\ntemplate<class T, size_t N>\nostream& operator<<(ostream&\
    \ os, const array<T, N> &arr) {\n  for(const T &X : arr)\n    os << X << ' ';\n\
    \  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const vector<T>\
    \ &vec) {\n  for(const T &X : vec)\n    os << X << ' ';\n  return os;\n}\ntemplate<class\
    \ T>\nostream& operator<<(ostream& os, const set<T> &s) {\n  for(const T &x :\
    \ s)\n    os << x << ' ';\n  return os;\n}\n#line 1 \"graph/dinic.cpp\"\ntemplate<class\
    \ T, T MAX>\nstruct Dinic {\n  const int N;\n  struct Edge {\n    int to, rev;\n\
    \    T cap;\n    Edge(int _to, T _cap, int _rev) : to(_to), rev(_rev), cap(_cap)\
    \ {}\n  };\n  vector<vector<Edge>> G;\n  Dinic(int _N) : N(_N), G(_N), level(_N),\
    \ iter(_N) {}\n  void addEdge(int from, int to, T cap) {\n    G[from].emplace_back(Edge(to,\
    \ cap, G[to].size()));\n    G[to].emplace_back(Edge(from, 0, (int)G[from].size()\
    \ - 1));\n  }\n  int n, s, t;\n  void init(int _n, int _s, int _t) {\n    n =\
    \ _n, s = _s, t = _t;\n    for(int i = 0; i < n; i++)\n      G[i].clear();\n \
    \ }\n  vector<int> level, iter;\n  void BFS() {\n    fill(level.begin(), level.end(),\
    \ INT_MAX);\n    level[s] = 0;\n    queue<int> q;\n    q.push(s);\n    while(!q.empty())\
    \ {\n      int now = q.front(); q.pop();\n      for(Edge &E : G[now]) {\n    \
    \    if (E.cap > 0 and level[E.to] == INT_MAX) {\n          level[E.to] = level[now]\
    \ + 1;\n          q.push(E.to);\n        }\n      }\n    }\n  }\n  T DFS(int V,\
    \ T flow) {\n    if (V == s)\n      return flow;\n\n    for(int &i = iter[V];\
    \ i < ssize(G[V]); i++) {\n      Edge &E = G[V][i];\n      if (T tmp; level[E.to]\
    \ == level[V] - 1 and G[E.to][E.rev].cap > 0) {\n        if ((tmp = DFS(E.to,\
    \ min(flow, G[E.to][E.rev].cap))) > 0) {\n          E.cap += tmp, G[E.to][E.rev].cap\
    \ -= tmp;\n          return tmp;\n        }\n      }\n    }\n\n    return 0;\n\
    \  }\n\n  T flow() {\n    T res = 0;\n    while(true) {\n      BFS();\n      if\
    \ (level[t] == INT_MAX)\n        break;\n      fill(iter.begin(), iter.end(),\
    \ 0);\n      T del;\n      while((del = DFS(t, MAX)) > 0) {\n        res += del;\n\
    \      }\n    }\n\n    return res;\n  }\n\n  bool left(int idx) {\n    return\
    \ level[idx] != INT_MAX;\n  }\n};\n#line 5 \"test/matching_on_bipartite_graph.test.cpp\"\
    \n\nint main() {\n  int l, r, m; cin >> l >> r >> m;\n\n  const int s = l + r,\
    \ t = l + r + 1;\n  Dinic<int, INT_MAX> flow(l + r + 2);\n  flow.init(l + r +\
    \ 2, s, t);\n  while(m--) {\n    int u, v; cin >> u >> v;\n    flow.addEdge(u,\
    \ v + l, 1);\n  }\n  for(int i = 0; i < l; i++)\n    flow.addEdge(s, i, 1);\n\
    \  for(int i = l; i < l + r; i++)\n    flow.addEdge(i, t, 1);\n\n  cout << flow.flow()\
    \ << '\\n';\n  for(int i = l; i < l + r; i++)\n    for(auto e : flow.G[i])\n \
    \     if (e.to != t and e.cap == 1)\n        cout << e.to << ' ' << i - l << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include \"../default/t.cpp\"\n#include \"../graph/dinic.cpp\"\n\nint main() {\n\
    \  int l, r, m; cin >> l >> r >> m;\n\n  const int s = l + r, t = l + r + 1;\n\
    \  Dinic<int, INT_MAX> flow(l + r + 2);\n  flow.init(l + r + 2, s, t);\n  while(m--)\
    \ {\n    int u, v; cin >> u >> v;\n    flow.addEdge(u, v + l, 1);\n  }\n  for(int\
    \ i = 0; i < l; i++)\n    flow.addEdge(s, i, 1);\n  for(int i = l; i < l + r;\
    \ i++)\n    flow.addEdge(i, t, 1);\n\n  cout << flow.flow() << '\\n';\n  for(int\
    \ i = l; i < l + r; i++)\n    for(auto e : flow.G[i])\n      if (e.to != t and\
    \ e.cap == 1)\n        cout << e.to << ' ' << i - l << '\\n';\n}\n"
  dependsOn:
  - default/t.cpp
  - graph/dinic.cpp
  isVerificationFile: true
  path: test/matching_on_bipartite_graph.test.cpp
  requiredBy: []
  timestamp: '2024-01-21 19:52:41+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/matching_on_bipartite_graph.test.cpp
layout: document
redirect_from:
- /verify/test/matching_on_bipartite_graph.test.cpp
- /verify/test/matching_on_bipartite_graph.test.cpp.html
title: test/matching_on_bipartite_graph.test.cpp
---
