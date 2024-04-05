---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/point_add_rectangle_sum.test.cpp
    title: test/point_add_rectangle_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/pointAddRectangleSum.cpp\"\n//#include<ds/fenwickTree2D.cpp>\n\
    //#include<misc/compression.cpp>\n\ntemplate<class T1, class T2>\nvector<T2> pointAddRectSum(vector<tuple<T1,\
    \ T1, T2>> pt, vector<array<T1, 4>> query, vector<int> updT) {\n  compression<T1>\
    \ xs(ssize(pt));\n  xs.insert(pt, [](auto &x) { return get<0>(x); });\n  xs.precompute();\n\
    \  xs.mapping(pt, [](auto &x) -> T1& { return get<0>(x); });\n  xs.mapping(query,\
    \ [](auto &x) -> T1& { return x[0]; });\n  xs.mapping(query, [](auto &x) -> T1&\
    \ { return x[1]; });\n\n  FT2<T1, T2> bit(xs.size());\n  for(auto [x, y, __] :\
    \ pt)\n    bit.fakeUpdate(x, y);\n  bit.init();\n\n  vector<T2> ans(ssize(query));\n\
    \  for(int i = 0, ptr = 0; auto [l, r, d, u] : query) {\n    while(ptr < ssize(pt)\
    \ and updT[ptr] <= i) {\n      auto [x, y, w] = pt[ptr++];\n      bit.update(x,\
    \ y, w);\n    }\n    ans[i++] = bit.query(r, u) - bit.query(l, u) - bit.query(r,\
    \ d) + bit.query(l, d);\n  }\n  \n  return ans;\n}\n"
  code: "//#include<ds/fenwickTree2D.cpp>\n//#include<misc/compression.cpp>\n\ntemplate<class\
    \ T1, class T2>\nvector<T2> pointAddRectSum(vector<tuple<T1, T1, T2>> pt, vector<array<T1,\
    \ 4>> query, vector<int> updT) {\n  compression<T1> xs(ssize(pt));\n  xs.insert(pt,\
    \ [](auto &x) { return get<0>(x); });\n  xs.precompute();\n  xs.mapping(pt, [](auto\
    \ &x) -> T1& { return get<0>(x); });\n  xs.mapping(query, [](auto &x) -> T1& {\
    \ return x[0]; });\n  xs.mapping(query, [](auto &x) -> T1& { return x[1]; });\n\
    \n  FT2<T1, T2> bit(xs.size());\n  for(auto [x, y, __] : pt)\n    bit.fakeUpdate(x,\
    \ y);\n  bit.init();\n\n  vector<T2> ans(ssize(query));\n  for(int i = 0, ptr\
    \ = 0; auto [l, r, d, u] : query) {\n    while(ptr < ssize(pt) and updT[ptr] <=\
    \ i) {\n      auto [x, y, w] = pt[ptr++];\n      bit.update(x, y, w);\n    }\n\
    \    ans[i++] = bit.query(r, u) - bit.query(l, u) - bit.query(r, d) + bit.query(l,\
    \ d);\n  }\n  \n  return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/pointAddRectangleSum.cpp
  requiredBy: []
  timestamp: '2024-01-28 22:59:51+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/point_add_rectangle_sum.test.cpp
documentation_of: misc/pointAddRectangleSum.cpp
layout: document
redirect_from:
- /library/misc/pointAddRectangleSum.cpp
- /library/misc/pointAddRectangleSum.cpp.html
title: misc/pointAddRectangleSum.cpp
---
