---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':x:'
    path: graph/steinerTree.cpp
    title: graph/steinerTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/minimum_steiner_tree
    links:
    - https://judge.yosupo.jp/problem/minimum_steiner_tree
  bundledCode: "#line 1 \"test/minimum_steiner_tree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/minimum_steiner_tree\"\n\n#line 1 \"default/t.cpp\"\
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
    \ 1 \"graph/steinerTree.cpp\"\ntemplate<class T>\npair<T, vector<int>> steiner_tree(int\
    \ n, vector<int> s, vector<tuple<int, int, T>> e) {\n  int k = 0;\n  {\n    vector<bool>\
    \ in_s(n, false);\n    for(int x : s) in_s[x] = true;\n    for(int v = 0; v <\
    \ n; v++) k += in_s[v];\n    vector<int> f(n);\n    int nxt = 0;\n    for(bool\
    \ x : {true, false})\n      for(int v = 0; v < n; v++)\n        if (in_s[v] ==\
    \ x)\n          f[v] = nxt++;\n    for(auto &[u, v, _] : e)\n      u = f[u], v\
    \ = f[v];\n  }\n\n  vector<vector<tuple<int, int, T>>> g(n);\n  for(int i = 0;\
    \ auto [u, v, w] : e) {\n    g[u].emplace_back(v, i, w);\n    g[v].emplace_back(u,\
    \ i++, w);\n  }\n\n  vector dp(1 << k, vector<T>(n, numeric_limits<T>::max()));\n\
    \  vector pre(1 << k, vector<array<int, 2>>(n, {-1, -1}));\n\n  for(unsigned x\
    \ = 1; x < (1 << k); x++) {\n    if (popcount(x) == 1) {\n      dp[x][countr_zero(x)]\
    \ = 0;\n    } else {\n      for(int r = 0; r < n; r++)\n        for(int y = (x\
    \ - 1) & x; y > 0; y = (y - 1) & x)\n          if (T tmp = dp[y][r] + dp[x^y][r];\
    \ tmp < dp[x][r])\n            dp[x][r] = tmp, pre[x][r] = {y, -1};\n    }\n \
    \   priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>>\
    \ pq;\n    for(int r = 0; r < n; r++)\n      pq.emplace(dp[x][r], r);\n    while(!pq.empty())\
    \ {\n      auto [d, v] = pq.top(); pq.pop();\n      if (d != dp[x][v]) continue;\n\
    \      for(auto [to, i, w] : g[v]) {\n        if (d + w < dp[x][to]) {\n     \
    \     dp[x][to] = d + w, pre[x][to] = {v, i};\n          pq.emplace(d + w, to);\n\
    \        }\n      }\n    }\n  }\n\n  vector<bool> in_t(size(e));\n  auto dfs =\
    \ [&](int x, int r, auto &&self) -> void {\n    auto [a, b] = pre[x][r];\n   \
    \ if (a == -1) return;\n    if (b == -1) {\n      self(a, r, self);\n      self(x\
    \ ^ a, r, self);\n    } else {\n      in_t[b] = true;\n      self(x, a, self);\n\
    \    }\n  };\n\n  int r = ranges::min_element(dp.back()) - dp.back().begin();\n\
    \  dfs((1 << k) - 1, r, dfs);\n\n  vector<int> t;\n  for(int i = 0; i < ssize(e);\
    \ i++)\n    if (in_t[i])\n      t.emplace_back(i);\n\n  return make_pair(dp.back()[r],\
    \ t);\n}\n#line 5 \"test/minimum_steiner_tree.test.cpp\"\n\nsigned main() {\n\
    \  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, m; cin >> n >> m;\n\
    \  vector<tuple<int, int, ll>> e(m);\n  for(auto &[u, v, w] : e) cin >> u >> v\
    \ >> w;\n  int k; cin >> k;\n  vector<int> s(k);\n  for(int &x : s) cin >> x;\n\
    \n  auto [cost, t] = steiner_tree(n, s, e);\n  cout << cost << ' ' << ssize(t)\
    \ << '\\n';\n  cout << t << '\\n';\n\n  return 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/minimum_steiner_tree\"\n\
    \n#include \"../default/t.cpp\"\n#include \"../graph/steinerTree.cpp\"\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, m; cin >>\
    \ n >> m;\n  vector<tuple<int, int, ll>> e(m);\n  for(auto &[u, v, w] : e) cin\
    \ >> u >> v >> w;\n  int k; cin >> k;\n  vector<int> s(k);\n  for(int &x : s)\
    \ cin >> x;\n\n  auto [cost, t] = steiner_tree(n, s, e);\n  cout << cost << '\
    \ ' << ssize(t) << '\\n';\n  cout << t << '\\n';\n\n  return 0;\n}\n\n"
  dependsOn:
  - default/t.cpp
  - graph/steinerTree.cpp
  isVerificationFile: true
  path: test/minimum_steiner_tree.test.cpp
  requiredBy: []
  timestamp: '2026-01-30 02:53:01+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/minimum_steiner_tree.test.cpp
layout: document
redirect_from:
- /verify/test/minimum_steiner_tree.test.cpp
- /verify/test/minimum_steiner_tree.test.cpp.html
title: test/minimum_steiner_tree.test.cpp
---
