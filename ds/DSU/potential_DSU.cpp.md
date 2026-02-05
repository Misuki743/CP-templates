---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/unionfind_with_potential.test.cpp
    title: test/unionfind_with_potential.test.cpp
  - icon: ':x:'
    path: test/unionfind_with_potential_non_commutative_group.test.cpp
    title: test/unionfind_with_potential_non_commutative_group.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/DSU/potential_DSU.cpp\"\ntemplate<class T, typename OP,\
    \ typename INV>\nrequires R_invocable<T, OP, T, T> && R_invocable<T, INV, T>\n\
    struct potential_DSU {\n  vi sz_par;\n  vc<T> pot;\n  OP op;\n  INV inv;\n\n \
    \ potential_DSU(int n, T id, OP _op, INV _inv) : sz_par(n, -1),\n    pot(n, id),\
    \ op(_op), inv(_inv) {}\n\n  int query(int v) {\n    if (sz_par[v] < 0) {\n  \
    \    return v;\n    } else {\n      int r = query(sz_par[v]);\n      pot[v] =\
    \ op(pot[v], pot[sz_par[v]]);\n      return sz_par[v] = r;\n    }\n  }\n\n  bool\
    \ merge(int v1, int v2, T prod) {\n    int b1 = query(v1), b2 = query(v2);\n\n\
    \    if (b1 == b2)\n      return op(pot[v1], inv(pot[v2])) == prod;\n\n    if\
    \ (-sz_par[b1] > -sz_par[b2])\n      swap(b1, b2), swap(v1, v2), prod = inv(prod);\n\
    \n    sz_par[b2] += sz_par[b1];\n    sz_par[b1] = b2;\n    pot[b1] = op(op(inv(pot[v1]),\
    \ prod), pot[v2]);\n\n    return true;\n  }\n\n  int size(int v) { return v =\
    \ query(v), -sz_par[v]; }\n  T query(int v1, int v2) {\n    assert(query(v1) ==\
    \ query(v2));\n    return op(pot[v1], inv(pot[v2]));\n  }\n};\n"
  code: "template<class T, typename OP, typename INV>\nrequires R_invocable<T, OP,\
    \ T, T> && R_invocable<T, INV, T>\nstruct potential_DSU {\n  vi sz_par;\n  vc<T>\
    \ pot;\n  OP op;\n  INV inv;\n\n  potential_DSU(int n, T id, OP _op, INV _inv)\
    \ : sz_par(n, -1),\n    pot(n, id), op(_op), inv(_inv) {}\n\n  int query(int v)\
    \ {\n    if (sz_par[v] < 0) {\n      return v;\n    } else {\n      int r = query(sz_par[v]);\n\
    \      pot[v] = op(pot[v], pot[sz_par[v]]);\n      return sz_par[v] = r;\n   \
    \ }\n  }\n\n  bool merge(int v1, int v2, T prod) {\n    int b1 = query(v1), b2\
    \ = query(v2);\n\n    if (b1 == b2)\n      return op(pot[v1], inv(pot[v2])) ==\
    \ prod;\n\n    if (-sz_par[b1] > -sz_par[b2])\n      swap(b1, b2), swap(v1, v2),\
    \ prod = inv(prod);\n\n    sz_par[b2] += sz_par[b1];\n    sz_par[b1] = b2;\n \
    \   pot[b1] = op(op(inv(pot[v1]), prod), pot[v2]);\n\n    return true;\n  }\n\n\
    \  int size(int v) { return v = query(v), -sz_par[v]; }\n  T query(int v1, int\
    \ v2) {\n    assert(query(v1) == query(v2));\n    return op(pot[v1], inv(pot[v2]));\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/DSU/potential_DSU.cpp
  requiredBy: []
  timestamp: '2026-02-05 13:11:35+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/unionfind_with_potential.test.cpp
  - test/unionfind_with_potential_non_commutative_group.test.cpp
documentation_of: ds/DSU/potential_DSU.cpp
layout: document
redirect_from:
- /library/ds/DSU/potential_DSU.cpp
- /library/ds/DSU/potential_DSU.cpp.html
title: ds/DSU/potential_DSU.cpp
---
