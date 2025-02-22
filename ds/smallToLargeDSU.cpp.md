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
  bundledCode: "#line 1 \"ds/smallToLargeDSU.cpp\"\n//note: op(b1, b2) b1 -> b2\n\
    template<class M, M(*id)(), void(*op)(M&, M&)>\nstruct DSU {\n  int size;\n  vector<int>\
    \ bos, sz;\n  vector<M> data;\n\n  DSU(vector<M> init) : size(init.size()), bos(size),\
    \ sz(size, 1), data(init) {\n    iota(bos.begin(), bos.end(), 0);\n  }\n  DSU(int\
    \ _size) : size(_size), bos(size), sz(size, 1), data(size, id()) {\n    iota(bos.begin(),\
    \ bos.end(), 0);\n  }\n\n  int query(int v) {\n    if (bos[v] == v)\n      return\
    \ v;\n    else\n      return bos[v] = query(bos[v]);\n  }\n\n  bool merge(int\
    \ v1, int v2) {\n    int b1 = query(v1), b2 = query(v2);\n\n    if (b1 == b2)\n\
    \      return false;\n\n    if (sz[b1] > sz[b2])\n      swap(b1, b2);\n    bos[b1]\
    \ = b2, sz[b2] += sz[b1];\n    op(data[b1], data[b2]);\n\n    return true;\n \
    \ }\n\n  M get(int v) { return data[query(v)]; }\n};\n"
  code: "//note: op(b1, b2) b1 -> b2\ntemplate<class M, M(*id)(), void(*op)(M&, M&)>\n\
    struct DSU {\n  int size;\n  vector<int> bos, sz;\n  vector<M> data;\n\n  DSU(vector<M>\
    \ init) : size(init.size()), bos(size), sz(size, 1), data(init) {\n    iota(bos.begin(),\
    \ bos.end(), 0);\n  }\n  DSU(int _size) : size(_size), bos(size), sz(size, 1),\
    \ data(size, id()) {\n    iota(bos.begin(), bos.end(), 0);\n  }\n\n  int query(int\
    \ v) {\n    if (bos[v] == v)\n      return v;\n    else\n      return bos[v] =\
    \ query(bos[v]);\n  }\n\n  bool merge(int v1, int v2) {\n    int b1 = query(v1),\
    \ b2 = query(v2);\n\n    if (b1 == b2)\n      return false;\n\n    if (sz[b1]\
    \ > sz[b2])\n      swap(b1, b2);\n    bos[b1] = b2, sz[b2] += sz[b1];\n    op(data[b1],\
    \ data[b2]);\n\n    return true;\n  }\n\n  M get(int v) { return data[query(v)];\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/smallToLargeDSU.cpp
  requiredBy: []
  timestamp: '2025-02-22 21:24:41+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/smallToLargeDSU.cpp
layout: document
redirect_from:
- /library/ds/smallToLargeDSU.cpp
- /library/ds/smallToLargeDSU.cpp.html
title: ds/smallToLargeDSU.cpp
---
