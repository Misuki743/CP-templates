---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mul_modp_convolution.test.cpp
    title: test/mul_modp_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki_2613.test.cpp
    title: test/yuki_2613.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/mulConvolution.cpp\"\n//#include \"poly/NTTmint.cpp\"\
    \n//#include \"modint/MontgomeryModInt.cpp\"\n\nstruct mulConvolution {\n  const\
    \ int P, root;\n  vector<int> powR, logR;\n\n  int primitiveRoot(int p) {\n  \
    \  vector<int> pf;\n    {\n      int tmp = p - 1;\n      for(int i = 2; i * i\
    \ <= (p - 1); i++) {\n        if (tmp % i != 0) continue;\n        pf.emplace_back(i);\n\
    \        while(tmp % i == 0) tmp /= i;\n      }\n      if (tmp != 1)\n       \
    \ pf.emplace_back(tmp);\n    }\n\n    auto modPow = [p](ll a, int x) -> int {\n\
    \      if (x == 0) return 1;\n      if (a == 0) return 0;\n      ll b = 1;\n \
    \     while(x) {\n        if (x & 1) b = b * a % p;\n        a = a * a % p, x\
    \ >>= 1;\n      }\n      return b;\n    };\n\n    for(int r = 1; ; r++) {\n  \
    \    bool isRoot = true;\n      for(int d : pf) {\n        if (modPow(r, (p -\
    \ 1) / d) == 1) {\n          isRoot = false;\n          break;\n        }\n  \
    \    }\n      if (isRoot)\n        return r;\n    }\n  }\n\n  mulConvolution(int\
    \ _P) : P(_P), root(primitiveRoot(_P)), powR(P - 1), logR(P, -1) {\n    for(int\
    \ i = 0, tmp = 1; i < P - 1; i++, tmp = (ll)tmp * root % P)\n      powR[i] = tmp,\
    \ logR[tmp] = i;\n  }\n\n  template<class Mint>\n  vector<Mint> transform(vector<Mint>\
    \ &f) {\n    assert(ssize(f) == P);\n    vector<Mint> g(P - 1);\n    for(int i\
    \ = 1; i < P; i++)\n      g[logR[i]] = f[i];\n    return g;\n  }\n\n  template<class\
    \ Mint>\n  vector<Mint> invTransform(vector<Mint> &f) {\n    assert(ssize(f) ==\
    \ P - 1);\n    vector<Mint> g(P);\n    for(int i = 0; i < P - 1; i++)\n      g[powR[i]]\
    \ = f[i];\n    return g;\n  }\n\n  template<class Mint>\n  vector<Mint> mulConv(vector<Mint>\
    \ a, vector<Mint> b, vector<Mint>(*conv)(vector<Mint>, vector<Mint>)) {\n    Mint\
    \ zero = accumulate(a.begin(), a.end(), Mint(0)) * b[0] + accumulate(b.begin()\
    \ + 1, b.end(), Mint(0)) * a[0];\n    a = transform(a), b = transform(b);\n  \
    \  a = conv(a, b);\n    for(int i = P - 1; i < 2 * P - 3; i++)\n      a[i - (P\
    \ - 1)] += a[i];\n    a.resize(P - 1);\n    a = invTransform(a);\n    a[0] = zero;\n\
    \    return a;\n  }\n};\n"
  code: "//#include \"poly/NTTmint.cpp\"\n//#include \"modint/MontgomeryModInt.cpp\"\
    \n\nstruct mulConvolution {\n  const int P, root;\n  vector<int> powR, logR;\n\
    \n  int primitiveRoot(int p) {\n    vector<int> pf;\n    {\n      int tmp = p\
    \ - 1;\n      for(int i = 2; i * i <= (p - 1); i++) {\n        if (tmp % i !=\
    \ 0) continue;\n        pf.emplace_back(i);\n        while(tmp % i == 0) tmp /=\
    \ i;\n      }\n      if (tmp != 1)\n        pf.emplace_back(tmp);\n    }\n\n \
    \   auto modPow = [p](ll a, int x) -> int {\n      if (x == 0) return 1;\n   \
    \   if (a == 0) return 0;\n      ll b = 1;\n      while(x) {\n        if (x &\
    \ 1) b = b * a % p;\n        a = a * a % p, x >>= 1;\n      }\n      return b;\n\
    \    };\n\n    for(int r = 1; ; r++) {\n      bool isRoot = true;\n      for(int\
    \ d : pf) {\n        if (modPow(r, (p - 1) / d) == 1) {\n          isRoot = false;\n\
    \          break;\n        }\n      }\n      if (isRoot)\n        return r;\n\
    \    }\n  }\n\n  mulConvolution(int _P) : P(_P), root(primitiveRoot(_P)), powR(P\
    \ - 1), logR(P, -1) {\n    for(int i = 0, tmp = 1; i < P - 1; i++, tmp = (ll)tmp\
    \ * root % P)\n      powR[i] = tmp, logR[tmp] = i;\n  }\n\n  template<class Mint>\n\
    \  vector<Mint> transform(vector<Mint> &f) {\n    assert(ssize(f) == P);\n   \
    \ vector<Mint> g(P - 1);\n    for(int i = 1; i < P; i++)\n      g[logR[i]] = f[i];\n\
    \    return g;\n  }\n\n  template<class Mint>\n  vector<Mint> invTransform(vector<Mint>\
    \ &f) {\n    assert(ssize(f) == P - 1);\n    vector<Mint> g(P);\n    for(int i\
    \ = 0; i < P - 1; i++)\n      g[powR[i]] = f[i];\n    return g;\n  }\n\n  template<class\
    \ Mint>\n  vector<Mint> mulConv(vector<Mint> a, vector<Mint> b, vector<Mint>(*conv)(vector<Mint>,\
    \ vector<Mint>)) {\n    Mint zero = accumulate(a.begin(), a.end(), Mint(0)) *\
    \ b[0] + accumulate(b.begin() + 1, b.end(), Mint(0)) * a[0];\n    a = transform(a),\
    \ b = transform(b);\n    a = conv(a, b);\n    for(int i = P - 1; i < 2 * P - 3;\
    \ i++)\n      a[i - (P - 1)] += a[i];\n    a.resize(P - 1);\n    a = invTransform(a);\n\
    \    a[0] = zero;\n    return a;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/mulConvolution.cpp
  requiredBy: []
  timestamp: '2024-02-06 18:26:29+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mul_modp_convolution.test.cpp
  - test/yuki_2613.test.cpp
documentation_of: poly/mulConvolution.cpp
layout: document
title: mulConvolution
---

## theory

Consider writing $i, j$ as power of some primitive root $r$ i.e. $(i = r^{i'}, j = r^{j'}, k = r^{k'})$, then $ij \equiv k \text{ mod } P\leftrightarrow r^{(i'+j')} \equiv r^{k'} \text{ mod } P \leftrightarrow i' + j' \equiv k' \text{ mod } (P - 1)$
reduce the problem to the normal convolution and can be solved by NTT.

## usage

Given prime $P$ and two polynomial $f(x), g(x)$, compute $h(x)\text{ s.t. } h_k = \sum\limits_{ij \equiv k \text{ mod } P} f_ig_j$ in $O(P\lg P)$

- `transform(f)` map $f_i$ to $f_{i'}$ where $r^{i'} \equiv i \text{ mod } P$
- `invTransform(f)` map $f_{i'}$ back to $f_i$
- `mulConv(f, g, conv)` compute $h(x)\text{ s.t. } h_k = \sum\limits_{ij \equiv k \text{ mod } P} f_ig_j$

