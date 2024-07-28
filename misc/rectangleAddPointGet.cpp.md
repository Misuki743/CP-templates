---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/rectangle_add_point_get.test.cpp
    title: test/rectangle_add_point_get.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/rectangleAddPointGet.cpp\"\n//#include<ds/fenwickTree2D.cpp>\n\
    //#include<misc/compression.cpp>\n\ntemplate<class T1, class T2>\nvector<T2> rectAddPointGet(vector<tuple<T1,\
    \ T1, T1, T1, T2>> &rect, vector<array<T1, 2>> &query, vector<int> updT) {\n \
    \ compression<T1> xs(ssize(query));\n  xs.insert(query, [](auto &x) { return x[0];\
    \ });\n  xs.precompute();\n  xs.mapping(query, [](auto &x) -> T1& { return x[0];\
    \ });\n  xs.mapping(rect, [](auto &x) -> T1& { return get<0>(x); });\n  xs.mapping(rect,\
    \ [](auto &x) -> T1& { return get<1>(x); });\n\n  FT2<T1, T2> bit(xs.size());\n\
    \  for(auto &[l, r, d, u, w] : rect) {\n    bit.fakeUpdate(l, d);\n    bit.fakeUpdate(r,\
    \ u);\n    bit.fakeUpdate(l, u);\n    bit.fakeUpdate(r, d);\n  }\n  bit.init();\n\
    \n  vector<T2> ans(ssize(query));\n  for(int i = 0, ptr = 0; auto &[x, y] : query)\
    \ {\n    while(ptr < ssize(rect) and updT[ptr] <= i) {\n      auto [l, r, d, u,\
    \ w] = rect[ptr++];\n      bit.update(l, d, w);\n      bit.update(r, u, w);\n\
    \      bit.update(l, u, -w);\n      bit.update(r, d, -w);\n    }\n    ans[i++]\
    \ = bit.query(x + 1, y + 1);\n  }\n\n  return ans;\n}\n"
  code: "//#include<ds/fenwickTree2D.cpp>\n//#include<misc/compression.cpp>\n\ntemplate<class\
    \ T1, class T2>\nvector<T2> rectAddPointGet(vector<tuple<T1, T1, T1, T1, T2>>\
    \ &rect, vector<array<T1, 2>> &query, vector<int> updT) {\n  compression<T1> xs(ssize(query));\n\
    \  xs.insert(query, [](auto &x) { return x[0]; });\n  xs.precompute();\n  xs.mapping(query,\
    \ [](auto &x) -> T1& { return x[0]; });\n  xs.mapping(rect, [](auto &x) -> T1&\
    \ { return get<0>(x); });\n  xs.mapping(rect, [](auto &x) -> T1& { return get<1>(x);\
    \ });\n\n  FT2<T1, T2> bit(xs.size());\n  for(auto &[l, r, d, u, w] : rect) {\n\
    \    bit.fakeUpdate(l, d);\n    bit.fakeUpdate(r, u);\n    bit.fakeUpdate(l, u);\n\
    \    bit.fakeUpdate(r, d);\n  }\n  bit.init();\n\n  vector<T2> ans(ssize(query));\n\
    \  for(int i = 0, ptr = 0; auto &[x, y] : query) {\n    while(ptr < ssize(rect)\
    \ and updT[ptr] <= i) {\n      auto [l, r, d, u, w] = rect[ptr++];\n      bit.update(l,\
    \ d, w);\n      bit.update(r, u, w);\n      bit.update(l, u, -w);\n      bit.update(r,\
    \ d, -w);\n    }\n    ans[i++] = bit.query(x + 1, y + 1);\n  }\n\n  return ans;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/rectangleAddPointGet.cpp
  requiredBy: []
  timestamp: '2024-01-28 22:59:51+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/rectangle_add_point_get.test.cpp
documentation_of: misc/rectangleAddPointGet.cpp
layout: document
redirect_from:
- /library/misc/rectangleAddPointGet.cpp
- /library/misc/rectangleAddPointGet.cpp.html
title: misc/rectangleAddPointGet.cpp
---
