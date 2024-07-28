---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/longest_common_substring.test.cpp
    title: test/longest_common_substring.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/longestCommonSubstring.cpp\"\n//#include<string/suffixArray.cpp>\n\
    \narray<int, 4> longestCommonSubstring(string s, string t) {\n  t = s + '#' +\
    \ t;\n  auto sa = suffix_array(t);\n  auto lcp = lcp_array(t, sa);\n  array<int,\
    \ 4> res = {};\n  for(int i = 0; i < ssize(lcp); i++) {\n    if (lcp[i] <= res[1]\
    \ - res[0]) continue;\n    if (sa[i] < ssize(s) and sa[i + 1] > ssize(s))\n  \
    \    res = {sa[i], sa[i] + lcp[i], sa[i + 1] - (int)(ssize(s) + 1), sa[i + 1]\
    \ - (int)(ssize(s) + 1) + lcp[i]};\n    else if (sa[i] > ssize(s) and sa[i + 1]\
    \ < ssize(s))\n      res = {sa[i + 1], sa[i + 1] + lcp[i], sa[i] - (int)(ssize(s)\
    \ + 1), sa[i] - (int)(ssize(s) + 1) + lcp[i]};\n  }\n  return res;\n}\n"
  code: "//#include<string/suffixArray.cpp>\n\narray<int, 4> longestCommonSubstring(string\
    \ s, string t) {\n  t = s + '#' + t;\n  auto sa = suffix_array(t);\n  auto lcp\
    \ = lcp_array(t, sa);\n  array<int, 4> res = {};\n  for(int i = 0; i < ssize(lcp);\
    \ i++) {\n    if (lcp[i] <= res[1] - res[0]) continue;\n    if (sa[i] < ssize(s)\
    \ and sa[i + 1] > ssize(s))\n      res = {sa[i], sa[i] + lcp[i], sa[i + 1] - (int)(ssize(s)\
    \ + 1), sa[i + 1] - (int)(ssize(s) + 1) + lcp[i]};\n    else if (sa[i] > ssize(s)\
    \ and sa[i + 1] < ssize(s))\n      res = {sa[i + 1], sa[i + 1] + lcp[i], sa[i]\
    \ - (int)(ssize(s) + 1), sa[i] - (int)(ssize(s) + 1) + lcp[i]};\n  }\n  return\
    \ res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/longestCommonSubstring.cpp
  requiredBy: []
  timestamp: '2024-02-11 15:11:45+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/longest_common_substring.test.cpp
documentation_of: string/longestCommonSubstring.cpp
layout: document
redirect_from:
- /library/string/longestCommonSubstring.cpp
- /library/string/longestCommonSubstring.cpp.html
title: string/longestCommonSubstring.cpp
---
