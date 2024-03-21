---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/compositional_inverse_of_formal_power_series_large.test.cpp
    title: test/compositional_inverse_of_formal_power_series_large.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/compositionalInverse.cpp\"\n//#include \"modint/MontgomeryModInt.cpp\"\
    \n//#include \"poly/NTTmint.cpp\"\n//#include \"poly/FPS.cpp\"\n//#include \"\
    poly/kthTermOfPowers.cpp\"\n\ntemplate<class Mint>\nFPS<Mint> compositionalInverse(FPS<Mint>\
    \ f, int k) {\n  assert(ssize(f) >= 2 and f[0] == 0 and f[1] != 0);\n  mint c\
    \ = f[1];\n  mint invc = 1 / c;\n  for(mint &x : f)\n    x *= invc;\n  k -= 1;\n\
    \  f = kthTermOfPowers(k, k + 1, f);\n  for(int i = 1; i <= k; i++)\n    f[i]\
    \ *= mint(k) / i;\n  ranges::reverse(f);\n  f = f.log(k + 1);\n  mint inv = 1\
    \ / mint(-k);\n  for(mint &x : f) x *= inv;\n  f = f.exp(k + 1);\n  f.insert(f.begin(),\
    \ Mint(0));\n  f.pop_back();\n  for(mint buf = 1; mint &x : f)\n    x *= buf,\
    \ buf *= invc;\n  return f;\n}\n"
  code: "//#include \"modint/MontgomeryModInt.cpp\"\n//#include \"poly/NTTmint.cpp\"\
    \n//#include \"poly/FPS.cpp\"\n//#include \"poly/kthTermOfPowers.cpp\"\n\ntemplate<class\
    \ Mint>\nFPS<Mint> compositionalInverse(FPS<Mint> f, int k) {\n  assert(ssize(f)\
    \ >= 2 and f[0] == 0 and f[1] != 0);\n  mint c = f[1];\n  mint invc = 1 / c;\n\
    \  for(mint &x : f)\n    x *= invc;\n  k -= 1;\n  f = kthTermOfPowers(k, k + 1,\
    \ f);\n  for(int i = 1; i <= k; i++)\n    f[i] *= mint(k) / i;\n  ranges::reverse(f);\n\
    \  f = f.log(k + 1);\n  mint inv = 1 / mint(-k);\n  for(mint &x : f) x *= inv;\n\
    \  f = f.exp(k + 1);\n  f.insert(f.begin(), Mint(0));\n  f.pop_back();\n  for(mint\
    \ buf = 1; mint &x : f)\n    x *= buf, buf *= invc;\n  return f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/compositionalInverse.cpp
  requiredBy: []
  timestamp: '2024-03-22 01:59:24+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/compositional_inverse_of_formal_power_series_large.test.cpp
documentation_of: poly/compositionalInverse.cpp
layout: document
redirect_from:
- /library/poly/compositionalInverse.cpp
- /library/poly/compositionalInverse.cpp.html
title: poly/compositionalInverse.cpp
---
