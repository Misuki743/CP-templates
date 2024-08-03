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
  bundledCode: "#line 1 \"ds_problem/area_of_union_of_rectangles.cpp\"\n//#include\
    \ \"segtree/lazySegmentTree.cpp\"\n//#include \"segtree/ultraLazySegmentTree.cpp\"\
    \n//#include \"actedMonoid/actedMonoid_addMinCnt.cpp\"\n\ntemplate<class coordinate_type,\
    \ class answer_type>\nanswer_type area_of_union_of_rectangles(vector<array<coordinate_type,\
    \ 4>> rect) {\n  vector<coordinate_type> xs(2 * size(rect)), ys(2 * size(rect));\n\
    \  for(int i = 0; auto [a, b, c, d] : rect)\n    tie(xs[2 * i], ys[2 * i], xs[2\
    \ * i + 1], ys[2 * i + 1]) = make_tuple(a, b, c, d), i++;\n  Unique(xs), Unique(ys);\n\
    \n  vector<array<int, 4>> event(2 * size(rect));\n  for(int i = 0; i < ssize(rect);\
    \ i++) {\n    event[2 * i] = {rect[i][0], rect[i][1], rect[i][3], 1};\n    event[2\
    \ * i + 1] = {rect[i][2], rect[i][1], rect[i][3], -1};\n  }\n  ranges::sort(event,\
    \ {}, [](auto &x) { return x[0]; });\n\n  using AM = actedMonoid_addMinCnt<coordinate_type>;\n\
    \  ultraLazySegmentTree<AM> st([&]() {\n    vector<typename AM::M> init(ssize(ys)\
    \ - 1);\n    for(int i = 0; i + 1 < ssize(ys); i++)\n      init[i] = make_pair(0,\
    \ ys[i + 1] - ys[i]);\n    return init;\n  }());\n\n  auto to_id = [&](int y)\
    \ { return ranges::lower_bound(ys, y) - ys.begin(); };\n\n  answer_type ans =\
    \ 0;\n  for(int i = 0, j = 0; ; i = j) {\n    while(j < ssize(event) and event[i][0]\
    \ == event[j][0]) j++;\n    if (j == ssize(event)) break;\n    for(int k = i;\
    \ k < j; k++) {\n      auto [_, l, r, d] = event[k];\n      st.modify(to_id(l),\
    \ to_id(r), d);\n    }\n    auto [mn, cnt] = st.query(0, st.size);\n    answer_type\
    \ w = event[j][0] - event[i][0];\n    ans += (ys.back() - ys[0] - (mn == 0 ? cnt\
    \ : 0)) * w;\n  }\n\n  return ans;\n}\n"
  code: "//#include \"segtree/lazySegmentTree.cpp\"\n//#include \"segtree/ultraLazySegmentTree.cpp\"\
    \n//#include \"actedMonoid/actedMonoid_addMinCnt.cpp\"\n\ntemplate<class coordinate_type,\
    \ class answer_type>\nanswer_type area_of_union_of_rectangles(vector<array<coordinate_type,\
    \ 4>> rect) {\n  vector<coordinate_type> xs(2 * size(rect)), ys(2 * size(rect));\n\
    \  for(int i = 0; auto [a, b, c, d] : rect)\n    tie(xs[2 * i], ys[2 * i], xs[2\
    \ * i + 1], ys[2 * i + 1]) = make_tuple(a, b, c, d), i++;\n  Unique(xs), Unique(ys);\n\
    \n  vector<array<int, 4>> event(2 * size(rect));\n  for(int i = 0; i < ssize(rect);\
    \ i++) {\n    event[2 * i] = {rect[i][0], rect[i][1], rect[i][3], 1};\n    event[2\
    \ * i + 1] = {rect[i][2], rect[i][1], rect[i][3], -1};\n  }\n  ranges::sort(event,\
    \ {}, [](auto &x) { return x[0]; });\n\n  using AM = actedMonoid_addMinCnt<coordinate_type>;\n\
    \  ultraLazySegmentTree<AM> st([&]() {\n    vector<typename AM::M> init(ssize(ys)\
    \ - 1);\n    for(int i = 0; i + 1 < ssize(ys); i++)\n      init[i] = make_pair(0,\
    \ ys[i + 1] - ys[i]);\n    return init;\n  }());\n\n  auto to_id = [&](int y)\
    \ { return ranges::lower_bound(ys, y) - ys.begin(); };\n\n  answer_type ans =\
    \ 0;\n  for(int i = 0, j = 0; ; i = j) {\n    while(j < ssize(event) and event[i][0]\
    \ == event[j][0]) j++;\n    if (j == ssize(event)) break;\n    for(int k = i;\
    \ k < j; k++) {\n      auto [_, l, r, d] = event[k];\n      st.modify(to_id(l),\
    \ to_id(r), d);\n    }\n    auto [mn, cnt] = st.query(0, st.size);\n    answer_type\
    \ w = event[j][0] - event[i][0];\n    ans += (ys.back() - ys[0] - (mn == 0 ? cnt\
    \ : 0)) * w;\n  }\n\n  return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: ds_problem/area_of_union_of_rectangles.cpp
  requiredBy: []
  timestamp: '2024-08-04 02:01:51+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/area_of_union_of_rectangles.test.cpp
documentation_of: ds_problem/area_of_union_of_rectangles.cpp
layout: document
redirect_from:
- /library/ds_problem/area_of_union_of_rectangles.cpp
- /library/ds_problem/area_of_union_of_rectangles.cpp.html
title: ds_problem/area_of_union_of_rectangles.cpp
---
