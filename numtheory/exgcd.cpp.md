---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/exgcd.cpp\"\n/**\n * template name: exgcd\n *\
    \ reference: KACTL\n * last update: 2023/08/03\n * verify: CF 1748D - ConstructOR\n\
    \ * note: inv calculate modulo inverse of r mod m where gcd(r, m) = 1\n */\n\n\
    ll euclid(ll a, ll b, ll &x, ll &y) {\n\tif (!b) return x = 1, y = 0, a;\n\tll\
    \ d = euclid(b, a % b, y, x);\n\treturn y -= a/b * x, d;\n}\n\nll inv(ll r, ll\
    \ m) {\n  ll x, y;\n  ll gcd = euclid(r, m, x, y);\n  assert(gcd == 1);\n  return\
    \ (x % m + m) % m;\n}\n"
  code: "/**\n * template name: exgcd\n * reference: KACTL\n * last update: 2023/08/03\n\
    \ * verify: CF 1748D - ConstructOR\n * note: inv calculate modulo inverse of r\
    \ mod m where gcd(r, m) = 1\n */\n\nll euclid(ll a, ll b, ll &x, ll &y) {\n\t\
    if (!b) return x = 1, y = 0, a;\n\tll d = euclid(b, a % b, y, x);\n\treturn y\
    \ -= a/b * x, d;\n}\n\nll inv(ll r, ll m) {\n  ll x, y;\n  ll gcd = euclid(r,\
    \ m, x, y);\n  assert(gcd == 1);\n  return (x % m + m) % m;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/exgcd.cpp
  requiredBy: []
  timestamp: '2024-01-20 02:52:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numtheory/exgcd.cpp
layout: document
redirect_from:
- /library/numtheory/exgcd.cpp
- /library/numtheory/exgcd.cpp.html
title: numtheory/exgcd.cpp
---
