---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/slope_trick.cpp\"\ntemplate<class T>\nstruct slope_trick\
    \ {\n  max_heap<T> L;\n  min_heap<T> R;\n  T mn, tag;\n\n  //(x - a)+\n  void\
    \ add_x_minus_a(T a) {\n    if (!L.empty())\n      mn += max((L.top() + tag) -\
    \ a, T(0));\n    L.push(a - tag);\n    R.push(L.top());\n    L.pop();\n  }\n\n\
    \  //(a - x)+\n  void add_a_minus_x(T a) {\n    if (!R.empty())\n      mn += max(a\
    \ - (R.top() + tag), T(0));\n    R.push(a - tag);\n    L.push(R.top());\n    R.pop();\n\
    \  }\n\n  void add_abs(T a) {\n    add_x_minus_a(a), add_a_minus_x(a);\n  }\n\n\
    \  void prefix_min() {\n    min_heap<T> x;\n    R.swap(x);\n  }\n\n  void suffix_min()\
    \ {\n    max_heap<T> x;\n    L.swap(x);\n  }\n\n  void shift(T d) { tag += d;\
    \ }\n\n  T eval(T x) {\n    T y = mn;\n    {\n      max_heap<T> tmp = L;\n   \
    \   while(!tmp.empty()) {\n        y += max((tmp.top() + tag) - x, T(0));\n  \
    \      tmp.pop();\n      }\n    }\n    {\n      min_heap<T> tmp = R;\n      while(!tmp.empty())\
    \ {\n        y += max(x - (tmp.top() + tag), T(0));\n        tmp.pop();\n    \
    \  }\n    }\n    return y;\n  }\n\n  T query_min() { return mn; }\n\n  array<T,\
    \ 2> argmin() {\n    return {L.empty() ? numeric_limits<T>::min() : L.top() +\
    \ tag,\n            R.empty() ? numeric_limits<T>::max() : R.top() + tag};\n \
    \ }\n};\n"
  code: "template<class T>\nstruct slope_trick {\n  max_heap<T> L;\n  min_heap<T>\
    \ R;\n  T mn, tag;\n\n  //(x - a)+\n  void add_x_minus_a(T a) {\n    if (!L.empty())\n\
    \      mn += max((L.top() + tag) - a, T(0));\n    L.push(a - tag);\n    R.push(L.top());\n\
    \    L.pop();\n  }\n\n  //(a - x)+\n  void add_a_minus_x(T a) {\n    if (!R.empty())\n\
    \      mn += max(a - (R.top() + tag), T(0));\n    R.push(a - tag);\n    L.push(R.top());\n\
    \    R.pop();\n  }\n\n  void add_abs(T a) {\n    add_x_minus_a(a), add_a_minus_x(a);\n\
    \  }\n\n  void prefix_min() {\n    min_heap<T> x;\n    R.swap(x);\n  }\n\n  void\
    \ suffix_min() {\n    max_heap<T> x;\n    L.swap(x);\n  }\n\n  void shift(T d)\
    \ { tag += d; }\n\n  T eval(T x) {\n    T y = mn;\n    {\n      max_heap<T> tmp\
    \ = L;\n      while(!tmp.empty()) {\n        y += max((tmp.top() + tag) - x, T(0));\n\
    \        tmp.pop();\n      }\n    }\n    {\n      min_heap<T> tmp = R;\n     \
    \ while(!tmp.empty()) {\n        y += max(x - (tmp.top() + tag), T(0));\n    \
    \    tmp.pop();\n      }\n    }\n    return y;\n  }\n\n  T query_min() { return\
    \ mn; }\n\n  array<T, 2> argmin() {\n    return {L.empty() ? numeric_limits<T>::min()\
    \ : L.top() + tag,\n            R.empty() ? numeric_limits<T>::max() : R.top()\
    \ + tag};\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/slope_trick.cpp
  requiredBy: []
  timestamp: '2024-08-30 17:59:56+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/slope_trick.cpp
layout: document
redirect_from:
- /library/ds/slope_trick.cpp
- /library/ds/slope_trick.cpp.html
title: ds/slope_trick.cpp
---
