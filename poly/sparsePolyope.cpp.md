---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/inv_of_formal_power_series_sparse.test.cpp
    title: test/inv_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/log_of_formal_power_series_sparse.test.cpp
    title: test/log_of_formal_power_series_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/sparsePolyope.cpp\"\n//#include<poly/FPS.cpp>\n//#include<poly/NTTmint.cpp>\n\
    //#include<modint/MontgomeryModInt.cpp>\n\nnamespace sparsePolyope {\n  template<class\
    \ Mint>\n  vector<pair<int, Mint>> sparsify(FPS<Mint> f) {\n    vector<pair<int,\
    \ Mint>> g;\n    for(int i = 0; i < ssize(f); i++)\n      if (f[i] != 0)\n   \
    \     g.emplace_back(i, f[i]);\n    return g;\n  }\n  template<class Mint>\n \
    \ FPS<Mint> sparseInv(FPS<Mint> f, int k) {\n    assert(f[0] != 0);\n    FPS<Mint>\
    \ g(k);\n    Mint inv = 1 / f[0];\n    g[0] = 1;\n    auto fs = sparsify(f);\n\
    \    for(int i = 0; i < k; i++) {\n      for(auto [j, val] : fs | V::drop(1))\n\
    \        if (j <= i)\n          g[i] -= g[i - j] * val;\n      g[i] *= inv;\n\
    \    }\n    return g;\n  }\n  template<class Mint>\n  FPS<Mint> sparseLog(FPS<Mint>\
    \ f, int k) {\n    assert(f[0] == 1);\n    auto invf = sparseInv(f, k);\n    auto\
    \ fs = sparsify(f.derivative());\n    FPS<Mint> g(k - 1);\n    for(int i = 0;\
    \ i < k - 1; i++)\n      for(auto [j, val] : fs)\n        if (j <= i)\n      \
    \    g[i] += invf[i - j] * val;\n    return g.integral();\n  }\n}\n\nusing namespace\
    \ sparsePolyope;\n"
  code: "//#include<poly/FPS.cpp>\n//#include<poly/NTTmint.cpp>\n//#include<modint/MontgomeryModInt.cpp>\n\
    \nnamespace sparsePolyope {\n  template<class Mint>\n  vector<pair<int, Mint>>\
    \ sparsify(FPS<Mint> f) {\n    vector<pair<int, Mint>> g;\n    for(int i = 0;\
    \ i < ssize(f); i++)\n      if (f[i] != 0)\n        g.emplace_back(i, f[i]);\n\
    \    return g;\n  }\n  template<class Mint>\n  FPS<Mint> sparseInv(FPS<Mint> f,\
    \ int k) {\n    assert(f[0] != 0);\n    FPS<Mint> g(k);\n    Mint inv = 1 / f[0];\n\
    \    g[0] = 1;\n    auto fs = sparsify(f);\n    for(int i = 0; i < k; i++) {\n\
    \      for(auto [j, val] : fs | V::drop(1))\n        if (j <= i)\n          g[i]\
    \ -= g[i - j] * val;\n      g[i] *= inv;\n    }\n    return g;\n  }\n  template<class\
    \ Mint>\n  FPS<Mint> sparseLog(FPS<Mint> f, int k) {\n    assert(f[0] == 1);\n\
    \    auto invf = sparseInv(f, k);\n    auto fs = sparsify(f.derivative());\n \
    \   FPS<Mint> g(k - 1);\n    for(int i = 0; i < k - 1; i++)\n      for(auto [j,\
    \ val] : fs)\n        if (j <= i)\n          g[i] += invf[i - j] * val;\n    return\
    \ g.integral();\n  }\n}\n\nusing namespace sparsePolyope;\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/sparsePolyope.cpp
  requiredBy: []
  timestamp: '2024-02-06 18:26:29+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/inv_of_formal_power_series_sparse.test.cpp
  - test/log_of_formal_power_series_sparse.test.cpp
documentation_of: poly/sparsePolyope.cpp
layout: document
redirect_from:
- /library/poly/sparsePolyope.cpp
- /library/poly/sparsePolyope.cpp.html
title: poly/sparsePolyope.cpp
---
