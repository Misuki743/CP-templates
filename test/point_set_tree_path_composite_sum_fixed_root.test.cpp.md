---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':x:'
    path: dp/dynamicTreeDP.cpp
    title: dp/dynamicTreeDP.cpp
  - icon: ':x:'
    path: ds/staticTopTree.cpp
    title: ds/staticTopTree.cpp
  - icon: ':question:'
    path: modint/MontgomeryModInt.cpp
    title: modint/MontgomeryModInt.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    \ (-INT128_MAX - 1)\n\n#define pb push_back\n#define eb emplace_back\n#define\
    \ clock chrono::steady_clock::now().time_since_epoch().count()\n\nusing namespace\
    \ std;\n\ntemplate<size_t I = 0, typename... args>\nostream& print_tuple(ostream&\
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
    }\n\ntemplate<bool directed>\nvvi read_graph(int n, int m, int base) {\n  vvi\
    \ g(n);\n  for(int i = 0; i < m; i++) {\n    int u, v; cin >> u >> v;\n    u -=\
    \ base, v -= base;\n    g[u].emplace_back(v);\n    if constexpr (!directed)\n\
    \      g[v].emplace_back(u);\n  }\n  return g;\n}\n\ntemplate<bool directed>\n\
    vvi adjacency_list(int n, vc<pii> e, int base) {\n  vvi g(n);\n  for(auto [u,\
    \ v] : e) {\n    u -= base, v -= base;\n    g[u].emplace_back(v);\n    if constexpr\
    \ (!directed)\n      g[v].emplace_back(u);\n  }\n  return g;\n}\n\ntemplate<class\
    \ T>\nvoid setBit(T &msk, int bit, bool x) { (msk &= ~(T(1) << bit)) |= T(x) <<\
    \ bit; }\ntemplate<class T> void onBit(T &msk, int bit) { setBit(msk, bit, true);\
    \ }\ntemplate<class T> void offBit(T &msk, int bit) { setBit(msk, bit, false);\
    \ }\ntemplate<class T> void flipBit(T &msk, int bit) { msk ^= T(1) << bit; }\n\
    template<class T> bool getBit(T msk, int bit) { return msk >> bit & T(1); }\n\n\
    template<class T>\nT floorDiv(T a, T b) {\n  if (b < 0) a *= -1, b *= -1;\n  return\
    \ a >= 0 ? a / b : (a - b + 1) / b;\n}\ntemplate<class T>\nT ceilDiv(T a, T b)\
    \ {\n  if (b < 0) a *= -1, b *= -1;\n  return a >= 0 ? (a + b - 1) / b : a / b;\n\
    }\n\ntemplate<class T> bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }\n\
    template<class T> bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }\n\n#line\
    \ 4 \"test/point_set_tree_path_composite_sum_fixed_root.test.cpp\"\n#define eb\
    \ emplace_back\n#define pb push_back\n#line 1 \"modint/MontgomeryModInt.cpp\"\n\
    //reference: https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10\n\
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
    \ is;\n  }\n};\n\nusing mint = MontgomeryModInt<998244353>;\n#line 1 \"ds/staticTopTree.cpp\"\
    \n//rake keep left child as exposed path\n//compress keep left child as higher\
    \ path\nstruct static_top_tree {\n  vector<vector<int>> g;\n  int n;\n  vector<int>\
    \ l, r, lc, rc, pa;\n  vector<bool> rake;\n\n  using a2 = array<int, 2>;\n\n \
    \ static_top_tree(vector<vector<int>> &_g, int R = 0)\n    : g(_g), n(size(g)),\
    \ l(n, -1), r(l), lc(l), rc(l), pa(l), rake(n) {\n    vector<int> sz(n, 1);\n\
    \    auto dfs = [&](int v, int p, auto &self) -> void {\n      l[v] = v, r[v]\
    \ = p;\n      int mx_c = -1;\n      for(int x : g[v]) {\n        if (x == p) continue;\n\
    \        self(x, v, self);\n        sz[v] += sz[x];\n        if (mx_c == -1 or\
    \ sz[x] > sz[mx_c])\n          mx_c = x;\n      }\n      if (auto ite = ranges::find(g[v],\
    \ p); ite != g[v].end())\n        g[v].erase(ite);\n      if (mx_c != -1)\n  \
    \      swap(g[v][0], *ranges::find(g[v], mx_c));\n    };\n\n    dfs(R, -1, dfs);\n\
    \    build(R);\n  }\n\n  int new_node(int _lc, int _rc, int _l, int _r, bool _rake)\
    \ {\n    lc.eb(_lc), rc.eb(_rc), l.eb(_l), r.eb(_r), pa.eb(-1), rake.eb(_rake);\n\
    \    return pa[_lc] = pa[_rc] = ssize(lc) - 1;\n  }\n\n  a2 build(int s) {\n \
    \   vector<int> path = {s};\n    while(!g[path.back()].empty())\n      path.eb(g[path.back()][0]);\n\
    \    vector<a2> exposed = {{0, s}};\n    for(int i = 0; int v : path | views::drop(1))\
    \ {\n      priority_queue<a2, vector<a2>, greater<a2>> pq;\n      pq.push({0,\
    \ v});\n      for(int x : g[path[i++]] | views::drop(1))\n        pq.push(build(x));\n\
    \      while(ssize(pq) > 1) {\n        auto [h1, v1] = pq.top(); pq.pop();\n \
    \       auto [h2, v2] = pq.top(); pq.pop();\n        if (v2 == v) swap(v1, v2);\n\
    \        int v3 = new_node(v1, v2, l[v1], r[v1], true);\n        pq.push({max(h1,\
    \ h2) + 1, v3});\n        if (v1 == v) v = v3;\n      }\n      exposed.eb(pq.top());\n\
    \    }\n    auto dc = [&](int ql, int qr, auto &self) -> a2 {\n      if (ql +\
    \ 1 == qr) return exposed[ql];\n      int mid = (ql + qr) / 2;\n      auto [hl,\
    \ vl] = self(ql, mid, self);\n      auto [hr, vr] = self(mid, qr, self);\n   \
    \   int v = new_node(vl, vr, l[vr], r[vl], false);\n      return {max(hl, hr)\
    \ + 1, v};\n    };\n    return dc(0, ssize(exposed), dc);\n  }\n};\n#line 1 \"\
    dp/dynamicTreeDP.cpp\"\n//#include \"ds/staticTopTree.cpp\"\ntemplate<class M,\
    \ M(*rake)(const M&, const M&), M(*compress)(const M&, const M&)>\nstruct dynamic_tree_dp\
    \ {\n  vector<M> dp;\n  static_top_tree stt;\n\n  void pull(int v) {\n    if (stt.rake[v])\
    \ dp[v] = rake(dp[stt.lc[v]], dp[stt.rc[v]]);\n    else dp[v] = compress(dp[stt.lc[v]],\
    \ dp[stt.rc[v]]);\n  }\n\n  dynamic_tree_dp(vector<vector<int>> &g, vector<M>\
    \ &init)\n    : dp(2 * ssize(g) - 1), stt(g) {\n    for(int i = 0; i < ssize(g);\
    \ i++)\n      dp[i] = init[i];\n    for(int i = ssize(g); i < 2 * ssize(g) - 1;\
    \ i++)\n      pull(i);\n  }\n\n  void set(int v, M x) {\n    dp[v] = x;\n    while((v\
    \ = stt.pa[v]) != -1) pull(v);\n  }\n\n  M query() { return dp.back(); }\n};\n\
    #line 9 \"test/point_set_tree_path_composite_sum_fixed_root.test.cpp\"\n\nstruct\
    \ M {\n  mint a, b, ans, sz;\n};\n\nM rake(const M &a, const M &b) {\n  return\
    \ M{a.a, a.b, a.ans + b.ans, a.sz + b.sz};\n}\nM compress(const M &a, const M\
    \ &b) {\n  return M{a.a * b.a, a.a * b.b + a.b, a.ans + b.ans * a.a + a.b * b.sz,\
    \ a.sz + b.sz};\n}\n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\
    \n  int n, q; cin >> n >> q;\n  vector<mint> a(n);\n  for(mint &x : a) cin >>\
    \ x;\n\n  vector<array<int, 4>> uvbc(n - 1);\n  for(auto &[u, v, b, c] : uvbc)\n\
    \    cin >> u >> v >> b >> c;\n\n  vector<vector<int>> g(n);\n  for(auto [u, v,\
    \ _, __] : uvbc)\n    g[u].eb(v), g[v].eb(u);\n  uvbc.pb({-1, 0, 1, 0});\n\n \
    \ static_top_tree stt(g);\n\n  vector<int> eid(n);\n  for(int i = 0; auto &[u,\
    \ v, _, __] : uvbc) {\n    if (stt.r[v] == u) swap(u, v);\n    eid[u] = i++;\n\
    \  }\n\n  auto get = [&](int v) {\n    auto [_, __, b, c] = uvbc[eid[v]];\n  \
    \  return M{b, c, a[v] * b + c, 1};\n  };\n\n  vector<M> init(n);\n  for(int i\
    \ = 0; i < n; i++)\n    init[i] = get(i);\n\n  dynamic_tree_dp<M, rake, compress>\
    \ ddp(g, init);\n\n  while(q--) {\n    int op; cin >> op;\n    if (op == 0) {\n\
    \      int w, x; cin >> w >> x;\n      a[w] = x;\n      ddp.set(w, get(w));\n\
    \    } else {\n      int e, y, z; cin >> e >> y >> z;\n      auto &[u, _, b, c]\
    \ = uvbc[e];\n      b = y, c = z;\n      ddp.set(u, get(u));\n    }\n    cout\
    \ << ddp.query().ans << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root\"\
    \n\n#include \"../default/t.cpp\"\n#define eb emplace_back\n#define pb push_back\n\
    #include \"../modint/MontgomeryModInt.cpp\"\n#include \"../ds/staticTopTree.cpp\"\
    \n#include \"../dp/dynamicTreeDP.cpp\"\n\nstruct M {\n  mint a, b, ans, sz;\n\
    };\n\nM rake(const M &a, const M &b) {\n  return M{a.a, a.b, a.ans + b.ans, a.sz\
    \ + b.sz};\n}\nM compress(const M &a, const M &b) {\n  return M{a.a * b.a, a.a\
    \ * b.b + a.b, a.ans + b.ans * a.a + a.b * b.sz, a.sz + b.sz};\n}\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin >> n >>\
    \ q;\n  vector<mint> a(n);\n  for(mint &x : a) cin >> x;\n\n  vector<array<int,\
    \ 4>> uvbc(n - 1);\n  for(auto &[u, v, b, c] : uvbc)\n    cin >> u >> v >> b >>\
    \ c;\n\n  vector<vector<int>> g(n);\n  for(auto [u, v, _, __] : uvbc)\n    g[u].eb(v),\
    \ g[v].eb(u);\n  uvbc.pb({-1, 0, 1, 0});\n\n  static_top_tree stt(g);\n\n  vector<int>\
    \ eid(n);\n  for(int i = 0; auto &[u, v, _, __] : uvbc) {\n    if (stt.r[v] ==\
    \ u) swap(u, v);\n    eid[u] = i++;\n  }\n\n  auto get = [&](int v) {\n    auto\
    \ [_, __, b, c] = uvbc[eid[v]];\n    return M{b, c, a[v] * b + c, 1};\n  };\n\n\
    \  vector<M> init(n);\n  for(int i = 0; i < n; i++)\n    init[i] = get(i);\n\n\
    \  dynamic_tree_dp<M, rake, compress> ddp(g, init);\n\n  while(q--) {\n    int\
    \ op; cin >> op;\n    if (op == 0) {\n      int w, x; cin >> w >> x;\n      a[w]\
    \ = x;\n      ddp.set(w, get(w));\n    } else {\n      int e, y, z; cin >> e >>\
    \ y >> z;\n      auto &[u, _, b, c] = uvbc[e];\n      b = y, c = z;\n      ddp.set(u,\
    \ get(u));\n    }\n    cout << ddp.query().ans << '\\n';\n  }\n\n  return 0;\n\
    }\n"
  dependsOn:
  - default/t.cpp
  - modint/MontgomeryModInt.cpp
  - ds/staticTopTree.cpp
  - dp/dynamicTreeDP.cpp
  isVerificationFile: true
  path: test/point_set_tree_path_composite_sum_fixed_root.test.cpp
  requiredBy: []
  timestamp: '2026-01-30 02:53:01+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/point_set_tree_path_composite_sum_fixed_root.test.cpp
layout: document
redirect_from:
- /verify/test/point_set_tree_path_composite_sum_fixed_root.test.cpp
- /verify/test/point_set_tree_path_composite_sum_fixed_root.test.cpp.html
title: test/point_set_tree_path_composite_sum_fixed_root.test.cpp
---
