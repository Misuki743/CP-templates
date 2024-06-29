---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: actedmonoid/actedMonoid_affineSum.cpp
    title: actedmonoid/actedMonoid_affineSum.cpp
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':question:'
    path: modint/MontgomeryModInt.cpp
    title: modint/MontgomeryModInt.cpp
  - icon: ':heavy_check_mark:'
    path: segtree/rangeSetSegmentTree.cpp
    title: segtree/rangeSetSegmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/range_set_range_composite
  bundledCode: "#line 1 \"test/range_set_range_composite.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_set_range_composite\"\n\n#line 1 \"\
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
    \ \"modint/MontgomeryModInt.cpp\"\n//reference: https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10\n\
    //note: mod should be a prime less than 2^30.\n\ntemplate<uint32_t mod>\nstruct\
    \ MontgomeryModInt {\n  using mint = MontgomeryModInt;\n  using i32 = int32_t;\n\
    \  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static constexpr u32 get_r()\
    \ {\n    u32 res = 1, base = mod;\n    for(i32 i = 0; i < 31; i++)\n      res\
    \ *= base, base *= base;\n    return -res;\n  }\n\n  static constexpr u32 get_mod()\
    \ {\n    return mod;\n  }\n\n  static constexpr u32 n2 = -u64(mod) % mod; //2^64\
    \ % mod\n  static constexpr u32 r = get_r(); //-P^{-1} % 2^32\n\n  u32 a;\n\n\
    \  static u32 reduce(const u64 &b) {\n    return (b + u64(u32(b) * r) * mod) >>\
    \ 32;\n  }\n\n  static u32 transform(const u64 &b) {\n    return reduce(u64(b)\
    \ * n2);\n  }\n\n  MontgomeryModInt() : a(0) {}\n  MontgomeryModInt(const int64_t\
    \ &b) \n    : a(transform(b % mod + mod)) {}\n\n  mint pow(u64 k) const {\n  \
    \  mint res(1), base(*this);\n    while(k) {\n      if (k & 1) \n        res *=\
    \ base;\n      base *= base, k >>= 1;\n    }\n    return res;\n  }\n\n  mint inverse()\
    \ const { return (*this).pow(mod - 2); }\n\n  u32 get() const {\n    u32 res =\
    \ reduce(a);\n    return res >= mod ? res - mod : res;\n  }\n\n  mint& operator+=(const\
    \ mint &b) {\n    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n\
    \  }\n\n  mint& operator-=(const mint &b) {\n    if (i32(a -= b.a) < 0) a += 2\
    \ * mod;\n    return *this;\n  }\n\n  mint& operator*=(const mint &b) {\n    a\
    \ = reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  mint& operator/=(const\
    \ mint &b) {\n    a = reduce(u64(a) * b.inverse().a);\n    return *this;\n  }\n\
    \n  mint operator-() { return mint() - mint(*this); }\n  bool operator==(mint\
    \ b) const {\n    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod :\
    \ b.a);\n  }\n  bool operator!=(mint b) const {\n    return (a >= mod ? a - mod\
    \ : a) != (b.a >= mod ? b.a - mod : b.a);\n  }\n\n  friend mint operator+(mint\
    \ a, mint b) { return a += b; }\n  friend mint operator-(mint a, mint b) { return\
    \ a -= b; }\n  friend mint operator*(mint a, mint b) { return a *= b; }\n  friend\
    \ mint operator/(mint a, mint b) { return a /= b; }\n\n  friend ostream& operator<<(ostream&\
    \ os, const mint& b) {\n    return os << b.get();\n  }\n  friend istream& operator>>(istream&\
    \ is, mint& b) {\n    int64_t val;\n    is >> val;\n    b = mint(val);\n    return\
    \ is;\n  }\n};\n\nusing mint = MontgomeryModInt<998244353>;\n#line 1 \"segtree/rangeSetSegmentTree.cpp\"\
    \ntemplate<class M, M(*id)(), M(*op)(const M&, const M&)>\nstruct rangeSetSegmentTree\
    \ {\n  vector<M> data, pre;\n  vector<int> tagId;\n  int size, nxt;\n\n  rangeSetSegmentTree(int\
    \ _size) : data(2 * _size, id()), pre(_size), tagId(_size, -1), size(_size), nxt(0)\
    \ {}\n\n  rangeSetSegmentTree(vector<M> init) : data(2 * ssize(init), id()), pre(ssize(init)),\
    \ tagId(ssize(init), -1), size(ssize(init)), nxt(0) {\n    copy(init.begin(),\
    \ init.end(), data.begin() + size);\n    for(int i = size - 1; i > 0; i--)\n \
    \     data[i] = op(data[i << 1], data[i << 1 | 1]);\n  }\n\n  void apply(int i,\
    \ int tId) {\n    data[i] = pre[tId];\n    if (i < size) tagId[i] = tId;\n  }\n\
    \n  void push(int i) {\n    for(int s = bit_width((unsigned)i) - 1; s > 0; s--)\
    \ {\n      if (tagId[i >> s] != -1) {\n        apply(i >> (s - 1), tagId[i >>\
    \ s] - 1);\n        apply(i >> (s - 1) ^ 1, tagId[i >> s] - 1);\n        tagId[i\
    \ >> s] = -1;\n      }\n    }\n  }\n\n  void pull(int i) {\n    while(i >>= 1)\
    \ data[i] = op(data[i << 1], data[i << 1 | 1]);\n  }\n\n  int trunc(unsigned i)\
    \ { return i >> countr_zero(i); }\n\n  void set(int i, M x) {\n    push(i + size);\n\
    \    data[i + size] = x;\n    pull(i + size);\n  }\n\n  M get(int i) {\n    push(i\
    \ + size);\n    return data[i + size];\n  }\n\n  void set(int l, int r, M x) {\n\
    \    if (l >= r or x == id()) return;\n    if (nxt + bit_width((unsigned)size)\
    \ > size) {\n      for(int i = 1; i < size; i++) {\n        if (tagId[i] != -1)\
    \ {\n          apply(i << 1, tagId[i] - 1);\n          apply(i << 1 | 1, tagId[i]\
    \ - 1);\n          tagId[i] = -1;\n        }\n      }\n      nxt = 0;\n    }\n\
    \    for(int i = 0; i < bit_width((unsigned)size); i++, x = op(x, x))\n      pre[nxt++]\
    \ = x;\n    push(trunc(l += size)), push(trunc(r += size) - 1);\n    int l0 =\
    \ l, r0 = r;\n    for(int tId = nxt - bit_width((unsigned)size); l < r; l >>=\
    \ 1, r >>= 1, tId++) {\n      if (l & 1) apply(l++, tId);\n      if (r & 1) apply(--r,\
    \ tId);\n    }\n    pull(trunc(l0)), pull(trunc(r0) - 1);\n  }\n\n  M query(int\
    \ l, int r) {\n    if (l >= r) return id();\n    M L = id(), R = id();\n    push(trunc(l\
    \ += size)), push(trunc(r += size) - 1);\n    for(; l < r; l >>= 1, r >>= 1) {\n\
    \      if (l & 1) L = op(L, data[l++]);\n      if (r & 1) R = op(data[--r], R);\n\
    \    }\n    return op(L, R);\n  }\n};\n#line 1 \"actedmonoid/actedMonoid_affineSum.cpp\"\
    \ntemplate<class U>\nstruct actedMonoid_affineSum {\n  using M = array<U, 2>;\n\
    \  static M Mid() { return M{0, 0}; }\n  static M Mop(const M &a, const M &b)\
    \ { return {a[0] + b[0], a[1] + b[1]}; }\n  using T = array<U, 2>;\n  static T\
    \ Tid() { return T{1, 0}; }\n  static T Top(const T &a, const T &b) { return T{a[0]\
    \ * b[0], a[1] * b[0] + b[1]}; }\n  static M act(const M &a, const T &b) { return\
    \ {a[0] * b[0] + a[1] * b[1], a[1]}; }\n};\n#line 7 \"test/range_set_range_composite.test.cpp\"\
    \n\nusing am = actedMonoid_affineSum<mint>;\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<am::T> ab(n);\n  for(auto\
    \ &[a, b] : ab)\n    cin >> a >> b;\n\n  rangeSetSegmentTree<am::T, am::Tid, am::Top>\
    \ st(ab);\n  while(q--) {\n    int t; cin >> t;\n    if (t == 0) {\n      int\
    \ l, r, c, d; cin >> l >> r >> c >> d;\n      st.set(l, r, am::T{c, d});\n   \
    \ } else {\n      int l, r, x; cin >> l >> r >> x;\n      cout << am::Top(am::T{0,\
    \ x}, st.query(l, r))[1] << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_set_range_composite\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../segtree/rangeSetSegmentTree.cpp\"\n#include \"../actedmonoid/actedMonoid_affineSum.cpp\"\
    \n\nusing am = actedMonoid_affineSum<mint>;\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<am::T> ab(n);\n  for(auto\
    \ &[a, b] : ab)\n    cin >> a >> b;\n\n  rangeSetSegmentTree<am::T, am::Tid, am::Top>\
    \ st(ab);\n  while(q--) {\n    int t; cin >> t;\n    if (t == 0) {\n      int\
    \ l, r, c, d; cin >> l >> r >> c >> d;\n      st.set(l, r, am::T{c, d});\n   \
    \ } else {\n      int l, r, x; cin >> l >> r >> x;\n      cout << am::Top(am::T{0,\
    \ x}, st.query(l, r))[1] << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/MontgomeryModInt.cpp
  - segtree/rangeSetSegmentTree.cpp
  - actedmonoid/actedMonoid_affineSum.cpp
  isVerificationFile: true
  path: test/range_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2024-04-05 18:02:52+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/range_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/range_set_range_composite.test.cpp
- /verify/test/range_set_range_composite.test.cpp.html
title: test/range_set_range_composite.test.cpp
---
