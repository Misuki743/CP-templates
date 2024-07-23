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
  bundledCode: "#line 1 \"numtheory/linearSieve.cpp\"\nconst int C = 1000001;\nvector<int>\
    \ prime;\nint mpf[C];\nvoid sieve() {\n  for(int i = 1; i < C; i++)\n    mpf[i]\
    \ = i;\n  for(int i = 2; i < C; i++) {\n    if (mpf[i] == i)\n      prime.emplace_back(i);\n\
    \    for(int P : prime) {\n      if (P > mpf[i] or i * P >= C)\n        break;\n\
    \      mpf[i * P] = P;\n    }\n  }\n}\n\nvector<pii> factorize(int val) {\n  vector<pii>\
    \ res;\n  while(val > 1) {\n    int p = mpf[val];\n    res.emplace_back(p, 0);\n\
    \    while(val % p == 0)\n      res.back().second += 1, val /= p;\n  }\n  return\
    \ res;\n}\n\nvector<int> factors(int val) {\n  vector<int> res(1, 1);\n  for(auto\
    \ [p, idx] : factorize(val)) {\n    vector<int> tmp;\n    ll base = 1;\n    for(int\
    \ i = 0; i <= idx; i++, base *= p)\n      for(int X : res)\n        tmp.emplace_back(X\
    \ * (int)base);\n    res.swap(tmp);\n  }\n  return res;\n}\n"
  code: "const int C = 1000001;\nvector<int> prime;\nint mpf[C];\nvoid sieve() {\n\
    \  for(int i = 1; i < C; i++)\n    mpf[i] = i;\n  for(int i = 2; i < C; i++) {\n\
    \    if (mpf[i] == i)\n      prime.emplace_back(i);\n    for(int P : prime) {\n\
    \      if (P > mpf[i] or i * P >= C)\n        break;\n      mpf[i * P] = P;\n\
    \    }\n  }\n}\n\nvector<pii> factorize(int val) {\n  vector<pii> res;\n  while(val\
    \ > 1) {\n    int p = mpf[val];\n    res.emplace_back(p, 0);\n    while(val %\
    \ p == 0)\n      res.back().second += 1, val /= p;\n  }\n  return res;\n}\n\n\
    vector<int> factors(int val) {\n  vector<int> res(1, 1);\n  for(auto [p, idx]\
    \ : factorize(val)) {\n    vector<int> tmp;\n    ll base = 1;\n    for(int i =\
    \ 0; i <= idx; i++, base *= p)\n      for(int X : res)\n        tmp.emplace_back(X\
    \ * (int)base);\n    res.swap(tmp);\n  }\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/linearSieve.cpp
  requiredBy: []
  timestamp: '2024-07-23 18:02:38+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numtheory/linearSieve.cpp
layout: document
redirect_from:
- /library/numtheory/linearSieve.cpp
- /library/numtheory/linearSieve.cpp.html
title: numtheory/linearSieve.cpp
---
