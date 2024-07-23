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
  bundledCode: "#line 1 \"numtheory/slowFactorize.cpp\"\nvector<pll> slowFactorize(ll\
    \ val) {\n  vector<pll> res;\n  for(ll d = 2; d * d <= val; d++) {\n    if (val\
    \ % d != 0) continue;\n    res.emplace_back(d, 0);\n    while(val % d == 0) {\n\
    \      val /= d;\n      res.back().second++;\n    }\n  }\n  if (val != 1) res.emplace_back(val,\
    \ 1);\n  return res;\n}\n\nvector<ll> factors(vector<pll> pf) {\n  vector<ll>\
    \ res(1, 1);\n  for(auto [p, idx] : pf) {\n    vector<ll> tmp;\n    ull base =\
    \ 1;\n    for(int i = 0; i <= idx; i++, base *= p)\n      for(ll X : res)\n  \
    \      tmp.emplace_back(X * base);\n    res.swap(tmp);\n  }\n  return res;\n}\n"
  code: "vector<pll> slowFactorize(ll val) {\n  vector<pll> res;\n  for(ll d = 2;\
    \ d * d <= val; d++) {\n    if (val % d != 0) continue;\n    res.emplace_back(d,\
    \ 0);\n    while(val % d == 0) {\n      val /= d;\n      res.back().second++;\n\
    \    }\n  }\n  if (val != 1) res.emplace_back(val, 1);\n  return res;\n}\n\nvector<ll>\
    \ factors(vector<pll> pf) {\n  vector<ll> res(1, 1);\n  for(auto [p, idx] : pf)\
    \ {\n    vector<ll> tmp;\n    ull base = 1;\n    for(int i = 0; i <= idx; i++,\
    \ base *= p)\n      for(ll X : res)\n        tmp.emplace_back(X * base);\n   \
    \ res.swap(tmp);\n  }\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/slowFactorize.cpp
  requiredBy: []
  timestamp: '2024-07-23 18:02:38+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numtheory/slowFactorize.cpp
layout: document
redirect_from:
- /library/numtheory/slowFactorize.cpp
- /library/numtheory/slowFactorize.cpp.html
title: numtheory/slowFactorize.cpp
---
