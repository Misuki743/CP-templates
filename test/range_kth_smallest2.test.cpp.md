---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: misc/compression.cpp
    title: compression
  - icon: ':heavy_check_mark:'
    path: segtree/persistentSegmentTree.cpp
    title: segtree/persistentSegmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"test/range_kth_smallest2.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#line 1 \"default/t.cpp\"\
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
    \ pb push_back\n#define eb emplace_back\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
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
    \ &&v) {\n  if (!v.empty())\n    for(T p = v[0]; T &x : v | views::drop(1))\n\
    \      x = p = OP()(p, x);\n}\ntemplate<ranges::forward_range rng, class T = ranges::range_value_t<rng>,\
    \ class OP>\nvoid pSum(rng &&v, OP op) {\n  if (!v.empty())\n    for(T p = v[0];\
    \ T &x : v | views::drop(1))\n      x = p = op(p, x);\n}\n\ntemplate<ranges::forward_range\
    \ rng>\nvoid Unique(rng &v) {\n  ranges::sort(v);\n  v.resize(unique(v.begin(),\
    \ v.end()) - v.begin());\n}\n\ntemplate<ranges::random_access_range rng>\nrng\
    \ invPerm(rng p) {\n  rng ret = p;\n  for(int i = 0; i < ssize(p); i++)\n    ret[p[i]]\
    \ = i;\n  return ret;\n}\n\ntemplate<ranges::random_access_range rng, ranges::random_access_range\
    \ rng2>\nrng Permute(rng v, rng2 p) {\n  rng ret = v;\n  for(int i = 0; i < ssize(p);\
    \ i++)\n    ret[p[i]] = v[i];\n  return ret;\n}\n\ntemplate<bool directed>\nvector<vector<int>>\
    \ read_graph(int n, int m, int base) {\n  vector<vector<int>> g(n);\n  for(int\
    \ i = 0; i < m; i++) {\n    int u, v; cin >> u >> v;\n    u -= base, v -= base;\n\
    \    g[u].emplace_back(v);\n    if constexpr (!directed)\n      g[v].emplace_back(u);\n\
    \  }\n  return g;\n}\n\ntemplate<bool directed>\nvector<vector<int>> adjacency_list(int\
    \ n, vector<pii> e, int base) {\n  vector<vector<int>> g(n);\n  for(auto [u, v]\
    \ : e) {\n    u -= base, v -= base;\n    g[u].emplace_back(v);\n    if constexpr\
    \ (!directed)\n      g[v].emplace_back(u);\n  }\n  return g;\n}\n\ntemplate<class\
    \ T>\nvoid setBit(T &msk, int bit, bool x) {\n  msk = (msk & ~(T(1) << bit)) |\
    \ (T(x) << bit);\n}\ntemplate<class T> void flipBit(T &msk, int bit) { msk ^=\
    \ T(1) << bit; }\ntemplate<class T> bool getBit(T msk, int bit) { return msk >>\
    \ bit & T(1); }\n\ntemplate<class T>\nT floorDiv(T a, T b) {\n  if (b < 0) a *=\
    \ -1, b *= -1;\n  return a >= 0 ? a / b : (a - b + 1) / b;\n}\ntemplate<class\
    \ T>\nT ceilDiv(T a, T b) {\n  if (b < 0) a *= -1, b *= -1;\n  return a >= 0 ?\
    \ (a + b - 1) / b : a / b;\n}\n\ntemplate<class T> bool chmin(T &a, T b) { return\
    \ a > b ? a = b, 1 : 0; }\ntemplate<class T> bool chmax(T &a, T b) { return a\
    \ < b ? a = b, 1 : 0; }\n\n#line 1 \"misc/compression.cpp\"\ntemplate<class T,\
    \ bool duplicate = false>\nstruct compression {\n  vector<int> ord;\n  vector<T>\
    \ val;\n\n  compression(vector<T> &init) : val(init) { precompute(); }\n  compression(int\
    \ size = 0) { val.reserve(size); }\n\n  void precompute() {\n    vector<T> init\
    \ = val;\n    ord.resize(ssize(val));\n    ranges::sort(val);\n    if constexpr\
    \ (duplicate) {\n      vector<int> cnt(ssize(init));\n      iota(cnt.begin(),\
    \ cnt.end(), 0);\n      for(int i = 0; i < ssize(ord); i++)\n        ord[i] =\
    \ cnt[lower_bound(init[i])]++;\n    } else {\n      val.resize(unique(val.begin(),\
    \ val.end()) - val.begin());\n      for(int i = 0; i < ssize(ord); i++)\n    \
    \    ord[i] = lower_bound(init[i]);\n    }\n  }\n\n  int lower_bound(T x) { return\
    \ ranges::lower_bound(val, x) - val.begin(); }\n  int size() { return ssize(val);\
    \ }\n  template<ranges::range rng, class proj = identity>\n  void mapping(rng\
    \ &v, proj p = {}) { for(auto &x : v) p(x) = lower_bound(p(x)); }\n  template<ranges::range\
    \ rng, class proj = identity>\n  void insert(rng &v, proj p = {}) { for(auto &x\
    \ : v) val.emplace_back(p(x)); }\n};\n#line 1 \"segtree/persistentSegmentTree.cpp\"\
    \ntemplate<class M, M(*id)(), M(*op)(const M&, const M&)>\nstruct persistentSegmentTree\
    \ {\n  vector<int> lc, rc;\n  vector<M> data, init;\n  int nxt = 0;\n\n  //sz\
    \ >= (2n - 1) + q * (bit_width(n) + 1) should be satisfied\n  persistentSegmentTree(int\
    \ sz, vector<M> _init = vector<M>())\n  : lc(sz, -1), rc(sz, -1), data(sz, id()),\
    \ init(_init) {}\n\n  int build(int l, int r) {\n    int i = nxt++;\n    if (l\
    \ + 1 == r) {\n      if (!init.empty()) data[i] = init[l];\n    } else {\n   \
    \   int mid = (l + r) / 2;\n      lc[i] = build(l, mid), rc[i] = build(mid, r);\n\
    \      data[i] = op(data[lc[i]], data[rc[i]]);\n    }\n    return i;\n  }\n\n\
    \  int set(int v, int l, int r, int i, M x) {  \n    int vv = nxt++;\n    if (l\
    \ + 1 == r) {\n      data[vv] = x;\n    } else {\n      if (int mid = (l + r)\
    \ / 2; i < mid)\n        lc[vv] = set(lc[v], l, mid, i, x), rc[vv] = rc[v];\n\
    \      else\n        lc[vv] = lc[v], rc[vv] = set(rc[v], mid, r, i, x);\n    \
    \  data[vv] = op(data[lc[vv]], data[rc[vv]]);\n    }\n    return vv;\n  }\n\n\
    \  M query(int i, int l, int r, int ql, int qr) {\n    if (ql == qr or i == -1\
    \ or r <= ql or l >= qr) return id();\n    if (ql <= l and r <= qr) return data[i];\n\
    \    return op(query(lc[i], l, (l + r) / 2, ql, qr), \n              query(rc[i],\
    \ (l + r) / 2, r, ql, qr));\n  }\n};\n#line 6 \"test/range_kth_smallest2.test.cpp\"\
    \n\nint id() { return 0; }\nint op(const int &a, const int &b) { return a + b;\
    \ }\n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int\
    \ n, q; cin >> n >> q;\n  vector<int> a(n);\n  for(int &x : a)\n    cin >> x;\n\
    \n  compression<int, true> xs(a);\n  persistentSegmentTree<int, id, op> st(2 *\
    \ n + n * (bit_width((unsigned)n) + 1));\n  vector<int> root(n + 1);\n  root[0]\
    \ = st.build(0, n);\n  for(int i = 1; i <= n; i++)\n    root[i] = st.set(root[i\
    \ - 1], 0, n, xs.ord[i - 1], 1);\n\n  while(q--) {\n    int l, r, k; cin >> l\
    \ >> r >> k;\n    int u = root[l], v = root[r];\n    int ql = 0, qr = n;\n   \
    \ while(ql + 1 < qr) {\n      int mid = (ql + qr) / 2;\n      if (int cnt = st.data[st.lc[v]]\
    \ - st.data[st.lc[u]]; cnt <= k)\n        k -= cnt, u = st.rc[u], v = st.rc[v],\
    \ ql = mid;\n      else\n        u = st.lc[u], v = st.lc[v], qr = mid;\n    }\n\
    \    cout << xs.val[ql] << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"../default/t.cpp\"\n#include \"../misc/compression.cpp\"\n#include\
    \ \"../segtree/persistentSegmentTree.cpp\"\n\nint id() { return 0; }\nint op(const\
    \ int &a, const int &b) { return a + b; }\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<int> a(n);\n  for(int\
    \ &x : a)\n    cin >> x;\n\n  compression<int, true> xs(a);\n  persistentSegmentTree<int,\
    \ id, op> st(2 * n + n * (bit_width((unsigned)n) + 1));\n  vector<int> root(n\
    \ + 1);\n  root[0] = st.build(0, n);\n  for(int i = 1; i <= n; i++)\n    root[i]\
    \ = st.set(root[i - 1], 0, n, xs.ord[i - 1], 1);\n\n  while(q--) {\n    int l,\
    \ r, k; cin >> l >> r >> k;\n    int u = root[l], v = root[r];\n    int ql = 0,\
    \ qr = n;\n    while(ql + 1 < qr) {\n      int mid = (ql + qr) / 2;\n      if\
    \ (int cnt = st.data[st.lc[v]] - st.data[st.lc[u]]; cnt <= k)\n        k -= cnt,\
    \ u = st.rc[u], v = st.rc[v], ql = mid;\n      else\n        u = st.lc[u], v =\
    \ st.lc[v], qr = mid;\n    }\n    cout << xs.val[ql] << '\\n';\n  }\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - misc/compression.cpp
  - segtree/persistentSegmentTree.cpp
  isVerificationFile: true
  path: test/range_kth_smallest2.test.cpp
  requiredBy: []
  timestamp: '2026-01-29 02:59:39+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/range_kth_smallest2.test.cpp
layout: document
redirect_from:
- /verify/test/range_kth_smallest2.test.cpp
- /verify/test/range_kth_smallest2.test.cpp.html
title: test/range_kth_smallest2.test.cpp
---
