---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: combi/binom.cpp
    title: combi/binom.cpp
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: modint/dynamicSimpleMint.cpp
    title: modint/dynamicSimpleMint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "#line 1 \"test/binomial_coefficient_prime_mod.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\n\
    \n#line 1 \"default/t.cpp\"\n#include <algorithm>\n#include <array>\n#include\
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
    \ (-INT128_MAX - 1)\n\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
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
    \ chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"modint/dynamicSimpleMint.cpp\"\
    \ntemplate<uint32_t ver>\nstruct simpleMint {\n  using mint = simpleMint;\n  using\
    \ u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static u32 mod;\n\n  static constexpr\
    \ u32 get_mod() { return mod; }\n  static void set_mod(u32 _mod) { mod = _mod;\
    \ }\n\n  simpleMint() : a(0) {}\n  simpleMint(const int64_t &b) : a((b % mod +\
    \ mod) % mod) {}\n\n  u32 a;\n\n  mint pow(u64 k) const {\n    mint res(1), base(*this);\n\
    \    while(k) {\n      if (k & 1)\n        res *= base;\n      base *= base, k\
    \ >>= 1;\n    }\n    return res;\n  }\n\n  mint inverse() const { return (*this).pow(mod\
    \ - 2); }\n  u32 get() const { return a; }\n\n  mint& norm() {\n    a = (a >=\
    \ mod ? a - mod : a < 0 ? a + mod : a);\n    return *this;\n  }\n\n  mint& operator+=(mint\
    \ b) {\n    a += b.a;\n    return (*this).norm();\n  }\n  mint& operator-=(mint\
    \ b) {\n    a -= b.a;\n    return (*this).norm();\n  }\n  mint& operator*=(mint\
    \ b) {\n    a = (u64(a) * b.a) % mod;\n    return *this;\n  }\n  mint& operator/=(mint\
    \ b) {\n    a = (u64(a) * b.inverse().a) % mod;\n    return *this;\n  }\n\n  mint\
    \ operator-() { return mint() - mint(*this); }\n  bool operator==(mint b) { return\
    \ a == b.a; }\n  bool operator!=(mint b) { return a != b.a; }\n  \n  friend mint\
    \ operator+(mint c, mint d) { return c += d; }\n  friend mint operator-(mint c,\
    \ mint d) { return c -= d; }\n  friend mint operator*(mint c, mint d) { return\
    \ c *= d; }\n  friend mint operator/(mint c, mint d) { return c /= d; }\n\n  friend\
    \ ostream& operator<<(ostream& os, const mint& b) {\n    return os << b.a;\n \
    \ }\n  friend istream& operator>>(istream& is, mint& b) {\n    int64_t val;\n\
    \    is >> val;\n    b = mint(val);\n    return is;\n  }\n};\n\ntemplate<> uint32_t\
    \ simpleMint<0>::mod = 2;\nusing mint = simpleMint<0>;\n#line 1 \"combi/binom.cpp\"\
    \n//#include<modint/MontgomeryModInt.cpp>\n\ntemplate<class Mint>\nstruct binomial\
    \ {\n  vector<Mint> _fac, _facInv;\n  binomial(int size) : _fac(size), _facInv(size)\
    \ {\n    _fac[0] = 1;\n    for(int i = 1; i < size; i++)\n      _fac[i] = _fac[i\
    \ - 1] * i;\n    if (size > 0)\n      _facInv.back() = 1 / _fac.back();\n    for(int\
    \ i = size - 2; i >= 0; i--)\n      _facInv[i] = _facInv[i + 1] * (i + 1);\n \
    \ }\n\n  Mint fac(int i) { return i < 0 ? 0 : _fac[i]; }\n  Mint faci(int i) {\
    \ return i < 0 ? 0 : _facInv[i]; }\n  Mint inv(int i) { return _facInv[i] * _fac[i\
    \ - 1]; }\n  Mint binom(int n, int r) { return r < 0 or n < r ? 0 : fac(n) * faci(r)\
    \ * faci(n - r); }\n  Mint catalan(int i) { return binom(2 * i, i) - binom(2 *\
    \ i, i + 1); }\n  Mint excatalan(int n, int m, int k) { //(+1) * n, (-1) * m,\
    \ prefix sum > -k\n    if (k > m) return binom(n + m, m);\n    else if (k > m\
    \ - n) return binom(n + m, m) - binom(n + m, m - k);\n    else return Mint(0);\n\
    \  }\n};\n#line 6 \"test/binomial_coefficient_prime_mod.test.cpp\"\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int t, p; cin >> t >>\
    \ p;\n  mint::set_mod(p);\n  binomial<mint> bn(min(p, 10000000));\n  while(t--)\
    \ {\n    int n, k; cin >> n >> k;\n    cout << bn.binom(n, k) << '\\n';\n  }\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/dynamicSimpleMint.cpp\"\
    \n#include \"../combi/binom.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int t, p; cin >> t >> p;\n  mint::set_mod(p);\n  binomial<mint>\
    \ bn(min(p, 10000000));\n  while(t--) {\n    int n, k; cin >> n >> k;\n    cout\
    \ << bn.binom(n, k) << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/dynamicSimpleMint.cpp
  - combi/binom.cpp
  isVerificationFile: true
  path: test/binomial_coefficient_prime_mod.test.cpp
  requiredBy: []
  timestamp: '2025-01-18 19:29:37+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/binomial_coefficient_prime_mod.test.cpp
layout: document
redirect_from:
- /verify/test/binomial_coefficient_prime_mod.test.cpp
- /verify/test/binomial_coefficient_prime_mod.test.cpp.html
title: test/binomial_coefficient_prime_mod.test.cpp
---
