---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/exp_of_formal_power_series_sparse.test.cpp
    title: test/exp_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/inv_of_formal_power_series_sparse.test.cpp
    title: test/inv_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/log_of_formal_power_series_sparse.test.cpp
    title: test/log_of_formal_power_series_sparse.test.cpp
  - icon: ':x:'
    path: test/pow_of_formal_power_series_sparse.test.cpp
    title: test/pow_of_formal_power_series_sparse.test.cpp
  - icon: ':x:'
    path: test/sqrt_of_formal_power_series.test.cpp
    title: test/sqrt_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/sqrt_of_formal_power_series_sparse.test.cpp
    title: test/sqrt_of_formal_power_series_sparse.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/sqrtMod.cpp\"\n//source: KACTL\n\nll modpow(ll\
    \ b, ll e, ll p) {\n  ll ans = 1;\n  for(; e; b = b * b % p, e /= 2)\n    if (e\
    \ & 1) ans = ans * b % p;\n  return ans;\n}\n\nll sqrt(ll a, ll p) {\n\ta %= p;\
    \ if (a < 0) a += p;\n\tif (a == 0) return 0;\n\t//assert(modpow(a, (p-1)/2, p)\
    \ == 1); // else no solution\n  if (modpow(a, (p-1)/2, p) != 1) return -1;\n\t\
    if (p % 4 == 3) return modpow(a, (p+1)/4, p);\n\t// a^(n+3)/8 or 2^(n+3)/8 * 2^(n-1)/4\
    \ works if p % 8 == 5\n\tll s = p - 1, n = 2;\n\tint r = 0, m;\n\twhile (s % 2\
    \ == 0)\n\t\t++r, s /= 2;\n\t/// find a non-square mod p\n\twhile (modpow(n, (p\
    \ - 1) / 2, p) != p - 1) ++n;\n\tll x = modpow(a, (s + 1) / 2, p);\n\tll b = modpow(a,\
    \ s, p), g = modpow(n, s, p);\n\tfor (;; r = m) {\n\t\tll t = b;\n\t\tfor (m =\
    \ 0; m < r && t != 1; ++m)\n\t\t\tt = t * t % p;\n\t\tif (m == 0) return x;\n\t\
    \tll gs = modpow(g, 1LL << (r - m - 1), p);\n\t\tg = gs * gs % p;\n\t\tx = x *\
    \ gs % p;\n\t\tb = b * g % p;\n\t}\n}\n"
  code: "//source: KACTL\n\nll modpow(ll b, ll e, ll p) {\n  ll ans = 1;\n  for(;\
    \ e; b = b * b % p, e /= 2)\n    if (e & 1) ans = ans * b % p;\n  return ans;\n\
    }\n\nll sqrt(ll a, ll p) {\n\ta %= p; if (a < 0) a += p;\n\tif (a == 0) return\
    \ 0;\n\t//assert(modpow(a, (p-1)/2, p) == 1); // else no solution\n  if (modpow(a,\
    \ (p-1)/2, p) != 1) return -1;\n\tif (p % 4 == 3) return modpow(a, (p+1)/4, p);\n\
    \t// a^(n+3)/8 or 2^(n+3)/8 * 2^(n-1)/4 works if p % 8 == 5\n\tll s = p - 1, n\
    \ = 2;\n\tint r = 0, m;\n\twhile (s % 2 == 0)\n\t\t++r, s /= 2;\n\t/// find a\
    \ non-square mod p\n\twhile (modpow(n, (p - 1) / 2, p) != p - 1) ++n;\n\tll x\
    \ = modpow(a, (s + 1) / 2, p);\n\tll b = modpow(a, s, p), g = modpow(n, s, p);\n\
    \tfor (;; r = m) {\n\t\tll t = b;\n\t\tfor (m = 0; m < r && t != 1; ++m)\n\t\t\
    \tt = t * t % p;\n\t\tif (m == 0) return x;\n\t\tll gs = modpow(g, 1LL << (r -\
    \ m - 1), p);\n\t\tg = gs * gs % p;\n\t\tx = x * gs % p;\n\t\tb = b * g % p;\n\
    \t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/sqrtMod.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/log_of_formal_power_series_sparse.test.cpp
  - test/pow_of_formal_power_series_sparse.test.cpp
  - test/sqrt_of_formal_power_series.test.cpp
  - test/inv_of_formal_power_series_sparse.test.cpp
  - test/exp_of_formal_power_series_sparse.test.cpp
  - test/sqrt_of_formal_power_series_sparse.test.cpp
documentation_of: numtheory/sqrtMod.cpp
layout: document
redirect_from:
- /library/numtheory/sqrtMod.cpp
- /library/numtheory/sqrtMod.cpp.html
title: numtheory/sqrtMod.cpp
---
