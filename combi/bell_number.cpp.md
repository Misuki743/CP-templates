---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/bell_number.test.cpp
    title: test/bell_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"combi/bell_number.cpp\"\n//#include \"modint/MontgomeryModInt.cpp\"\
    \n//#include \"poly/NTTmint.cpp\"\n//#include \"poly/FPS.cpp\"\n//#include \"\
    combi/binom.cpp\"\n\ntemplate<class Mint>\nFPS<Mint> bell_number(int n) {\n  binomial<Mint>\
    \ bn(n);\n  FPS<Mint> f(n);\n  for(int i = 1; i < n; i++) f[i] = bn.faci(i);\n\
    \  f = f.exp(n);\n  for(int i = 0; i < n; i++) f[i] *= bn.fac(i);\n  return f;\n\
    }\n"
  code: "//#include \"modint/MontgomeryModInt.cpp\"\n//#include \"poly/NTTmint.cpp\"\
    \n//#include \"poly/FPS.cpp\"\n//#include \"combi/binom.cpp\"\n\ntemplate<class\
    \ Mint>\nFPS<Mint> bell_number(int n) {\n  binomial<Mint> bn(n);\n  FPS<Mint>\
    \ f(n);\n  for(int i = 1; i < n; i++) f[i] = bn.faci(i);\n  f = f.exp(n);\n  for(int\
    \ i = 0; i < n; i++) f[i] *= bn.fac(i);\n  return f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/bell_number.cpp
  requiredBy: []
  timestamp: '2024-11-24 01:06:04+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/bell_number.test.cpp
documentation_of: combi/bell_number.cpp
layout: document
redirect_from:
- /library/combi/bell_number.cpp
- /library/combi/bell_number.cpp.html
title: combi/bell_number.cpp
---
