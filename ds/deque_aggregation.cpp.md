---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/deque_operate_all_composite.test.cpp
    title: test/deque_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/deque_aggregation.cpp\"\ntemplate<class M, M(*id)(),\
    \ M(*op)(const M&, const M&)>\nstruct deque_aggregation {\n  vector<M> L, R;\n\
    \  vector<M> L_prod, R_prod;\n\n  deque_aggregation() : L_prod(1, id()), R_prod(1,\
    \ id()) {}\n\n  void pushL(M m) {\n    L.emplace_back(m);\n    L_prod.emplace_back(op(m,\
    \ L_prod.back()));\n  }\n  void pushR(M m) {\n    R.emplace_back(m);\n    R_prod.emplace_back(op(R_prod.back(),\
    \ m));\n  }\n  void popL() { L.pop_back(), L_prod.pop_back(); }\n  void popR()\
    \ { R.pop_back(), R_prod.pop_back(); }\n\n  void balanceL() {\n    int cnt = (ssize(L)\
    \ + 1) / 2;\n    vector<M> tmp(L.begin() + cnt, L.end());\n    for(int i = ssize(L)\
    \ - 1; i >= cnt; i--)\n      popL();\n    for(int i = ssize(L) - 1; i >= 0; i--)\
    \ {\n      pushR(L.back());\n      popL();\n    }\n    for(auto &m : tmp)\n  \
    \    pushL(m);\n  }\n\n  void balanceR() {\n    int cnt = (ssize(R) + 1) / 2;\n\
    \    vector<M> tmp(R.begin() + cnt, R.end());\n    for(int i = ssize(R) - 1; i\
    \ >= cnt; i--)\n      popR();\n    for(int i = ssize(R) - 1; i >= 0; i--) {\n\
    \      pushL(R.back());\n      popR();\n    }\n    for(auto &m : tmp)\n      pushR(m);\n\
    \  }\n\n  void push_front(M m) { pushL(m); }\n  void push_back(M m) { pushR(m);\
    \ }\n  void pop_front() {\n    if (L.empty()) balanceR();\n    popL();\n  }\n\
    \  void pop_back() {\n    if (R.empty()) balanceL();\n    popR();\n  }\n  M query()\
    \ { return op(L_prod.back(), R_prod.back()); }\n};\n"
  code: "template<class M, M(*id)(), M(*op)(const M&, const M&)>\nstruct deque_aggregation\
    \ {\n  vector<M> L, R;\n  vector<M> L_prod, R_prod;\n\n  deque_aggregation() :\
    \ L_prod(1, id()), R_prod(1, id()) {}\n\n  void pushL(M m) {\n    L.emplace_back(m);\n\
    \    L_prod.emplace_back(op(m, L_prod.back()));\n  }\n  void pushR(M m) {\n  \
    \  R.emplace_back(m);\n    R_prod.emplace_back(op(R_prod.back(), m));\n  }\n \
    \ void popL() { L.pop_back(), L_prod.pop_back(); }\n  void popR() { R.pop_back(),\
    \ R_prod.pop_back(); }\n\n  void balanceL() {\n    int cnt = (ssize(L) + 1) /\
    \ 2;\n    vector<M> tmp(L.begin() + cnt, L.end());\n    for(int i = ssize(L) -\
    \ 1; i >= cnt; i--)\n      popL();\n    for(int i = ssize(L) - 1; i >= 0; i--)\
    \ {\n      pushR(L.back());\n      popL();\n    }\n    for(auto &m : tmp)\n  \
    \    pushL(m);\n  }\n\n  void balanceR() {\n    int cnt = (ssize(R) + 1) / 2;\n\
    \    vector<M> tmp(R.begin() + cnt, R.end());\n    for(int i = ssize(R) - 1; i\
    \ >= cnt; i--)\n      popR();\n    for(int i = ssize(R) - 1; i >= 0; i--) {\n\
    \      pushL(R.back());\n      popR();\n    }\n    for(auto &m : tmp)\n      pushR(m);\n\
    \  }\n\n  void push_front(M m) { pushL(m); }\n  void push_back(M m) { pushR(m);\
    \ }\n  void pop_front() {\n    if (L.empty()) balanceR();\n    popL();\n  }\n\
    \  void pop_back() {\n    if (R.empty()) balanceL();\n    popR();\n  }\n  M query()\
    \ { return op(L_prod.back(), R_prod.back()); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/deque_aggregation.cpp
  requiredBy: []
  timestamp: '2025-09-11 20:23:07+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/deque_operate_all_composite.test.cpp
documentation_of: ds/deque_aggregation.cpp
layout: document
redirect_from:
- /library/ds/deque_aggregation.cpp
- /library/ds/deque_aggregation.cpp.html
title: ds/deque_aggregation.cpp
---
