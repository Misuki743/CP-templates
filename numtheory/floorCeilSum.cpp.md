---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/enumerate_quotients.test.cpp
    title: test/enumerate_quotients.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/floorCeilSum.cpp\"\n// note: g = floor(x / val)\
    \ is the greatest value s.t. floor(x / g) = val for floor sum, \n//       g =\
    \ ceil(x / val) is the least value s.t. ceil(x / g) = val for ceil sum. \n//\n\
    template<class T>\nvector<array<T, 3>> calc_floor(T x) {\n  vector<T> v, rng;\n\
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
  code: "// note: g = floor(x / val) is the greatest value s.t. floor(x / g) = val\
    \ for floor sum, \n//       g = ceil(x / val) is the least value s.t. ceil(x /\
    \ g) = val for ceil sum. \n//\ntemplate<class T>\nvector<array<T, 3>> calc_floor(T\
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
  path: numtheory/floorCeilSum.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/enumerate_quotients.test.cpp
documentation_of: numtheory/floorCeilSum.cpp
layout: document
redirect_from:
- /library/numtheory/floorCeilSum.cpp
- /library/numtheory/floorCeilSum.cpp.html
title: numtheory/floorCeilSum.cpp
---
