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
  bundledCode: "#line 1 \"setfunc/fastZetaTransform.cpp\"\n//note: to change to poset,\
    \ flip the condition inside if statement. \n\ntemplate<class T>\nvoid fastZetaTransform(vector<T>\
    \ &vec, bool inverse = false) {\n  for(int i = 0; (1 << i) < (int)vec.size();\
    \ i++)\n    for(int j = 0; j < (int)vec.size(); j++)\n      if (j >> i & 1)\n\
    \        vec[j] += (inverse ? -vec[j ^ (1 << i)] : vec[j ^ (1 << i)]);\n}\n"
  code: "//note: to change to poset, flip the condition inside if statement. \n\n\
    template<class T>\nvoid fastZetaTransform(vector<T> &vec, bool inverse = false)\
    \ {\n  for(int i = 0; (1 << i) < (int)vec.size(); i++)\n    for(int j = 0; j <\
    \ (int)vec.size(); j++)\n      if (j >> i & 1)\n        vec[j] += (inverse ? -vec[j\
    \ ^ (1 << i)] : vec[j ^ (1 << i)]);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/fastZetaTransform.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: setfunc/fastZetaTransform.cpp
layout: document
redirect_from:
- /library/setfunc/fastZetaTransform.cpp
- /library/setfunc/fastZetaTransform.cpp.html
title: setfunc/fastZetaTransform.cpp
---
