---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cartesian_tree.test.cpp
    title: test/cartesian_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/cartesian_tree.cpp\"\ntemplate<class T>\nvi cartesian_tree(vc<T>\
    \ a) {\n  vi p(size(a)), s;\n  for(int i = 0; i < ssize(a); i++) {\n    int last_pop\
    \ = -1;\n    while(!s.empty() and a[s.back()] > a[i]) {\n      int j = s.back();\
    \ s.pop_back();\n      if (last_pop != -1)\n        p[last_pop] = j;\n      last_pop\
    \ = j;\n    }\n    if (last_pop != -1)\n      p[last_pop] = i;\n    s.emplace_back(i);\n\
    \  }\n\n  p[s[0]] = s[0];\n  for(int i = 1; i < ssize(s); i++)\n    p[s[i]] =\
    \ s[i - 1];\n\n  return p;\n}\n"
  code: "template<class T>\nvi cartesian_tree(vc<T> a) {\n  vi p(size(a)), s;\n  for(int\
    \ i = 0; i < ssize(a); i++) {\n    int last_pop = -1;\n    while(!s.empty() and\
    \ a[s.back()] > a[i]) {\n      int j = s.back(); s.pop_back();\n      if (last_pop\
    \ != -1)\n        p[last_pop] = j;\n      last_pop = j;\n    }\n    if (last_pop\
    \ != -1)\n      p[last_pop] = i;\n    s.emplace_back(i);\n  }\n\n  p[s[0]] = s[0];\n\
    \  for(int i = 1; i < ssize(s); i++)\n    p[s[i]] = s[i - 1];\n\n  return p;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/cartesian_tree.cpp
  requiredBy: []
  timestamp: '2026-02-01 21:51:25+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cartesian_tree.test.cpp
documentation_of: tree/cartesian_tree.cpp
layout: document
redirect_from:
- /library/tree/cartesian_tree.cpp
- /library/tree/cartesian_tree.cpp.html
title: tree/cartesian_tree.cpp
---
