---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':question:'
    path: tree/tree.cpp
    title: tree/tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/lowest_common_ancestor.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\n\n#line 1 \"default/t.cpp\"\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include <cinttypes>\n\
    #include <climits>\n#include <cmath>\n#include <complex>\n#include <cstdarg>\n\
    #include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n\
    #include <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n\
    #include <initializer_list>\n#include <iomanip>\n#include <ios>\n#include <iostream>\n\
    #include <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n\
    #include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n#include\
    \ <ostream>\n#include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <streambuf>\n#include <string>\n#include <tuple>\n\
    #include <type_traits>\n#include <variant>\n#include <bit>\n#include <compare>\n\
    #include <concepts>\n#include <numbers>\n#include <ranges>\n#include <span>\n\n\
    #define INT128_MAX (__int128)(((unsigned __int128) 1 << ((sizeof(__int128) * __CHAR_BIT__)\
    \ - 1)) - 1)\n#define INT128_MIN (-INT128_MAX - 1)\n\n#define pb push_back\n#define\
    \ eb emplace_back\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
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
    \ < b ? a = b, 1 : 0; }\n\n#line 1 \"tree/tree.cpp\"\nclass tree {\n  using i32\
    \ = int32_t;\n\n  vector<i32> ord;\n\n  public:\n\n  int n, root;\n  vector<int>\
    \ p, sz, dep, jp;\n\n  void calc(vector<i32> d, vector<i32> adj) {\n    sz = vector<int>(n,\
    \ 1);\n    p = dep = jp = vector<int>(n);\n\n    ord.reserve(n - 1);\n    for(int\
    \ i = 0; i < n; i++) {\n      int v = i;\n      while(d[v] == 1) {\n        ord.emplace_back(v);\n\
    \        p[v] = adj[v], sz[p[v]] += sz[v];\n        d[v] = 0, d[p[v]]--, adj[p[v]]\
    \ ^= v;\n        v = p[v];\n      }\n    }\n\n    assert(ssize(ord) == n - 1);\n\
    \n    p[root] = jp[root] = root;\n    for(i32 v : ord | views::reverse) {\n  \
    \    dep[v] = dep[p[v]] + 1;\n      if (dep[p[v]] + dep[jp[jp[p[v]]]] == 2 * dep[jp[p[v]]])\n\
    \        jp[v] = jp[jp[p[v]]];\n      else\n        jp[v] = p[v];\n    }\n  }\n\
    \n  tree(vector<pii> e, int _root = 0) : n(size(e) + 1), root(_root) {\n    vector<i32>\
    \ d(n), adj(n);\n    for(auto [u, v] : e)\n      d[u]++, d[v]++, adj[u] ^= v,\
    \ adj[v] ^= u;\n    d[root] = 0;\n    calc(d, adj);\n  }\n\n  tree(vector<int>\
    \ pa) : n(size(pa)) {\n    root = ranges::find(pa, -1) - pa.begin();\n    vector<i32>\
    \ d(n), adj(n);\n    for(int v = 0; v < n; v++)\n      if (pa[v] != -1)\n    \
    \    d[v]++, d[pa[v]]++, adj[v] ^= pa[v], adj[pa[v]] ^= v;\n    d[root] = 0;\n\
    \    calc(d, adj);\n  }\n\n  int jump(int v, int k) {\n    k = min(k, dep[v]);\n\
    \    while(k) {\n      if (int d = dep[v] - dep[jp[v]]; d <= k)\n        v = jp[v],\
    \ k -= d;\n      else\n        v = p[v], k -= 1;\n    }\n    return v;\n  }\n\n\
    \  int lca(int u, int v) {\n    if (dep[u] < dep[v])\n      swap(u, v);\n    u\
    \ = jump(u, dep[u] - dep[v]);\n    if (u == v) return u;\n    while(p[u] != p[v])\
    \ {\n      if (jp[u] != jp[v]) u = jp[u], v = jp[v];\n      else u = p[u], v =\
    \ p[v];\n    }\n    return p[u];\n  }\n\n  int kth(int s, int t, int k) {\n  \
    \  int m = lca(s, t);\n    if (dep[s] + dep[t] - 2 * dep[m] < k)\n      return\
    \ -1;\n    else if (dep[s] - dep[m] >= k)\n      return jump(s, k);\n    else\n\
    \      return jump(t, dep[s] + dep[t] - 2 * dep[m] - k);\n  }\n\n  int dis(int\
    \ u, int v) {\n    return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n  }\n\n  int\
    \ median(int u, int v, int w) {\n    return lca(u, v) ^ lca(u, w) ^ lca(v, w);\n\
    \  }\n\n  auto centroid() {\n    array<int, 2> r = {-1, -1};\n    vector<bool>\
    \ ok(n, true);\n    for(int v = 0; v < n; v++) {\n      if (2 * (n - sz[v]) >\
    \ n)\n        ok[v] = false;\n      if (v != root and 2 * sz[v] > n)\n       \
    \ ok[p[v]] = false;\n    }\n    for(int v = 0; v < n; v++)\n      if (ok[v])\n\
    \        r[1] = v, swap(r[0], r[1]);\n    return r;\n  }\n};\n#line 5 \"test/lowest_common_ancestor.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ q; cin >> n >> q;\n  vector<int> p(n - 1);\n  for(int &x : p) cin >> x;\n  p.insert(p.begin(),\
    \ -1);\n  tree T(std::move(p));\n  while(q--) {\n    int u, v; cin >> u >> v;\n\
    \    cout << T.lca(u, v) << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../default/t.cpp\"\
    \n#include \"../tree/tree.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<int> p(n - 1);\n  for(int\
    \ &x : p) cin >> x;\n  p.insert(p.begin(), -1);\n  tree T(std::move(p));\n  while(q--)\
    \ {\n    int u, v; cin >> u >> v;\n    cout << T.lca(u, v) << '\\n';\n  }\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - tree/tree.cpp
  isVerificationFile: true
  path: test/lowest_common_ancestor.test.cpp
  requiredBy: []
  timestamp: '2026-01-31 20:47:40+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/lowest_common_ancestor.test.cpp
layout: document
redirect_from:
- /verify/test/lowest_common_ancestor.test.cpp
- /verify/test/lowest_common_ancestor.test.cpp.html
title: test/lowest_common_ancestor.test.cpp
---
