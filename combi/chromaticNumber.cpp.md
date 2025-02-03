---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"combi/chromaticNumber.cpp\"\n//#include \"modint/dynamicMontgomeryModInt.cpp\"\
    \n//#include \"numtheory/fastFactorize.cpp\"\n\ntemplate<> uint32_t MontgomeryModInt<123>::mod\
    \ = 0;\ntemplate<> uint32_t MontgomeryModInt<123>::n2 = 0;\ntemplate<> uint32_t\
    \ MontgomeryModInt<123>::r = 0;\nint chromatic_number(vector<vector<bool>> g)\
    \ {\n  const int n = ssize(g);\n\n  mt19937 rng(clock);\n  uniform_int_distribution<int>\
    \ unif(1 << 29, 1 << 30);\n  int p = 4;\n  while(!isPrime(p)) p = unif(rng);\n\
    \  using Mint = MontgomeryModInt<123>;\n  Mint::set_mod(p);\n\n  vector<Mint>\
    \ I(1 << n);\n  I[0] = 1;\n  for(unsigned msk = 1; msk < (1 << n); msk++) {\n\
    \    int v = countr_zero(bit_floor(msk));\n    I[msk] = I[msk ^ (1 << v)];\n \
    \   unsigned msk2 = msk ^ (1 << v);\n    for(int x = 0; x < n; x++)\n      if\
    \ (g[v][x] and (msk2 >> x & 1))\n        msk2 ^= 1 << x;\n    I[msk] += I[msk2];\n\
    \  }\n\n  auto check = [&](int c) {\n    if (c == n) return true;\n    Mint cnt\
    \ = 0;\n    for(unsigned msk = 0; msk < (1 << n); msk++)\n      cnt += I[msk].pow(c)\
    \ * (popcount(msk ^ ((1 << n) - 1)) % 2 == 1 ? -1 : 1);\n    return cnt != 0;\n\
    \  };\n\n  int c = 1;\n  while(!check(c)) c++;\n\n  return c;\n}\n"
  code: "//#include \"modint/dynamicMontgomeryModInt.cpp\"\n//#include \"numtheory/fastFactorize.cpp\"\
    \n\ntemplate<> uint32_t MontgomeryModInt<123>::mod = 0;\ntemplate<> uint32_t MontgomeryModInt<123>::n2\
    \ = 0;\ntemplate<> uint32_t MontgomeryModInt<123>::r = 0;\nint chromatic_number(vector<vector<bool>>\
    \ g) {\n  const int n = ssize(g);\n\n  mt19937 rng(clock);\n  uniform_int_distribution<int>\
    \ unif(1 << 29, 1 << 30);\n  int p = 4;\n  while(!isPrime(p)) p = unif(rng);\n\
    \  using Mint = MontgomeryModInt<123>;\n  Mint::set_mod(p);\n\n  vector<Mint>\
    \ I(1 << n);\n  I[0] = 1;\n  for(unsigned msk = 1; msk < (1 << n); msk++) {\n\
    \    int v = countr_zero(bit_floor(msk));\n    I[msk] = I[msk ^ (1 << v)];\n \
    \   unsigned msk2 = msk ^ (1 << v);\n    for(int x = 0; x < n; x++)\n      if\
    \ (g[v][x] and (msk2 >> x & 1))\n        msk2 ^= 1 << x;\n    I[msk] += I[msk2];\n\
    \  }\n\n  auto check = [&](int c) {\n    if (c == n) return true;\n    Mint cnt\
    \ = 0;\n    for(unsigned msk = 0; msk < (1 << n); msk++)\n      cnt += I[msk].pow(c)\
    \ * (popcount(msk ^ ((1 << n) - 1)) % 2 == 1 ? -1 : 1);\n    return cnt != 0;\n\
    \  };\n\n  int c = 1;\n  while(!check(c)) c++;\n\n  return c;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/chromaticNumber.cpp
  requiredBy: []
  timestamp: '2025-02-03 23:28:39+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: combi/chromaticNumber.cpp
layout: document
redirect_from:
- /library/combi/chromaticNumber.cpp
- /library/combi/chromaticNumber.cpp.html
title: combi/chromaticNumber.cpp
---
