---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/potentialDSU.cpp
    title: ds/potentialDSU.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group
    links:
    - https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group
  bundledCode: "#line 1 \"test/unionfind_with_potential_non_commutative_group.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group\"\
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
    \ chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"ds/potentialDSU.cpp\"\
    \ntemplate<class G, G(*id)(), G(*op)(const G&, const G&), G(*inv)(const G&)>\n\
    struct DSU {\n  vector<int> bos, sz;\n  vector<G> _pot;\n  int size;\n\n  DSU(int\
    \ _size) : bos(_size), sz(_size, 1), _pot(_size, id()), size(_size) {\n    iota(bos.begin(),\
    \ bos.end(), 0);\n  }\n\n  int query(int v) {\n    if (bos[v] == v) {\n      return\
    \ v;\n    } else {\n      int tmp = query(bos[v]);\n      _pot[v] = op(_pot[bos[v]],\
    \ _pot[v]);\n      return bos[v] = tmp;\n    }\n  }\n\n  //op(v1, d) = v2\n  bool\
    \ merge(int v1, int v2, G d) {\n    int b1 = query(v1), b2 = query(v2);\n\n  \
    \  if (b1 == b2)\n      return op(inv(_pot[v1]), _pot[v2]) == d;\n\n    if (sz[b1]\
    \ > sz[b2]) {\n      swap(b1, b2), swap(v1, v2);\n      d = inv(d);\n    }\n \
    \   bos[b1] = b2, sz[b2] += sz[b1], _pot[b1] = op(op(_pot[v2], inv(d)), inv(_pot[v1]));\n\
    \n    return true;\n  }\n\n  //op(inv(v1), v2)\n  G query(int v1, int v2) {\n\
    \    query(v1), query(v2);\n    return op(inv(_pot[v1]), _pot[v2]);\n  }\n};\n\
    #line 1 \"modint/MontgomeryModInt.cpp\"\n//reference: https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10\n\
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
    \ is;\n  }\n};\n\nusing mint = MontgomeryModInt<998244353>;\n#line 6 \"test/unionfind_with_potential_non_commutative_group.test.cpp\"\
    \n\nusing matrix = array<array<mint, 2>, 2>;\nmatrix id() {\n  matrix m;\n  m[0][0]\
    \ = m[1][1] = 1;\n  return m;\n}\nmatrix op(const matrix &m1, const matrix &m2)\
    \ {\n  matrix m;\n  for(int i : {0, 1})\n    for(int k : {0, 1})\n      for(int\
    \ j : {0, 1})\n        m[i][j] += m1[i][k] * m2[k][j];\n  return m;\n}\nmatrix\
    \ inv(const matrix &m) {\n  matrix a = m;\n  swap(a[0][0], a[1][1]);\n  a[0][1]\
    \ = -a[0][1], a[1][0] = -a[1][0];\n  return a;\n}\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  DSU<matrix, id, op, inv> dsu(n);\n\
    \  while(q--) {\n    int t, u, v; cin >> t >> u >> v;\n    swap(u, v);\n    if\
    \ (t == 0) {\n      matrix m;\n      for(auto &v : m) for(mint &x : v) cin >>\
    \ x;\n      cout << dsu.merge(u, v, m) << '\\n';\n    } else {\n      if (dsu.query(u)\
    \ != dsu.query(v))\n        cout << -1 << '\\n';\n      else\n        cout <<\
    \ dsu.query(u, v) << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../ds/potentialDSU.cpp\"\n#include\
    \ \"../modint/MontgomeryModInt.cpp\"\n\nusing matrix = array<array<mint, 2>, 2>;\n\
    matrix id() {\n  matrix m;\n  m[0][0] = m[1][1] = 1;\n  return m;\n}\nmatrix op(const\
    \ matrix &m1, const matrix &m2) {\n  matrix m;\n  for(int i : {0, 1})\n    for(int\
    \ k : {0, 1})\n      for(int j : {0, 1})\n        m[i][j] += m1[i][k] * m2[k][j];\n\
    \  return m;\n}\nmatrix inv(const matrix &m) {\n  matrix a = m;\n  swap(a[0][0],\
    \ a[1][1]);\n  a[0][1] = -a[0][1], a[1][0] = -a[1][0];\n  return a;\n}\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin >>\
    \ n >> q;\n  DSU<matrix, id, op, inv> dsu(n);\n  while(q--) {\n    int t, u, v;\
    \ cin >> t >> u >> v;\n    swap(u, v);\n    if (t == 0) {\n      matrix m;\n \
    \     for(auto &v : m) for(mint &x : v) cin >> x;\n      cout << dsu.merge(u,\
    \ v, m) << '\\n';\n    } else {\n      if (dsu.query(u) != dsu.query(v))\n   \
    \     cout << -1 << '\\n';\n      else\n        cout << dsu.query(u, v) << '\\\
    n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - ds/potentialDSU.cpp
  - modint/MontgomeryModInt.cpp
  isVerificationFile: true
  path: test/unionfind_with_potential_non_commutative_group.test.cpp
  requiredBy: []
  timestamp: '2024-07-28 21:04:51+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unionfind_with_potential_non_commutative_group.test.cpp
layout: document
redirect_from:
- /verify/test/unionfind_with_potential_non_commutative_group.test.cpp
- /verify/test/unionfind_with_potential_non_commutative_group.test.cpp.html
title: test/unionfind_with_potential_non_commutative_group.test.cpp
---
