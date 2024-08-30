---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/point_add_rectangle_sum.test.cpp
    title: test/point_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/range_kth_smallest.test.cpp
    title: test/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/range_kth_smallest2.test.cpp
    title: test/range_kth_smallest2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/rectangle_add_point_get.test.cpp
    title: test/rectangle_add_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/rectangle_sum.test.cpp
    title: test/rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/static_range_count_distinct.test.cpp
    title: test/static_range_count_distinct.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/static_range_frequency.test.cpp
    title: test/static_range_frequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/compression.cpp\"\ntemplate<class T, bool duplicate\
    \ = false>\nstruct compression {\n  vector<int> ord;\n  vector<T> val;\n\n  compression(vector<T>\
    \ &init) : val(init) { precompute(); }\n  compression(int size = 0) { val.reserve(size);\
    \ }\n\n  void precompute() {\n    vector<T> init = val;\n    ord.resize(ssize(val));\n\
    \    ranges::sort(val);\n    if constexpr (duplicate) {\n      vector<int> cnt(ssize(init));\n\
    \      iota(cnt.begin(), cnt.end(), 0);\n      for(int i = 0; i < ssize(ord);\
    \ i++)\n        ord[i] = cnt[lower_bound(init[i])]++;\n    } else {\n      val.resize(unique(val.begin(),\
    \ val.end()) - val.begin());\n      for(int i = 0; i < ssize(ord); i++)\n    \
    \    ord[i] = lower_bound(init[i]);\n    }\n  }\n\n  int lower_bound(T x) { return\
    \ ranges::lower_bound(val, x) - val.begin(); }\n  int size() { return ssize(val);\
    \ }\n  template<ranges::range rng, class proj = identity>\n  void mapping(rng\
    \ &v, proj p = {}) { for(auto &x : v) p(x) = lower_bound(p(x)); }\n  template<ranges::range\
    \ rng, class proj = identity>\n  void insert(rng &v, proj p = {}) { for(auto &x\
    \ : v) val.emplace_back(p(x)); }\n};\n"
  code: "template<class T, bool duplicate = false>\nstruct compression {\n  vector<int>\
    \ ord;\n  vector<T> val;\n\n  compression(vector<T> &init) : val(init) { precompute();\
    \ }\n  compression(int size = 0) { val.reserve(size); }\n\n  void precompute()\
    \ {\n    vector<T> init = val;\n    ord.resize(ssize(val));\n    ranges::sort(val);\n\
    \    if constexpr (duplicate) {\n      vector<int> cnt(ssize(init));\n      iota(cnt.begin(),\
    \ cnt.end(), 0);\n      for(int i = 0; i < ssize(ord); i++)\n        ord[i] =\
    \ cnt[lower_bound(init[i])]++;\n    } else {\n      val.resize(unique(val.begin(),\
    \ val.end()) - val.begin());\n      for(int i = 0; i < ssize(ord); i++)\n    \
    \    ord[i] = lower_bound(init[i]);\n    }\n  }\n\n  int lower_bound(T x) { return\
    \ ranges::lower_bound(val, x) - val.begin(); }\n  int size() { return ssize(val);\
    \ }\n  template<ranges::range rng, class proj = identity>\n  void mapping(rng\
    \ &v, proj p = {}) { for(auto &x : v) p(x) = lower_bound(p(x)); }\n  template<ranges::range\
    \ rng, class proj = identity>\n  void insert(rng &v, proj p = {}) { for(auto &x\
    \ : v) val.emplace_back(p(x)); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/compression.cpp
  requiredBy: []
  timestamp: '2024-04-05 18:02:52+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/static_range_count_distinct.test.cpp
  - test/range_kth_smallest.test.cpp
  - test/rectangle_add_point_get.test.cpp
  - test/static_range_frequency.test.cpp
  - test/point_add_rectangle_sum.test.cpp
  - test/rectangle_sum.test.cpp
  - test/range_kth_smallest2.test.cpp
documentation_of: misc/compression.cpp
layout: document
title: compression
---

An std-like coordinate compression template

about some usage cases of projection, see `misc/rectangleSum.cpp`

## usage

#### constructors

- `compression(vector<T> &init)` initialize with coordinates in init
- `compression(int size = 0)` reserve space for later addition of coordinates, after finishing inserting coordinate, call precompute()

#### member functions

- `void precompute()` do coordinate compression and store result in `ord` and `val`
- `int lower_bound(T x)` find # of coordinates less than $x$
- `int size()` return # of coordinates
- `void mapping(rng &v, proj p = {})` replace coordinates in a range `v` with its compressed coordinates, projection is allowed to used so you can do e.g. mapping a certain entry of a `vector<array<T, sz>>`
- `void insert(rng &v, proj p = {})` insert coordinates in a range `v`, projection is allowed to used so you can do e.g. inserting certain entry of a `vector<array<T, sz>>`

