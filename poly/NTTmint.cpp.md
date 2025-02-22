---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/addition_of_big_integers.test.cpp
    title: test/addition_of_big_integers.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/addition_of_big_integers_2.test.cpp
    title: test/addition_of_big_integers_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/bell_number.test.cpp
    title: test/bell_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/bernoulli_number.test.cpp
    title: test/bernoulli_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/compositional_inverse_of_formal_power_series_large.test.cpp
    title: test/compositional_inverse_of_formal_power_series_large.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution.test.cpp
    title: test/convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution_1e9+7.test.cpp
    title: test/convolution_1e9+7.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/division_of_polynomials.test.cpp
    title: test/division_of_polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/exp_of_formal_power_series.test.cpp
    title: test/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/exp_of_formal_power_series_sparse.test.cpp
    title: test/exp_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/inv_of_formal_power_series.test.cpp
    title: test/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/inv_of_formal_power_series_sparse.test.cpp
    title: test/inv_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/log_of_formal_power_series.test.cpp
    title: test/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/log_of_formal_power_series_sparse.test.cpp
    title: test/log_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mul_modp_convolution.test.cpp
    title: test/mul_modp_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/multiplication_of_big_intergers.test.cpp
    title: test/multiplication_of_big_intergers.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/multiplication_of_big_intergers_2.test.cpp
    title: test/multiplication_of_big_intergers_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/multipoint_evaluation.test.cpp
    title: test/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial_interpolation.test.cpp
    title: test/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial_taylor_shift.test.cpp
    title: test/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/pow_of_formal_power_series.test.cpp
    title: test/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/pow_of_formal_power_series_sparse.test.cpp
    title: test/pow_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/product_of_polynomial_sequence.test.cpp
    title: test/product_of_polynomial_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/sharp_p_subset_sum.test.cpp
    title: test/sharp_p_subset_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/sqrt_of_formal_power_series.test.cpp
    title: test/sqrt_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/sqrt_of_formal_power_series_sparse.test.cpp
    title: test/sqrt_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/stirling_number_of_the_first_kind.test.cpp
    title: test/stirling_number_of_the_first_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/stirling_number_of_the_second_kind.test.cpp
    title: test/stirling_number_of_the_second_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/subset_convolution.test.cpp
    title: test/subset_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/wildcard_pattern_matching.test.cpp
    title: test/wildcard_pattern_matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki_2544.test.cpp
    title: test/yuki_2544.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki_2613.test.cpp
    title: test/yuki_2613.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://judge.yosupo.jp/submission/69896
  bundledCode: "#line 1 \"poly/NTTmint.cpp\"\n//reference: https://judge.yosupo.jp/submission/69896\n\
    //remark: MOD = 2^K * C + 1, R is a primitive root modulo MOD\n//remark: a.size()\
    \ <= 2^K must be satisfied\n//some common modulo: 998244353  = 2^23 * 119 + 1,\
    \ R = 3\n//                    469762049  = 2^26 * 7   + 1, R = 3\n//        \
    \            1224736769 = 2^24 * 73  + 1, R = 3\n\ntemplate<int32_t k = 23, int32_t\
    \ c = 119, int32_t r = 3, class Mint = MontgomeryModInt<998244353>>\nstruct NTT\
    \ {\n\n  using u32 = uint32_t;\n  static constexpr u32 mod = (1 << k) * c + 1;\n\
    \  static constexpr u32 get_mod() { return mod; }\n\n  static void ntt(vector<Mint>\
    \ &a, bool inverse) {\n    static array<Mint, 30> w, w_inv;\n    if (w[0] == 0)\
    \ {\n      Mint root = 2;\n      while(root.pow((mod - 1) / 2) == 1) root += 1;\n\
    \      for(int i = 0; i < 30; i++)\n        w[i] = -(root.pow((mod - 1) >> (i\
    \ + 2))), w_inv[i] = 1 / w[i];\n    }\n    int n = ssize(a);\n    if (not inverse)\
    \ {\n      for(int m = n; m >>= 1; ) {\n        Mint ww = 1;\n        for(int\
    \ s = 0, l = 0; s < n; s += 2 * m) {\n          for(int i = s, j = s + m; i <\
    \ s + m; i++, j++) {\n            Mint x = a[i], y = a[j] * ww;\n            a[i]\
    \ = x + y, a[j] = x - y;\n          }\n          ww *= w[__builtin_ctz(++l)];\n\
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
    \  }\n};\n"
  code: "//reference: https://judge.yosupo.jp/submission/69896\n//remark: MOD = 2^K\
    \ * C + 1, R is a primitive root modulo MOD\n//remark: a.size() <= 2^K must be\
    \ satisfied\n//some common modulo: 998244353  = 2^23 * 119 + 1, R = 3\n//    \
    \                469762049  = 2^26 * 7   + 1, R = 3\n//                    1224736769\
    \ = 2^24 * 73  + 1, R = 3\n\ntemplate<int32_t k = 23, int32_t c = 119, int32_t\
    \ r = 3, class Mint = MontgomeryModInt<998244353>>\nstruct NTT {\n\n  using u32\
    \ = uint32_t;\n  static constexpr u32 mod = (1 << k) * c + 1;\n  static constexpr\
    \ u32 get_mod() { return mod; }\n\n  static void ntt(vector<Mint> &a, bool inverse)\
    \ {\n    static array<Mint, 30> w, w_inv;\n    if (w[0] == 0) {\n      Mint root\
    \ = 2;\n      while(root.pow((mod - 1) / 2) == 1) root += 1;\n      for(int i\
    \ = 0; i < 30; i++)\n        w[i] = -(root.pow((mod - 1) >> (i + 2))), w_inv[i]\
    \ = 1 / w[i];\n    }\n    int n = ssize(a);\n    if (not inverse) {\n      for(int\
    \ m = n; m >>= 1; ) {\n        Mint ww = 1;\n        for(int s = 0, l = 0; s <\
    \ n; s += 2 * m) {\n          for(int i = s, j = s + m; i < s + m; i++, j++) {\n\
    \            Mint x = a[i], y = a[j] * ww;\n            a[i] = x + y, a[j] = x\
    \ - y;\n          }\n          ww *= w[__builtin_ctz(++l)];\n        }\n     \
    \ }\n    } else {\n      for(int m = 1; m < n; m *= 2) {\n        Mint ww = 1;\n\
    \        for(int s = 0, l = 0; s < n; s += 2 * m) {\n          for(int i = s,\
    \ j = s + m; i < s + m; i++, j++) {\n            Mint x = a[i], y = a[j];\n  \
    \          a[i] = x + y, a[j] = (x - y) * ww;\n          }\n          ww *= w_inv[__builtin_ctz(++l)];\n\
    \        }\n      }\n      Mint inv = 1 / Mint(n);\n      for(Mint &x : a) x *=\
    \ inv;\n    }\n  }\n\n  static vector<Mint> conv(vector<Mint> a, vector<Mint>\
    \ b) {\n    int sz = ssize(a) + ssize(b) - 1;\n    int n = bit_ceil((u32)sz);\n\
    \n    a.resize(n, 0);\n    ntt(a, false);\n    b.resize(n, 0);\n    ntt(b, false);\n\
    \n    for(int i = 0; i < n; i++)\n      a[i] *= b[i];\n\n    ntt(a, true);\n\n\
    \    a.resize(sz);\n\n    return a;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/NTTmint.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution_1e9+7.test.cpp
  - test/log_of_formal_power_series_sparse.test.cpp
  - test/wildcard_pattern_matching.test.cpp
  - test/bernoulli_number.test.cpp
  - test/sqrt_of_formal_power_series_sparse.test.cpp
  - test/bell_number.test.cpp
  - test/division_of_polynomials.test.cpp
  - test/addition_of_big_integers_2.test.cpp
  - test/log_of_formal_power_series.test.cpp
  - test/yuki_2544.test.cpp
  - test/convolution.test.cpp
  - test/stirling_number_of_the_second_kind.test.cpp
  - test/multiplication_of_big_intergers_2.test.cpp
  - test/subset_convolution.test.cpp
  - test/pow_of_formal_power_series.test.cpp
  - test/sharp_p_subset_sum.test.cpp
  - test/compositional_inverse_of_formal_power_series_large.test.cpp
  - test/product_of_polynomial_sequence.test.cpp
  - test/exp_of_formal_power_series.test.cpp
  - test/kth_term_of_linearly_recurrent_sequence.test.cpp
  - test/polynomial_interpolation.test.cpp
  - test/pow_of_formal_power_series_sparse.test.cpp
  - test/exp_of_formal_power_series_sparse.test.cpp
  - test/multiplication_of_big_intergers.test.cpp
  - test/stirling_number_of_the_first_kind.test.cpp
  - test/sqrt_of_formal_power_series.test.cpp
  - test/yuki_2613.test.cpp
  - test/polynomial_taylor_shift.test.cpp
  - test/inv_of_formal_power_series.test.cpp
  - test/inv_of_formal_power_series_sparse.test.cpp
  - test/addition_of_big_integers.test.cpp
  - test/multipoint_evaluation.test.cpp
  - test/mul_modp_convolution.test.cpp
documentation_of: poly/NTTmint.cpp
layout: document
redirect_from:
- /library/poly/NTTmint.cpp
- /library/poly/NTTmint.cpp.html
title: poly/NTTmint.cpp
---
