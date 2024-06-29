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
    \ x << ' ';\n  return os;\n}\n#line 1 \"misc/compression.cpp\"\ntemplate<class\
    \ T, bool duplicate = false>\nstruct compression {\n  vector<int> ord;\n  vector<T>\
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
  timestamp: '2024-06-29 18:02:37+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/range_kth_smallest2.test.cpp
layout: document
redirect_from:
- /verify/test/range_kth_smallest2.test.cpp
- /verify/test/range_kth_smallest2.test.cpp.html
title: test/range_kth_smallest2.test.cpp
---
