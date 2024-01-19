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
  bundledCode: "#line 1 \"string/manacher.cpp\"\n/**\n * template name: manacher\n\
    \ * author: Misuki\n * last update: 2022/02/04\n */\n\nint p[2000001];\nvoid build(string\
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
  path: string/manacher.cpp
  requiredBy: []
  timestamp: '2024-01-20 02:52:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/manacher.cpp
layout: document
redirect_from:
- /library/string/manacher.cpp
- /library/string/manacher.cpp.html
title: string/manacher.cpp
---
