---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: combi/binom.cpp
    title: combi/binom.cpp
  - icon: ':heavy_check_mark:'
    path: combi/countEulerianCircuit.cpp
    title: combi/countEulerianCircuit.cpp
  - icon: ':heavy_check_mark:'
    path: combi/countSpanningForest.cpp
    title: combi/countSpanningForest.cpp
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':question:'
    path: linalg/matrixMint.cpp
    title: linalg/matrixMint.cpp
  - icon: ':question:'
    path: modint/MontgomeryModInt.cpp
    title: modint/MontgomeryModInt.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/counting_eulerian_circuits
    links:
    - https://judge.yosupo.jp/problem/counting_eulerian_circuits
  bundledCode: "#line 1 \"test/counting_eulerian_circuits.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/counting_eulerian_circuits\"\n\n#line 1 \"\
    default/t.cpp\"\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include\
    \ <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include\
    \ <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include <deque>\n#include\
    \ <fstream>\n#include <functional>\n#include <initializer_list>\n#include <iomanip>\n\
    #include <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n\
    #include <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include\
    \ <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <sstream>\n#include <stack>\n#include <streambuf>\n#include\
    \ <string>\n#include <tuple>\n#include <type_traits>\n#include <variant>\n#include\
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
    \ chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"modint/MontgomeryModInt.cpp\"\
    \n//reference: https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10\n\
    //note: mod should be a prime less than 2^30.\n\ntemplate<uint32_t mod>\nstruct\
    \ MontgomeryModInt {\n  using mint = MontgomeryModInt;\n  using i32 = int32_t;\n\
    \  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static constexpr u32 get_r()\
    \ {\n    u32 res = 1, base = mod;\n    for(i32 i = 0; i < 31; i++)\n      res\
    \ *= base, base *= base;\n    return -res;\n  }\n\n  static constexpr u32 get_mod()\
    \ {\n    return mod;\n  }\n\n  static constexpr u32 n2 = -u64(mod) % mod; //2^64\
    \ % mod\n  static constexpr u32 r = get_r(); //-P^{-1} % 2^32\n\n  u32 a;\n\n\
    \  static u32 reduce(const u64 &b) {\n    return (b + u64(u32(b) * r) * mod) >>\
    \ 32;\n  }\n\n  static u32 transform(const u64 &b) {\n    return reduce(u64(b)\
    \ * n2);\n  }\n\n  MontgomeryModInt() : a(0) {}\n  MontgomeryModInt(const int64_t\
    \ &b) \n    : a(transform(b % mod + mod)) {}\n\n  mint pow(u64 k) const {\n  \
    \  mint res(1), base(*this);\n    while(k) {\n      if (k & 1) \n        res *=\
    \ base;\n      base *= base, k >>= 1;\n    }\n    return res;\n  }\n\n  mint inverse()\
    \ const { return (*this).pow(mod - 2); }\n\n  u32 get() const {\n    u32 res =\
    \ reduce(a);\n    return res >= mod ? res - mod : res;\n  }\n\n  mint& operator+=(const\
    \ mint &b) {\n    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n\
    \  }\n\n  mint& operator-=(const mint &b) {\n    if (i32(a -= b.a) < 0) a += 2\
    \ * mod;\n    return *this;\n  }\n\n  mint& operator*=(const mint &b) {\n    a\
    \ = reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  mint& operator/=(const\
    \ mint &b) {\n    a = reduce(u64(a) * b.inverse().a);\n    return *this;\n  }\n\
    \n  mint operator-() { return mint() - mint(*this); }\n  bool operator==(mint\
    \ b) const {\n    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod :\
    \ b.a);\n  }\n  bool operator!=(mint b) const {\n    return (a >= mod ? a - mod\
    \ : a) != (b.a >= mod ? b.a - mod : b.a);\n  }\n\n  friend mint operator+(mint\
    \ c, mint d) { return c += d; }\n  friend mint operator-(mint c, mint d) { return\
    \ c -= d; }\n  friend mint operator*(mint c, mint d) { return c *= d; }\n  friend\
    \ mint operator/(mint c, mint d) { return c /= d; }\n\n  friend ostream& operator<<(ostream&\
    \ os, const mint& b) {\n    return os << b.get();\n  }\n  friend istream& operator>>(istream&\
    \ is, mint& b) {\n    int64_t val;\n    is >> val;\n    b = mint(val);\n    return\
    \ is;\n  }\n};\n\nusing mint = MontgomeryModInt<998244353>;\n#line 1 \"linalg/matrixMint.cpp\"\
    \n//source: KACTL(for det() and inv())\n\ntemplate<class Mint>\nstruct matrix\
    \ : vector<vector<Mint>> {\n  matrix(int n, int m) : vector<vector<Mint>>(n, vector<Mint>(m,\
    \ 0)) {}\n  matrix(int n) : vector<vector<Mint>>(n, vector<Mint>(n, 0)) {}\n\n\
    \  int n() const { return ssize(*this); }\n  int m() const { return ssize((*this)[0]);\
    \ }\n\n  static matrix I(int n) {\n    auto res = matrix(n, n);\n    for(int i\
    \ = 0; i < n; i++)\n      res[i][i] = 1;\n    return res;\n  }\n\n  matrix& operator+=(const\
    \ matrix &b) {\n    assert(n() == b.n());\n    assert(m() == b.m());\n    for(int\
    \ i = 0; i < n(); i++)\n      for(int j = 0; j < m(); j++)\n        (*this)[i][j]\
    \ += b[i][j];\n    return *this;\n  }\n\n  matrix& operator-=(const matrix &b)\
    \ {\n    assert(n() == b.n());\n    assert(m() == b.m());\n    for(int i = 0;\
    \ i < n(); i++)\n      for(int j = 0; j < m(); j++)\n        (*this)[i][j] -=\
    \ b[i][j];\n    return *this;\n  }\n\n  matrix& operator*=(const matrix &b) {\n\
    \    assert(m() == b.n());\n    auto res = matrix(n(), b.m());\n    for(int i\
    \ = 0; i < n(); i++)\n      for(int k = 0; k < m(); k++)\n        for(int j =\
    \ 0; j < b.m(); j++)\n          res[i][j] += (*this)[i][k] * b[k][j];\n    this\
    \ -> swap(res);\n    return *this;\n  }\n\n  matrix pow(ll k) const {\n    assert(n()\
    \ == m());\n    auto res = I(n()), base = *this;\n    while(k) {\n      if (k\
    \ & 1) res *= base;\n      base *= base, k >>= 1;\n    }\n    return res;\n  }\n\
    \n  Mint det() const {\n    Mint res = 1;\n    auto a = *this;\n    for(int i\
    \ = 0; i < n(); i++) {\n      for(int j = i + 1; j < m(); j++) {\n        while(a[j][i]\
    \ != 0) {\n          Mint t = a[i][i] / a[j][i];\n          if (t != 0)\n    \
    \        for(int k = i; k < n(); k++)\n              a[i][k] -= a[j][k] * t;\n\
    \          swap(a[i], a[j]);\n          res = -res;\n        }\n      }\n    \
    \  res *= a[i][i];\n      if (res == 0) return 0;\n    }\n    return res;\n  }\n\
    \n  matrix inv() const {\n    assert(n() == m());\n    matrix a = *this, tmp =\
    \ I(n());\n    vector<int> col(n());\n    for(int i = 0; i < n(); i++) col[i]\
    \ = i;\n\n    for(int i = 0; i < n(); i++) {\n      int r = i, c = i;\n      for(int\
    \ j = i; j < n(); j++) {\n        for(int k = i; k < n(); k++) {\n          if\
    \ (a[j][k] != 0) {\n            r = j, c = k;\n            goto found;\n     \
    \     }\n        }\n      }\n      return matrix(0);\n      found:\n      a[i].swap(a[r]),\
    \ tmp[i].swap(tmp[r]);\n      for(int j = 0; j < n(); j++)\n        swap(a[j][i],\
    \ a[j][c]), swap(tmp[j][i], tmp[j][c]);\n      swap(col[i], col[c]);\n      Mint\
    \ v = 1 / a[i][i];\n      for(int j = i + 1; j < n(); j++) {\n        Mint f =\
    \ a[j][i] * v;\n        a[j][i] = 0;\n        for(int k = i + 1; k < n(); k++)\n\
    \          a[j][k] -= f * a[i][k];\n        for(int k = 0; k < n(); k++)\n   \
    \       tmp[j][k] -= f * tmp[i][k];\n      }\n      for(int j = i + 1; j < n();\
    \ j++) \n        a[i][j] *= v;\n      for(int j = 0; j < n(); j++) \n        tmp[i][j]\
    \ *= v;\n      a[i][i] = 1;\n    }\n\n    for(int i = n() - 1; i > 0; i--) {\n\
    \      for(int j = 0; j < i; j++) {\n        Mint v = a[j][i];\n        for(int\
    \ k = 0; k < n(); k++)\n          tmp[j][k] -= v * tmp[i][k];\n      }\n    }\n\
    \n    for(int i = 0; i < n(); i++)\n      for(int j = 0; j < n(); j++)\n     \
    \   a[col[i]][col[j]] = tmp[i][j];\n    return a;\n  }\n\n  matrix operator-()\
    \ { return matrix(n(), m()) - (*this); }\n  \n  friend matrix operator+(matrix\
    \ a, matrix b) { return a += b; }\n  friend matrix operator-(matrix a, matrix\
    \ b) { return a -= b; }\n  friend matrix operator*(matrix a, matrix b) { return\
    \ a *= b; }\n  \n  friend ostream& operator<<(ostream& os, const matrix& b) {\n\
    \    for(int i = 0; i < b.n(); i++) {\n      os << '\\n';\n      for(int j = 0;\
    \ j < b.m(); j++)\n        os << b[i][j] << ' ';\n    }\n    return os;\n  }\n\
    \  friend istream& operator>>(istream& is, matrix& b) {\n    for(int i = 0; i\
    \ < b.n(); i++)\n      for(int j = 0; j < b.m(); j++)\n        is >> b[i][j];\n\
    \    return is;\n  }\n};\n#line 1 \"combi/binom.cpp\"\n//#include<modint/MontgomeryModInt.cpp>\n\
    \ntemplate<class Mint>\nstruct binomial {\n  vector<Mint> _fac, _facInv;\n  binomial(int\
    \ size) : _fac(size), _facInv(size) {\n    _fac[0] = 1;\n    for(int i = 1; i\
    \ < size; i++)\n      _fac[i] = _fac[i - 1] * i;\n    if (size > 0)\n      _facInv.back()\
    \ = 1 / _fac.back();\n    for(int i = size - 2; i >= 0; i--)\n      _facInv[i]\
    \ = _facInv[i + 1] * (i + 1);\n  }\n\n  Mint fac(int i) { return i < 0 ? 0 : _fac[i];\
    \ }\n  Mint faci(int i) { return i < 0 ? 0 : _facInv[i]; }\n  Mint inv(int i)\
    \ { return _facInv[i] * _fac[i - 1]; }\n  Mint binom(int n, int r) { return r\
    \ < 0 or n < r ? 0 : fac(n) * faci(r) * faci(n - r); }\n  Mint catalan(int i)\
    \ { return binom(2 * i, i) - binom(2 * i, i + 1); }\n  Mint excatalan(int n, int\
    \ m, int k) { //(+1) * n, (-1) * m, prefix sum > -k\n    if (k > m) return binom(n\
    \ + m, m);\n    else if (k > m - n) return binom(n + m, m) - binom(n + m, m -\
    \ k);\n    else return Mint(0);\n  }\n};\n#line 1 \"combi/countSpanningForest.cpp\"\
    \n//#include \"modint/MontgomeryModInt.cpp\"\n//#include \"linalg/matrixMint.cpp\"\
    \n\ntemplate<class Mint, bool directed = false>\nMint countSpanningForest(vector<tuple<int,\
    \ int, Mint>> e, int n, vector<int> r = vector(1, 0)) {\n  vector<int> id(n, 1);\n\
    \  for(int x : r) id[x] = 0;\n  id[0] -= 1;\n  pSum(id);\n  for(int x : r) id[x]\
    \ = -1;\n\n  matrix<Mint> M(n - ssize(r));\n  for(auto [u, v, w] : e) {\n    u\
    \ = id[u], v = id[v];\n    if (u != -1 and v != -1) {\n      M[u][v] -= w;\n \
    \     if constexpr (!directed) M[v][u] -= w;\n    }\n    if constexpr (!directed)\
    \ if (u != -1) M[u][u] += w;\n    if (v != -1) M[v][v] += w;\n  }\n  return M.det();\n\
    }\n#line 1 \"combi/countEulerianCircuit.cpp\"\n//#include \"modint/MontgomeryModInt.cpp\"\
    \n//#include \"linalg/matrixMint.cpp\"\n//#include \"combi/countSpanningForest.cpp\"\
    \n//#include \"combi/binom.cpp\"\n\ntemplate<class Mint>\nMint countEulerianCircuit(vector<array<int,\
    \ 2>> e, int n) {\n  vector<int> deg(n);\n  vector<vector<int>> g(n);\n  for(auto\
    \ [u, v] : e) {\n    deg[v]++;\n    g[u].emplace_back(v);\n  }\n\n  for(int v\
    \ = 0; v < n; v++)\n    if (deg[v] != ssize(g[v]))\n      return Mint(0);\n\n\
    \  vector<bool> vis(n, false);\n  auto dfs = [&](int v, auto &&self) -> void {\n\
    \    vis[v] = true;\n    for(int x : g[v])\n      if (!vis[x])\n        self(x,\
    \ self);\n  };\n\n  int s = 0;\n  while(s < n and deg[s] == 0) s++;\n  s %= n;\n\
    \  dfs(s, dfs);\n\n  vector<int> r(1, s);\n  for(int v = 0; v < n; v++) if (!vis[v])\
    \ {\n    if (deg[v] != 0) return Mint(0);\n    else r.emplace_back(v);\n  }\n\n\
    \  vector<tuple<int, int, Mint>> ep(ssize(e));\n  for(int i = 0; auto [u, v] :\
    \ e)\n    ep[i++] = {u, v, Mint(1)};\n  \n  Mint c = 1;\n  binomial<Mint> bn(ssize(e));\n\
    \  for(int v = 0; v < n; v++)\n    c *= bn.fac(max(deg[v] - 1, 0));\n\n  return\
    \ c * countSpanningForest<Mint, true>(ep, n, r);\n}\n#line 9 \"test/counting_eulerian_circuits.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ m; cin >> n >> m;\n  vector<array<int, 2>> e(m);\n  for(auto &[u, v] : e) cin\
    \ >> u >> v;\n\n  cout << countEulerianCircuit<mint>(e, n) << '\\n';\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_eulerian_circuits\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../linalg/matrixMint.cpp\"\n#include \"../combi/binom.cpp\"\n#include\
    \ \"../combi/countSpanningForest.cpp\"\n#include \"../combi/countEulerianCircuit.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ m; cin >> n >> m;\n  vector<array<int, 2>> e(m);\n  for(auto &[u, v] : e) cin\
    \ >> u >> v;\n\n  cout << countEulerianCircuit<mint>(e, n) << '\\n';\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/MontgomeryModInt.cpp
  - linalg/matrixMint.cpp
  - combi/binom.cpp
  - combi/countSpanningForest.cpp
  - combi/countEulerianCircuit.cpp
  isVerificationFile: true
  path: test/counting_eulerian_circuits.test.cpp
  requiredBy: []
  timestamp: '2024-08-02 21:56:58+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/counting_eulerian_circuits.test.cpp
layout: document
redirect_from:
- /verify/test/counting_eulerian_circuits.test.cpp
- /verify/test/counting_eulerian_circuits.test.cpp.html
title: test/counting_eulerian_circuits.test.cpp
---
