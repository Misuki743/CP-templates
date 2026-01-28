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
  bundledCode: "#line 1 \"enumerate/enumerate_integer_partition.cpp\"\ntemplate<typename\
    \ F>\nrequires invocable<F, vector<int>>\nvoid enumerate_integer_partition(int\
    \ n, F f) {\n  assert(n >= 0);\n  vector<int> p;\n  auto dfs = [&](int s, auto\
    \ &self) -> void {\n    if (s == 0) {\n      f(p);\n    } else {\n      for(int\
    \ x = (p.empty() ? s : min(p.back(), s)); x > 0; x--) {\n        p.emplace_back(x);\n\
    \        self(s - x, self);\n        p.pop_back();\n      }\n    }\n  };\n  dfs(n,\
    \ dfs);\n}\n"
  code: "template<typename F>\nrequires invocable<F, vector<int>>\nvoid enumerate_integer_partition(int\
    \ n, F f) {\n  assert(n >= 0);\n  vector<int> p;\n  auto dfs = [&](int s, auto\
    \ &self) -> void {\n    if (s == 0) {\n      f(p);\n    } else {\n      for(int\
    \ x = (p.empty() ? s : min(p.back(), s)); x > 0; x--) {\n        p.emplace_back(x);\n\
    \        self(s - x, self);\n        p.pop_back();\n      }\n    }\n  };\n  dfs(n,\
    \ dfs);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/enumerate_integer_partition.cpp
  requiredBy: []
  timestamp: '2026-01-29 02:59:39+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: enumerate/enumerate_integer_partition.cpp
layout: document
redirect_from:
- /library/enumerate/enumerate_integer_partition.cpp
- /library/enumerate/enumerate_integer_partition.cpp.html
title: enumerate/enumerate_integer_partition.cpp
---
