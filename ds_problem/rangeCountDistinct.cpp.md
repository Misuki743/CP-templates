---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/static_range_count_distinct.test.cpp
    title: test/static_range_count_distinct.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds_problem/rangeCountDistinct.cpp\"\n//#include<ds/fenwickTree.cpp>\n\
    //#include<misc/compression.cpp>\n\ntemplate<class T>\nvector<int> rangeCountDistinct(vector<T>\
    \ a, vector<array<int, 2>> query) {\n  vector<int> b = [&]() {\n    compression\
    \ ys(a);\n    return ys.ord;\n  }();\n\n  vector<int> qId(ssize(query));\n  iota(qId.begin(),\
    \ qId.end(), 0);\n  ranges::sort(qId, less<int>{}, [&](auto &i) { return query[i][1];\
    \ });\n\n  fenwickTree<int> ft(ssize(a));\n  vector<int> ans(ssize(query)), pos(ssize(b),\
    \ -1);\n  for(int ptr = 0; int i : qId) {\n    auto [l, r] = query[i];\n    if\
    \ (l == r) continue;\n    while(ptr < r) {\n      ft.add(pos[b[ptr]] + 1, 1);\n\
    \      ft.add(ptr + 1, -1);\n      pos[b[ptr]] = ptr, ptr++;\n    }\n    ans[i]\
    \ = ft.query(l);\n  }\n\n  return ans;\n}\n"
  code: "//#include<ds/fenwickTree.cpp>\n//#include<misc/compression.cpp>\n\ntemplate<class\
    \ T>\nvector<int> rangeCountDistinct(vector<T> a, vector<array<int, 2>> query)\
    \ {\n  vector<int> b = [&]() {\n    compression ys(a);\n    return ys.ord;\n \
    \ }();\n\n  vector<int> qId(ssize(query));\n  iota(qId.begin(), qId.end(), 0);\n\
    \  ranges::sort(qId, less<int>{}, [&](auto &i) { return query[i][1]; });\n\n \
    \ fenwickTree<int> ft(ssize(a));\n  vector<int> ans(ssize(query)), pos(ssize(b),\
    \ -1);\n  for(int ptr = 0; int i : qId) {\n    auto [l, r] = query[i];\n    if\
    \ (l == r) continue;\n    while(ptr < r) {\n      ft.add(pos[b[ptr]] + 1, 1);\n\
    \      ft.add(ptr + 1, -1);\n      pos[b[ptr]] = ptr, ptr++;\n    }\n    ans[i]\
    \ = ft.query(l);\n  }\n\n  return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: ds_problem/rangeCountDistinct.cpp
  requiredBy: []
  timestamp: '2024-08-04 01:36:11+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/static_range_count_distinct.test.cpp
documentation_of: ds_problem/rangeCountDistinct.cpp
layout: document
redirect_from:
- /library/ds_problem/rangeCountDistinct.cpp
- /library/ds_problem/rangeCountDistinct.cpp.html
title: ds_problem/rangeCountDistinct.cpp
---
