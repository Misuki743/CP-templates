---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/multipoint_evaluation_on_geometric_sequence.test.cpp
    title: test/multipoint_evaluation_on_geometric_sequence.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/chirp_Z_transform.cpp\"\ntemplate<NTT Ntt, class Mint>\n\
    vector<Mint> chirp_Z_transform(vector<Mint> P, Mint a, Mint r, int m) {\n  const\
    \ int n = ssize(P);\n  const int sz = bit_ceil((unsigned)(2 * (n - 1) + m + 1));\n\
    \n  if (r == Mint(0)) {\n    vector<Mint> Q(m, P[0]);\n    mint prod_a = a;\n\
    \    for(int i = 1; i < n; i++, prod_a *= a)\n      Q[0] += P[i] * prod_a;\n \
    \   return Q;\n  }\n\n  vector<Mint> pw_r(n + m), pw_ri(n + m);\n  pw_r[0] = 1;\n\
    \  for(int i = 1; i < n + m; i++)\n    pw_r[i] = pw_r[i - 1] * r;\n  pw_ri.back()\
    \ = 1 / pw_r.back();\n  for(int i = n + m - 2; i >= 0; i--)\n    pw_ri[i] = pw_ri[i\
    \ + 1] * r;\n\n  vector<Mint> F(sz), G(sz);\n  {\n    mint prod_a = 1, prod_ri\
    \ = 1;\n    for(int i = 0; i < n; prod_a *= a, prod_ri *= pw_ri[i++])\n      F[(sz\
    \ - i) % sz] = P[i] * prod_a * prod_ri;\n    mint prod_r = 1;\n    for(int i =\
    \ 0; i < n + m - 1; prod_r *= pw_r[i++])\n      G[i] = prod_r;\n  }\n\n  Ntt.ntt(F,\
    \ false), Ntt.ntt(G, false);\n  for(int i = 0; i < sz; i++)\n    F[i] *= G[i];\n\
    \  Ntt.ntt(F, true);\n\n  vector<Mint> Q(m);\n  mint prod_ri = 1;\n  for(int i\
    \ = 0; i < m; prod_ri *= pw_ri[i++])\n    Q[i] = F[i] * prod_ri;\n\n  return Q;\n\
    }\n"
  code: "template<NTT Ntt, class Mint>\nvector<Mint> chirp_Z_transform(vector<Mint>\
    \ P, Mint a, Mint r, int m) {\n  const int n = ssize(P);\n  const int sz = bit_ceil((unsigned)(2\
    \ * (n - 1) + m + 1));\n\n  if (r == Mint(0)) {\n    vector<Mint> Q(m, P[0]);\n\
    \    mint prod_a = a;\n    for(int i = 1; i < n; i++, prod_a *= a)\n      Q[0]\
    \ += P[i] * prod_a;\n    return Q;\n  }\n\n  vector<Mint> pw_r(n + m), pw_ri(n\
    \ + m);\n  pw_r[0] = 1;\n  for(int i = 1; i < n + m; i++)\n    pw_r[i] = pw_r[i\
    \ - 1] * r;\n  pw_ri.back() = 1 / pw_r.back();\n  for(int i = n + m - 2; i >=\
    \ 0; i--)\n    pw_ri[i] = pw_ri[i + 1] * r;\n\n  vector<Mint> F(sz), G(sz);\n\
    \  {\n    mint prod_a = 1, prod_ri = 1;\n    for(int i = 0; i < n; prod_a *= a,\
    \ prod_ri *= pw_ri[i++])\n      F[(sz - i) % sz] = P[i] * prod_a * prod_ri;\n\
    \    mint prod_r = 1;\n    for(int i = 0; i < n + m - 1; prod_r *= pw_r[i++])\n\
    \      G[i] = prod_r;\n  }\n\n  Ntt.ntt(F, false), Ntt.ntt(G, false);\n  for(int\
    \ i = 0; i < sz; i++)\n    F[i] *= G[i];\n  Ntt.ntt(F, true);\n\n  vector<Mint>\
    \ Q(m);\n  mint prod_ri = 1;\n  for(int i = 0; i < m; prod_ri *= pw_ri[i++])\n\
    \    Q[i] = F[i] * prod_ri;\n\n  return Q;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/chirp_Z_transform.cpp
  requiredBy: []
  timestamp: '2025-05-10 02:31:09+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/multipoint_evaluation_on_geometric_sequence.test.cpp
documentation_of: poly/chirp_Z_transform.cpp
layout: document
redirect_from:
- /library/poly/chirp_Z_transform.cpp
- /library/poly/chirp_Z_transform.cpp.html
title: poly/chirp_Z_transform.cpp
---
