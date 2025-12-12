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
  bundledCode: "#line 1 \"numtheory/quotient_enumerate.cpp\"\nauto quotient_floor_enumerate(int64_t\
    \ x) {\n  using i64 = int64_t;\n  vector<i64> v, s;\n  v.reserve(2 * (sqrt(x)\
    \ + 32));\n  s.reserve(2 * (sqrt(x) + 32));\n  for(i64 i = x; i; ) {\n    v.emplace_back(x\
    \ / i);\n    s.emplace_back(x / v.back() + 1);\n    i = x / (v.back() + 1);\n\
    \  }\n  s.emplace_back(1);\n\n  struct Data { int64_t quotient, l, r; };\n  vector<Data>\
    \ res(size(v));\n  for(int i = 0; i < ssize(v); i++)\n    res[i] = Data{v[i],\
    \ s[i + 1], s[i]};\n\n  return res;\n}\n\nauto quotient_ceil_enumerate(int64_t\
    \ x) {\n  using i64 = int64_t;\n  vector<i64> v, s;\n  v.reserve(2 * (sqrt(x)\
    \ + 32));\n  s.reserve(2 * (sqrt(x) + 32));\n  for(i64 i = 1; ;) {\n    v.emplace_back((x\
    \ + i - 1) / i);\n    s.emplace_back((x + v.back() - 1) / v.back());\n    if (v.back()\
    \ == 1) break;\n    i = (x + v.back() - 2) / (v.back() - 1);\n  }\n  s.emplace_back(x\
    \ + 1);\n\n  struct Data { int64_t quotient, l, r; };\n  vector<Data> res(size(v));\n\
    \  for(int i = 0; i < ssize(v); i++)\n    res[i] = Data{v[i], s[i], s[i + 1]};\n\
    \n  return res;\n}\n"
  code: "auto quotient_floor_enumerate(int64_t x) {\n  using i64 = int64_t;\n  vector<i64>\
    \ v, s;\n  v.reserve(2 * (sqrt(x) + 32));\n  s.reserve(2 * (sqrt(x) + 32));\n\
    \  for(i64 i = x; i; ) {\n    v.emplace_back(x / i);\n    s.emplace_back(x / v.back()\
    \ + 1);\n    i = x / (v.back() + 1);\n  }\n  s.emplace_back(1);\n\n  struct Data\
    \ { int64_t quotient, l, r; };\n  vector<Data> res(size(v));\n  for(int i = 0;\
    \ i < ssize(v); i++)\n    res[i] = Data{v[i], s[i + 1], s[i]};\n\n  return res;\n\
    }\n\nauto quotient_ceil_enumerate(int64_t x) {\n  using i64 = int64_t;\n  vector<i64>\
    \ v, s;\n  v.reserve(2 * (sqrt(x) + 32));\n  s.reserve(2 * (sqrt(x) + 32));\n\
    \  for(i64 i = 1; ;) {\n    v.emplace_back((x + i - 1) / i);\n    s.emplace_back((x\
    \ + v.back() - 1) / v.back());\n    if (v.back() == 1) break;\n    i = (x + v.back()\
    \ - 2) / (v.back() - 1);\n  }\n  s.emplace_back(x + 1);\n\n  struct Data { int64_t\
    \ quotient, l, r; };\n  vector<Data> res(size(v));\n  for(int i = 0; i < ssize(v);\
    \ i++)\n    res[i] = Data{v[i], s[i], s[i + 1]};\n\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/quotient_enumerate.cpp
  requiredBy: []
  timestamp: '2025-12-12 18:41:06+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/enumerate_quotients.test.cpp
documentation_of: numtheory/quotient_enumerate.cpp
layout: document
redirect_from:
- /library/numtheory/quotient_enumerate.cpp
- /library/numtheory/quotient_enumerate.cpp.html
title: numtheory/quotient_enumerate.cpp
---
