---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yuki_2654.test.cpp
    title: test/yuki_2654.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/dynamicMedian.cpp\"\ntemplate<class T1, class T2>\nstruct\
    \ dynamic_median {\n  multiset<T1> D, U;\n  T2 Dsum = 0, Usum = 0;\n  void balance()\
    \ {\n    if (ssize(U) > ssize(D) + 1) {\n      auto ite = U.begin();\n      Usum\
    \ -= *ite, Dsum += *ite;\n      D.insert(*ite), U.erase(ite);\n    }\n    if (ssize(D)\
    \ > ssize(U)) {\n      auto ite = prev(D.end());\n      Dsum -= *ite, Usum +=\
    \ *ite;\n      U.insert(*ite), D.erase(ite);\n    }\n  }\n  void insert(T1 x)\
    \ {\n    if (U.empty() or x >= *U.begin())\n      U.insert(x), Usum += x;\n  \
    \  else\n      D.insert(x), Dsum += x;\n    balance();\n  }\n  void erase(T1 x)\
    \ {\n    if (auto ite = U.find(x); ite != U.end())\n      U.erase(ite), Usum -=\
    \ x;\n    else if (auto ite2 = D.find(x); ite2 != D.end())\n      D.erase(ite2),\
    \ Dsum -= x;\n    balance();\n  }\n  T1 median() { return *U.begin(); }\n  T1\
    \ min() { return D.empty() ? *U.begin() : *D.begin(); }\n  T1 max() { return *U.rbegin();\
    \ }\n  uint64_t size() { return ssize(D) + ssize(U); }\n};\n"
  code: "template<class T1, class T2>\nstruct dynamic_median {\n  multiset<T1> D,\
    \ U;\n  T2 Dsum = 0, Usum = 0;\n  void balance() {\n    if (ssize(U) > ssize(D)\
    \ + 1) {\n      auto ite = U.begin();\n      Usum -= *ite, Dsum += *ite;\n   \
    \   D.insert(*ite), U.erase(ite);\n    }\n    if (ssize(D) > ssize(U)) {\n   \
    \   auto ite = prev(D.end());\n      Dsum -= *ite, Usum += *ite;\n      U.insert(*ite),\
    \ D.erase(ite);\n    }\n  }\n  void insert(T1 x) {\n    if (U.empty() or x >=\
    \ *U.begin())\n      U.insert(x), Usum += x;\n    else\n      D.insert(x), Dsum\
    \ += x;\n    balance();\n  }\n  void erase(T1 x) {\n    if (auto ite = U.find(x);\
    \ ite != U.end())\n      U.erase(ite), Usum -= x;\n    else if (auto ite2 = D.find(x);\
    \ ite2 != D.end())\n      D.erase(ite2), Dsum -= x;\n    balance();\n  }\n  T1\
    \ median() { return *U.begin(); }\n  T1 min() { return D.empty() ? *U.begin()\
    \ : *D.begin(); }\n  T1 max() { return *U.rbegin(); }\n  uint64_t size() { return\
    \ ssize(D) + ssize(U); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/dynamicMedian.cpp
  requiredBy: []
  timestamp: '2025-09-06 14:29:06+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yuki_2654.test.cpp
documentation_of: ds/dynamicMedian.cpp
layout: document
redirect_from:
- /library/ds/dynamicMedian.cpp
- /library/ds/dynamicMedian.cpp.html
title: ds/dynamicMedian.cpp
---
