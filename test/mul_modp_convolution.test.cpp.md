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
    path: poly/NTTmint.cpp
    title: poly/NTTmint.cpp
  - icon: ':heavy_check_mark:'
    path: poly/mulConvolution.cpp
    title: mulConvolution
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/mul_modp_convolution
    links:
    - https://judge.yosupo.jp/problem/mul_modp_convolution
  bundledCode: "#line 1 \"test/mul_modp_convolution.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/mul_modp_convolution\"\n\n#line 1 \"default/t.cpp\"\
    \n#include <algorithm>\n#include <array>\n#include <bit>\n#include <bitset>\n\
    #include <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <compare>\n#include <complex>\n#include <concepts>\n#include <cstdarg>\n#include\
    \ <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include\
    \ <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
    \ <initializer_list>\n#include <iomanip>\n#include <ios>\n#include <iostream>\n\
    #include <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n\
    #include <map>\n#include <memory>\n#include <new>\n#include <numbers>\n#include\
    \ <numeric>\n#include <ostream>\n#include <queue>\n#include <random>\n#include\
    \ <ranges>\n#include <set>\n#include <span>\n#include <sstream>\n#include <stack>\n\
    #include <streambuf>\n#include <string>\n#include <tuple>\n#include <type_traits>\n\
    #include <variant>\n\n#define INT128_MAX (__int128)(((unsigned __int128) 1 <<\
    \ ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN (-INT128_MAX\
    \ - 1)\n\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
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
    \ is;\n  }\n};\n\nusing mint = MontgomeryModInt<998244353>;\n#line 1 \"poly/NTTmint.cpp\"\
    \n//reference: https://judge.yosupo.jp/submission/69896\n//remark: MOD = 2^K *\
    \ C + 1, R is a primitive root modulo MOD\n//remark: a.size() <= 2^K must be satisfied\n\
    //some common modulo: 998244353  = 2^23 * 119 + 1, R = 3\n//                 \
    \   469762049  = 2^26 * 7   + 1, R = 3\n//                    1224736769 = 2^24\
    \ * 73  + 1, R = 3\n\ntemplate<int32_t k = 23, int32_t c = 119, int32_t r = 3,\
    \ class Mint = MontgomeryModInt<998244353>>\nstruct NTT {\n\n  using u32 = uint32_t;\n\
    \  static constexpr u32 mod = (1 << k) * c + 1;\n  static constexpr u32 get_mod()\
    \ { return mod; }\n\n  static void ntt(vector<Mint> &a, bool inverse) {\n    static\
    \ array<Mint, 30> w, w_inv;\n    if (w[0] == 0) {\n      Mint root = 2;\n    \
    \  while(root.pow((mod - 1) / 2) == 1) root += 1;\n      for(int i = 0; i < 30;\
    \ i++)\n        w[i] = -(root.pow((mod - 1) >> (i + 2))), w_inv[i] = 1 / w[i];\n\
    \    }\n    int n = ssize(a);\n    if (not inverse) {\n      for(int m = n; m\
    \ >>= 1; ) {\n        Mint ww = 1;\n        for(int s = 0, l = 0; s < n; s +=\
    \ 2 * m) {\n          for(int i = s, j = s + m; i < s + m; i++, j++) {\n     \
    \       Mint x = a[i], y = a[j] * ww;\n            a[i] = x + y, a[j] = x - y;\n\
    \          }\n          ww *= w[__builtin_ctz(++l)];\n        }\n      }\n   \
    \ } else {\n      for(int m = 1; m < n; m *= 2) {\n        Mint ww = 1;\n    \
    \    for(int s = 0, l = 0; s < n; s += 2 * m) {\n          for(int i = s, j =\
    \ s + m; i < s + m; i++, j++) {\n            Mint x = a[i], y = a[j];\n      \
    \      a[i] = x + y, a[j] = (x - y) * ww;\n          }\n          ww *= w_inv[__builtin_ctz(++l)];\n\
    \        }\n      }\n      Mint inv = 1 / Mint(n);\n      for(Mint &x : a) x *=\
    \ inv;\n    }\n  }\n\n  static vector<Mint> conv(vector<Mint> a, vector<Mint>\
    \ b) {\n    int sz = ssize(a) + ssize(b) - 1;\n    int n = bit_ceil((u32)sz);\n\
    \n    a.resize(n, 0);\n    ntt(a, false);\n    b.resize(n, 0);\n    ntt(b, false);\n\
    \n    for(int i = 0; i < n; i++)\n      a[i] *= b[i];\n\n    ntt(a, true);\n\n\
    \    a.resize(sz);\n\n    return a;\n  }\n};\n#line 1 \"poly/mulConvolution.cpp\"\
    \n//#include \"poly/NTTmint.cpp\"\n//#include \"modint/MontgomeryModInt.cpp\"\n\
    \nstruct mulConvolution {\n  const int P, root;\n  vector<int> powR, logR;\n\n\
    \  int primitiveRoot(int p) {\n    vector<int> pf;\n    {\n      int tmp = p -\
    \ 1;\n      for(int i = 2; i * i <= (p - 1); i++) {\n        if (tmp % i != 0)\
    \ continue;\n        pf.emplace_back(i);\n        while(tmp % i == 0) tmp /= i;\n\
    \      }\n      if (tmp != 1)\n        pf.emplace_back(tmp);\n    }\n\n    auto\
    \ modPow = [p](ll a, int x) -> int {\n      if (x == 0) return 1;\n      if (a\
    \ == 0) return 0;\n      ll b = 1;\n      while(x) {\n        if (x & 1) b = b\
    \ * a % p;\n        a = a * a % p, x >>= 1;\n      }\n      return b;\n    };\n\
    \n    for(int r = 1; ; r++) {\n      bool isRoot = true;\n      for(int d : pf)\
    \ {\n        if (modPow(r, (p - 1) / d) == 1) {\n          isRoot = false;\n \
    \         break;\n        }\n      }\n      if (isRoot)\n        return r;\n \
    \   }\n  }\n\n  mulConvolution(int _P) : P(_P), root(primitiveRoot(_P)), powR(P\
    \ - 1), logR(P, -1) {\n    for(int i = 0, tmp = 1; i < P - 1; i++, tmp = (ll)tmp\
    \ * root % P)\n      powR[i] = tmp, logR[tmp] = i;\n  }\n\n  template<class Mint>\n\
    \  vector<Mint> transform(vector<Mint> &f) {\n    assert(ssize(f) == P);\n   \
    \ vector<Mint> g(P - 1);\n    for(int i = 1; i < P; i++)\n      g[logR[i]] = f[i];\n\
    \    return g;\n  }\n\n  template<class Mint>\n  vector<Mint> invTransform(vector<Mint>\
    \ &f) {\n    assert(ssize(f) == P - 1);\n    vector<Mint> g(P);\n    for(int i\
    \ = 0; i < P - 1; i++)\n      g[powR[i]] = f[i];\n    return g;\n  }\n\n  template<class\
    \ Mint>\n  vector<Mint> mulConv(vector<Mint> a, vector<Mint> b, vector<Mint>(*conv)(vector<Mint>,\
    \ vector<Mint>)) {\n    Mint zero = accumulate(a.begin(), a.end(), Mint(0)) *\
    \ b[0] + accumulate(b.begin() + 1, b.end(), Mint(0)) * a[0];\n    a = transform(a),\
    \ b = transform(b);\n    a = conv(a, b);\n    for(int i = P - 1; i < 2 * P - 3;\
    \ i++)\n      a[i - (P - 1)] += a[i];\n    a.resize(P - 1);\n    a = invTransform(a);\n\
    \    a[0] = zero;\n    return a;\n  }\n};\n#line 7 \"test/mul_modp_convolution.test.cpp\"\
    \n\nNTT ntt;\n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\
    \n  int p; cin >> p;\n  vector<mint> a(p), b(p);\n  for(mint &x : a)\n    cin\
    \ >> x;\n  for(mint &x : b)\n    cin >> x;\n\n  mulConvolution mu(p);\n  cout\
    \ << mu.mulConv(a, b, ntt.conv) << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/mul_modp_convolution\"\n\
    \n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\n\
    #include \"../poly/NTTmint.cpp\"\n#include \"../poly/mulConvolution.cpp\"\n\n\
    NTT ntt;\n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n\
    \  int p; cin >> p;\n  vector<mint> a(p), b(p);\n  for(mint &x : a)\n    cin >>\
    \ x;\n  for(mint &x : b)\n    cin >> x;\n\n  mulConvolution mu(p);\n  cout <<\
    \ mu.mulConv(a, b, ntt.conv) << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/MontgomeryModInt.cpp
  - poly/NTTmint.cpp
  - poly/mulConvolution.cpp
  isVerificationFile: true
  path: test/mul_modp_convolution.test.cpp
  requiredBy: []
  timestamp: '2024-04-05 18:02:52+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mul_modp_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/mul_modp_convolution.test.cpp
- /verify/test/mul_modp_convolution.test.cpp.html
title: test/mul_modp_convolution.test.cpp
---