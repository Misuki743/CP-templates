---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/static_RMQ.test.cpp
    title: test/static_RMQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/sparseTable.cpp\"\ntemplate<class T>\nstruct sparseTable{\n\
    \  vector<vector<T> > table;\n  function<T(const T&, const T&)> comb;\n  int size\
    \ = 0;\n\n  sparseTable(vector<T> base, function<T(const T&, const T&)> _comb)\
    \ {\n    comb = _comb;\n    size = base.size();\n    table.resize(bit_width((unsigned)size),\
    \ std::vector<T>(size));\n    \n    table[0] = base;\n    for(int i = 1; i < ssize(table);\
    \ i++) {\n      for(int j = 0; j < size; j++) {\n        if (j + (1 << (i - 1))\
    \ < size)\n          table[i][j] = comb(table[i - 1][j], table[i - 1][j + (1 <<\
    \ (i - 1))]);\n        else\n          table[i][j] = table[i - 1][j];\n      }\n\
    \    }\n  }\n\n  T query(int l, int r) {\n    int range = bit_width((unsigned)(r\
    \ - l)) - 1;\n    return comb(table[range][l], table[range][r - (1 << range)]);\n\
    \  }\n};\n"
  code: "template<class T>\nstruct sparseTable{\n  vector<vector<T> > table;\n  function<T(const\
    \ T&, const T&)> comb;\n  int size = 0;\n\n  sparseTable(vector<T> base, function<T(const\
    \ T&, const T&)> _comb) {\n    comb = _comb;\n    size = base.size();\n    table.resize(bit_width((unsigned)size),\
    \ std::vector<T>(size));\n    \n    table[0] = base;\n    for(int i = 1; i < ssize(table);\
    \ i++) {\n      for(int j = 0; j < size; j++) {\n        if (j + (1 << (i - 1))\
    \ < size)\n          table[i][j] = comb(table[i - 1][j], table[i - 1][j + (1 <<\
    \ (i - 1))]);\n        else\n          table[i][j] = table[i - 1][j];\n      }\n\
    \    }\n  }\n\n  T query(int l, int r) {\n    int range = bit_width((unsigned)(r\
    \ - l)) - 1;\n    return comb(table[range][l], table[range][r - (1 << range)]);\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/sparseTable.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/static_RMQ.test.cpp
documentation_of: ds/sparseTable.cpp
layout: document
redirect_from:
- /library/ds/sparseTable.cpp
- /library/ds/sparseTable.cpp.html
title: ds/sparseTable.cpp
---