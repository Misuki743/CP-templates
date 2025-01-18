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
  bundledCode: "#line 1 \"ds/pSum2D.cpp\"\ntemplate<class M, M(*id)() = nullptr, M(*op)(const\
    \ M&, const M&) = nullptr, M(*inv)(const M&) = nullptr>\nstruct pSum2D {\n  int\
    \ n, m;\n  vector<M> data;\n  pSum2D(vector<vector<M>> &init) : n(size(init) +\
    \ 1), m(size(init[0]) + 1), data(n * m) {\n    if constexpr (id != nullptr) {\n\
    \      for(int i = 0; i < n; i++)\n        data[i * m] = id();\n      for(int\
    \ j = 0; j < m; j++)\n        data[j] = id();\n    }\n    for(int i = 1; i < n;\
    \ i++)\n      for(int j = 1; j < m; j++)\n        data[i * m + j] = init[i - 1][j\
    \ - 1];\n    for(int i = 0; i < n; i++) {\n      for(int j = 1; j < m; j++) {\n\
    \        if constexpr (op != nullptr)\n          data[i * m + j] = op(data[i *\
    \ m + j - 1], data[i * m + j]);\n        else\n          data[i * m + j] += data[i\
    \ * m + j - 1];\n      }\n    }\n    for(int i = 1; i < n; i++) {\n      for(int\
    \ j = 0; j < m; j++) {\n        if constexpr (op != nullptr)\n          data[i\
    \ * m + j] = op(data[(i - 1) * m + j], data[i * m + j]);\n        else\n     \
    \     data[i * m + j] += data[(i - 1) * m + j];\n      }\n    }\n  }\n  //[x1,\
    \ x2) x [y1, y2)\n  M query(int x1, int x2, int y1, int y2) {\n    if constexpr\
    \ (inv != nullptr)\n      return op(op(data[x2 * m + y2], data[x1 * m + y1]),\n\
    \            inv(op(data[x1 * m + y2], data[x2 * m + y1])));\n    else\n     \
    \ return data[x2 * m + y2] + data[x1 * m + y1] -\n             data[x1 * m + y2]\
    \ - data[x2 * m + y1];\n  }\n};\n"
  code: "template<class M, M(*id)() = nullptr, M(*op)(const M&, const M&) = nullptr,\
    \ M(*inv)(const M&) = nullptr>\nstruct pSum2D {\n  int n, m;\n  vector<M> data;\n\
    \  pSum2D(vector<vector<M>> &init) : n(size(init) + 1), m(size(init[0]) + 1),\
    \ data(n * m) {\n    if constexpr (id != nullptr) {\n      for(int i = 0; i <\
    \ n; i++)\n        data[i * m] = id();\n      for(int j = 0; j < m; j++)\n   \
    \     data[j] = id();\n    }\n    for(int i = 1; i < n; i++)\n      for(int j\
    \ = 1; j < m; j++)\n        data[i * m + j] = init[i - 1][j - 1];\n    for(int\
    \ i = 0; i < n; i++) {\n      for(int j = 1; j < m; j++) {\n        if constexpr\
    \ (op != nullptr)\n          data[i * m + j] = op(data[i * m + j - 1], data[i\
    \ * m + j]);\n        else\n          data[i * m + j] += data[i * m + j - 1];\n\
    \      }\n    }\n    for(int i = 1; i < n; i++) {\n      for(int j = 0; j < m;\
    \ j++) {\n        if constexpr (op != nullptr)\n          data[i * m + j] = op(data[(i\
    \ - 1) * m + j], data[i * m + j]);\n        else\n          data[i * m + j] +=\
    \ data[(i - 1) * m + j];\n      }\n    }\n  }\n  //[x1, x2) x [y1, y2)\n  M query(int\
    \ x1, int x2, int y1, int y2) {\n    if constexpr (inv != nullptr)\n      return\
    \ op(op(data[x2 * m + y2], data[x1 * m + y1]),\n            inv(op(data[x1 * m\
    \ + y2], data[x2 * m + y1])));\n    else\n      return data[x2 * m + y2] + data[x1\
    \ * m + y1] -\n             data[x1 * m + y2] - data[x2 * m + y1];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/pSum2D.cpp
  requiredBy: []
  timestamp: '2024-12-16 01:53:50+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/pSum2D.cpp
layout: document
redirect_from:
- /library/ds/pSum2D.cpp
- /library/ds/pSum2D.cpp.html
title: ds/pSum2D.cpp
---
