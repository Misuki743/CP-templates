---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/waveletMatrix.cpp
    title: ds/waveletMatrix.cpp
  - icon: ':heavy_check_mark:'
    path: misc/compression.cpp
    title: compression
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_frequency
    links:
    - https://judge.yosupo.jp/problem/static_range_frequency
  bundledCode: "#line 1 \"test/static_range_frequency.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_frequency\"\n\n#line 1 \"default/t.cpp\"\
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
    \nnamespace R = std::ranges;\nnamespace V = std::views;\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing ull = unsigned long long;\nusing ldb = long double;\n\
    using pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate<class T>\n\
    ostream& operator<<(ostream& os, const pair<T, T> pr) {\n  return os << pr.first\
    \ << ' ' << pr.second;\n}\ntemplate<class T, size_t N>\nostream& operator<<(ostream&\
    \ os, const array<T, N> &arr) {\n  for(const T &X : arr)\n    os << X << ' ';\n\
    \  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const vector<T>\
    \ &vec) {\n  for(const T &X : vec)\n    os << X << ' ';\n  return os;\n}\ntemplate<class\
    \ T>\nostream& operator<<(ostream& os, const set<T> &s) {\n  for(const T &x :\
    \ s)\n    os << x << ' ';\n  return os;\n}\n#line 1 \"misc/compression.cpp\"\n\
    template<class T, bool duplicate = false>\nstruct compression {\n  vector<int>\
    \ ord;\n  vector<T> val;\n\n  compression(vector<T> &init) : val(init) { precompute();\
    \ }\n  compression(int size = 0) { val.reserve(size); }\n\n  void precompute()\
    \ {\n    vector<T> init = val;\n    ord.resize(ssize(val));\n    R::sort(val);\n\
    \    if constexpr (duplicate) {\n      vector<int> cnt(ssize(init));\n      iota(cnt.begin(),\
    \ cnt.end(), 0);\n      for(int i = 0; i < ssize(ord); i++)\n        ord[i] =\
    \ cnt[lower_bound(init[i])]++;\n    } else {\n      val.resize(unique(val.begin(),\
    \ val.end()) - val.begin());\n      for(int i = 0; i < ssize(ord); i++)\n    \
    \    ord[i] = lower_bound(init[i]);\n    }\n  }\n\n  int lower_bound(T x) { return\
    \ R::lower_bound(val, x) - val.begin(); }\n  int size() { return ssize(val); }\n\
    \  template<R::range rng, class proj = identity>\n  void mapping(rng &v, proj\
    \ p = {}) { for(auto &x : v) p(x) = lower_bound(p(x)); }\n  template<R::range\
    \ rng, class proj = identity>\n  void insert(rng &v, proj p = {}) { for(auto &x\
    \ : v) val.emplace_back(p(x)); }\n};\n#line 1 \"ds/waveletMatrix.cpp\"\ntemplate<class\
    \ T, int mxBit>\nstruct waveletMatrix {\n  struct bitvector {\n    static constexpr\
    \ uint W = 64;\n    int cnt0 = 0, size;\n    vector<ull> bv;\n    vector<int>\
    \ pre;\n\n    bitvector(uint _size) : size(_size), bv(_size / W + 1), pre(_size\
    \ / W + 1) {};\n    void set(uint i) { bv[i / W] |= 1LL << (i % W); }\n    uint\
    \ get(uint i) { return bv[i / W] >> (i % W) & 1; }\n    void build() {\n     \
    \ for(int i = 1; i < ssize(pre); i++)\n        pre[i] = pre[i - 1] + popcount(bv[i\
    \ - 1]);\n      cnt0 = rank0(size);\n    }\n    int rank1(uint i) { return pre[i\
    \ / W] + popcount(bv[i / W] & ((1LL << i) - 1)); }\n    int rank0(uint i) { return\
    \ i - rank1(i); }\n  };\n\n  vector<bitvector> level;\n  waveletMatrix(vector<T>\
    \ init) : level(mxBit + 1, bitvector(init.size())){\n    for(int bit = mxBit;\
    \ bit >= 0; bit--) {\n      for(int i = 0; i < ssize(init); i++)\n        if (init[i]\
    \ >> bit & 1)\n          level[bit].set(i);\n      level[bit].build();\n     \
    \ vector<T> tmp(ssize(init));\n      array<int, 2> ptr = {0, level[bit].cnt0};\n\
    \      for(int i = 0; i < ssize(init); i++) {\n        assert(ptr[level[bit].get(i)]\
    \ < ssize(tmp));\n        tmp[ptr[level[bit].get(i)]++] = init[i];\n      }\n\
    \      init.swap(tmp);\n    }\n  }\n\n  T kth(int l, int r, int k) {\n    T res\
    \ = 0;\n    for(int bit = mxBit; bit >= 0; bit--) {\n      if (int l0 = level[bit].rank0(l),\
    \ r0 = level[bit].rank0(r); r0 - l0 <= k) {\n        res |= T(1) << bit, k -=\
    \ r0 - l0;\n        l = level[bit].cnt0 + level[bit].rank1(l), r = level[bit].cnt0\
    \ + level[bit].rank1(r);\n      } else {\n        l = l0, r = r0;\n      }\n \
    \   }\n    return res;\n  }\n\n  int rangeLess(int l, int r, T u) {\n    if (u\
    \ >= (T(2) << mxBit)) return r - l;\n    int cnt = 0;\n    for(int bit = mxBit;\
    \ bit >= 0; bit--) {\n      if (u >> bit & 1) {\n        cnt += level[bit].rank0(r)\
    \ - level[bit].rank0(l);\n        l = level[bit].cnt0 + level[bit].rank1(l), r\
    \ = level[bit].cnt0 + level[bit].rank1(r);\n      } else {\n        l = level[bit].rank0(l),\
    \ r = level[bit].rank0(r);\n      }\n    }\n    return cnt;\n  }\n\n  int rectQuery(int\
    \ l, int r, T d, T u) {\n    return rangeLess(l, r, u) - rangeLess(l, r, d);\n\
    \  }\n};\n#line 6 \"test/static_range_frequency.test.cpp\"\n\nsigned main() {\n\
    \  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n\
    \  vector<int> a(n);\n  for(int &x : a)\n    cin >> x;\n\n  a.emplace_back(INT_MAX);\n\
    \  compression<int> xs(a);\n  waveletMatrix<int, 18> wv(xs.ord);\n\n  while(q--)\
    \ {\n    int l, r, x; cin >> l >> r >> x;\n    int y = xs.lower_bound(x);\n  \
    \  if (xs.val[y] != x)\n      cout << 0 << '\\n';\n    else\n      cout << wv.rectQuery(l,\
    \ r, y, y + 1) << '\\n';\n  }\n\n  return 0;\n}\n"
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
  timestamp: '2024-01-27 18:42:26+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/static_range_frequency.test.cpp
layout: document
redirect_from:
- /verify/test/static_range_frequency.test.cpp
- /verify/test/static_range_frequency.test.cpp.html
title: test/static_range_frequency.test.cpp
---
