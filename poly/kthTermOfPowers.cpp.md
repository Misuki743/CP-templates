---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/compositional_inverse_of_formal_power_series_large.test.cpp
    title: test/compositional_inverse_of_formal_power_series_large.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://noshi91.hatenablog.com/entry/2024/03/16/224034
  bundledCode: "#line 1 \"poly/kthTermOfPowers.cpp\"\n//#include \"modint/MontgomeryModInt.cpp\"\
    \n//#include \"poly/NTTmint.cpp\"\n//#include \"poly/FPS.cpp\"\n\n//compute [x^k]f(x)^i\
    \ for all i in [0, n) in O(klg^2k)\n//reference: https://noshi91.hatenablog.com/entry/2024/03/16/224034\n\
    template<class Mint>\nFPS<Mint> kthTermOfPowers(int k, int n, FPS<Mint> g, FPS<Mint>\
    \ f = FPS<Mint>(1, 1)) {\n  assert(g[0] == 0);\n  auto remap = [](FPS<Mint> f,\
    \ int x0, int x1) -> FPS<Mint> {\n    int y0 = (ssize(f) + x0 - 1) / x0;\n   \
    \ FPS<Mint> g(y0 * x1);\n    for(int y = 0; y < y0; y++)\n      for(int x = 0;\
    \ x < x0 and y * x0 + x < ssize(f); x++)\n        g[y * x1 + x] = f[y * x0 + x];\n\
    \    return g;\n  };\n\n  FPS<Mint> P(k + 1), Q(2 * (k + 1));\n  for(int i = 0;\
    \ i < ssize(f) and i <= k; i++)\n    P[i] = f[i];\n  Q[0] = 1;\n  for(int i =\
    \ 0; i < ssize(g) and i <= k; i++)\n    Q[i + k + 1] = -g[i];\n\n  while(k) {\n\
    \    int yp = (ssize(Q) + k) / (k + 1) * 2 - 1, x0 = 2 * k + 1;\n    P = remap(P,\
    \ k + 1, x0), Q = remap(Q, k + 1, x0);\n    int sz = bit_ceil((unsigned)yp * x0);\n\
    \    P.resize(sz), Q.resize(sz);\n    FPS<Mint> Qneg = Q;\n    for(int y = 0;\
    \ y < yp; y++)\n      for(int x = 1; x < x0; x += 2)\n        Qneg[y * x0 + x]\
    \ *= -1;\n    FPS<Mint>::dft(P, false), FPS<Mint>::dft(Q, false), FPS<Mint>::dft(Qneg,\
    \ false);\n    FPS<Mint> U(sz), V(sz);\n    for(int i = 0; i < sz; i++)\n    \
    \  U[i] += P[i] * Qneg[i], V[i] = Q[i] * Qneg[i];\n    FPS<Mint>::dft(U, true),\
    \ FPS<Mint>::dft(V, true);\n    int xp = k / 2 + 1;\n    FPS<Mint> UU(yp * xp);\n\
    \    for(int y = 0; y < yp; y++)\n      for(int x = k & 1; x / 2 < xp and y *\
    \ x0 + x < ssize(U); x += 2)\n        UU[y * xp + x / 2] = U[y * x0 + x];\n  \
    \  FPS<Mint> VV(yp * xp);\n    for(int y = 0; y < yp; y++)\n      for(int x =\
    \ 0; x / 2 < xp and y * x0 + x < ssize(V); x += 2)\n        VV[y * xp + x / 2]\
    \ = V[y * x0 + x];\n    P.swap(UU), Q.swap(VV);\n    k /= 2;\n  }\n\n  FPS<Mint>\
    \ res = P * Q.inv(n);\n  res.resize(n);\n\n  return res;\n}\n"
  code: "//#include \"modint/MontgomeryModInt.cpp\"\n//#include \"poly/NTTmint.cpp\"\
    \n//#include \"poly/FPS.cpp\"\n\n//compute [x^k]f(x)^i for all i in [0, n) in\
    \ O(klg^2k)\n//reference: https://noshi91.hatenablog.com/entry/2024/03/16/224034\n\
    template<class Mint>\nFPS<Mint> kthTermOfPowers(int k, int n, FPS<Mint> g, FPS<Mint>\
    \ f = FPS<Mint>(1, 1)) {\n  assert(g[0] == 0);\n  auto remap = [](FPS<Mint> f,\
    \ int x0, int x1) -> FPS<Mint> {\n    int y0 = (ssize(f) + x0 - 1) / x0;\n   \
    \ FPS<Mint> g(y0 * x1);\n    for(int y = 0; y < y0; y++)\n      for(int x = 0;\
    \ x < x0 and y * x0 + x < ssize(f); x++)\n        g[y * x1 + x] = f[y * x0 + x];\n\
    \    return g;\n  };\n\n  FPS<Mint> P(k + 1), Q(2 * (k + 1));\n  for(int i = 0;\
    \ i < ssize(f) and i <= k; i++)\n    P[i] = f[i];\n  Q[0] = 1;\n  for(int i =\
    \ 0; i < ssize(g) and i <= k; i++)\n    Q[i + k + 1] = -g[i];\n\n  while(k) {\n\
    \    int yp = (ssize(Q) + k) / (k + 1) * 2 - 1, x0 = 2 * k + 1;\n    P = remap(P,\
    \ k + 1, x0), Q = remap(Q, k + 1, x0);\n    int sz = bit_ceil((unsigned)yp * x0);\n\
    \    P.resize(sz), Q.resize(sz);\n    FPS<Mint> Qneg = Q;\n    for(int y = 0;\
    \ y < yp; y++)\n      for(int x = 1; x < x0; x += 2)\n        Qneg[y * x0 + x]\
    \ *= -1;\n    FPS<Mint>::dft(P, false), FPS<Mint>::dft(Q, false), FPS<Mint>::dft(Qneg,\
    \ false);\n    FPS<Mint> U(sz), V(sz);\n    for(int i = 0; i < sz; i++)\n    \
    \  U[i] += P[i] * Qneg[i], V[i] = Q[i] * Qneg[i];\n    FPS<Mint>::dft(U, true),\
    \ FPS<Mint>::dft(V, true);\n    int xp = k / 2 + 1;\n    FPS<Mint> UU(yp * xp);\n\
    \    for(int y = 0; y < yp; y++)\n      for(int x = k & 1; x / 2 < xp and y *\
    \ x0 + x < ssize(U); x += 2)\n        UU[y * xp + x / 2] = U[y * x0 + x];\n  \
    \  FPS<Mint> VV(yp * xp);\n    for(int y = 0; y < yp; y++)\n      for(int x =\
    \ 0; x / 2 < xp and y * x0 + x < ssize(V); x += 2)\n        VV[y * xp + x / 2]\
    \ = V[y * x0 + x];\n    P.swap(UU), Q.swap(VV);\n    k /= 2;\n  }\n\n  FPS<Mint>\
    \ res = P * Q.inv(n);\n  res.resize(n);\n\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/kthTermOfPowers.cpp
  requiredBy: []
  timestamp: '2024-03-22 01:43:37+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/compositional_inverse_of_formal_power_series_large.test.cpp
documentation_of: poly/kthTermOfPowers.cpp
layout: document
redirect_from:
- /library/poly/kthTermOfPowers.cpp
- /library/poly/kthTermOfPowers.cpp.html
title: poly/kthTermOfPowers.cpp
---
