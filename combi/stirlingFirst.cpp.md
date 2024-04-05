---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/stirling_number_of_the_first_kind.test.cpp
    title: test/stirling_number_of_the_first_kind.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"combi/stirlingFirst.cpp\"\n//#include<modint/MontgomeryModInt.cpp>\n\
    //#include<poly/NTTmint.cpp>\n//#include<poly/FPS.cpp>\n\ntemplate<class Mint>\n\
    FPS<Mint> stirlingFirst(int n) {\n  vector<FPS<Mint>> fs(n, {0, 1});\n  for(int\
    \ i = 0; i < n; i++)\n    fs[i][0] = -i;\n  return FPS<Mint>::allProd(fs);\n}\n"
  code: "//#include<modint/MontgomeryModInt.cpp>\n//#include<poly/NTTmint.cpp>\n//#include<poly/FPS.cpp>\n\
    \ntemplate<class Mint>\nFPS<Mint> stirlingFirst(int n) {\n  vector<FPS<Mint>>\
    \ fs(n, {0, 1});\n  for(int i = 0; i < n; i++)\n    fs[i][0] = -i;\n  return FPS<Mint>::allProd(fs);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/stirlingFirst.cpp
  requiredBy: []
  timestamp: '2024-01-28 03:46:27+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/stirling_number_of_the_first_kind.test.cpp
documentation_of: combi/stirlingFirst.cpp
layout: document
redirect_from:
- /library/combi/stirlingFirst.cpp
- /library/combi/stirlingFirst.cpp.html
title: combi/stirlingFirst.cpp
---
