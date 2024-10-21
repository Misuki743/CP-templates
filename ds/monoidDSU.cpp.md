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
  bundledCode: "#line 1 \"ds/monoidDSU.cpp\"\ntemplate<class M, M(*id)(), M(*op)(const\
    \ M&, const M&)>\nstruct DSU {\n  int size;\n  vector<int> bos, sz;\n  vector<M>\
    \ data;\n\n  DSU(vector<M> init) : size(init.size()), bos(size), sz(size, 1),\
    \ data(init) {\n    iota(bos.begin(), bos.end(), 0);\n  }\n  DSU(int _size) :\
    \ size(_size), bos(size), sz(size, 1), data(size, id()) {\n    iota(bos.begin(),\
    \ bos.end(), 0);\n  }\n\n  int query(int v) {\n    if (bos[v] == v)\n      return\
    \ v;\n    else\n      return bos[v] = query(bos[v]);\n  }\n\n  bool merge(int\
    \ v1, int v2) {\n    int b1 = query(v1), b2 = query(v2);\n\n    if (b1 == b2)\n\
    \      return false;\n\n    if (sz[b1] > sz[b2])\n      swap(b1, b2);\n    bos[b1]\
    \ = b2, sz[b2] += sz[b1];\n    data[b2] = op(data[b1], data[b2]);\n\n    return\
    \ true;\n  }\n\n  M get(int v) { return data[query(v)]; }\n};\n"
  code: "template<class M, M(*id)(), M(*op)(const M&, const M&)>\nstruct DSU {\n \
    \ int size;\n  vector<int> bos, sz;\n  vector<M> data;\n\n  DSU(vector<M> init)\
    \ : size(init.size()), bos(size), sz(size, 1), data(init) {\n    iota(bos.begin(),\
    \ bos.end(), 0);\n  }\n  DSU(int _size) : size(_size), bos(size), sz(size, 1),\
    \ data(size, id()) {\n    iota(bos.begin(), bos.end(), 0);\n  }\n\n  int query(int\
    \ v) {\n    if (bos[v] == v)\n      return v;\n    else\n      return bos[v] =\
    \ query(bos[v]);\n  }\n\n  bool merge(int v1, int v2) {\n    int b1 = query(v1),\
    \ b2 = query(v2);\n\n    if (b1 == b2)\n      return false;\n\n    if (sz[b1]\
    \ > sz[b2])\n      swap(b1, b2);\n    bos[b1] = b2, sz[b2] += sz[b1];\n    data[b2]\
    \ = op(data[b1], data[b2]);\n\n    return true;\n  }\n\n  M get(int v) { return\
    \ data[query(v)]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/monoidDSU.cpp
  requiredBy: []
  timestamp: '2024-10-21 21:31:03+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/monoidDSU.cpp
layout: document
redirect_from:
- /library/ds/monoidDSU.cpp
- /library/ds/monoidDSU.cpp.html
title: ds/monoidDSU.cpp
---
