---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/sqrt_of_formal_power_series.test.cpp
    title: test/sqrt_of_formal_power_series.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/FPSsqrt.cpp\"\n//#include<poly/NTTmint.cpp>\n//#include<modint/MontgomeryModInt.cpp>\n\
    //#include<numtheory/sqrtMod.cpp>\n\ntemplate<class Mint>\nFPS<Mint> FPSsqrt(FPS<Mint>\
    \ F, int k) {\n  assert(!F.empty());\n  if (F[0] == 0) {\n    for(int i = 1; i\
    \ < ssize(F); i++) {\n      if (F[i] != 0) {\n        if (i & 1) return {}; //no\
    \ solution\n        if (i / 2 >= k) break;\n        auto Q = FPSsqrt(FPS<Mint>(F.begin()\
    \ + i, F.end()), k - i / 2);\n        if (Q.empty()) return {}; //no solution\n\
    \        Q.resize(k, 0);\n        R::rotate(Q, Q.begin() + k - i / 2);\n     \
    \   return Q;\n      }\n    }\n    return FPS<Mint>(k, 0);\n  }\n\n  Mint sqr\
    \ = sqrt(F[0].get(), Mint::get_mod()), inv2 = 1 / Mint(2);\n  if (sqr == -1) return\
    \ {}; //no solution\n  FPS<Mint> Q(1, sqr);\n  for(int i = 1; (1 << (i - 1)) <\
    \ k; i++) {\n    FPS<Mint> P(1 << i, 0);\n    copy(F.begin(), F.begin() + min(1\
    \ << i, (int)F.size()), P.begin());\n    FPS<Mint> R = P * Q.inv(1 << i);\n  \
    \  for(int j = 0; Mint &x : Q)\n      R[j++] += x;\n    for(Mint &x : R)\n   \
    \   x *= inv2;\n    R.resize(1 << i);\n    R.swap(Q);\n  }\n  Q.resize(k);\n \
    \ return Q;\n}\n"
  code: "//#include<poly/NTTmint.cpp>\n//#include<modint/MontgomeryModInt.cpp>\n//#include<numtheory/sqrtMod.cpp>\n\
    \ntemplate<class Mint>\nFPS<Mint> FPSsqrt(FPS<Mint> F, int k) {\n  assert(!F.empty());\n\
    \  if (F[0] == 0) {\n    for(int i = 1; i < ssize(F); i++) {\n      if (F[i] !=\
    \ 0) {\n        if (i & 1) return {}; //no solution\n        if (i / 2 >= k) break;\n\
    \        auto Q = FPSsqrt(FPS<Mint>(F.begin() + i, F.end()), k - i / 2);\n   \
    \     if (Q.empty()) return {}; //no solution\n        Q.resize(k, 0);\n     \
    \   R::rotate(Q, Q.begin() + k - i / 2);\n        return Q;\n      }\n    }\n\
    \    return FPS<Mint>(k, 0);\n  }\n\n  Mint sqr = sqrt(F[0].get(), Mint::get_mod()),\
    \ inv2 = 1 / Mint(2);\n  if (sqr == -1) return {}; //no solution\n  FPS<Mint>\
    \ Q(1, sqr);\n  for(int i = 1; (1 << (i - 1)) < k; i++) {\n    FPS<Mint> P(1 <<\
    \ i, 0);\n    copy(F.begin(), F.begin() + min(1 << i, (int)F.size()), P.begin());\n\
    \    FPS<Mint> R = P * Q.inv(1 << i);\n    for(int j = 0; Mint &x : Q)\n     \
    \ R[j++] += x;\n    for(Mint &x : R)\n      x *= inv2;\n    R.resize(1 << i);\n\
    \    R.swap(Q);\n  }\n  Q.resize(k);\n  return Q;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/FPSsqrt.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/sqrt_of_formal_power_series.test.cpp
documentation_of: poly/FPSsqrt.cpp
layout: document
redirect_from:
- /library/poly/FPSsqrt.cpp
- /library/poly/FPSsqrt.cpp.html
title: poly/FPSsqrt.cpp
---
