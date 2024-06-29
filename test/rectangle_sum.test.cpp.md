---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':x:'
    path: ds/fenwickTree.cpp
    title: ds/fenwickTree.cpp
  - icon: ':question:'
    path: misc/compression.cpp
    title: compression
  - icon: ':x:'
    path: misc/rectangleSum.cpp
    title: misc/rectangleSum.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"test/rectangle_sum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\
    \n\n#line 1 \"default/t.cpp\"\n#include <algorithm>\n#include <array>\n#include\
    \ <bit>\n#include <bitset>\n#include <cassert>\n#include <cctype>\n#include <cfenv>\n\
    #include <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include <climits>\n\
    #include <cmath>\n#include <compare>\n#include <complex>\n#include <concepts>\n\
    #include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include <cstdio>\n\
    #include <cstdlib>\n#include <cstring>\n#include <deque>\n#include <fstream>\n\
    #include <functional>\n#include <initializer_list>\n#include <iomanip>\n#include\
    \ <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n#include\
    \ <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include <new>\n\
    #include <numbers>\n#include <numeric>\n#include <ostream>\n#include <queue>\n\
    #include <random>\n#include <ranges>\n#include <set>\n#include <span>\n#include\
    \ <sstream>\n#include <stack>\n#include <streambuf>\n#include <string>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <variant>\n\n#define INT128_MAX (__int128)(((unsigned\
    \ __int128) 1 << ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN\
    \ (-INT128_MAX - 1)\n\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
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
    \ x << ' ';\n  return os;\n}\n#line 1 \"ds/fenwickTree.cpp\"\ntemplate<class T>\n\
    struct fenwickTree {\n  const int size;\n  vector<T> data;\n\n  fenwickTree(int\
    \ _size) : size(_size + 1), data(_size + 1) {}\n  fenwickTree(vector<T> &init)\
    \ : size(ssize(init) + 1), data(ssize(init) + 1) {\n    partial_sum(init.begin(),\
    \ init.end(), data.begin() + 1);\n    for(int i = size - 1; i > 0; i--)\n    \
    \  data[i] -= data[i - (i & (-i))];\n  }\n\n  void add(int i, T d) {\n    for(i\
    \ += 1; i < size; i += i & (-i))\n      data[i] += d;\n  }\n\n  T query(int i)\
    \ {\n    T res = T(0);\n    for(i += 1; i > 0; i -= i & (-i))\n      res += data[i];\n\
    \    return res;\n  }\n\n  T query(int l, int r) { //query [l, r)\n    return\
    \ query(r - 1) - query(l - 1);\n  }\n};\n#line 1 \"misc/compression.cpp\"\ntemplate<class\
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
    \ : v) val.emplace_back(p(x)); }\n};\n#line 1 \"misc/rectangleSum.cpp\"\n//#include<ds/fenwickTree.cpp>\n\
    //#include<misc/compression.cpp>\n\ntemplate<class T1, class T2>\nvector<T2> rectangleSum(vector<tuple<T1,\
    \ T1, T2>> pt, vector<array<T1, 4>> query) {\n  compression<T1> ys(ssize(pt));\n\
    \  ys.insert(pt, [](auto &x) { return get<1>(x); });\n  ys.precompute();\n  ys.mapping(pt,\
    \ [](auto &x) -> T1& { return get<1>(x); });\n  ys.mapping(query, [](auto &x)\
    \ -> T1& { return x[2]; });\n  ys.mapping(query, [](auto &x) -> T1& { return x[3];\
    \ });\n\n  ranges::sort(pt, less<T1>{}, [](auto x) { return get<0>(x); });\n\n\
    \  vector<tuple<T1, int, int>> qry;\n  qry.reserve(2 * ssize(query));\n  for(int\
    \ i = 0; i < ssize(query); i++) {\n    qry.emplace_back(query[i][0] - 1, -1, i);\n\
    \    qry.emplace_back(query[i][1] - 1, 1, i);\n  }\n  ranges::sort(qry, {}, [](auto\
    \ &x) { return get<0>(x); });\n\n  fenwickTree<T2> bit(ys.size());\n  vector<T2>\
    \ ans(ssize(query));\n  for(int ptr = 0; auto [x, r, i] : qry) {\n    while(ptr\
    \ < ssize(pt) and get<0>(pt[ptr]) <= x) {\n      auto [_, y, w] = pt[ptr++];\n\
    \      bit.add(y, w);\n    }\n    ans[i] += r * bit.query(query[i][2], query[i][3]);\n\
    \  }\n\n  return ans;\n}\n#line 7 \"test/rectangle_sum.test.cpp\"\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin >> n >>\
    \ q;\n  vector<tuple<int, int, ll>> pts(n);\n  for(auto &[x, y, w] : pts)\n  \
    \  cin >> x >> y >> w;\n  vector<array<int, 4>> query(q);\n  for(auto &[l, d,\
    \ r, u] : query)\n    cin >> l >> r >> d >> u;\n\n  for(ll ans : rectangleSum(pts,\
    \ query))\n    cout << ans << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ \"../default/t.cpp\"\n#include \"../ds/fenwickTree.cpp\"\n#include \"../misc/compression.cpp\"\
    \n#include \"../misc/rectangleSum.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<tuple<int, int, ll>>\
    \ pts(n);\n  for(auto &[x, y, w] : pts)\n    cin >> x >> y >> w;\n  vector<array<int,\
    \ 4>> query(q);\n  for(auto &[l, d, r, u] : query)\n    cin >> l >> r >> d >>\
    \ u;\n\n  for(ll ans : rectangleSum(pts, query))\n    cout << ans << '\\n';\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - ds/fenwickTree.cpp
  - misc/compression.cpp
  - misc/rectangleSum.cpp
  isVerificationFile: true
  path: test/rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2024-06-29 18:02:37+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/rectangle_sum.test.cpp
- /verify/test/rectangle_sum.test.cpp.html
title: test/rectangle_sum.test.cpp
---
