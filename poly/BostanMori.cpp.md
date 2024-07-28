---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/kth_term_of_linearly_recurrent_sequence.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/BostanMori.cpp\"\ntemplate<NTT Ntt, class Mint>\nmint\
    \ BostanMori(vector<Mint> P, vector<Mint> Q, ll k) {\n  assert(!P.empty() and\
    \ !Q.empty() and Q[0] != 0);\n  \n  int d = max(ssize(P), ssize(Q) - 1);\n  P.resize(d,\
    \ 0), Q.resize(d + 1, 0);\n\n  int size = 1 << (bit_width((unsigned)d) + 1);\n\
    \  while(k) {\n    vector<Mint> Qneg(size);\n    for(int i = 0; i < ssize(Q);\
    \ i++)\n      Qneg[i] = Q[i] * ((i & 1) ? -1 : 1);\n    Ntt.ntt(Qneg, false);\n\
    \n    vector<Mint> U(size), V(size);\n    copy(P.begin(), P.end(), U.begin());\n\
    \    copy(Q.begin(), Q.end(), V.begin());\n\n    Ntt.ntt(U, false), Ntt.ntt(V,\
    \ false);\n    for(int i = 0; i < size; i++)\n      U[i] *= Qneg[i], V[i] *= Qneg[i];\n\
    \    Ntt.ntt(U, true), Ntt.ntt(V, true);\n\n    for(int i = k & 1; i < 2 * d;\
    \ i += 2)\n      P[i >> 1] = U[i];\n    for(int i = 0; i <= 2 * d; i += 2)\n \
    \     Q[i >> 1] = V[i];\n    k >>= 1;\n  }\n\n  return P[0] / Q[0];\n}\n"
  code: "template<NTT Ntt, class Mint>\nmint BostanMori(vector<Mint> P, vector<Mint>\
    \ Q, ll k) {\n  assert(!P.empty() and !Q.empty() and Q[0] != 0);\n  \n  int d\
    \ = max(ssize(P), ssize(Q) - 1);\n  P.resize(d, 0), Q.resize(d + 1, 0);\n\n  int\
    \ size = 1 << (bit_width((unsigned)d) + 1);\n  while(k) {\n    vector<Mint> Qneg(size);\n\
    \    for(int i = 0; i < ssize(Q); i++)\n      Qneg[i] = Q[i] * ((i & 1) ? -1 :\
    \ 1);\n    Ntt.ntt(Qneg, false);\n\n    vector<Mint> U(size), V(size);\n    copy(P.begin(),\
    \ P.end(), U.begin());\n    copy(Q.begin(), Q.end(), V.begin());\n\n    Ntt.ntt(U,\
    \ false), Ntt.ntt(V, false);\n    for(int i = 0; i < size; i++)\n      U[i] *=\
    \ Qneg[i], V[i] *= Qneg[i];\n    Ntt.ntt(U, true), Ntt.ntt(V, true);\n\n    for(int\
    \ i = k & 1; i < 2 * d; i += 2)\n      P[i >> 1] = U[i];\n    for(int i = 0; i\
    \ <= 2 * d; i += 2)\n      Q[i >> 1] = V[i];\n    k >>= 1;\n  }\n\n  return P[0]\
    \ / Q[0];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/BostanMori.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/kth_term_of_linearly_recurrent_sequence.test.cpp
documentation_of: poly/BostanMori.cpp
layout: document
redirect_from:
- /library/poly/BostanMori.cpp
- /library/poly/BostanMori.cpp.html
title: poly/BostanMori.cpp
---
