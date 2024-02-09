---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/area_of_union_of_rectangles.test.cpp
    title: test/area_of_union_of_rectangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/areaOfUnionOfRectangles.cpp\"\n//#include<segtree/lazySegmentTree.cpp>\n\
    //#include<segtree/ultraLazySegmentTree.cpp>\n//#include<actedmonoid/actedMonoid_addMinCnt.cpp>\n\
    //#include<misc/compression.cpp>\n\ntemplate<class T1, class T2>\nT2 areaOfUnionOfRectangles(vector<array<T1,\
    \ 4>> rect) {\n  compression<T1> xs(2 * ssize(rect)), ys(2 * ssize(rect));\n \
    \ xs.insert(rect, [](auto &x) { return x[0]; });\n  xs.insert(rect, [](auto &x)\
    \ { return x[1]; });\n  ys.insert(rect, [](auto &x) { return x[2]; });\n  ys.insert(rect,\
    \ [](auto &x) { return x[3]; });\n  xs.precompute();\n  ys.precompute();\n  xs.mapping(rect,\
    \ [](auto &x) -> T1& { return x[0]; });\n  xs.mapping(rect, [](auto &x) -> T1&\
    \ { return x[1]; });\n  ys.mapping(rect, [](auto &x) -> T1& { return x[2]; });\n\
    \  ys.mapping(rect, [](auto &x) -> T1& { return x[3]; });\n\n  vector<tuple<T1,\
    \ int, int>> add;\n  add.reserve(ssize(rect));\n  for(int i = 0; auto &[l, r,\
    \ _, __] : rect) {\n    add.emplace_back(l, 1, i);\n    add.emplace_back(r, -1,\
    \ i++);\n  }\n  R::sort(add, {}, [](auto &x) { return get<0>(x); });\n\n  vector<pair<T1,\
    \ T1>> init(ys.size() - 1);\n  for(int i = 0; i + 1 < ys.size(); i++)\n    init[i]\
    \ = make_pair(T1(0), ys.val[i + 1] - ys.val[i]);\n  ultraLazySegmentTree<actedMonoid_addMinCnt<T1>>\
    \ st(init);\n\n  T2 ans = 0;\n  for(int i = 1, ptr = 0; i < xs.size(); i++) {\n\
    \    while(ptr < ssize(add) and get<0>(add[ptr]) < i) {\n      auto [x, r, i]\
    \ = add[ptr++];\n      auto [_, __, d, u] = rect[i];\n      st.modify(d, u, r);\n\
    \    }\n    ans += T2(xs.val[i] - xs.val[i - 1]) * ((ys.val.back() - ys.val[0])\
    \ - actedMonoid_addMinCnt<T1>::Mop(st.query(0, st.size), make_pair(0, 0)).second);\n\
    \  }\n\n  return ans;\n}\n"
  code: "//#include<segtree/lazySegmentTree.cpp>\n//#include<segtree/ultraLazySegmentTree.cpp>\n\
    //#include<actedmonoid/actedMonoid_addMinCnt.cpp>\n//#include<misc/compression.cpp>\n\
    \ntemplate<class T1, class T2>\nT2 areaOfUnionOfRectangles(vector<array<T1, 4>>\
    \ rect) {\n  compression<T1> xs(2 * ssize(rect)), ys(2 * ssize(rect));\n  xs.insert(rect,\
    \ [](auto &x) { return x[0]; });\n  xs.insert(rect, [](auto &x) { return x[1];\
    \ });\n  ys.insert(rect, [](auto &x) { return x[2]; });\n  ys.insert(rect, [](auto\
    \ &x) { return x[3]; });\n  xs.precompute();\n  ys.precompute();\n  xs.mapping(rect,\
    \ [](auto &x) -> T1& { return x[0]; });\n  xs.mapping(rect, [](auto &x) -> T1&\
    \ { return x[1]; });\n  ys.mapping(rect, [](auto &x) -> T1& { return x[2]; });\n\
    \  ys.mapping(rect, [](auto &x) -> T1& { return x[3]; });\n\n  vector<tuple<T1,\
    \ int, int>> add;\n  add.reserve(ssize(rect));\n  for(int i = 0; auto &[l, r,\
    \ _, __] : rect) {\n    add.emplace_back(l, 1, i);\n    add.emplace_back(r, -1,\
    \ i++);\n  }\n  R::sort(add, {}, [](auto &x) { return get<0>(x); });\n\n  vector<pair<T1,\
    \ T1>> init(ys.size() - 1);\n  for(int i = 0; i + 1 < ys.size(); i++)\n    init[i]\
    \ = make_pair(T1(0), ys.val[i + 1] - ys.val[i]);\n  ultraLazySegmentTree<actedMonoid_addMinCnt<T1>>\
    \ st(init);\n\n  T2 ans = 0;\n  for(int i = 1, ptr = 0; i < xs.size(); i++) {\n\
    \    while(ptr < ssize(add) and get<0>(add[ptr]) < i) {\n      auto [x, r, i]\
    \ = add[ptr++];\n      auto [_, __, d, u] = rect[i];\n      st.modify(d, u, r);\n\
    \    }\n    ans += T2(xs.val[i] - xs.val[i - 1]) * ((ys.val.back() - ys.val[0])\
    \ - actedMonoid_addMinCnt<T1>::Mop(st.query(0, st.size), make_pair(0, 0)).second);\n\
    \  }\n\n  return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/areaOfUnionOfRectangles.cpp
  requiredBy: []
  timestamp: '2024-02-09 22:19:36+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/area_of_union_of_rectangles.test.cpp
documentation_of: misc/areaOfUnionOfRectangles.cpp
layout: document
redirect_from:
- /library/misc/areaOfUnionOfRectangles.cpp
- /library/misc/areaOfUnionOfRectangles.cpp.html
title: misc/areaOfUnionOfRectangles.cpp
---
