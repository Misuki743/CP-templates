---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/range_kth_smallest.test.cpp
    title: test/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/static_range_frequency.test.cpp
    title: test/static_range_frequency.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/compression.cpp\"\ntemplate<class T, bool duplicate\
    \ = false>\nstruct compression {\n  vector<int> ord;\n  vector<T> val;\n  compression(vector<T>\
    \ &init) : ord(ssize(init)), val(init) {\n    R::sort(val);\n    if constexpr\
    \ (duplicate) {\n      vector<int> cnt(ssize(init));\n      iota(cnt.begin(),\
    \ cnt.end(), 0);\n      for(int i = 0; i < ssize(init); i++)\n        ord[i] =\
    \ cnt[lb(init[i])]++;\n    } else {\n      val.resize(unique(val.begin(), val.end())\
    \ - val.begin());\n      for(int i = 0; i < ssize(init); i++)\n        ord[i]\
    \ = lb(init[i]);\n    }\n  }\n  int lb(T x) { return R::lower_bound(val, x) -\
    \ val.begin(); }\n};\n"
  code: "template<class T, bool duplicate = false>\nstruct compression {\n  vector<int>\
    \ ord;\n  vector<T> val;\n  compression(vector<T> &init) : ord(ssize(init)), val(init)\
    \ {\n    R::sort(val);\n    if constexpr (duplicate) {\n      vector<int> cnt(ssize(init));\n\
    \      iota(cnt.begin(), cnt.end(), 0);\n      for(int i = 0; i < ssize(init);\
    \ i++)\n        ord[i] = cnt[lb(init[i])]++;\n    } else {\n      val.resize(unique(val.begin(),\
    \ val.end()) - val.begin());\n      for(int i = 0; i < ssize(init); i++)\n   \
    \     ord[i] = lb(init[i]);\n    }\n  }\n  int lb(T x) { return R::lower_bound(val,\
    \ x) - val.begin(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/compression.cpp
  requiredBy: []
  timestamp: '2024-01-27 01:09:14+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/static_range_frequency.test.cpp
  - test/range_kth_smallest.test.cpp
documentation_of: misc/compression.cpp
layout: document
redirect_from:
- /library/misc/compression.cpp
- /library/misc/compression.cpp.html
title: misc/compression.cpp
---
