---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/sharp_p_subset_sum.test.cpp
    title: test/sharp_p_subset_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/sharpPSubsetSum.cpp\"\n//#include<modint/MontgomeryModInt>\n\
    //#include<poly/NTTmint>\n//#include<poly/FPS>\n\ntemplate<class Mint>\nFPS<Mint>\
    \ sharpPSubsetSum(vector<int> w, int C) {\n  vector<int> freq(C + 1);\n  for(int\
    \ x : w)\n    if (x <= C)\n      freq[x]++;\n\n  vector<Mint> Inv(C + 1);\n  Inv[1]\
    \ = 1;\n  for(int i = 2; i < ssize(Inv); i++)\n    Inv[i] = (Mint::get_mod() -\
    \ Mint::get_mod() / i) * Inv[Mint::get_mod() % i];\n\n  FPS<Mint> f(C + 1);\n\
    \  for(int i = 1; i <= C; i++)\n    for(int j = 1; j * i <= C; j++)\n      f[j\
    \ * i] += freq[i] * Inv[j] * (j % 2 == 0 ? -1 : 1);\n\n  return f.exp(C + 1);\n\
    }\n"
  code: "//#include<modint/MontgomeryModInt>\n//#include<poly/NTTmint>\n//#include<poly/FPS>\n\
    \ntemplate<class Mint>\nFPS<Mint> sharpPSubsetSum(vector<int> w, int C) {\n  vector<int>\
    \ freq(C + 1);\n  for(int x : w)\n    if (x <= C)\n      freq[x]++;\n\n  vector<Mint>\
    \ Inv(C + 1);\n  Inv[1] = 1;\n  for(int i = 2; i < ssize(Inv); i++)\n    Inv[i]\
    \ = (Mint::get_mod() - Mint::get_mod() / i) * Inv[Mint::get_mod() % i];\n\n  FPS<Mint>\
    \ f(C + 1);\n  for(int i = 1; i <= C; i++)\n    for(int j = 1; j * i <= C; j++)\n\
    \      f[j * i] += freq[i] * Inv[j] * (j % 2 == 0 ? -1 : 1);\n\n  return f.exp(C\
    \ + 1);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/sharpPSubsetSum.cpp
  requiredBy: []
  timestamp: '2024-02-06 18:50:15+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/sharp_p_subset_sum.test.cpp
documentation_of: misc/sharpPSubsetSum.cpp
layout: document
redirect_from:
- /library/misc/sharpPSubsetSum.cpp
- /library/misc/sharpPSubsetSum.cpp.html
title: misc/sharpPSubsetSum.cpp
---
