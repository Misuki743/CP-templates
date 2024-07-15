---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Z_algorithm.test.cpp
    title: test/Z_algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/zFunc.cpp\"\ntemplate<class T>\nvector<int> zFunc(T\
    \ &s) {\n  vector<int> z(ssize(s));\n  z[0] = ssize(s);\n  for(int i = 1, l =\
    \ 0, r = -1; i < ssize(s); i++) {\n    if (i <= r)\n      z[i] = min(r - i + 1,\
    \ z[i - l]);\n    while(i + z[i] < ssize(s) and s[i + z[i]] == s[z[i]])\n    \
    \  l = i, r = i + z[i], z[i] += 1;\n  }\n  return z;\n}\n"
  code: "template<class T>\nvector<int> zFunc(T &s) {\n  vector<int> z(ssize(s));\n\
    \  z[0] = ssize(s);\n  for(int i = 1, l = 0, r = -1; i < ssize(s); i++) {\n  \
    \  if (i <= r)\n      z[i] = min(r - i + 1, z[i - l]);\n    while(i + z[i] < ssize(s)\
    \ and s[i + z[i]] == s[z[i]])\n      l = i, r = i + z[i], z[i] += 1;\n  }\n  return\
    \ z;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/zFunc.cpp
  requiredBy: []
  timestamp: '2024-07-15 22:07:26+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Z_algorithm.test.cpp
documentation_of: string/zFunc.cpp
layout: document
redirect_from:
- /library/string/zFunc.cpp
- /library/string/zFunc.cpp.html
title: string/zFunc.cpp
---
