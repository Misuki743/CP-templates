---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dynamic_sequence_range_affine_range_sum.test.cpp
    title: test/dynamic_sequence_range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/queue_operate_all_composite.test.cpp
    title: test/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/range_affine_range_sum.test.cpp
    title: test/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/range_set_range_composite.test.cpp
    title: test/range_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/vertex_set_path_composite.test.cpp
    title: test/vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"actedmonoid/actedMonoid_affineSum.cpp\"\ntemplate<class\
    \ U>\nstruct actedMonoid_affineSum {\n  using M = array<U, 2>;\n  static M Mid()\
    \ { return M{0, 0}; }\n  static M Mop(const M &a, const M &b) { return {a[0] +\
    \ b[0], a[1] + b[1]}; }\n  using T = array<U, 2>;\n  static T Tid() { return T{1,\
    \ 0}; }\n  static T Top(const T &a, const T &b) { return T{a[0] * b[0], a[1] *\
    \ b[0] + b[1]}; }\n  static M act(const M &a, const T &b) { return {a[0] * b[0]\
    \ + a[1] * b[1], a[1]}; }\n};\n"
  code: "template<class U>\nstruct actedMonoid_affineSum {\n  using M = array<U, 2>;\n\
    \  static M Mid() { return M{0, 0}; }\n  static M Mop(const M &a, const M &b)\
    \ { return {a[0] + b[0], a[1] + b[1]}; }\n  using T = array<U, 2>;\n  static T\
    \ Tid() { return T{1, 0}; }\n  static T Top(const T &a, const T &b) { return T{a[0]\
    \ * b[0], a[1] * b[0] + b[1]}; }\n  static M act(const M &a, const T &b) { return\
    \ {a[0] * b[0] + a[1] * b[1], a[1]}; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: actedmonoid/actedMonoid_affineSum.cpp
  requiredBy: []
  timestamp: '2024-02-09 22:57:04+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dynamic_sequence_range_affine_range_sum.test.cpp
  - test/range_set_range_composite.test.cpp
  - test/vertex_set_path_composite.test.cpp
  - test/queue_operate_all_composite.test.cpp
  - test/range_affine_range_sum.test.cpp
documentation_of: actedmonoid/actedMonoid_affineSum.cpp
layout: document
redirect_from:
- /library/actedmonoid/actedMonoid_affineSum.cpp
- /library/actedmonoid/actedMonoid_affineSum.cpp.html
title: actedmonoid/actedMonoid_affineSum.cpp
---
