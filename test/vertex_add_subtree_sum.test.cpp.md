---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':x:'
    path: ds/eulerTour2.cpp
    title: ds/eulerTour2.cpp
  - icon: ':x:'
    path: segtree/segmentTree.cpp
    title: segtree/segmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/vertex_add_subtree_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n#line 1 \"default/t.cpp\"\
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
    \ chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"segtree/segmentTree.cpp\"\
    \ntemplate<class M, M(*id)(), M(*op)(const M&, const M&)>\nstruct segmentTree\
    \ {\n  int size;\n  vector<M> data;\n\n  segmentTree(int _size) : size(_size),\
    \ data(2 * size, id()) {}\n  segmentTree(vector<M> init) : size(ssize(init)),\
    \ data(2 * size, id()) {\n    ranges::copy(init, data.begin() + size);\n    for(int\
    \ i = size - 1; i > 0; i--)\n      data[i] = op(data[i << 1], data[i << 1 | 1]);\n\
    \  }\n\n  void set(int i, M x) {\n    data[i += size] = x;\n    while(i >>= 1)\n\
    \      data[i] = op(data[i << 1], data[i << 1 | 1]);\n  }\n\n  M get(int i) {\
    \ return data[i + size]; }\n\n  M query(int l, int r) {\n    M L = id(), R = id();\n\
    \    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) L\
    \ = op(L, data[l++]);\n      if (r & 1) R = op(data[--r], R);\n    }\n    return\
    \ op(L, R);\n  }\n\n  int firstTrue(int l, int r, function<bool(const M&)> f)\
    \ {\n    vector<int> idL, idR;\n    int r0 = r;\n    for(l += size, r += size;\
    \ l < r; l >>= 1, r >>= 1) {\n      if (l & 1) idL.emplace_back(l++);\n      if\
    \ (r & 1) idR.emplace_back(--r);\n    }\n    while(!idR.empty()) {\n      idL.emplace_back(idR.back());\n\
    \      idR.pop_back();\n    }\n    M pre = id();\n    int v = -1;\n    for(int\
    \ i : idL) {\n      if (f(op(pre, data[i]))) {\n        v = i;\n        break;\n\
    \      } else {\n        pre = op(pre, data[i]);\n      }\n    }\n    if (v ==\
    \ -1)\n      return r0;\n    while(v < size) {\n      if (f(op(pre, data[v <<\
    \ 1])))\n        v = v << 1;\n      else\n        pre = op(pre, data[v << 1]),\
    \ v = v << 1 | 1;\n    }\n    return v - size;\n  }\n};\n#line 1 \"ds/eulerTour2.cpp\"\
    \n//#include<segtree/segmentTree.cpp>\n\ntemplate<class M, M(*id)(), M(*op)(const\
    \ M&, const M&)>\nstruct eulerTour2 {\n  vector<int> tin, tout, p;\n  segmentTree<M,\
    \ id, op> st;\n\n  eulerTour2(vector<vector<int>> g, int root = 0) : tin(ssize(g)),\
    \ tout(ssize(g)), p(ssize(g), -1), st(ssize(g)) {\n    int t = 0;\n    auto dfs\
    \ = [&](int v, auto self) -> void {\n      tin[v] = t++;\n      for(int x : g[v])\
    \ {\n        if (x == p[v]) continue;\n        p[x] = v;\n        self(x, self);\n\
    \      }\n      tout[v] = t;\n    };\n\n    dfs(root, dfs);\n  }\n\n  void set(int\
    \ v, M x) { st.set(tin[v], x); }\n  M get(int v) { return st.get(tin[v]); }\n\
    \  M query(int v) { return st.query(tin[v], tout[v]); }\n};\n#line 6 \"test/vertex_add_subtree_sum.test.cpp\"\
    \n\nll unit() { return 0ll; }\nll add(const ll &a, const ll &b) { return a + b;\
    \ }\n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int\
    \ n, q; cin >> n >> q;\n  vector<ll> a(n);\n  for(ll &x : a)\n    cin >> x;\n\
    \  vector<vector<int>> g(n);\n  for(int u = 1; u < n; u++) {\n    int v; cin >>\
    \ v;\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n  }\n\n  eulerTour2<ll,\
    \ unit, add> eu(g);\n\n  for(int v = 0; v < n; v++)\n    eu.set(v, a[v]);\n\n\
    \  while(q--) {\n    int t; cin >> t;\n    if (t == 0) {\n      int x, y; cin\
    \ >> x >> y;\n      eu.set(x, eu.get(x) + y);\n    } else {\n      int x; cin\
    \ >> x;\n      cout << eu.query(x) << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../segtree/segmentTree.cpp\"\n#include\
    \ \"../ds/eulerTour2.cpp\"\n\nll unit() { return 0ll; }\nll add(const ll &a, const\
    \ ll &b) { return a + b; }\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<ll> a(n);\n  for(ll &x\
    \ : a)\n    cin >> x;\n  vector<vector<int>> g(n);\n  for(int u = 1; u < n; u++)\
    \ {\n    int v; cin >> v;\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n\
    \  }\n\n  eulerTour2<ll, unit, add> eu(g);\n\n  for(int v = 0; v < n; v++)\n \
    \   eu.set(v, a[v]);\n\n  while(q--) {\n    int t; cin >> t;\n    if (t == 0)\
    \ {\n      int x, y; cin >> x >> y;\n      eu.set(x, eu.get(x) + y);\n    } else\
    \ {\n      int x; cin >> x;\n      cout << eu.query(x) << '\\n';\n    }\n  }\n\
    \n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - segtree/segmentTree.cpp
  - ds/eulerTour2.cpp
  isVerificationFile: true
  path: test/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2024-07-28 21:04:51+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_add_subtree_sum.test.cpp
- /verify/test/vertex_add_subtree_sum.test.cpp.html
title: test/vertex_add_subtree_sum.test.cpp
---
