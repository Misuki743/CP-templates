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
  bundledCode: "#line 1 \"ds/DSU.cpp\"\n/**\n * template name: DSU\n * author: Misuki\n\
    \ * last update: 2024/01/01\n * verify: Library Checker - Unionfind\n */\n\nstruct\
    \ DSU {\n  vector<int> bos, sz;\n  int size;\n\n  DSU(int _size) : bos(_size),\
    \ sz(_size, 1), size(_size) {\n    iota(bos.begin(), bos.end(), 0);\n  }\n\n \
    \ int query(int v) {\n    if (bos[v] == v)\n      return v;\n    else\n      return\
    \ bos[v] = query(bos[v]);\n  }\n\n  bool merge(int v1, int v2) {\n    int b1 =\
    \ query(v1), b2 = query(v2);\n\n    if (b1 == b2)\n      return false;\n\n   \
    \ if (sz[b1] > sz[b2])\n      swap(b1, b2);\n    bos[b1] = b2, sz[b2] += sz[b1];\n\
    \n    return true;\n  }\n};\n"
  code: "/**\n * template name: DSU\n * author: Misuki\n * last update: 2024/01/01\n\
    \ * verify: Library Checker - Unionfind\n */\n\nstruct DSU {\n  vector<int> bos,\
    \ sz;\n  int size;\n\n  DSU(int _size) : bos(_size), sz(_size, 1), size(_size)\
    \ {\n    iota(bos.begin(), bos.end(), 0);\n  }\n\n  int query(int v) {\n    if\
    \ (bos[v] == v)\n      return v;\n    else\n      return bos[v] = query(bos[v]);\n\
    \  }\n\n  bool merge(int v1, int v2) {\n    int b1 = query(v1), b2 = query(v2);\n\
    \n    if (b1 == b2)\n      return false;\n\n    if (sz[b1] > sz[b2])\n      swap(b1,\
    \ b2);\n    bos[b1] = b2, sz[b2] += sz[b1];\n\n    return true;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/DSU.cpp
  requiredBy: []
  timestamp: '2024-01-20 02:52:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/DSU.cpp
layout: document
redirect_from:
- /library/ds/DSU.cpp
- /library/ds/DSU.cpp.html
title: ds/DSU.cpp
---
