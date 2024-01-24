---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki_2606.test.cpp
    title: test/yuki_2606.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/palindromicTree.cpp\"\ntemplate<unsigned sigma =\
    \ 26, char base = 'a'>\nstruct palindromicTree {\n  vector<int> len, link;\n \
    \ vector<ll> freq;\n  vector<array<int, sigma>> go;\n\n  palindromicTree(string\
    \ s) {\n    array<int, sigma> unit;\n    fill(unit.begin(), unit.end(), -1);\n\
    \    len = link = {-1, 0}, go = {unit, unit}, freq = {0, 0};\n    len.reserve(ssize(s)\
    \ + 2);\n    link.reserve(ssize(s) + 2);\n    go.reserve(ssize(s) + 2);\n    freq.reserve(ssize(s)\
    \ + 2);\n\n    int v = 0;\n    for(int i = 0; i < ssize(s); i++) {\n      while(len[v]\
    \ == i or s[i - len[v] - 1] != s[i])\n        v = link[v];\n      if (go[v][s[i]\
    \ - base] == -1) {\n        go[v][s[i] - base] = ssize(len);\n        len.emplace_back(len[v]\
    \ + 2);\n        freq.emplace_back();\n        go.emplace_back(unit);\n      \
    \  int u = link[v];\n        while(u != -1 and s[i - len[u] - 1] != s[i])\n  \
    \        u = link[u];\n        link.emplace_back(u == -1 ? 1 : go[u][s[i] - base]);\n\
    \      }\n      v = go[v][s[i] - base];\n      freq[v]++;\n    }\n\n    for(int\
    \ i = ssize(len) - 1; i > 0; i--)\n      freq[link[i]] += freq[i];\n    freq[0]\
    \ = freq[1] = 0;\n  }\n};\n"
  code: "template<unsigned sigma = 26, char base = 'a'>\nstruct palindromicTree {\n\
    \  vector<int> len, link;\n  vector<ll> freq;\n  vector<array<int, sigma>> go;\n\
    \n  palindromicTree(string s) {\n    array<int, sigma> unit;\n    fill(unit.begin(),\
    \ unit.end(), -1);\n    len = link = {-1, 0}, go = {unit, unit}, freq = {0, 0};\n\
    \    len.reserve(ssize(s) + 2);\n    link.reserve(ssize(s) + 2);\n    go.reserve(ssize(s)\
    \ + 2);\n    freq.reserve(ssize(s) + 2);\n\n    int v = 0;\n    for(int i = 0;\
    \ i < ssize(s); i++) {\n      while(len[v] == i or s[i - len[v] - 1] != s[i])\n\
    \        v = link[v];\n      if (go[v][s[i] - base] == -1) {\n        go[v][s[i]\
    \ - base] = ssize(len);\n        len.emplace_back(len[v] + 2);\n        freq.emplace_back();\n\
    \        go.emplace_back(unit);\n        int u = link[v];\n        while(u !=\
    \ -1 and s[i - len[u] - 1] != s[i])\n          u = link[u];\n        link.emplace_back(u\
    \ == -1 ? 1 : go[u][s[i] - base]);\n      }\n      v = go[v][s[i] - base];\n \
    \     freq[v]++;\n    }\n\n    for(int i = ssize(len) - 1; i > 0; i--)\n     \
    \ freq[link[i]] += freq[i];\n    freq[0] = freq[1] = 0;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/palindromicTree.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki_2606.test.cpp
documentation_of: string/palindromicTree.cpp
layout: document
redirect_from:
- /library/string/palindromicTree.cpp
- /library/string/palindromicTree.cpp.html
title: string/palindromicTree.cpp
---
