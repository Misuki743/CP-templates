---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/rectangle_sum.test.cpp
    title: test/rectangle_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds_problem/rectangleSum.cpp\"\n//#include<ds/fenwickTree.cpp>\n\
    //#include<misc/compression.cpp>\n\ntemplate<class T1, class T2>\nvector<T2> rectangleSum(vector<tuple<T1,\
    \ T1, T2>> pt, vector<array<T1, 4>> query) {\n  compression<T1> ys(ssize(pt));\n\
    \  ys.insert(pt, [](auto &x) { return get<1>(x); });\n  ys.precompute();\n  ys.mapping(pt,\
    \ [](auto &x) -> T1& { return get<1>(x); });\n  ys.mapping(query, [](auto &x)\
    \ -> T1& { return x[2]; });\n  ys.mapping(query, [](auto &x) -> T1& { return x[3];\
    \ });\n\n  ranges::sort(pt, less<T1>{}, [](auto x) { return get<0>(x); });\n\n\
    \  vector<tuple<T1, int, int>> qry;\n  qry.reserve(2 * ssize(query));\n  for(int\
    \ i = 0; i < ssize(query); i++) {\n    qry.emplace_back(query[i][0] - 1, -1, i);\n\
    \    qry.emplace_back(query[i][1] - 1, 1, i);\n  }\n  ranges::sort(qry, {}, [](auto\
    \ &x) { return get<0>(x); });\n\n  fenwickTree<T2> bit(ys.size());\n  vector<T2>\
    \ ans(ssize(query));\n  for(int ptr = 0; auto [x, r, i] : qry) {\n    while(ptr\
    \ < ssize(pt) and get<0>(pt[ptr]) <= x) {\n      auto [_, y, w] = pt[ptr++];\n\
    \      bit.add(y, w);\n    }\n    ans[i] += r * bit.query(query[i][2], query[i][3]);\n\
    \  }\n\n  return ans;\n}\n"
  code: "//#include<ds/fenwickTree.cpp>\n//#include<misc/compression.cpp>\n\ntemplate<class\
    \ T1, class T2>\nvector<T2> rectangleSum(vector<tuple<T1, T1, T2>> pt, vector<array<T1,\
    \ 4>> query) {\n  compression<T1> ys(ssize(pt));\n  ys.insert(pt, [](auto &x)\
    \ { return get<1>(x); });\n  ys.precompute();\n  ys.mapping(pt, [](auto &x) ->\
    \ T1& { return get<1>(x); });\n  ys.mapping(query, [](auto &x) -> T1& { return\
    \ x[2]; });\n  ys.mapping(query, [](auto &x) -> T1& { return x[3]; });\n\n  ranges::sort(pt,\
    \ less<T1>{}, [](auto x) { return get<0>(x); });\n\n  vector<tuple<T1, int, int>>\
    \ qry;\n  qry.reserve(2 * ssize(query));\n  for(int i = 0; i < ssize(query); i++)\
    \ {\n    qry.emplace_back(query[i][0] - 1, -1, i);\n    qry.emplace_back(query[i][1]\
    \ - 1, 1, i);\n  }\n  ranges::sort(qry, {}, [](auto &x) { return get<0>(x); });\n\
    \n  fenwickTree<T2> bit(ys.size());\n  vector<T2> ans(ssize(query));\n  for(int\
    \ ptr = 0; auto [x, r, i] : qry) {\n    while(ptr < ssize(pt) and get<0>(pt[ptr])\
    \ <= x) {\n      auto [_, y, w] = pt[ptr++];\n      bit.add(y, w);\n    }\n  \
    \  ans[i] += r * bit.query(query[i][2], query[i][3]);\n  }\n\n  return ans;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: ds_problem/rectangleSum.cpp
  requiredBy: []
  timestamp: '2024-08-04 01:36:11+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/rectangle_sum.test.cpp
documentation_of: ds_problem/rectangleSum.cpp
layout: document
redirect_from:
- /library/ds_problem/rectangleSum.cpp
- /library/ds_problem/rectangleSum.cpp.html
title: ds_problem/rectangleSum.cpp
---
