---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: actedmonoid/actedMonoid_affineSum.cpp
    title: actedmonoid/actedMonoid_affineSum.cpp
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/heavyLightDecomposition.cpp
    title: ds/heavyLightDecomposition.cpp
  - icon: ':heavy_check_mark:'
    path: modint/MontgomeryModInt.cpp
    title: modint/MontgomeryModInt.cpp
  - icon: ':heavy_check_mark:'
    path: segtree/segmentTree.cpp
    title: segtree/segmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"test/vertex_set_path_composite.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\n\n#line 1 \"\
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
    \ is;\n  }\n};\n\nusing mint = MontgomeryModInt<998244353>;\n#line 1 \"segtree/segmentTree.cpp\"\
    \ntemplate<class M, M(*id)(), M(*op)(const M&, const M&)>\nstruct segmentTree\
    \ {\n  int size;\n  vector<M> data;\n\n  segmentTree(int _size) : size(_size),\
    \ data(2 * size, id()) {}\n  segmentTree(vector<M> init) : size(ssize(init)),\
    \ data(2 * size, id()) {\n    ranges::copy(init, data.begin() + size);\n    for(int\
    \ i = size - 1; i > 0; i--)\n      data[i] = op(data[i << 1], data[i << 1 | 1]);\n\
    \  }\n\n  void set(int i, M x) {\n    data[i += size] = x;\n    while(i >>= 1)\n\
    \      data[i] = op(data[i << 1], data[i << 1 | 1]);\n  }\n\n  M get(int i) {\
    \ return data[i + size]; }\n\n  M query(int l, int r) {\n    M L = id(), R = id();\n\
    \    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) L\
    \ = op(L, data[l++]);\n      if (r & 1) R = op(data[--r], R);\n    }\n    return\
    \ op(L, R);\n  }\n};\n#line 1 \"actedmonoid/actedMonoid_affineSum.cpp\"\ntemplate<class\
    \ U>\nstruct actedMonoid_affineSum {\n  using M = array<U, 2>;\n  static M Mid()\
    \ { return M{0, 0}; }\n  static M Mop(const M &a, const M &b) { return {a[0] +\
    \ b[0], a[1] + b[1]}; }\n  using T = array<U, 2>;\n  static T Tid() { return T{1,\
    \ 0}; }\n  static T Top(const T &a, const T &b) { return T{a[0] * b[0], a[1] *\
    \ b[0] + b[1]}; }\n  static M act(const M &a, const T &b) { return {a[0] * b[0]\
    \ + a[1] * b[1], a[1]}; }\n};\n#line 1 \"ds/heavyLightDecomposition.cpp\"\nstruct\
    \ HLD {\n  int n;\n  vector<int> dep, p, head, id;\n\n  HLD(vector<vector<int>>\
    \ &g, vector<int> root = vector<int>(1, 0))\n  : n(ssize(g)), dep(n), p(n, -1),\
    \ head(n), id(n) {\n    vector<int> sz(n, 1);\n\n    auto dfs = [&](int v, auto\
    \ self) -> void {\n      int mx = -1;\n      for(int i = -1; int x : g[v]) {\n\
    \        i++;\n        if (x == p[v]) continue;\n        p[x] = v, dep[x] = dep[v]\
    \ + 1;\n        self(x, self);\n        sz[v] += sz[x];\n        if (mx == -1\
    \ or sz[x] > sz[g[v][mx]]) mx = i;\n      }\n      if (mx != -1) swap(g[v][0],\
    \ g[v][mx]);\n    };\n\n    int nxt = 0;\n    auto cut = [&](int v, int h, auto\
    \ self) -> void {\n      id[v] = nxt++, head[v] = h;\n      if (!g[v].empty()\
    \ and g[v][0] != p[v])\n        self(g[v][0], h, self);\n      for(int x : g[v]\
    \ | V::drop(1)) if (x != p[v])\n          self(x, x, self);\n    };\n\n    for(int\
    \ x : root) {\n      dfs(x, dfs);\n      cut(x, x, cut);\n    }\n  }\n\n  //(l,\
    \ r, rev)\n  vector<tuple<int, int, bool>> query(int u, int v, bool edge = false)\
    \ {\n    vector<array<int, 2>> resL, resR;\n    while(head[u] != head[v]) {\n\
    \      if (dep[head[u]] >= dep[head[v]]) {\n        resL.push_back({id[head[u]],\
    \ id[u] + 1});\n        u = p[head[u]];\n      } else {\n        resR.push_back({id[head[v]],\
    \ id[v] + 1});\n        v = p[head[v]];\n      }\n    }\n    if (id[v] + edge\
    \ <= id[u])\n      resL.push_back({id[v] + edge, id[u] + 1});\n    else if (id[u]\
    \ + edge <= id[v])\n      resR.push_back({id[u] + edge, id[v] + 1});\n    vector<tuple<int,\
    \ int, bool>> res;\n    for(auto [l, r] : resL)\n      res.push_back({l, r, true});\n\
    \    for(auto [l, r] : resR | V::reverse)\n      res.push_back({l, r, false});\n\
    \    return res;\n  }\n};\n#line 8 \"test/vertex_set_path_composite.test.cpp\"\
    \n\nusing am = actedMonoid_affineSum<mint>;\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<am::T> ab(n);\n  for(auto\
    \ &[a, b] : ab)\n    cin >> a >> b;\n  vector<vector<int>> g(n);\n  for(int i\
    \ = 1; i < n; i++) {\n    int u, v; cin >> u >> v;\n    g[u].emplace_back(v);\n\
    \    g[v].emplace_back(u);\n  }\n\n  HLD hld(g);\n  vector<am::T> init(n);\n \
    \ for(int i = 0; i < n; i++)\n    init[hld.id[i]] = ab[i];\n  segmentTree<am::T,\
    \ am::Tid, am::Top> st(init);\n  R::reverse(init);\n  segmentTree<am::T, am::Tid,\
    \ am::Top> str(init);\n\n  while(q--) {\n    int t, a, b, c; cin >> t >> a >>\
    \ b >> c;\n    if (t == 0) {\n      st.set(hld.id[a], am::T{b, c});\n      str.set((n\
    \ - 1) - hld.id[a], am::T{b, c});\n    } else {\n      auto res = am::T{0, c};\n\
    \      for(auto [l, r, rev] : hld.query(a, b)) {\n        if (rev)\n         \
    \ res = am::Top(res, str.query(n - r, n - l));\n        else\n          res =\
    \ am::Top(res, st.query(l, r));\n      }\n      cout << res[1] << '\\n';\n   \
    \ }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../segtree/segmentTree.cpp\"\n#include \"../actedmonoid/actedMonoid_affineSum.cpp\"\
    \n#include \"../ds/heavyLightDecomposition.cpp\"\n\nusing am = actedMonoid_affineSum<mint>;\n\
    \nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q;\
    \ cin >> n >> q;\n  vector<am::T> ab(n);\n  for(auto &[a, b] : ab)\n    cin >>\
    \ a >> b;\n  vector<vector<int>> g(n);\n  for(int i = 1; i < n; i++) {\n    int\
    \ u, v; cin >> u >> v;\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n\
    \  }\n\n  HLD hld(g);\n  vector<am::T> init(n);\n  for(int i = 0; i < n; i++)\n\
    \    init[hld.id[i]] = ab[i];\n  segmentTree<am::T, am::Tid, am::Top> st(init);\n\
    \  R::reverse(init);\n  segmentTree<am::T, am::Tid, am::Top> str(init);\n\n  while(q--)\
    \ {\n    int t, a, b, c; cin >> t >> a >> b >> c;\n    if (t == 0) {\n      st.set(hld.id[a],\
    \ am::T{b, c});\n      str.set((n - 1) - hld.id[a], am::T{b, c});\n    } else\
    \ {\n      auto res = am::T{0, c};\n      for(auto [l, r, rev] : hld.query(a,\
    \ b)) {\n        if (rev)\n          res = am::Top(res, str.query(n - r, n - l));\n\
    \        else\n          res = am::Top(res, st.query(l, r));\n      }\n      cout\
    \ << res[1] << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/MontgomeryModInt.cpp
  - segtree/segmentTree.cpp
  - actedmonoid/actedMonoid_affineSum.cpp
  - ds/heavyLightDecomposition.cpp
  isVerificationFile: true
  path: test/vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2024-03-07 01:57:47+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_set_path_composite.test.cpp
- /verify/test/vertex_set_path_composite.test.cpp.html
title: test/vertex_set_path_composite.test.cpp
---