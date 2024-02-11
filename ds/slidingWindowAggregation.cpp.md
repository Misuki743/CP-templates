---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/queue_operate_all_composite.test.cpp
    title: test/queue_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/slidingWindowAggregation.cpp\"\ntemplate<class M, M(*id)(),\
    \ M(*op)(const M&, const M&)>\nstruct SWAG {\n  vector<M> left, right;\n  M rightComp;\n\
    \n  SWAG() : left(1, id()), rightComp(id()) {}\n  void push(M x) {\n    right.emplace_back(x);\n\
    \    rightComp = op(rightComp, x);\n  }\n  void pop() {\n    if (ssize(left) ==\
    \ 1) {\n      for(auto &x : right | V::reverse)\n        left.emplace_back(op(x,\
    \ left.back()));\n      vector<M> tmp;\n      right.swap(tmp);\n      rightComp\
    \ = id();\n    }\n    left.pop_back();\n  }\n  M query() { return op(left.back(),\
    \ rightComp); }\n};\n"
  code: "template<class M, M(*id)(), M(*op)(const M&, const M&)>\nstruct SWAG {\n\
    \  vector<M> left, right;\n  M rightComp;\n\n  SWAG() : left(1, id()), rightComp(id())\
    \ {}\n  void push(M x) {\n    right.emplace_back(x);\n    rightComp = op(rightComp,\
    \ x);\n  }\n  void pop() {\n    if (ssize(left) == 1) {\n      for(auto &x : right\
    \ | V::reverse)\n        left.emplace_back(op(x, left.back()));\n      vector<M>\
    \ tmp;\n      right.swap(tmp);\n      rightComp = id();\n    }\n    left.pop_back();\n\
    \  }\n  M query() { return op(left.back(), rightComp); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/slidingWindowAggregation.cpp
  requiredBy: []
  timestamp: '2024-02-10 22:33:36+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/queue_operate_all_composite.test.cpp
documentation_of: ds/slidingWindowAggregation.cpp
layout: document
redirect_from:
- /library/ds/slidingWindowAggregation.cpp
- /library/ds/slidingWindowAggregation.cpp.html
title: ds/slidingWindowAggregation.cpp
---
