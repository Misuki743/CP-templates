---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/min_plus_convolution_convex_arbitrary.test.cpp
    title: test/min_plus_convolution_convex_arbitrary.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/min_plus_convolution.cpp\"\ntemplate<class T>\nvector<T>\
    \ min_plus_convolution(vector<T> convex, vector<T> b) {\n  vector<T> c(ssize(convex)\
    \ + ssize(b) - 1, numeric_limits<T>::max());\n  auto dc = [&](int l, int r, int\
    \ ql, int qr, auto &&self) -> void {\n    int mid = (l + r) / 2;\n    int best\
    \ = -1;\n    for(int j = max(ql, mid - (int)size(convex) + 1); j <= min(qr, mid);\
    \ j++)\n      if (chmin(c[mid], convex[mid - j] + b[j]))\n        best = j;\n\
    \    if (l + 1 != r) {\n      self(l, mid, ql, best, self);\n      self(mid, r,\
    \ best, qr, self);\n    }\n  };\n  dc(0, ssize(c), 0, ssize(b) - 1, dc);\n  return\
    \ c;\n}\n"
  code: "template<class T>\nvector<T> min_plus_convolution(vector<T> convex, vector<T>\
    \ b) {\n  vector<T> c(ssize(convex) + ssize(b) - 1, numeric_limits<T>::max());\n\
    \  auto dc = [&](int l, int r, int ql, int qr, auto &&self) -> void {\n    int\
    \ mid = (l + r) / 2;\n    int best = -1;\n    for(int j = max(ql, mid - (int)size(convex)\
    \ + 1); j <= min(qr, mid); j++)\n      if (chmin(c[mid], convex[mid - j] + b[j]))\n\
    \        best = j;\n    if (l + 1 != r) {\n      self(l, mid, ql, best, self);\n\
    \      self(mid, r, best, qr, self);\n    }\n  };\n  dc(0, ssize(c), 0, ssize(b)\
    \ - 1, dc);\n  return c;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/min_plus_convolution.cpp
  requiredBy: []
  timestamp: '2024-09-29 01:28:13+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/min_plus_convolution_convex_arbitrary.test.cpp
documentation_of: poly/min_plus_convolution.cpp
layout: document
redirect_from:
- /library/poly/min_plus_convolution.cpp
- /library/poly/min_plus_convolution.cpp.html
title: poly/min_plus_convolution.cpp
---
