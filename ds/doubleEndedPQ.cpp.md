---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/double_ended_priority_queue.test.cpp
    title: test/double_ended_priority_queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/doubleEndedPQ.cpp\"\ntemplate<class T>\nstruct doubleEndedPQ\
    \ {\n  priority_queue<pair<T, int>> mx;\n  priority_queue<pair<T, int>, vector<pair<T,\
    \ int>>, greater<pair<T, int>>> mn;\n  vector<bool> inPQ;\n  int t = 0, _size\
    \ = 0;\n  void push(T x) {\n    mn.push(make_pair(x, t)), mx.push(make_pair(x,\
    \ t));\n    inPQ.emplace_back(true);\n    _size++, t++;\n  }\n  void clean() {\n\
    \    while(!mn.empty() and !inPQ[mn.top().second]) mn.pop();\n    while(!mx.empty()\
    \ and !inPQ[mx.top().second]) mx.pop();\n  }\n  T min() { return mn.top().first;\
    \ }\n  T max() { return mx.top().first; }\n  void popMin() {\n    inPQ[mn.top().second]\
    \ = false, _size--;\n    clean();\n  }\n  void popMax() {\n    inPQ[mx.top().second]\
    \ = false, _size--;\n    clean();\n  }\n  int size() { return _size; }\n  bool\
    \ empty() { return _size == 0; }\n};\n"
  code: "template<class T>\nstruct doubleEndedPQ {\n  priority_queue<pair<T, int>>\
    \ mx;\n  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>>\
    \ mn;\n  vector<bool> inPQ;\n  int t = 0, _size = 0;\n  void push(T x) {\n   \
    \ mn.push(make_pair(x, t)), mx.push(make_pair(x, t));\n    inPQ.emplace_back(true);\n\
    \    _size++, t++;\n  }\n  void clean() {\n    while(!mn.empty() and !inPQ[mn.top().second])\
    \ mn.pop();\n    while(!mx.empty() and !inPQ[mx.top().second]) mx.pop();\n  }\n\
    \  T min() { return mn.top().first; }\n  T max() { return mx.top().first; }\n\
    \  void popMin() {\n    inPQ[mn.top().second] = false, _size--;\n    clean();\n\
    \  }\n  void popMax() {\n    inPQ[mx.top().second] = false, _size--;\n    clean();\n\
    \  }\n  int size() { return _size; }\n  bool empty() { return _size == 0; }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/doubleEndedPQ.cpp
  requiredBy: []
  timestamp: '2024-03-19 02:05:55+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/double_ended_priority_queue.test.cpp
documentation_of: ds/doubleEndedPQ.cpp
layout: document
redirect_from:
- /library/ds/doubleEndedPQ.cpp
- /library/ds/doubleEndedPQ.cpp.html
title: ds/doubleEndedPQ.cpp
---
