---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/DSU.cpp
    title: ds/DSU.cpp
  - icon: ':heavy_check_mark:'
    path: graph/Kruskal.cpp
    title: graph/Kruskal.cpp
  - icon: ':heavy_check_mark:'
    path: graph/Prim.cpp
    title: graph/Prim.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/minimum_spanning_tree
    links:
    - https://judge.yosupo.jp/problem/minimum_spanning_tree
  bundledCode: "#line 1 \"test/minimum_spanning_tree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/minimum_spanning_tree\"\n\n#line 1 \"default/t.cpp\"\
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
    \ \"ds/DSU.cpp\"\nstruct DSU {\n  vector<int> bos, sz;\n  int size;\n\n  DSU(int\
    \ _size) : bos(_size), sz(_size, 1), size(_size) {\n    iota(bos.begin(), bos.end(),\
    \ 0);\n  }\n\n  int query(int v) {\n    if (bos[v] == v)\n      return v;\n  \
    \  else\n      return bos[v] = query(bos[v]);\n  }\n\n  bool merge(int v1, int\
    \ v2) {\n    int b1 = query(v1), b2 = query(v2);\n\n    if (b1 == b2)\n      return\
    \ false;\n\n    if (sz[b1] > sz[b2])\n      swap(b1, b2);\n    bos[b1] = b2, sz[b2]\
    \ += sz[b1];\n\n    return true;\n  }\n};\n#line 1 \"graph/Kruskal.cpp\"\n//#include\
    \ \"ds/DSU.cpp\"\n\ntemplate<class T>\npair<T, vector<int>> Kruskal(vector<array<T,\
    \ 3>> &e, int n) {\n  vector<int> id(ssize(e));\n  iota(id.begin(), id.end(),\
    \ 0);\n  sort(id.begin(), id.end(), [&e](int i, int j) { return e[i][2] < e[j][2];\
    \ });\n\n  T cost = 0;\n  DSU dsu(n);\n  vector<int> res;\n  for(int i : id) {\n\
    \    auto [u, v, w] = e[i];\n    if (dsu.merge(u, v)) {\n      cost += w;\n  \
    \    res.emplace_back(i);\n    }\n  }\n  return make_pair(cost, res);\n}\n#line\
    \ 1 \"graph/Prim.cpp\"\ntemplate<class T>\npair<T, vector<int>> Prim(vector<array<T,\
    \ 3>> &e, int n) {\n  vector id(n, vector<int>(n, -1));\n  for(int i = 0; auto\
    \ [u, v, w] : e) {\n    if (id[u][v] == -1 or w < e[id[u][v]][2])\n      id[u][v]\
    \ = id[v][u] = i;\n    i++;\n  }\n\n  T cost = 0;\n  vector<bool> inT(n, false);\n\
    \  vector<int> eid, mn = id[0];\n  inT[0] = true;\n  for(int i = 0; i < n - 1;\
    \ i++) {\n    int v = -1;\n    for(int x = 0; x < n; x++)\n      if (!inT[x] and\
    \ mn[x] != -1 and (v == -1 or e[mn[x]][2] < e[mn[v]][2]))\n        v = x;\n  \
    \  if (v == -1) break;\n    inT[v] = true, cost += e[mn[v]][2];\n    eid.emplace_back(mn[v]);\n\
    \    for(int x = 0; x < n; x++)\n      if (id[v][x] != -1 and (mn[x] == -1 or\
    \ e[id[v][x]][2] < e[mn[x]][2]))\n        mn[x] = id[v][x];\n  }\n\n  if (ssize(eid)\
    \ == n - 1)\n    return make_pair(cost, eid);\n  else\n    return make_pair(numeric_limits<T>::max(),\
    \ vector<int>());\n}\n#line 7 \"test/minimum_spanning_tree.test.cpp\"\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  ll n, m; cin >>\
    \ n >> m;\n  vector<array<ll, 3>> e(m);\n  for(auto &[u, v, w] : e)\n    cin >>\
    \ u >> v >> w;\n\n  ll cost;\n  vector<int> eid;\n  if (n * n < m * (int)bit_width((unsigned)m))\n\
    \    tie(cost, eid) = Prim(e, n);\n  else\n    tie(cost, eid) = Kruskal(e, n);\n\
    \n  cout << cost << '\\n';\n  cout << eid << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/minimum_spanning_tree\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../ds/DSU.cpp\"\n#include \"../graph/Kruskal.cpp\"\
    \n#include \"../graph/Prim.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  ll n, m; cin >> n >> m;\n  vector<array<ll, 3>> e(m);\n\
    \  for(auto &[u, v, w] : e)\n    cin >> u >> v >> w;\n\n  ll cost;\n  vector<int>\
    \ eid;\n  if (n * n < m * (int)bit_width((unsigned)m))\n    tie(cost, eid) = Prim(e,\
    \ n);\n  else\n    tie(cost, eid) = Kruskal(e, n);\n\n  cout << cost << '\\n';\n\
    \  cout << eid << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - ds/DSU.cpp
  - graph/Kruskal.cpp
  - graph/Prim.cpp
  isVerificationFile: true
  path: test/minimum_spanning_tree.test.cpp
  requiredBy: []
  timestamp: '2024-04-05 18:02:52+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/minimum_spanning_tree.test.cpp
layout: document
redirect_from:
- /verify/test/minimum_spanning_tree.test.cpp
- /verify/test/minimum_spanning_tree.test.cpp.html
title: test/minimum_spanning_tree.test.cpp
---