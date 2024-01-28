---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/bernoulli_number.test.cpp
    title: test/bernoulli_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"combi/bernoulliNumber.cpp\"\n//#include<modint/MontgomeryModInt.cpp>\n\
    //#include<poly/NTTmint.cpp>\n//#include<poly/FPS.cpp>\n\ntemplate<class Mint>\n\
    FPS<Mint> bernoulliNumber(int n) {\n  fps fac(n + 2);\n  fac[0] = 1;\n  for(int\
    \ i = 1; i <= n + 1; i++)\n    fac[i] = fac[i - 1] * i;\n  fps f(n + 2);\n  f[n\
    \ + 1] = Mint(1) / fac[n + 1];\n  for(int i = n; i > 0; i--)\n    f[i] = f[i +\
    \ 1] * (i + 1);\n  f.erase(f.begin());\n  f = f.inv(n + 1);\n  for(int i = 0;\
    \ i <= n; i++)\n    f[i] *= fac[i];\n  return f;\n}\n"
  code: "//#include<modint/MontgomeryModInt.cpp>\n//#include<poly/NTTmint.cpp>\n//#include<poly/FPS.cpp>\n\
    \ntemplate<class Mint>\nFPS<Mint> bernoulliNumber(int n) {\n  fps fac(n + 2);\n\
    \  fac[0] = 1;\n  for(int i = 1; i <= n + 1; i++)\n    fac[i] = fac[i - 1] * i;\n\
    \  fps f(n + 2);\n  f[n + 1] = Mint(1) / fac[n + 1];\n  for(int i = n; i > 0;\
    \ i--)\n    f[i] = f[i + 1] * (i + 1);\n  f.erase(f.begin());\n  f = f.inv(n +\
    \ 1);\n  for(int i = 0; i <= n; i++)\n    f[i] *= fac[i];\n  return f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/bernoulliNumber.cpp
  requiredBy: []
  timestamp: '2024-01-28 22:59:51+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/bernoulli_number.test.cpp
documentation_of: combi/bernoulliNumber.cpp
layout: document
redirect_from:
- /library/combi/bernoulliNumber.cpp
- /library/combi/bernoulliNumber.cpp.html
title: combi/bernoulliNumber.cpp
---
