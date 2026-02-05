---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest_auxiliary_tree.test.cpp
    title: test/mytest_auxiliary_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest_tree.test.cpp
    title: test/mytest_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest_tree_diameter.test.cpp
    title: test/mytest_tree_diameter.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/prufer_recover.cpp\"\n//empty vector would be assumed\
    \ to be n = 2\nvc<pii> prufer_recover(vi prufer_code) {\n  const int n = ssize(prufer_code)\
    \ + 2;\n  assert(prufer_code.empty() or (ranges::min(prufer_code) >= 0 and ranges::max(prufer_code)\
    \ < n));\n  vi d(n, 1);\n  for(int x : prufer_code) d[x]++;\n  min_heap<int> leaf;\n\
    \  for(int v = 0; v < n; v++)\n    if (d[v] == 1)\n      leaf.emplace(v);\n  vc<pii>\
    \ edges;\n  for(int x : prufer_code) {\n    int v = leaf.top(); leaf.pop();\n\
    \    edges.emplace_back(v, x);\n    if (--d[x] == 1)\n      leaf.emplace(x);\n\
    \  }\n  int v = leaf.top(); leaf.pop();\n  edges.emplace_back(v, leaf.top());\n\
    \  return edges;\n}\n"
  code: "//empty vector would be assumed to be n = 2\nvc<pii> prufer_recover(vi prufer_code)\
    \ {\n  const int n = ssize(prufer_code) + 2;\n  assert(prufer_code.empty() or\
    \ (ranges::min(prufer_code) >= 0 and ranges::max(prufer_code) < n));\n  vi d(n,\
    \ 1);\n  for(int x : prufer_code) d[x]++;\n  min_heap<int> leaf;\n  for(int v\
    \ = 0; v < n; v++)\n    if (d[v] == 1)\n      leaf.emplace(v);\n  vc<pii> edges;\n\
    \  for(int x : prufer_code) {\n    int v = leaf.top(); leaf.pop();\n    edges.emplace_back(v,\
    \ x);\n    if (--d[x] == 1)\n      leaf.emplace(x);\n  }\n  int v = leaf.top();\
    \ leaf.pop();\n  edges.emplace_back(v, leaf.top());\n  return edges;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/prufer_recover.cpp
  requiredBy: []
  timestamp: '2026-02-02 01:08:31+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest_tree_diameter.test.cpp
  - test/mytest_tree.test.cpp
  - test/mytest_auxiliary_tree.test.cpp
documentation_of: tree/prufer_recover.cpp
layout: document
redirect_from:
- /library/tree/prufer_recover.cpp
- /library/tree/prufer_recover.cpp.html
title: tree/prufer_recover.cpp
---
