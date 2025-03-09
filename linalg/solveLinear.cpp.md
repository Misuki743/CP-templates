---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/system_of_linear_equations.test.cpp
    title: test/system_of_linear_equations.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/solveLinear.cpp\"\n//#include<modint/MontgomeryModInt.cpp>\n\
    //#include<linalg/matrixMint.cpp>\n\ntemplate<class Mint>\npair<vector<Mint>,\
    \ vector<vector<Mint>>> solve_linear(matrix<Mint> A, vector<Mint> b) {\n  const\
    \ int n = A.n(), m = A.m();\n  assert(n == ssize(b));\n\n  {\n    matrix<Mint>\
    \ tmp(n, m + 1);\n    for(int i = 0; i < n; i++) {\n      for(int j = 0; j < m;\
    \ j++)\n        tmp[i][j] = A[i][j];\n      tmp[i][m] = b[i];\n    }\n    A.swap(tmp);\n\
    \  }\n\n  vector<int> where(m, -1), inv_where(n, -1);\n  for(int row = 0, col\
    \ = 0; row < n and col < m; col++) {\n    int p_row = -1;\n    for(int i = row;\
    \ i < n and p_row == -1; i++)\n      if (A[i][col] != 0) \n        p_row = i;\n\
    \    if (p_row == -1) continue;\n    where[col] = row, inv_where[row] = col;\n\
    \    for(int j = col; j <= m; j++)\n      swap(A[row][j], A[p_row][j]);\n    Mint\
    \ r = 1 / Mint(A[row][col]);\n    for(int j = col; j <= m; j++)\n      A[row][j]\
    \ *= r;\n    for(int i = 0; i < n; i++) {\n      if (i == row or A[i][col] ==\
    \ 0) continue;\n      Mint s = A[i][col];\n      for(int j = col; j <= m; j++)\n\
    \        A[i][j] -= A[row][j] * s;\n    }\n    row++;\n  }\n\n  vector<Mint> ans(m);\n\
    \  for(int i = 0; i < m; i++)\n    if (where[i] != -1)\n      ans[i] = A[where[i]][m];\n\
    \n  for(int i = 0; i < n; i++) {\n    Mint s = -A[i][m];\n    for(int j = 0; j\
    \ < m; j++)\n      s += ans[j] * A[i][j];\n    if (s != 0)\n      return {};\n\
    \  }\n\n  vector<vector<Mint>> basis;\n  for(int col = 0, last_row = 0; col <\
    \ m; col++) {\n    if (where[col] != -1) {\n      last_row = where[col];\n   \
    \ } else {\n      basis.emplace_back(m);\n      basis.back()[col] = 1;\n     \
    \ for(int i = 0; i <= last_row; i++)\n        basis.back()[inv_where[i]] = -A[i][col];\n\
    \    }\n  }\n\n  return make_pair(ans, basis);\n}\n"
  code: "//#include<modint/MontgomeryModInt.cpp>\n//#include<linalg/matrixMint.cpp>\n\
    \ntemplate<class Mint>\npair<vector<Mint>, vector<vector<Mint>>> solve_linear(matrix<Mint>\
    \ A, vector<Mint> b) {\n  const int n = A.n(), m = A.m();\n  assert(n == ssize(b));\n\
    \n  {\n    matrix<Mint> tmp(n, m + 1);\n    for(int i = 0; i < n; i++) {\n   \
    \   for(int j = 0; j < m; j++)\n        tmp[i][j] = A[i][j];\n      tmp[i][m]\
    \ = b[i];\n    }\n    A.swap(tmp);\n  }\n\n  vector<int> where(m, -1), inv_where(n,\
    \ -1);\n  for(int row = 0, col = 0; row < n and col < m; col++) {\n    int p_row\
    \ = -1;\n    for(int i = row; i < n and p_row == -1; i++)\n      if (A[i][col]\
    \ != 0) \n        p_row = i;\n    if (p_row == -1) continue;\n    where[col] =\
    \ row, inv_where[row] = col;\n    for(int j = col; j <= m; j++)\n      swap(A[row][j],\
    \ A[p_row][j]);\n    Mint r = 1 / Mint(A[row][col]);\n    for(int j = col; j <=\
    \ m; j++)\n      A[row][j] *= r;\n    for(int i = 0; i < n; i++) {\n      if (i\
    \ == row or A[i][col] == 0) continue;\n      Mint s = A[i][col];\n      for(int\
    \ j = col; j <= m; j++)\n        A[i][j] -= A[row][j] * s;\n    }\n    row++;\n\
    \  }\n\n  vector<Mint> ans(m);\n  for(int i = 0; i < m; i++)\n    if (where[i]\
    \ != -1)\n      ans[i] = A[where[i]][m];\n\n  for(int i = 0; i < n; i++) {\n \
    \   Mint s = -A[i][m];\n    for(int j = 0; j < m; j++)\n      s += ans[j] * A[i][j];\n\
    \    if (s != 0)\n      return {};\n  }\n\n  vector<vector<Mint>> basis;\n  for(int\
    \ col = 0, last_row = 0; col < m; col++) {\n    if (where[col] != -1) {\n    \
    \  last_row = where[col];\n    } else {\n      basis.emplace_back(m);\n      basis.back()[col]\
    \ = 1;\n      for(int i = 0; i <= last_row; i++)\n        basis.back()[inv_where[i]]\
    \ = -A[i][col];\n    }\n  }\n\n  return make_pair(ans, basis);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/solveLinear.cpp
  requiredBy: []
  timestamp: '2025-03-09 17:24:59+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/system_of_linear_equations.test.cpp
documentation_of: linalg/solveLinear.cpp
layout: document
redirect_from:
- /library/linalg/solveLinear.cpp
- /library/linalg/solveLinear.cpp.html
title: linalg/solveLinear.cpp
---
