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
  bundledCode: "#line 1 \"ds/bipartiteDSU.cpp\"\nstruct DSU {\n  vector<int> dep;\n\
    \  vector<int> bos;\n  vector<int> d;\n  int size;\n\n  DSU(int _size) : size(_size),\
    \ dep(_size, 0), bos(_size), d(_size) {\n    iota(bos.begin(), bos.end(), 0);\n\
    \  }\n\n  array<int, 2> query(int V) {\n    if (bos[V] == V) {\n      return {d[V],\
    \ V};\n    } else {\n      auto res = query(bos[V]);\n      d[V] ^= res[0];\n\
    \      bos[V] = res[1];\n      return {d[V], bos[V]};\n    }\n  }\n\n  bool merge(int\
    \ V1, int V2, bool eq) {\n    int del = (eq ? 0 : 1);\n    int B1 = query(V1)[1];\n\
    \    int B2 = query(V2)[1];\n\n    if (B1 == B2)\n      return (d[V1] ^ d[V2])\
    \ == del;\n\n    if (dep[B1] < dep[B2]) {\n      bos[B1] = B2, d[B1] = d[V1] ^\
    \ d[V2] ^ del;\n    } else if (dep[B1] > dep[B2]) {\n      bos[B2] = B1, d[B2]\
    \ = d[V1] ^ d[V2] ^ del;\n    } else {\n      bos[B1] = B2, d[B1] = d[V1] ^ d[V2]\
    \ ^ del;\n      dep[B2] += 1;\n    }\n\n    return true;\n  }\n};\n"
  code: "struct DSU {\n  vector<int> dep;\n  vector<int> bos;\n  vector<int> d;\n\
    \  int size;\n\n  DSU(int _size) : size(_size), dep(_size, 0), bos(_size), d(_size)\
    \ {\n    iota(bos.begin(), bos.end(), 0);\n  }\n\n  array<int, 2> query(int V)\
    \ {\n    if (bos[V] == V) {\n      return {d[V], V};\n    } else {\n      auto\
    \ res = query(bos[V]);\n      d[V] ^= res[0];\n      bos[V] = res[1];\n      return\
    \ {d[V], bos[V]};\n    }\n  }\n\n  bool merge(int V1, int V2, bool eq) {\n   \
    \ int del = (eq ? 0 : 1);\n    int B1 = query(V1)[1];\n    int B2 = query(V2)[1];\n\
    \n    if (B1 == B2)\n      return (d[V1] ^ d[V2]) == del;\n\n    if (dep[B1] <\
    \ dep[B2]) {\n      bos[B1] = B2, d[B1] = d[V1] ^ d[V2] ^ del;\n    } else if\
    \ (dep[B1] > dep[B2]) {\n      bos[B2] = B1, d[B2] = d[V1] ^ d[V2] ^ del;\n  \
    \  } else {\n      bos[B1] = B2, d[B1] = d[V1] ^ d[V2] ^ del;\n      dep[B2] +=\
    \ 1;\n    }\n\n    return true;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/bipartiteDSU.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/bipartiteDSU.cpp
layout: document
redirect_from:
- /library/ds/bipartiteDSU.cpp
- /library/ds/bipartiteDSU.cpp.html
title: ds/bipartiteDSU.cpp
---