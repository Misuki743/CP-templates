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
  bundledCode: "#line 1 \"matrix.cpp\"\n/**\n * template name: matrix\n * author:\
    \ Misuki\n * last update: 2022/08/21\n * include: mint\n */\n\nusing matrix =\
    \ vector<vector<mint>>;\n\nmatrix mul(matrix a, matrix b) {\n  int n = a.size(),\
    \ m = b[0].size();\n  matrix res(n, vector<mint>(m));\n  for(int i = 0; i < n;\
    \ i++)\n    for(int j = 0; j < m; j++)\n      for(int k = 0; k < b.size(); k++)\n\
    \        res[i][j] += a[i][k] * b[k][j];\n  return res;\n}\n\nmatrix pow(matrix\
    \ a, int index) {\n  matrix res(a.size(), vector<mint>(a.size()));\n  for(int\
    \ i = 0; i < a.size(); i++)\n    res[i][i] = 1;\n  while(index) {\n    if (index\
    \ & 1)\n      res = mul(res, a);\n    a = mul(a, a), index >>= 1;\n  }\n  return\
    \ res;\n}\n"
  code: "/**\n * template name: matrix\n * author: Misuki\n * last update: 2022/08/21\n\
    \ * include: mint\n */\n\nusing matrix = vector<vector<mint>>;\n\nmatrix mul(matrix\
    \ a, matrix b) {\n  int n = a.size(), m = b[0].size();\n  matrix res(n, vector<mint>(m));\n\
    \  for(int i = 0; i < n; i++)\n    for(int j = 0; j < m; j++)\n      for(int k\
    \ = 0; k < b.size(); k++)\n        res[i][j] += a[i][k] * b[k][j];\n  return res;\n\
    }\n\nmatrix pow(matrix a, int index) {\n  matrix res(a.size(), vector<mint>(a.size()));\n\
    \  for(int i = 0; i < a.size(); i++)\n    res[i][i] = 1;\n  while(index) {\n \
    \   if (index & 1)\n      res = mul(res, a);\n    a = mul(a, a), index >>= 1;\n\
    \  }\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: matrix.cpp
  requiredBy: []
  timestamp: '2023-06-16 02:10:58+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix.cpp
layout: document
redirect_from:
- /library/matrix.cpp
- /library/matrix.cpp.html
title: matrix.cpp
---
