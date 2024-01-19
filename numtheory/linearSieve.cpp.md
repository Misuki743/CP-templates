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
  bundledCode: "#line 1 \"numtheory/linearSieve.cpp\"\n/**\n * template name: linearSieve\n\
    \ * author: Misuki\n * last update: 2022/12/13\n */\n\nconst int C = 1000001;\n\
    vector<int> prime;\nint mpf[C];\nvoid sieve() {\n  for(int i = 1; i < C; i++)\n\
    \    mpf[i] = i;\n  for(int i = 2; i < C; i++) {\n    if (mpf[i] == i)\n     \
    \ prime.emplace_back(i);\n    for(int P : prime) {\n      if (P > mpf[i] or i\
    \ * P >= C)\n        break;\n      mpf[i * P] = P;\n    }\n  }\n}\n\nvector<pii>\
    \ factorize(int val) {\n  vector<pii> res;\n  while(val > 1) {\n    int p = mpf[val];\n\
    \    res.emplace_back(p, 0);\n    while(val % p == 0)\n      res.back().second\
    \ += 1, val /= p;\n  }\n  return res;\n}\n\nvector<int> factors(int val) {\n \
    \ vector<int> res(1, 1);\n  for(auto [p, idx] : factorize(val)) {\n    vector<int>\
    \ tmp;\n    for(int i = 0, base = 1; i <= idx; i++, base *= p)\n      for(int\
    \ X : res)\n        tmp.emplace_back(X * base);\n    res.swap(tmp);\n  }\n  return\
    \ res;\n}\n"
  code: "/**\n * template name: linearSieve\n * author: Misuki\n * last update: 2022/12/13\n\
    \ */\n\nconst int C = 1000001;\nvector<int> prime;\nint mpf[C];\nvoid sieve()\
    \ {\n  for(int i = 1; i < C; i++)\n    mpf[i] = i;\n  for(int i = 2; i < C; i++)\
    \ {\n    if (mpf[i] == i)\n      prime.emplace_back(i);\n    for(int P : prime)\
    \ {\n      if (P > mpf[i] or i * P >= C)\n        break;\n      mpf[i * P] = P;\n\
    \    }\n  }\n}\n\nvector<pii> factorize(int val) {\n  vector<pii> res;\n  while(val\
    \ > 1) {\n    int p = mpf[val];\n    res.emplace_back(p, 0);\n    while(val %\
    \ p == 0)\n      res.back().second += 1, val /= p;\n  }\n  return res;\n}\n\n\
    vector<int> factors(int val) {\n  vector<int> res(1, 1);\n  for(auto [p, idx]\
    \ : factorize(val)) {\n    vector<int> tmp;\n    for(int i = 0, base = 1; i <=\
    \ idx; i++, base *= p)\n      for(int X : res)\n        tmp.emplace_back(X * base);\n\
    \    res.swap(tmp);\n  }\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/linearSieve.cpp
  requiredBy: []
  timestamp: '2024-01-20 02:52:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numtheory/linearSieve.cpp
layout: document
redirect_from:
- /library/numtheory/linearSieve.cpp
- /library/numtheory/linearSieve.cpp.html
title: numtheory/linearSieve.cpp
---
