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
  bundledCode: "#line 1 \"ds/doubling.cpp\"\ntemplate<class M, M(*id)(), M(*op)(const\
    \ M&, const M&)>\nstruct doubling {\n  int n, k;\n  vector<vector<int>> jp;\n\
    \  vector<vector<M>> data;\n\n  doubling(vector<int> to, vector<M> init, int _k)\
    \ :\n  n(size(to)), k(_k), jp(k, vector<int>(n, -1)), data(k, vector<M>(n, id()))\
    \ {\n    jp[0] = to, data[0] = init;\n    for(int i = 1; i < k; i++) {\n     \
    \ for(int j = 0; j < n; j++) {\n        if (jp[i - 1][j] != -1 and jp[i - 1][jp[i\
    \ - 1][j]] != -1) {\n          jp[i][j] = jp[i - 1][jp[i - 1][j]];\n         \
    \ data[i][j] = op(data[i - 1][j], data[i - 1][jp[i - 1][j]]);\n        }\n   \
    \   }\n    }\n  }\n\n  pair<int, M> query(int v, ll len) {\n    M res = id();\n\
    \    for(int i = 0; i < k; i++)\n      if ((len >> i & 1) and jp[i][v] != -1)\n\
    \        res = op(res, data[i][v]), v = jp[i][v];\n    return make_pair(v, res);\n\
    \  }\n\n  int lastTrue(int v, function<bool(const M&)> f) {\n    M res = id();\n\
    \    for(int i = k - 1; i >= 0; i--)\n      if (jp[i][v] != -1 and f(op(res, data[i][v])))\n\
    \        res = op(res, data[i][v]), v = jp[i][v];\n    return v;\n  }\n};\n"
  code: "template<class M, M(*id)(), M(*op)(const M&, const M&)>\nstruct doubling\
    \ {\n  int n, k;\n  vector<vector<int>> jp;\n  vector<vector<M>> data;\n\n  doubling(vector<int>\
    \ to, vector<M> init, int _k) :\n  n(size(to)), k(_k), jp(k, vector<int>(n, -1)),\
    \ data(k, vector<M>(n, id())) {\n    jp[0] = to, data[0] = init;\n    for(int\
    \ i = 1; i < k; i++) {\n      for(int j = 0; j < n; j++) {\n        if (jp[i -\
    \ 1][j] != -1 and jp[i - 1][jp[i - 1][j]] != -1) {\n          jp[i][j] = jp[i\
    \ - 1][jp[i - 1][j]];\n          data[i][j] = op(data[i - 1][j], data[i - 1][jp[i\
    \ - 1][j]]);\n        }\n      }\n    }\n  }\n\n  pair<int, M> query(int v, ll\
    \ len) {\n    M res = id();\n    for(int i = 0; i < k; i++)\n      if ((len >>\
    \ i & 1) and jp[i][v] != -1)\n        res = op(res, data[i][v]), v = jp[i][v];\n\
    \    return make_pair(v, res);\n  }\n\n  int lastTrue(int v, function<bool(const\
    \ M&)> f) {\n    M res = id();\n    for(int i = k - 1; i >= 0; i--)\n      if\
    \ (jp[i][v] != -1 and f(op(res, data[i][v])))\n        res = op(res, data[i][v]),\
    \ v = jp[i][v];\n    return v;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/doubling.cpp
  requiredBy: []
  timestamp: '2024-08-30 17:59:56+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/doubling.cpp
layout: document
redirect_from:
- /library/ds/doubling.cpp
- /library/ds/doubling.cpp.html
title: ds/doubling.cpp
---
