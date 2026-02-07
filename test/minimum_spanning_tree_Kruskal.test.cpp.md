---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/DSU/DSU.cpp
    title: ds/DSU/DSU.cpp
  - icon: ':heavy_check_mark:'
    path: graph/minimum_spanning_tree/Kruskal.cpp
    title: graph/minimum_spanning_tree/Kruskal.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/minimum_spanning_tree
    links:
    - https://judge.yosupo.jp/problem/minimum_spanning_tree
  bundledCode: "#line 1 \"test/minimum_spanning_tree_Kruskal.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/minimum_spanning_tree\"\n\n#line 1 \"default/t.cpp\"\
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
    \ < b ? a = b, 1 : 0; }\n\n#line 1 \"ds/DSU/DSU.cpp\"\ntemplate<class T = int,\
    \ typename F = void*>\nstruct DSU {\n  vi sz_par;\n  vc<T> data;\n  F op;\n\n\
    \  DSU(int n) requires same_as<F, void*> : sz_par(n, -1), op(nullptr) {}\n\n \
    \ DSU(vc<T> init, F f) requires invocable<F, T&, T&> &&\n    (!invocable<F, T,\
    \ T&>) && (!invocable<F, T&, T>)\n    : sz_par(std::size(init), -1), data(std::move(init)),\
    \ op(f) {}\n\n  int query(int v) {\n    int r = v;\n    while(sz_par[r] >= 0)\
    \ r = sz_par[r];\n    while(v != r) {\n      int nxt = sz_par[v];\n      sz_par[v]\
    \ = r, v = nxt;\n    }\n    return r;\n  }\n\n  bool merge(int v1, int v2) {\n\
    \    int b1 = query(v1), b2 = query(v2);\n\n    if (b1 == b2)\n      return false;\n\
    \n    if (-sz_par[b1] > -sz_par[b2])\n      swap(b1, b2);\n\n    sz_par[b2] +=\
    \ sz_par[b1];\n    sz_par[b1] = b2;\n    if constexpr (!same_as<F, void*>)\n \
    \     op(data[b2], data[b1]);\n\n    return true;\n  }\n\n  int size(int v) {\
    \ return v = query(v), -sz_par[v]; }\n  const T& get(int v) requires (!same_as<F,\
    \ void*>) {\n    return data[query(v)];\n  }\n};\n#line 1 \"graph/minimum_spanning_tree/Kruskal.cpp\"\
    \n//#include \"ds/DSU/DSU.cpp\"\n\ntemplate<bool sorted = false, integral T>\n\
    auto Kruskal(int n, vector<tuple<int, int, T>> &e) {\n  vi ord;\n  if constexpr\
    \ (sorted) {\n    ord.resize(n);\n    iota(ord.begin(), ord.end(), 0ll);\n  }\
    \ else {\n    ord = argSort(e, [](tuple<int, int, T> &t) { return get<2>(t); });\n\
    \  }\n\n  T cost = 0;\n  vi eid;\n  DSU dsu(n);\n  for(int i : ord) {\n    auto\
    \ [u, v, w] = e[i];\n    if (dsu.merge(u, v))\n      cost += w, eid.emplace_back(i);\n\
    \  }\n\n  return pair(cost, eid);\n}\n#line 6 \"test/minimum_spanning_tree_Kruskal.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ m; cin >> n >> m;\n  vector<tuple<int, int, ll>> e(m);\n  for(auto &[u, v, w]\
    \ : e)\n    cin >> u >> v >> w;\n\n  auto [cost, eid] = Kruskal(n, e);\n  cout\
    \ << cost << '\\n';\n  cout << eid << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/minimum_spanning_tree\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../ds/DSU/DSU.cpp\"\n#include \"\
    ../graph/minimum_spanning_tree/Kruskal.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, m; cin >> n >> m;\n  vector<tuple<int, int, ll>>\
    \ e(m);\n  for(auto &[u, v, w] : e)\n    cin >> u >> v >> w;\n\n  auto [cost,\
    \ eid] = Kruskal(n, e);\n  cout << cost << '\\n';\n  cout << eid << '\\n';\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - ds/DSU/DSU.cpp
  - graph/minimum_spanning_tree/Kruskal.cpp
  isVerificationFile: true
  path: test/minimum_spanning_tree_Kruskal.test.cpp
  requiredBy: []
  timestamp: '2026-01-31 20:47:40+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/minimum_spanning_tree_Kruskal.test.cpp
layout: document
redirect_from:
- /verify/test/minimum_spanning_tree_Kruskal.test.cpp
- /verify/test/minimum_spanning_tree_Kruskal.test.cpp.html
title: test/minimum_spanning_tree_Kruskal.test.cpp
---
