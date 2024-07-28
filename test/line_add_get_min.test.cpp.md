---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: segtree/lichaoSegmentTree.cpp
    title: segtree/lichaoSegmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/line_add_get_min.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\
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
    \ chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"segtree/lichaoSegmentTree.cpp\"\
    \n//note: size should be power of 2, finding min line in default\n\ntemplate<class\
    \ M, M unit>\nstruct lichaoSegmentTree {\n  vector<array<M, 2>> data;\n  vector<M>\
    \ xMid;\n  unsigned size;\n\n  lichaoSegmentTree(unsigned _size, vector<M> x =\
    \ vector<M>()) : data(2 * _size, {0, unit}), xMid(2 * _size), size(_size) {\n\
    \    assert(popcount(size) == 1);\n    if (x.empty()) {\n      iota(xMid.begin()\
    \ + size, xMid.end(), 0);\n    } else {\n      copy(x.begin(), x.end(), xMid.begin()\
    \ + size);\n      fill(xMid.begin() + size + ssize(x), xMid.end(), x.back());\n\
    \    }\n    vector<int> r(2 * size);\n    iota(r.begin() + size, r.end(), size);\n\
    \    for(int i = size - 1; i > 0; i--)\n      r[i] = r[i << 1 | 1];\n    for(int\
    \ i = size - 1; i > 0; i--)\n      xMid[i] = (xMid[r[i << 1]] + xMid[r[i << 1]\
    \ + 1]) / 2;\n  }\n\n  M eval(M a, M b, M x) { return a * x + b; }\n\n  void insert(int\
    \ v, M a, M b) {\n    if (a > data[v][0]) {\n      swap(a, data[v][0]);\n    \
    \  swap(b, data[v][1]);\n    }\n\n    if (v >= size) {\n      if (eval(a, b, xMid[v])\
    \ < eval(data[v][0], data[v][1], xMid[v])) {\n        swap(a, data[v][0]);\n \
    \       swap(b, data[v][1]);\n      }\n      return;\n    }\n\n    if (eval(a,\
    \ b, xMid[v]) > eval(data[v][0], data[v][1], xMid[v])) {\n      insert(v << 1\
    \ | 1, a, b);\n    } else {\n      swap(a, data[v][0]);\n      swap(b, data[v][1]);\n\
    \      insert(v << 1, a, b);\n    }\n  }\n\n  M query(int v) {\n    v += size;\n\
    \    M ans = unit;\n    int x = xMid[v];\n    while(v >= 1)\n      ans = min(ans,\
    \ eval(data[v][0], data[v][1], x)), v >>= 1;\n    return ans;\n  }\n\n  void insertRange(int\
    \ l, int r, M a, M b) {\n    for(l += size, r += size; l < r; l >>= 1, r >>= 1)\
    \ {\n      if (l & 1) insert(l++, a, b);\n      if (r & 1) insert(--r, a, b);\n\
    \    }\n  }\n};\n#line 5 \"test/line_add_get_min.test.cpp\"\n\nsigned main() {\n\
    \  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n\
    \  vector<array<ll, 2>> ab(n);\n  for(auto &[a, b] : ab)\n    cin >> a >> b;\n\
    \  vector<array<ll, 3>> query(q);\n  for(auto &[t, a, b] : query) {\n    cin >>\
    \ t >> a;\n    if (t == 0)\n      cin >> b;\n  }\n\n  vector<ll> pt;\n  for(auto\
    \ [t, a, b] : query)\n    if (t == 1)\n      pt.emplace_back(a);\n\n  ranges::sort(pt);\n\
    \  pt.resize(unique(pt.begin(), pt.end()) - pt.begin());\n  for(auto &[t, a, b]\
    \ : query)\n    if (t == 1)\n      a = ranges::lower_bound(pt, a) - pt.begin();\n\
    \n  lichaoSegmentTree<ll, LLONG_MAX> st(bit_ceil((unsigned)q), pt);\n  for(auto\
    \ [a, b] : ab)\n    st.insert(1, a, b);\n  for(auto [t, a, b] : query) {\n   \
    \ if (t == 0)\n      st.insert(1, a, b);\n    else\n      cout << st.query(a)\
    \ << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include \"../default/t.cpp\"\n#include \"../segtree/lichaoSegmentTree.cpp\"\n\
    \nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q;\
    \ cin >> n >> q;\n  vector<array<ll, 2>> ab(n);\n  for(auto &[a, b] : ab)\n  \
    \  cin >> a >> b;\n  vector<array<ll, 3>> query(q);\n  for(auto &[t, a, b] : query)\
    \ {\n    cin >> t >> a;\n    if (t == 0)\n      cin >> b;\n  }\n\n  vector<ll>\
    \ pt;\n  for(auto [t, a, b] : query)\n    if (t == 1)\n      pt.emplace_back(a);\n\
    \n  ranges::sort(pt);\n  pt.resize(unique(pt.begin(), pt.end()) - pt.begin());\n\
    \  for(auto &[t, a, b] : query)\n    if (t == 1)\n      a = ranges::lower_bound(pt,\
    \ a) - pt.begin();\n\n  lichaoSegmentTree<ll, LLONG_MAX> st(bit_ceil((unsigned)q),\
    \ pt);\n  for(auto [a, b] : ab)\n    st.insert(1, a, b);\n  for(auto [t, a, b]\
    \ : query) {\n    if (t == 0)\n      st.insert(1, a, b);\n    else\n      cout\
    \ << st.query(a) << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - segtree/lichaoSegmentTree.cpp
  isVerificationFile: true
  path: test/line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2024-07-28 21:04:51+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/line_add_get_min.test.cpp
- /verify/test/line_add_get_min.test.cpp.html
title: test/line_add_get_min.test.cpp
---
