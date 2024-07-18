---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unionfind_with_potential_non_commutative_group.test.cpp
    title: test/unionfind_with_potential_non_commutative_group.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/potentialDSU.cpp\"\ntemplate<class G, G(*id)(), G(*op)(const\
    \ G&, const G&), G(*inv)(const G&)>\nstruct DSU {\n  vector<int> bos, sz;\n  vector<G>\
    \ _pot;\n  int size;\n\n  DSU(int _size) : bos(_size), sz(_size, 1), _pot(_size,\
    \ id()), size(_size) {\n    iota(bos.begin(), bos.end(), 0);\n  }\n\n  int query(int\
    \ v) {\n    if (bos[v] == v) {\n      return v;\n    } else {\n      int tmp =\
    \ query(bos[v]);\n      _pot[v] = op(_pot[bos[v]], _pot[v]);\n      return bos[v]\
    \ = tmp;\n    }\n  }\n\n  //op(v1, d) = v2\n  bool merge(int v1, int v2, G d)\
    \ {\n    int b1 = query(v1), b2 = query(v2);\n\n    if (b1 == b2)\n      return\
    \ op(inv(_pot[v1]), _pot[v2]) == d;\n\n    if (sz[b1] > sz[b2]) {\n      swap(b1,\
    \ b2), swap(v1, v2);\n      d = inv(d);\n    }\n    bos[b1] = b2, sz[b2] += sz[b1],\
    \ _pot[b1] = op(op(_pot[v2], inv(d)), inv(_pot[v1]));\n\n    return true;\n  }\n\
    \n  //op(inv(v1), v2)\n  G query(int v1, int v2) {\n    query(v1), query(v2);\n\
    \    return op(inv(_pot[v1]), _pot[v2]);\n  }\n};\n"
  code: "template<class G, G(*id)(), G(*op)(const G&, const G&), G(*inv)(const G&)>\n\
    struct DSU {\n  vector<int> bos, sz;\n  vector<G> _pot;\n  int size;\n\n  DSU(int\
    \ _size) : bos(_size), sz(_size, 1), _pot(_size, id()), size(_size) {\n    iota(bos.begin(),\
    \ bos.end(), 0);\n  }\n\n  int query(int v) {\n    if (bos[v] == v) {\n      return\
    \ v;\n    } else {\n      int tmp = query(bos[v]);\n      _pot[v] = op(_pot[bos[v]],\
    \ _pot[v]);\n      return bos[v] = tmp;\n    }\n  }\n\n  //op(v1, d) = v2\n  bool\
    \ merge(int v1, int v2, G d) {\n    int b1 = query(v1), b2 = query(v2);\n\n  \
    \  if (b1 == b2)\n      return op(inv(_pot[v1]), _pot[v2]) == d;\n\n    if (sz[b1]\
    \ > sz[b2]) {\n      swap(b1, b2), swap(v1, v2);\n      d = inv(d);\n    }\n \
    \   bos[b1] = b2, sz[b2] += sz[b1], _pot[b1] = op(op(_pot[v2], inv(d)), inv(_pot[v1]));\n\
    \n    return true;\n  }\n\n  //op(inv(v1), v2)\n  G query(int v1, int v2) {\n\
    \    query(v1), query(v2);\n    return op(inv(_pot[v1]), _pot[v2]);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/potentialDSU.cpp
  requiredBy: []
  timestamp: '2024-07-18 22:15:57+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unionfind_with_potential_non_commutative_group.test.cpp
documentation_of: ds/potentialDSU.cpp
layout: document
redirect_from:
- /library/ds/potentialDSU.cpp
- /library/ds/potentialDSU.cpp.html
title: ds/potentialDSU.cpp
---
