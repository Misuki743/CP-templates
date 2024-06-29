---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: misc/rerootingDP.cpp
    title: misc/rerootingDP.cpp
  - icon: ':heavy_check_mark:'
    path: modint/MontgomeryModInt.cpp
    title: modint/MontgomeryModInt.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_path_composite_sum
    links:
    - https://judge.yosupo.jp/problem/tree_path_composite_sum
  bundledCode: "#line 1 \"test/tree_path_composite_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\n\n#line 1 \"default/t.cpp\"\
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
    \ x << ' ';\n  return os;\n}\n#line 1 \"modint/MontgomeryModInt.cpp\"\n//reference:\
    \ https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10\n\
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
    \ is;\n  }\n};\n\nusing mint = MontgomeryModInt<998244353>;\n#line 1 \"misc/rerootingDP.cpp\"\
    \ntemplate<class V, V(*base)(int), class E, E(*addEdge)(const V&, int eid),\n\
    E(*op)(const E&, const E&), V(*addVertex)(const E&, int vid)>\nvector<V> rerootingDP(vector<array<int,\
    \ 2>> e) {\n  int n = ssize(e) + 1;\n  vector<vector<int>> g(n);\n  for(int i\
    \ = 0; auto [u, v] : e)\n    g[u].emplace_back(i), g[v].emplace_back(i++);\n\n\
    \  vector<V> data(n);\n  for(int v = 0; v < n; v++) data[v] = base(v);\n  auto\
    \ precalc = [&](int v, int p, auto &&self) -> void {\n    bool leaf = true;\n\
    \    E prod;\n    for(int eid : g[v]) {\n      int x = e[eid][0] ^ e[eid][1] ^\
    \ v;\n      if (x == p) continue;\n      self(x, v, self);\n      if (leaf)\n\
    \        prod = addEdge(data[x], eid), leaf = false;\n      else\n        prod\
    \ = op(prod, addEdge(data[x], eid));\n    }\n    if (!leaf) data[v] = addVertex(prod,\
    \ v);\n  };\n\n  precalc(0, -1, precalc);\n\n  vector<V> ret(n);\n  auto reroot\
    \ = [&](int v, int p, auto &&self) -> void {\n    int deg = ssize(g[v]);\n   \
    \ vector<E> pre(deg), suf(deg);\n    for(int i = 0; int eid : g[v]) {\n      int\
    \ x = e[eid][0] ^ e[eid][1] ^ v;\n      pre[i] = suf[i] = addEdge(data[x], eid),\
    \ i++;\n    }\n    for(int i = 1; i < deg; i++) pre[i] = op(pre[i - 1], pre[i]);\n\
    \    for(int i = deg - 2; i >= 0; i--) suf[i] = op(suf[i], suf[i + 1]);\n    V\
    \ tmp = data[v];\n    ret[v] = data[v] = (deg ? addVertex(suf[0], v) : base(v));\n\
    \    for(int i = 0; int eid : g[v]) {\n      int x = e[eid][0] ^ e[eid][1] ^ v;\n\
    \      if (x != p) {\n        bool leaf = true;\n        E prod;\n        if (i\
    \ > 0) prod = pre[i - 1], leaf = false;\n        if (i + 1 < deg) prod = (leaf\
    \ ? suf[i + 1] : op(prod, suf[i + 1])), leaf = false;\n        V tmp2 = data[v];\n\
    \        data[v] = (leaf ? base(v) : addVertex(prod, v));\n        self(x, v,\
    \ self);\n        data[v] = tmp2;\n      }\n      i++;\n    }\n    data[v] = tmp;\n\
    \  };\n\n  reroot(0, -1, reroot);\n\n  return ret;\n}\n#line 6 \"test/tree_path_composite_sum.test.cpp\"\
    \n\nusing V = array<mint, 2>;\nusing E = array<mint, 2>;\n\nvector<mint> a, b,\
    \ c;\n\nV base(int i) { return {a[i], 1}; }\nE addEdge(const V &v, int i) { return\
    \ {b[i] * v[0] + c[i] * v[1], v[1]}; }\nE op(const E &l, const E &r) { return\
    \ {l[0] + r[0], l[1] + r[1]}; }\nV addVertex(const E &e, int i) { return {e[0]\
    \ + a[i], e[1] + 1}; }\n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\
    \n  int n; cin >> n;\n  a.resize(n);\n  for(mint &x : a) cin >> x;\n  vector<array<int,\
    \ 2>> e(n - 1);\n  b.resize(n - 1), c.resize(n - 1);\n  for(int i = 0; i < n -\
    \ 1; i++)\n    cin >> e[i][0] >> e[i][1] >> b[i] >> c[i];\n\n  auto ans = rerootingDP<V,\
    \ base, E, addEdge, op, addVertex>(e);\n  for(int i = 0; i < n; i++)\n    cout\
    \ << ans[i][0] << \" \\n\"[i + 1 == n];\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../misc/rerootingDP.cpp\"\n\nusing V = array<mint, 2>;\nusing E =\
    \ array<mint, 2>;\n\nvector<mint> a, b, c;\n\nV base(int i) { return {a[i], 1};\
    \ }\nE addEdge(const V &v, int i) { return {b[i] * v[0] + c[i] * v[1], v[1]};\
    \ }\nE op(const E &l, const E &r) { return {l[0] + r[0], l[1] + r[1]}; }\nV addVertex(const\
    \ E &e, int i) { return {e[0] + a[i], e[1] + 1}; }\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n; cin >> n;\n  a.resize(n);\n  for(mint &x : a) cin\
    \ >> x;\n  vector<array<int, 2>> e(n - 1);\n  b.resize(n - 1), c.resize(n - 1);\n\
    \  for(int i = 0; i < n - 1; i++)\n    cin >> e[i][0] >> e[i][1] >> b[i] >> c[i];\n\
    \n  auto ans = rerootingDP<V, base, E, addEdge, op, addVertex>(e);\n  for(int\
    \ i = 0; i < n; i++)\n    cout << ans[i][0] << \" \\n\"[i + 1 == n];\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/MontgomeryModInt.cpp
  - misc/rerootingDP.cpp
  isVerificationFile: true
  path: test/tree_path_composite_sum.test.cpp
  requiredBy: []
  timestamp: '2024-06-29 18:02:37+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree_path_composite_sum.test.cpp
layout: document
redirect_from:
- /verify/test/tree_path_composite_sum.test.cpp
- /verify/test/tree_path_composite_sum.test.cpp.html
title: test/tree_path_composite_sum.test.cpp
---
