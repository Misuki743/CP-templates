---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/area_of_union_of_rectangles.test.cpp
    title: test/area_of_union_of_rectangles.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/range_kth_smallest.test.cpp
    title: test/range_kth_smallest.test.cpp
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
    \    R::sort(val);\n    if constexpr (duplicate) {\n      vector<int> cnt(ssize(init));\n\
    \      iota(cnt.begin(), cnt.end(), 0);\n      for(int i = 0; i < ssize(ord);\
    \ i++)\n        ord[i] = cnt[lower_bound(init[i])]++;\n    } else {\n      val.resize(unique(val.begin(),\
    \ val.end()) - val.begin());\n      for(int i = 0; i < ssize(ord); i++)\n    \
    \    ord[i] = lower_bound(init[i]);\n    }\n  }\n\n  int lower_bound(T x) { return\
    \ R::lower_bound(val, x) - val.begin(); }\n  int size() { return ssize(val); }\n\
    \  template<R::range rng, class proj = identity>\n  void mapping(rng &v, proj\
    \ p = {}) { for(auto &x : v) p(x) = lower_bound(p(x)); }\n  template<R::range\
    \ rng, class proj = identity>\n  void insert(rng &v, proj p = {}) { for(auto &x\
    \ : v) val.emplace_back(p(x)); }\n};\n"
  code: "template<class T, bool duplicate = false>\nstruct compression {\n  vector<int>\
    \ ord;\n  vector<T> val;\n\n  compression(vector<T> &init) : val(init) { precompute();\
    \ }\n  compression(int size = 0) { val.reserve(size); }\n\n  void precompute()\
    \ {\n    vector<T> init = val;\n    ord.resize(ssize(val));\n    R::sort(val);\n\
    \    if constexpr (duplicate) {\n      vector<int> cnt(ssize(init));\n      iota(cnt.begin(),\
    \ cnt.end(), 0);\n      for(int i = 0; i < ssize(ord); i++)\n        ord[i] =\
    \ cnt[lower_bound(init[i])]++;\n    } else {\n      val.resize(unique(val.begin(),\
    \ val.end()) - val.begin());\n      for(int i = 0; i < ssize(ord); i++)\n    \
    \    ord[i] = lower_bound(init[i]);\n    }\n  }\n\n  int lower_bound(T x) { return\
    \ R::lower_bound(val, x) - val.begin(); }\n  int size() { return ssize(val); }\n\
    \  template<R::range rng, class proj = identity>\n  void mapping(rng &v, proj\
    \ p = {}) { for(auto &x : v) p(x) = lower_bound(p(x)); }\n  template<R::range\
    \ rng, class proj = identity>\n  void insert(rng &v, proj p = {}) { for(auto &x\
    \ : v) val.emplace_back(p(x)); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/compression.cpp
  requiredBy: []
  timestamp: '2024-01-27 18:42:26+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/static_range_frequency.test.cpp
  - test/area_of_union_of_rectangles.test.cpp
  - test/range_kth_smallest.test.cpp
documentation_of: misc/compression.cpp
layout: document
redirect_from:
- /library/misc/compression.cpp
- /library/misc/compression.cpp.html
title: misc/compression.cpp
---
