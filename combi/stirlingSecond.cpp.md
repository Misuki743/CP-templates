---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/stirling_number_of_the_second_kind.test.cpp
    title: test/stirling_number_of_the_second_kind.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"combi/stirlingSecond.cpp\"\n//#include \"modint/MontgomeryModInt.cpp\"\
    \n//#include \"poly/NTTmint.cpp\"\n//#include \"poly/FPS.cpp\"\n//#include \"\
    combi/binom.cpp\"\n\ntemplate<class Mint>\nFPS<Mint> stirling_number_second(int\
    \ n) {\n  binomial<Mint> bn(n + 1);\n  FPS<Mint> f(n + 1), g(n + 1);\n  for(int\
    \ i = 0; i <= n; i++) {\n    f[i] = bn.faci(i) * (i % 2 == 1 ? -1 : 1);\n    g[i]\
    \ = bn.faci(i) * mint(i).pow(n);\n  }\n  auto h = f * g;\n  h.resize(n + 1);\n\
    \  return h;\n}\n"
  code: "//#include \"modint/MontgomeryModInt.cpp\"\n//#include \"poly/NTTmint.cpp\"\
    \n//#include \"poly/FPS.cpp\"\n//#include \"combi/binom.cpp\"\n\ntemplate<class\
    \ Mint>\nFPS<Mint> stirling_number_second(int n) {\n  binomial<Mint> bn(n + 1);\n\
    \  FPS<Mint> f(n + 1), g(n + 1);\n  for(int i = 0; i <= n; i++) {\n    f[i] =\
    \ bn.faci(i) * (i % 2 == 1 ? -1 : 1);\n    g[i] = bn.faci(i) * mint(i).pow(n);\n\
    \  }\n  auto h = f * g;\n  h.resize(n + 1);\n  return h;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/stirlingSecond.cpp
  requiredBy: []
  timestamp: '2024-11-24 01:06:04+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/stirling_number_of_the_second_kind.test.cpp
documentation_of: combi/stirlingSecond.cpp
layout: document
redirect_from:
- /library/combi/stirlingSecond.cpp
- /library/combi/stirlingSecond.cpp.html
title: combi/stirlingSecond.cpp
---
