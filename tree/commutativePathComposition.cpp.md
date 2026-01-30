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
  bundledCode: "#line 1 \"tree/commutativePathComposition.cpp\"\ntemplate<class M,\
    \ M(*id)(), M(*op)(const M&, const M&), bool edge = true>\nstruct commutative_path_composition\
    \ {\n  const int n, m;\n  vector<vector<int>> jp, dat;\n  vector<int> dep;\n\n\
    \  commutative_path_composition(vector<vector<int>> &g, vector<int> init)\n  :\
    \ n(bit_width(size(g))), m(size(g)), jp(n, vector<int>(m, -1)), dat(n, vector(m,\
    \ id())), dep(m) {\n    auto dfs = [&](int v, auto &self) -> void {\n      for(int\
    \ x : g[v]) {\n        if (x == jp[0][v]) continue;\n        jp[0][x] = v, dep[x]\
    \ = dep[v] + 1;\n        self(x, self);\n      }\n    };\n    dfs(0, dfs);\n\n\
    \    dat[0] = init;\n    for(int i = 1; i < n; i++)\n      for(int j = 0; j <\
    \ m; j++)\n        if (jp[i - 1][j] != -1 and jp[i - 1][jp[i - 1][j]] != -1)\n\
    \          jp[i][j] = jp[i - 1][jp[i - 1][j]], dat[i][j] = op(dat[i - 1][j], dat[i\
    \ - 1][jp[i - 1][j]]);\n  }\n\n  M query(int u, int v) {\n    if (dep[u] < dep[v])\
    \ swap(u, v);\n    M res = id();\n    for(int i = 0, dif = dep[u] - dep[v]; i\
    \ < n; i++)\n      if (dif >> i & 1)\n        res = op(res, dat[i][u]), u = jp[i][u];\n\
    \    if (u == v) return edge ? res : op(res, dat[0][u]);\n    for(int i = n -\
    \ 1; i >= 0; i--)\n      if (jp[i][u] != jp[i][v])\n        res = op(res, op(dat[i][u],\
    \ dat[i][v])), u = jp[i][u], v = jp[i][v];\n    return op(res, op(dat[0][u], dat[!edge][v]));\n\
    \  }\n};\n"
  code: "template<class M, M(*id)(), M(*op)(const M&, const M&), bool edge = true>\n\
    struct commutative_path_composition {\n  const int n, m;\n  vector<vector<int>>\
    \ jp, dat;\n  vector<int> dep;\n\n  commutative_path_composition(vector<vector<int>>\
    \ &g, vector<int> init)\n  : n(bit_width(size(g))), m(size(g)), jp(n, vector<int>(m,\
    \ -1)), dat(n, vector(m, id())), dep(m) {\n    auto dfs = [&](int v, auto &self)\
    \ -> void {\n      for(int x : g[v]) {\n        if (x == jp[0][v]) continue;\n\
    \        jp[0][x] = v, dep[x] = dep[v] + 1;\n        self(x, self);\n      }\n\
    \    };\n    dfs(0, dfs);\n\n    dat[0] = init;\n    for(int i = 1; i < n; i++)\n\
    \      for(int j = 0; j < m; j++)\n        if (jp[i - 1][j] != -1 and jp[i - 1][jp[i\
    \ - 1][j]] != -1)\n          jp[i][j] = jp[i - 1][jp[i - 1][j]], dat[i][j] = op(dat[i\
    \ - 1][j], dat[i - 1][jp[i - 1][j]]);\n  }\n\n  M query(int u, int v) {\n    if\
    \ (dep[u] < dep[v]) swap(u, v);\n    M res = id();\n    for(int i = 0, dif = dep[u]\
    \ - dep[v]; i < n; i++)\n      if (dif >> i & 1)\n        res = op(res, dat[i][u]),\
    \ u = jp[i][u];\n    if (u == v) return edge ? res : op(res, dat[0][u]);\n   \
    \ for(int i = n - 1; i >= 0; i--)\n      if (jp[i][u] != jp[i][v])\n        res\
    \ = op(res, op(dat[i][u], dat[i][v])), u = jp[i][u], v = jp[i][v];\n    return\
    \ op(res, op(dat[0][u], dat[!edge][v]));\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/commutativePathComposition.cpp
  requiredBy: []
  timestamp: '2026-01-30 20:10:19+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/commutativePathComposition.cpp
layout: document
redirect_from:
- /library/tree/commutativePathComposition.cpp
- /library/tree/commutativePathComposition.cpp.html
title: tree/commutativePathComposition.cpp
---
