---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/binomial_coefficient_prime_mod.test.cpp
    title: test/binomial_coefficient_prime_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/stirling_number_of_first_kind_small_p_large_n.test.cpp
    title: test/stirling_number_of_first_kind_small_p_large_n.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/stirling_number_of_second_kind_small_p_large_n.test.cpp
    title: test/stirling_number_of_second_kind_small_p_large_n.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"modint/dynamicSimpleMint.cpp\"\ntemplate<uint32_t ver>\n\
    struct simpleMint {\n  using mint = simpleMint;\n  using u32 = uint32_t;\n  using\
    \ u64 = uint64_t;\n\n  static u32 mod;\n\n  static constexpr u32 get_mod() { return\
    \ mod; }\n  static void set_mod(u32 _mod) { mod = _mod; }\n\n  simpleMint() :\
    \ a(0) {}\n  simpleMint(const int64_t &b) : a((b % mod + mod) % mod) {}\n\n  u32\
    \ a;\n\n  mint pow(u64 k) const {\n    mint res(1), base(*this);\n    while(k)\
    \ {\n      if (k & 1)\n        res *= base;\n      base *= base, k >>= 1;\n  \
    \  }\n    return res;\n  }\n\n  mint inverse() const { return (*this).pow(mod\
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
    \ simpleMint<0>::mod = 2;\nusing mint = simpleMint<0>;\n"
  code: "template<uint32_t ver>\nstruct simpleMint {\n  using mint = simpleMint;\n\
    \  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static u32 mod;\n\n  static\
    \ constexpr u32 get_mod() { return mod; }\n  static void set_mod(u32 _mod) { mod\
    \ = _mod; }\n\n  simpleMint() : a(0) {}\n  simpleMint(const int64_t &b) : a((b\
    \ % mod + mod) % mod) {}\n\n  u32 a;\n\n  mint pow(u64 k) const {\n    mint res(1),\
    \ base(*this);\n    while(k) {\n      if (k & 1)\n        res *= base;\n     \
    \ base *= base, k >>= 1;\n    }\n    return res;\n  }\n\n  mint inverse() const\
    \ { return (*this).pow(mod - 2); }\n  u32 get() const { return a; }\n\n  mint&\
    \ norm() {\n    a = (a >= mod ? a - mod : a < 0 ? a + mod : a);\n    return *this;\n\
    \  }\n\n  mint& operator+=(mint b) {\n    a += b.a;\n    return (*this).norm();\n\
    \  }\n  mint& operator-=(mint b) {\n    a -= b.a;\n    return (*this).norm();\n\
    \  }\n  mint& operator*=(mint b) {\n    a = (u64(a) * b.a) % mod;\n    return\
    \ *this;\n  }\n  mint& operator/=(mint b) {\n    a = (u64(a) * b.inverse().a)\
    \ % mod;\n    return *this;\n  }\n\n  mint operator-() { return mint() - mint(*this);\
    \ }\n  bool operator==(mint b) { return a == b.a; }\n  bool operator!=(mint b)\
    \ { return a != b.a; }\n  \n  friend mint operator+(mint c, mint d) { return c\
    \ += d; }\n  friend mint operator-(mint c, mint d) { return c -= d; }\n  friend\
    \ mint operator*(mint c, mint d) { return c *= d; }\n  friend mint operator/(mint\
    \ c, mint d) { return c /= d; }\n\n  friend ostream& operator<<(ostream& os, const\
    \ mint& b) {\n    return os << b.a;\n  }\n  friend istream& operator>>(istream&\
    \ is, mint& b) {\n    int64_t val;\n    is >> val;\n    b = mint(val);\n    return\
    \ is;\n  }\n};\n\ntemplate<> uint32_t simpleMint<0>::mod = 2;\nusing mint = simpleMint<0>;\n"
  dependsOn: []
  isVerificationFile: false
  path: modint/dynamicSimpleMint.cpp
  requiredBy: []
  timestamp: '2025-01-18 19:29:37+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/binomial_coefficient_prime_mod.test.cpp
  - test/stirling_number_of_second_kind_small_p_large_n.test.cpp
  - test/stirling_number_of_first_kind_small_p_large_n.test.cpp
documentation_of: modint/dynamicSimpleMint.cpp
layout: document
redirect_from:
- /library/modint/dynamicSimpleMint.cpp
- /library/modint/dynamicSimpleMint.cpp.html
title: modint/dynamicSimpleMint.cpp
---
