---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':x:'
    path: ds/fast_set.cpp
    title: ds/fast_set.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"test/predecessor_problem.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/predecessor_problem\"\n\n#line 1 \"default/t.cpp\"\
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
    \ < b ? a = b, 1 : 0; }\n\n#line 1 \"ds/fast_set.cpp\"\nstruct fast_set {\n  using\
    \ u64 = uint64_t;\n  using i64 = int64_t;\n  static constexpr u64 B = 64;\n  i64\
    \ sz;\n  vector<vector<u64>> data;\n\n  fast_set(u64 _sz) : sz(_sz) {\n    do\
    \ {\n      data.push_back(vector<u64>(ceilDiv(_sz, B)));\n      _sz = ceilDiv(_sz,\
    \ B);\n    } while(_sz > 1);\n  }\n\n  fast_set(string s) : sz(ssize(s)) {\n \
    \   u64 _sz = sz;\n    data.push_back(vector<u64>(ceilDiv(_sz, B)));\n    for(i64\
    \ i = 0; i < ssize(s); i++)\n      data[0][i / B] |= u64(s[i] - '0') << (i % B);\n\
    \    _sz = ceilDiv(_sz, B);\n    while(_sz > 1) {\n      data.push_back(vector<u64>(ceilDiv(_sz,\
    \ B)));\n      for(u64 i = 0; i < _sz; i++)\n        data.back()[i / B] |= u64(!!end(data)[-2][i])\
    \ << (i % B);\n      _sz = ceilDiv(_sz, B);\n    }\n  }\n\n  bool contains(i64\
    \ x) {\n    return x < sz and (data[0][x / B] >> (x % B) & 1);\n  }\n\n  void\
    \ insert(i64 x) {\n    if (contains(x)) return;\n    assert(x < sz);\n    for(auto\
    \ &v : data)\n      v[x / B] |= u64(1) << (x % B), x /= B;\n  }\n\n  void erase(i64\
    \ x) {\n    if (x >= sz or !contains(x)) return;\n    u64 pre = !(data[0][x /\
    \ B] &= (-u64(1)) ^ (u64(1) << (x % B)));\n    for(auto &v : data | views::drop(1))\n\
    \      x /= B, pre = !(v[x / B] ^= u64(pre) << (x % B));\n  }\n\n  i64 geq(i64\
    \ x) {\n    if (x >= sz) return sz;\n    chmax(x, i64(0));\n    for(i64 i = 0;\
    \ i < ssize(data) and x / (i64)B < ssize(data[i]); i++, x = x / (i64)B + 1) {\n\
    \      if (data[i][x / B] >> (x % B)) {\n        i64 y = x;\n        for(i64 j\
    \ = i; j >= 0; j--)\n          y = (y + countr_zero(data[j][y / B] >> (y % B)))\
    \ * B;\n        return y / B;\n      }\n    }\n    return sz;\n  }\n\n  i64 leq(i64\
    \ x) {\n    if (x < 0) return -1;\n    chmin(x, sz - 1);\n    for(i64 i = 0; i\
    \ < ssize(data) and x >= 0; i++, x = x / (i64)B - 1) {\n      if (data[i][x /\
    \ B] << (B - 1 - x % B)) {\n        i64 y = x;\n        for(i64 j = i; j >= 0;\
    \ j--)\n          y = (y - countl_zero(data[j][y / B] << (B - 1 - y % B))) * B\
    \ + (B - 1);\n        return y / B;\n      }\n    }\n    return -1;\n  }\n};\n\
    #line 5 \"test/predecessor_problem.test.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  string t; cin >> t;\n  fast_set\
    \ s(t);\n  while(q--) {\n    int c, k; cin >> c >> k;\n    if (c == 0) s.insert(k);\n\
    \    if (c == 1) s.erase(k);\n    if (c == 2) cout << s.contains(k) << '\\n';\n\
    \    if (c == 3) {\n      int x = s.geq(k);\n      cout << (x == n ? -1 : x) <<\
    \ '\\n';\n    }\n    if (c == 4) cout << s.leq(k) << '\\n';\n  }\n\n  return 0;\n\
    }\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    \n#include \"../default/t.cpp\"\n#include \"../ds/fast_set.cpp\"\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin >> n >>\
    \ q;\n  string t; cin >> t;\n  fast_set s(t);\n  while(q--) {\n    int c, k; cin\
    \ >> c >> k;\n    if (c == 0) s.insert(k);\n    if (c == 1) s.erase(k);\n    if\
    \ (c == 2) cout << s.contains(k) << '\\n';\n    if (c == 3) {\n      int x = s.geq(k);\n\
    \      cout << (x == n ? -1 : x) << '\\n';\n    }\n    if (c == 4) cout << s.leq(k)\
    \ << '\\n';\n  }\n\n  return 0;\n}\n\n"
  dependsOn:
  - default/t.cpp
  - ds/fast_set.cpp
  isVerificationFile: true
  path: test/predecessor_problem.test.cpp
  requiredBy: []
  timestamp: '2026-01-31 03:10:37+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/predecessor_problem.test.cpp
layout: document
redirect_from:
- /verify/test/predecessor_problem.test.cpp
- /verify/test/predecessor_problem.test.cpp.html
title: test/predecessor_problem.test.cpp
---
