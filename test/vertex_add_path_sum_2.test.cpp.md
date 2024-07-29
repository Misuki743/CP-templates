---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/STT_pathAggregate.cpp
    title: ds/STT_pathAggregate.cpp
  - icon: ':heavy_check_mark:'
    path: ds/staticTopTree2.cpp
    title: ds/staticTopTree2.cpp
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
  bundledCode: "#line 1 \"test/vertex_add_path_sum_2.test.cpp\"\n#define PROBLEM \"\
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
    \ clock chrono::steady_clock::now().time_since_epoch().count()\n\nusing namespace\
    \ std;\n\ntemplate<class T1, class T2>\nostream& operator<<(ostream& os, const\
    \ pair<T1, T2> pr) {\n  return os << pr.first << ' ' << pr.second;\n}\ntemplate<class\
    \ T, size_t N>\nostream& operator<<(ostream& os, const array<T, N> &arr) {\n \
    \ for(size_t i = 0; T x : arr) {\n    os << x;\n    if (++i != N) os << ' ';\n\
    \  }\n  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const\
    \ vector<T> &vec) {\n  for(size_t i = 0; T x : vec) {\n    os << x;\n    if (++i\
    \ != size(vec)) os << ' ';\n  }\n  return os;\n}\ntemplate<class T>\nostream&\
    \ operator<<(ostream& os, const set<T> &s) {\n  for(size_t i = 0; T x : s) {\n\
    \    os << x;\n    if (++i != size(s)) os << ' ';\n  }\n  return os;\n}\ntemplate<class\
    \ T1, class T2>\nostream& operator<<(ostream& os, const map<T1, T2> &m) {\n  for(size_t\
    \ i = 0; pair<T1, T2> x : m) {\n    os << x;\n    if (++i != size(m)) os << '\
    \ ';\n  }\n  return os;\n}\n\n#ifdef DEBUG\n#define dbg(...) cerr << '(', _do(#__VA_ARGS__),\
    \ cerr << \") = \", _do2(__VA_ARGS__)\ntemplate<typename T> void _do(T &&x) {\
    \ cerr << x; }\ntemplate<typename T, typename ...S> void _do(T &&x, S&&...y) {\
    \ cerr << x << \", \"; _do(y...); }\ntemplate<typename T> void _do2(T &&x) { cerr\
    \ << x << endl; }\ntemplate<typename T, typename ...S> void _do2(T &&x, S&&...y)\
    \ { cerr << x << \", \"; _do2(y...); }\n#else\n#define dbg(...)\n#endif\n\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing ldb = long double;\n\
    using pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate<typename T>\
    \ using min_heap = priority_queue<T, vector<T>, greater<T>>;\ntemplate<typename\
    \ T> using max_heap = priority_queue<T>;\n\ntemplate<ranges::forward_range rng,\
    \ class T = ranges::range_value_t<rng>, class OP = plus<T>>\nvoid pSum(rng &v)\
    \ {\n  if (!v.empty())\n    for(T p = v[0]; T &x : v | views::drop(1))\n     \
    \ x = p = OP()(p, x);\n}\ntemplate<ranges::forward_range rng, class T = ranges::range_value_t<rng>,\
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
    \ chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"ds/staticTopTree2.cpp\"\
    \nstruct staticTopTree {\n  enum type { AddVertex, Rake, Compress };\n\n  vector<vector<int>>\
    \ g;\n  int n, nxt;\n  vector<int> lc, rc, p, vt, mp;\n\n  staticTopTree(vector<vector<int>>\
    \ _g) : g(_g), n(size(g)), nxt(0),\n  lc(3 * n, -1), rc(3 * n, -1), p(3 * n, -1),\
    \ vt(3 * n), mp(n) {\n    dfs(0, -1);\n    compress(0);\n  }\n\n  int dfs(int\
    \ v, int p) {\n    int sz = 1, mx = 0;\n    for(int &x : g[v]) {\n      if (x\
    \ == p) swap(x, g[v].back());\n      if (x == p) continue;\n      int c = dfs(x,\
    \ v);\n      sz += c;\n      if (chmax(mx, c)) swap(x, g[v][0]);\n    }\n    if\
    \ (!g[v].empty() and g[v].back() == p) g[v].pop_back();\n    return sz;\n  }\n\
    \n  void allocate(int v, int l, int r, type t) {\n    if (l != -1) p[l] = v, lc[v]\
    \ = l;\n    if (r != -1) p[r] = v, rc[v] = r;\n    vt[v] = t;\n  }\n\n  pii merge(vector<pii>\
    \ &vs, type t) {\n    if (size(vs) == 1) return vs[0];\n    int szSum = 0, i =\
    \ 0, pre = 0;\n    for(auto [_, sz] : vs) szSum += sz;\n    while(i + 1 < ssize(vs)\
    \ and 2 * pre <= szSum) pre += vs[i++].second;\n    vector lv(vs.begin(), vs.begin()\
    \ + i), rv(vs.begin() + i, vs.end());\n    auto [l, lsz] = merge(lv, t);\n   \
    \ auto [r, rsz] = merge(rv, t);\n    allocate(nxt, l, r, t);\n    return {nxt++,\
    \ lsz + rsz + 1};\n  }\n\n  pii compress(int v) {\n    vector vs(1, addVertex(v));\n\
    \    while(!g[v].empty())\n      vs.emplace_back(addVertex(v = g[v][0]));\n  \
    \  return merge(vs, type::Compress);\n  }\n\n  pii addVertex(int v) {\n    auto\
    \ [l, lsz] = rake(v);\n    allocate(nxt, l, -1, type::AddVertex);\n    mp[v] =\
    \ nxt;\n    return {nxt++, lsz + 1};\n  }\n\n  pii rake(int v) {\n    if (ssize(g[v])\
    \ <= 1) return {-1, 0};\n    vector<pii> vs;\n    for(int x : g[v] | views::drop(1))\n\
    \      vs.emplace_back(compress(x));\n    return merge(vs, type::Rake);\n  }\n\
    };\n#line 1 \"ds/STT_pathAggregate.cpp\"\n//#include \"ds/staticTopTree2.cpp\"\
    \n\ntemplate<class M, M(*id)(), M(*op)(const M&, const M&)>\nstruct STT_pathAggregate\
    \ : staticTopTree {\n  vector<M> data;\n  vector<int> dep, head;\n\n  STT_pathAggregate(vector<vector<int>>\
    \ g, vector<M> init = vector<M>())\n  : staticTopTree(g), data(nxt, id()), dep(nxt),\
    \ head(nxt) {\n    head[nxt - 1] = nxt - 1;\n    dfs(nxt - 1);\n    if (!init.empty())\
    \ {\n      for(int v = 0; v < n; v++)\n        data[mp[v]] = init[v];\n      for(int\
    \ v = 0; v < nxt; v++)\n        if (vt[v] == type::Compress)\n          recalc(v);\n\
    \    }\n  }\n\n  void dfs(int v) {\n    if (lc[v] != -1) {\n      dep[lc[v]] =\
    \ dep[v] + 1;\n      head[lc[v]] = vt[v] == type::AddVertex or (vt[v] == type::Rake\
    \ and vt[lc[v]] != type::Rake) ? lc[v] : head[v];\n      dfs(lc[v]);\n    }\n\
    \    if (rc[v] != -1) {\n      dep[rc[v]] = dep[v] + 1;\n      head[rc[v]] = vt[v]\
    \ == type::AddVertex or (vt[v] == type::Rake and vt[rc[v]] != type::Rake) ? rc[v]\
    \ : head[v];\n      dfs(rc[v]);\n    }\n  }\n\n  void recalc(int v) {\n    if\
    \ (rc[v] != -1) data[v] = op(data[lc[v]], data[rc[v]]);\n    else if (lc[v] !=\
    \ -1) data[v] = op(data[lc[v]], data[v]);\n  }\n\n  void pull(int v) {\n    v\
    \ = p[v];\n    while(v != -1 and vt[v] == type::Compress) {\n      data[v] = op(data[lc[v]],\
    \ data[rc[v]]);\n      v = p[v];\n    }\n  }\n\n  void set(int v, M x) { data[mp[v]]\
    \ = x, pull(mp[v]); }\n\n  M levelAggregate(int v) {\n    int x = head[v];\n \
    \   M ret = data[v];\n    while(v != x) {\n      int w = p[v];\n      if (vt[w]\
    \ == type::Compress and rc[w] == v)\n        ret = op(ret, data[lc[w]]);\n   \
    \   v = w;\n    }\n    return ret;\n  }\n\n  M query(int u, int v) {\n    u =\
    \ mp[u], v = mp[v];\n    M ret = id();\n    while(head[u] != head[v]) {\n    \
    \  if (dep[head[u]] > dep[head[v]])\n        ret = op(ret, levelAggregate(u)),\
    \ u = p[head[u]];\n      else\n        ret = op(ret, levelAggregate(v)), v = p[head[v]];\n\
    \    }\n    if (vt[head[u]] == type::Rake) return op(ret, data[p[head[u]]]);\n\
    \    if (u == v) return op(ret, data[u]);\n    if (u > v) swap(u, v);\n    ret\
    \ = op(ret, op(data[u], data[v]));\n    while(p[u] != p[v]) {\n      if (dep[u]\
    \ > dep[v]) {\n        int w = p[u];\n        if (lc[w] == u and rc[w] != -1)\n\
    \          ret = op(ret, data[rc[w]]);\n        u = w;\n      } else {\n     \
    \   int w = p[v];\n        if (rc[w] == v)\n          ret = op(ret, data[lc[w]]);\n\
    \        v = w;\n      }\n    }\n    return ret;\n  }\n};\n#line 6 \"test/vertex_add_path_sum_2.test.cpp\"\
    \n\nll id() { return 0ll; }\nll op(const ll &a, const ll &b) { return a + b; }\n\
    \nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q;\
    \ cin >> n >> q;\n  vector<ll> a(n);\n  for(ll &x : a) cin >> x;\n  auto g = readGraph<false>(n,\
    \ n - 1, 0);\n\n  STT_pathAggregate<ll, id, op> stt(g, a);\n\n  while(q--) {\n\
    \    int op; cin >> op;\n    if (op == 0) {\n      int p, x; cin >> p >> x;\n\
    \      stt.set(p, a[p] += x);\n    } else {\n      int u, v; cin >> u >> v;\n\
    \      cout << stt.query(u, v) << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../default/t.cpp\"\n#include \"../ds/staticTopTree2.cpp\"\n#include\
    \ \"../ds/STT_pathAggregate.cpp\"\n\nll id() { return 0ll; }\nll op(const ll &a,\
    \ const ll &b) { return a + b; }\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<ll> a(n);\n  for(ll &x\
    \ : a) cin >> x;\n  auto g = readGraph<false>(n, n - 1, 0);\n\n  STT_pathAggregate<ll,\
    \ id, op> stt(g, a);\n\n  while(q--) {\n    int op; cin >> op;\n    if (op ==\
    \ 0) {\n      int p, x; cin >> p >> x;\n      stt.set(p, a[p] += x);\n    } else\
    \ {\n      int u, v; cin >> u >> v;\n      cout << stt.query(u, v) << '\\n';\n\
    \    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - ds/staticTopTree2.cpp
  - ds/STT_pathAggregate.cpp
  isVerificationFile: true
  path: test/vertex_add_path_sum_2.test.cpp
  requiredBy: []
  timestamp: '2024-07-30 00:39:06+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/vertex_add_path_sum_2.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_add_path_sum_2.test.cpp
- /verify/test/vertex_add_path_sum_2.test.cpp.html
title: test/vertex_add_path_sum_2.test.cpp
---
