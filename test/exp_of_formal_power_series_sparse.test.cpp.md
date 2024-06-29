---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: combi/binom.cpp
    title: combi/binom.cpp
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':question:'
    path: modint/MontgomeryModInt.cpp
    title: modint/MontgomeryModInt.cpp
  - icon: ':question:'
    path: numtheory/sqrtMod.cpp
    title: numtheory/sqrtMod.cpp
  - icon: ':question:'
    path: poly/FPS.cpp
    title: poly/FPS.cpp
  - icon: ':question:'
    path: poly/NTTmint.cpp
    title: poly/NTTmint.cpp
  - icon: ':question:'
    path: poly/sparsePolyope.cpp
    title: poly/sparsePolyope.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/exp_of_formal_power_series_sparse
    links:
    - https://judge.yosupo.jp/problem/exp_of_formal_power_series_sparse
  bundledCode: "#line 1 \"test/exp_of_formal_power_series_sparse.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/exp_of_formal_power_series_sparse\"\
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
    \ntemplate<ranges::forward_range rng, class T = ranges::range_value_t<rng>, class\
    \ OP = plus<T>>\nvoid pSum(rng &&v) {\n  if (!v.empty())\n    for(T p = v[0];\
    \ T &x : v | views::drop(1))\n      x = p = OP()(p, x);\n}\ntemplate<ranges::forward_range\
    \ rng, class T = ranges::range_value_t<rng>, class OP>\nvoid pSum(rng &&v, OP\
    \ op) {\n  if (!v.empty())\n    for(T p = v[0]; T &x : v | views::drop(1))\n \
    \     x = p = op(p, x);\n}\ntemplate<class T>\nT floorDiv(T a, T b) {\n  if (b\
    \ < 0) a *= -1, b *= -1;\n  return a >= 0 ? a / b : (a - b + 1) / b;\n}\ntemplate<class\
    \ T>\nT ceilDiv(T a, T b) {\n  if (b < 0) a *= -1, b *= -1;\n  return a >= 0 ?\
    \ (a + b - 1) / b : a / b;\n}\ntemplate<class T>\nostream& operator<<(ostream&\
    \ os, const pair<T, T> pr) {\n  return os << pr.first << ' ' << pr.second;\n}\n\
    template<class T, size_t N>\nostream& operator<<(ostream& os, const array<T, N>\
    \ &arr) {\n  for(const T &X : arr)\n    os << X << ' ';\n  return os;\n}\ntemplate<class\
    \ T>\nostream& operator<<(ostream& os, const vector<T> &vec) {\n  for(const T\
    \ &X : vec)\n    os << X << ' ';\n  return os;\n}\ntemplate<class T>\nostream&\
    \ operator<<(ostream& os, const set<T> &s) {\n  for(const T &x : s)\n    os <<\
    \ x << ' ';\n  return os;\n}\n#line 1 \"modint/MontgomeryModInt.cpp\"\n//reference:\
    \ https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10\n\
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
    \ \"modint/MontgomeryModInt.cpp\"\n//#include \"poly/NTTmint.cpp\"\n\n//lagrange\
    \ inversion formula:\n//  let f(x) be composition inverse of g(x) (i.e. f(g(x))\
    \ = x) and [x^0]f(x) = [x^0]g(x) = 0, [x^1]f(x) != 0, [x^1]g(x) != 0, then\n//\
    \  [x^n]g(x)^k = k/n [x^{n - k}] (x / f(x))^n\n//  [x^n]g(x) = 1/n [x^{n - 1}]\
    \ (x / f(x))^n (for k = 1)\n\ntemplate<class Mint>\nstruct FPS : vector<Mint>\
    \ {\n\n  static function<void(vector<Mint>&, bool)> dft;\n  static function<vector<Mint>(vector<Mint>,\
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
    \ *= b;\n    return *this;\n  }\n\n  FPS& operator<<=(int x) {\n    this -> resize(ssize(*this)\
    \ + x, Mint(0));\n    ranges::rotate(*this, this -> end() - x);\n    return *this;\n\
    \  }\n\n  FPS& operator>>=(int x) {\n    if (x >= ssize(*this)) {\n      this\
    \ -> resize(1);\n      (*this)[0] = 0;\n    } else {\n      ranges::rotate(*this,\
    \ this -> begin() + x);\n      this -> resize(ssize(*this) - x);\n    }\n    return\
    \ *this;\n  }\n\n  FPS shrink() {\n    FPS F = *this;\n    int size = ssize(F);\n\
    \    while(size and F[size - 1] == 0) size -= 1;\n    F.resize(size);\n    return\
    \ F;\n  }\n\n  FPS integral() {\n    if (this -> empty()) return {0};\n    vector<Mint>\
    \ Inv(ssize(*this) + 1);\n    Inv[1] = 1;\n    for(int i = 2; i < ssize(Inv);\
    \ i++)\n      Inv[i] = (Mint::get_mod() - Mint::get_mod() / i) * Inv[Mint::get_mod()\
    \ % i];\n    FPS Q(ssize(*this) + 1, 0);\n    for(int i = 0; i < ssize(*this);\
    \ i++)\n      Q[i + 1] = (*this)[i] * Inv[i + 1];\n    return Q;\n  }\n\n  FPS\
    \ derivative() {\n    assert(!this -> empty());\n    FPS Q(ssize(*this) - 1);\n\
    \    for(int i = 1; i < ssize(*this); i++)\n      Q[i - 1] = (*this)[i] * i;\n\
    \    return Q;\n  }\n\n  Mint eval(Mint x) {\n    Mint base = 1, res = 0;\n  \
    \  for(int i = 0; i < ssize(*this); i++, base *= x)\n      res += (*this)[i] *\
    \ base;\n    return res;\n  }\n\n  FPS inv(int k) { // 1 / FPS (mod x^k)\n   \
    \ assert(!this -> empty() and (*this)[0] != 0);\n    FPS Q(1, 1 / (*this)[0]);\n\
    \    for(int i = 1; (1 << (i - 1)) < k; i++) {\n      FPS P = (*this);\n     \
    \ P.resize(1 << i, 0);\n      Q = Q * (FPS(1, 2) - P * Q);\n      Q.resize(1 <<\
    \ i, 0);\n    }\n    Q.resize(k);\n    return Q;\n  }\n\n  array<FPS, 2> div(FPS\
    \ G) {\n    FPS F = this -> shrink();\n    G = G.shrink();\n    assert(!G.empty());\n\
    \    if (ssize(G) > ssize(F))\n      return {{{}, F}};\n    int n = ssize(F) -\
    \ ssize(G) + 1;\n    auto FR = F, GR = G;\n    ranges::reverse(FR);\n    ranges::reverse(GR);\n\
    \    FPS Q = FR * GR.inv(n);\n    Q.resize(n);\n    ranges::reverse(Q);\n    return\
    \ {Q, (F - G * Q).shrink()};\n  }\n\n  FPS log(int k) {\n    assert(!this -> empty()\
    \ and (*this)[0] == 1);\n    FPS Q = *this;\n    Q = (Q.derivative() * Q.inv(k));\n\
    \    Q.resize(k - 1);\n    return Q.integral();\n  }\n\n  FPS exp(int k) {\n \
    \   assert(!this -> empty() and (*this)[0] == 0);\n    FPS Q(1, 1);\n    for(int\
    \ i = 1; (1 << (i - 1)) < k; i++) {\n      FPS P = (*this);\n      P.resize(1\
    \ << i, 0);\n      Q = Q * (FPS(1, 1) + P - Q.log(1 << i));\n      Q.resize(1\
    \ << i, 0);\n    }\n    Q.resize(k);\n    return Q;\n  }\n\n  FPS pow(ll idx,\
    \ int k) {\n    if (idx == 0) {\n      FPS res(k, 0);\n      res[0] = 1;\n   \
    \   return res;\n    }\n    for(int i = 0; i < ssize(*this) and i * idx < k; i++)\
    \ {\n      if ((*this)[i] != 0) {\n        Mint Inv = 1 / (*this)[i];\n      \
    \  FPS Q(ssize(*this) - i);\n        for(int j = i; j < ssize(*this); j++)\n \
    \         Q[j - i] = (*this)[j] * Inv;\n        Q = (Q.log(k) * idx).exp(k);\n\
    \        FPS Q2(k, 0);\n        Mint Pow = (*this)[i].pow(idx);\n        for(int\
    \ j = 0; j + i * idx < k; j++)\n          Q2[j + i * idx] = Q[j] * Pow;\n    \
    \    return Q2;\n      }\n    } \n    return FPS(k, 0);\n  }\n\n  FPS pow(ll idx)\
    \ {\n    int mxDeg = (ssize(*this) - 1) * idx;\n    FPS a = (*this);\n    a.resize(bit_ceil((unsigned)(mxDeg\
    \ + 1)));\n    dft(a, false);\n    for(Mint &x : a) x = x.pow(idx);\n    dft(a,\
    \ true);\n    return FPS(a.begin(), a.begin() + mxDeg + 1);\n  }\n\n  vector<Mint>\
    \ multieval(vector<Mint> xs) {\n    int n = ssize(xs);\n    vector<FPS> data(2\
    \ * n);\n    for(int i = 0; i < n; i++)\n      data[n + i] = {-xs[i], 1};\n  \
    \  for(int i = n - 1; i > 0; i--)\n      data[i] = data[i << 1] * data[i << 1\
    \ | 1];\n    data[1] = (this -> div(data[1]))[1];\n    for(int i = 1; i < n; i++)\
    \ {\n      data[i << 1] = data[i].div(data[i << 1])[1];\n      data[i << 1 | 1]\
    \ = data[i].div(data[i << 1 | 1])[1];\n    }\n    vector<Mint> res(n);\n    for(int\
    \ i = 0; i < n; i++)\n      res[i] = data[n + i].empty() ? 0 : data[n + i][0];\n\
    \    return res;\n  }\n\n  static vector<Mint> interpolate(vector<Mint> xs, vector<Mint>\
    \ ys) {\n    assert(ssize(xs) == ssize(ys));\n    int n = ssize(xs);\n    vector<FPS>\
    \ data(2 * n), res(2 * n);\n    for(int i = 0; i < n; i++)\n      data[n + i]\
    \ = {-xs[i], 1};\n    for(int i = n - 1; i > 0; i--)\n      data[i] = data[i <<\
    \ 1] * data[i << 1 | 1];\n    res[1] = data[1].derivative().div(data[1])[1];\n\
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
    \ operator/(FPS a, Mint b) { return a /= b; }\n  friend FPS operator<<(FPS a,\
    \ int x) { return a <<= x; }\n  friend FPS operator>>(FPS a, int x) { return a\
    \ >>= x; }\n};\n\nNTT ntt;\nusing fps = FPS<mint>;\ntemplate<>\nfunction<vector<mint>(vector<mint>,\
    \ vector<mint>)> fps::conv = ntt.conv;\ntemplate<>\nfunction<void(vector<mint>&,\
    \ bool)> fps::dft = ntt.ntt;\n#line 1 \"combi/binom.cpp\"\n//#include<modint/MontgomeryModInt.cpp>\n\
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
    \ k);\n    else return Mint(0);\n  }\n};\n#line 1 \"numtheory/sqrtMod.cpp\"\n\
    //source: KACTL\n\nll modpow(ll b, ll e, ll p) {\n  ll ans = 1;\n  for(; e; b\
    \ = b * b % p, e /= 2)\n    if (e & 1) ans = ans * b % p;\n  return ans;\n}\n\n\
    ll sqrt(ll a, ll p) {\n\ta %= p; if (a < 0) a += p;\n\tif (a == 0) return 0;\n\
    \t//assert(modpow(a, (p-1)/2, p) == 1); // else no solution\n  if (modpow(a, (p-1)/2,\
    \ p) != 1) return -1;\n\tif (p % 4 == 3) return modpow(a, (p+1)/4, p);\n\t// a^(n+3)/8\
    \ or 2^(n+3)/8 * 2^(n-1)/4 works if p % 8 == 5\n\tll s = p - 1, n = 2;\n\tint\
    \ r = 0, m;\n\twhile (s % 2 == 0)\n\t\t++r, s /= 2;\n\t/// find a non-square mod\
    \ p\n\twhile (modpow(n, (p - 1) / 2, p) != p - 1) ++n;\n\tll x = modpow(a, (s\
    \ + 1) / 2, p);\n\tll b = modpow(a, s, p), g = modpow(n, s, p);\n\tfor (;; r =\
    \ m) {\n\t\tll t = b;\n\t\tfor (m = 0; m < r && t != 1; ++m)\n\t\t\tt = t * t\
    \ % p;\n\t\tif (m == 0) return x;\n\t\tll gs = modpow(g, 1LL << (r - m - 1), p);\n\
    \t\tg = gs * gs % p;\n\t\tx = x * gs % p;\n\t\tb = b * g % p;\n\t}\n}\n#line 1\
    \ \"poly/sparsePolyope.cpp\"\n//#include<poly/FPS.cpp>\n//#include<poly/NTTmint.cpp>\n\
    //#include<modint/MontgomeryModInt.cpp>\n//#include<combi/binom.cpp>\n//#include<numtheory/sqrtMod.cpp>\n\
    \nnamespace sparsePolyope {\n  template<class Mint>\n  vector<pair<int, Mint>>\
    \ sparsify(FPS<Mint> f) {\n    vector<pair<int, Mint>> g;\n    for(int i = 0;\
    \ i < ssize(f); i++)\n      if (f[i] != 0)\n        g.emplace_back(i, f[i]);\n\
    \    return g;\n  }\n  template<class Mint>\n  FPS<Mint> sparseInv(FPS<Mint> f,\
    \ int k) {\n    assert(f[0] != 0);\n    FPS<Mint> g(k);\n    Mint inv = 1 / f[0];\n\
    \    g[0] = 1;\n    auto fs = sparsify(f);\n    for(int i = 0; i < k; i++) {\n\
    \      for(auto [j, val] : fs | views::drop(1))\n        if (j <= i)\n       \
    \   g[i] -= g[i - j] * val;\n      g[i] *= inv;\n    }\n    return g;\n  }\n \
    \ template<class Mint>\n  FPS<Mint> sparseExp(FPS<Mint> f, int k) {\n    assert(f[0]\
    \ == 0);\n    binomial<Mint> bn(k);\n    FPS<Mint> g(k);\n    g[0] = 1;\n    auto\
    \ fs = sparsify(f);\n    for(auto &[i, val] : fs) val *= i--;\n    for(int i =\
    \ 0; i < k - 1; i++) {\n      for(auto [j, val] : fs)\n        if (j <= i)\n \
    \         g[i + 1] += g[i - j] * val;\n      g[i + 1] *= bn.inv(i + 1);\n    }\n\
    \    return g;\n  }\n  template<class Mint>\n  FPS<Mint> sparseLog(FPS<Mint> f,\
    \ int k) {\n    assert(f[0] == 1);\n    auto invf = sparseInv(f, k);\n    auto\
    \ fs = sparsify(f.derivative());\n    FPS<Mint> g(k - 1);\n    for(int i = 0;\
    \ i < k - 1; i++)\n      for(auto [j, val] : fs)\n        if (j <= i)\n      \
    \    g[i] += invf[i - j] * val;\n    return g.integral();\n  }\n  template<class\
    \ Mint>\n  FPS<Mint> sparsePow(FPS<Mint> f, ll idx, int k) {\n    if (idx == 0)\
    \ {\n      FPS<Mint> g(k);\n      g[0] = 1;\n      return g;\n    } else if (f[0]\
    \ == 0) {\n      for(int i = 0; i < ssize(f) and i * idx < k; i++) {\n       \
    \ if (f[i] != 0) {\n          FPS<Mint> g = sparsePow<Mint>({f.begin() + i, f.end()},\
    \ idx, k - i * idx);\n          g.resize(k);\n          for(int j = k - 1; j >=\
    \ i * idx; j--)\n            swap(g[j], g[j - i * idx]);\n          return g;\n\
    \        }\n      }\n      return FPS<Mint>(k);\n    } else {\n      Mint inv\
    \ = 1 / f[0];\n      vector<Mint> g(k), gd(k - 1);\n      binomial<Mint> bn(k);\n\
    \      g[0] = f[0].pow(idx);\n      auto fs = sparsify(f);\n      auto fds = fs;\n\
    \      fds.erase(fds.begin());\n      for(auto &[i, val] : fds) val *= i--;\n\
    \      for(int i = 0; i < k - 1; i++) {\n        for(auto [j, val] : fds)\n  \
    \        if (j <= i)\n            gd[i] += g[i - j] * val;\n        gd[i] *= idx;\n\
    \        for(auto [j, val] : fs)\n          if (0 < j and j <= i)\n          \
    \  gd[i] -= gd[i - j] * val;\n        gd[i] *= inv;\n        g[i + 1] = gd[i]\
    \ * bn.inv(i + 1);\n      }\n      return g;\n    }\n  }\n  template<class Mint>\n\
    \  FPS<Mint> sparseSqrt(FPS<Mint> f, int k) {\n    if (f[0] == 0) {\n      for(int\
    \ i = 0; i < ssize(f) and i < 2 * k; i++) {\n        if (f[i] != 0) {\n      \
    \    if (i & 1) return FPS<Mint>();\n          FPS<Mint> g = sparseSqrt<Mint>({f.begin()\
    \ + i, f.end()}, k - i / 2);\n          if (g.empty()) return g;\n          g.resize(k);\n\
    \          for(int j = k - 1; j >= i / 2; j--)\n            swap(g[j], g[j - i\
    \ / 2]);\n          return g;\n        }\n      }\n      return FPS<Mint>(k);\n\
    \    } else {\n      Mint inv = 1 / f[0];\n      vector<Mint> g(k), gd(k - 1);\n\
    \      binomial<Mint> bn(k);\n      if (ll x = sqrt(f[0].get(), Mint::get_mod());\
    \ x == -1)\n        return FPS<Mint>();\n      else\n        g[0] = x;\n     \
    \ auto fs = sparsify(f);\n      auto fds = fs;\n      fds.erase(fds.begin());\n\
    \      for(auto &[i, val] : fds) val *= i--;\n      Mint half = Mint(1) / 2;\n\
    \      for(int i = 0; i < k - 1; i++) {\n        for(auto [j, val] : fds)\n  \
    \        if (j <= i)\n            gd[i] += g[i - j] * val;\n        gd[i] *= half;\n\
    \        for(auto [j, val] : fs)\n          if (0 < j and j <= i)\n          \
    \  gd[i] -= gd[i - j] * val;\n        gd[i] *= inv;\n        g[i + 1] = gd[i]\
    \ * bn.inv(i + 1);\n      }\n      return g;\n    }\n  }\n}\n\nusing namespace\
    \ sparsePolyope;\n#line 10 \"test/exp_of_formal_power_series_sparse.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ k; cin >> n >> k;\n  fps f(n);\n  for(int i = 0; i < k; i++) {\n    int j, val;\
    \ cin >> j >> val;\n    f[j] = val;\n  }\n\n  cout << sparseExp(f, n) << '\\n';\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_formal_power_series_sparse\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../poly/NTTmint.cpp\"\n#include \"../poly/FPS.cpp\"\n#include \"\
    ../combi/binom.cpp\"\n#include \"../numtheory/sqrtMod.cpp\"\n#include \"../poly/sparsePolyope.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ k; cin >> n >> k;\n  fps f(n);\n  for(int i = 0; i < k; i++) {\n    int j, val;\
    \ cin >> j >> val;\n    f[j] = val;\n  }\n\n  cout << sparseExp(f, n) << '\\n';\n\
    \n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/MontgomeryModInt.cpp
  - poly/NTTmint.cpp
  - poly/FPS.cpp
  - combi/binom.cpp
  - numtheory/sqrtMod.cpp
  - poly/sparsePolyope.cpp
  isVerificationFile: true
  path: test/exp_of_formal_power_series_sparse.test.cpp
  requiredBy: []
  timestamp: '2024-06-29 18:02:37+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/exp_of_formal_power_series_sparse.test.cpp
layout: document
redirect_from:
- /verify/test/exp_of_formal_power_series_sparse.test.cpp
- /verify/test/exp_of_formal_power_series_sparse.test.cpp.html
title: test/exp_of_formal_power_series_sparse.test.cpp
---
