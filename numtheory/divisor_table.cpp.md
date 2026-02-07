---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest_divisor_table.test.cpp
    title: test/mytest_divisor_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/divisor_table.cpp\"\ntemplate<int32_t C>\nstruct\
    \ divisor_table {\n  using i32 = int32_t;\n  array<i32, C + 1> s = {};\n  vector<i32>\
    \ d;\n  divisor_table() {\n    for(int i = 1; i < C; i++)\n      for(int j = i;\
    \ j < C; j += i)\n        s[j]++;\n    for(int i = 1; i <= C; i++)\n      s[i]\
    \ += s[i - 1];\n    d.resize(s[C]);\n    for(int i = C - 1; i >= 1; i--)\n   \
    \   for(int j = i; j < C; j += i)\n        d[--s[j]] = i;\n  }\n  vi divisor(int\
    \ x) {\n    return vi(d.begin() + s[x], d.begin() + s[x + 1]);\n  }\n};\n"
  code: "template<int32_t C>\nstruct divisor_table {\n  using i32 = int32_t;\n  array<i32,\
    \ C + 1> s = {};\n  vector<i32> d;\n  divisor_table() {\n    for(int i = 1; i\
    \ < C; i++)\n      for(int j = i; j < C; j += i)\n        s[j]++;\n    for(int\
    \ i = 1; i <= C; i++)\n      s[i] += s[i - 1];\n    d.resize(s[C]);\n    for(int\
    \ i = C - 1; i >= 1; i--)\n      for(int j = i; j < C; j += i)\n        d[--s[j]]\
    \ = i;\n  }\n  vi divisor(int x) {\n    return vi(d.begin() + s[x], d.begin()\
    \ + s[x + 1]);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/divisor_table.cpp
  requiredBy: []
  timestamp: '2026-02-08 01:19:23+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest_divisor_table.test.cpp
documentation_of: numtheory/divisor_table.cpp
layout: document
redirect_from:
- /library/numtheory/divisor_table.cpp
- /library/numtheory/divisor_table.cpp.html
title: numtheory/divisor_table.cpp
---
