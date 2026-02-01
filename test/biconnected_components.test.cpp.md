---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: graph/connectivity/BCC.cpp
    title: graph/connectivity/BCC.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/biconnected_components
    links:
    - https://judge.yosupo.jp/problem/biconnected_components
  bundledCode: "#line 1 \"test/biconnected_components.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/biconnected_components\"\n\n#line 1 \"default/t.cpp\"\
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
    \ < b ? a = b, 1 : 0; }\n\n#line 1 \"graph/connectivity/BCC.cpp\"\nstruct BCC\
    \ {\n  vector<int> f, vb, eb, gv, ge, eid, vid;\n  int size = -1;\n\n  BCC(vector<array<int,\
    \ 2>> &e, int n)\n  : f(n), eid(ssize(e)), vid(n, -1) {\n\n    auto newComp =\
    \ [&]() {\n      vb.emplace_back(ssize(gv));\n      eb.emplace_back(ssize(ge));\n\
    \      size++;\n    };\n\n    vector<vector<int>> g(n);\n    for(int i = 0; auto\
    \ [u, v] : e) {\n      g[u].emplace_back(i);\n      g[v].emplace_back(i++);\n\
    \    }\n\n    int t = 0;\n    vector<int> tin(n, -1), low(n), cnt(n), s;\n   \
    \ vector<bool> vis(ssize(e), false);\n    auto dfs = [&](int v, auto &&self) ->\
    \ void {\n      tin[v] = low[v] = t++;\n      for(int i : g[v]) if (!vis[i]) {\n\
    \        int x = e[i][0] ^ e[i][1] ^ v;\n        vis[i] = true, s.emplace_back(i);\n\
    \        if (tin[x] != -1) {\n          low[v] = min(low[v], tin[x]);\n      \
    \  } else {\n          self(x, self);\n          low[v] = min(low[v], low[x]);\n\
    \          if (low[x] >= tin[v]) {\n            newComp();\n            do {\n\
    \              int j = s.back(); s.pop_back();\n              for(int u : e[j])\n\
    \                if (++cnt[u] == 1)\n                  gv.emplace_back(u);\n \
    \             eid[j] = size;\n              ge.emplace_back(j);\n            }\
    \ while(ge.back() != i);\n            for(int u : gv | views::drop(vb.back()))\n\
    \              cnt[u] = 0, f[u]++, vid[u] = size;\n          }\n        }\n  \
    \    }\n      if (g[v].empty()) newComp(), gv.emplace_back(v), vid[v] = size;\n\
    \    };\n\n    for(int v = 0; v < n; v++)\n      if (tin[v] == -1)\n        dfs(v,\
    \ dfs);\n    newComp();\n  }\n\n  vector<int> vertexGroup(int id) {\n    return\
    \ {gv.begin() + vb[id], gv.begin() + vb[id + 1]};\n  }\n  vector<int> edgeGroup(int\
    \ id) {\n    return {ge.begin() + eb[id], ge.begin() + eb[id + 1]};\n  }\n  bool\
    \ isCutVertex(int v) { return f[v] > 1; }\n  pair<vector<vector<int>>, vector<int>>\
    \ blockCutTree() {\n    int n = ssize(f);\n    vector<vector<int>> g(n + size);\n\
    \    vector<int> mp = vid;\n    for(int &x : mp) x += n;\n    for(int i = 0; i\
    \ < size; i++)\n      for(int v : vertexGroup(i))\n        if (isCutVertex(v))\
    \ {\n          g[i + n].emplace_back(v);\n          g[v].emplace_back(i + n);\n\
    \          mp[v] = v;\n        }\n    return make_pair(g, mp);\n  }\n};\n#line\
    \ 5 \"test/biconnected_components.test.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, m; cin >> n >> m;\n  vector<array<int, 2>> e(m);\n\
    \  for(auto &[u, v] : e) cin >> u >> v;\n\n  BCC bcc(e, n);\n\n  cout << bcc.size\
    \ << '\\n';\n  for(int g = 0; g < bcc.size; g++) {\n    auto gv = bcc.vertexGroup(g);\n\
    \    cout << ssize(gv);\n    for(int v : gv)\n      cout << ' ' << v;\n    cout\
    \ << '\\n';\n  }\n\n  return 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/biconnected_components\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../graph/connectivity/BCC.cpp\"\n\
    \nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, m;\
    \ cin >> n >> m;\n  vector<array<int, 2>> e(m);\n  for(auto &[u, v] : e) cin >>\
    \ u >> v;\n\n  BCC bcc(e, n);\n\n  cout << bcc.size << '\\n';\n  for(int g = 0;\
    \ g < bcc.size; g++) {\n    auto gv = bcc.vertexGroup(g);\n    cout << ssize(gv);\n\
    \    for(int v : gv)\n      cout << ' ' << v;\n    cout << '\\n';\n  }\n\n  return\
    \ 0;\n}\n\n"
  dependsOn:
  - default/t.cpp
  - graph/connectivity/BCC.cpp
  isVerificationFile: true
  path: test/biconnected_components.test.cpp
  requiredBy: []
  timestamp: '2026-01-31 03:47:42+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/biconnected_components.test.cpp
layout: document
redirect_from:
- /verify/test/biconnected_components.test.cpp
- /verify/test/biconnected_components.test.cpp.html
title: test/biconnected_components.test.cpp
---
