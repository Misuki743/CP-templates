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
    path: ds/hashTable.cpp
    title: ds/hashTable.cpp
  - icon: ':heavy_check_mark:'
    path: tree/centroid_tree.cpp
    title: tree/centroid_tree.cpp
  - icon: ':heavy_check_mark:'
    path: tree/tree.cpp
    title: tree/tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree
    links:
    - https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree
  bundledCode: "#line 1 \"test/vertex_add_range_contour_sum_on_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree\"\
    \n\n#include <bits/extc++.h>\n#line 22 \"default/t.cpp\"\n#include <initializer_list>\n\
    #line 43 \"default/t.cpp\"\n#include <type_traits>\n#include <variant>\n#include\
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
    \ < b ? a = b, 1 : 0; }\n\n#line 1 \"ds/hashTable.cpp\"\n//source: https://codeforces.com/blog/entry/62393\n\
    //#include<ext/pb_ds/assoc_container.hpp>\n//#include<ext/pb_ds/tree_policy.hpp>\n\
    \nstruct custom_hash {\n    static uint64_t splitmix64(uint64_t x) {\n       \
    \ x += 0x9e3779b97f4a7c15;\n        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n        return x ^ (x >> 31);\n\
    \    }\n\n    size_t operator()(uint64_t x) const {\n        static const uint64_t\
    \ FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n   \
    \     return splitmix64(x + FIXED_RANDOM);\n    }\n};\n\nusing namespace __gnu_pbds;\n\
    \n//gp_hash_table<ll, int, custom_hash> m({}, {}, {}, {}, {1 << 16});\n#line 1\
    \ \"ds/fenwickTree.cpp\"\ntemplate<class T>\nstruct fenwickTree {\n  const int\
    \ size;\n  vector<T> data;\n\n  fenwickTree(int _size) : size(_size + 1), data(_size\
    \ + 1) {}\n  fenwickTree(vector<T> init) : size(ssize(init) + 1), data(ssize(init)\
    \ + 1) {\n    partial_sum(init.begin(), init.end(), data.begin() + 1);\n    for(int\
    \ i = size - 1; i > 0; i--)\n      data[i] -= data[i - (i & (-i))];\n  }\n\n \
    \ void add(int i, T d) {\n    for(i += 1; i < size; i += i & (-i))\n      data[i]\
    \ += d;\n  }\n\n  T query(int i) {\n    T res = T(0);\n    for(i += 1; i > 0;\
    \ i -= i & (-i))\n      res += data[i];\n    return res;\n  }\n\n  T query(int\
    \ l, int r) { //query [l, r)\n    return query(r - 1) - query(l - 1);\n  }\n};\n\
    #line 1 \"tree/tree.cpp\"\nclass tree {\n  using i32 = int32_t;\n\n  vc<i32> ord;\n\
    \n  public:\n\n  int n, root;\n  vc<int> p, sz, dep, jp;\n\n  tree(vc<pii> e,\
    \ int _root = 0) : n(size(e) + 1), root(_root) {\n    vc<i32> d(n), adj(n);\n\
    \    for(auto [u, v] : e)\n      d[u]++, d[v]++, adj[u] ^= v, adj[v] ^= u;\n \
    \   d[root] = 0;\n    calc(d, adj);\n  }\n\n  tree(vi pa) : n(size(pa)) {\n  \
    \  root = ranges::find(pa, -1) - pa.begin();\n    vc<i32> d(n), adj(n);\n    for(int\
    \ v = 0; v < n; v++)\n      if (pa[v] != -1)\n        d[v]++, d[pa[v]]++, adj[v]\
    \ ^= pa[v], adj[pa[v]] ^= v;\n    d[root] = 0;\n    calc(d, adj);\n  }\n\n  void\
    \ calc(vc<i32> d, vc<i32> adj) {\n    sz = vi(n, 1);\n    p = dep = jp = vi(n);\n\
    \n    ord.reserve(n - 1);\n    for(int i = 0; i < n; i++) {\n      int v = i;\n\
    \      while(d[v] == 1) {\n        ord.emplace_back(v);\n        p[v] = adj[v],\
    \ sz[p[v]] += sz[v];\n        d[v] = 0, d[p[v]]--, adj[p[v]] ^= v;\n        v\
    \ = p[v];\n      }\n    }\n\n    assert(ssize(ord) == n - 1);\n\n    p[root] =\
    \ jp[root] = root;\n    for(i32 v : ord | views::reverse) {\n      dep[v] = dep[p[v]]\
    \ + 1;\n      if (dep[p[v]] + dep[jp[jp[p[v]]]] == 2 * dep[jp[p[v]]])\n      \
    \  jp[v] = jp[jp[p[v]]];\n      else\n        jp[v] = p[v];\n    }\n  }\n\n  int\
    \ jump(int v, int k) {\n    k = min(k, dep[v]);\n    while(k) {\n      if (int\
    \ d = dep[v] - dep[jp[v]]; d <= k)\n        v = jp[v], k -= d;\n      else\n \
    \       v = p[v], k -= 1;\n    }\n    return v;\n  }\n\n  int lca(int u, int v)\
    \ {\n    if (dep[u] < dep[v])\n      swap(u, v);\n    u = jump(u, dep[u] - dep[v]);\n\
    \    if (u == v) return u;\n    while(p[u] != p[v]) {\n      if (jp[u] != jp[v])\
    \ u = jp[u], v = jp[v];\n      else u = p[u], v = p[v];\n    }\n    return p[u];\n\
    \  }\n\n  int kth(int s, int t, int k) {\n    int m = lca(s, t);\n    if (dep[s]\
    \ + dep[t] - 2 * dep[m] < k)\n      return -1;\n    else if (dep[s] - dep[m] >=\
    \ k)\n      return jump(s, k);\n    else\n      return jump(t, dep[s] + dep[t]\
    \ - 2 * dep[m] - k);\n  }\n\n  int dis(int u, int v) {\n    return dep[u] + dep[v]\
    \ - 2 * dep[lca(u, v)];\n  }\n\n  int median(int u, int v, int w) {\n    return\
    \ lca(u, v) ^ lca(u, w) ^ lca(v, w);\n  }\n\n  auto centroid() {\n    array<int,\
    \ 2> r = {-1, -1};\n    vector<bool> ok(n, true);\n    for(int v = 0; v < n; v++)\
    \ {\n      if (2 * (n - sz[v]) > n)\n        ok[v] = false;\n      if (v != root\
    \ and 2 * sz[v] > n)\n        ok[p[v]] = false;\n    }\n    for(int v = 0; v <\
    \ n; v++)\n      if (ok[v])\n        r[1] = v, swap(r[0], r[1]);\n    return r;\n\
    \  }\n};\n#line 1 \"tree/centroid_tree.cpp\"\nauto centroid_tree(vvi &g) {\n \
    \ int n = ssize(g);\n  vvi tr(n);\n  vi sz(n);\n  vc<bool> block(n, false);\n\n\
    \  auto calc = [&](int v, int p, auto &self) -> void {\n    sz[v] = 1;\n    for(int\
    \ x : g[v]) {\n      if (x == p or block[x]) continue;\n      self(x, v, self);\n\
    \      sz[v] += sz[x];\n    }\n  };\n\n  auto dfs = [&](int v, auto &self) ->\
    \ int {\n    calc(v, -1, calc);\n\n    int c = v, p = -1;\n    bool move;\n  \
    \  do {\n      move = false;\n      for(int x : g[c]) {\n        if (x == p or\
    \ block[x] or 2 * sz[x] <= sz[v]) continue;\n        move = true, p = c, c = x;\n\
    \        break;\n      }\n    } while(move);\n\n    block[c] = true;\n    for(int\
    \ x : g[c]) {\n      if (block[x]) continue;\n      x = self(x, self);\n     \
    \ tr[c].emplace_back(x);\n      tr[x].emplace_back(c);\n    }\n\n    return c;\n\
    \  };\n\n  int root = dfs(0, dfs);\n\n  return pair(tr, root);\n}\n#line 9 \"\
    test/vertex_add_range_contour_sum_on_tree.test.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<int> a(n);\n  for(int\
    \ &x : a)\n    cin >> x;\n  vector<pii> e(n - 1);\n  for(auto &[u, v] : e)\n \
    \   cin >> u >> v;\n  vector<vector<int>> g(n);\n  for(auto [u, v] : e) {\n  \
    \  g[u].emplace_back(v);\n    g[v].emplace_back(u);\n  }\n\n  auto [g2, r] = centroid_tree(g);\n\
    \n  vector<int> p(n, -1);\n  auto dfs = [&](int v, auto self) -> void {\n    for(int\
    \ x : g2[v]) {\n      if (x == p[v]) continue;\n      p[x] = v;\n      self(x,\
    \ self);\n    }\n  };\n  dfs(r, dfs);\n\n  gp_hash_table<ll, int, custom_hash>\
    \ toId;\n  vector<vector<array<int, 2>>> cand(2 * n);\n  vector<int> base(2 *\
    \ n);\n  vector<ll> init;\n  ::tree tr(e);\n  for(int s = 0; s < n; s++) {\n \
    \   auto dfs = [&](int v, auto self) -> void {\n      cand[s].push_back({tr.dis(s,\
    \ v), v});\n      if (p[s] != -1)\n        cand[s + n].push_back({tr.dis(p[s],\
    \ v), v});\n      for(int x : g2[v]) {\n        if (x == p[v]) continue;\n   \
    \     self(x, self);\n      }\n    };\n    dfs(s, dfs);\n    for(int d : {0, n})\
    \ {\n      base[s + d] = ssize(init);\n      ranges::sort(cand[s + d]);\n    \
    \  for(auto [_, v] : cand[s + d]) {\n        toId[(ll)v << 32 | (s + d)] = ssize(init);\n\
    \        init.emplace_back(a[v]);\n      }\n    }\n  }\n\n  fenwickTree<ll> ft(init);\n\
    \  auto query = [&](int v, int l, int r) {\n    int ql = base[v] + (ranges::lower_bound(cand[v],\
    \ array<int, 2>{l, -1}) - cand[v].begin());\n    int qr = base[v] + (ranges::lower_bound(cand[v],\
    \ array<int, 2>{r, -1}) - cand[v].begin());\n    return ft.query(ql, qr);\n  };\n\
    \n  while(q--) {\n    int op; cin >> op;\n    if (op == 0) {\n      int x, d;\
    \ cin >> x >> d;\n      int v = x;\n      while(v != -1) {\n        ft.add(toId[(ll)x\
    \ << 32 | v], d);\n        if (p[v] != -1)\n          ft.add(toId[(ll)x << 32\
    \ | (v + n)], d);\n        v = p[v];\n      }\n    } else {\n      int x, l, r;\
    \ cin >> x >> l >> r;\n      int v = x, pv = -1;\n      ll ans = 0;\n      while(v\
    \ != -1) {\n        int d = tr.dis(v, x);\n        ans += query(v, l - d, r -\
    \ d);\n        if (pv != -1)\n          ans -= query(pv + n, l - d, r - d);\n\
    \        pv = v, v = p[v];\n      }\n\n      cout << ans << '\\n';\n    }\n  }\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree\"\
    \n\n#include <bits/extc++.h>\n#include \"../default/t.cpp\"\n#include \"../ds/hashTable.cpp\"\
    \n#include \"../ds/fenwickTree.cpp\"\n#include \"../tree/tree.cpp\"\n#include\
    \ \"../tree/centroid_tree.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<int> a(n);\n  for(int\
    \ &x : a)\n    cin >> x;\n  vector<pii> e(n - 1);\n  for(auto &[u, v] : e)\n \
    \   cin >> u >> v;\n  vector<vector<int>> g(n);\n  for(auto [u, v] : e) {\n  \
    \  g[u].emplace_back(v);\n    g[v].emplace_back(u);\n  }\n\n  auto [g2, r] = centroid_tree(g);\n\
    \n  vector<int> p(n, -1);\n  auto dfs = [&](int v, auto self) -> void {\n    for(int\
    \ x : g2[v]) {\n      if (x == p[v]) continue;\n      p[x] = v;\n      self(x,\
    \ self);\n    }\n  };\n  dfs(r, dfs);\n\n  gp_hash_table<ll, int, custom_hash>\
    \ toId;\n  vector<vector<array<int, 2>>> cand(2 * n);\n  vector<int> base(2 *\
    \ n);\n  vector<ll> init;\n  ::tree tr(e);\n  for(int s = 0; s < n; s++) {\n \
    \   auto dfs = [&](int v, auto self) -> void {\n      cand[s].push_back({tr.dis(s,\
    \ v), v});\n      if (p[s] != -1)\n        cand[s + n].push_back({tr.dis(p[s],\
    \ v), v});\n      for(int x : g2[v]) {\n        if (x == p[v]) continue;\n   \
    \     self(x, self);\n      }\n    };\n    dfs(s, dfs);\n    for(int d : {0, n})\
    \ {\n      base[s + d] = ssize(init);\n      ranges::sort(cand[s + d]);\n    \
    \  for(auto [_, v] : cand[s + d]) {\n        toId[(ll)v << 32 | (s + d)] = ssize(init);\n\
    \        init.emplace_back(a[v]);\n      }\n    }\n  }\n\n  fenwickTree<ll> ft(init);\n\
    \  auto query = [&](int v, int l, int r) {\n    int ql = base[v] + (ranges::lower_bound(cand[v],\
    \ array<int, 2>{l, -1}) - cand[v].begin());\n    int qr = base[v] + (ranges::lower_bound(cand[v],\
    \ array<int, 2>{r, -1}) - cand[v].begin());\n    return ft.query(ql, qr);\n  };\n\
    \n  while(q--) {\n    int op; cin >> op;\n    if (op == 0) {\n      int x, d;\
    \ cin >> x >> d;\n      int v = x;\n      while(v != -1) {\n        ft.add(toId[(ll)x\
    \ << 32 | v], d);\n        if (p[v] != -1)\n          ft.add(toId[(ll)x << 32\
    \ | (v + n)], d);\n        v = p[v];\n      }\n    } else {\n      int x, l, r;\
    \ cin >> x >> l >> r;\n      int v = x, pv = -1;\n      ll ans = 0;\n      while(v\
    \ != -1) {\n        int d = tr.dis(v, x);\n        ans += query(v, l - d, r -\
    \ d);\n        if (pv != -1)\n          ans -= query(pv + n, l - d, r - d);\n\
    \        pv = v, v = p[v];\n      }\n\n      cout << ans << '\\n';\n    }\n  }\n\
    \n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - ds/hashTable.cpp
  - ds/fenwickTree.cpp
  - tree/tree.cpp
  - tree/centroid_tree.cpp
  isVerificationFile: true
  path: test/vertex_add_range_contour_sum_on_tree.test.cpp
  requiredBy: []
  timestamp: '2026-02-07 19:26:24+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/vertex_add_range_contour_sum_on_tree.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_add_range_contour_sum_on_tree.test.cpp
- /verify/test/vertex_add_range_contour_sum_on_tree.test.cpp.html
title: test/vertex_add_range_contour_sum_on_tree.test.cpp
---
