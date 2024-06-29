---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/maximum_independent_set.test.cpp
    title: test/maximum_independent_set.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/MIS.cpp\"\nvector<int> MIS(vector<ull> g, int n) {\n\
    \  vector<unsigned> pre(1 << (n / 2));\n  for(unsigned msk = 0; msk < (1 << (n\
    \ / 2)); msk++) {\n    int adj = 0;\n    for(int v = 0; v < n / 2; v++)\n    \
    \  if (msk >> v & 1)\n        adj |= g[v];\n    if (!(adj & msk))\n      pre[msk]\
    \ = msk;\n  }\n  for(int i = 0; (1 << i) < ssize(pre); i++)\n    for(int j = 0;\
    \ j < ssize(pre); j++)\n      if ((j >> i & 1) and popcount(pre[j ^ (1 << i)])\
    \ > popcount(pre[j]))\n        pre[j] = pre[j ^ (1 << i)];\n\n  ull best = 0;\n\
    \  auto dfs = [&](int v, ull is, ull adj, auto self) -> void {\n    if (v == n\
    \ / 2 - 1) {\n      is |= pre[~adj & ((1LL << (n / 2)) - 1)];\n      if (popcount(is)\
    \ > popcount(best))\n        best = is;\n    } else  {\n      self(v - 1, is,\
    \ adj, self);\n      adj |= g[v];\n      if (~adj >> v & 1)\n        self(v -\
    \ 1, is | (1LL << v), adj, self);\n    }\n  };\n\n  dfs(n - 1, 0, 0, dfs);\n\n\
    \  vector<int> mis;\n  for(int v = 0; v < n; v++)\n    if (best >> v & 1)\n  \
    \    mis.emplace_back(v);\n\n  return mis;\n}\n"
  code: "vector<int> MIS(vector<ull> g, int n) {\n  vector<unsigned> pre(1 << (n /\
    \ 2));\n  for(unsigned msk = 0; msk < (1 << (n / 2)); msk++) {\n    int adj =\
    \ 0;\n    for(int v = 0; v < n / 2; v++)\n      if (msk >> v & 1)\n        adj\
    \ |= g[v];\n    if (!(adj & msk))\n      pre[msk] = msk;\n  }\n  for(int i = 0;\
    \ (1 << i) < ssize(pre); i++)\n    for(int j = 0; j < ssize(pre); j++)\n     \
    \ if ((j >> i & 1) and popcount(pre[j ^ (1 << i)]) > popcount(pre[j]))\n     \
    \   pre[j] = pre[j ^ (1 << i)];\n\n  ull best = 0;\n  auto dfs = [&](int v, ull\
    \ is, ull adj, auto self) -> void {\n    if (v == n / 2 - 1) {\n      is |= pre[~adj\
    \ & ((1LL << (n / 2)) - 1)];\n      if (popcount(is) > popcount(best))\n     \
    \   best = is;\n    } else  {\n      self(v - 1, is, adj, self);\n      adj |=\
    \ g[v];\n      if (~adj >> v & 1)\n        self(v - 1, is | (1LL << v), adj, self);\n\
    \    }\n  };\n\n  dfs(n - 1, 0, 0, dfs);\n\n  vector<int> mis;\n  for(int v =\
    \ 0; v < n; v++)\n    if (best >> v & 1)\n      mis.emplace_back(v);\n\n  return\
    \ mis;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/MIS.cpp
  requiredBy: []
  timestamp: '2024-01-28 03:46:27+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/maximum_independent_set.test.cpp
documentation_of: graph/MIS.cpp
layout: document
redirect_from:
- /library/graph/MIS.cpp
- /library/graph/MIS.cpp.html
title: graph/MIS.cpp
---
