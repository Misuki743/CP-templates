---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwickTree.cpp
    title: ds/fenwickTree.cpp
  - icon: ':heavy_check_mark:'
    path: misc/compression.cpp
    title: compression
  - icon: ':heavy_check_mark:'
    path: misc/rangeCountDistinct.cpp
    title: misc/rangeCountDistinct.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_count_distinct
    links:
    - https://judge.yosupo.jp/problem/static_range_count_distinct
  bundledCode: "#line 1 \"test/static_range_count_distinct.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_count_distinct\"\n\n#line 1 \"\
    default/t.cpp\"\n#include <algorithm>\n#include <array>\n#include <bit>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cctype>\n#include <cfenv>\n#include\
    \ <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include <climits>\n#include\
    \ <cmath>\n#include <compare>\n#include <complex>\n#include <concepts>\n#include\
    \ <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <deque>\n#include <fstream>\n#include\
    \ <functional>\n#include <initializer_list>\n#include <iomanip>\n#include <ios>\n\
    #include <iostream>\n#include <istream>\n#include <iterator>\n#include <limits>\n\
    #include <list>\n#include <map>\n#include <memory>\n#include <new>\n#include <numbers>\n\
    #include <numeric>\n#include <ostream>\n#include <queue>\n#include <random>\n\
    #include <ranges>\n#include <set>\n#include <span>\n#include <sstream>\n#include\
    \ <stack>\n#include <streambuf>\n#include <string>\n#include <tuple>\n#include\
    \ <type_traits>\n#include <variant>\n\n#define INT128_MAX (__int128)(((unsigned\
    \ __int128) 1 << ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN\
    \ (-INT128_MAX - 1)\n\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ldb = long double;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\
    \ntemplate<class T>\nostream& operator<<(ostream& os, const pair<T, T> pr) {\n\
    \  return os << pr.first << ' ' << pr.second;\n}\ntemplate<class T, size_t N>\n\
    ostream& operator<<(ostream& os, const array<T, N> &arr) {\n  for(const T &X :\
    \ arr)\n    os << X << ' ';\n  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream&\
    \ os, const vector<T> &vec) {\n  for(const T &X : vec)\n    os << X << ' ';\n\
    \  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const set<T>\
    \ &s) {\n  for(const T &x : s)\n    os << x << ' ';\n  return os;\n}\n#line 1\
    \ \"ds/fenwickTree.cpp\"\ntemplate<class T>\nstruct fenwickTree {\n  const int\
    \ size;\n  vector<T> data;\n\n  fenwickTree(int _size) : size(_size + 1), data(_size\
    \ + 1) {}\n  fenwickTree(vector<T> &init) : size(ssize(init) + 1), data(ssize(init)\
    \ + 1) {\n    partial_sum(init.begin(), init.end(), data.begin() + 1);\n    for(int\
    \ i = size - 1; i > 0; i--)\n      data[i] -= data[i - (i & (-i))];\n  }\n\n \
    \ void add(int i, T d) {\n    for(i += 1; i < size; i += i & (-i))\n      data[i]\
    \ += d;\n  }\n\n  T query(int i) {\n    T res = T(0);\n    for(i += 1; i > 0;\
    \ i -= i & (-i))\n      res += data[i];\n    return res;\n  }\n\n  T query(int\
    \ l, int r) { //query [l, r)\n    return query(r - 1) - query(l - 1);\n  }\n};\n\
    #line 1 \"misc/compression.cpp\"\ntemplate<class T, bool duplicate = false>\n\
    struct compression {\n  vector<int> ord;\n  vector<T> val;\n\n  compression(vector<T>\
    \ &init) : val(init) { precompute(); }\n  compression(int size = 0) { val.reserve(size);\
    \ }\n\n  void precompute() {\n    vector<T> init = val;\n    ord.resize(ssize(val));\n\
    \    ranges::sort(val);\n    if constexpr (duplicate) {\n      vector<int> cnt(ssize(init));\n\
    \      iota(cnt.begin(), cnt.end(), 0);\n      for(int i = 0; i < ssize(ord);\
    \ i++)\n        ord[i] = cnt[lower_bound(init[i])]++;\n    } else {\n      val.resize(unique(val.begin(),\
    \ val.end()) - val.begin());\n      for(int i = 0; i < ssize(ord); i++)\n    \
    \    ord[i] = lower_bound(init[i]);\n    }\n  }\n\n  int lower_bound(T x) { return\
    \ ranges::lower_bound(val, x) - val.begin(); }\n  int size() { return ssize(val);\
    \ }\n  template<ranges::range rng, class proj = identity>\n  void mapping(rng\
    \ &v, proj p = {}) { for(auto &x : v) p(x) = lower_bound(p(x)); }\n  template<ranges::range\
    \ rng, class proj = identity>\n  void insert(rng &v, proj p = {}) { for(auto &x\
    \ : v) val.emplace_back(p(x)); }\n};\n#line 1 \"misc/rangeCountDistinct.cpp\"\n\
    //#include<ds/fenwickTree.cpp>\n//#include<misc/compression.cpp>\n\ntemplate<class\
    \ T>\nvector<int> rangeCountDistinct(vector<T> a, vector<array<int, 2>> query)\
    \ {\n  vector<int> b = [&]() {\n    compression ys(a);\n    return ys.ord;\n \
    \ }();\n\n  vector<int> qId(ssize(query));\n  iota(qId.begin(), qId.end(), 0);\n\
    \  ranges::sort(qId, less<int>{}, [&](auto &i) { return query[i][1]; });\n\n \
    \ fenwickTree<int> ft(ssize(a));\n  vector<int> ans(ssize(query)), pos(ssize(b),\
    \ -1);\n  for(int ptr = 0; int i : qId) {\n    auto [l, r] = query[i];\n    if\
    \ (l == r) continue;\n    while(ptr < r) {\n      ft.add(pos[b[ptr]] + 1, 1);\n\
    \      ft.add(ptr + 1, -1);\n      pos[b[ptr]] = ptr, ptr++;\n    }\n    ans[i]\
    \ = ft.query(l);\n  }\n\n  return ans;\n}\n#line 7 \"test/static_range_count_distinct.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ q; cin >> n >> q;\n  vector<int> a(n);\n  for(int &x : a)\n    cin >> x;\n \
    \ vector<array<int, 2>> query(q);\n  for(auto &[l, r] : query)\n    cin >> l >>\
    \ r;\n\n  for(int x : rangeCountDistinct(a, query))\n    cout << x << '\\n';\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_count_distinct\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../ds/fenwickTree.cpp\"\n#include\
    \ \"../misc/compression.cpp\"\n#include \"../misc/rangeCountDistinct.cpp\"\n\n\
    signed main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q;\
    \ cin >> n >> q;\n  vector<int> a(n);\n  for(int &x : a)\n    cin >> x;\n  vector<array<int,\
    \ 2>> query(q);\n  for(auto &[l, r] : query)\n    cin >> l >> r;\n\n  for(int\
    \ x : rangeCountDistinct(a, query))\n    cout << x << '\\n';\n\n  return 0;\n\
    }\n"
  dependsOn:
  - default/t.cpp
  - ds/fenwickTree.cpp
  - misc/compression.cpp
  - misc/rangeCountDistinct.cpp
  isVerificationFile: true
  path: test/static_range_count_distinct.test.cpp
  requiredBy: []
  timestamp: '2024-04-05 18:02:52+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/static_range_count_distinct.test.cpp
layout: document
redirect_from:
- /verify/test/static_range_count_distinct.test.cpp
- /verify/test/static_range_count_distinct.test.cpp.html
title: test/static_range_count_distinct.test.cpp
---