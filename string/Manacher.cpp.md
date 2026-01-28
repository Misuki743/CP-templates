---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/enumerate_palindromes.test.cpp
    title: test/enumerate_palindromes.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/Manacher.cpp\"\nvector<int> Manacher(string &s) {\n\
    \  vector<int> p(ssize(s));\n  for(int i = 0, l = -1, r = -1; i < ssize(s); i++)\
    \ {\n    if (i <= r)\n      p[i] = min(p[2 * l - i], r - i + 1);\n    while(i\
    \ + p[i] < ssize(s) and i - p[i] >= 0 and s[i + p[i]] == s[i - p[i]])\n      l\
    \ = i, r = i + p[i], p[i] += 1;\n  }\n\n  return p;\n}\n\nvector<int> enumeratePalindrome(string\
    \ &s) {\n  string t = \"#\";\n  for(char c : s)\n    t += c, t += '#';\n  vector<int>\
    \ p = Manacher(t);\n  for(int &x : p)\n    x -= 1;\n  return vector<int>(p.begin()\
    \ + 1, p.end() - 1);\n}\n"
  code: "vector<int> Manacher(string &s) {\n  vector<int> p(ssize(s));\n  for(int\
    \ i = 0, l = -1, r = -1; i < ssize(s); i++) {\n    if (i <= r)\n      p[i] = min(p[2\
    \ * l - i], r - i + 1);\n    while(i + p[i] < ssize(s) and i - p[i] >= 0 and s[i\
    \ + p[i]] == s[i - p[i]])\n      l = i, r = i + p[i], p[i] += 1;\n  }\n\n  return\
    \ p;\n}\n\nvector<int> enumeratePalindrome(string &s) {\n  string t = \"#\";\n\
    \  for(char c : s)\n    t += c, t += '#';\n  vector<int> p = Manacher(t);\n  for(int\
    \ &x : p)\n    x -= 1;\n  return vector<int>(p.begin() + 1, p.end() - 1);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/Manacher.cpp
  requiredBy: []
  timestamp: '2024-01-23 21:50:14+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/enumerate_palindromes.test.cpp
documentation_of: string/Manacher.cpp
layout: document
redirect_from:
- /library/string/Manacher.cpp
- /library/string/Manacher.cpp.html
title: string/Manacher.cpp
---
