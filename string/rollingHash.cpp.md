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
  bundledCode: "#line 1 \"string/rollingHash.cpp\"\ntemplate<class Mint, int cnt>\n\
    struct rollingHash {\n  int sz;\n  vector<vector<Mint>> powr;\n  rollingHash(int\
    \ mxLen) : sz(mxLen + 1), powr(cnt, vector<Mint>(mxLen + 1)) {\n    mt19937 rng(clock);\n\
    \    uniform_int_distribution<int> unif(0, Mint::get_mod() - 1);\n    for(int\
    \ i = 0; i < cnt; i++) {\n      powr[i][0] = 1, powr[i][1] = unif(rng);\n    \
    \  for(int j = 2; j < sz; j++)\n        powr[i][j] = powr[i][j - 1] * powr[i][1];\n\
    \    }\n  }\n\n  //pad a zero before first char\n  vector<vector<Mint>> prefixHash(string\
    \ s) {\n    vector h(cnt, vector<Mint>(ssize(s) + 1));\n    for(int i = 0; i <\
    \ cnt; i++)\n      for(int j = 0; j < ssize(s); j++)\n        h[i][j + 1] = h[i][j]\
    \ * powr[i][1] + Mint(s[j]);\n    return h;\n  }\n\n  //return hash of [l, r),\
    \ 0-based\n  array<Mint, cnt> substringHash(vector<vector<Mint>> &h, int l, int\
    \ r) {\n    array<Mint, cnt> ret;\n    for(int i = 0; i < cnt; i++)\n      ret[i]\
    \ = h[i][r] - h[i][l] * powr[i][r - l];\n    return ret;\n  }\n};\n"
  code: "template<class Mint, int cnt>\nstruct rollingHash {\n  int sz;\n  vector<vector<Mint>>\
    \ powr;\n  rollingHash(int mxLen) : sz(mxLen + 1), powr(cnt, vector<Mint>(mxLen\
    \ + 1)) {\n    mt19937 rng(clock);\n    uniform_int_distribution<int> unif(0,\
    \ Mint::get_mod() - 1);\n    for(int i = 0; i < cnt; i++) {\n      powr[i][0]\
    \ = 1, powr[i][1] = unif(rng);\n      for(int j = 2; j < sz; j++)\n        powr[i][j]\
    \ = powr[i][j - 1] * powr[i][1];\n    }\n  }\n\n  //pad a zero before first char\n\
    \  vector<vector<Mint>> prefixHash(string s) {\n    vector h(cnt, vector<Mint>(ssize(s)\
    \ + 1));\n    for(int i = 0; i < cnt; i++)\n      for(int j = 0; j < ssize(s);\
    \ j++)\n        h[i][j + 1] = h[i][j] * powr[i][1] + Mint(s[j]);\n    return h;\n\
    \  }\n\n  //return hash of [l, r), 0-based\n  array<Mint, cnt> substringHash(vector<vector<Mint>>\
    \ &h, int l, int r) {\n    array<Mint, cnt> ret;\n    for(int i = 0; i < cnt;\
    \ i++)\n      ret[i] = h[i][r] - h[i][l] * powr[i][r - l];\n    return ret;\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/rollingHash.cpp
  requiredBy: []
  timestamp: '2024-05-19 17:15:40+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rollingHash.cpp
layout: document
redirect_from:
- /library/string/rollingHash.cpp
- /library/string/rollingHash.cpp.html
title: string/rollingHash.cpp
---
