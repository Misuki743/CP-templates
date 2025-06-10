---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwickTree.cpp
    title: ds/fenwickTree.cpp
  - icon: ':heavy_check_mark:'
    path: ds_problem/point_set_range_frequency.cpp
    title: ds_problem/point_set_range_frequency.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_frequency
    links:
    - https://judge.yosupo.jp/problem/point_set_range_frequency
  bundledCode: "#line 1 \"test/point_set_range_frequency.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_set_range_frequency\"\n\n#line 1 \"\
    default/t.cpp\"\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include\
    \ <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include\
    \ <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include <deque>\n#include\
    \ <fstream>\n#include <functional>\n#include <initializer_list>\n#include <iomanip>\n\
    #include <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n\
    #include <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include\
    \ <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <sstream>\n#include <stack>\n#include <streambuf>\n#include\
    \ <string>\n#include <tuple>\n#include <type_traits>\n#include <variant>\n#include\
    \ <bit>\n#include <compare>\n#include <concepts>\n#include <numbers>\n#include\
    \ <ranges>\n#include <span>\n\n#define INT128_MAX (__int128)(((unsigned __int128)\
    \ 1 << ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN (-INT128_MAX\
    \ - 1)\n\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
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
    \ chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"ds/fenwickTree.cpp\"\
    \ntemplate<class T>\nstruct fenwickTree {\n  const int size;\n  vector<T> data;\n\
    \n  fenwickTree(int _size) : size(_size + 1), data(_size + 1) {}\n  fenwickTree(vector<T>\
    \ &init) : size(ssize(init) + 1), data(ssize(init) + 1) {\n    partial_sum(init.begin(),\
    \ init.end(), data.begin() + 1);\n    for(int i = size - 1; i > 0; i--)\n    \
    \  data[i] -= data[i - (i & (-i))];\n  }\n\n  void add(int i, T d) {\n    for(i\
    \ += 1; i < size; i += i & (-i))\n      data[i] += d;\n  }\n\n  T query(int i)\
    \ {\n    T res = T(0);\n    for(i += 1; i > 0; i -= i & (-i))\n      res += data[i];\n\
    \    return res;\n  }\n\n  T query(int l, int r) { //query [l, r)\n    return\
    \ query(r - 1) - query(l - 1);\n  }\n};\n#line 1 \"ds_problem/point_set_range_frequency.cpp\"\
    \n//#include<ds/fenwickTree.cpp>\n\ntemplate<class T>\nstruct point_set_range_frequency\
    \ {\n  vector<T> a;\n  int n, now = 0;\n  struct Query {\n    T x;\n    int t,\
    \ l, r, id;\n  };\n  vector<Query> q;\n  struct Modification {\n    T x;\n   \
    \ int t, i;\n    bool add;\n  };\n  vector<Modification> m;\n\n  point_set_range_frequency(vector<T>\
    \ &_a)\n    : a(_a), n(ssize(a)), m(n) {\n    for(int i = 0; i < n; i++)\n   \
    \   m[i] = {a[i], 0, i, true};\n  };\n\n  void modify(int i, T x) {\n    m.push_back({a[i],\
    \ now, i, false});\n    m.push_back({a[i] = x, now, i, true});\n  }\n\n  void\
    \ query(int l, int r, T x) {\n    q.push_back({x, now++, l, r, (int)size(q)});\n\
    \  }\n\n  vector<int> solve() {\n    for(int i = 0; i < n; i++)\n      m.push_back({a[i],\
    \ now, i, false});\n    ranges::sort(q, {}, [&](auto &e) { return pair(e.x, e.t);\
    \ });\n    ranges::sort(m, {}, [&](auto &e) { return pair(e.x, e.t); });\n   \
    \ vector<int> ans(ssize(q));\n    fenwickTree<int> ft(n);\n    for(int i = 0;\
    \ auto [x, t, l, r, id] : q) {\n      while(i < ssize(m) and pair(m[i].x, m[i].t)\
    \ <= pair(x, t))\n        ft.add(m[i].i, m[i].add ? 1 : -1), i++;\n      ans[id]\
    \ = ft.query(l, r);\n    }\n    return ans;\n  }\n};\n#line 6 \"test/point_set_range_frequency.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ q; cin >> n >> q;\n  vector<int> a(n);\n  for(int &x : a) cin >> x;\n\n  point_set_range_frequency<int>\
    \ ds(a);\n  while(q--) {\n    int op; cin >> op;\n    if (op == 0) {\n      int\
    \ k, v; cin >> k >> v;\n      ds.modify(k, v);\n    } else {\n      int l, r,\
    \ x; cin >> l >> r >> x;\n      ds.query(l, r, x);\n    }\n  }\n\n  for(int x\
    \ : ds.solve())\n    cout << x << '\\n';\n\n  return 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_frequency\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../ds/fenwickTree.cpp\"\n#include\
    \ \"../ds_problem/point_set_range_frequency.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<int> a(n);\n  for(int\
    \ &x : a) cin >> x;\n\n  point_set_range_frequency<int> ds(a);\n  while(q--) {\n\
    \    int op; cin >> op;\n    if (op == 0) {\n      int k, v; cin >> k >> v;\n\
    \      ds.modify(k, v);\n    } else {\n      int l, r, x; cin >> l >> r >> x;\n\
    \      ds.query(l, r, x);\n    }\n  }\n\n  for(int x : ds.solve())\n    cout <<\
    \ x << '\\n';\n\n  return 0;\n}\n\n"
  dependsOn:
  - default/t.cpp
  - ds/fenwickTree.cpp
  - ds_problem/point_set_range_frequency.cpp
  isVerificationFile: true
  path: test/point_set_range_frequency.test.cpp
  requiredBy: []
  timestamp: '2025-06-10 23:00:40+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/point_set_range_frequency.test.cpp
layout: document
redirect_from:
- /verify/test/point_set_range_frequency.test.cpp
- /verify/test/point_set_range_frequency.test.cpp.html
title: test/point_set_range_frequency.test.cpp
---
