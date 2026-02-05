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
    path: segtree/segmentTree.cpp
    title: segtree/segmentTree.cpp
  - icon: ':heavy_check_mark:'
    path: tree/HLD.cpp
    title: tree/HLD.cpp
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
    default/t.cpp\"\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include\
    \ <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include\
    \ <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include <deque>\n#include\
    \ <fstream>\n#include <functional>\n#include <initializer_list>\n#include <iomanip>\n\
    #include <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n\
    #include <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include\
    \ <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <sstream>\n#include <stack>\n#include <streambuf>\n#include\
    \ <string>\n#include <tuple>\n#include <type_traits>\n#include <variant>\n#include\
    \ <bit>\n#include <compare>\n#include <concepts>\n#include <numbers>\n#include\
    \ <ranges>\n#include <span>\n\n#define INT128_MAX (__int128)(((unsigned __int128)\
    \ 1 << ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN (-INT128_MAX\
    \ - 1)\n\n#define pb push_back\n#define eb emplace_back\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
    \nusing namespace std;\n\ntemplate<size_t I = 0, typename... args>\nostream& print_tuple(ostream&\
    \ os, const tuple<args...> tu) {\n  os << get<I>(tu);\n  if constexpr (I + 1 !=\
    \ sizeof...(args)) {\n    os << ' ';\n    print_tuple<I + 1>(os, tu);\n  }\n \
    \ return os;\n}\ntemplate<typename... args>\nostream& operator<<(ostream& os,\
    \ const tuple<args...> tu) {\n  return print_tuple(os, tu);\n}\ntemplate<class\
    \ T1, class T2>\nostream& operator<<(ostream& os, const pair<T1, T2> pr) {\n \
    \ return os << pr.first << ' ' << pr.second;\n}\ntemplate<class T, size_t N>\n\
    ostream& operator<<(ostream& os, const array<T, N> &arr) {\n  for(size_t i = 0;\
    \ T x : arr) {\n    os << x;\n    if (++i != N) os << ' ';\n  }\n  return os;\n\
    }\ntemplate<class T>\nostream& operator<<(ostream& os, const vector<T> &vec) {\n\
    \  for(size_t i = 0; T x : vec) {\n    os << x;\n    if (++i != size(vec)) os\
    \ << ' ';\n  }\n  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream&\
    \ os, const set<T> &s) {\n  for(size_t i = 0; T x : s) {\n    os << x;\n    if\
    \ (++i != size(s)) os << ' ';\n  }\n  return os;\n}\ntemplate<class T>\nostream&\
    \ operator<<(ostream& os, const multiset<T> &s) {\n  for(size_t i = 0; T x : s)\
    \ {\n    os << x;\n    if (++i != size(s)) os << ' ';\n  }\n  return os;\n}\n\
    template<class T1, class T2>\nostream& operator<<(ostream& os, const map<T1, T2>\
    \ &m) {\n  for(size_t i = 0; pair<T1, T2> x : m) {\n    os << x.first << \" :\
    \ \" << x.second;\n    if (++i != size(m)) os << \", \";\n  }\n  return os;\n\
    }\n\n#ifdef DEBUG\n#define dbg(...) cerr << '(', _do(#__VA_ARGS__), cerr << \"\
    ) = \", _do2(__VA_ARGS__)\ntemplate<typename T> void _do(T &&x) { cerr << x; }\n\
    template<typename T, typename ...S> void _do(T &&x, S&&...y) { cerr << x << \"\
    , \"; _do(y...); }\ntemplate<typename T> void _do2(T &&x) { cerr << x << endl;\
    \ }\ntemplate<typename T, typename ...S> void _do2(T &&x, S&&...y) { cerr << x\
    \ << \", \"; _do2(y...); }\n#else\n#define dbg(...)\n#endif\n\nusing ll = long\
    \ long;\nusing ull = unsigned long long;\nusing ldb = long double;\nusing pii\
    \ = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate<typename T> using vc\
    \ = vector<T>;\ntemplate<typename T> using vvc = vc<vc<T>>;\ntemplate<typename\
    \ T> using vvvc = vc<vvc<T>>;\n\nusing vi = vc<int>;\nusing vll = vc<ll>;\nusing\
    \ vvi = vvc<int>;\nusing vvll = vvc<ll>;\n\ntemplate<typename T> using min_heap\
    \ = priority_queue<T, vc<T>, greater<T>>;\ntemplate<typename T> using max_heap\
    \ = priority_queue<T>;\n\ntemplate<typename R, typename F, typename... Args>\n\
    concept R_invocable = requires(F&& f, Args&&... args) {\n  { std::invoke(std::forward<F>(f),\
    \ std::forward<Args>(args)...) } -> std::same_as<R>;\n};\ntemplate<ranges::forward_range\
    \ rng, class T = ranges::range_value_t<rng>, typename F>\nrequires R_invocable<T,\
    \ F, T, T>\nvoid pSum(rng &&v, F f) {\n  if (!v.empty())\n    for(T p = *v.begin();\
    \ T &x : v | views::drop(1))\n      x = p = f(p, x);\n}\ntemplate<ranges::forward_range\
    \ rng, class T = ranges::range_value_t<rng>>\nvoid pSum(rng &&v) {\n  if (!v.empty())\n\
    \    for(T p = *v.begin(); T &x : v | views::drop(1))\n      x = p = p + x;\n\
    }\n\ntemplate<ranges::forward_range rng>\nvoid Unique(rng &v) {\n  ranges::sort(v);\n\
    \  v.resize(unique(v.begin(), v.end()) - v.begin());\n}\n\ntemplate<ranges::random_access_range\
    \ rng>\nrng invPerm(rng p) {\n  rng ret = p;\n  for(int i = 0; i < ssize(p); i++)\n\
    \    ret[p[i]] = i;\n  return ret;\n}\n\ntemplate<ranges::random_access_range\
    \ rng>\nvi argSort(rng p) {\n  vi id(size(p));\n  iota(id.begin(), id.end(), 0);\n\
    \  ranges::sort(id, {}, [&](int i) { return pair(p[i], i); });\n  return id;\n\
    }\n\ntemplate<ranges::random_access_range rng, class T = ranges::range_value_t<rng>,\
    \ typename F>\nrequires invocable<F, T&>\nvi argSort(rng p, F proj) {\n  vi id(size(p));\n\
    \  iota(id.begin(), id.end(), 0);\n  ranges::sort(id, {}, [&](int i) { return\
    \ pair(proj(p[i]), i); });\n  return id;\n}\n\ntemplate<bool directed>\nvvi read_graph(int\
    \ n, int m, int base) {\n  vvi g(n);\n  for(int i = 0; i < m; i++) {\n    int\
    \ u, v; cin >> u >> v;\n    u -= base, v -= base;\n    g[u].emplace_back(v);\n\
    \    if constexpr (!directed)\n      g[v].emplace_back(u);\n  }\n  return g;\n\
    }\n\ntemplate<bool directed>\nvvi adjacency_list(int n, vc<pii> e, int base) {\n\
    \  vvi g(n);\n  for(auto [u, v] : e) {\n    u -= base, v -= base;\n    g[u].emplace_back(v);\n\
    \    if constexpr (!directed)\n      g[v].emplace_back(u);\n  }\n  return g;\n\
    }\n\ntemplate<class T>\nvoid setBit(T &msk, int bit, bool x) { (msk &= ~(T(1)\
    \ << bit)) |= T(x) << bit; }\ntemplate<class T> void onBit(T &msk, int bit) {\
    \ setBit(msk, bit, true); }\ntemplate<class T> void offBit(T &msk, int bit) {\
    \ setBit(msk, bit, false); }\ntemplate<class T> void flipBit(T &msk, int bit)\
    \ { msk ^= T(1) << bit; }\ntemplate<class T> bool getBit(T msk, int bit) { return\
    \ msk >> bit & T(1); }\n\ntemplate<class T>\nT floorDiv(T a, T b) {\n  if (b <\
    \ 0) a *= -1, b *= -1;\n  return a >= 0 ? a / b : (a - b + 1) / b;\n}\ntemplate<class\
    \ T>\nT ceilDiv(T a, T b) {\n  if (b < 0) a *= -1, b *= -1;\n  return a >= 0 ?\
    \ (a + b - 1) / b : a / b;\n}\n\ntemplate<class T> bool chmin(T &a, T b) { return\
    \ a > b ? a = b, 1 : 0; }\ntemplate<class T> bool chmax(T &a, T b) { return a\
    \ < b ? a = b, 1 : 0; }\n\n#line 1 \"modint/MontgomeryModInt.cpp\"\n//reference:\
    \ https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10\n\
    //note: mod should be an odd prime less than 2^30.\n\ntemplate<uint32_t mod>\n\
    struct MontgomeryModInt {\n  using mint = MontgomeryModInt;\n  using i32 = int32_t;\n\
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
    \ op(L, R);\n  }\n\n  //return first j in [i, size) s.t. f(op([l, j])) is true,\n\
    \  //assume f(id()) is false.\n  int firstTrue(int i, function<bool(const M&)>\
    \ f) {\n    vector<int> idL, idR;\n    for(int l = i + size, r = size << 1; l\
    \ < r; l >>= 1, r >>= 1) {\n      if (l & 1) idL.emplace_back(l++);\n      if\
    \ (r & 1) idR.emplace_back(--r);\n    }\n    idL.insert(idL.end(), idR.rbegin(),\
    \ idR.rend());\n    M pre = id();\n    int v = -1;\n    for(int j : idL) {\n \
    \     if (f(op(pre, data[j]))) {\n        v = j;\n        break;\n      } else\
    \ {\n        pre = op(pre, data[j]);\n      }\n    }\n    if (v == -1) return\
    \ size;\n    while(v < size) {\n      if (f(op(pre, data[v << 1])))\n        v\
    \ = v << 1;\n      else\n        pre = op(pre, data[v << 1]), v = v << 1 | 1;\n\
    \    }\n    return v - size;\n  }\n\n  int lastTrue(int i, function<bool(const\
    \ M&)> f) {\n    vector<int> idL, idR;\n    for(int l = size, r = (i + 1) + size;\
    \ l < r; l >>= 1, r >>= 1) {\n      if (l & 1) idL.emplace_back(l++);\n      if\
    \ (r & 1) idR.emplace_back(--r);\n    }\n    idR.insert(idR.end(), idL.rbegin(),\
    \ idL.rend());\n    M suf = id();\n    int v = -1;\n    for(int j : idR) {\n \
    \     if (f(op(data[j], suf))) {\n        v = j;\n        break;\n      } else\
    \ {\n        suf = op(data[j], suf);\n      }\n    }\n    if (v == -1) return\
    \ -1;\n    while(v < size) {\n      if (f(op(data[v << 1 | 1], suf)))\n      \
    \  v = v << 1 | 1;\n      else\n        suf = op(data[v << 1 | 1], suf), v = v\
    \ << 1;\n    }\n    return v - size;\n  }\n};\n#line 1 \"actedmonoid/actedMonoid_affineSum.cpp\"\
    \ntemplate<class U>\nstruct actedMonoid_affineSum {\n  using M = array<U, 2>;\n\
    \  static M Mid() { return M{0, 0}; }\n  static M Mop(const M &a, const M &b)\
    \ { return {a[0] + b[0], a[1] + b[1]}; }\n  using T = array<U, 2>;\n  static T\
    \ Tid() { return T{1, 0}; }\n  static T Top(const T &a, const T &b) { return T{a[0]\
    \ * b[0], a[1] * b[0] + b[1]}; }\n  static M act(const M &a, const T &b) { return\
    \ {a[0] * b[0] + a[1] * b[1], a[1]}; }\n};\n#line 1 \"tree/HLD.cpp\"\nstruct HLD\
    \ {\n  static const int MSK = (1 << 30);\n  vi dep, p_head, tin, tout, inv_tin;\n\
    \n  inline int head(int v) const { return (p_head[v] & MSK) ? v : p_head[v]; }\n\
    \  inline int head_parent(int v) const { return p_head[head(v)] & (MSK - 1); }\n\
    \n  HLD(vc<pii> e, int root = 0) {\n    const int n = ssize(e) + 1;\n\n    dep\
    \ = p_head = tin = tout = vi(n);\n\n    vi sz(n, 1), mx_child_sz(n, -1);\n   \
    \ {\n      vi d(n);\n      for(auto [u, v] : e)\n        p_head[u] ^= v, p_head[v]\
    \ ^= u, d[u]++, d[v]++;\n      d[root] = 0;\n      for(int i = 0; i < n; i++)\
    \ {\n        int v = i;\n        while(d[v] == 1) {\n          d[v] = 0, d[p_head[v]]--,\
    \ p_head[p_head[v]] ^= v;\n          sz[p_head[v]] += sz[v];\n          chmax(mx_child_sz[p_head[v]],\
    \ sz[v]);\n          v = p_head[v];\n        }\n      }\n    }\n\n    vi ord(n);\n\
    \    {\n      vi f(n + 2);\n      for(int x : sz) f[x + 1]++;\n      pSum(f);\n\
    \      for(int v = 0; v < n; v++)\n        ord[n - 1 - (f[sz[v]]++)] = v;\n  \
    \  }\n\n    {\n      p_head[root] = (root | MSK), tout[root] = n;\n\n      vi\
    \ add(n, 1);\n      for(int v : ord | views::drop(1)) {\n        dep[v] = dep[p_head[v]]\
    \ + 1;\n        tin[v] = tin[p_head[v]] + add[p_head[v]];\n        add[p_head[v]]\
    \ += sz[v];\n        tout[v] = tin[v] + sz[v];\n        if (mx_child_sz[p_head[v]]\
    \ == sz[v])\n          mx_child_sz[p_head[v]] = 0, p_head[v] = head(p_head[v]);\n\
    \        else\n          p_head[v] |= MSK;\n      }\n    }\n\n    inv_tin = invPerm(tin);\n\
    \  }\n\n  auto query_path(int u, int v, bool edge = false) {\n    vc<pii> lr;\n\
    \    while(head(u) != head(v)) {\n      if (dep[head(u)] > dep[head(v)])\n   \
    \     swap(u, v);\n      lr.emplace_back(tin[head(v)], tin[v] + 1);\n      v =\
    \ head_parent(v);\n    }\n\n    if (tin[u] > tin[v]) swap(u, v);\n    if (tin[u]\
    \ + edge <= tin[v])\n      lr.emplace_back(tin[u] + edge, tin[v] + 1);\n\n   \
    \ return lr;\n  }\n\n  //l < r: op(l, op(l + 1, ...))\n  //l > r: op(r - 1, op(r\
    \ - 2, ...))\n  auto query_path_non_commutative(int u, int v, bool edge = false)\
    \ {\n    vc<pii> lr1, lr2;\n    while(head(u) != head(v)) {\n      if (dep[head(u)]\
    \ > dep[head(v)]) {\n        lr1.emplace_back(tin[u] + 1, tin[head(u)]);\n   \
    \     u = head_parent(u);\n      } else {\n        lr2.emplace_back(tin[head(v)],\
    \ tin[v] + 1);\n        v = head_parent(v);\n      }\n    }\n\n    if (tin[u]\
    \ + edge <= tin[v])\n      lr2.emplace_back(tin[u] + edge, tin[v] + 1);\n    else\
    \ if (tin[v] + edge <= tin[u])\n      lr1.emplace_back(tin[u] + 1, tin[v] + edge);\n\
    \n    lr1.insert(end(lr1), lr2.rbegin(), lr2.rend());\n\n    return lr1;\n  }\n\
    \n  auto query_subtree(int v) { return pii(tin[v], tout[v]); }\n\n  int query_point(int\
    \ v) { return tin[v]; }\n\n  int lca(int u, int v) {\n    while(head(u) != head(v))\
    \ {\n      if (dep[head(u)] > dep[head(v)])\n        swap(u, v);\n      v = head_parent(v);\n\
    \    }\n    return tin[u] < tin[v] ? u : v;\n  }\n\n  int kth(int s, int t, int\
    \ k) {\n    int l = lca(s, t);\n    if (int d = dep[s] + dep[t] - 2 * dep[l];\
    \ k > d)\n      return -1;\n    else if (k > dep[s] - dep[l])\n      k = d - k,\
    \ swap(s, t);\n    while(k > dep[s] - dep[head(s)]) {\n      k -= dep[s] - dep[head(s)]\
    \ + 1;\n      s = head_parent(s);\n    }\n    return inv_tin[tin[s] - k];\n  }\n\
    \n  template<class M>\n  vc<M> reorder_init(vc<M> init) {\n    assert(ssize(init)\
    \ == ssize(dep));\n    auto r = init;\n    for(int i = 0; i < ssize(init); i++)\n\
    \      r[tin[i]] = init[i];\n    return r;\n  }\n};\n#line 8 \"test/vertex_set_path_composite.test.cpp\"\
    \n\nusing am = actedMonoid_affineSum<mint>;\n\nam::T R_Top(const am::T &a, const\
    \ am::T &b) { return am::T{a[0] * b[0], b[1] * a[0] + a[1]}; }\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin >> n >>\
    \ q;\n  vc<array<mint, 2>> init(n);\n  for(auto &[a, b] : init)\n    cin >> a\
    \ >> b;\n  vc<pii> e(n - 1);\n  for(auto &[u, v] : e)\n    cin >> u >> v;\n\n\
    \  HLD hld(std::move(e));\n  init = hld.reorder_init(std::move(init));\n  segmentTree<am::T,\
    \ am::Tid, R_Top> st_rev(init);\n  segmentTree<am::T, am::Tid, am::Top> st(init);\n\
    \  while(q--) {\n    int op; cin >> op;\n    if (op == 0) {\n      int p, c, d;\
    \ cin >> p >> c >> d;\n      st.set(hld.query_point(p), am::M{c, d});\n      st_rev.set(hld.query_point(p),\
    \ am::M{c, d});\n    } else {\n      int u, v, x; cin >> u >> v >> x;\n      am::T\
    \ prod = am::T{1, 0};\n      for(auto [l, r] : hld.query_path_non_commutative(u,\
    \ v)) {\n        if (l < r) prod = am::Top(prod, st.query(l, r));\n        else\
    \ prod = am::Top(prod, st_rev.query(r, l));\n      }\n      cout << prod[0] *\
    \ x + prod[1] << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../segtree/segmentTree.cpp\"\n#include \"../actedmonoid/actedMonoid_affineSum.cpp\"\
    \n#include \"../tree/HLD.cpp\"\n\nusing am = actedMonoid_affineSum<mint>;\n\n\
    am::T R_Top(const am::T &a, const am::T &b) { return am::T{a[0] * b[0], b[1] *\
    \ a[0] + a[1]}; }\n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\
    \n  int n, q; cin >> n >> q;\n  vc<array<mint, 2>> init(n);\n  for(auto &[a, b]\
    \ : init)\n    cin >> a >> b;\n  vc<pii> e(n - 1);\n  for(auto &[u, v] : e)\n\
    \    cin >> u >> v;\n\n  HLD hld(std::move(e));\n  init = hld.reorder_init(std::move(init));\n\
    \  segmentTree<am::T, am::Tid, R_Top> st_rev(init);\n  segmentTree<am::T, am::Tid,\
    \ am::Top> st(init);\n  while(q--) {\n    int op; cin >> op;\n    if (op == 0)\
    \ {\n      int p, c, d; cin >> p >> c >> d;\n      st.set(hld.query_point(p),\
    \ am::M{c, d});\n      st_rev.set(hld.query_point(p), am::M{c, d});\n    } else\
    \ {\n      int u, v, x; cin >> u >> v >> x;\n      am::T prod = am::T{1, 0};\n\
    \      for(auto [l, r] : hld.query_path_non_commutative(u, v)) {\n        if (l\
    \ < r) prod = am::Top(prod, st.query(l, r));\n        else prod = am::Top(prod,\
    \ st_rev.query(r, l));\n      }\n      cout << prod[0] * x + prod[1] << '\\n';\n\
    \    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/MontgomeryModInt.cpp
  - segtree/segmentTree.cpp
  - actedmonoid/actedMonoid_affineSum.cpp
  - tree/HLD.cpp
  isVerificationFile: true
  path: test/vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2026-02-03 04:18:40+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_set_path_composite.test.cpp
- /verify/test/vertex_set_path_composite.test.cpp.html
title: test/vertex_set_path_composite.test.cpp
---
