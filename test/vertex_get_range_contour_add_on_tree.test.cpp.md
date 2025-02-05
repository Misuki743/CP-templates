---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/centroidTree.cpp
    title: ds/centroidTree.cpp
  - icon: ':heavy_check_mark:'
    path: ds/fastJump.cpp
    title: ds/fastJump.cpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwickTree.cpp
    title: ds/fenwickTree.cpp
  - icon: ':heavy_check_mark:'
    path: ds/hashTable.cpp
    title: ds/hashTable.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree
    links:
    - https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree
  bundledCode: "#line 1 \"test/vertex_get_range_contour_add_on_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree\"\
    \n\n#include <bits/extc++.h>\n#line 22 \"default/t.cpp\"\n#include <initializer_list>\n\
    #line 43 \"default/t.cpp\"\n#include <type_traits>\n#include <variant>\n#include\
    \ <bit>\n#include <compare>\n#include <concepts>\n#include <numbers>\n#include\
    \ <ranges>\n#include <span>\n\n#define INT128_MAX (__int128)(((unsigned __int128)\
    \ 1 << ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN (-INT128_MAX\
    \ - 1)\n\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
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
    \ chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"ds/hashTable.cpp\"\
    \n//source: https://codeforces.com/blog/entry/62393\n//#include<ext/pb_ds/assoc_container.hpp>\n\
    //#include<ext/pb_ds/tree_policy.hpp>\n\nstruct custom_hash {\n    static uint64_t\
    \ splitmix64(uint64_t x) {\n        x += 0x9e3779b97f4a7c15;\n        x = (x ^\
    \ (x >> 30)) * 0xbf58476d1ce4e5b9;\n        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \        return x ^ (x >> 31);\n    }\n\n    size_t operator()(uint64_t x) const\
    \ {\n        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n\
    \        return splitmix64(x + FIXED_RANDOM);\n    }\n};\n\nusing namespace __gnu_pbds;\n\
    \n//gp_hash_table<ll, int, custom_hash> m({}, {}, {}, {}, {1 << 16});\n#line 1\
    \ \"ds/fenwickTree.cpp\"\ntemplate<class T>\nstruct fenwickTree {\n  const int\
    \ size;\n  vector<T> data;\n\n  fenwickTree(int _size) : size(_size + 1), data(_size\
    \ + 1) {}\n  fenwickTree(vector<T> &init) : size(ssize(init) + 1), data(ssize(init)\
    \ + 1) {\n    partial_sum(init.begin(), init.end(), data.begin() + 1);\n    for(int\
    \ i = size - 1; i > 0; i--)\n      data[i] -= data[i - (i & (-i))];\n  }\n\n \
    \ void add(int i, T d) {\n    for(i += 1; i < size; i += i & (-i))\n      data[i]\
    \ += d;\n  }\n\n  T query(int i) {\n    T res = T(0);\n    for(i += 1; i > 0;\
    \ i -= i & (-i))\n      res += data[i];\n    return res;\n  }\n\n  T query(int\
    \ l, int r) { //query [l, r)\n    return query(r - 1) - query(l - 1);\n  }\n};\n\
    #line 1 \"ds/fastJump.cpp\"\nstruct fastJump {\n  vector<int> p, jp, dep;\n\n\
    \  fastJump(vector<vector<int>> g, int root = 0) : p(ssize(g)), jp(ssize(g)),\
    \ dep(ssize(g)) {\n    auto dfs = [&](int v, auto self) -> void {\n      if (dep[p[v]]\
    \ + dep[jp[jp[p[v]]]] == 2 * dep[jp[p[v]]])\n        jp[v] = jp[jp[p[v]]];\n \
    \     else\n        jp[v] = p[v];\n\n      for(int x : g[v]) {\n        if (x\
    \ == p[v]) continue;\n        p[x] = v, dep[x] = dep[v] + 1;\n        self(x,\
    \ self);\n      }\n    };\n\n    p[root] = jp[root] = root;\n    dfs(root, dfs);\n\
    \  }\n\n  int jump(int v, int k) {\n    k = min(k, dep[v]);\n    while(k) {\n\
    \      if (int d = dep[v] - dep[jp[v]]; d <= k)\n        v = jp[v], k -= d;\n\
    \      else\n        v = p[v], k -= 1;\n    }\n    return v;\n  }\n\n  int lca(int\
    \ u, int v) {\n    if (dep[u] < dep[v])\n      swap(u, v);\n    u = jump(u, dep[u]\
    \ - dep[v]);\n    if (u == v) return u;\n    while(p[u] != p[v]) {\n      if (jp[u]\
    \ != jp[v]) u = jp[u], v = jp[v];\n      else u = p[u], v = p[v];\n    }\n   \
    \ return p[u];\n  }\n\n  int kth(int s, int t, int k) {\n    int m = lca(s, t);\n\
    \    if (dep[s] + dep[t] - 2 * dep[m] < k)\n      return -1;\n    else if (dep[s]\
    \ - dep[m] >= k)\n      return jump(s, k);\n    else\n      return jump(t, dep[s]\
    \ + dep[t] - 2 * dep[m] - k);\n  }\n\n  int dis(int u, int v) {\n    return dep[u]\
    \ + dep[v] - 2 * dep[lca(u, v)];\n  }\n};\n#line 1 \"ds/centroidTree.cpp\"\npair<vector<vector<int>>,\
    \ int> centroidTree(vector<vector<int>> &g) {\n  int n = ssize(g);\n  vector<vector<int>>\
    \ g2(n);\n  vector<int> sz(n);\n  vector<bool> block(n, false);\n\n  auto calc\
    \ = [&](int v, int p, auto self) -> void {\n    sz[v] = 1;\n    for(int x : g[v])\
    \ {\n      if (x == p or block[x]) continue;\n      self(x, v, self);\n      sz[v]\
    \ += sz[x];\n    }\n  };\n\n  auto dfs = [&](int v, auto self) -> int {\n    calc(v,\
    \ -1, calc);\n\n    int c = v, p = -1;\n    bool move;\n    do {\n      move =\
    \ false;\n      for(int x : g[c]) {\n        if (x == p or block[x] or 2 * sz[x]\
    \ <= sz[v]) continue;\n        move = true, p = c, c = x;\n        break;\n  \
    \    }\n    } while(move);\n\n    block[c] = true;\n    for(int x : g[c]) {\n\
    \      if (block[x]) continue;\n      x = self(x, self);\n      g2[c].emplace_back(x);\n\
    \      g2[x].emplace_back(c);\n    }\n\n    return c;\n  };\n\n  int root = dfs(0,\
    \ dfs);\n\n  return make_pair(g2, root);\n}\n#line 9 \"test/vertex_get_range_contour_add_on_tree.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ q; cin >> n >> q;\n  vector<int> a(n);\n  for(int &x : a)\n    cin >> x;\n \
    \ vector<vector<int>> g(n);\n  for(int i = 1; i < n; i++) {\n    int u, v; cin\
    \ >> u >> v;\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n  }\n\n  auto\
    \ [g2, r] = centroidTree(g);\n\n  vector<int> p(n, -1);\n  auto dfs = [&](int\
    \ v, auto self) -> void {\n    for(int x : g2[v]) {\n      if (x == p[v]) continue;\n\
    \      p[x] = v;\n      self(x, self);\n    }\n  };\n  dfs(r, dfs);\n\n  gp_hash_table<ll,\
    \ int, custom_hash> toId({}, {}, {}, {}, {1 << 19});\n  vector<vector<array<int,\
    \ 2>>> cand(2 * n);\n  vector<int> base(2 * n);\n  vector<ll> init;\n  init.reserve(1\
    \ << 19);\n  fastJump fj(g);\n  for(int s = 0; s < n; s++) {\n    auto dfs = [&](int\
    \ v, auto self) -> void {\n      cand[s].push_back({fj.dis(s, v), v});\n     \
    \ if (p[s] != -1)\n        cand[s + n].push_back({fj.dis(p[s], v), v});\n    \
    \  for(int x : g2[v]) {\n        if (x == p[v]) continue;\n        self(x, self);\n\
    \      }\n    };\n    dfs(s, dfs);\n    for(int d : {0, n}) {\n      base[s +\
    \ d] = ssize(init);\n      ranges::sort(cand[s + d]);\n      for(auto [_, v] :\
    \ cand[s + d]) {\n        toId[(ll)v << 32 | (s + d)] = ssize(init);\n       \
    \ init.emplace_back(a[v]);\n      }\n    }\n  }\n\n  adjacent_difference(init.begin(),\
    \ init.end(), init.begin());\n  fenwickTree<ll> ft(init);\n  auto modify = [&](int\
    \ v, int l, int r, int d) {\n    int ql = base[v] + (ranges::lower_bound(cand[v],\
    \ array<int, 2>{l, -1}) - cand[v].begin());\n    int qr = base[v] + (ranges::lower_bound(cand[v],\
    \ array<int, 2>{r, -1}) - cand[v].begin());\n    ft.add(ql, d), ft.add(qr, -d);\n\
    \  };\n\n  while(q--) {\n    int op; cin >> op;\n    if (op == 0) {\n      int\
    \ x, l, r, d; cin >> x >> l >> r >> d;\n      int v = x, pv = -1;\n      while(v\
    \ != -1) {\n        int di = fj.dis(v, x);\n        modify(v, l - di, r - di,\
    \ d);\n        if (pv != -1) {\n          modify(pv + n, l - di, r - di, d);\n\
    \        }\n        pv = v, v = p[v];\n      }\n    } else {\n      int x; cin\
    \ >> x;\n      int v = x, pv = -1;\n      ll ans = 0;\n      while(v != -1) {\n\
    \        ans += ft.query(toId[(ll)x << 32 | v]);\n        if (pv != -1)\n    \
    \      ans -= ft.query(toId[(ll)x << 32 | (pv + n)]);\n        pv = v, v = p[v];\n\
    \      }\n      cout << ans << '\\n';\n    }\n  }\n\n  return 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree\"\
    \n\n#include <bits/extc++.h>\n#include \"../default/t.cpp\"\n#include \"../ds/hashTable.cpp\"\
    \n#include \"../ds/fenwickTree.cpp\"\n#include \"../ds/fastJump.cpp\"\n#include\
    \ \"../ds/centroidTree.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<int> a(n);\n  for(int\
    \ &x : a)\n    cin >> x;\n  vector<vector<int>> g(n);\n  for(int i = 1; i < n;\
    \ i++) {\n    int u, v; cin >> u >> v;\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n\
    \  }\n\n  auto [g2, r] = centroidTree(g);\n\n  vector<int> p(n, -1);\n  auto dfs\
    \ = [&](int v, auto self) -> void {\n    for(int x : g2[v]) {\n      if (x ==\
    \ p[v]) continue;\n      p[x] = v;\n      self(x, self);\n    }\n  };\n  dfs(r,\
    \ dfs);\n\n  gp_hash_table<ll, int, custom_hash> toId({}, {}, {}, {}, {1 << 19});\n\
    \  vector<vector<array<int, 2>>> cand(2 * n);\n  vector<int> base(2 * n);\n  vector<ll>\
    \ init;\n  init.reserve(1 << 19);\n  fastJump fj(g);\n  for(int s = 0; s < n;\
    \ s++) {\n    auto dfs = [&](int v, auto self) -> void {\n      cand[s].push_back({fj.dis(s,\
    \ v), v});\n      if (p[s] != -1)\n        cand[s + n].push_back({fj.dis(p[s],\
    \ v), v});\n      for(int x : g2[v]) {\n        if (x == p[v]) continue;\n   \
    \     self(x, self);\n      }\n    };\n    dfs(s, dfs);\n    for(int d : {0, n})\
    \ {\n      base[s + d] = ssize(init);\n      ranges::sort(cand[s + d]);\n    \
    \  for(auto [_, v] : cand[s + d]) {\n        toId[(ll)v << 32 | (s + d)] = ssize(init);\n\
    \        init.emplace_back(a[v]);\n      }\n    }\n  }\n\n  adjacent_difference(init.begin(),\
    \ init.end(), init.begin());\n  fenwickTree<ll> ft(init);\n  auto modify = [&](int\
    \ v, int l, int r, int d) {\n    int ql = base[v] + (ranges::lower_bound(cand[v],\
    \ array<int, 2>{l, -1}) - cand[v].begin());\n    int qr = base[v] + (ranges::lower_bound(cand[v],\
    \ array<int, 2>{r, -1}) - cand[v].begin());\n    ft.add(ql, d), ft.add(qr, -d);\n\
    \  };\n\n  while(q--) {\n    int op; cin >> op;\n    if (op == 0) {\n      int\
    \ x, l, r, d; cin >> x >> l >> r >> d;\n      int v = x, pv = -1;\n      while(v\
    \ != -1) {\n        int di = fj.dis(v, x);\n        modify(v, l - di, r - di,\
    \ d);\n        if (pv != -1) {\n          modify(pv + n, l - di, r - di, d);\n\
    \        }\n        pv = v, v = p[v];\n      }\n    } else {\n      int x; cin\
    \ >> x;\n      int v = x, pv = -1;\n      ll ans = 0;\n      while(v != -1) {\n\
    \        ans += ft.query(toId[(ll)x << 32 | v]);\n        if (pv != -1)\n    \
    \      ans -= ft.query(toId[(ll)x << 32 | (pv + n)]);\n        pv = v, v = p[v];\n\
    \      }\n      cout << ans << '\\n';\n    }\n  }\n\n  return 0;\n}\n\n"
  dependsOn:
  - default/t.cpp
  - ds/hashTable.cpp
  - ds/fenwickTree.cpp
  - ds/fastJump.cpp
  - ds/centroidTree.cpp
  isVerificationFile: true
  path: test/vertex_get_range_contour_add_on_tree.test.cpp
  requiredBy: []
  timestamp: '2024-11-19 21:59:27+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/vertex_get_range_contour_add_on_tree.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_get_range_contour_add_on_tree.test.cpp
- /verify/test/vertex_get_range_contour_add_on_tree.test.cpp.html
title: test/vertex_get_range_contour_add_on_tree.test.cpp
---
