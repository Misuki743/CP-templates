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
  bundledCode: "#line 1 \"enumerate/enumerate_cartesian_product.cpp\"\n//enumerate\
    \ product of [0, rs_i)\ntemplate<typename F>\nrequires invocable<F, vector<int>>\n\
    void enumerate_cartesian_product(vector<int> rs, F f) {\n  vector<int> a(size(rs));\n\
    \  auto dfs = [&](int i, auto &self) -> void {\n    if (i == ssize(rs)) {\n  \
    \    f(a);\n    } else {\n      for(int j = 0; j < rs[i]; j++) {\n        a[i]\
    \ = j;\n        self(i + 1, self);\n      }\n    }\n  };\n  dfs(0, dfs);\n}\n"
  code: "//enumerate product of [0, rs_i)\ntemplate<typename F>\nrequires invocable<F,\
    \ vector<int>>\nvoid enumerate_cartesian_product(vector<int> rs, F f) {\n  vector<int>\
    \ a(size(rs));\n  auto dfs = [&](int i, auto &self) -> void {\n    if (i == ssize(rs))\
    \ {\n      f(a);\n    } else {\n      for(int j = 0; j < rs[i]; j++) {\n     \
    \   a[i] = j;\n        self(i + 1, self);\n      }\n    }\n  };\n  dfs(0, dfs);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/enumerate_cartesian_product.cpp
  requiredBy: []
  timestamp: '2026-01-29 02:59:39+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: enumerate/enumerate_cartesian_product.cpp
layout: document
redirect_from:
- /library/enumerate/enumerate_cartesian_product.cpp
- /library/enumerate/enumerate_cartesian_product.cpp.html
title: enumerate/enumerate_cartesian_product.cpp
---
