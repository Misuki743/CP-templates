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
  - icon: ':question:'
    path: segtree/lazySegmentTree.cpp
    title: segtree/lazySegmentTree.cpp
  - icon: ':question:'
    path: segtree/ultraLazySegmentTree.cpp
    title: segtree/ultraLazySegmentTree.cpp
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
    \ clock chrono::steady_clock::now().time_since_epoch().count()\n\nusing namespace\
    \ std;\n\ntemplate<class T1, class T2>\nostream& operator<<(ostream& os, const\
    \ pair<T1, T2> pr) {\n  return os << pr.first << ' ' << pr.second;\n}\ntemplate<class\
    \ T, size_t N>\nostream& operator<<(ostream& os, const array<T, N> &arr) {\n \
    \ for(size_t i = 0; T x : arr) {\n    os << x;\n    if (++i != N) os << ' ';\n\
    \  }\n  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const\
    \ vector<T> &vec) {\n  for(size_t i = 0; T x : vec) {\n    os << x;\n    if (++i\
    \ != size(vec)) os << ' ';\n  }\n  return os;\n}\ntemplate<class T>\nostream&\
    \ operator<<(ostream& os, const set<T> &s) {\n  for(size_t i = 0; T x : s) {\n\
    \    os << x;\n    if (++i != size(s)) os << ' ';\n  }\n  return os;\n}\ntemplate<class\
    \ T1, class T2>\nostream& operator<<(ostream& os, const map<T1, T2> &m) {\n  for(size_t\
    \ i = 0; pair<T1, T2> x : m) {\n    os << x;\n    if (++i != size(m)) os << '\
    \ ';\n  }\n  return os;\n}\n\n#ifdef DEBUG\n#define dbg(...) cerr << '(', _do(#__VA_ARGS__),\
    \ cerr << \") = \", _do2(__VA_ARGS__)\ntemplate<typename T> void _do(T &&x) {\
    \ cerr << x; }\ntemplate<typename T, typename ...S> void _do(T &&x, S&&...y) {\
    \ cerr << x << \", \"; _do(y...); }\ntemplate<typename T> void _do2(T &&x) { cerr\
    \ << x << endl; }\ntemplate<typename T, typename ...S> void _do2(T &&x, S&&...y)\
    \ { cerr << x << \", \"; _do2(y...); }\n#else\n#define dbg(...)\n#endif\n\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing ldb = long double;\n\
    using pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate<typename T>\
    \ using min_heap = priority_queue<T, vector<T>, greater<T>>;\ntemplate<typename\
    \ T> using max_heap = priority_queue<T>;\n\ntemplate<ranges::forward_range rng,\
    \ class T = ranges::range_value_t<rng>, class OP = plus<T>>\nvoid pSum(rng &v)\
    \ {\n  if (!v.empty())\n    for(T p = v[0]; T &x : v | views::drop(1))\n     \
    \ x = p = OP()(p, x);\n}\ntemplate<ranges::forward_range rng, class T = ranges::range_value_t<rng>,\
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
    \ chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"modint/MontgomeryModInt.cpp\"\
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
    \ c, mint d) { return c += d; }\n  friend mint operator-(mint c, mint d) { return\
    \ c -= d; }\n  friend mint operator*(mint c, mint d) { return c *= d; }\n  friend\
    \ mint operator/(mint c, mint d) { return c /= d; }\n\n  friend ostream& operator<<(ostream&\
    \ os, const mint& b) {\n    return os << b.get();\n  }\n  friend istream& operator>>(istream&\
    \ is, mint& b) {\n    int64_t val;\n    is >> val;\n    b = mint(val);\n    return\
    \ is;\n  }\n};\n\nusing mint = MontgomeryModInt<998244353>;\n#line 1 \"segtree/lazySegmentTree.cpp\"\
    \ntemplate<class M, M(*Mid)(), M(*Mop)(const M&, const M&), class T, T(*Tid)(),\
    \ T(*Top)(const T&, const T&), M(*act)(const M&, const T&)>\nstruct lazySegmentTree\
    \ {\n  int size;\n  vector<M> data;\n  vector<T> tag;\n\n  lazySegmentTree(int\
    \ _size) : size(_size), data(2 * size, Mid()), tag(size, Tid()) {}\n\n  lazySegmentTree(vector<M>\
    \ init) : size(ssize(init)), data(2 * size, Mid()), tag(size, Tid()) {\n    ranges::copy(init,\
    \ data.begin() + size);\n    for(int i = size - 1; i > 0; i--)\n      data[i]\
    \ = Mop(data[i << 1], data[i << 1 | 1]);\n  }\n\n  void apply(int i, T x) {\n\
    \    data[i] = act(data[i], x);\n    if (i < size) tag[i] = Top(tag[i], x);\n\
    \  }\n\n  void push(unsigned i) {\n    for(int s = bit_width(i) - 1; s > 0; s--)\
    \ {\n      if (tag[i >> s] != Tid()) {\n        apply(i >> (s - 1), tag[i >> s]);\n\
    \        apply(i >> (s - 1) ^ 1, tag[i >> s]);\n        tag[i >> s] = Tid();\n\
    \      }\n    }\n  }\n\n  void pull(int i) {\n    while(i >>= 1) data[i] = Mop(data[i\
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
    \ i, function<bool(const M&)> f) {\n    vector<int> idL, idR;\n    push(trunc(i\
    \ + size)), push(trunc(size << 1) - 1);\n    for(int l = i + size, r = size <<\
    \ 1; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) idL.emplace_back(l++);\n   \
    \   if (r & 1) idR.emplace_back(--r);\n    }\n    idL.insert(idL.end(), idR.rbegin(),\
    \ idR.rend());\n    M pre = Mid();\n    int v = -1;\n    for(int j : idL) {\n\
    \      if (f(Mop(pre, data[j]))) {\n        v = j;\n        break;\n      } else\
    \ {\n        pre = Mop(pre, data[j]);\n      }\n    }\n    if (v == -1) return\
    \ size;\n    while(v < size) {\n      if (tag[v] != Tid()) {\n        apply(v\
    \ << 1, tag[v]);\n        apply(v << 1 | 1, tag[v]);\n        tag[v] = Tid();\n\
    \      }\n      if (f(Mop(pre, data[v << 1])))\n        v = v << 1;\n      else\n\
    \        pre = Mop(pre, data[v << 1]), v = v << 1 | 1;\n    }\n    return v -\
    \ size;\n  }\n\n  int lastTrue(int i, function<bool(const M&)> f) {\n    vector<int>\
    \ idL, idR;\n    push(trunc(size)), push(trunc((i + 1) + size) - 1);\n    for(int\
    \ l = size, r = (i + 1) + size; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) idL.emplace_back(l++);\n\
    \      if (r & 1) idR.emplace_back(--r);\n    }\n    idR.insert(idR.end(), idL.rbegin(),\
    \ idL.rend());\n    M suf = Mid();\n    int v = -1;\n    for(int j : idR) {\n\
    \      if (f(Mop(data[j], suf))) {\n        v = j;\n        break;\n      } else\
    \ {\n        suf = Mop(data[j], suf);\n      }\n    }\n    if (v == -1) return\
    \ -1;\n    while(v < size) {\n      if (tag[v] != Tid()) {\n        apply(v <<\
    \ 1, tag[v]);\n        apply(v << 1 | 1, tag[v]);\n        tag[v] = Tid();\n \
    \     }\n      if (f(Mop(data[v << 1 | 1], suf)))\n        v = v << 1 | 1;\n \
    \     else\n        suf = Mop(data[v << 1 | 1], suf), v = v << 1;\n    }\n   \
    \ return v - size;\n  }\n};\n#line 1 \"segtree/ultraLazySegmentTree.cpp\"\n//#include<segtree/lazySegmentTree.cpp>\n\
    \ntemplate<class AM>\nstruct ultraLazySegmentTree : lazySegmentTree<typename AM::M,\
    \ AM::Mid, AM::Mop, typename AM::T, AM::Tid, AM::Top, AM::act> {\n  using base\
    \ = lazySegmentTree<typename AM::M, AM::Mid, AM::Mop, typename AM::T, AM::Tid,\
    \ AM::Top, AM::act>;\n  ultraLazySegmentTree(vector<typename AM::M> init) : base(init)\
    \ {}\n  ultraLazySegmentTree(int size) : base(size) {}\n};\n#line 1 \"actedmonoid/actedMonoid_affineSum.cpp\"\
    \ntemplate<class U>\nstruct actedMonoid_affineSum {\n  using M = array<U, 2>;\n\
    \  static M Mid() { return M{0, 0}; }\n  static M Mop(const M &a, const M &b)\
    \ { return {a[0] + b[0], a[1] + b[1]}; }\n  using T = array<U, 2>;\n  static T\
    \ Tid() { return T{1, 0}; }\n  static T Top(const T &a, const T &b) { return T{a[0]\
    \ * b[0], a[1] * b[0] + b[1]}; }\n  static M act(const M &a, const T &b) { return\
    \ {a[0] * b[0] + a[1] * b[1], a[1]}; }\n};\n#line 8 \"test/range_affine_range_sum.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ q; cin >> n >> q;\n  vector<array<mint, 2>> a(n);\n  for(auto &[x, s] : a) {\n\
    \    cin >> x;\n    s = 1;\n  }\n\n  ultraLazySegmentTree<actedMonoid_affineSum<mint>>\
    \ st(a);\n  while(q--) {\n    int t; cin >> t;\n    if (t == 0) {\n      int l,\
    \ r, b, c; cin >> l >> r >> b >> c;\n      st.modify(l, r, array<mint, 2>{b, c});\n\
    \    } else {\n      int l, r; cin >> l >> r;\n      cout << st.query(l, r)[0]\
    \ << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../segtree/lazySegmentTree.cpp\"\n#include \"../segtree/ultraLazySegmentTree.cpp\"\
    \n#include \"../actedmonoid/actedMonoid_affineSum.cpp\"\n\nsigned main() {\n \
    \ ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n\
    \  vector<array<mint, 2>> a(n);\n  for(auto &[x, s] : a) {\n    cin >> x;\n  \
    \  s = 1;\n  }\n\n  ultraLazySegmentTree<actedMonoid_affineSum<mint>> st(a);\n\
    \  while(q--) {\n    int t; cin >> t;\n    if (t == 0) {\n      int l, r, b, c;\
    \ cin >> l >> r >> b >> c;\n      st.modify(l, r, array<mint, 2>{b, c});\n   \
    \ } else {\n      int l, r; cin >> l >> r;\n      cout << st.query(l, r)[0] <<\
    \ '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/MontgomeryModInt.cpp
  - segtree/lazySegmentTree.cpp
  - segtree/ultraLazySegmentTree.cpp
  - actedmonoid/actedMonoid_affineSum.cpp
  isVerificationFile: true
  path: test/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-08-02 21:56:58+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/range_affine_range_sum.test.cpp
- /verify/test/range_affine_range_sum.test.cpp.html
title: test/range_affine_range_sum.test.cpp
---
