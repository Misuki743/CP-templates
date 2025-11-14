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
  bundledCode: "#line 1 \"icpc/Bostan_Mori.cpp\"\n//#include \"polyope\"\nll BostanMori(vl\
    \ P, vl Q, ll k) {\n  assert(!P.empty() and !Q.empty() and Q[0] != 0);\n\n  int\
    \ d = max(ssize(P), ssize(Q) - 1);\n  P.resize(d, 0), Q.resize(d + 1, 0);\n\n\
    \  int size = 1 << (bit_width((unsigned)d) + 1);\n  ll inv = modpow(size, mod\
    \ - 2);\n  while(k) {\n    vl Qneg(size);\n    for(int i = 0; i < ssize(Q); i++)\n\
    \      Qneg[i] = Q[i] * ((i & 1) ? mod - 1 : 1) % mod;\n    ntt(Qneg);\n\n   \
    \ vl U(size), V(size);\n    ranges::copy(P, U.begin());\n    ranges::copy(Q, V.begin());\n\
    \    ntt(U), ntt(V);\n    for(int i = 0; i < size; i++) {\n      U[i] = U[i] *\
    \ Qneg[i] % mod * inv % mod;\n      V[i] = V[i] * Qneg[i] % mod * inv % mod;\n\
    \    }\n    ranges::reverse(U), ranges::reverse(V);\n    ranges::rotate(U, prev(U.end()));\n\
    \    ranges::rotate(V, prev(V.end()));\n    ntt(U), ntt(V);\n\n    for(int i =\
    \ k & 1; i < 2 * d; i += 2)\n      P[i >> 1] = U[i];\n    for(int i = 0; i <=\
    \ 2 * d; i += 2)\n      Q[i >> 1] = V[i];\n    k >>= 1;\n  }\n  return P[0] *\
    \ modpow(Q[0], mod - 2) % mod;\n}\n\nll calc_linear_recurrence(vl a, vl c, ll\
    \ k) {\n  assert(ssize(a) >= ssize(c) - 1);\n  a.resize(ssize(c) - 1);\n  for(ll\
    \ &x : c) x = (mod - x) % mod;\n  c[0] = 1;\n  a = conv(a, c);\n  a.resize(ssize(c)\
    \ - 1);\n  return BostanMori(a, c, k);\n}\n"
  code: "//#include \"polyope\"\nll BostanMori(vl P, vl Q, ll k) {\n  assert(!P.empty()\
    \ and !Q.empty() and Q[0] != 0);\n\n  int d = max(ssize(P), ssize(Q) - 1);\n \
    \ P.resize(d, 0), Q.resize(d + 1, 0);\n\n  int size = 1 << (bit_width((unsigned)d)\
    \ + 1);\n  ll inv = modpow(size, mod - 2);\n  while(k) {\n    vl Qneg(size);\n\
    \    for(int i = 0; i < ssize(Q); i++)\n      Qneg[i] = Q[i] * ((i & 1) ? mod\
    \ - 1 : 1) % mod;\n    ntt(Qneg);\n\n    vl U(size), V(size);\n    ranges::copy(P,\
    \ U.begin());\n    ranges::copy(Q, V.begin());\n    ntt(U), ntt(V);\n    for(int\
    \ i = 0; i < size; i++) {\n      U[i] = U[i] * Qneg[i] % mod * inv % mod;\n  \
    \    V[i] = V[i] * Qneg[i] % mod * inv % mod;\n    }\n    ranges::reverse(U),\
    \ ranges::reverse(V);\n    ranges::rotate(U, prev(U.end()));\n    ranges::rotate(V,\
    \ prev(V.end()));\n    ntt(U), ntt(V);\n\n    for(int i = k & 1; i < 2 * d; i\
    \ += 2)\n      P[i >> 1] = U[i];\n    for(int i = 0; i <= 2 * d; i += 2)\n   \
    \   Q[i >> 1] = V[i];\n    k >>= 1;\n  }\n  return P[0] * modpow(Q[0], mod - 2)\
    \ % mod;\n}\n\nll calc_linear_recurrence(vl a, vl c, ll k) {\n  assert(ssize(a)\
    \ >= ssize(c) - 1);\n  a.resize(ssize(c) - 1);\n  for(ll &x : c) x = (mod - x)\
    \ % mod;\n  c[0] = 1;\n  a = conv(a, c);\n  a.resize(ssize(c) - 1);\n  return\
    \ BostanMori(a, c, k);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: icpc/Bostan_Mori.cpp
  requiredBy: []
  timestamp: '2025-11-14 17:40:41+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc/Bostan_Mori.cpp
layout: document
redirect_from:
- /library/icpc/Bostan_Mori.cpp
- /library/icpc/Bostan_Mori.cpp.html
title: icpc/Bostan_Mori.cpp
---
