---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/binomial_coefficient_prime_mod.test.cpp
    title: test/binomial_coefficient_prime_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"modint/mintAnyMod.cpp\"\n//note: inversion only works when\
    \ MOD is a prime\n\nstruct mint {\n  static long long MOD;\n  long long _val;\n\
    \n  mint(long long init = 0) {\n    _val = init % MOD;\n    (*this).norm();\n\
    \  }\n\n  mint POW(long long index) {\n    if (index == 0)\n      return mint(1ll);\n\
    \    mint base = *this;\n    mint res = (base == 0ll ? 0ll : 1ll);\n    while(index)\
    \ {\n      if (index & 1)\n        res *= base;\n      base *= base, index >>=\
    \ 1;\n    }\n    return res;\n  }\n\n  mint inv() { return (*this).POW(MOD - 2);\
    \ }\n\n  mint& norm() {\n    if (_val >= MOD)\n      _val -= MOD;\n    if (_val\
    \ < 0)\n      _val += MOD;\n    return *this;\n  }\n\n  mint& operator+=(mint\
    \ b) {\n    _val += b._val;\n    return (*this).norm();\n  }\n  mint& operator-=(mint\
    \ b) {\n    _val -= b._val;\n    return (*this).norm();\n  }\n  mint& operator*=(mint\
    \ b) {\n    _val = (_val * b._val) % MOD;\n    return *this;\n  }\n  mint& operator/=(mint\
    \ b) {\n    _val = (_val * b.inv()._val) % MOD;\n    return *this;\n  }\n\n  mint&\
    \ operator++() {\n    _val += 1;\n    return (*this).norm();\n  }\n  mint& operator--()\
    \ {\n    _val -= 1;\n    return (*this).norm();\n  }\n  mint operator++(signed)\
    \ {\n    mint tmp = *this;\n    ++(*this);\n    return tmp;\n  }\n  mint operator--(signed)\
    \ {\n    mint tmp = *this;\n    --(*this);\n    return tmp;\n  }\n\n  mint operator-()\
    \ { return mint(-_val); }\n  bool operator==(mint b) { return _val == b._val;\
    \ }\n  bool operator!=(mint b) { return _val != b._val; }\n  \n  friend mint operator+(mint\
    \ a, mint b) { return a += b; }\n  friend mint operator-(mint a, mint b) { return\
    \ a -= b; }\n  friend mint operator*(mint a, mint b) { return a *= b; }\n  friend\
    \ mint operator/(mint a, mint b) { return a /= b; }\n\n  friend ostream& operator<<(ostream&\
    \ os, const mint& b) {\n    return os << b._val;\n  }\n  friend istream& operator>>(istream&\
    \ is, mint& b) {\n    long long val;\n    is >> val;\n    b = mint(val);\n   \
    \ return is;\n  }\n};\n"
  code: "//note: inversion only works when MOD is a prime\n\nstruct mint {\n  static\
    \ long long MOD;\n  long long _val;\n\n  mint(long long init = 0) {\n    _val\
    \ = init % MOD;\n    (*this).norm();\n  }\n\n  mint POW(long long index) {\n \
    \   if (index == 0)\n      return mint(1ll);\n    mint base = *this;\n    mint\
    \ res = (base == 0ll ? 0ll : 1ll);\n    while(index) {\n      if (index & 1)\n\
    \        res *= base;\n      base *= base, index >>= 1;\n    }\n    return res;\n\
    \  }\n\n  mint inv() { return (*this).POW(MOD - 2); }\n\n  mint& norm() {\n  \
    \  if (_val >= MOD)\n      _val -= MOD;\n    if (_val < 0)\n      _val += MOD;\n\
    \    return *this;\n  }\n\n  mint& operator+=(mint b) {\n    _val += b._val;\n\
    \    return (*this).norm();\n  }\n  mint& operator-=(mint b) {\n    _val -= b._val;\n\
    \    return (*this).norm();\n  }\n  mint& operator*=(mint b) {\n    _val = (_val\
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
    \ return is;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: modint/mintAnyMod.cpp
  requiredBy: []
  timestamp: '2024-03-02 02:00:27+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/binomial_coefficient_prime_mod.test.cpp
documentation_of: modint/mintAnyMod.cpp
layout: document
redirect_from:
- /library/modint/mintAnyMod.cpp
- /library/modint/mintAnyMod.cpp.html
title: modint/mintAnyMod.cpp
---
