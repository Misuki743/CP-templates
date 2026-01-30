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
  bundledCode: "#line 1 \"ds/DSU/DSUrollback.cpp\"\nstruct DSU {\n  vector<array<int,\
    \ 4>> his;\n  vector<int> bos, sz;\n  int size;\n\n  DSU(int _size) : bos(_size),\
    \ sz(_size, 1), size(_size) {\n    iota(bos.begin(), bos.end(), 0);\n  }\n\n \
    \ int query(int v) {\n    if (bos[v] == v)\n      return v;\n    else\n      return\
    \ query(bos[v]);\n  }\n\n  bool merge(int v1, int v2) {\n    int b1 = query(v1),\
    \ b2 = query(v2);\n\n    if (b1 == b2)\n      return false;\n\n    if (sz[b1]\
    \ > sz[b2])\n      swap(b1, b2);\n\n    his.push_back({b1, bos[b1], b2, sz[b2]});\n\
    \    bos[b1] = b2, sz[b2] += sz[b1];\n\n    return true;\n  }\n\n  int time()\
    \ { return ssize(his); }\n\n  void rollback(int t) {\n    while(ssize(his) > t)\
    \ {\n      auto arr = his.back(); his.pop_back();\n      bos[arr[0]] = arr[1],\
    \ sz[arr[2]] = arr[3];\n    }\n  }\n\n  int cc() { return size - ssize(his); }\n\
    };\n"
  code: "struct DSU {\n  vector<array<int, 4>> his;\n  vector<int> bos, sz;\n  int\
    \ size;\n\n  DSU(int _size) : bos(_size), sz(_size, 1), size(_size) {\n    iota(bos.begin(),\
    \ bos.end(), 0);\n  }\n\n  int query(int v) {\n    if (bos[v] == v)\n      return\
    \ v;\n    else\n      return query(bos[v]);\n  }\n\n  bool merge(int v1, int v2)\
    \ {\n    int b1 = query(v1), b2 = query(v2);\n\n    if (b1 == b2)\n      return\
    \ false;\n\n    if (sz[b1] > sz[b2])\n      swap(b1, b2);\n\n    his.push_back({b1,\
    \ bos[b1], b2, sz[b2]});\n    bos[b1] = b2, sz[b2] += sz[b1];\n\n    return true;\n\
    \  }\n\n  int time() { return ssize(his); }\n\n  void rollback(int t) {\n    while(ssize(his)\
    \ > t) {\n      auto arr = his.back(); his.pop_back();\n      bos[arr[0]] = arr[1],\
    \ sz[arr[2]] = arr[3];\n    }\n  }\n\n  int cc() { return size - ssize(his); }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/DSU/DSUrollback.cpp
  requiredBy: []
  timestamp: '2026-01-30 20:10:19+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/DSU/DSUrollback.cpp
layout: document
redirect_from:
- /library/ds/DSU/DSUrollback.cpp
- /library/ds/DSU/DSUrollback.cpp.html
title: ds/DSU/DSUrollback.cpp
---
