---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/LCA.cpp
    title: ds/LCA.cpp
  - icon: ':heavy_check_mark:'
    path: ds/RMQ.cpp
    title: ds/RMQ.cpp
  - icon: ':heavy_check_mark:'
    path: ds/eulerTour.cpp
    title: ds/eulerTour.cpp
  - icon: ':heavy_check_mark:'
    path: segtree/dualSegmentTree.cpp
    title: segtree/dualSegmentTree.cpp
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
    \ &&v) {\n  if (!v.empty())\n    for(T p = v[0]; T &x : v | views::drop(1))\n\
    \      x = p = OP()(p, x);\n}\ntemplate<ranges::forward_range rng, class T = ranges::range_value_t<rng>,\
    \ class OP>\nvoid pSum(rng &&v, OP op) {\n  if (!v.empty())\n    for(T p = v[0];\
    \ T &x : v | views::drop(1))\n      x = p = op(p, x);\n}\n\ntemplate<ranges::forward_range\
    \ rng>\nvoid Unique(rng &v) {\n  ranges::sort(v);\n  v.resize(unique(v.begin(),\
    \ v.end()) - v.begin());\n}\n\ntemplate<ranges::random_access_range rng>\nrng\
    \ invPerm(rng p) {\n  rng ret = p;\n  for(int i = 0; i < ssize(p); i++)\n    ret[p[i]]\
    \ = i;\n  return ret;\n}\n\ntemplate<ranges::random_access_range rng, ranges::random_access_range\
    \ rng2>\nrng Permute(rng v, rng2 p) {\n  rng ret = v;\n  for(int i = 0; i < ssize(p);\
    \ i++)\n    ret[p[i]] = v[i];\n  return ret;\n}\n\ntemplate<bool directed>\nvector<vector<int>>\
    \ read_graph(int n, int m, int base) {\n  vector<vector<int>> g(n);\n  for(int\
    \ i = 0; i < m; i++) {\n    int u, v; cin >> u >> v;\n    u -= base, v -= base;\n\
    \    g[u].emplace_back(v);\n    if constexpr (!directed)\n      g[v].emplace_back(u);\n\
    \  }\n  return g;\n}\n\ntemplate<bool directed>\nvector<vector<int>> adjacency_list(int\
    \ n, vector<pii> e, int base) {\n  vector<vector<int>> g(n);\n  for(auto [u, v]\
    \ : e) {\n    u -= base, v -= base;\n    g[u].emplace_back(v);\n    if constexpr\
    \ (!directed)\n      g[v].emplace_back(u);\n  }\n  return g;\n}\n\ntemplate<class\
    \ T>\nvoid setBit(T &msk, int bit, bool x) {\n  msk = (msk & ~(T(1) << bit)) |\
    \ (T(x) << bit);\n}\ntemplate<class T> void flipBit(T &msk, int bit) { msk ^=\
    \ T(1) << bit; }\ntemplate<class T> bool getBit(T msk, int bit) { return msk >>\
    \ bit & T(1); }\n\ntemplate<class T>\nT floorDiv(T a, T b) {\n  if (b < 0) a *=\
    \ -1, b *= -1;\n  return a >= 0 ? a / b : (a - b + 1) / b;\n}\ntemplate<class\
    \ T>\nT ceilDiv(T a, T b) {\n  if (b < 0) a *= -1, b *= -1;\n  return a >= 0 ?\
    \ (a + b - 1) / b : a / b;\n}\n\ntemplate<class T> bool chmin(T &a, T b) { return\
    \ a > b ? a = b, 1 : 0; }\ntemplate<class T> bool chmax(T &a, T b) { return a\
    \ < b ? a = b, 1 : 0; }\n\n#line 1 \"ds/RMQ.cpp\"\ntemplate<class T>\nstruct RMQ\
    \ {\n  uint64_t size;\n  vector<T> base;\n  vector<vector<T>> table;\n  vector<uint32_t>\
    \ msk;\n\n  static const int lgw = 5;\n  static const int w = 1 << lgw;\n  RMQ(vector<T>\
    \ _base) : size(ssize(_base)), base(_base), msk(size) {\n    msk.back() = 1;\n\
    \    for(int i = size - 2; i >= 0; i--) {\n      msk[i] = msk[i + 1] << 1;\n \
    \     while(msk[i] != 0 and base[i + countr_zero(msk[i])] >= base[i])\n      \
    \  msk[i] ^= 1u << countr_zero(msk[i]);\n      msk[i] |= 1u;\n    }\n\n    table\
    \ = vector(bit_width(size >> lgw), vector<T>(size >> lgw));\n    if (!table.empty())\n\
    \      for(uint64_t i = 0; i + w <= size; i += w)\n        table[0][i >> lgw]\
    \ = base[i + bit_width(msk[i]) - 1];\n    for(int i = 1; i < ssize(table); i++)\n\
    \      for(uint64_t j = 0; j < (size >> lgw); j++)\n        if (j + (1 << (i -\
    \ 1)) < (size >> lgw))\n          table[i][j] = min(table[i - 1][j], table[i -\
    \ 1][j + (1 << (i - 1))]);\n        else\n          table[i][j] = table[i - 1][j];\n\
    \  }\n\n  T query(int l, int r) {\n    if (l >= r) {\n      return numeric_limits<T>::max();\n\
    \    } else if (r - l <= w) {\n      return base[l + bit_width(msk[l] & (~0u >>\
    \ (w - (r - l)))) - 1];\n    } else {\n      T ret = min(query(l, l + w), query(r\
    \ - w, r));\n      l = (l + w) >> lgw, r >>= lgw;\n      if (l == r) return ret;\n\
    \      int range = bit_width((unsigned)(r - l)) - 1;\n      return min({ret, table[range][l],\
    \ table[range][r - (1 << range)]});\n    }\n  }\n};\n#line 1 \"ds/LCA.cpp\"\n\
    //#include \"ds/RMQ.cpp\"\n\nstruct LCA {\n  vector<int> dep, tin, tout, mp;\n\
    \  RMQ<int> rmq;\n\n  LCA(vector<vector<int>> g, int root = 0)\n  : dep(size(g)),\
    \ tin(size(g)), tout(size(g)), mp(size(g)), rmq(vector<int>(1)) {\n\n    int t\
    \ = 0;\n    vector<int> init(2 * ssize(g) - 1);\n    auto dfs = [&](int v, int\
    \ p, auto &&self) -> void {\n      init[t] = v;\n      tin[v] = t++;\n      for(int\
    \ x : g[v]) {\n        if (x == p) continue;\n        dep[x] = dep[v] + 1;\n \
    \       self(x, v, self);\n        init[t++] = v;\n      }\n      tout[v] = t;\n\
    \    };\n\n    dfs(root, -1, dfs);\n\n    vector<int> f(size(g));\n    for(int\
    \ x : dep) f[x]++;\n    for(int i = 1; i < ssize(g); i++)\n      f[i] += f[i -\
    \ 1];\n    vector<int> toOrd(size(g));\n    for(int i = 0; i < ssize(g); i++)\
    \ {\n      toOrd[i] = --f[dep[i]];\n      mp[f[dep[i]]] = i;\n    }\n    for(int\
    \ &x : init) x = toOrd[x];\n    rmq = RMQ(init);\n  }\n\n  int lca(int u, int\
    \ v) {\n    if (tin[u] > tin[v]) swap(u, v);\n    return mp[rmq.query(tin[u],\
    \ tout[v])];\n  }\n\n  int dis(int u, int v) {\n    return dep[u] + dep[v] - 2\
    \ * dep[lca(u, v)];\n  }\n};\n#line 1 \"segtree/dualSegmentTree.cpp\"\ntemplate<class\
    \ M, M(*Mid)(), class T, T(*Tid)(), T(*Top)(const T&, const T&), M(*act)(const\
    \ M&, const T&)>\nstruct dualSegmentTree {\n  vector<M> data;\n  vector<T> tag;\n\
    \  int size;\n\n  dualSegmentTree(int _size) : data(_size, Mid()), tag(_size,\
    \ Tid()), size(_size) {}\n  dualSegmentTree(vector<M> init) : data(init), tag(ssize(init),\
    \ Tid()), size(ssize(init)) {}\n\n  void apply(int i, T x) {\n    if (i < size)\n\
    \      tag[i] = Top(tag[i], x);\n    else\n      data[i - size] = act(data[i -\
    \ size], x);\n  }\n\n  int trunc(unsigned i) { return i >> countr_zero(i); }\n\
    \n  void push(int i) {\n    for(int s = (int)bit_width((unsigned)i) - 1; s > 0;\
    \ s--) {\n      if (tag[i >> s] != Tid()) {\n        apply(i >> (s - 1), tag[i\
    \ >> s]);\n        apply(i >> (s - 1) ^ 1, tag[i >> s]);\n        tag[i >> s]\
    \ = Tid();\n      }\n    }\n  }\n\n  void set(int i, M x) {\n    push(i + size);\n\
    \    data[i] = x;\n  }\n\n  M get(int i) {\n    push(i + size);\n    return data[i];\n\
    \  }\n\n  void modify(int l, int r, T x) {\n    if (l >= r or x == Tid()) return;\n\
    \    push(trunc(l + size)), push(trunc(r + size) - 1);\n    for(l += size, r +=\
    \ size; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) apply(l++, x);\n      if\
    \ (r & 1) apply(--r, x);\n    }\n  }\n};\n#line 1 \"ds/eulerTour.cpp\"\n//#include<ds/RMQ.cpp>\n\
    //#include<ds/LCA.cpp>\n//#include<segtree/dualSegmentTree.cpp>\n\ntemplate<class\
    \ M, M(*Mid)(), M(*Mop)(const M&, const M&), M(*Minv)(const M&), \nclass T, T(*Tid)(),\
    \ T(*Top)(const T&, const T&), M(*act)(const M&, const T&)>\nstruct eulerTour\
    \ {\n  vector<int> tin, tout, p;\n  dualSegmentTree<M, Mid, T, Tid, Top, act>\
    \ st;\n  LCA lc;\n\n  eulerTour(vector<vector<int>> g, int root = 0) : tin(ssize(g)),\
    \ tout(ssize(g)), p(ssize(g), -1), st(ssize(g)), lc(g, root) {\n    int t = 0;\n\
    \    auto dfs = [&](int v, auto self) -> void {\n      tin[v] = t++;\n      for(int\
    \ x : g[v]) {\n        if (x == p[v]) continue;\n        p[x] = v;\n        self(x,\
    \ self);\n      }\n      tout[v] = t;\n    };\n\n    dfs(root, dfs);\n  }\n\n\
    \  //for point modify, path query, inversion of monoid is needed\n  void modify(int\
    \ v, T x) { st.modify(tin[v], tout[v], x); }\n  M query(int u, int v) {\n    int\
    \ Lca = lc.lca(u, v);\n    M res = Mop(st.get(tin[u]), st.get(tin[v]));\n    res\
    \ = Mop(res, Minv(st.get(tin[Lca])));\n    if (p[Lca] != -1)\n      res = Mop(res,\
    \ Minv(st.get(tin[p[Lca]])));\n    return res;\n  }\n};\n#line 8 \"test/vertex_add_path_sum.test.cpp\"\
    \n\nll add(const ll &a, const ll &b) { return a + b; }\nll zero() { return 0ll;\
    \ }\nll inv(const ll &x) { return -x; }\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<ll> a(n);\n  for(ll &x\
    \ : a)\n    cin >> x;\n  vector<vector<int>> g(n);\n  for(int i = 1; i < n; i++)\
    \ {\n    int u, v; cin >> u >> v;\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n\
    \  }\n\n  eulerTour<ll, zero, add, inv, ll, zero, add, add> eu(g);\n\n  for(int\
    \ v = 0; v < n; v++)\n    eu.modify(v, a[v]);\n\n  while(q--) {\n    int t, x,\
    \ y; cin >> t >> x >> y;\n    if (t == 0)\n      eu.modify(x, y);\n    else\n\
    \      cout << eu.query(x, y) << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../default/t.cpp\"\n#include \"../ds/RMQ.cpp\"\n#include \"../ds/LCA.cpp\"\
    \n#include \"../segtree/dualSegmentTree.cpp\"\n#include \"../ds/eulerTour.cpp\"\
    \n\nll add(const ll &a, const ll &b) { return a + b; }\nll zero() { return 0ll;\
    \ }\nll inv(const ll &x) { return -x; }\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<ll> a(n);\n  for(ll &x\
    \ : a)\n    cin >> x;\n  vector<vector<int>> g(n);\n  for(int i = 1; i < n; i++)\
    \ {\n    int u, v; cin >> u >> v;\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n\
    \  }\n\n  eulerTour<ll, zero, add, inv, ll, zero, add, add> eu(g);\n\n  for(int\
    \ v = 0; v < n; v++)\n    eu.modify(v, a[v]);\n\n  while(q--) {\n    int t, x,\
    \ y; cin >> t >> x >> y;\n    if (t == 0)\n      eu.modify(x, y);\n    else\n\
    \      cout << eu.query(x, y) << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - ds/RMQ.cpp
  - ds/LCA.cpp
  - segtree/dualSegmentTree.cpp
  - ds/eulerTour.cpp
  isVerificationFile: true
  path: test/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2026-01-29 02:59:39+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_add_path_sum.test.cpp
- /verify/test/vertex_add_path_sum.test.cpp.html
title: test/vertex_add_path_sum.test.cpp
---
