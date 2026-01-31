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
  bundledCode: "#line 1 \"ds/DSU/rollback_DSU.cpp\"\nstruct rollback_DSU {\n  vi sz_par;\n\
    \  vc<pii> his;\n  int nxt;\n\n  rollback_DSU(int n) : sz_par(n, -1), his(2 *\
    \ (n - 1)), nxt(0) {}\n\n  int query(int v) {\n    int r = v;\n    while(sz_par[r]\
    \ >= 0) r = sz_par[r];\n    return r;\n  }\n\n  bool merge(int v1, int v2) {\n\
    \    int b1 = query(v1), b2 = query(v2);\n\n    if (b1 == b2)\n      return false;\n\
    \n    if (-sz_par[b1] > -sz_par[b2])\n      swap(b1, b2);\n\n    his[nxt++] =\
    \ pair(b2, sz_par[b2]);\n    his[nxt++] = pair(b1, sz_par[b1]);\n    sz_par[b2]\
    \ += sz_par[b1];\n    sz_par[b1] = b2;\n\n    return true;\n  }\n\n  int time()\
    \ { return nxt; }\n  int size(int v) { return -sz_par[query(v)]; }\n\n  void rollback(int\
    \ t) {\n    chmin(t, nxt);\n    for(auto [i, x] : views::counted(his.begin() +\
    \ t, nxt - t)\n                    | views::reverse)\n      sz_par[i] = x;\n \
    \   nxt = t;\n  }\n};\n"
  code: "struct rollback_DSU {\n  vi sz_par;\n  vc<pii> his;\n  int nxt;\n\n  rollback_DSU(int\
    \ n) : sz_par(n, -1), his(2 * (n - 1)), nxt(0) {}\n\n  int query(int v) {\n  \
    \  int r = v;\n    while(sz_par[r] >= 0) r = sz_par[r];\n    return r;\n  }\n\n\
    \  bool merge(int v1, int v2) {\n    int b1 = query(v1), b2 = query(v2);\n\n \
    \   if (b1 == b2)\n      return false;\n\n    if (-sz_par[b1] > -sz_par[b2])\n\
    \      swap(b1, b2);\n\n    his[nxt++] = pair(b2, sz_par[b2]);\n    his[nxt++]\
    \ = pair(b1, sz_par[b1]);\n    sz_par[b2] += sz_par[b1];\n    sz_par[b1] = b2;\n\
    \n    return true;\n  }\n\n  int time() { return nxt; }\n  int size(int v) { return\
    \ -sz_par[query(v)]; }\n\n  void rollback(int t) {\n    chmin(t, nxt);\n    for(auto\
    \ [i, x] : views::counted(his.begin() + t, nxt - t)\n                    | views::reverse)\n\
    \      sz_par[i] = x;\n    nxt = t;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/DSU/rollback_DSU.cpp
  requiredBy: []
  timestamp: '2026-01-31 18:57:43+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/persistent_unionfind.test.cpp
documentation_of: ds/DSU/rollback_DSU.cpp
layout: document
redirect_from:
- /library/ds/DSU/rollback_DSU.cpp
- /library/ds/DSU/rollback_DSU.cpp.html
title: ds/DSU/rollback_DSU.cpp
---
