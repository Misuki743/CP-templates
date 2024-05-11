---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/wildcard_pattern_matching.test.cpp
    title: test/wildcard_pattern_matching.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/wildcardPatternMatcing.cpp\"\n//#include<modint/MontgomeryModInt.cpp>\n\
    //#include<poly/NTTmint.cpp>\n//#include<poly/FPS.cpp>\n\ntemplate<class Mint,\
    \ char base = 'a'>\nvector<bool> wildcardPatternMatching(string s, string t) {\n\
    \  mt19937 rng(clock);\n  uniform_int_distribution<int> unif(1, Mint::get_mod()\
    \ - 1);\n  array<Mint, 26> mp;\n  auto getVal = [&](char c) -> Mint { return c\
    \ == '*' ? Mint(0) : mp[c - base]; };\n  for(Mint &x : mp) x = unif(rng);\n  FPS<Mint>\
    \ tot;\n  FPS<Mint> ss(ssize(s)), tt(ssize(t));\n  for(int i = 0; i < ssize(s);\
    \ i++)\n    ss[i] = getVal(s[i]) * getVal(s[i]) * getVal(s[i]);\n  for(int i =\
    \ 0; i < ssize(t); i++)\n    tt[ssize(t) - i - 1] = getVal(t[i]);\n  tot = ss\
    \ * tt;\n  for(int i = 0; i < ssize(s); i++)\n    ss[i] = getVal(s[i]) * getVal(s[i]);\n\
    \  for(int i = 0; i < ssize(t); i++)\n    tt[ssize(t) - i - 1] = getVal(t[i])\
    \ * getVal(t[i]);\n  tot -= ss * tt * 2;\n  for(int i = 0; i < ssize(s); i++)\n\
    \    ss[i] = getVal(s[i]);\n  for(int i = 0; i < ssize(t); i++)\n    tt[ssize(t)\
    \ - i - 1] = getVal(t[i]) * getVal(t[i]) * getVal(t[i]);\n  tot += ss * tt;\n\
    \  vector<bool> ret(ssize(s) - ssize(t) + 1, false);\n  for(int i = 0; i < ssize(ret);\
    \ i++)\n    ret[i] = tot[i + ssize(t) - 1] == 0;\n  return ret;\n}\n"
  code: "//#include<modint/MontgomeryModInt.cpp>\n//#include<poly/NTTmint.cpp>\n//#include<poly/FPS.cpp>\n\
    \ntemplate<class Mint, char base = 'a'>\nvector<bool> wildcardPatternMatching(string\
    \ s, string t) {\n  mt19937 rng(clock);\n  uniform_int_distribution<int> unif(1,\
    \ Mint::get_mod() - 1);\n  array<Mint, 26> mp;\n  auto getVal = [&](char c) ->\
    \ Mint { return c == '*' ? Mint(0) : mp[c - base]; };\n  for(Mint &x : mp) x =\
    \ unif(rng);\n  FPS<Mint> tot;\n  FPS<Mint> ss(ssize(s)), tt(ssize(t));\n  for(int\
    \ i = 0; i < ssize(s); i++)\n    ss[i] = getVal(s[i]) * getVal(s[i]) * getVal(s[i]);\n\
    \  for(int i = 0; i < ssize(t); i++)\n    tt[ssize(t) - i - 1] = getVal(t[i]);\n\
    \  tot = ss * tt;\n  for(int i = 0; i < ssize(s); i++)\n    ss[i] = getVal(s[i])\
    \ * getVal(s[i]);\n  for(int i = 0; i < ssize(t); i++)\n    tt[ssize(t) - i -\
    \ 1] = getVal(t[i]) * getVal(t[i]);\n  tot -= ss * tt * 2;\n  for(int i = 0; i\
    \ < ssize(s); i++)\n    ss[i] = getVal(s[i]);\n  for(int i = 0; i < ssize(t);\
    \ i++)\n    tt[ssize(t) - i - 1] = getVal(t[i]) * getVal(t[i]) * getVal(t[i]);\n\
    \  tot += ss * tt;\n  vector<bool> ret(ssize(s) - ssize(t) + 1, false);\n  for(int\
    \ i = 0; i < ssize(ret); i++)\n    ret[i] = tot[i + ssize(t) - 1] == 0;\n  return\
    \ ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/wildcardPatternMatcing.cpp
  requiredBy: []
  timestamp: '2024-05-11 22:13:26+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/wildcard_pattern_matching.test.cpp
documentation_of: misc/wildcardPatternMatcing.cpp
layout: document
redirect_from:
- /library/misc/wildcardPatternMatcing.cpp
- /library/misc/wildcardPatternMatcing.cpp.html
title: misc/wildcardPatternMatcing.cpp
---
