---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution.test.cpp
    title: test/convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution_1e9+7.test.cpp
    title: test/convolution_1e9+7.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/determinant_of_matrix.test.cpp
    title: test/determinant_of_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/division_of_polynomials.test.cpp
    title: test/division_of_polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/exp_of_formal_power_series.test.cpp
    title: test/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/find_linear_recurrence.test.cpp
    title: test/find_linear_recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/inv_of_formal_power_series.test.cpp
    title: test/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/inv_of_formal_power_series_sparse.test.cpp
    title: test/inv_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/inverse_matrix.test.cpp
    title: test/inverse_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/log_of_formal_power_series.test.cpp
    title: test/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix_product.test.cpp
    title: test/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/multipoint_evaluation.test.cpp
    title: test/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/point_set_range_composite.test.cpp
    title: test/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial_interpolation.test.cpp
    title: test/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/pow_of_formal_power_series.test.cpp
    title: test/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/pow_of_matrix.test.cpp
    title: test/pow_of_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/range_affine_point_get.test.cpp
    title: test/range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/range_affine_range_sum.test.cpp
    title: test/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/sqrt_of_formal_power_series.test.cpp
    title: test/sqrt_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/subset_convolution.test.cpp
    title: test/subset_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki_2613.test.cpp
    title: test/yuki_2613.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10
  bundledCode: "#line 1 \"modint/MontgomeryModInt.cpp\"\n//reference: https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10\n\
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
    \ is;\n  }\n};\n\nusing mint = MontgomeryModInt<998244353>;\n"
  code: "//reference: https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10\n\
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
    \ is;\n  }\n};\n\nusing mint = MontgomeryModInt<998244353>;\n"
  dependsOn: []
  isVerificationFile: false
  path: modint/MontgomeryModInt.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/pow_of_formal_power_series.test.cpp
  - test/range_affine_point_get.test.cpp
  - test/pow_of_matrix.test.cpp
  - test/determinant_of_matrix.test.cpp
  - test/inverse_matrix.test.cpp
  - test/kth_term_of_linearly_recurrent_sequence.test.cpp
  - test/inv_of_formal_power_series_sparse.test.cpp
  - test/subset_convolution.test.cpp
  - test/range_affine_range_sum.test.cpp
  - test/convolution.test.cpp
  - test/matrix_product.test.cpp
  - test/division_of_polynomials.test.cpp
  - test/yuki_2613.test.cpp
  - test/exp_of_formal_power_series.test.cpp
  - test/polynomial_interpolation.test.cpp
  - test/sqrt_of_formal_power_series.test.cpp
  - test/log_of_formal_power_series.test.cpp
  - test/inv_of_formal_power_series.test.cpp
  - test/point_set_range_composite.test.cpp
  - test/find_linear_recurrence.test.cpp
  - test/multipoint_evaluation.test.cpp
  - test/convolution_1e9+7.test.cpp
documentation_of: modint/MontgomeryModInt.cpp
layout: document
redirect_from:
- /library/modint/MontgomeryModInt.cpp
- /library/modint/MontgomeryModInt.cpp.html
title: modint/MontgomeryModInt.cpp
---