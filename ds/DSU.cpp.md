---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/minimum_spanning_tree.test.cpp
    title: test/minimum_spanning_tree.test.cpp
  - icon: ':x:'
    path: test/unionfind.test.cpp
    title: test/unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/DSU.cpp\"\nstruct DSU {\n  vector<int> bos, sz;\n  int\
    \ size;\n\n  DSU(int _size) : bos(_size), sz(_size, 1), size(_size) {\n    iota(bos.begin(),\
    \ bos.end(), 0);\n  }\n\n  int query(int v) {\n    if (bos[v] == v)\n      return\
    \ v;\n    else\n      return bos[v] = query(bos[v]);\n  }\n\n  bool merge(int\
    \ v1, int v2) {\n    int b1 = query(v1), b2 = query(v2);\n\n    if (b1 == b2)\n\
    \      return false;\n\n    if (sz[b1] > sz[b2])\n      swap(b1, b2);\n    bos[b1]\
    \ = b2, sz[b2] += sz[b1];\n\n    return true;\n  }\n};\n"
  code: "struct DSU {\n  vector<int> bos, sz;\n  int size;\n\n  DSU(int _size) : bos(_size),\
    \ sz(_size, 1), size(_size) {\n    iota(bos.begin(), bos.end(), 0);\n  }\n\n \
    \ int query(int v) {\n    if (bos[v] == v)\n      return v;\n    else\n      return\
    \ bos[v] = query(bos[v]);\n  }\n\n  bool merge(int v1, int v2) {\n    int b1 =\
    \ query(v1), b2 = query(v2);\n\n    if (b1 == b2)\n      return false;\n\n   \
    \ if (sz[b1] > sz[b2])\n      swap(b1, b2);\n    bos[b1] = b2, sz[b2] += sz[b1];\n\
    \n    return true;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/DSU.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/unionfind.test.cpp
  - test/minimum_spanning_tree.test.cpp
documentation_of: ds/DSU.cpp
layout: document
redirect_from:
- /library/ds/DSU.cpp
- /library/ds/DSU.cpp.html
title: ds/DSU.cpp
---
