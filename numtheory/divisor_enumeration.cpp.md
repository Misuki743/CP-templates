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
  bundledCode: "#line 1 \"numtheory/divisor_enumeration.cpp\"\ntemplate<int32_t C>\n\
    struct divisor_enumeration {\n  using i32 = int32_t;\n  array<i32, C + 1> s;\n\
    \  vector<i32> d;\n  divisor_enumeration() {\n    for(int i = 1; i < C; i++)\n\
    \      for(int j = i; j < C; j += i)\n        s[j]++;\n    for(int i = 1; i <=\
    \ C; i++)\n      s[i] += s[i - 1];\n    d.resize(s[C]);\n    for(int i = C - 1;\
    \ i >= 1; i--)\n      for(int j = i; j < C; j += i)\n        d[--s[j]] = i;\n\
    \  }\n  vector<i32> divisor(i32 x) {\n    return vector(d.begin() + s[x], d.begin()\
    \ + s[x + 1]);\n  }\n};\n"
  code: "template<int32_t C>\nstruct divisor_enumeration {\n  using i32 = int32_t;\n\
    \  array<i32, C + 1> s;\n  vector<i32> d;\n  divisor_enumeration() {\n    for(int\
    \ i = 1; i < C; i++)\n      for(int j = i; j < C; j += i)\n        s[j]++;\n \
    \   for(int i = 1; i <= C; i++)\n      s[i] += s[i - 1];\n    d.resize(s[C]);\n\
    \    for(int i = C - 1; i >= 1; i--)\n      for(int j = i; j < C; j += i)\n  \
    \      d[--s[j]] = i;\n  }\n  vector<i32> divisor(i32 x) {\n    return vector(d.begin()\
    \ + s[x], d.begin() + s[x + 1]);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/divisor_enumeration.cpp
  requiredBy: []
  timestamp: '2025-12-12 15:07:14+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numtheory/divisor_enumeration.cpp
layout: document
redirect_from:
- /library/numtheory/divisor_enumeration.cpp
- /library/numtheory/divisor_enumeration.cpp.html
title: numtheory/divisor_enumeration.cpp
---
