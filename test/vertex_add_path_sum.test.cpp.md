---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwickTree.cpp
    title: ds/fenwickTree.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/vertex_add_path_sum.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#line 1 \"default/t.cpp\"\
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
    \ pb push_back\n#define eb emplace_back\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
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
    \ < b ? a = b, 1 : 0; }\n\n#line 1 \"tree/HLD.cpp\"\nstruct HLD {\n  static const\
    \ int MSK = (1 << 30);\n  vi dep, p_head, tin, tout, inv_tin;\n\n  inline int\
    \ head(int v) const { return (p_head[v] & MSK) ? v : p_head[v]; }\n  inline int\
    \ head_parent(int v) const { return p_head[head(v)] & (MSK - 1); }\n\n  HLD(vc<pii>\
    \ e, int root = 0) {\n    const int n = ssize(e) + 1;\n\n    dep = p_head = tin\
    \ = tout = vi(n);\n\n    vi sz(n, 1), mx_child_sz(n, -1);\n    {\n      vi d(n);\n\
    \      for(auto [u, v] : e)\n        p_head[u] ^= v, p_head[v] ^= u, d[u]++, d[v]++;\n\
    \      d[root] = 0;\n      for(int i = 0; i < n; i++) {\n        int v = i;\n\
    \        while(d[v] == 1) {\n          d[v] = 0, d[p_head[v]]--, p_head[p_head[v]]\
    \ ^= v;\n          sz[p_head[v]] += sz[v];\n          chmax(mx_child_sz[p_head[v]],\
    \ sz[v]);\n          v = p_head[v];\n        }\n      }\n      p_head[root] =\
    \ root;\n    }\n\n    vi ord(n);\n    {\n      vi f(n + 2);\n      for(int x :\
    \ sz) f[x + 1]++;\n      pSum(f);\n      for(int v = 0; v < n; v++)\n        ord[n\
    \ - 1 - (f[sz[v]]++)] = v;\n    }\n\n    {\n      p_head[root] = (root | MSK),\
    \ tout[root] = n;\n\n      vi add(n, 1);\n      for(int v : ord | views::drop(1))\
    \ {\n        dep[v] = dep[p_head[v]] + 1;\n        tin[v] = tin[p_head[v]] + add[p_head[v]];\n\
    \        add[p_head[v]] += sz[v];\n        tout[v] = tin[v] + sz[v];\n       \
    \ if (mx_child_sz[p_head[v]] == sz[v])\n          mx_child_sz[p_head[v]] = 0,\
    \ p_head[v] = head(p_head[v]);\n        else\n          p_head[v] |= MSK;\n  \
    \    }\n    }\n\n    inv_tin = invPerm(tin);\n  }\n\n  auto query_path(int u,\
    \ int v, bool edge = false) {\n    vc<pii> lr;\n    while(head(u) != head(v))\
    \ {\n      if (dep[head(u)] > dep[head(v)])\n        swap(u, v);\n      lr.emplace_back(tin[head(v)],\
    \ tin[v] + 1);\n      v = head_parent(v);\n    }\n\n    if (tin[u] > tin[v]) swap(u,\
    \ v);\n    if (tin[u] + edge <= tin[v])\n      lr.emplace_back(tin[u] + edge,\
    \ tin[v] + 1);\n\n    return lr;\n  }\n\n  //l < r: op(l, op(l + 1, ...))\n  //l\
    \ > r: op(r - 1, op(r - 2, ...))\n  auto query_path_non_commutative(int u, int\
    \ v, bool edge = false) {\n    vc<pii> lr1, lr2;\n    while(head(u) != head(v))\
    \ {\n      if (dep[head(u)] > dep[head(v)]) {\n        lr1.emplace_back(tin[u]\
    \ + 1, tin[head(u)]);\n        u = head_parent(u);\n      } else {\n        lr2.emplace_back(tin[head(v)],\
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
    \      r[tin[i]] = init[i];\n    return r;\n  }\n};\n#line 1 \"ds/fenwickTree.cpp\"\
    \ntemplate<class T>\nstruct fenwickTree {\n  const int size;\n  vector<T> data;\n\
    \n  fenwickTree(int _size) : size(_size + 1), data(_size + 1) {}\n  fenwickTree(vector<T>\
    \ init) : size(ssize(init) + 1), data(ssize(init) + 1) {\n    partial_sum(init.begin(),\
    \ init.end(), data.begin() + 1);\n    for(int i = size - 1; i > 0; i--)\n    \
    \  data[i] -= data[i - (i & (-i))];\n  }\n\n  void add(int i, T d) {\n    for(i\
    \ += 1; i < size; i += i & (-i))\n      data[i] += d;\n  }\n\n  T query(int i)\
    \ {\n    T res = T(0);\n    for(i += 1; i > 0; i -= i & (-i))\n      res += data[i];\n\
    \    return res;\n  }\n\n  T query(int l, int r) { //query [l, r)\n    return\
    \ query(r - 1) - query(l - 1);\n  }\n};\n#line 6 \"test/vertex_add_path_sum.test.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q;\
    \ cin >> n >> q;\n  vll a(n);\n  for(ll &x : a) cin >> x;\n  vc<pii> e(n - 1);\n\
    \  for(auto &[u, v] : e)\n    cin >> u >> v;\n\n  HLD hld(std::move(e));\n  fenwickTree\
    \ ft(hld.reorder_init(a));\n  while(q--) {\n    int op; cin >> op;\n    if (op\
    \ == 0) {\n      int p, x; cin >> p >> x;\n      ft.add(hld.query_point(p), x);\n\
    \    } else {\n      int u, v; cin >> u >> v;\n      ll sum = 0;\n      for(auto\
    \ [l, r] : hld.query_path(u, v))\n        sum += ft.query(l, r);\n      cout <<\
    \ sum << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../default/t.cpp\"\n#include \"../tree/HLD.cpp\"\n#include \"../ds/fenwickTree.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q;\
    \ cin >> n >> q;\n  vll a(n);\n  for(ll &x : a) cin >> x;\n  vc<pii> e(n - 1);\n\
    \  for(auto &[u, v] : e)\n    cin >> u >> v;\n\n  HLD hld(std::move(e));\n  fenwickTree\
    \ ft(hld.reorder_init(a));\n  while(q--) {\n    int op; cin >> op;\n    if (op\
    \ == 0) {\n      int p, x; cin >> p >> x;\n      ft.add(hld.query_point(p), x);\n\
    \    } else {\n      int u, v; cin >> u >> v;\n      ll sum = 0;\n      for(auto\
    \ [l, r] : hld.query_path(u, v))\n        sum += ft.query(l, r);\n      cout <<\
    \ sum << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - tree/HLD.cpp
  - ds/fenwickTree.cpp
  isVerificationFile: true
  path: test/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2026-02-07 19:26:24+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_add_path_sum.test.cpp
- /verify/test/vertex_add_path_sum.test.cpp.html
title: test/vertex_add_path_sum.test.cpp
---
