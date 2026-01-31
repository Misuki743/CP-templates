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
  bundledCode: "#line 1 \"ds/DSU/bipartite_DSU.cpp\"\nstruct bipartite_DSU {\n  vi\
    \ sz_par;\n  vc<bool> d;\n\n  bipartite_DSU(int n) : sz_par(n, -1), d(n, false)\
    \ {}\n\n  int query(int v) {\n    int r = v, sum = 0;\n    while(sz_par[r] >=\
    \ 0)\n      sum ^= d[r], r = sz_par[r];\n    while(v != r) {\n      int nxt =\
    \ sz_par[v], tmp = d[v];\n      d[v] = sum, sum ^= tmp;\n      sz_par[v] = r,\
    \ v = nxt;\n    }\n    return r;\n  }\n\n  bool merge(int v1, int v2, bool diff)\
    \ {\n    int b1 = query(v1), b2 = query(v2);\n\n    if (b1 == b2)\n      return\
    \ (d[v1] ^ d[v2]) == diff;\n\n    if (-sz_par[b1] > -sz_par[b2])\n      swap(b1,\
    \ b2);\n\n    d[b1] = d[v1] ^ d[v2] ^ diff;\n    sz_par[b2] += sz_par[b1];\n \
    \   sz_par[b1] = b2;\n\n    return true;\n  }\n\n  int size(int v) { return v\
    \ = query(v), -sz_par[v]; }\n  bool color(int v) { return query(v), d[v]; }\n\
    };\n"
  code: "struct bipartite_DSU {\n  vi sz_par;\n  vc<bool> d;\n\n  bipartite_DSU(int\
    \ n) : sz_par(n, -1), d(n, false) {}\n\n  int query(int v) {\n    int r = v, sum\
    \ = 0;\n    while(sz_par[r] >= 0)\n      sum ^= d[r], r = sz_par[r];\n    while(v\
    \ != r) {\n      int nxt = sz_par[v], tmp = d[v];\n      d[v] = sum, sum ^= tmp;\n\
    \      sz_par[v] = r, v = nxt;\n    }\n    return r;\n  }\n\n  bool merge(int\
    \ v1, int v2, bool diff) {\n    int b1 = query(v1), b2 = query(v2);\n\n    if\
    \ (b1 == b2)\n      return (d[v1] ^ d[v2]) == diff;\n\n    if (-sz_par[b1] > -sz_par[b2])\n\
    \      swap(b1, b2);\n\n    d[b1] = d[v1] ^ d[v2] ^ diff;\n    sz_par[b2] += sz_par[b1];\n\
    \    sz_par[b1] = b2;\n\n    return true;\n  }\n\n  int size(int v) { return v\
    \ = query(v), -sz_par[v]; }\n  bool color(int v) { return query(v), d[v]; }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/DSU/bipartite_DSU.cpp
  requiredBy: []
  timestamp: '2026-01-31 18:57:43+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/DSU/bipartite_DSU.cpp
layout: document
redirect_from:
- /library/ds/DSU/bipartite_DSU.cpp
- /library/ds/DSU/bipartite_DSU.cpp.html
title: ds/DSU/bipartite_DSU.cpp
---
