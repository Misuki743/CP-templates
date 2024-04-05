---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/persistent_unionfind.test.cpp
    title: test/persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/DSUrollback.cpp\"\nstruct DSU {\n  vector<array<int,\
    \ 4>> his;\n  vector<int> bos, sz;\n  int size;\n\n  DSU(int _size) : bos(_size),\
    \ sz(_size, 1), size(_size) {\n    iota(bos.begin(), bos.end(), 0);\n  }\n\n \
    \ int query(int v) {\n    if (bos[v] == v)\n      return v;\n    else\n      return\
    \ query(bos[v]);\n  }\n\n  bool merge(int v1, int v2) {\n    int b1 = query(v1),\
    \ b2 = query(v2);\n\n    if (b1 == b2)\n      return false;\n\n    if (sz[b1]\
    \ > sz[b2])\n      swap(b1, b2);\n\n    his.push_back({b1, bos[b1], b2, sz[b2]});\n\
    \    bos[b1] = b2, sz[b2] += sz[b1];\n\n    return true;\n  }\n\n  int time()\
    \ { return ssize(his); }\n\n  void rollback(int t) {\n    while(ssize(his) > t)\
    \ {\n      auto arr = his.back(); his.pop_back();\n      bos[arr[0]] = arr[1],\
    \ sz[arr[2]] = arr[3];\n    }\n  }\n};\n"
  code: "struct DSU {\n  vector<array<int, 4>> his;\n  vector<int> bos, sz;\n  int\
    \ size;\n\n  DSU(int _size) : bos(_size), sz(_size, 1), size(_size) {\n    iota(bos.begin(),\
    \ bos.end(), 0);\n  }\n\n  int query(int v) {\n    if (bos[v] == v)\n      return\
    \ v;\n    else\n      return query(bos[v]);\n  }\n\n  bool merge(int v1, int v2)\
    \ {\n    int b1 = query(v1), b2 = query(v2);\n\n    if (b1 == b2)\n      return\
    \ false;\n\n    if (sz[b1] > sz[b2])\n      swap(b1, b2);\n\n    his.push_back({b1,\
    \ bos[b1], b2, sz[b2]});\n    bos[b1] = b2, sz[b2] += sz[b1];\n\n    return true;\n\
    \  }\n\n  int time() { return ssize(his); }\n\n  void rollback(int t) {\n    while(ssize(his)\
    \ > t) {\n      auto arr = his.back(); his.pop_back();\n      bos[arr[0]] = arr[1],\
    \ sz[arr[2]] = arr[3];\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/DSUrollback.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/persistent_unionfind.test.cpp
documentation_of: ds/DSUrollback.cpp
layout: document
redirect_from:
- /library/ds/DSUrollback.cpp
- /library/ds/DSUrollback.cpp.html
title: ds/DSUrollback.cpp
---
