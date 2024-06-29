---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki_2654.test.cpp
    title: test/yuki_2654.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/dynamicMedian.cpp\"\ntemplate<class T1, class T2>\nstruct\
    \ dynamicMedian {\n  multiset<T1> left, right;\n  T2 lsum = 0, rsum = 0;\n  void\
    \ insert(T1 x) {\n    left.insert(x);\n    lsum += x;\n    if (!right.empty()\
    \ and (*left.rbegin()) > (*right.begin())) {\n      T1 tmpl = *left.rbegin();\
    \ \n      left.erase(prev(left.end()));\n      T1 tmpr = *right.begin();\n   \
    \   right.erase(right.begin());\n      left.insert(tmpr);\n      right.insert(tmpl);\n\
    \      lsum += tmpr - tmpl, rsum += tmpl - tmpr;\n    }\n    if (ssize(left) >\
    \ ssize(right) + 1) {\n      T1 tmp = *left.rbegin();\n      left.erase(prev(left.end()));\n\
    \      right.insert(tmp);\n      lsum -= tmp, rsum += tmp;\n    }\n  }\n  void\
    \ erase(T1 x) {\n    if (left.contains(x)) {\n      left.erase(left.find(x));\n\
    \      lsum -= x;\n      if (ssize(left) < ssize(right)) {\n        T1 tmp = *right.begin();\n\
    \        right.erase(right.begin());\n        left.insert(tmp);\n        lsum\
    \ += tmp, rsum -= tmp;\n      }\n    } else if (right.contains(x)) {\n      right.erase(right.find(x));\n\
    \      rsum -= x;\n      if (ssize(left) == ssize(right) + 2) {\n        T1 tmp\
    \ = *left.rbegin();\n        left.erase(prev(left.end()));\n        right.insert(tmp);\n\
    \        lsum -= tmp, rsum += tmp;\n      }\n    }\n  }\n  T1 median() { return\
    \ *left.rbegin(); }\n  T1 min() { return *left.begin(); }\n  T1 max() { return\
    \ right.empty() ? *left.rbegin() : *right.rbegin(); }\n  int size() { return ssize(left)\
    \ + ssize(right); }\n};\n"
  code: "template<class T1, class T2>\nstruct dynamicMedian {\n  multiset<T1> left,\
    \ right;\n  T2 lsum = 0, rsum = 0;\n  void insert(T1 x) {\n    left.insert(x);\n\
    \    lsum += x;\n    if (!right.empty() and (*left.rbegin()) > (*right.begin()))\
    \ {\n      T1 tmpl = *left.rbegin(); \n      left.erase(prev(left.end()));\n \
    \     T1 tmpr = *right.begin();\n      right.erase(right.begin());\n      left.insert(tmpr);\n\
    \      right.insert(tmpl);\n      lsum += tmpr - tmpl, rsum += tmpl - tmpr;\n\
    \    }\n    if (ssize(left) > ssize(right) + 1) {\n      T1 tmp = *left.rbegin();\n\
    \      left.erase(prev(left.end()));\n      right.insert(tmp);\n      lsum -=\
    \ tmp, rsum += tmp;\n    }\n  }\n  void erase(T1 x) {\n    if (left.contains(x))\
    \ {\n      left.erase(left.find(x));\n      lsum -= x;\n      if (ssize(left)\
    \ < ssize(right)) {\n        T1 tmp = *right.begin();\n        right.erase(right.begin());\n\
    \        left.insert(tmp);\n        lsum += tmp, rsum -= tmp;\n      }\n    }\
    \ else if (right.contains(x)) {\n      right.erase(right.find(x));\n      rsum\
    \ -= x;\n      if (ssize(left) == ssize(right) + 2) {\n        T1 tmp = *left.rbegin();\n\
    \        left.erase(prev(left.end()));\n        right.insert(tmp);\n        lsum\
    \ -= tmp, rsum += tmp;\n      }\n    }\n  }\n  T1 median() { return *left.rbegin();\
    \ }\n  T1 min() { return *left.begin(); }\n  T1 max() { return right.empty() ?\
    \ *left.rbegin() : *right.rbegin(); }\n  int size() { return ssize(left) + ssize(right);\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/dynamicMedian.cpp
  requiredBy: []
  timestamp: '2024-02-25 01:28:51+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki_2654.test.cpp
documentation_of: ds/dynamicMedian.cpp
layout: document
redirect_from:
- /library/ds/dynamicMedian.cpp
- /library/ds/dynamicMedian.cpp.html
title: ds/dynamicMedian.cpp
---
