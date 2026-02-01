---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: misc/bigint.cpp
    title: misc/bigint.cpp
  - icon: ':heavy_check_mark:'
    path: modint/MontgomeryModInt.cpp
    title: modint/MontgomeryModInt.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/addition_of_big_integers
    links:
    - https://judge.yosupo.jp/problem/addition_of_big_integers
  bundledCode: "#line 1 \"test/addition_of_big_integers_2.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/addition_of_big_integers\"\n\n#line 1 \"default/t.cpp\"\
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
    \ < b ? a = b, 1 : 0; }\n\n#line 1 \"modint/MontgomeryModInt.cpp\"\n//reference:\
    \ https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10\n\
    //note: mod should be an odd prime less than 2^30.\n\ntemplate<uint32_t mod>\n\
    struct MontgomeryModInt {\n  using mint = MontgomeryModInt;\n  using i32 = int32_t;\n\
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
    \    a.resize(sz);\n\n    return a;\n  }\n};\n#line 1 \"misc/bigint.cpp\"\n//#include<modint/MontgomeryModInt.cpp>\n\
    //#include<poly/NTTmint.cpp>\n\ntemplate<bool fast_mul = true>\nstruct bigint\
    \ {\n  int sgn;\n  vector<int> val;\n  static constexpr int LOG = fast_mul ? 1\
    \ : 9;\n  static constexpr int W = fast_mul ? 10 : 1'000'000'000;\n\n  bigint(string\
    \ s = \"0\") {\n    if (!s.empty() and s[0] == '-') {\n      sgn = -1;\n     \
    \ s.erase(s.begin());\n    } else {\n      sgn = 1;\n    }\n    s.insert(0, (LOG\
    \ - ssize(s) % LOG) % LOG, '0');\n    if (s.empty()) s = string(LOG, '0');\n \
    \   val.resize(size(s) / LOG);\n    ranges::reverse(s);\n    for(int i = ssize(s)\
    \ - 1; i >= 0; i--)\n      val[i / LOG] = val[i / LOG] * 10 + (s[i] - '0');\n\
    \  }\n\n  int log10() {\n    assert(sgn == 1);\n    int x = LOG * (ssize(val)\
    \ - 1), y = val.back();\n    while(y) x++, y /= 10;\n    return x - 1;\n  }\n\n\
    \  void norm() {\n    if (sgn == -1 and ssize(val) == 1 and val[0] == 0)\n   \
    \   sgn = 1;\n  }\n\n  bool abs_less(const bigint &b) const {\n    if (size(val)\
    \ != size(b.val))\n      return size(val) < size(b.val);\n    for(int i = ssize(val)\
    \ - 1; i >= 0; i--)\n      if (val[i] != b.val[i])\n        return val[i] < b.val[i];\n\
    \    return false;\n  }\n\n  bigint& operator+=(const bigint &b) {\n    if (sgn\
    \ != b.sgn) {\n      *this -= -b;\n    } else if (abs_less(b)) {\n      *this\
    \ = b + *this;\n    } else {\n      for(int i = 0; i < min(ssize(val), ssize(b.val));\
    \ i++) {\n        val[i] += b.val[i];\n        if (int q = val[i] / W; q > 0)\
    \ {\n          if (i + 1 == ssize(val)) val.emplace_back();\n          val[i]\
    \ -= q * W, val[i + 1] += q;\n        }\n      }\n      int j = min(ssize(val),\
    \ ssize(b.val));\n      while(j < ssize(val) and val[j] >= W) {\n        int q\
    \ = val[j] / W;\n        if (j + 1 == ssize(val)) val.emplace_back();\n      \
    \  val[j] -= q * W, val[j + 1] += q, j++;\n      }\n    }\n    norm();\n    return\
    \ *this;\n  }\n\n  bigint& operator-=(const bigint &b) {\n    if (sgn != b.sgn)\
    \ {\n      *this += -b;\n    } else if (abs_less(b)) {\n      *this = b - *this,\
    \ sgn = -sgn;\n    } else {\n      for(int i = 0; i < min(ssize(val), ssize(b.val));\
    \ i++) {\n        val[i] -= b.val[i];\n        if (val[i] < 0)\n          val[i]\
    \ += W, val[i + 1] -= 1;\n      }\n      int j = min(ssize(val), ssize(b.val));\n\
    \      while(j < ssize(val) and val[j] < 0)\n        val[j] += W, val[j + 1] -=\
    \ 1, j++;\n      while(ssize(val) > 1 and val.back() == 0) val.pop_back();\n \
    \   }\n    norm();\n    return *this;\n  }\n\n  bigint& operator*=(const bigint\
    \ &b) {\n    if constexpr (LOG == 1) {\n      static NTT ntt;\n      vector<mint>\
    \ c(size(val)), d(size(b.val));\n      for(int i = 0; i < ssize(c); i++) c[i]\
    \ = val[i];\n      for(int i = 0; i < ssize(d); i++) d[i] = b.val[i];\n      c\
    \ = ntt.conv(c, d);\n      vector<int> tmp(ssize(c));\n      for(int i = 0; i\
    \ < ssize(c); i++)\n        tmp[i] = c[i].get();\n      for(int i = 0; i < ssize(tmp);\
    \ i++) {\n        if (int q = tmp[i] / W; q > 0) {\n          if (i + 1 == ssize(tmp))\
    \ tmp.emplace_back();\n          tmp[i] -= q * W, tmp[i + 1] += q;\n        }\n\
    \      }\n      val.swap(tmp);\n    } else {\n      vector<int> tmp(ssize(val)\
    \ + ssize(b.val) + 1);\n      for(int i = 0; i < ssize(val); i++) {\n        for(int\
    \ j = 0; j < ssize(b.val); j++) {\n          if (int q = tmp[i + j] / W; q > 0)\n\
    \            tmp[i + j] -= q * W, tmp[i + j + 1] += q;\n          ll x = (ll)val[i]\
    \ * b.val[j];\n          tmp[i + j] += x % W, tmp[i + j + 1] += x / W;\n     \
    \     if (int q = tmp[i + j] / W; q > 0)\n            tmp[i + j] -= q * W, tmp[i\
    \ + j + 1] += q;\n        }\n      }\n      val.swap(tmp);\n    }\n    while(ssize(val)\
    \ > 1 and val.back() == 0) val.pop_back();\n    sgn *= b.sgn;\n    norm();\n \
    \   return *this;\n  }\n\n  bool operator<(const bigint &b) const {\n    if (sgn\
    \ != b.sgn) return sgn == -1;\n    else if (sgn == 1) return abs_less(b);\n  \
    \  else return b.abs_less(*this);\n  }\n  bool operator>(const bigint &b) const\
    \ { return b < *this; }\n  bool operator<=(const bigint &b) const { return !(*this\
    \ > b); }\n  bool operator>=(const bigint &b) const { return !(*this < b); }\n\
    \  bool operator==(const bigint &b) const { return sgn == b.sgn and val == b.val;\
    \ }\n  friend bigint operator+(bigint a, bigint b) { return a += b; }\n  friend\
    \ bigint operator-(bigint a, bigint b) { return a -= b; }\n  friend bigint operator*(bigint\
    \ a, bigint b) { return a *= b; }\n\n  bigint operator-() const {\n    bigint\
    \ b = *this;\n    b.sgn = -b.sgn;\n    return b;\n  }\n\n  string to_string()\
    \ const {\n    string s;\n    for(int i = 0; i < ssize(val); i++) {\n      int\
    \ x = val[i];\n      for(int j = 0; j < LOG; j++)\n        s += '0' + (x % 10),\
    \ x /= 10;\n    }\n    while(ssize(s) > 1 and s.back() == '0') s.pop_back();\n\
    \    if (sgn == -1) s += '-';\n    ranges::reverse(s);\n    return s;\n  }\n\n\
    \  friend ostream& operator<<(ostream& os, const bigint& b) {\n    return os <<\
    \ b.to_string();\n  }\n};\n#line 7 \"test/addition_of_big_integers_2.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int t;\
    \ cin >> t;\n  while(t--) {\n    string a, b; cin >> a >> b;\n    bigint<false>\
    \ A(a), B(b);\n    cout << A + B << '\\n';\n  }\n\n  return 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/addition_of_big_integers\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/MontgomeryModInt.cpp\"\
    \n#include \"../poly/NTTmint.cpp\"\n#include \"../misc/bigint.cpp\"\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int t; cin >> t;\n\
    \  while(t--) {\n    string a, b; cin >> a >> b;\n    bigint<false> A(a), B(b);\n\
    \    cout << A + B << '\\n';\n  }\n\n  return 0;\n}\n\n"
  dependsOn:
  - default/t.cpp
  - modint/MontgomeryModInt.cpp
  - poly/NTTmint.cpp
  - misc/bigint.cpp
  isVerificationFile: true
  path: test/addition_of_big_integers_2.test.cpp
  requiredBy: []
  timestamp: '2026-01-31 03:10:37+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/addition_of_big_integers_2.test.cpp
layout: document
redirect_from:
- /verify/test/addition_of_big_integers_2.test.cpp
- /verify/test/addition_of_big_integers_2.test.cpp.html
title: test/addition_of_big_integers_2.test.cpp
---
