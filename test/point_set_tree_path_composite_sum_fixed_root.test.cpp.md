---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/staticTopTree.cpp
    title: ds/staticTopTree.cpp
  - icon: ':heavy_check_mark:'
    path: misc/dynamicTreeDP.cpp
    title: misc/dynamicTreeDP.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
    links:
    - https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
  bundledCode: "#line 1 \"test/point_set_tree_path_composite_sum_fixed_root.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root\"\
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
    \ a, mint b) { return a += b; }\n  friend mint operator-(mint a, mint b) { return\
    \ a -= b; }\n  friend mint operator*(mint a, mint b) { return a *= b; }\n  friend\
    \ mint operator/(mint a, mint b) { return a /= b; }\n\n  friend ostream& operator<<(ostream&\
    \ os, const mint& b) {\n    return os << b.get();\n  }\n  friend istream& operator>>(istream&\
    \ is, mint& b) {\n    int64_t val;\n    is >> val;\n    b = mint(val);\n    return\
    \ is;\n  }\n};\n\nusing mint = MontgomeryModInt<998244353>;\n#line 1 \"ds/staticTopTree.cpp\"\
    \nstruct staticTopTree {\n  enum type { Vertex, Rake, Compress, AddEdge, AddVertex};\n\
    \n  vector<vector<int>> g;\n  int stt_rt, n;\n  vector<int> lc, rc, p, ord;\n\
    \  vector<type> vt;\n  int nxt;\n\n  staticTopTree(vector<vector<int>> _g, int\
    \ root = 0) : n(size(_g)),\n  lc(4 * n, -1), rc(4 * n, -1), p(4 * n, -1), vt(4\
    \ * n, type::Vertex), nxt(2 * n) {\n    g.swap(_g);\n    dfs(root, -1);\n    stt_rt\
    \ = compress(root).first;\n    g.swap(_g);\n  }\n\n  int dfs(int v, int p) {\n\
    \    int sz = 1, pid = -1;\n    pii heavy(-1, -1);\n    for(int i = -1; int x\
    \ : g[v]) {\n      i++;\n      if (x == p) {\n        pid = i;\n        continue;\n\
    \      }\n      int tmp = dfs(x, v);\n      chmax(heavy, pii(tmp, i));\n     \
    \ sz += tmp;\n    }\n    if (heavy.second != -1) swap(g[v][heavy.second], g[v][0]);\n\
    \    if (pid != -1) g[v].erase(g[v].begin() + (pid == 0 and heavy.second != -1\
    \ ? heavy.second : pid));\n    return sz;\n  }\n\n  void newVertex(int l, int\
    \ r, type t) {\n    if (l != -1) p[l] = nxt, lc[nxt] = l;\n    if (r != -1) p[r]\
    \ = nxt, rc[nxt] = r;\n    ord.emplace_back(nxt);\n    vt[nxt++] = t;\n  }\n\n\
    \  void setVertex(int l, int r, int v, type t) {\n    if (l != -1) p[l] = v, lc[v]\
    \ = l;\n    if (r != -1) p[r] = v, rc[v] = r;\n    ord.emplace_back(v);\n    vt[v]\
    \ = t;\n  }\n\n  pii merge(vector<pii> &vs, type t, int v = -1) {\n    if (size(vs)\
    \ == 1) return vs[0];\n    int szSum = 0;\n    for(auto [_, sz] : vs) szSum +=\
    \ sz;\n    int i = 0, pre = 0;\n    while(i + 1 < ssize(vs) and 2 * pre <= szSum)\
    \ pre += vs[i++].second;\n    vector<pii> lv(vs.begin(), vs.begin() + i), rv(vs.begin()\
    \ + i, vs.end());\n    auto [l, lsz] = merge(lv, t);\n    auto [r, rsz] = merge(rv,\
    \ t);\n    if (v == -1) {\n      newVertex(l, r, t);\n      return {nxt - 1, lsz\
    \ + rsz + 1};\n    } else {\n      setVertex(l, r, v, t);\n      return {v, lsz\
    \ + rsz + 1};\n    }\n  }\n\n  pii compress(int v) {\n    vector<pii> vs(1, addEdge(v));\n\
    \    while(!g[v].empty()) \n      vs.emplace_back(addEdge(v = g[v][0]));\n   \
    \ return merge(vs, type::Compress);\n  }\n\n  pii addEdge(int v) {\n    auto [l,\
    \ lsz] = addVertex(v);\n    setVertex(l, -1, v + n, type::AddEdge);\n    return\
    \ {v + n, lsz + 1};\n  }\n\n  pii addVertex(int v) {\n    if (ssize(g[v]) <= 1)\
    \ {\n      setVertex(-1, -1, v, type::Vertex);\n      return {v, 1};\n    } else\
    \ {\n      auto [l, lsz] = rake(v);\n      setVertex(l, -1, v, type::AddVertex);\n\
    \      return {v, lsz + 1};\n    }\n  }\n\n  pii rake(int v) {\n    vector<pii>\
    \ vs;\n    for(int x : g[v] | views::drop(1))\n      vs.emplace_back(compress(x));\n\
    \    return merge(vs, type::Rake);\n  }\n};\n#line 1 \"misc/dynamicTreeDP.cpp\"\
    \n//#include \"ds/staticTopTree.cpp\"\n\ntemplate<class V, V(*base)(int), class\
    \ E, E(*addEdge)(const V&, int eid),\nE(*op)(const E&, const E&), V(*addVertex)(const\
    \ E&, int vid), E(*compress)(const E&, const E&)>\nstruct dynamicTreeDP {\n  int\
    \ n;\n  staticTopTree stt;\n  vector<V> dpV;\n  vector<E> dpE;\n\n  dynamicTreeDP(vector<vector<int>>\
    \ &g)\n  : n(size(g)),stt(g), dpV(n), dpE(3 * n) {\n    for(int v : stt.ord)\n\
    \      update(v);\n  }\n\n  void update(int v) {\n    if (auto type = stt.vt[v];\
    \ type == 0)\n      dpV[v] = base(v);\n    else if (type == 1)\n      dpE[v -\
    \ n] = op(dpE[stt.lc[v] - n], dpE[stt.rc[v] - n]);\n    else if (type == 2)\n\
    \      dpE[v - n] = compress(dpE[stt.rc[v] - n], dpE[stt.lc[v] - n]);\n    else\
    \ if (type == 3)\n      dpE[v - n] = addEdge(dpV[stt.lc[v]], v - n);\n    else\
    \ if (type == 4)\n      dpV[v] = addVertex(dpE[stt.lc[v] - n], v);\n  }\n\n  void\
    \ pull(int v) {\n    while(v != -1) {\n      update(v);\n      v = stt.p[v];\n\
    \    }\n  }\n\n  void updateVertex(int v) { pull(v); }\n  void updateEdge(int\
    \ e) { pull(e + n); }\n  E get() { return dpE[stt.stt_rt - n]; }\n};\n#line 7\
    \ \"test/point_set_tree_path_composite_sum_fixed_root.test.cpp\"\n\nusing V =\
    \ array<mint, 2>;\nusing E = array<mint, 4>;\n\nvector<mint> a, b, c;\n\nV base(int\
    \ i) { return {a[i], 1}; }\nE addEdge(const V &v, int i) { return {b[i] * v[0]\
    \ + c[i] * v[1], v[1], b[i], c[i]}; }\nE op(const E &l, const E &r) { return {l[0]\
    \ + r[0], l[1] + r[1], 0, 0}; }\nV addVertex(const E &e, int i) { return {e[0]\
    \ + a[i], e[1] + 1}; }\nE compress(const E &l, const E &r) {\n  auto [c, d, i,\
    \ j] = l;\n  auto [e, f, g, h] = r;\n  return {c * g + d * h + e, d + f, i * g,\
    \ (j * g + h)};\n}\n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\
    \n  int n, q; cin >> n >> q;\n  a.resize(n);\n  for(mint &x : a) cin >> x;\n \
    \ vector<array<int, 4>> e(n - 1);\n  for(auto &[u, v, b, c] : e)\n    cin >> u\
    \ >> v >> b >> c;\n\n  vector<vector<int>> g(n);\n  for(auto [u, v, _, __] : e)\
    \ {\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n  }\n\n  vector<int>\
    \ dep(n);\n  auto dfs = [&](int v, int p, auto &&self) -> void {\n    for(int\
    \ x : g[v]) if (x != p) {\n      dep[x] = dep[v] + 1;\n      self(x, v, self);\n\
    \    }\n  };\n  dfs(0, -1, dfs);\n\n  b.resize(n, 1), c.resize(n);\n  for(auto\
    \ &[u, v, bb, cc] : e) {\n    if (dep[u] > dep[v]) swap(u, v);\n    b[v] = bb,\
    \ c[v] = cc;\n  }\n\n  dynamicTreeDP<V, base, E, addEdge, op, addVertex, compress>\
    \ ddp(g);\n\n  while(q--) {\n    int op; cin >> op;\n    if (op == 0) {\n    \
    \  int w, x; cin >> w >> x;\n      a[w] = x;\n      ddp.updateVertex(w);\n   \
    \ } else if (op == 1) {\n      int i, y, z; cin >> i >> y >> z;\n      int id\
    \ = e[i][1];\n      b[id] = y, c[id] = z;\n      ddp.updateEdge(id);\n    }\n\
    \    cout << ddp.get()[0] << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../ds/staticTopTree.cpp\"\n#include \"../misc/dynamicTreeDP.cpp\"\
    \n\nusing V = array<mint, 2>;\nusing E = array<mint, 4>;\n\nvector<mint> a, b,\
    \ c;\n\nV base(int i) { return {a[i], 1}; }\nE addEdge(const V &v, int i) { return\
    \ {b[i] * v[0] + c[i] * v[1], v[1], b[i], c[i]}; }\nE op(const E &l, const E &r)\
    \ { return {l[0] + r[0], l[1] + r[1], 0, 0}; }\nV addVertex(const E &e, int i)\
    \ { return {e[0] + a[i], e[1] + 1}; }\nE compress(const E &l, const E &r) {\n\
    \  auto [c, d, i, j] = l;\n  auto [e, f, g, h] = r;\n  return {c * g + d * h +\
    \ e, d + f, i * g, (j * g + h)};\n}\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  a.resize(n);\n  for(mint &x\
    \ : a) cin >> x;\n  vector<array<int, 4>> e(n - 1);\n  for(auto &[u, v, b, c]\
    \ : e)\n    cin >> u >> v >> b >> c;\n\n  vector<vector<int>> g(n);\n  for(auto\
    \ [u, v, _, __] : e) {\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n\
    \  }\n\n  vector<int> dep(n);\n  auto dfs = [&](int v, int p, auto &&self) ->\
    \ void {\n    for(int x : g[v]) if (x != p) {\n      dep[x] = dep[v] + 1;\n  \
    \    self(x, v, self);\n    }\n  };\n  dfs(0, -1, dfs);\n\n  b.resize(n, 1), c.resize(n);\n\
    \  for(auto &[u, v, bb, cc] : e) {\n    if (dep[u] > dep[v]) swap(u, v);\n   \
    \ b[v] = bb, c[v] = cc;\n  }\n\n  dynamicTreeDP<V, base, E, addEdge, op, addVertex,\
    \ compress> ddp(g);\n\n  while(q--) {\n    int op; cin >> op;\n    if (op == 0)\
    \ {\n      int w, x; cin >> w >> x;\n      a[w] = x;\n      ddp.updateVertex(w);\n\
    \    } else if (op == 1) {\n      int i, y, z; cin >> i >> y >> z;\n      int\
    \ id = e[i][1];\n      b[id] = y, c[id] = z;\n      ddp.updateEdge(id);\n    }\n\
    \    cout << ddp.get()[0] << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/MontgomeryModInt.cpp
  - ds/staticTopTree.cpp
  - misc/dynamicTreeDP.cpp
  isVerificationFile: true
  path: test/point_set_tree_path_composite_sum_fixed_root.test.cpp
  requiredBy: []
  timestamp: '2024-07-28 22:15:46+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/point_set_tree_path_composite_sum_fixed_root.test.cpp
layout: document
redirect_from:
- /verify/test/point_set_tree_path_composite_sum_fixed_root.test.cpp
- /verify/test/point_set_tree_path_composite_sum_fixed_root.test.cpp.html
title: test/point_set_tree_path_composite_sum_fixed_root.test.cpp
---
