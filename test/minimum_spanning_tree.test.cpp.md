---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':x:'
    path: ds/DSU.cpp
    title: ds/DSU.cpp
  - icon: ':x:'
    path: graph/Kruskal.cpp
    title: graph/Kruskal.cpp
  - icon: ':x:'
    path: graph/Prim.cpp
    title: graph/Prim.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/minimum_spanning_tree
    links:
    - https://judge.yosupo.jp/problem/minimum_spanning_tree
  bundledCode: "#line 1 \"test/minimum_spanning_tree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/minimum_spanning_tree\"\n\n#line 1 \"default/t.cpp\"\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include\
    \ <cinttypes>\n#include <climits>\n#include <cmath>\n#include <complex>\n#include\
    \ <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <deque>\n#include <fstream>\n#include\
    \ <functional>\n#include <initializer_list>\n#include <iomanip>\n#include <ios>\n\
    #include <iostream>\n#include <istream>\n#include <iterator>\n#include <limits>\n\
    #include <list>\n#include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n\
    #include <ostream>\n#include <queue>\n#include <random>\n#include <set>\n#include\
    \ <sstream>\n#include <stack>\n#include <streambuf>\n#include <string>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <variant>\n#include <bit>\n#include\
    \ <compare>\n#include <concepts>\n#include <numbers>\n#include <ranges>\n#include\
    \ <span>\n\n#define INT128_MAX (__int128)(((unsigned __int128) 1 << ((sizeof(__int128)\
    \ * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN (-INT128_MAX - 1)\n\n#define\
    \ clock chrono::steady_clock::now().time_since_epoch().count()\n\nusing namespace\
    \ std;\n\ntemplate<class T1, class T2>\nostream& operator<<(ostream& os, const\
    \ pair<T1, T2> pr) {\n  return os << pr.first << ' ' << pr.second;\n}\ntemplate<class\
    \ T, size_t N>\nostream& operator<<(ostream& os, const array<T, N> &arr) {\n \
    \ for(size_t i = 0; T x : arr) {\n    os << x;\n    if (++i != N) os << ' ';\n\
    \  }\n  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const\
    \ vector<T> &vec) {\n  for(size_t i = 0; T x : vec) {\n    os << x;\n    if (++i\
    \ != size(vec)) os << ' ';\n  }\n  return os;\n}\ntemplate<class T>\nostream&\
    \ operator<<(ostream& os, const set<T> &s) {\n  for(size_t i = 0; T x : s) {\n\
    \    os << x;\n    if (++i != size(s)) os << ' ';\n  }\n  return os;\n}\ntemplate<class\
    \ T1, class T2>\nostream& operator<<(ostream& os, const map<T1, T2> &m) {\n  for(size_t\
    \ i = 0; pair<T1, T2> x : m) {\n    os << x;\n    if (++i != size(m)) os << '\
    \ ';\n  }\n  return os;\n}\n\n#ifdef DEBUG\n#define dbg(...) cerr << '(', _do(#__VA_ARGS__),\
    \ cerr << \") = \", _do2(__VA_ARGS__)\ntemplate<typename T> void _do(T &&x) {\
    \ cerr << x; }\ntemplate<typename T, typename ...S> void _do(T &&x, S&&...y) {\
    \ cerr << x << \", \"; _do(y...); }\ntemplate<typename T> void _do2(T &&x) { cerr\
    \ << x << endl; }\ntemplate<typename T, typename ...S> void _do2(T &&x, S&&...y)\
    \ { cerr << x << \", \"; _do2(y...); }\n#else\n#define dbg(...)\n#endif\n\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing ldb = long double;\n\
    using pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate<typename T>\
    \ using min_heap = priority_queue<T, vector<T>, greater<T>>;\ntemplate<typename\
    \ T> using max_heap = priority_queue<T>;\n\ntemplate<ranges::forward_range rng,\
    \ class T = ranges::range_value_t<rng>, class OP = plus<T>>\nvoid pSum(rng &v)\
    \ {\n  if (!v.empty())\n    for(T p = v[0]; T &x : v | views::drop(1))\n     \
    \ x = p = OP()(p, x);\n}\ntemplate<ranges::forward_range rng, class T = ranges::range_value_t<rng>,\
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
    \ chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"ds/DSU.cpp\"\n\
    struct DSU {\n  vector<int> bos, sz;\n  int size;\n\n  DSU(int _size) : bos(_size),\
    \ sz(_size, 1), size(_size) {\n    iota(bos.begin(), bos.end(), 0);\n  }\n\n \
    \ int query(int v) {\n    if (bos[v] == v)\n      return v;\n    else\n      return\
    \ bos[v] = query(bos[v]);\n  }\n\n  bool merge(int v1, int v2) {\n    int b1 =\
    \ query(v1), b2 = query(v2);\n\n    if (b1 == b2)\n      return false;\n\n   \
    \ if (sz[b1] > sz[b2])\n      swap(b1, b2);\n    bos[b1] = b2, sz[b2] += sz[b1];\n\
    \n    return true;\n  }\n};\n#line 1 \"graph/Kruskal.cpp\"\n//#include \"ds/DSU.cpp\"\
    \n\ntemplate<class T, bool sorted = false>\npair<T, vector<int>> Kruskal(vector<array<T,\
    \ 3>> &e, int n) {\n  vector<int> id(ssize(e));\n  iota(id.begin(), id.end(),\
    \ 0);\n  if constexpr (!sorted)\n    ranges::sort(id, {}, [&e](int i) { return\
    \ e[i][2]; });\n\n  T cost = 0;\n  DSU dsu(n);\n  vector<int> res;\n  for(int\
    \ i : id) {\n    auto [u, v, w] = e[i];\n    if (dsu.merge(u, v)) {\n      cost\
    \ += w;\n      res.emplace_back(i);\n    }\n  }\n  return make_pair(cost, res);\n\
    }\n#line 1 \"graph/Prim.cpp\"\ntemplate<class T>\npair<T, vector<int>> Prim(vector<array<T,\
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
  timestamp: '2024-07-28 21:04:51+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/minimum_spanning_tree.test.cpp
layout: document
redirect_from:
- /verify/test/minimum_spanning_tree.test.cpp
- /verify/test/minimum_spanning_tree.test.cpp.html
title: test/minimum_spanning_tree.test.cpp
---
