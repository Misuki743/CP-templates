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
  bundledCode: "#line 1 \"poly/FFT.cpp\"\nconst double PI = acos(-1);\nvector<complex<double>\
    \ > w(2, 1), w_inv(2, 1);\n\nvoid FFT(vector<complex<double> > &a, bool inverse)\
    \ {\n  int n = a.size();\n\n  if (w.size() < n) {\n    int lgSz = __lg((int)w.size());\n\
    \    int lgN = __lg(n);\n    w.resize(n);\n    w_inv.resize(n);\n    for(int i\
    \ = lgSz; i < lgN; i++) {\n      complex<double> w_k = exp(complex<double>(0,\
    \ PI / (double)(1 << i)));\n      complex<double> w_k_inv = exp(complex<double>(0,\
    \ -PI / (double)(1 << i)));\n      for(int j = 1 << i; j < (1 << (i + 1)); j++)\
    \ {\n        w[j] = (j & 1) ? w[j >> 1] * w_k : w[j >> 1]; \n        w_inv[j]\
    \ = (j & 1) ? w_inv[j >> 1] * w_k_inv : w_inv[j >> 1];\n      }\n    }\n  }\n\n\
    \  vector<complex<double> > tmp = a;\n  for(int i = 0; i < a.size(); i++) {\n\
    \    int idx = 0;\n    int lgn = __lg(n);\n    for(int j = lgn - 1; j >= 0; j--)\
    \ {\n      idx = (idx << 1) | ((i >> (lgn - j - 1)) & 1);\n    }\n    a[idx] =\
    \ tmp[i];\n  }\n\n  for(int l = 2; l <= n; l <<= 1) {\n    for(int i = 0; i <\
    \ n; i += l) {\n      for(int j = 0; j < (l >> 1); j += 1) {\n        complex<double>\
    \ w_j = (inverse ? w_inv[(l >> 1) + j] : w[(l >> 1) + j]);\n        complex<double>\
    \ t = a[i + j + l / 2] * w_j;\n        a[i + j + l / 2] = a[i + j] - t;\n    \
    \    a[i + j] = a[i + j] + t;\n      }\n    } \n  } \n\n  if (inverse) {\n   \
    \ for(int i = 0; i < n; i++)\n      a[i] = a[i] / (double)n;\n  }\n}\n\nvector<int>\
    \ multiply(vector<int> a, vector<int> b) {\n  int mxSz = (int)a.size() + (int)b.size()\
    \ - 1;\n  int n = (mxSz == 1) ? 2 : (1 << (__lg(mxSz - 1) + 1));\n\n  vector<complex<double>\
    \ > c(n), d(n);\n  for(int i = 0; i < n; i++)\n    c[i] = d[i] = 0;\n  for(int\
    \ i = 0; i < a.size(); i++)\n    c[i] = a[i];\n  for(int i = 0; i < b.size();\
    \ i++)\n    d[i] = b[i];\n\n  FFT(c, false);\n  FFT(d, false);\n\n  for(int i\
    \ = 0; i < n; i++)\n    c[i] = c[i] * d[i];\n\n  FFT(c, true);\n\n  vector<int>\
    \ res(mxSz);\n  for(int i = 0; i < mxSz; i++)\n    res[i] = round(c[i].real());\n\
    \n  return res;\n}\n"
  code: "const double PI = acos(-1);\nvector<complex<double> > w(2, 1), w_inv(2, 1);\n\
    \nvoid FFT(vector<complex<double> > &a, bool inverse) {\n  int n = a.size();\n\
    \n  if (w.size() < n) {\n    int lgSz = __lg((int)w.size());\n    int lgN = __lg(n);\n\
    \    w.resize(n);\n    w_inv.resize(n);\n    for(int i = lgSz; i < lgN; i++) {\n\
    \      complex<double> w_k = exp(complex<double>(0, PI / (double)(1 << i)));\n\
    \      complex<double> w_k_inv = exp(complex<double>(0, -PI / (double)(1 << i)));\n\
    \      for(int j = 1 << i; j < (1 << (i + 1)); j++) {\n        w[j] = (j & 1)\
    \ ? w[j >> 1] * w_k : w[j >> 1]; \n        w_inv[j] = (j & 1) ? w_inv[j >> 1]\
    \ * w_k_inv : w_inv[j >> 1];\n      }\n    }\n  }\n\n  vector<complex<double>\
    \ > tmp = a;\n  for(int i = 0; i < a.size(); i++) {\n    int idx = 0;\n    int\
    \ lgn = __lg(n);\n    for(int j = lgn - 1; j >= 0; j--) {\n      idx = (idx <<\
    \ 1) | ((i >> (lgn - j - 1)) & 1);\n    }\n    a[idx] = tmp[i];\n  }\n\n  for(int\
    \ l = 2; l <= n; l <<= 1) {\n    for(int i = 0; i < n; i += l) {\n      for(int\
    \ j = 0; j < (l >> 1); j += 1) {\n        complex<double> w_j = (inverse ? w_inv[(l\
    \ >> 1) + j] : w[(l >> 1) + j]);\n        complex<double> t = a[i + j + l / 2]\
    \ * w_j;\n        a[i + j + l / 2] = a[i + j] - t;\n        a[i + j] = a[i + j]\
    \ + t;\n      }\n    } \n  } \n\n  if (inverse) {\n    for(int i = 0; i < n; i++)\n\
    \      a[i] = a[i] / (double)n;\n  }\n}\n\nvector<int> multiply(vector<int> a,\
    \ vector<int> b) {\n  int mxSz = (int)a.size() + (int)b.size() - 1;\n  int n =\
    \ (mxSz == 1) ? 2 : (1 << (__lg(mxSz - 1) + 1));\n\n  vector<complex<double> >\
    \ c(n), d(n);\n  for(int i = 0; i < n; i++)\n    c[i] = d[i] = 0;\n  for(int i\
    \ = 0; i < a.size(); i++)\n    c[i] = a[i];\n  for(int i = 0; i < b.size(); i++)\n\
    \    d[i] = b[i];\n\n  FFT(c, false);\n  FFT(d, false);\n\n  for(int i = 0; i\
    \ < n; i++)\n    c[i] = c[i] * d[i];\n\n  FFT(c, true);\n\n  vector<int> res(mxSz);\n\
    \  for(int i = 0; i < mxSz; i++)\n    res[i] = round(c[i].real());\n\n  return\
    \ res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/FFT.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/FFT.cpp
layout: document
redirect_from:
- /library/poly/FFT.cpp
- /library/poly/FFT.cpp.html
title: poly/FFT.cpp
---
