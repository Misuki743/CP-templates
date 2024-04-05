---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/point_add_range_sum.test.cpp
    title: test/point_add_range_sum.test.cpp
  - icon: ':x:'
    path: test/rectangle_sum.test.cpp
    title: test/rectangle_sum.test.cpp
  - icon: ':x:'
    path: test/static_range_count_distinct.test.cpp
    title: test/static_range_count_distinct.test.cpp
  - icon: ':x:'
    path: test/vertex_add_range_contour_sum_on_tree.test.cpp
    title: test/vertex_add_range_contour_sum_on_tree.test.cpp
  - icon: ':x:'
    path: test/vertex_get_range_contour_add_on_tree.test.cpp
    title: test/vertex_get_range_contour_add_on_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/fenwickTree.cpp\"\ntemplate<class T>\nstruct fenwickTree\
    \ {\n  const int size;\n  vector<T> data;\n\n  fenwickTree(int _size) : size(_size\
    \ + 1), data(_size + 1) {}\n  fenwickTree(vector<T> &init) : size(ssize(init)\
    \ + 1), data(ssize(init) + 1) {\n    partial_sum(init.begin(), init.end(), data.begin()\
    \ + 1);\n    for(int i = size - 1; i > 0; i--)\n      data[i] -= data[i - (i &\
    \ (-i))];\n  }\n\n  void add(int i, T d) {\n    for(i += 1; i < size; i += i &\
    \ (-i))\n      data[i] += d;\n  }\n\n  T query(int i) {\n    T res = T(0);\n \
    \   for(i += 1; i > 0; i -= i & (-i))\n      res += data[i];\n    return res;\n\
    \  }\n\n  T query(int l, int r) { //query [l, r)\n    return query(r - 1) - query(l\
    \ - 1);\n  }\n};\n"
  code: "template<class T>\nstruct fenwickTree {\n  const int size;\n  vector<T> data;\n\
    \n  fenwickTree(int _size) : size(_size + 1), data(_size + 1) {}\n  fenwickTree(vector<T>\
    \ &init) : size(ssize(init) + 1), data(ssize(init) + 1) {\n    partial_sum(init.begin(),\
    \ init.end(), data.begin() + 1);\n    for(int i = size - 1; i > 0; i--)\n    \
    \  data[i] -= data[i - (i & (-i))];\n  }\n\n  void add(int i, T d) {\n    for(i\
    \ += 1; i < size; i += i & (-i))\n      data[i] += d;\n  }\n\n  T query(int i)\
    \ {\n    T res = T(0);\n    for(i += 1; i > 0; i -= i & (-i))\n      res += data[i];\n\
    \    return res;\n  }\n\n  T query(int l, int r) { //query [l, r)\n    return\
    \ query(r - 1) - query(l - 1);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/fenwickTree.cpp
  requiredBy: []
  timestamp: '2024-04-04 16:33:52+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/rectangle_sum.test.cpp
  - test/static_range_count_distinct.test.cpp
  - test/vertex_add_range_contour_sum_on_tree.test.cpp
  - test/vertex_get_range_contour_add_on_tree.test.cpp
  - test/point_add_range_sum.test.cpp
documentation_of: ds/fenwickTree.cpp
layout: document
redirect_from:
- /library/ds/fenwickTree.cpp
- /library/ds/fenwickTree.cpp.html
title: ds/fenwickTree.cpp
---
