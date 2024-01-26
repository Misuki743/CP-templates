---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: modint/MontgomeryModInt.cpp
    title: modint/MontgomeryModInt.cpp
  - icon: ':heavy_check_mark:'
    path: segtree/lazySegmentTree.cpp
    title: segtree/lazySegmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/range_affine_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n#line 1 \"default/t.cpp\"\
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
    \ s)\n    os << x << ' ';\n  return os;\n}\n#line 1 \"modint/MontgomeryModInt.cpp\"\
    \n//reference: https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10\n\
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
    \ is;\n  }\n};\n\nusing mint = MontgomeryModInt<998244353>;\n#line 1 \"segtree/lazySegmentTree.cpp\"\
    \ntemplate<class M, class T, M(*Munit)(), T(*Tunit)(), M(*Mope)(const M&, const\
    \ M&), T(*Tope)(const T&, const T&), M(*comp)(const M&, const T&)>\nstruct lazySegmentTree\
    \ {\n  vector<M> data;\n  vector<T> tag;\n  int size;\n\n  lazySegmentTree(int\
    \ _size) : data(2 * _size, Munit()), tag(_size, Tunit()), size(_size) {}\n\n \
    \ lazySegmentTree(vector<M> init) : data(2 * ssize(init), Munit()), tag(ssize(init),\
    \ Tunit()), size(ssize(init)) {\n    copy(init.begin(), init.end(), data.begin()\
    \ + size);\n    for(int i = size - 1; i > 0; i--)\n      data[i] = Mope(data[i\
    \ << 1], data[i << 1 | 1]);\n  }\n\n  void apply(int i, T x) {\n    data[i] =\
    \ comp(data[i], x);\n    if (i < size) tag[i] = Tope(tag[i], x);\n  }\n\n  void\
    \ push(int i) {\n    for(int s = bit_width((unsigned)i) - 1; s > 0; s--) {\n \
    \     if (tag[i >> s] != Tunit()) {\n        apply(i >> (s - 1), tag[i >> s]);\n\
    \        apply(i >> (s - 1) ^ 1, tag[i >> s]);\n        tag[i >> s] = Tunit();\n\
    \      }\n    }\n  }\n\n  void pull(int i) {\n    while(i >>= 1) data[i] = Mope(data[i\
    \ << 1], data[i << 1 | 1]);\n  }\n\n  int trunc(unsigned i) { return i >> countr_zero(i);\
    \ }\n\n  void set(int i, M x) {\n    push(i + size);\n    data[i + size] = x;\n\
    \    pull(i + size);\n  }\n\n  M get(int i) {\n    push(i + size);\n    return\
    \ data[i + size];\n  }\n\n  void modify(int l, int r, T x) {\n    if (x == Tunit())\
    \ return;\n    push(trunc(l += size)), push(trunc(r += size) - 1);\n    int l0\
    \ = l, r0 = r;\n    for(; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) apply(l++,\
    \ x);\n      if (r & 1) apply(--r, x);\n    }\n    pull(trunc(l0)), pull(trunc(r0)\
    \ - 1);\n  }\n\n  M query(int l, int r) {\n    M L = Munit(), R = Munit();\n \
    \   push(trunc(l += size)), push(trunc(r += size) - 1);\n    for(; l < r; l >>=\
    \ 1, r >>= 1) {\n      if (l & 1) L = Mope(L, data[l++]);\n      if (r & 1) R\
    \ = Mope(data[--r], R);\n    }\n    return Mope(L, R);\n  }\n\n  int firstTrue(int\
    \ l, int r, function<bool(const M&)> f) {\n    vector<int> idL, idR;\n    int\
    \ r0 = r;\n    push(trunc(l + size)), push(trunc(r + size) - 1);\n    for(l +=\
    \ size, r += size; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) idL.emplace_back(l++);\n\
    \      if (r & 1) idR.emplace_back(--r);\n    }\n    while(!idR.empty()) {\n \
    \     idL.emplace_back(idR.back());\n      idR.pop_back();\n    }\n    M pre =\
    \ Munit();\n    int v = -1;\n    for(int i : idL) {\n      if (f(Mope(pre, data[i])))\
    \ {\n        v = i;\n        break;\n      } else {\n        pre = Mope(pre, data[i]);\n\
    \      }\n    }\n    if (v == -1)\n      return r0;\n    while(v < size) {\n \
    \     if (tag[v] != Tunit()) {\n        apply(v << 1, tag[v]);\n        apply(v\
    \ << 1 | 1, tag[v]);\n        tag[v] = Tunit();\n      }\n      if (f(Mope(pre,\
    \ data[v << 1])))\n        v = v << 1;\n      else\n        pre = Mope(pre, data[v\
    \ << 1]), v = v << 1 | 1;\n    }\n    return v - size;\n  }\n};\n#line 6 \"test/range_affine_range_sum.test.cpp\"\
    \n\nusing monoid = array<mint, 2>;\nusing tag = array<mint, 2>;\nmonoid Munit()\
    \ { return monoid{0, 0}; }\ntag Tunit() { return tag{1, 0}; }\nmonoid Mope(const\
    \ monoid &l, const monoid &r) { return {l[0] + r[0], l[1] + r[1]}; }\ntag Tope(const\
    \ tag &l, const tag &r) { return tag{l[0] * r[0], l[1] * r[0] + r[1]}; }\nmonoid\
    \ comp(const monoid &l, const tag &r) { return {l[0] * r[0] + l[1] * r[1], l[1]};\
    \ }\n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int\
    \ n, q; cin >> n >> q;\n  vector<monoid> a(n);\n  for(auto &[x, s] : a) {\n  \
    \  cin >> x;\n    s = 1;\n  }\n\n  lazySegmentTree<monoid, tag, Munit, Tunit,\
    \ Mope, Tope, comp> st(a);\n  while(q--) {\n    int t; cin >> t;\n    if (t ==\
    \ 0) {\n      int l, r, b, c; cin >> l >> r >> b >> c;\n      st.modify(l, r,\
    \ tag{b, c});\n    } else {\n      int l, r; cin >> l >> r;\n      cout << st.query(l,\
    \ r)[0] << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../segtree/lazySegmentTree.cpp\"\n\nusing monoid = array<mint, 2>;\n\
    using tag = array<mint, 2>;\nmonoid Munit() { return monoid{0, 0}; }\ntag Tunit()\
    \ { return tag{1, 0}; }\nmonoid Mope(const monoid &l, const monoid &r) { return\
    \ {l[0] + r[0], l[1] + r[1]}; }\ntag Tope(const tag &l, const tag &r) { return\
    \ tag{l[0] * r[0], l[1] * r[0] + r[1]}; }\nmonoid comp(const monoid &l, const\
    \ tag &r) { return {l[0] * r[0] + l[1] * r[1], l[1]}; }\n\nsigned main() {\n \
    \ ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n\
    \  vector<monoid> a(n);\n  for(auto &[x, s] : a) {\n    cin >> x;\n    s = 1;\n\
    \  }\n\n  lazySegmentTree<monoid, tag, Munit, Tunit, Mope, Tope, comp> st(a);\n\
    \  while(q--) {\n    int t; cin >> t;\n    if (t == 0) {\n      int l, r, b, c;\
    \ cin >> l >> r >> b >> c;\n      st.modify(l, r, tag{b, c});\n    } else {\n\
    \      int l, r; cin >> l >> r;\n      cout << st.query(l, r)[0] << '\\n';\n \
    \   }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/MontgomeryModInt.cpp
  - segtree/lazySegmentTree.cpp
  isVerificationFile: true
  path: test/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/range_affine_range_sum.test.cpp
- /verify/test/range_affine_range_sum.test.cpp.html
title: test/range_affine_range_sum.test.cpp
---
