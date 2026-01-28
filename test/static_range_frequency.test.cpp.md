---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':x:'
    path: ds/waveletMatrix.cpp
    title: waveletMatrix
  - icon: ':x:'
    path: misc/compression.cpp
    title: compression
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_frequency
    links:
    - https://judge.yosupo.jp/problem/static_range_frequency
  bundledCode: "#line 1 \"test/static_range_frequency.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_frequency\"\n\n#line 1 \"default/t.cpp\"\
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
    \ : v) val.emplace_back(p(x)); }\n};\n#line 1 \"ds/waveletMatrix.cpp\"\ntemplate<class\
    \ T, int H>\nstruct waveletMatrix {\n  using uint = uint32_t;\n  struct bitvec\
    \ {\n    static constexpr uint W = 64;\n    int cnt0 = 0, size;\n    vector<ull>\
    \ bv;\n    vector<int> pre;\n\n    bitvec(uint _size) : size(_size), bv(size /\
    \ W + 1), pre(size / W + 1) {};\n    void set(uint i) { bv[i / W] |= 1LL << (i\
    \ % W); }\n    uint get(uint i) { return bv[i / W] >> (i % W) & 1; }\n    void\
    \ build() {\n      for(int i = 1; i < ssize(pre); i++)\n        pre[i] = pre[i\
    \ - 1] + popcount(bv[i - 1]);\n      cnt0 = rank0(size);\n    }\n    int rank1(uint\
    \ i) { return pre[i / W] + popcount(bv[i / W] & ((1LL << i) - 1)); }\n    int\
    \ rank0(uint i) { return i - rank1(i); }\n  };\n\n  vector<bitvec> data;\n  waveletMatrix(vector<T>\
    \ init) : data(H + 1, bitvec(init.size())) {\n    for(int bit = H; auto &v : data)\
    \ {\n      for(int i = 0; i < ssize(init); i++)\n        if (init[i] >> bit &\
    \ 1)\n          v.set(i);\n      v.build();\n      vector<T> tmp(ssize(init));\n\
    \      int ptr[2] = {0, v.cnt0};\n      for(int i = 0; i < ssize(init); i++)\n\
    \        tmp[ptr[v.get(i)]++] = init[i];\n      init.swap(tmp);\n      bit--;\n\
    \    }\n  }\n\n  T kth(int l, int r, int k) {\n    T res = 0;\n    for(int bit\
    \ = H; auto &v : data) {\n      if (int l0 = v.rank0(l), r0 = v.rank0(r); r0 -\
    \ l0 <= k) {\n        res |= T(1) << bit, k -= r0 - l0;\n        l = v.cnt0 +\
    \ v.rank1(l), r = v.cnt0 + v.rank1(r);\n      } else {\n        l = l0, r = r0;\n\
    \      }\n      bit--;\n    }\n    return res;\n  }\n\n  int less(int l, int r,\
    \ T u) {\n    if (u >= (T(2) << H)) return r - l;\n    int cnt = 0;\n    for(int\
    \ bit = H; auto &v : data) {\n      if (u >> bit & 1) {\n        cnt += v.rank0(r)\
    \ - v.rank0(l);\n        l = v.cnt0 + v.rank1(l), r = v.cnt0 + v.rank1(r);\n \
    \     } else {\n        l = v.rank0(l), r = v.rank0(r);\n      }\n      bit--;\n\
    \    }\n    return cnt;\n  }\n\n  int rectQuery(int l, int r, T d, T u) {\n  \
    \  return less(l, r, u) - less(l, r, d);\n  }\n};\n#line 6 \"test/static_range_frequency.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ q; cin >> n >> q;\n  vector<int> a(n);\n  for(int &x : a)\n    cin >> x;\n\n\
    \  a.emplace_back(INT_MAX);\n  compression<int> xs(a);\n  waveletMatrix<int, 18>\
    \ wv(xs.ord);\n\n  while(q--) {\n    int l, r, x; cin >> l >> r >> x;\n    int\
    \ y = xs.lower_bound(x);\n    if (xs.val[y] != x)\n      cout << 0 << '\\n';\n\
    \    else\n      cout << wv.rectQuery(l, r, y, y + 1) << '\\n';\n  }\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../misc/compression.cpp\"\n#include\
    \ \"../ds/waveletMatrix.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<int> a(n);\n  for(int\
    \ &x : a)\n    cin >> x;\n\n  a.emplace_back(INT_MAX);\n  compression<int> xs(a);\n\
    \  waveletMatrix<int, 18> wv(xs.ord);\n\n  while(q--) {\n    int l, r, x; cin\
    \ >> l >> r >> x;\n    int y = xs.lower_bound(x);\n    if (xs.val[y] != x)\n \
    \     cout << 0 << '\\n';\n    else\n      cout << wv.rectQuery(l, r, y, y + 1)\
    \ << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - misc/compression.cpp
  - ds/waveletMatrix.cpp
  isVerificationFile: true
  path: test/static_range_frequency.test.cpp
  requiredBy: []
  timestamp: '2026-01-29 02:59:39+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/static_range_frequency.test.cpp
layout: document
redirect_from:
- /verify/test/static_range_frequency.test.cpp
- /verify/test/static_range_frequency.test.cpp.html
title: test/static_range_frequency.test.cpp
---
