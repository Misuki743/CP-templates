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
  bundledCode: "#line 1 \"sparseTable2D.cpp\"\n/**\n * template name: sparseTable2D\n\
    \ * author: Misuki\n * last update: 2023/11/30\n * verify: CF 1301-E\n */\ntemplate<class\
    \ T>\nstruct sparseTable2D {\n  vector<vector<vector<vector<T>>>> table;\n  function<T(T,\
    \ T)> comb;\n  int size = 0;\n\n  sparseTable2D(vector<sparseTable<T>> &base,\
    \ function<T(T, T)> _comb) {\n    comb = _comb;\n    size = base.size();\n   \
    \ vector<vector<vector<T>>> tmp(size);\n    for(int i = 0; i < size; i++)\n  \
    \    tmp[i] = base[i].table;\n    table.resize(bit_width((unsigned)size), tmp);\n\
    \    for(int i = 1; i < (int)table.size(); i++) {\n      for(int j = 0; j < size;\
    \ j++) {\n        for(int k = 0; k < (int)table[i][j].size(); k++) {\n       \
    \   for(int l = 0; l < (int)table[i][j][k].size(); l++) {\n            if (j +\
    \ (1 << (i - 1)) < size)\n              table[i][j][k][l] = comb(table[i - 1][j][k][l],\
    \ table[i - 1][j + (1 << (i - 1))][k][l]);\n            else\n              table[i][j][k][l]\
    \ = table[i - 1][j][k][l];\n          }\n        }\n      }\n    }\n  }\n\n  //query\
    \ range in [r1, r2) x [c1, c2)\n  T query(int r1, int c1, int r2, int c2) {\n\
    \    int rRange = bit_width((unsigned)(r2 - r1)) - 1, cRange = bit_width((unsigned)(c2\
    \ - c1)) - 1;\n    return comb(comb(table[rRange][r1][cRange][c1], table[rRange][r1][cRange][c2\
    \ - (1 << cRange)]),\n                comb(table[rRange][r2 - (1 << rRange)][cRange][c1],\
    \ table[rRange][r2 - (1 << rRange)][cRange][c2 - (1 << cRange)]));\n  }\n};\n"
  code: "/**\n * template name: sparseTable2D\n * author: Misuki\n * last update:\
    \ 2023/11/30\n * verify: CF 1301-E\n */\ntemplate<class T>\nstruct sparseTable2D\
    \ {\n  vector<vector<vector<vector<T>>>> table;\n  function<T(T, T)> comb;\n \
    \ int size = 0;\n\n  sparseTable2D(vector<sparseTable<T>> &base, function<T(T,\
    \ T)> _comb) {\n    comb = _comb;\n    size = base.size();\n    vector<vector<vector<T>>>\
    \ tmp(size);\n    for(int i = 0; i < size; i++)\n      tmp[i] = base[i].table;\n\
    \    table.resize(bit_width((unsigned)size), tmp);\n    for(int i = 1; i < (int)table.size();\
    \ i++) {\n      for(int j = 0; j < size; j++) {\n        for(int k = 0; k < (int)table[i][j].size();\
    \ k++) {\n          for(int l = 0; l < (int)table[i][j][k].size(); l++) {\n  \
    \          if (j + (1 << (i - 1)) < size)\n              table[i][j][k][l] = comb(table[i\
    \ - 1][j][k][l], table[i - 1][j + (1 << (i - 1))][k][l]);\n            else\n\
    \              table[i][j][k][l] = table[i - 1][j][k][l];\n          }\n     \
    \   }\n      }\n    }\n  }\n\n  //query range in [r1, r2) x [c1, c2)\n  T query(int\
    \ r1, int c1, int r2, int c2) {\n    int rRange = bit_width((unsigned)(r2 - r1))\
    \ - 1, cRange = bit_width((unsigned)(c2 - c1)) - 1;\n    return comb(comb(table[rRange][r1][cRange][c1],\
    \ table[rRange][r1][cRange][c2 - (1 << cRange)]),\n                comb(table[rRange][r2\
    \ - (1 << rRange)][cRange][c1], table[rRange][r2 - (1 << rRange)][cRange][c2 -\
    \ (1 << cRange)]));\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: sparseTable2D.cpp
  requiredBy: []
  timestamp: '2024-01-06 18:21:41+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: sparseTable2D.cpp
layout: document
redirect_from:
- /library/sparseTable2D.cpp
- /library/sparseTable2D.cpp.html
title: sparseTable2D.cpp
---
