---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest_tree.test.cpp
    title: test/mytest_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/prufer_recover.cpp\"\n//empty vector would be assumed\
    \ to be n = 2\nvector<pii> prufer_recover(vector<int> prufer_code) {\n  const\
    \ int n = ssize(prufer_code) + 2;\n  assert(prufer_code.empty() or (ranges::min(prufer_code)\
    \ >= 0 and ranges::max(prufer_code) < n));\n  vector<int> d(n, 1);\n  for(int\
    \ x : prufer_code) d[x]++;\n  min_heap<int> leaf;\n  for(int v = 0; v < n; v++)\n\
    \    if (d[v] == 1)\n      leaf.emplace(v);\n  vector<pii> edges;\n  for(int x\
    \ : prufer_code) {\n    int v = leaf.top(); leaf.pop();\n    edges.emplace_back(v,\
    \ x);\n    if (--d[x] == 1)\n      leaf.emplace(x);\n  }\n  int v = leaf.top();\
    \ leaf.pop();\n  edges.emplace_back(v, leaf.top());\n  return edges;\n}\n"
  code: "//empty vector would be assumed to be n = 2\nvector<pii> prufer_recover(vector<int>\
    \ prufer_code) {\n  const int n = ssize(prufer_code) + 2;\n  assert(prufer_code.empty()\
    \ or (ranges::min(prufer_code) >= 0 and ranges::max(prufer_code) < n));\n  vector<int>\
    \ d(n, 1);\n  for(int x : prufer_code) d[x]++;\n  min_heap<int> leaf;\n  for(int\
    \ v = 0; v < n; v++)\n    if (d[v] == 1)\n      leaf.emplace(v);\n  vector<pii>\
    \ edges;\n  for(int x : prufer_code) {\n    int v = leaf.top(); leaf.pop();\n\
    \    edges.emplace_back(v, x);\n    if (--d[x] == 1)\n      leaf.emplace(x);\n\
    \  }\n  int v = leaf.top(); leaf.pop();\n  edges.emplace_back(v, leaf.top());\n\
    \  return edges;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/prufer_recover.cpp
  requiredBy: []
  timestamp: '2026-01-29 02:59:39+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest_tree.test.cpp
documentation_of: graph/prufer_recover.cpp
layout: document
redirect_from:
- /library/graph/prufer_recover.cpp
- /library/graph/prufer_recover.cpp.html
title: graph/prufer_recover.cpp
---
