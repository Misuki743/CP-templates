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
  bundledCode: "#line 1 \"KMPA.cpp\"\n/**\n * template name: KMPA\n * author: Misuki\n\
    \ * last update: 2023/08/24\n * verify: CF 1721E - Prefix Function Queries\n */\n\
    \nstruct KMPA {\n  static constexpr array<int, 26> UNIT = {};\n  vector<array<int,\
    \ 26>> v;\n  vector<int> pi;\n\n  KMPA() {\n    pi.emplace_back(0);\n    v.emplace_back(UNIT);\n\
    \  }\n\n  void insert(char ch) {\n    int id = ch - 'a';\n    pi.emplace_back(v.back()[id]);\n\
    \    v.back()[id] = ssize(v);\n    v.emplace_back(UNIT);\n    for(int i = 0; i\
    \ < 26; i++)\n      v.back()[i] = v[pi.back()][i];\n  }\n\n  void pop() {\n  \
    \  assert(ssize(v) > 1);\n    v.pop_back();\n    pi.pop_back();\n    int id =\
    \ ranges::max_element(v.back()) - v.back().begin();\n    v.back()[id] = v[pi.back()][id];\n\
    \  }\n};\n"
  code: "/**\n * template name: KMPA\n * author: Misuki\n * last update: 2023/08/24\n\
    \ * verify: CF 1721E - Prefix Function Queries\n */\n\nstruct KMPA {\n  static\
    \ constexpr array<int, 26> UNIT = {};\n  vector<array<int, 26>> v;\n  vector<int>\
    \ pi;\n\n  KMPA() {\n    pi.emplace_back(0);\n    v.emplace_back(UNIT);\n  }\n\
    \n  void insert(char ch) {\n    int id = ch - 'a';\n    pi.emplace_back(v.back()[id]);\n\
    \    v.back()[id] = ssize(v);\n    v.emplace_back(UNIT);\n    for(int i = 0; i\
    \ < 26; i++)\n      v.back()[i] = v[pi.back()][i];\n  }\n\n  void pop() {\n  \
    \  assert(ssize(v) > 1);\n    v.pop_back();\n    pi.pop_back();\n    int id =\
    \ ranges::max_element(v.back()) - v.back().begin();\n    v.back()[id] = v[pi.back()][id];\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: KMPA.cpp
  requiredBy: []
  timestamp: '2023-09-28 20:57:04+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: KMPA.cpp
layout: document
redirect_from:
- /library/KMPA.cpp
- /library/KMPA.cpp.html
title: KMPA.cpp
---
