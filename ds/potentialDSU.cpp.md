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
  bundledCode: "#line 1 \"ds/potentialDSU.cpp\"\ntemplate<class T>\nstruct DSU {\n\
    \  vector<int> bos, sz;\n  vector<T> _pot;\n  int size;\n\n  DSU(int _size) :\
    \ bos(_size), sz(_size, 1), _pot(_size), size(_size) {\n    iota(bos.begin(),\
    \ bos.end(), 0);\n  }\n\n  int query(int v) {\n    if (bos[v] == v) {\n      return\
    \ v;\n    } else {\n      int tmp = query(bos[v]);\n      _pot[v] += _pot[bos[v]];\
    \ \n      return bos[v] = tmp;\n    }\n  }\n\n  //v1 + d = v2\n  bool merge(int\
    \ v1, int v2, T d) {\n    int b1 = query(v1), b2 = query(v2);\n\n    if (b1 ==\
    \ b2)\n      return false;\n\n    if (sz[b1] > sz[b2]) {\n      swap(b1, b2),\
    \ swap(v1, v2);\n      d *= -1;\n    }\n    bos[b1] = b2, sz[b2] += sz[b1], _pot[b1]\
    \ = _pot[v2] - _pot[v1] - d;\n\n    return true;\n  }\n\n  int pot(int v) {\n\
    \    query(v);\n    return _pot[v];\n  }\n};\n"
  code: "template<class T>\nstruct DSU {\n  vector<int> bos, sz;\n  vector<T> _pot;\n\
    \  int size;\n\n  DSU(int _size) : bos(_size), sz(_size, 1), _pot(_size), size(_size)\
    \ {\n    iota(bos.begin(), bos.end(), 0);\n  }\n\n  int query(int v) {\n    if\
    \ (bos[v] == v) {\n      return v;\n    } else {\n      int tmp = query(bos[v]);\n\
    \      _pot[v] += _pot[bos[v]]; \n      return bos[v] = tmp;\n    }\n  }\n\n \
    \ //v1 + d = v2\n  bool merge(int v1, int v2, T d) {\n    int b1 = query(v1),\
    \ b2 = query(v2);\n\n    if (b1 == b2)\n      return false;\n\n    if (sz[b1]\
    \ > sz[b2]) {\n      swap(b1, b2), swap(v1, v2);\n      d *= -1;\n    }\n    bos[b1]\
    \ = b2, sz[b2] += sz[b1], _pot[b1] = _pot[v2] - _pot[v1] - d;\n\n    return true;\n\
    \  }\n\n  int pot(int v) {\n    query(v);\n    return _pot[v];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/potentialDSU.cpp
  requiredBy: []
  timestamp: '2024-06-25 20:53:53+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/potentialDSU.cpp
layout: document
redirect_from:
- /library/ds/potentialDSU.cpp
- /library/ds/potentialDSU.cpp.html
title: ds/potentialDSU.cpp
---
