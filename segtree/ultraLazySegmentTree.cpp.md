---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/area_of_union_of_rectangles.test.cpp
    title: test/area_of_union_of_rectangles.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/range_affine_range_sum.test.cpp
    title: test/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segtree/ultraLazySegmentTree.cpp\"\n//#include<segtree/lazySegmentTree.cpp>\n\
    \ntemplate<class AM>\nstruct ultraLazySegmentTree : lazySegmentTree<typename AM::M,\
    \ AM::Mid, AM::Mop, typename AM::T, AM::Tid, AM::Top, AM::act> {\n  using base\
    \ = lazySegmentTree<typename AM::M, AM::Mid, AM::Mop, typename AM::T, AM::Tid,\
    \ AM::Top, AM::act>;\n  ultraLazySegmentTree(vector<typename AM::M> init) : base(init)\
    \ {}\n  ultraLazySegmentTree(int size) : base(size) {}\n};\n"
  code: "//#include<segtree/lazySegmentTree.cpp>\n\ntemplate<class AM>\nstruct ultraLazySegmentTree\
    \ : lazySegmentTree<typename AM::M, AM::Mid, AM::Mop, typename AM::T, AM::Tid,\
    \ AM::Top, AM::act> {\n  using base = lazySegmentTree<typename AM::M, AM::Mid,\
    \ AM::Mop, typename AM::T, AM::Tid, AM::Top, AM::act>;\n  ultraLazySegmentTree(vector<typename\
    \ AM::M> init) : base(init) {}\n  ultraLazySegmentTree(int size) : base(size)\
    \ {}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/ultraLazySegmentTree.cpp
  requiredBy: []
  timestamp: '2024-02-09 21:58:48+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/range_affine_range_sum.test.cpp
  - test/area_of_union_of_rectangles.test.cpp
documentation_of: segtree/ultraLazySegmentTree.cpp
layout: document
redirect_from:
- /library/segtree/ultraLazySegmentTree.cpp
- /library/segtree/ultraLazySegmentTree.cpp.html
title: segtree/ultraLazySegmentTree.cpp
---