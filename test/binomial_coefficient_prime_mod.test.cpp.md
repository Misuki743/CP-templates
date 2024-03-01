---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: combi/binom.cpp
    title: combi/binom.cpp
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: modint/mintAnyMod.cpp
    title: modint/mintAnyMod.cpp
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
    \ s)\n    os << x << ' ';\n  return os;\n}\n#line 1 \"modint/mintAnyMod.cpp\"\n\
    //note: inversion only works when MOD is a prime\n\nstruct mint {\n  static long\
    \ long MOD;\n  long long _val;\n\n  mint(long long init = 0) {\n    _val = init\
    \ % MOD;\n    (*this).norm();\n  }\n\n  mint POW(long long index) {\n    if (index\
    \ == 0)\n      return mint(1ll);\n    mint base = *this;\n    mint res = (base\
    \ == 0ll ? 0ll : 1ll);\n    while(index) {\n      if (index & 1)\n        res\
    \ *= base;\n      base *= base, index >>= 1;\n    }\n    return res;\n  }\n\n\
    \  mint inv() { return (*this).POW(MOD - 2); }\n\n  mint& norm() {\n    if (_val\
    \ >= MOD)\n      _val -= MOD;\n    if (_val < 0)\n      _val += MOD;\n    return\
    \ *this;\n  }\n\n  mint& operator+=(mint b) {\n    _val += b._val;\n    return\
    \ (*this).norm();\n  }\n  mint& operator-=(mint b) {\n    _val -= b._val;\n  \
    \  return (*this).norm();\n  }\n  mint& operator*=(mint b) {\n    _val = (_val\
    \ * b._val) % MOD;\n    return *this;\n  }\n  mint& operator/=(mint b) {\n   \
    \ _val = (_val * b.inv()._val) % MOD;\n    return *this;\n  }\n\n  mint& operator++()\
    \ {\n    _val += 1;\n    return (*this).norm();\n  }\n  mint& operator--() {\n\
    \    _val -= 1;\n    return (*this).norm();\n  }\n  mint operator++(signed) {\n\
    \    mint tmp = *this;\n    ++(*this);\n    return tmp;\n  }\n  mint operator--(signed)\
    \ {\n    mint tmp = *this;\n    --(*this);\n    return tmp;\n  }\n\n  mint operator-()\
    \ { return mint(-_val); }\n  bool operator==(mint b) { return _val == b._val;\
    \ }\n  bool operator!=(mint b) { return _val != b._val; }\n  \n  friend mint operator+(mint\
    \ a, mint b) { return a += b; }\n  friend mint operator-(mint a, mint b) { return\
    \ a -= b; }\n  friend mint operator*(mint a, mint b) { return a *= b; }\n  friend\
    \ mint operator/(mint a, mint b) { return a /= b; }\n\n  friend ostream& operator<<(ostream&\
    \ os, const mint& b) {\n    return os << b._val;\n  }\n  friend istream& operator>>(istream&\
    \ is, mint& b) {\n    long long val;\n    is >> val;\n    b = mint(val);\n   \
    \ return is;\n  }\n};\n#line 1 \"combi/binom.cpp\"\ntemplate<class Mint>\nstruct\
    \ binomial {\n  vector<Mint> _fac, _facInv;\n  binomial(int size) : _fac(size),\
    \ _facInv(size) {\n    _fac[0] = 1;\n    for(int i = 1; i < size; i++)\n     \
    \ _fac[i] = _fac[i - 1] * i;\n    if (size > 0)\n      _facInv.back() = 1 / _fac.back();\n\
    \    for(int i = size - 2; i >= 0; i--)\n      _facInv[i] = _facInv[i + 1] * (i\
    \ + 1);\n  }\n\n  Mint fac(int i) { return i < 0 ? 0 : _fac[i]; }\n  Mint faci(int\
    \ i) { return i < 0 ? 0 : _facInv[i]; }\n  Mint binom(int n, int r) { return r\
    \ < 0 or n < r ? 0 : fac(n) * faci(r) * faci(n - r); }\n};\n#line 6 \"test/binomial_coefficient_prime_mod.test.cpp\"\
    \n\nll mint::MOD;\n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\
    \n  int t; cin >> t >> mint::MOD;\n  binomial<mint> bn(min(mint::MOD, 10000000ll));\n\
    \  while(t--) {\n    int n, k; cin >> n >> k;\n    cout << bn.binom(n, k) << '\\\
    n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../modint/mintAnyMod.cpp\"\n#include\
    \ \"../combi/binom.cpp\"\n\nll mint::MOD;\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int t; cin >> t >> mint::MOD;\n  binomial<mint> bn(min(mint::MOD,\
    \ 10000000ll));\n  while(t--) {\n    int n, k; cin >> n >> k;\n    cout << bn.binom(n,\
    \ k) << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - modint/mintAnyMod.cpp
  - combi/binom.cpp
  isVerificationFile: true
  path: test/binomial_coefficient_prime_mod.test.cpp
  requiredBy: []
  timestamp: '2024-03-02 02:00:27+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/binomial_coefficient_prime_mod.test.cpp
layout: document
redirect_from:
- /verify/test/binomial_coefficient_prime_mod.test.cpp
- /verify/test/binomial_coefficient_prime_mod.test.cpp.html
title: test/binomial_coefficient_prime_mod.test.cpp
---
