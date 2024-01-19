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
  bundledCode: "#line 1 \"poly/FFTmod.cpp\"\n/**\n * template name: FFTmod\n * author:\
    \ Misuki\n * last update: 2022/04/07\n * include template: FFT\n */\n\nconst long\
    \ long MOD = 1e9 + 7;\nconst long long SQRT = sqrt(MOD);\nvoid sqrtDivide(vector<long\
    \ long> &a, vector<long long> &b) {\n  vector<long long> tmp = a;\n  a.clear();\n\
    \  b.clear();\n  a.resize(tmp.size());\n  b.resize(tmp.size());\n  for(int i =\
    \ 0; i < tmp.size(); i++) {\n    a[i] = tmp[i] % SQRT;\n    b[i] = tmp[i] / SQRT;\n\
    \  }\n}\n\nvector<long long> multiplyMOD(vector<long long> a1, vector<long long>\
    \ b1) {\n  int mxSz = (int)a1.size() + (int)b1.size() - 1;\n  int n = (mxSz ==\
    \ 1) ? 2 : (1 << (__lg(mxSz - 1) + 1));\n\n  vector<long long> a2, b2;\n  sqrtDivide(a1,\
    \ a2);\n  sqrtDivide(b1, b2);\n\n  vector<complex<double> > c1(n), c2(n), d1(n),\
    \ d2(n);\n  for(int i = 0; i < n; i++)\n    c1[i] = c2[i] = d1[i] = d2[i] = 0;\n\
    \  for(int i = 0; i < a1.size(); i++)\n    c1[i] = a1[i], c2[i] = a2[i];\n  for(int\
    \ i = 0; i < b1.size(); i++)\n    d1[i] = b1[i], d2[i] = b2[i];\n\n  FFT(c1, false);\n\
    \  FFT(c2, false);\n  FFT(d1, false);\n  FFT(d2, false);\n\n  vector<complex<double>\
    \ > c1d1(n), c1d2(n), c2d1(n), c2d2(n);\n  for(int i = 0; i < n; i++) {\n    c1d1[i]\
    \ = c1[i] * d1[i];\n    c1d2[i] = c1[i] * d2[i];\n    c2d1[i] = c2[i] * d1[i];\n\
    \    c2d2[i] = c2[i] * d2[i];\n  }\n\n  FFT(c1d1, true);\n  FFT(c1d2, true);\n\
    \  FFT(c2d1, true);\n  FFT(c2d2, true);\n\n  vector<long long> res(mxSz);\n  for(int\
    \ i = 0; i < mxSz; i++) {\n    long long c1d1Val = (long long)round(c1d1[i].real());\n\
    \    long long c1d2Val = (long long)round(c1d2[i].real());\n    long long c2d1Val\
    \ = (long long)round(c2d1[i].real());\n    long long c2d2Val = (long long)round(c2d2[i].real());\n\
    \    c1d1Val %= MOD;\n    c1d2Val %= MOD;\n    c2d1Val %= MOD;\n    c2d2Val %=\
    \ MOD;\n\n    res[i] = ((((((c2d2Val * SQRT) % MOD) + (c1d2Val + c2d1Val)) * SQRT)\
    \ % MOD) + c1d1Val) % MOD;\n  }\n\n  return res;\n}\n"
  code: "/**\n * template name: FFTmod\n * author: Misuki\n * last update: 2022/04/07\n\
    \ * include template: FFT\n */\n\nconst long long MOD = 1e9 + 7;\nconst long long\
    \ SQRT = sqrt(MOD);\nvoid sqrtDivide(vector<long long> &a, vector<long long> &b)\
    \ {\n  vector<long long> tmp = a;\n  a.clear();\n  b.clear();\n  a.resize(tmp.size());\n\
    \  b.resize(tmp.size());\n  for(int i = 0; i < tmp.size(); i++) {\n    a[i] =\
    \ tmp[i] % SQRT;\n    b[i] = tmp[i] / SQRT;\n  }\n}\n\nvector<long long> multiplyMOD(vector<long\
    \ long> a1, vector<long long> b1) {\n  int mxSz = (int)a1.size() + (int)b1.size()\
    \ - 1;\n  int n = (mxSz == 1) ? 2 : (1 << (__lg(mxSz - 1) + 1));\n\n  vector<long\
    \ long> a2, b2;\n  sqrtDivide(a1, a2);\n  sqrtDivide(b1, b2);\n\n  vector<complex<double>\
    \ > c1(n), c2(n), d1(n), d2(n);\n  for(int i = 0; i < n; i++)\n    c1[i] = c2[i]\
    \ = d1[i] = d2[i] = 0;\n  for(int i = 0; i < a1.size(); i++)\n    c1[i] = a1[i],\
    \ c2[i] = a2[i];\n  for(int i = 0; i < b1.size(); i++)\n    d1[i] = b1[i], d2[i]\
    \ = b2[i];\n\n  FFT(c1, false);\n  FFT(c2, false);\n  FFT(d1, false);\n  FFT(d2,\
    \ false);\n\n  vector<complex<double> > c1d1(n), c1d2(n), c2d1(n), c2d2(n);\n\
    \  for(int i = 0; i < n; i++) {\n    c1d1[i] = c1[i] * d1[i];\n    c1d2[i] = c1[i]\
    \ * d2[i];\n    c2d1[i] = c2[i] * d1[i];\n    c2d2[i] = c2[i] * d2[i];\n  }\n\n\
    \  FFT(c1d1, true);\n  FFT(c1d2, true);\n  FFT(c2d1, true);\n  FFT(c2d2, true);\n\
    \n  vector<long long> res(mxSz);\n  for(int i = 0; i < mxSz; i++) {\n    long\
    \ long c1d1Val = (long long)round(c1d1[i].real());\n    long long c1d2Val = (long\
    \ long)round(c1d2[i].real());\n    long long c2d1Val = (long long)round(c2d1[i].real());\n\
    \    long long c2d2Val = (long long)round(c2d2[i].real());\n    c1d1Val %= MOD;\n\
    \    c1d2Val %= MOD;\n    c2d1Val %= MOD;\n    c2d2Val %= MOD;\n\n    res[i] =\
    \ ((((((c2d2Val * SQRT) % MOD) + (c1d2Val + c2d1Val)) * SQRT) % MOD) + c1d1Val)\
    \ % MOD;\n  }\n\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/FFTmod.cpp
  requiredBy: []
  timestamp: '2024-01-20 02:52:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/FFTmod.cpp
layout: document
redirect_from:
- /library/poly/FFTmod.cpp
- /library/poly/FFTmod.cpp.html
title: poly/FFTmod.cpp
---
