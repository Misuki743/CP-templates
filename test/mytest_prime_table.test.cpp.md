---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: numtheory/prime_table.cpp
    title: numtheory/prime_table.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest_prime_table.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n#line 1 \"default/t.cpp\"\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cctype>\n#include <cfenv>\n#include\
    \ <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include <climits>\n#include\
    \ <cmath>\n#include <complex>\n#include <cstdarg>\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <initializer_list>\n\
    #include <iomanip>\n#include <ios>\n#include <iostream>\n#include <istream>\n\
    #include <iterator>\n#include <limits>\n#include <list>\n#include <map>\n#include\
    \ <memory>\n#include <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n\
    #include <random>\n#include <set>\n#include <sstream>\n#include <stack>\n#include\
    \ <streambuf>\n#include <string>\n#include <tuple>\n#include <type_traits>\n#include\
    \ <variant>\n#include <bit>\n#include <compare>\n#include <concepts>\n#include\
    \ <numbers>\n#include <ranges>\n#include <span>\n\n#define INT128_MAX (__int128)(((unsigned\
    \ __int128) 1 << ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN\
    \ (-INT128_MAX - 1)\n\n#define pb push_back\n#define eb emplace_back\n#define\
    \ clock chrono::steady_clock::now().time_since_epoch().count()\n\nusing namespace\
    \ std;\n\ntemplate<size_t I = 0, typename... args>\nostream& print_tuple(ostream&\
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
    \ < b ? a = b, 1 : 0; }\n\n#line 1 \"numtheory/prime_table.cpp\"\ntemplate<int32_t\
    \ C>\nclass prime_table {\n  static constexpr int32_t D = (C + 29) / 30 * 30;\n\
    \  bitset<D / 2> table = {};\n\n  public:\n\n  vi prime;\n\n  prime_table() :\
    \ prime({2, 3, 5}) {\n    table[3 / 2] = table[5 / 2] = true;\n    for(int i =\
    \ 0; i < D; i += 30) {\n      table[(i + 01) / 2] = table[(i + 07) / 2] =\n  \
    \    table[(i + 11) / 2] = table[(i + 13) / 2] =\n      table[(i + 17) / 2] =\
    \ table[(i + 19) / 2] =\n      table[(i + 23) / 2] = table[(i + 29) / 2] = true;\n\
    \    }\n    table[1 / 2] = false;\n\n    const int32_t S = sqrtl(D) + 10;\n  \
    \  for(int i = 7, j = 4; i < S; i += j, j ^= 6) {\n      if (table[i / 2]) {\n\
    \        for(int k = ((i + 4) / 6 * 6 + 1) * i; k < D; k += 6 * i)\n         \
    \ table[k / 2] = false;\n        for(int k = (i / 6 * 6 + 5) * i; k < D; k +=\
    \ 6 * i)\n          table[k / 2] = false;\n      }\n    }\n\n    prime.reserve(1.1\
    \ * D / log(D));\n    for(int i = 0; i < D; i += 30) {\n      if (table[(i + 01)\
    \ / 2]) prime.emplace_back(i + 01);\n      if (table[(i + 07) / 2]) prime.emplace_back(i\
    \ + 07);\n      if (table[(i + 11) / 2]) prime.emplace_back(i + 11);\n      if\
    \ (table[(i + 13) / 2]) prime.emplace_back(i + 13);\n      if (table[(i + 17)\
    \ / 2]) prime.emplace_back(i + 17);\n      if (table[(i + 19) / 2]) prime.emplace_back(i\
    \ + 19);\n      if (table[(i + 23) / 2]) prime.emplace_back(i + 23);\n      if\
    \ (table[(i + 29) / 2]) prime.emplace_back(i + 29);\n    }\n\n    int n = ssize(prime)\
    \ - 1;\n    while(n >= 0 and prime[n] >= C) n--;\n    prime.resize(n + 1);\n \
    \ }\n\n  bool is_prime(int x) { return x == 2 or ((x & 1) and table[x / 2]); }\n\
    \  //make sure to not copy the array by using &x = prime_array()\n  const vi&\
    \ prime_array() { return prime; }\n};\n#line 5 \"test/mytest_prime_table.test.cpp\"\
    \n\nvoid a_plus_b() {\n  int a, b; cin >> a >> b;\n  cout << a + b << '\\n';\n\
    }\n\ntemplate<int32_t N = 70>\nvoid check_small() {\n  if (N == 0) return;\n \
    \ {\n    prime_table<N> pt;\n\n    auto is_prime = [&](int x) {\n      if (x ==\
    \ 0 or x == 1) return false;\n      for(int i = 2; i < x; i++)\n        if (x\
    \ % i == 0)\n          return false;\n      return true;\n    };\n\n    vi primes;\n\
    \    for(int i = 0; i < N; i++) {\n      assert(pt.is_prime(i) == is_prime(i));\n\
    \      if (pt.is_prime(i))\n        primes.emplace_back(i);\n    }\n    assert(pt.prime_array()\
    \ == primes);\n  }\n  check_small<max(N - 1, 0)>();\n}\n\nbitset<(1 << 22)> is_prime\
    \ = {};\ntemplate<int32_t N = (1 << 22)>\nvoid check_power() {\n  if (N == 1)\
    \ return;\n  {\n    prime_table<N> pt;\n\n    vi primes;\n    for(int i = 0; i\
    \ < N; i++) {\n      assert(pt.is_prime(i) == is_prime[i]);\n      if (pt.is_prime(i))\n\
    \        primes.emplace_back(i);\n    }\n    assert(pt.prime_array() == primes);\n\
    \  }\n  check_power<max(N >> 1, 1)>();\n}\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  check_small();\n\n  is_prime.set();\n  is_prime[0] = is_prime[1]\
    \ = false;\n  for(int i = 2; i < (1 << 22); i++)\n    if (is_prime[i])\n     \
    \ for(int j = 2 * i; j < (1 << 22); j += i)\n        is_prime[j] = false;\n  check_power();\n\
    \n  a_plus_b();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../default/t.cpp\"\n#include \"../numtheory/prime_table.cpp\"\n\nvoid a_plus_b()\
    \ {\n  int a, b; cin >> a >> b;\n  cout << a + b << '\\n';\n}\n\ntemplate<int32_t\
    \ N = 70>\nvoid check_small() {\n  if (N == 0) return;\n  {\n    prime_table<N>\
    \ pt;\n\n    auto is_prime = [&](int x) {\n      if (x == 0 or x == 1) return\
    \ false;\n      for(int i = 2; i < x; i++)\n        if (x % i == 0)\n        \
    \  return false;\n      return true;\n    };\n\n    vi primes;\n    for(int i\
    \ = 0; i < N; i++) {\n      assert(pt.is_prime(i) == is_prime(i));\n      if (pt.is_prime(i))\n\
    \        primes.emplace_back(i);\n    }\n    assert(pt.prime_array() == primes);\n\
    \  }\n  check_small<max(N - 1, 0)>();\n}\n\nbitset<(1 << 22)> is_prime = {};\n\
    template<int32_t N = (1 << 22)>\nvoid check_power() {\n  if (N == 1) return;\n\
    \  {\n    prime_table<N> pt;\n\n    vi primes;\n    for(int i = 0; i < N; i++)\
    \ {\n      assert(pt.is_prime(i) == is_prime[i]);\n      if (pt.is_prime(i))\n\
    \        primes.emplace_back(i);\n    }\n    assert(pt.prime_array() == primes);\n\
    \  }\n  check_power<max(N >> 1, 1)>();\n}\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  check_small();\n\n  is_prime.set();\n  is_prime[0] = is_prime[1]\
    \ = false;\n  for(int i = 2; i < (1 << 22); i++)\n    if (is_prime[i])\n     \
    \ for(int j = 2 * i; j < (1 << 22); j += i)\n        is_prime[j] = false;\n  check_power();\n\
    \n  a_plus_b();\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - numtheory/prime_table.cpp
  isVerificationFile: true
  path: test/mytest_prime_table.test.cpp
  requiredBy: []
  timestamp: '2026-02-01 21:09:59+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest_prime_table.test.cpp
layout: document
redirect_from:
- /verify/test/mytest_prime_table.test.cpp
- /verify/test/mytest_prime_table.test.cpp.html
title: test/mytest_prime_table.test.cpp
---
