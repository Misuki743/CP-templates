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
  bundledCode: "#line 1 \"manacher.cpp\"\n/**\n * template name: manacher\n * author:\
    \ Misuki\n * last update: 2022/02/04\n */\n\nint p[2000001];\nvoid build(string\
    \ &s) {\n  for(int i = 0, l = -1, r = -1; i < s.size(); i++) {\n    if (i <= r)\n\
    \      p[i] = min(p[2 * l - i], r - i + 1);\n    while(i + p[i] < s.size() and\
    \ i - p[i] >= 0 and s[i + p[i]] == s[i - p[i]])\n      l = i, r = i + p[i], p[i]\
    \ += 1;\n  }\n}\n"
  code: "/**\n * template name: manacher\n * author: Misuki\n * last update: 2022/02/04\n\
    \ */\n\nint p[2000001];\nvoid build(string &s) {\n  for(int i = 0, l = -1, r =\
    \ -1; i < s.size(); i++) {\n    if (i <= r)\n      p[i] = min(p[2 * l - i], r\
    \ - i + 1);\n    while(i + p[i] < s.size() and i - p[i] >= 0 and s[i + p[i]] ==\
    \ s[i - p[i]])\n      l = i, r = i + p[i], p[i] += 1;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: manacher.cpp
  requiredBy: []
  timestamp: '2023-06-16 02:10:58+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: manacher.cpp
layout: document
redirect_from:
- /library/manacher.cpp
- /library/manacher.cpp.html
title: manacher.cpp
---
