---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest_auxiliary_tree.test.cpp
    title: test/mytest_auxiliary_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest_enumerate_twelvefold.test.cpp
    title: test/mytest_enumerate_twelvefold.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest_tree.test.cpp
    title: test/mytest_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest_tree_diameter.test.cpp
    title: test/mytest_tree_diameter.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/enumerate_bit.cpp\"\n\ntemplate<typename F, typename\
    \ INT>\nrequires invocable<F, INT>\nvoid enumerate_subset(INT msk, F f) {\n  for(INT\
    \ x = msk; x > 0; x = (x - 1) & msk)\n    f(x);\n  f(0);\n}\n"
  code: "\ntemplate<typename F, typename INT>\nrequires invocable<F, INT>\nvoid enumerate_subset(INT\
    \ msk, F f) {\n  for(INT x = msk; x > 0; x = (x - 1) & msk)\n    f(x);\n  f(0);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/enumerate_bit.cpp
  requiredBy: []
  timestamp: '2026-01-29 06:19:40+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest_tree_diameter.test.cpp
  - test/mytest_enumerate_twelvefold.test.cpp
  - test/mytest_tree.test.cpp
  - test/mytest_auxiliary_tree.test.cpp
documentation_of: enumerate/enumerate_bit.cpp
layout: document
redirect_from:
- /library/enumerate/enumerate_bit.cpp
- /library/enumerate/enumerate_bit.cpp.html
title: enumerate/enumerate_bit.cpp
---
