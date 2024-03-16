---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: misc/sharpPSubsetSum.cpp
    title: misc/sharpPSubsetSum.cpp
  - icon: ':heavy_check_mark:'
    path: modint/MontgomeryModInt.cpp
    title: modint/MontgomeryModInt.cpp
  - icon: ':heavy_check_mark:'
    path: poly/FPS.cpp
    title: poly/FPS.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/sharp_p_subset_sum
    links:
    - https://judge.yosupo.jp/problem/sharp_p_subset_sum
  bundledCode: "#line 1 \"test/sharp_p_subset_sum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/sharp_p_subset_sum\"\
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
    \    a.resize(sz);\n\n    return a;\n  }\n};\n#line 1 \"poly/FPS.cpp\"\n//#include\
    \ \"modint/MontgomeryModInt.cpp\"\n//#include \"poly/NTTmint.cpp\"\n\ntemplate<class\
    \ Mint>\nstruct FPS : vector<Mint> {\n\n  static function<vector<Mint>(vector<Mint>,\
    \ vector<Mint>)> conv;\n\n  FPS(vector<Mint> v) : vector<Mint>(v) {}\n\n  using\
    \ vector<Mint>::vector;\n  FPS& operator+=(FPS b) {\n    if (ssize(*this) < ssize(b))\
    \ this -> resize(ssize(b), 0);\n    for(int i = 0; i < ssize(b); i++)\n      (*this)[i]\
    \ += b[i];\n    return *this;\n  }\n\n  FPS& operator-=(FPS b) {\n    if (ssize(*this)\
    \ < ssize(b)) this -> resize(ssize(b), 0);\n    for(int i = 0; i < ssize(b); i++)\n\
    \      (*this)[i] -= b[i];\n    return *this;\n  }\n\n  FPS& operator*=(FPS b)\
    \ {\n    auto c = conv(*this, b);\n    this -> resize(ssize(*this) + ssize(b)\
    \ - 1);\n    copy(c.begin(), c.end(), this -> begin());\n    return *this;\n \
    \ }\n\n  FPS& operator*=(Mint b) {\n    for(int i = 0; i < ssize(*this); i++)\n\
    \      (*this)[i] *= b;\n    return *this;\n  }\n\n  FPS& operator/=(Mint b) {\n\
    \    b = Mint(1) / b;\n    for(int i = 0; i < ssize(*this); i++)\n      (*this)[i]\
    \ *= b;\n    return *this;\n  }\n\n  FPS shrink() {\n    FPS F = *this;\n    int\
    \ size = ssize(F);\n    while(size and F[size - 1] == 0) size -= 1;\n    F.resize(size);\n\
    \    return F;\n  }\n\n  FPS integral() {\n    if (this -> empty()) return {0};\n\
    \    vector<Mint> Inv(ssize(*this) + 1);\n    Inv[1] = 1;\n    for(int i = 2;\
    \ i < ssize(Inv); i++)\n      Inv[i] = (Mint::get_mod() - Mint::get_mod() / i)\
    \ * Inv[Mint::get_mod() % i];\n    FPS Q(ssize(*this) + 1, 0);\n    for(int i\
    \ = 0; i < ssize(*this); i++)\n      Q[i + 1] = (*this)[i] * Inv[i + 1];\n   \
    \ return Q;\n  }\n\n  FPS derivative() {\n    assert(!this -> empty());\n    FPS\
    \ Q(ssize(*this) - 1);\n    for(int i = 1; i < ssize(*this); i++)\n      Q[i -\
    \ 1] = (*this)[i] * i;\n    return Q;\n  }\n\n  Mint eval(Mint x) {\n    Mint\
    \ base = 1, res = 0;\n    for(int i = 0; i < ssize(*this); i++, base *= x)\n \
    \     res += (*this)[i] * base;\n    return res;\n  }\n\n  FPS inv(int k) { //\
    \ 1 / FPS (mod x^k)\n    assert(!this -> empty() and (*this)[0] != 0);\n    FPS\
    \ Q(1, 1 / (*this)[0]);\n    for(int i = 1; (1 << (i - 1)) < k; i++) {\n     \
    \ FPS P = (*this);\n      P.resize(1 << i, 0);\n      Q = Q * (FPS(1, 2) - P *\
    \ Q);\n      Q.resize(1 << i, 0);\n    }\n    Q.resize(k);\n    return Q;\n  }\n\
    \n  array<FPS, 2> div(FPS G) {\n    FPS F = this -> shrink();\n    G = G.shrink();\n\
    \    assert(!G.empty());\n    if (ssize(G) > ssize(F))\n      return {{{}, F}};\n\
    \    int n = ssize(F) - ssize(G) + 1;\n    auto FR = F, GR = G;\n    ranges::reverse(FR);\n\
    \    ranges::reverse(GR);\n    FPS Q = FR * GR.inv(n);\n    Q.resize(n);\n   \
    \ ranges::reverse(Q);\n    return {Q, (F - G * Q).shrink()};\n  }\n\n  FPS log(int\
    \ k) {\n    assert(!this -> empty() and (*this)[0] == 1);\n    FPS Q = *this;\n\
    \    Q = (Q.derivative() * Q.inv(k));\n    Q.resize(k - 1);\n    return Q.integral();\n\
    \  }\n\n  FPS exp(int k) {\n    assert(!this -> empty() and (*this)[0] == 0);\n\
    \    FPS Q(1, 1);\n    for(int i = 1; (1 << (i - 1)) < k; i++) {\n      FPS P\
    \ = (*this);\n      P.resize(1 << i, 0);\n      Q = Q * (FPS(1, 1) + P - Q.log(1\
    \ << i));\n      Q.resize(1 << i, 0);\n    }\n    Q.resize(k);\n    return Q;\n\
    \  }\n\n  FPS pow(ll idx, int k) {\n    if (idx == 0) {\n      FPS res(k, 0);\n\
    \      res[0] = 1;\n      return res;\n    }\n    for(int i = 0; i < ssize(*this)\
    \ and i * idx < k; i++) {\n      if ((*this)[i] != 0) {\n        Mint Inv = 1\
    \ / (*this)[i];\n        FPS Q(ssize(*this) - i);\n        for(int j = i; j <\
    \ ssize(*this); j++)\n          Q[j - i] = (*this)[j] * Inv;\n        Q = (Q.log(k)\
    \ * idx).exp(k);\n        FPS Q2(k, 0);\n        Mint Pow = (*this)[i].pow(idx);\n\
    \        for(int j = 0; j + i * idx < k; j++)\n          Q2[j + i * idx] = Q[j]\
    \ * Pow;\n        return Q2;\n      }\n    } \n    return FPS(k, 0);\n  }\n\n\
    \  vector<Mint> multieval(vector<Mint> xs) {\n    int n = ssize(xs);\n    vector<FPS>\
    \ data(2 * n);\n    for(int i = 0; i < n; i++)\n      data[n + i] = {-xs[i], 1};\n\
    \    for(int i = n - 1; i > 0; i--)\n      data[i] = data[i << 1] * data[i <<\
    \ 1 | 1];\n    data[1] = (this -> div(data[1]))[1];\n    for(int i = 1; i < n;\
    \ i++) {\n      data[i << 1] = data[i].div(data[i << 1])[1];\n      data[i <<\
    \ 1 | 1] = data[i].div(data[i << 1 | 1])[1];\n    }\n    vector<Mint> res(n);\n\
    \    for(int i = 0; i < n; i++)\n      res[i] = data[n + i].empty() ? 0 : data[n\
    \ + i][0];\n    return res;\n  }\n\n  static vector<Mint> interpolate(vector<Mint>\
    \ xs, vector<Mint> ys) {\n    assert(ssize(xs) == ssize(ys));\n    int n = ssize(xs);\n\
    \    vector<FPS> data(2 * n), res(2 * n);\n    for(int i = 0; i < n; i++)\n  \
    \    data[n + i] = {-xs[i], 1};\n    for(int i = n - 1; i > 0; i--)\n      data[i]\
    \ = data[i << 1] * data[i << 1 | 1];\n    res[1] = data[1].derivative().div(data[1])[1];\n\
    \    for(int i = 1; i < n; i++) {\n      res[i << 1] = res[i].div(data[i << 1])[1];\n\
    \      res[i << 1 | 1] = res[i].div(data[i << 1 | 1])[1];\n    }\n    for(int\
    \ i = 0; i < n; i++)\n      res[n + i][0] = ys[i] / res[n + i][0];\n    for(int\
    \ i = n - 1; i > 0; i--)\n      res[i] = res[i << 1] * data[i << 1 | 1] + res[i\
    \ << 1 | 1] * data[i << 1];\n    return res[1];\n  }\n\n  static vector<Mint>\
    \ allProd(vector<FPS> &fs) {\n    if (fs.empty()) return {1};\n    auto dfs =\
    \ [&](int l, int r, auto self) -> FPS {\n      if (l + 1 == r)\n        return\
    \ fs[l];\n      else\n        return self(l, (l + r) / 2, self) * self((l + r)\
    \ / 2, r, self);\n    };\n    return dfs(0, ssize(fs), dfs);\n  }\n\n  friend\
    \ FPS operator+(FPS a, FPS b) { return a += b; }\n  friend FPS operator-(FPS a,\
    \ FPS b) { return a -= b; }\n  friend FPS operator*(FPS a, FPS b) { return a *=\
    \ b; }\n  friend FPS operator*(FPS a, Mint b) { return a *= b; }\n  friend FPS\
    \ operator/(FPS a, Mint b) { return a /= b; }\n};\n\nNTT ntt;\nusing fps = FPS<mint>;\n\
    template<>\nfunction<vector<mint>(vector<mint>, vector<mint>)> fps::conv = ntt.conv;\n\
    #line 1 \"misc/sharpPSubsetSum.cpp\"\n//#include<modint/MontgomeryModInt>\n//#include<poly/NTTmint>\n\
    //#include<poly/FPS>\n\ntemplate<class Mint>\nFPS<Mint> sharpPSubsetSum(vector<int>\
    \ w, int C) {\n  vector<int> freq(C + 1);\n  for(int x : w)\n    if (x <= C)\n\
    \      freq[x]++;\n\n  vector<Mint> Inv(C + 1);\n  Inv[1] = 1;\n  for(int i =\
    \ 2; i < ssize(Inv); i++)\n    Inv[i] = (Mint::get_mod() - Mint::get_mod() / i)\
    \ * Inv[Mint::get_mod() % i];\n\n  FPS<Mint> f(C + 1);\n  for(int i = 1; i <=\
    \ C; i++)\n    for(int j = 1; j * i <= C; j++)\n      f[j * i] += freq[i] * Inv[j]\
    \ * (j % 2 == 0 ? -1 : 1);\n\n  return f.exp(C + 1);\n}\n#line 8 \"test/sharp_p_subset_sum.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ t; cin >> n >> t;\n  vector<int> w(n);\n  for(int &x : w)\n    cin >> x;\n\n\
    \  auto f = sharpPSubsetSum<mint>(w, t);\n  f.erase(f.begin());\n  cout << f <<\
    \ '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sharp_p_subset_sum\"\n\n\
    #include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\n#include\
    \ \"../poly/NTTmint.cpp\"\n#include \"../poly/FPS.cpp\"\n#include \"../misc/sharpPSubsetSum.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ t; cin >> n >> t;\n  vector<int> w(n);\n  for(int &x : w)\n    cin >> x;\n\n\
    \  auto f = sharpPSubsetSum<mint>(w, t);\n  f.erase(f.begin());\n  cout << f <<\
    \ '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/MontgomeryModInt.cpp
  - poly/NTTmint.cpp
  - poly/FPS.cpp
  - misc/sharpPSubsetSum.cpp
  isVerificationFile: true
  path: test/sharp_p_subset_sum.test.cpp
  requiredBy: []
  timestamp: '2024-03-16 18:32:12+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/sharp_p_subset_sum.test.cpp
layout: document
redirect_from:
- /verify/test/sharp_p_subset_sum.test.cpp
- /verify/test/sharp_p_subset_sum.test.cpp.html
title: test/sharp_p_subset_sum.test.cpp
---
