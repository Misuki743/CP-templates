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
  bundledCode: "#line 1 \"icpc/BerlekampMassey.cpp\"\nvoid modadd(ll &a, ll b) { a\
    \ = (a + b % mod + mod) % mod; }\nvector<ll> BerlekampMassey(vector<ll> s) {\n\
    \  for(ll &x : s) x = (x % mod + mod) % mod;\n  vector<ll> c(1), c0(1);\n  int\
    \ f = -1;\n  for(int i = 0; i < ssize(s); i++) {\n    ll del = s[i];\n    for(int\
    \ j = 1; j < ssize(c); j++)\n      modadd(del, -s[i - j] * c[j]);\n    if (del\
    \ == 0) continue;\n    if (f == -1) {\n      f = i, c.resize(i + 2, 0);\n    }\
    \ else {\n      vector<ll> d = c0;\n      int fp = f;\n      if (i - ssize(c)\
    \ > f - ssize(c0))\n        c0 = c, fp = i;\n      for(ll &x : d) x = (-x + mod)\
    \ % mod;\n      d.insert(d.begin() + 1, 1);\n      ll div = 0;\n      for(int\
    \ j = 1; j < ssize(d); j++)\n        modadd(div, s[f - j + 1] * d[j]);\n     \
    \ ll coef = del * modpow(div, mod - 2) % mod;\n      for(ll &x : d) x = x * coef\
    \ % mod;\n      d.insert(d.begin() + 1, i - f - 1, 0);\n      if (ssize(c) < ssize(d))\
    \ c.resize(d.size(), 0);\n      for(int j = 1; j < ssize(d); j++) modadd(c[j],\
    \ d[j]);\n      f = fp;\n    }\n  }\n  return c;\n}\n"
  code: "void modadd(ll &a, ll b) { a = (a + b % mod + mod) % mod; }\nvector<ll> BerlekampMassey(vector<ll>\
    \ s) {\n  for(ll &x : s) x = (x % mod + mod) % mod;\n  vector<ll> c(1), c0(1);\n\
    \  int f = -1;\n  for(int i = 0; i < ssize(s); i++) {\n    ll del = s[i];\n  \
    \  for(int j = 1; j < ssize(c); j++)\n      modadd(del, -s[i - j] * c[j]);\n \
    \   if (del == 0) continue;\n    if (f == -1) {\n      f = i, c.resize(i + 2,\
    \ 0);\n    } else {\n      vector<ll> d = c0;\n      int fp = f;\n      if (i\
    \ - ssize(c) > f - ssize(c0))\n        c0 = c, fp = i;\n      for(ll &x : d) x\
    \ = (-x + mod) % mod;\n      d.insert(d.begin() + 1, 1);\n      ll div = 0;\n\
    \      for(int j = 1; j < ssize(d); j++)\n        modadd(div, s[f - j + 1] * d[j]);\n\
    \      ll coef = del * modpow(div, mod - 2) % mod;\n      for(ll &x : d) x = x\
    \ * coef % mod;\n      d.insert(d.begin() + 1, i - f - 1, 0);\n      if (ssize(c)\
    \ < ssize(d)) c.resize(d.size(), 0);\n      for(int j = 1; j < ssize(d); j++)\
    \ modadd(c[j], d[j]);\n      f = fp;\n    }\n  }\n  return c;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: icpc/BerlekampMassey.cpp
  requiredBy: []
  timestamp: '2025-11-14 17:40:41+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc/BerlekampMassey.cpp
layout: document
redirect_from:
- /library/icpc/BerlekampMassey.cpp
- /library/icpc/BerlekampMassey.cpp.html
title: icpc/BerlekampMassey.cpp
---
