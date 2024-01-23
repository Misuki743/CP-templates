---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: modint/MontgomeryModInt.cpp
    title: modint/MontgomeryModInt.cpp
  - icon: ':heavy_check_mark:'
    path: poly/BostanMori.cpp
    title: poly/BostanMori.cpp
  - icon: ':heavy_check_mark:'
    path: poly/NTTmint.cpp
    title: poly/NTTmint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
    links:
    - https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
  bundledCode: "#line 1 \"test/kth_term_of_linearly_recurrent_sequence.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
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
    \nnamespace R = std::ranges;\nnamespace V = std::views;\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing ull = unsigned long long;\nusing ldb = long double;\n\
    using pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate<class T>\n\
    ostream& operator<<(ostream& os, const pair<T, T> pr) {\n  return os << pr.first\
    \ << ' ' << pr.second;\n}\ntemplate<class T, size_t N>\nostream& operator<<(ostream&\
    \ os, const array<T, N> &arr) {\n  for(const T &X : arr)\n    os << X << ' ';\n\
    \  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const vector<T>\
    \ &vec) {\n  for(const T &X : vec)\n    os << X << ' ';\n  return os;\n}\ntemplate<class\
    \ T>\nostream& operator<<(ostream& os, const set<T> &s) {\n  for(const T &x :\
    \ s)\n    os << x << ' ';\n  return os;\n}\n#line 1 \"modint/MontgomeryModInt.cpp\"\
    \n/**\n * template name: MontgomeryModInt\n * author: Misuki\n * reference: https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10\n\
    \ * last update: 2023/11/30\n * note: mod should be a prime less than 2^30.\n\
    \ */\n\ntemplate<uint32_t mod>\nstruct MontgomeryModInt {\n  using mint = MontgomeryModInt;\n\
    \  using i32 = int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n\
    \  static constexpr u32 get_r() {\n    u32 res = 1, base = mod;\n    for(i32 i\
    \ = 0; i < 31; i++)\n      res *= base, base *= base;\n    return -res;\n  }\n\
    \n  static constexpr u32 get_mod() {\n    return mod;\n  }\n\n  static constexpr\
    \ u32 n2 = -u64(mod) % mod; //2^64 % mod\n  static constexpr u32 r = get_r();\
    \ //-P^{-1} % 2^32\n\n  u32 a;\n\n  static u32 reduce(const u64 &b) {\n    return\
    \ (b + u64(u32(b) * r) * mod) >> 32;\n  }\n\n  static u32 transform(const u64\
    \ &b) {\n    return reduce(u64(b) * n2);\n  }\n\n  MontgomeryModInt() : a(0) {}\n\
    \  MontgomeryModInt(const int64_t &b) \n    : a(transform(b % mod + mod)) {}\n\
    \n  mint pow(u64 k) const {\n    mint res(1), base(*this);\n    while(k) {\n \
    \     if (k & 1) \n        res *= base;\n      base *= base, k >>= 1;\n    }\n\
    \    return res;\n  }\n\n  mint inverse() const { return (*this).pow(mod - 2);\
    \ }\n\n  u32 get() const {\n    u32 res = reduce(a);\n    return res >= mod ?\
    \ res - mod : res;\n  }\n\n  mint& operator+=(const mint &b) {\n    if (i32(a\
    \ += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  mint& operator-=(const\
    \ mint &b) {\n    if (i32(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n\
    \n  mint& operator*=(const mint &b) {\n    a = reduce(u64(a) * b.a);\n    return\
    \ *this;\n  }\n\n  mint& operator/=(const mint &b) {\n    a = reduce(u64(a) *\
    \ b.inverse().a);\n    return *this;\n  }\n\n  mint operator-() { return mint()\
    \ - mint(*this); }\n  bool operator==(mint b) const {\n    return (a >= mod ?\
    \ a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n  bool operator!=(mint\
    \ b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod :\
    \ b.a);\n  }\n\n  friend mint operator+(mint a, mint b) { return a += b; }\n \
    \ friend mint operator-(mint a, mint b) { return a -= b; }\n  friend mint operator*(mint\
    \ a, mint b) { return a *= b; }\n  friend mint operator/(mint a, mint b) { return\
    \ a /= b; }\n\n  friend ostream& operator<<(ostream& os, const mint& b) {\n  \
    \  return os << b.get();\n  }\n  friend istream& operator>>(istream& is, mint&\
    \ b) {\n    int64_t val;\n    is >> val;\n    b = mint(val);\n    return is;\n\
    \  }\n};\n\nusing mint = MontgomeryModInt<998244353>;\n#line 1 \"poly/NTTmint.cpp\"\
    \n/**\n * template name: NTTmint\n * reference: https://judge.yosupo.jp/submission/69896\n\
    \ * last update: 2024/01/07\n * include: mint\n * remark: MOD = 2^K * C + 1, R\
    \ is a primitive root modulo MOD\n * remark: a.size() <= 2^K must be satisfied\n\
    \ * some common modulo: 998244353  = 2^23 * 119 + 1, R = 3\n *               \
    \      469762049  = 2^26 * 7   + 1, R = 3\n *                     1224736769 =\
    \ 2^24 * 73  + 1, R = 3\n * verify: Library Checker - Convolution\n */\n\ntemplate<int32_t\
    \ k = 23, int32_t c = 119, int32_t r = 3, class Mint = MontgomeryModInt<998244353>>\n\
    struct NTT {\n\n  using u32 = uint32_t;\n  static constexpr u32 mod = (1 << k)\
    \ * c + 1;\n  static constexpr u32 get_mod() { return mod; }\n\n  static void\
    \ ntt(vector<Mint> &a, bool inverse) {\n    static array<Mint, 30> w, w_inv;\n\
    \    if (w[0] == 0) {\n      Mint root = 2;\n      while(root.pow((mod - 1) /\
    \ 2) == 1) root += 1;\n      for(int i = 0; i < 30; i++)\n        w[i] = -(root.pow((mod\
    \ - 1) >> (i + 2))), w_inv[i] = 1 / w[i];\n    }\n    int n = ssize(a);\n    if\
    \ (not inverse) {\n      for(int m = n; m >>= 1; ) {\n        Mint ww = 1;\n \
    \       for(int s = 0, l = 0; s < n; s += 2 * m) {\n          for(int i = s, j\
    \ = s + m; i < s + m; i++, j++) {\n            Mint x = a[i], y = a[j] * ww;\n\
    \            a[i] = x + y, a[j] = x - y;\n          }\n          ww *= w[__builtin_ctz(++l)];\n\
    \        }\n      }\n    } else {\n      for(int m = 1; m < n; m *= 2) {\n   \
    \     Mint ww = 1;\n        for(int s = 0, l = 0; s < n; s += 2 * m) {\n     \
    \     for(int i = s, j = s + m; i < s + m; i++, j++) {\n            Mint x = a[i],\
    \ y = a[j];\n            a[i] = x + y, a[j] = (x - y) * ww;\n          }\n   \
    \       ww *= w_inv[__builtin_ctz(++l)];\n        }\n      }\n      Mint inv =\
    \ 1 / Mint(n);\n      for(Mint &x : a) x *= inv;\n    }\n  }\n\n  static vector<Mint>\
    \ conv(vector<Mint> a, vector<Mint> b) {\n    int sz = ssize(a) + ssize(b) - 1;\n\
    \    int n = bit_ceil((u32)sz);\n\n    a.resize(n, 0);\n    ntt(a, false);\n \
    \   b.resize(n, 0);\n    ntt(b, false);\n\n    for(int i = 0; i < n; i++)\n  \
    \    a[i] *= b[i];\n\n    ntt(a, true);\n\n    a.resize(sz);\n\n    return a;\n\
    \  }\n};\n#line 1 \"poly/BostanMori.cpp\"\n/**\n * template name: Bostan-Mori\n\
    \ * author: Misuki\n * last update: 2024/01/06\n * include: NTT, mint\n * usage:\
    \ compute k-th term of P(x)/Q(x) in O(dlgdlgk)\n * verify: Library Checker - Kth\
    \ term of Linearly Recurrent Sequence\n */\n\ntemplate<NTT Ntt, class Mint>\n\
    mint BostanMori(vector<Mint> P, vector<Mint> Q, ll k) {\n  assert(!P.empty() and\
    \ !Q.empty() and Q[0] != 0);\n  \n  int d = max(ssize(P), ssize(Q) - 1);\n  P.resize(d,\
    \ 0), Q.resize(d + 1, 0);\n\n  int size = 1 << (bit_width((unsigned)d) + 1);\n\
    \  while(k) {\n    vector<Mint> Qneg(size);\n    for(int i = 0; i < ssize(Q);\
    \ i++)\n      Qneg[i] = Q[i] * ((i & 1) ? -1 : 1);\n    Ntt.ntt(Qneg, false);\n\
    \n    vector<Mint> U(size), V(size);\n    copy(P.begin(), P.end(), U.begin());\n\
    \    copy(Q.begin(), Q.end(), V.begin());\n\n    Ntt.ntt(U, false), Ntt.ntt(V,\
    \ false);\n    for(int i = 0; i < size; i++)\n      U[i] *= Qneg[i], V[i] *= Qneg[i];\n\
    \    Ntt.ntt(U, true), Ntt.ntt(V, true);\n\n    for(int i = k & 1; i < 2 * d;\
    \ i += 2)\n      P[i >> 1] = U[i];\n    for(int i = 0; i <= 2 * d; i += 2)\n \
    \     Q[i >> 1] = V[i];\n    k >>= 1;\n  }\n\n  return P[0] / Q[0];\n}\n#line\
    \ 7 \"test/kth_term_of_linearly_recurrent_sequence.test.cpp\"\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int d; cin >> d;\n  ll\
    \ k; cin >> k;\n  vector<mint> a(d), c(d);\n  for(mint &x : a)\n    cin >> x;\n\
    \  for(mint &x : c) {\n    cin >> x;\n    x *= -1;\n  }\n\n  c.insert(c.begin(),\
    \ mint(1));\n  NTT<23, 119, 3, mint> ntt;\n  a = ntt.conv(a, c);\n  a.resize(d);\n\
    \n  cout << BostanMori<ntt, mint>(a, c, k) << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../poly/NTTmint.cpp\"\n#include \"../poly/BostanMori.cpp\"\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int d; cin >> d;\n\
    \  ll k; cin >> k;\n  vector<mint> a(d), c(d);\n  for(mint &x : a)\n    cin >>\
    \ x;\n  for(mint &x : c) {\n    cin >> x;\n    x *= -1;\n  }\n\n  c.insert(c.begin(),\
    \ mint(1));\n  NTT<23, 119, 3, mint> ntt;\n  a = ntt.conv(a, c);\n  a.resize(d);\n\
    \n  cout << BostanMori<ntt, mint>(a, c, k) << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/MontgomeryModInt.cpp
  - poly/NTTmint.cpp
  - poly/BostanMori.cpp
  isVerificationFile: true
  path: test/kth_term_of_linearly_recurrent_sequence.test.cpp
  requiredBy: []
  timestamp: '2024-01-21 17:57:21+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/kth_term_of_linearly_recurrent_sequence.test.cpp
layout: document
redirect_from:
- /verify/test/kth_term_of_linearly_recurrent_sequence.test.cpp
- /verify/test/kth_term_of_linearly_recurrent_sequence.test.cpp.html
title: test/kth_term_of_linearly_recurrent_sequence.test.cpp
---
