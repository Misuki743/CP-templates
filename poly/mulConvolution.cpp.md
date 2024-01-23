---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki_2613.test.cpp
    title: test/yuki_2613.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/mulConvolution.cpp\"\n//#include \"../numtheory/primitiveRoot.cpp\"\
    \n//#include \"../numtheory/fastFactorize.cpp\"\n//#include \"../poly/NTTmint.cpp\"\
    \n//#include \"../modint/MontgomeryModInt.cpp\"\n\nstruct mulConvolution {\n \
    \ const int P, root;\n  vector<int> powR, logR;\n\n  mulConvolution(int _P) :\
    \ P(_P), root(primitiveRoot(_P)), powR(P - 1), logR(P, -1) {\n    for(int i =\
    \ 0, tmp = 1; i < P - 1; i++, tmp = (ll)tmp * root % P)\n      powR[i] = tmp,\
    \ logR[tmp] = i;\n  }\n\n  template<class Mint>\n  vector<Mint> transform(vector<Mint>\
    \ &f) {\n    assert(ssize(f) == P);\n    vector<Mint> g(P - 1);\n    for(int i\
    \ = 1; i < P; i++)\n      g[logR[i]] = f[i];\n    return g;\n  }\n\n  template<class\
    \ Mint>\n  vector<Mint> invTransform(vector<Mint> &f) {\n    assert(ssize(f) ==\
    \ P - 1);\n    vector<Mint> g(P);\n    for(int i = 0; i < P - 1; i++)\n      g[powR[i]]\
    \ = f[i];\n    return g;\n  }\n\n  template<class Mint>\n  vector<Mint> mulConv(vector<Mint>\
    \ a, vector<Mint> b, vector<Mint>(*conv)(vector<Mint>, vector<Mint>)) {\n    a\
    \ = transform(a), b = transform(b);\n    a = conv(a, b);\n    for(int i = P -\
    \ 1; i < 2 * P - 3; i++)\n      a[i - (P - 1)] += a[i];\n    a.resize(P - 1);\n\
    \    a = invTransform(a);\n    return a;\n  }\n};\n"
  code: "//#include \"../numtheory/primitiveRoot.cpp\"\n//#include \"../numtheory/fastFactorize.cpp\"\
    \n//#include \"../poly/NTTmint.cpp\"\n//#include \"../modint/MontgomeryModInt.cpp\"\
    \n\nstruct mulConvolution {\n  const int P, root;\n  vector<int> powR, logR;\n\
    \n  mulConvolution(int _P) : P(_P), root(primitiveRoot(_P)), powR(P - 1), logR(P,\
    \ -1) {\n    for(int i = 0, tmp = 1; i < P - 1; i++, tmp = (ll)tmp * root % P)\n\
    \      powR[i] = tmp, logR[tmp] = i;\n  }\n\n  template<class Mint>\n  vector<Mint>\
    \ transform(vector<Mint> &f) {\n    assert(ssize(f) == P);\n    vector<Mint> g(P\
    \ - 1);\n    for(int i = 1; i < P; i++)\n      g[logR[i]] = f[i];\n    return\
    \ g;\n  }\n\n  template<class Mint>\n  vector<Mint> invTransform(vector<Mint>\
    \ &f) {\n    assert(ssize(f) == P - 1);\n    vector<Mint> g(P);\n    for(int i\
    \ = 0; i < P - 1; i++)\n      g[powR[i]] = f[i];\n    return g;\n  }\n\n  template<class\
    \ Mint>\n  vector<Mint> mulConv(vector<Mint> a, vector<Mint> b, vector<Mint>(*conv)(vector<Mint>,\
    \ vector<Mint>)) {\n    a = transform(a), b = transform(b);\n    a = conv(a, b);\n\
    \    for(int i = P - 1; i < 2 * P - 3; i++)\n      a[i - (P - 1)] += a[i];\n \
    \   a.resize(P - 1);\n    a = invTransform(a);\n    return a;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/mulConvolution.cpp
  requiredBy: []
  timestamp: '2024-01-23 16:55:41+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki_2613.test.cpp
documentation_of: poly/mulConvolution.cpp
layout: document
title: mulConvolution
---

## theory

Consider writing $i, j$ as power of some primitive root $r$ i.e. $(i = r^{i'}, j = r^{j'}, k = r^{k'})$, then $ij \equiv k \text{ mod } P\leftrightarrow r^{(i'+j')} \equiv r^{k'} \text{ mod } P \leftrightarrow i' + j' \equiv k' \text{ mod } (P - 1)$
reduce the problem to the normal convolution and can be solved by NTT.

## usage

Given prime $P$ and two polynomial $f(x), g(x)$, compute $h(x) = \sum\limits_{ij \equiv k \text{ mod } P} f_ig_j x^{k}$ in $O(P\lg P)$

- `transform(f)` map $f_i$ to $f_{i'}$ where $r^{i'} \equiv i \text{ mod } P$
- `invTransform(f)` map $f_{i'}$ back to $f_i$
- `mulConv(f, g, conv)` compute $h(x) = \sum\limits_{ij \equiv k \text{ mod } P} f_ig_j x^{k}$
