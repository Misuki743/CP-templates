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
  bundledCode: "#line 1 \"KMP.cpp\"\n/**\n * template name: KMP\n * author: Misuki\n\
    \ * last update: 2022/02/04\n */\n\nint fail[1000000];\nvoid build(string &s)\
    \ {\n  fail[0] = -1;\n  for(int i = 1; i < s.size(); i++) {\n    int now = fail[i\
    \ - 1];\n    while(now != -1 and s[i] != s[now + 1])\n      now = fail[now];\n\
    \    fail[i] = now + ((s[now + 1] == s[i]) ? 1 : 0);\n  }\n}\n\nint match(string\
    \ &a, string &b) {\n  build(b);\n  int res = 0;\n  int now = -1;\n  for(char X\
    \ : a) {\n    while(now != -1 and X != b[now + 1])\n      now = fail[now];\n \
    \   if (X == b[now + 1])\n      now++;\n    if (now + 1 == b.size())\n      res++,\
    \ now = fail[now];\n  }\n\n  return res;\n}\n"
  code: "/**\n * template name: KMP\n * author: Misuki\n * last update: 2022/02/04\n\
    \ */\n\nint fail[1000000];\nvoid build(string &s) {\n  fail[0] = -1;\n  for(int\
    \ i = 1; i < s.size(); i++) {\n    int now = fail[i - 1];\n    while(now != -1\
    \ and s[i] != s[now + 1])\n      now = fail[now];\n    fail[i] = now + ((s[now\
    \ + 1] == s[i]) ? 1 : 0);\n  }\n}\n\nint match(string &a, string &b) {\n  build(b);\n\
    \  int res = 0;\n  int now = -1;\n  for(char X : a) {\n    while(now != -1 and\
    \ X != b[now + 1])\n      now = fail[now];\n    if (X == b[now + 1])\n      now++;\n\
    \    if (now + 1 == b.size())\n      res++, now = fail[now];\n  }\n\n  return\
    \ res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: KMP.cpp
  requiredBy: []
  timestamp: '2023-06-16 02:10:58+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: KMP.cpp
layout: document
redirect_from:
- /library/KMP.cpp
- /library/KMP.cpp.html
title: KMP.cpp
---
