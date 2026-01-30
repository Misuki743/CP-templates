---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/primitive_root.test.cpp
    title: test/primitive_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numtheory/primitive_root.cpp\"\n//#include \"numtheory/fastFactorize.cpp\"\
    \n\null primitiveRoot(ull p) {\n  auto fac = factor(p - 1);\n  ranges::sort(fac);\n\
    \  fac.resize(unique(fac.begin(), fac.end()) - fac.begin());\n  auto test = [p,\
    \ fac](ull x) {\n    for(ull d : fac)\n      if (modpow(x, (p - 1) / d, p) ==\
    \ 1)\n        return false;\n    return true;\n  };\n  static mt19937_64 rng(clock);\n\
    \  uniform_int_distribution<ull> unif(1, p - 1);\n  ull root;\n  while(!test(root\
    \ = unif(rng)));\n  return root;\n}\n"
  code: "//#include \"numtheory/fastFactorize.cpp\"\n\null primitiveRoot(ull p) {\n\
    \  auto fac = factor(p - 1);\n  ranges::sort(fac);\n  fac.resize(unique(fac.begin(),\
    \ fac.end()) - fac.begin());\n  auto test = [p, fac](ull x) {\n    for(ull d :\
    \ fac)\n      if (modpow(x, (p - 1) / d, p) == 1)\n        return false;\n   \
    \ return true;\n  };\n  static mt19937_64 rng(clock);\n  uniform_int_distribution<ull>\
    \ unif(1, p - 1);\n  ull root;\n  while(!test(root = unif(rng)));\n  return root;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/primitive_root.cpp
  requiredBy: []
  timestamp: '2025-12-12 18:41:06+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/primitive_root.test.cpp
documentation_of: numtheory/primitive_root.cpp
layout: document
redirect_from:
- /library/numtheory/primitive_root.cpp
- /library/numtheory/primitive_root.cpp.html
title: numtheory/primitive_root.cpp
---
