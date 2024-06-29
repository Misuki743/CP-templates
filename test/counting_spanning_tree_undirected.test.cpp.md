---
data:
  _extendedDependsOn:
  - icon: ':x:'
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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/counting_spanning_tree_undirected
    links:
    - https://judge.yosupo.jp/problem/counting_spanning_tree_undirected
  bundledCode: "#line 1 \"test/counting_spanning_tree_undirected.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/counting_spanning_tree_undirected\"\
    \n\n#line 1 \"default/t.cpp\"\n#include <algorithm>\n#include <array>\n#include\
    \ <bit>\n#include <bitset>\n#include <cassert>\n#include <cctype>\n#include <cfenv>\n\
    #include <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include <climits>\n\
    #include <cmath>\n#include <compare>\n#include <complex>\n#include <concepts>\n\
    #include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include <cstdio>\n\
    #include <cstdlib>\n#include <cstring>\n#include <deque>\n#include <fstream>\n\
    #include <functional>\n#include <initializer_list>\n#include <iomanip>\n#include\
    \ <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n#include\
    \ <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include <new>\n\
    #include <numbers>\n#include <numeric>\n#include <ostream>\n#include <queue>\n\
    #include <random>\n#include <ranges>\n#include <set>\n#include <span>\n#include\
    \ <sstream>\n#include <stack>\n#include <streambuf>\n#include <string>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <variant>\n\n#define INT128_MAX (__int128)(((unsigned\
    \ __int128) 1 << ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN\
    \ (-INT128_MAX - 1)\n\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ldb = long double;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\
    \ntemplate<class T>\nostream& operator<<(ostream& os, const pair<T, T> pr) {\n\
    \  return os << pr.first << ' ' << pr.second;\n}\ntemplate<class T, size_t N>\n\
    ostream& operator<<(ostream& os, const array<T, N> &arr) {\n  for(const T &X :\
    \ arr)\n    os << X << ' ';\n  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream&\
    \ os, const vector<T> &vec) {\n  for(const T &X : vec)\n    os << X << ' ';\n\
    \  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const set<T>\
    \ &s) {\n  for(const T &x : s)\n    os << x << ' ';\n  return os;\n}\n#line 1\
    \ \"modint/MontgomeryModInt.cpp\"\n//reference: https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10\n\
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
    \ a, mint b) { return a += b; }\n  friend mint operator-(mint a, mint b) { return\
    \ a -= b; }\n  friend mint operator*(mint a, mint b) { return a *= b; }\n  friend\
    \ mint operator/(mint a, mint b) { return a /= b; }\n\n  friend ostream& operator<<(ostream&\
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
    \    return is;\n  }\n};\n#line 1 \"combi/countSpanningForest.cpp\"\n//#include\
    \ \"modint/MontgomeryModInt.cpp\"\n//#include \"linalg/matrixMint.cpp\"\n\ntemplate<class\
    \ Mint, bool directed = false>\nMint countSpanningForest(vector<tuple<int, int,\
    \ Mint>> e, int n, vector<int> r = vector(1, 0)) {\n  vector<int> id(n, 1);\n\
    \  for(int x : r) id[x] = 0;\n  id[0] -= 1;\n  pSum(id);\n  for(int x : r) id[x]\
    \ = -1;\n\n  matrix<Mint> M(n - ssize(r));\n  for(auto [u, v, w] : e) {\n    u\
    \ = id[u], v = id[v];\n    if (u != -1 and v != -1) {\n      M[u][v] -= w;\n \
    \     if constexpr (!directed) M[v][u] -= w;\n    }\n    if constexpr (!directed)\
    \ if (u != -1) M[u][u] += w;\n    if (v != -1) M[v][v] += w;\n  }\n  return M.det();\n\
    }\n#line 7 \"test/counting_spanning_tree_undirected.test.cpp\"\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, m; cin >> n >>\
    \ m;\n  vector<tuple<int, int, mint>> e(m);\n  for(auto &[u, v, w] : e) {\n  \
    \  cin >> u >> v;\n    w = 1;\n  }\n\n  cout << countSpanningForest(e, n) << '\\\
    n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_spanning_tree_undirected\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../linalg/matrixMint.cpp\"\n#include \"../combi/countSpanningForest.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ m; cin >> n >> m;\n  vector<tuple<int, int, mint>> e(m);\n  for(auto &[u, v,\
    \ w] : e) {\n    cin >> u >> v;\n    w = 1;\n  }\n\n  cout << countSpanningForest(e,\
    \ n) << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/MontgomeryModInt.cpp
  - linalg/matrixMint.cpp
  - combi/countSpanningForest.cpp
  isVerificationFile: true
  path: test/counting_spanning_tree_undirected.test.cpp
  requiredBy: []
  timestamp: '2024-06-29 17:34:40+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/counting_spanning_tree_undirected.test.cpp
layout: document
redirect_from:
- /verify/test/counting_spanning_tree_undirected.test.cpp
- /verify/test/counting_spanning_tree_undirected.test.cpp.html
title: test/counting_spanning_tree_undirected.test.cpp
---
