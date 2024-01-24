---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/subset_convolution.test.cpp
    title: test/subset_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"setfunc/fastSubsetTransform.cpp\"\n//#include<poly/FPS.cpp>\n\
    \ntemplate<class FPS>\nvector<FPS> FST(FPS f) {\n  assert(popcount(f.size()) ==\
    \ 1);\n  int n = bit_width(f.size()) - 1;\n  vector<FPS> fHat(1 << n, FPS(n +\
    \ 1));\n  for(unsigned i = 0; i < (1 << n); i++)\n    fHat[i][popcount(i)] = f[i];\n\
    \n  for(int k = 0; k < n; k++)\n    for(int i = 0; i < (1 << n); i++)\n      if\
    \ (!(i >> k & 1))\n        for(int j = 0; j <= n; j++)\n          fHat[i|1<<k][j]\
    \ += fHat[i][j];\n\n  return fHat;\n}\n\ntemplate<class FPS>\nFPS FSTinv(vector<FPS>\
    \ fHat) {\n  int n = bit_width(fHat.size()) - 1;\n  for(int k = 0; k < n; k++)\n\
    \    for(int i = 0; i < (1 << n); i++)\n      if (!(i >> k & 1))\n        for(int\
    \ j = 0; j <= n; j++)\n          fHat[i|1<<k][j] -= fHat[i][j];\n\n  FPS f(1 <<\
    \ n);\n  for(unsigned i = 0; i < (1 << n); i++)\n    f[i] = fHat[i][popcount(i)];\n\
    \n  return f;\n}\n\ntemplate<class FPS>\nFPS conv(FPS f, FPS g) {\n  assert(ssize(f)\
    \ == ssize(g));\n  auto fHat = FST(f), gHat = FST(g);\n  for(int i = 0; i < ssize(fHat);\
    \ i++) {\n    fHat[i] *= gHat[i];\n    fHat[i].resize(ssize(gHat[i]));\n  }\n\
    \  return FSTinv(fHat);\n}\n\n/* OMG this is so slowwwwwwwwwwwwwwwww\nFPS subsetPow(FPS\
    \ f, long long idx) {\n  int n = __lg(f.size());\n  vector<FPS> fHat = FST(f);\n\
    \  for(int i = 0; i < fHat.size(); i++)\n    fHat[i] = fHat[i].pow(idx, n + 1);\n\
    \  f = FSTinv(fHat);\n  return f;\n}\n*/\n"
  code: "//#include<poly/FPS.cpp>\n\ntemplate<class FPS>\nvector<FPS> FST(FPS f) {\n\
    \  assert(popcount(f.size()) == 1);\n  int n = bit_width(f.size()) - 1;\n  vector<FPS>\
    \ fHat(1 << n, FPS(n + 1));\n  for(unsigned i = 0; i < (1 << n); i++)\n    fHat[i][popcount(i)]\
    \ = f[i];\n\n  for(int k = 0; k < n; k++)\n    for(int i = 0; i < (1 << n); i++)\n\
    \      if (!(i >> k & 1))\n        for(int j = 0; j <= n; j++)\n          fHat[i|1<<k][j]\
    \ += fHat[i][j];\n\n  return fHat;\n}\n\ntemplate<class FPS>\nFPS FSTinv(vector<FPS>\
    \ fHat) {\n  int n = bit_width(fHat.size()) - 1;\n  for(int k = 0; k < n; k++)\n\
    \    for(int i = 0; i < (1 << n); i++)\n      if (!(i >> k & 1))\n        for(int\
    \ j = 0; j <= n; j++)\n          fHat[i|1<<k][j] -= fHat[i][j];\n\n  FPS f(1 <<\
    \ n);\n  for(unsigned i = 0; i < (1 << n); i++)\n    f[i] = fHat[i][popcount(i)];\n\
    \n  return f;\n}\n\ntemplate<class FPS>\nFPS conv(FPS f, FPS g) {\n  assert(ssize(f)\
    \ == ssize(g));\n  auto fHat = FST(f), gHat = FST(g);\n  for(int i = 0; i < ssize(fHat);\
    \ i++) {\n    fHat[i] *= gHat[i];\n    fHat[i].resize(ssize(gHat[i]));\n  }\n\
    \  return FSTinv(fHat);\n}\n\n/* OMG this is so slowwwwwwwwwwwwwwwww\nFPS subsetPow(FPS\
    \ f, long long idx) {\n  int n = __lg(f.size());\n  vector<FPS> fHat = FST(f);\n\
    \  for(int i = 0; i < fHat.size(); i++)\n    fHat[i] = fHat[i].pow(idx, n + 1);\n\
    \  f = FSTinv(fHat);\n  return f;\n}\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/fastSubsetTransform.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/subset_convolution.test.cpp
documentation_of: setfunc/fastSubsetTransform.cpp
layout: document
redirect_from:
- /library/setfunc/fastSubsetTransform.cpp
- /library/setfunc/fastSubsetTransform.cpp.html
title: setfunc/fastSubsetTransform.cpp
---
