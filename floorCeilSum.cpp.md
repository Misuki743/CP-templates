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
  bundledCode: "#line 1 \"floorCeilSum.cpp\"\n/**\n * template name: floorCeilSum\n\
    \ * author: Misuki\n * last update: 2024/01/11\n * note: g = floor(x / val) is\
    \ the greatest value s.t. floor(x / g) = val for floor sum, \n *       g = ceil(x\
    \ / val) is the least value s.t. ceil(x / g) = val for ceil sum. \n * verify:\
    \ brute forced x <= 1e4\n *         Library Checker - Enumerate Quotients\n */\n\
    \ntemplate<class T>\nvector<array<T, 3>> calc_floor(T x) {\n  vector<T> v, rng;\n\
    \  for(T i = x; i; ) {\n    T val = x / i;\n    v.emplace_back(val);\n    rng.emplace_back(x\
    \ / val);\n    i = x / (val + 1);\n  }\n  rng.emplace_back(0);\n\n  vector<array<T,\
    \ 3>> res;\n  for(int i = 0; i < ssize(v); i++)\n    res.push_back({v[i], rng[i\
    \ + 1] + 1, rng[i]}); //{q, [l, r]}\n\n  return res;\n}\n\ntemplate<class T>\n\
    vector<array<T, 3>> calc_ceil(T x) {\n  vector<T> v, rng;\n  for(T i = 1; ; )\
    \ {\n    T val = (x + i - 1) / i;\n    v.emplace_back(val);\n    rng.emplace_back((x\
    \ + val - 1) / val);\n    if (val == 1)\n      break;\n    i = (x + val - 2) /\
    \ (val - 1);\n  }\n  rng.emplace_back(x + 1);\n\n  vector<array<T, 3>> res;\n\
    \  for(int i = 0; i < ssize(v); i++)\n    res.push_back({v[i], rng[i], rng[i +\
    \ 1] - 1}); //{q, [l, r]}\n\n  return res;\n}\n"
  code: "/**\n * template name: floorCeilSum\n * author: Misuki\n * last update: 2024/01/11\n\
    \ * note: g = floor(x / val) is the greatest value s.t. floor(x / g) = val for\
    \ floor sum, \n *       g = ceil(x / val) is the least value s.t. ceil(x / g)\
    \ = val for ceil sum. \n * verify: brute forced x <= 1e4\n *         Library Checker\
    \ - Enumerate Quotients\n */\n\ntemplate<class T>\nvector<array<T, 3>> calc_floor(T\
    \ x) {\n  vector<T> v, rng;\n  for(T i = x; i; ) {\n    T val = x / i;\n    v.emplace_back(val);\n\
    \    rng.emplace_back(x / val);\n    i = x / (val + 1);\n  }\n  rng.emplace_back(0);\n\
    \n  vector<array<T, 3>> res;\n  for(int i = 0; i < ssize(v); i++)\n    res.push_back({v[i],\
    \ rng[i + 1] + 1, rng[i]}); //{q, [l, r]}\n\n  return res;\n}\n\ntemplate<class\
    \ T>\nvector<array<T, 3>> calc_ceil(T x) {\n  vector<T> v, rng;\n  for(T i = 1;\
    \ ; ) {\n    T val = (x + i - 1) / i;\n    v.emplace_back(val);\n    rng.emplace_back((x\
    \ + val - 1) / val);\n    if (val == 1)\n      break;\n    i = (x + val - 2) /\
    \ (val - 1);\n  }\n  rng.emplace_back(x + 1);\n\n  vector<array<T, 3>> res;\n\
    \  for(int i = 0; i < ssize(v); i++)\n    res.push_back({v[i], rng[i], rng[i +\
    \ 1] - 1}); //{q, [l, r]}\n\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: floorCeilSum.cpp
  requiredBy: []
  timestamp: '2024-01-13 20:11:08+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: floorCeilSum.cpp
layout: document
redirect_from:
- /library/floorCeilSum.cpp
- /library/floorCeilSum.cpp.html
title: floorCeilSum.cpp
---
