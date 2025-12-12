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
  bundledCode: "#line 1 \"numtheory/dirichlet_convolution.cpp\"\ntemplate<class T>\n\
    vector<T> dirichlet_convolution(vector<T> a, vector<T> b) {\n  assert(size(a)\
    \ == size(b));\n  vector<T> c(size(a));\n  for(int i = 1; i < ssize(a); i++)\n\
    \    for(int j = 1; i * j < ssize(a); j++)\n      c[i * j] += a[i] * b[j];\n \
    \ return c;\n}\n"
  code: "template<class T>\nvector<T> dirichlet_convolution(vector<T> a, vector<T>\
    \ b) {\n  assert(size(a) == size(b));\n  vector<T> c(size(a));\n  for(int i =\
    \ 1; i < ssize(a); i++)\n    for(int j = 1; i * j < ssize(a); j++)\n      c[i\
    \ * j] += a[i] * b[j];\n  return c;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/dirichlet_convolution.cpp
  requiredBy: []
  timestamp: '2025-12-12 18:41:06+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numtheory/dirichlet_convolution.cpp
layout: document
redirect_from:
- /library/numtheory/dirichlet_convolution.cpp
- /library/numtheory/dirichlet_convolution.cpp.html
title: numtheory/dirichlet_convolution.cpp
---
