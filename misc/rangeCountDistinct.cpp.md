---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/static_range_count_distinct.test.cpp
    title: test/static_range_count_distinct.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/rangeCountDistinct.cpp\"\n//#include<ds/fenwickTree.cpp>\n\
    //#include<misc/compression.cpp>\n\ntemplate<class T>\nvector<int> rangeCountDistinct(vector<T>\
    \ a, vector<array<int, 2>> query) {\n  vector<int> b = [&]() {\n    compression\
    \ ys(a);\n    return ys.ord;\n  }();\n\n  vector<int> qId(ssize(query));\n  iota(qId.begin(),\
    \ qId.end(), 0);\n  R::sort(qId, less<int>{}, [&](auto &i) { return query[i][1];\
    \ });\n\n  fenwickTree<int> ft(ssize(a));\n  vector<int> ans(ssize(query)), pos(ssize(b),\
    \ -1);\n  for(int ptr = 0; int i : qId) {\n    auto [l, r] = query[i];\n    if\
    \ (l == r) continue;\n    while(ptr < r) {\n      ft.add(pos[b[ptr]] + 1, 1);\n\
    \      ft.add(ptr + 1, -1);\n      pos[b[ptr]] = ptr, ptr++;\n    }\n    ans[i]\
    \ = ft.query(l);\n  }\n\n  return ans;\n}\n"
  code: "//#include<ds/fenwickTree.cpp>\n//#include<misc/compression.cpp>\n\ntemplate<class\
    \ T>\nvector<int> rangeCountDistinct(vector<T> a, vector<array<int, 2>> query)\
    \ {\n  vector<int> b = [&]() {\n    compression ys(a);\n    return ys.ord;\n \
    \ }();\n\n  vector<int> qId(ssize(query));\n  iota(qId.begin(), qId.end(), 0);\n\
    \  R::sort(qId, less<int>{}, [&](auto &i) { return query[i][1]; });\n\n  fenwickTree<int>\
    \ ft(ssize(a));\n  vector<int> ans(ssize(query)), pos(ssize(b), -1);\n  for(int\
    \ ptr = 0; int i : qId) {\n    auto [l, r] = query[i];\n    if (l == r) continue;\n\
    \    while(ptr < r) {\n      ft.add(pos[b[ptr]] + 1, 1);\n      ft.add(ptr + 1,\
    \ -1);\n      pos[b[ptr]] = ptr, ptr++;\n    }\n    ans[i] = ft.query(l);\n  }\n\
    \n  return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/rangeCountDistinct.cpp
  requiredBy: []
  timestamp: '2024-02-11 15:11:45+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/static_range_count_distinct.test.cpp
documentation_of: misc/rangeCountDistinct.cpp
layout: document
redirect_from:
- /library/misc/rangeCountDistinct.cpp
- /library/misc/rangeCountDistinct.cpp.html
title: misc/rangeCountDistinct.cpp
---
