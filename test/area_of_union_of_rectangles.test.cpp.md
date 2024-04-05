---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: actedmonoid/actedMonoid_addMinCnt.cpp
    title: actedmonoid/actedMonoid_addMinCnt.cpp
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: misc/areaOfUnionOfRectangles.cpp
    title: misc/areaOfUnionOfRectangles.cpp
  - icon: ':heavy_check_mark:'
    path: misc/compression.cpp
    title: compression
  - icon: ':heavy_check_mark:'
    path: segtree/lazySegmentTree.cpp
    title: segtree/lazySegmentTree.cpp
  - icon: ':heavy_check_mark:'
    path: segtree/ultraLazySegmentTree.cpp
    title: segtree/ultraLazySegmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/area_of_union_of_rectangles
    links:
    - https://judge.yosupo.jp/problem/area_of_union_of_rectangles
  bundledCode: "#line 1 \"test/area_of_union_of_rectangles.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/area_of_union_of_rectangles\"\n\n#line 1 \"\
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
    \ \"segtree/lazySegmentTree.cpp\"\ntemplate<class M, M(*Mid)(), M(*Mop)(const\
    \ M&, const M&), class T, T(*Tid)(), T(*Top)(const T&, const T&), M(*act)(const\
    \ M&, const T&)>\nstruct lazySegmentTree {\n  int size;\n  vector<M> data;\n \
    \ vector<T> tag;\n\n  lazySegmentTree(int _size) : size(_size), data(2 * size,\
    \ Mid()), tag(size, Tid()) {}\n\n  lazySegmentTree(vector<M> init) : size(ssize(init)),\
    \ data(2 * size, Mid()), tag(size, Tid()) {\n    ranges::copy(init, data.begin()\
    \ + size);\n    for(int i = size - 1; i > 0; i--)\n      data[i] = Mop(data[i\
    \ << 1], data[i << 1 | 1]);\n  }\n\n  void apply(int i, T x) {\n    data[i] =\
    \ act(data[i], x);\n    if (i < size) tag[i] = Top(tag[i], x);\n  }\n\n  void\
    \ push(unsigned i) {\n    for(int s = bit_width(i) - 1; s > 0; s--) {\n      if\
    \ (tag[i >> s] != Tid()) {\n        apply(i >> (s - 1), tag[i >> s]);\n      \
    \  apply(i >> (s - 1) ^ 1, tag[i >> s]);\n        tag[i >> s] = Tid();\n     \
    \ }\n    }\n  }\n\n  void pull(int i) {\n    while(i >>= 1) data[i] = Mop(data[i\
    \ << 1], data[i << 1 | 1]);\n  }\n\n  int trunc(unsigned i) { return i >> countr_zero(i);\
    \ }\n\n  void set(int i, M x) {\n    push(i += size);\n    data[i] = x;\n    pull(i);\n\
    \  }\n\n  M get(int i) { push(i += size); return data[i]; }\n\n  void modify(int\
    \ l, int r, T x) {\n    if (l >= r or x == Tid()) return;\n    push(trunc(l +=\
    \ size)), push(trunc(r += size) - 1);\n    int l0 = l, r0 = r;\n    for(; l <\
    \ r; l >>= 1, r >>= 1) {\n      if (l & 1) apply(l++, x);\n      if (r & 1) apply(--r,\
    \ x);\n    }\n    pull(trunc(l0)), pull(trunc(r0) - 1);\n  }\n\n  M query(int\
    \ l, int r) {\n    if (l >= r) return Mid();\n    M L = Mid(), R = Mid();\n  \
    \  push(trunc(l += size)), push(trunc(r += size) - 1);\n    for(; l < r; l >>=\
    \ 1, r >>= 1) {\n      if (l & 1) L = Mop(L, data[l++]);\n      if (r & 1) R =\
    \ Mop(data[--r], R);\n    }\n    return Mop(L, R);\n  }\n\n  int firstTrue(int\
    \ l, int r, function<bool(const M&)> f) {\n    vector<int> idL, idR;\n    int\
    \ r0 = r;\n    push(trunc(l + size)), push(trunc(r + size) - 1);\n    for(l +=\
    \ size, r += size; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) idL.emplace_back(l++);\n\
    \      if (r & 1) idR.emplace_back(--r);\n    }\n    while(!idR.empty()) {\n \
    \     idL.emplace_back(idR.back());\n      idR.pop_back();\n    }\n    M pre =\
    \ Mid();\n    int v = -1;\n    for(int i : idL) {\n      if (f(Mop(pre, data[i])))\
    \ {\n        v = i;\n        break;\n      } else {\n        pre = Mop(pre, data[i]);\n\
    \      }\n    }\n    if (v == -1)\n      return r0;\n    while(v < size) {\n \
    \     if (tag[v] != Tid()) {\n        apply(v << 1, tag[v]);\n        apply(v\
    \ << 1 | 1, tag[v]);\n        tag[v] = Tid();\n      }\n      if (f(Mop(pre, data[v\
    \ << 1])))\n        v = v << 1;\n      else\n        pre = Mop(pre, data[v <<\
    \ 1]), v = v << 1 | 1;\n    }\n    return v - size;\n  }\n};\n#line 1 \"segtree/ultraLazySegmentTree.cpp\"\
    \n//#include<segtree/lazySegmentTree.cpp>\n\ntemplate<class AM>\nstruct ultraLazySegmentTree\
    \ : lazySegmentTree<typename AM::M, AM::Mid, AM::Mop, typename AM::T, AM::Tid,\
    \ AM::Top, AM::act> {\n  using base = lazySegmentTree<typename AM::M, AM::Mid,\
    \ AM::Mop, typename AM::T, AM::Tid, AM::Top, AM::act>;\n  ultraLazySegmentTree(vector<typename\
    \ AM::M> init) : base(init) {}\n  ultraLazySegmentTree(int size) : base(size)\
    \ {}\n};\n#line 1 \"actedmonoid/actedMonoid_addMinCnt.cpp\"\ntemplate<class U>\n\
    struct actedMonoid_addMinCnt {\n  using M = pair<U, int>;\n  static M Mid() {\
    \ return make_pair(numeric_limits<U>::max(), 0); }\n  static M Mop(const M &a,\
    \ const M &b) { return a.first == b.first ? make_pair(a.first, a.second + b.second)\
    \ : min(a, b); }\n  using T = U;\n  static T Tid() { return T(0); }\n  static\
    \ T Top(const T &a, const T &b) { return a + b; }\n  static M act(const M &a,\
    \ const T &b) { return make_pair(a.first + b, a.second); }\n};\n#line 1 \"misc/compression.cpp\"\
    \ntemplate<class T, bool duplicate = false>\nstruct compression {\n  vector<int>\
    \ ord;\n  vector<T> val;\n\n  compression(vector<T> &init) : val(init) { precompute();\
    \ }\n  compression(int size = 0) { val.reserve(size); }\n\n  void precompute()\
    \ {\n    vector<T> init = val;\n    ord.resize(ssize(val));\n    ranges::sort(val);\n\
    \    if constexpr (duplicate) {\n      vector<int> cnt(ssize(init));\n      iota(cnt.begin(),\
    \ cnt.end(), 0);\n      for(int i = 0; i < ssize(ord); i++)\n        ord[i] =\
    \ cnt[lower_bound(init[i])]++;\n    } else {\n      val.resize(unique(val.begin(),\
    \ val.end()) - val.begin());\n      for(int i = 0; i < ssize(ord); i++)\n    \
    \    ord[i] = lower_bound(init[i]);\n    }\n  }\n\n  int lower_bound(T x) { return\
    \ ranges::lower_bound(val, x) - val.begin(); }\n  int size() { return ssize(val);\
    \ }\n  template<ranges::range rng, class proj = identity>\n  void mapping(rng\
    \ &v, proj p = {}) { for(auto &x : v) p(x) = lower_bound(p(x)); }\n  template<ranges::range\
    \ rng, class proj = identity>\n  void insert(rng &v, proj p = {}) { for(auto &x\
    \ : v) val.emplace_back(p(x)); }\n};\n#line 1 \"misc/areaOfUnionOfRectangles.cpp\"\
    \n//#include<segtree/lazySegmentTree.cpp>\n//#include<segtree/ultraLazySegmentTree.cpp>\n\
    //#include<actedmonoid/actedMonoid_addMinCnt.cpp>\n//#include<misc/compression.cpp>\n\
    \ntemplate<class T1, class T2>\nT2 areaOfUnionOfRectangles(vector<array<T1, 4>>\
    \ rect) {\n  compression<T1> xs(2 * ssize(rect)), ys(2 * ssize(rect));\n  xs.insert(rect,\
    \ [](auto &x) { return x[0]; });\n  xs.insert(rect, [](auto &x) { return x[1];\
    \ });\n  ys.insert(rect, [](auto &x) { return x[2]; });\n  ys.insert(rect, [](auto\
    \ &x) { return x[3]; });\n  xs.precompute();\n  ys.precompute();\n  xs.mapping(rect,\
    \ [](auto &x) -> T1& { return x[0]; });\n  xs.mapping(rect, [](auto &x) -> T1&\
    \ { return x[1]; });\n  ys.mapping(rect, [](auto &x) -> T1& { return x[2]; });\n\
    \  ys.mapping(rect, [](auto &x) -> T1& { return x[3]; });\n\n  vector<tuple<T1,\
    \ int, int>> add;\n  add.reserve(ssize(rect));\n  for(int i = 0; auto &[l, r,\
    \ _, __] : rect) {\n    add.emplace_back(l, 1, i);\n    add.emplace_back(r, -1,\
    \ i++);\n  }\n  ranges::sort(add, {}, [](auto &x) { return get<0>(x); });\n\n\
    \  vector<pair<T1, T1>> init(ys.size() - 1);\n  for(int i = 0; i + 1 < ys.size();\
    \ i++)\n    init[i] = make_pair(T1(0), ys.val[i + 1] - ys.val[i]);\n  ultraLazySegmentTree<actedMonoid_addMinCnt<T1>>\
    \ st(init);\n\n  T2 ans = 0;\n  for(int i = 1, ptr = 0; i < xs.size(); i++) {\n\
    \    while(ptr < ssize(add) and get<0>(add[ptr]) < i) {\n      auto [x, r, i]\
    \ = add[ptr++];\n      auto [_, __, d, u] = rect[i];\n      st.modify(d, u, r);\n\
    \    }\n    ans += T2(xs.val[i] - xs.val[i - 1]) * ((ys.val.back() - ys.val[0])\
    \ - actedMonoid_addMinCnt<T1>::Mop(st.query(0, st.size), make_pair(0, 0)).second);\n\
    \  }\n\n  return ans;\n}\n#line 9 \"test/area_of_union_of_rectangles.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n;\
    \ cin >> n;\n  vector<array<int, 4>> rect(n);\n  for(auto &[l, r, d, u] : rect)\n\
    \    cin >> l >> d >> r >> u;\n\n  cout << areaOfUnionOfRectangles<int, ll>(rect)\
    \ << '\\n';\n\n  return 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/area_of_union_of_rectangles\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../segtree/lazySegmentTree.cpp\"\
    \n#include \"../segtree/ultraLazySegmentTree.cpp\"\n#include \"../actedmonoid/actedMonoid_addMinCnt.cpp\"\
    \n#include \"../misc/compression.cpp\"\n#include \"../misc/areaOfUnionOfRectangles.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n;\
    \ cin >> n;\n  vector<array<int, 4>> rect(n);\n  for(auto &[l, r, d, u] : rect)\n\
    \    cin >> l >> d >> r >> u;\n\n  cout << areaOfUnionOfRectangles<int, ll>(rect)\
    \ << '\\n';\n\n  return 0;\n}\n\n"
  dependsOn:
  - default/t.cpp
  - segtree/lazySegmentTree.cpp
  - segtree/ultraLazySegmentTree.cpp
  - actedmonoid/actedMonoid_addMinCnt.cpp
  - misc/compression.cpp
  - misc/areaOfUnionOfRectangles.cpp
  isVerificationFile: true
  path: test/area_of_union_of_rectangles.test.cpp
  requiredBy: []
  timestamp: '2024-04-05 18:02:52+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/area_of_union_of_rectangles.test.cpp
layout: document
redirect_from:
- /verify/test/area_of_union_of_rectangles.test.cpp
- /verify/test/area_of_union_of_rectangles.test.cpp.html
title: test/area_of_union_of_rectangles.test.cpp
---
