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
  bundledCode: "#line 1 \"zFunc.cpp\"\n/**\n * template name: zFunc\n * author: Misuki\n\
    \ * last update: 2024/01/01\n * verify: Library Checker - Z Algorithm\n */\n\n\
    vector<int> zFunc(string &s) {\n  vector<int> z(ssize(s));\n  z[0] = ssize(s);\n\
    \  for(int i = 1, l = 0, r = -1; i < ssize(s); i++) {\n    if (i <= r)\n     \
    \ z[i] = min(r - i + 1, z[i - l]);\n    while(i + z[i] < ssize(s) and s[i + z[i]]\
    \ == s[z[i]])\n      l = i, r = i + z[i], z[i] += 1;\n  }\n  return z;\n}\n"
  code: "/**\n * template name: zFunc\n * author: Misuki\n * last update: 2024/01/01\n\
    \ * verify: Library Checker - Z Algorithm\n */\n\nvector<int> zFunc(string &s)\
    \ {\n  vector<int> z(ssize(s));\n  z[0] = ssize(s);\n  for(int i = 1, l = 0, r\
    \ = -1; i < ssize(s); i++) {\n    if (i <= r)\n      z[i] = min(r - i + 1, z[i\
    \ - l]);\n    while(i + z[i] < ssize(s) and s[i + z[i]] == s[z[i]])\n      l =\
    \ i, r = i + z[i], z[i] += 1;\n  }\n  return z;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: zFunc.cpp
  requiredBy: []
  timestamp: '2024-01-06 18:21:41+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: zFunc.cpp
layout: document
redirect_from:
- /library/zFunc.cpp
- /library/zFunc.cpp.html
title: zFunc.cpp
---
