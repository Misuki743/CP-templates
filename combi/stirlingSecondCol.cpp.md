---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/stirling_number_of_the_second_kind_fixed_k.test.cpp
    title: test/stirling_number_of_the_second_kind_fixed_k.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"combi/stirlingSecondCol.cpp\"\n//#include \"modint/MontgomeryModInt.cpp\"\
    \n//#include \"poly/NTTmint.cpp\"\n//#include \"poly/FPS.cpp\"\n\ntemplate<class\
    \ Mint>\nFPS<Mint> stirling_number_second_col(int n, int k) {\n  vector<FPS<Mint>>\
    \ fs(k);\n  for(int i = 0; i < k; i++) fs[i] = {1, -(i + 1)};\n  auto F = FPS<Mint>::allProd(fs).inv(n\
    \ - k);\n  return F;\n}\n"
  code: "//#include \"modint/MontgomeryModInt.cpp\"\n//#include \"poly/NTTmint.cpp\"\
    \n//#include \"poly/FPS.cpp\"\n\ntemplate<class Mint>\nFPS<Mint> stirling_number_second_col(int\
    \ n, int k) {\n  vector<FPS<Mint>> fs(k);\n  for(int i = 0; i < k; i++) fs[i]\
    \ = {1, -(i + 1)};\n  auto F = FPS<Mint>::allProd(fs).inv(n - k);\n  return F;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/stirlingSecondCol.cpp
  requiredBy: []
  timestamp: '2025-03-01 02:24:43+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/stirling_number_of_the_second_kind_fixed_k.test.cpp
documentation_of: combi/stirlingSecondCol.cpp
layout: document
redirect_from:
- /library/combi/stirlingSecondCol.cpp
- /library/combi/stirlingSecondCol.cpp.html
title: combi/stirlingSecondCol.cpp
---
