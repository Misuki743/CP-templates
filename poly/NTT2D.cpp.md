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
  bundledCode: "#line 1 \"poly/NTT2D.cpp\"\nvector<vector<mint>> NTT2D(vector<vector<mint>>\
    \ f, vector<vector<mint>> g) {\n  static NTT ntt;\n  int n1 = size(f), m1 = size(f[0]),\
    \ n2 = size(g), m2 = size(g[0]);\n\n  int n = n1 + n2 - 1, m = m1 + m2 - 1;\n\
    \  auto flatten = [n, m](vector<vector<mint>> &f) {\n    vector<mint> g(n * m);\n\
    \    for(int i = 0; i < ssize(f); i++)\n      for(int j = 0; j < ssize(f[i]);\
    \ j++)\n        g[i * m + j] = f[i][j];\n    return g;\n  };\n\n  auto hp = ntt.conv(flatten(f),\
    \ flatten(g));\n  vector h(n, vector(m, mint(0)));\n  for(int i = 0; i < n; i++)\n\
    \    for(int j = 0; j < m; j++)\n      h[i][j] = hp[i * m + j];\n  return h;\n\
    }\n"
  code: "vector<vector<mint>> NTT2D(vector<vector<mint>> f, vector<vector<mint>> g)\
    \ {\n  static NTT ntt;\n  int n1 = size(f), m1 = size(f[0]), n2 = size(g), m2\
    \ = size(g[0]);\n\n  int n = n1 + n2 - 1, m = m1 + m2 - 1;\n  auto flatten = [n,\
    \ m](vector<vector<mint>> &f) {\n    vector<mint> g(n * m);\n    for(int i = 0;\
    \ i < ssize(f); i++)\n      for(int j = 0; j < ssize(f[i]); j++)\n        g[i\
    \ * m + j] = f[i][j];\n    return g;\n  };\n\n  auto hp = ntt.conv(flatten(f),\
    \ flatten(g));\n  vector h(n, vector(m, mint(0)));\n  for(int i = 0; i < n; i++)\n\
    \    for(int j = 0; j < m; j++)\n      h[i][j] = hp[i * m + j];\n  return h;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/NTT2D.cpp
  requiredBy: []
  timestamp: '2024-08-03 15:30:37+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/NTT2D.cpp
layout: document
redirect_from:
- /library/poly/NTT2D.cpp
- /library/poly/NTT2D.cpp.html
title: poly/NTT2D.cpp
---
