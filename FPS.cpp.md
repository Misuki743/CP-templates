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
  bundledCode: "#line 1 \"FPS.cpp\"\n/**\n * template name: FPS\n * author: Misuki\n\
    \ * last update: 2024/01/10\n * include: NTT/mint\n * verify: Library Checker\
    \ - Inv of Formal Power Series\n *         Library Checker - Exp of Formal Power\
    \ Series\n *         Library Checker - Log of Formal Power Series\n *        \
    \ Library Checker - Pow of Formal Power Series\n *         Library Checker - Convolution\n\
    \ *         Library Checker - Division of Polynomials\n *         Library Checker\
    \ - Multipoint Evaluation\n *         Library Checker - Polynomial Interpolation\n\
    \ */\n\ntemplate<class Mint>\nstruct FPS : vector<Mint> {\n\n  static function<vector<Mint>(vector<Mint>,\
    \ vector<Mint>)> conv;\n\n  FPS(vector<Mint> v) { *this = v; }\n\n  using vector<Mint>::vector;\n\
    \  FPS& operator+=(FPS b) {\n    if (ssize(*this) < ssize(b)) this -> resize(ssize(b),\
    \ 0);\n    for(int i = 0; i < ssize(b); i++)\n      (*this)[i] += b[i];\n    return\
    \ *this;\n  }\n\n  FPS& operator-=(FPS b) {\n    if (ssize(*this) < ssize(b))\
    \ this -> resize(ssize(b), 0);\n    for(int i = 0; i < ssize(b); i++)\n      (*this)[i]\
    \ -= b[i];\n    return *this;\n  }\n\n  FPS& operator*=(FPS b) {\n    auto c =\
    \ conv(*this, b);\n    this -> resize(ssize(*this) + ssize(b) - 1);\n    copy(c.begin(),\
    \ c.end(), this -> begin());\n    return *this;\n  }\n\n  FPS& operator*=(Mint\
    \ b) {\n    for(int i = 0; i < ssize(*this); i++)\n      (*this)[i] *= b;\n  \
    \  return *this;\n  }\n\n  FPS& operator/=(Mint b) {\n    b = Mint(1) / b;\n \
    \   for(int i = 0; i < ssize(*this); i++)\n      (*this)[i] *= b;\n    return\
    \ *this;\n  }\n\n  FPS shrink() {\n    FPS F = *this;\n    while(ssize(F) > 1\
    \ and F.back() == 0)\n      F.pop_back();\n    return F;\n  }\n\n  FPS integral()\
    \ {\n    vector<Mint> Inv(ssize(*this) + 1);\n    Inv[1] = 1;\n    for(int i =\
    \ 2; i < ssize(Inv); i++)\n      Inv[i] = (Mint::get_mod() - Mint::get_mod() /\
    \ i) * Inv[Mint::get_mod() % i];\n    FPS Q(ssize(*this) + 1, 0);\n    for(int\
    \ i = 0; i < ssize(*this); i++)\n      Q[i + 1] = (*this)[i] * Inv[i + 1];\n \
    \   return Q;\n  }\n\n  FPS derivative() {\n    assert(!this -> empty());\n  \
    \  FPS Q(ssize(*this) - 1);\n    for(int i = 1; i < ssize(*this); i++)\n     \
    \ Q[i - 1] = (*this)[i] * i;\n    return Q;\n  }\n\n  Mint eval(Mint x) {\n  \
    \  Mint base = 1, res = 0;\n    for(int i = 0; i < ssize(*this); i++, base *=\
    \ x)\n      res += (*this)[i] * base;\n    return res;\n  }\n\n  FPS inv(int k)\
    \ { // 1 / FPS (mod x^k)\n    assert(!this -> empty() and (*this)[0] != 0);\n\
    \    FPS Q(1, 1 / (*this)[0]);\n    for(int i = 1; (1 << (i - 1)) < k; i++) {\n\
    \      FPS P = (*this);\n      P.resize(1 << i, 0);\n      Q = Q * (FPS(1, 2)\
    \ - P * Q);\n      Q.resize(1 << i, 0);\n    }\n    Q.resize(k);\n    return Q;\n\
    \  }\n\n  array<FPS, 2> div(FPS G) {\n    FPS F = this -> shrink();\n    G = G.shrink();\n\
    \    assert(!G.empty());\n    if (ssize(G) > ssize(F))\n      return {{{}, F}};\n\
    \    int n = ssize(F) - ssize(G) + 1;\n    auto FR = F, GR = G;\n    R::reverse(FR);\n\
    \    R::reverse(GR);\n    FPS Q = FR * GR.inv(n);\n    Q.resize(n);\n    R::reverse(Q);\n\
    \    return {Q, (F - G * Q).shrink()};\n  }\n\n  FPS log(int k) {\n    assert(!this\
    \ -> empty() and (*this)[0] == 1);\n    FPS Q = *this;\n    Q = (Q.derivative()\
    \ * Q.inv(k));\n    Q.resize(k - 1);\n    return Q.integral();\n  }\n\n  FPS exp(int\
    \ k) {\n    assert(!this -> empty() and (*this)[0] == 0);\n    FPS Q(1, 1);\n\
    \    for(int i = 1; (1 << (i - 1)) < k; i++) {\n      FPS P = (*this);\n     \
    \ P.resize(1 << i, 0);\n      Q = Q * (FPS(1, 1) + P - Q.log(1 << i));\n     \
    \ Q.resize(1 << i, 0);\n    }\n    Q.resize(k);\n    return Q;\n  }\n\n  FPS pow(ll\
    \ idx, int k) {\n    if (idx == 0) {\n      FPS res(k, 0);\n      res[0] = 1;\n\
    \      return res;\n    }\n    for(int i = 0; i < ssize(*this) and i * idx < k;\
    \ i++) {\n      if ((*this)[i] != 0) {\n        Mint Inv = 1 / (*this)[i];\n \
    \       FPS Q(ssize(*this) - i);\n        for(int j = i; j < ssize(*this); j++)\n\
    \          Q[j - i] = (*this)[j] * Inv;\n        Q = (Q.log(k) * idx).exp(k);\n\
    \        FPS Q2(k, 0);\n        Mint Pow = (*this)[i].pow(idx);\n        for(int\
    \ j = 0; j + i * idx < k; j++)\n          Q2[j + i * idx] = Q[j] * Pow;\n    \
    \    return Q2;\n      }\n    } \n    return FPS(k, 0);\n  }\n\n  vector<Mint>\
    \ multieval(vector<Mint> xs) {\n    int n = ssize(xs);\n    vector<FPS> data(2\
    \ * n);\n    for(int i = 0; i < n; i++)\n      data[n + i] = {-xs[i], 1};\n  \
    \  for(int i = n - 1; i > 0; i--)\n      data[i] = data[i << 1] * data[i << 1\
    \ | 1];\n    data[1] = (this -> div(data[1]))[1];\n    for(int i = 1; i < n; i++)\
    \ {\n      data[i << 1] = data[i].div(data[i << 1])[1];\n      data[i << 1 | 1]\
    \ = data[i].div(data[i << 1 | 1])[1];\n    }\n    vector<Mint> res(n);\n    for(int\
    \ i = 0; i < n; i++)\n      res[i] = data[n + i][0];\n    return res;\n  }\n\n\
    \  static vector<Mint> interpolate(vector<Mint> xs, vector<Mint> ys) {\n    assert(ssize(xs)\
    \ == ssize(ys));\n    int n = ssize(xs);\n    vector<FPS> data(2 * n), res(2 *\
    \ n);\n    for(int i = 0; i < n; i++)\n      data[n + i] = {-xs[i], 1};\n    for(int\
    \ i = n - 1; i > 0; i--)\n      data[i] = data[i << 1] * data[i << 1 | 1];\n \
    \   res[1] = data[1].derivative().div(data[1])[1];\n    for(int i = 1; i < n;\
    \ i++) {\n      res[i << 1] = res[i].div(data[i << 1])[1];\n      res[i << 1 |\
    \ 1] = res[i].div(data[i << 1 | 1])[1];\n    }\n    for(int i = 0; i < n; i++)\n\
    \      res[n + i][0] = ys[i] / res[n + i][0];\n    for(int i = n - 1; i > 0; i--)\n\
    \      res[i] = res[i << 1] * data[i << 1 | 1] + res[i << 1 | 1] * data[i << 1];\n\
    \    return res[1];\n  }\n\n  friend FPS operator+(FPS a, FPS b) { return a +=\
    \ b; }\n  friend FPS operator-(FPS a, FPS b) { return a -= b; }\n  friend FPS\
    \ operator*(FPS a, FPS b) { return a *= b; }\n  friend FPS operator*(FPS a, Mint\
    \ b) { return a *= b; }\n  friend FPS operator/(FPS a, Mint b) { return a /= b;\
    \ }\n};\n\nNTT ntt;\nusing fps = FPS<mint>;\ntemplate<>\nfunction<vector<mint>(vector<mint>,\
    \ vector<mint>)> fps::conv = ntt.conv;\n"
  code: "/**\n * template name: FPS\n * author: Misuki\n * last update: 2024/01/10\n\
    \ * include: NTT/mint\n * verify: Library Checker - Inv of Formal Power Series\n\
    \ *         Library Checker - Exp of Formal Power Series\n *         Library Checker\
    \ - Log of Formal Power Series\n *         Library Checker - Pow of Formal Power\
    \ Series\n *         Library Checker - Convolution\n *         Library Checker\
    \ - Division of Polynomials\n *         Library Checker - Multipoint Evaluation\n\
    \ *         Library Checker - Polynomial Interpolation\n */\n\ntemplate<class\
    \ Mint>\nstruct FPS : vector<Mint> {\n\n  static function<vector<Mint>(vector<Mint>,\
    \ vector<Mint>)> conv;\n\n  FPS(vector<Mint> v) { *this = v; }\n\n  using vector<Mint>::vector;\n\
    \  FPS& operator+=(FPS b) {\n    if (ssize(*this) < ssize(b)) this -> resize(ssize(b),\
    \ 0);\n    for(int i = 0; i < ssize(b); i++)\n      (*this)[i] += b[i];\n    return\
    \ *this;\n  }\n\n  FPS& operator-=(FPS b) {\n    if (ssize(*this) < ssize(b))\
    \ this -> resize(ssize(b), 0);\n    for(int i = 0; i < ssize(b); i++)\n      (*this)[i]\
    \ -= b[i];\n    return *this;\n  }\n\n  FPS& operator*=(FPS b) {\n    auto c =\
    \ conv(*this, b);\n    this -> resize(ssize(*this) + ssize(b) - 1);\n    copy(c.begin(),\
    \ c.end(), this -> begin());\n    return *this;\n  }\n\n  FPS& operator*=(Mint\
    \ b) {\n    for(int i = 0; i < ssize(*this); i++)\n      (*this)[i] *= b;\n  \
    \  return *this;\n  }\n\n  FPS& operator/=(Mint b) {\n    b = Mint(1) / b;\n \
    \   for(int i = 0; i < ssize(*this); i++)\n      (*this)[i] *= b;\n    return\
    \ *this;\n  }\n\n  FPS shrink() {\n    FPS F = *this;\n    while(ssize(F) > 1\
    \ and F.back() == 0)\n      F.pop_back();\n    return F;\n  }\n\n  FPS integral()\
    \ {\n    vector<Mint> Inv(ssize(*this) + 1);\n    Inv[1] = 1;\n    for(int i =\
    \ 2; i < ssize(Inv); i++)\n      Inv[i] = (Mint::get_mod() - Mint::get_mod() /\
    \ i) * Inv[Mint::get_mod() % i];\n    FPS Q(ssize(*this) + 1, 0);\n    for(int\
    \ i = 0; i < ssize(*this); i++)\n      Q[i + 1] = (*this)[i] * Inv[i + 1];\n \
    \   return Q;\n  }\n\n  FPS derivative() {\n    assert(!this -> empty());\n  \
    \  FPS Q(ssize(*this) - 1);\n    for(int i = 1; i < ssize(*this); i++)\n     \
    \ Q[i - 1] = (*this)[i] * i;\n    return Q;\n  }\n\n  Mint eval(Mint x) {\n  \
    \  Mint base = 1, res = 0;\n    for(int i = 0; i < ssize(*this); i++, base *=\
    \ x)\n      res += (*this)[i] * base;\n    return res;\n  }\n\n  FPS inv(int k)\
    \ { // 1 / FPS (mod x^k)\n    assert(!this -> empty() and (*this)[0] != 0);\n\
    \    FPS Q(1, 1 / (*this)[0]);\n    for(int i = 1; (1 << (i - 1)) < k; i++) {\n\
    \      FPS P = (*this);\n      P.resize(1 << i, 0);\n      Q = Q * (FPS(1, 2)\
    \ - P * Q);\n      Q.resize(1 << i, 0);\n    }\n    Q.resize(k);\n    return Q;\n\
    \  }\n\n  array<FPS, 2> div(FPS G) {\n    FPS F = this -> shrink();\n    G = G.shrink();\n\
    \    assert(!G.empty());\n    if (ssize(G) > ssize(F))\n      return {{{}, F}};\n\
    \    int n = ssize(F) - ssize(G) + 1;\n    auto FR = F, GR = G;\n    R::reverse(FR);\n\
    \    R::reverse(GR);\n    FPS Q = FR * GR.inv(n);\n    Q.resize(n);\n    R::reverse(Q);\n\
    \    return {Q, (F - G * Q).shrink()};\n  }\n\n  FPS log(int k) {\n    assert(!this\
    \ -> empty() and (*this)[0] == 1);\n    FPS Q = *this;\n    Q = (Q.derivative()\
    \ * Q.inv(k));\n    Q.resize(k - 1);\n    return Q.integral();\n  }\n\n  FPS exp(int\
    \ k) {\n    assert(!this -> empty() and (*this)[0] == 0);\n    FPS Q(1, 1);\n\
    \    for(int i = 1; (1 << (i - 1)) < k; i++) {\n      FPS P = (*this);\n     \
    \ P.resize(1 << i, 0);\n      Q = Q * (FPS(1, 1) + P - Q.log(1 << i));\n     \
    \ Q.resize(1 << i, 0);\n    }\n    Q.resize(k);\n    return Q;\n  }\n\n  FPS pow(ll\
    \ idx, int k) {\n    if (idx == 0) {\n      FPS res(k, 0);\n      res[0] = 1;\n\
    \      return res;\n    }\n    for(int i = 0; i < ssize(*this) and i * idx < k;\
    \ i++) {\n      if ((*this)[i] != 0) {\n        Mint Inv = 1 / (*this)[i];\n \
    \       FPS Q(ssize(*this) - i);\n        for(int j = i; j < ssize(*this); j++)\n\
    \          Q[j - i] = (*this)[j] * Inv;\n        Q = (Q.log(k) * idx).exp(k);\n\
    \        FPS Q2(k, 0);\n        Mint Pow = (*this)[i].pow(idx);\n        for(int\
    \ j = 0; j + i * idx < k; j++)\n          Q2[j + i * idx] = Q[j] * Pow;\n    \
    \    return Q2;\n      }\n    } \n    return FPS(k, 0);\n  }\n\n  vector<Mint>\
    \ multieval(vector<Mint> xs) {\n    int n = ssize(xs);\n    vector<FPS> data(2\
    \ * n);\n    for(int i = 0; i < n; i++)\n      data[n + i] = {-xs[i], 1};\n  \
    \  for(int i = n - 1; i > 0; i--)\n      data[i] = data[i << 1] * data[i << 1\
    \ | 1];\n    data[1] = (this -> div(data[1]))[1];\n    for(int i = 1; i < n; i++)\
    \ {\n      data[i << 1] = data[i].div(data[i << 1])[1];\n      data[i << 1 | 1]\
    \ = data[i].div(data[i << 1 | 1])[1];\n    }\n    vector<Mint> res(n);\n    for(int\
    \ i = 0; i < n; i++)\n      res[i] = data[n + i][0];\n    return res;\n  }\n\n\
    \  static vector<Mint> interpolate(vector<Mint> xs, vector<Mint> ys) {\n    assert(ssize(xs)\
    \ == ssize(ys));\n    int n = ssize(xs);\n    vector<FPS> data(2 * n), res(2 *\
    \ n);\n    for(int i = 0; i < n; i++)\n      data[n + i] = {-xs[i], 1};\n    for(int\
    \ i = n - 1; i > 0; i--)\n      data[i] = data[i << 1] * data[i << 1 | 1];\n \
    \   res[1] = data[1].derivative().div(data[1])[1];\n    for(int i = 1; i < n;\
    \ i++) {\n      res[i << 1] = res[i].div(data[i << 1])[1];\n      res[i << 1 |\
    \ 1] = res[i].div(data[i << 1 | 1])[1];\n    }\n    for(int i = 0; i < n; i++)\n\
    \      res[n + i][0] = ys[i] / res[n + i][0];\n    for(int i = n - 1; i > 0; i--)\n\
    \      res[i] = res[i << 1] * data[i << 1 | 1] + res[i << 1 | 1] * data[i << 1];\n\
    \    return res[1];\n  }\n\n  friend FPS operator+(FPS a, FPS b) { return a +=\
    \ b; }\n  friend FPS operator-(FPS a, FPS b) { return a -= b; }\n  friend FPS\
    \ operator*(FPS a, FPS b) { return a *= b; }\n  friend FPS operator*(FPS a, Mint\
    \ b) { return a *= b; }\n  friend FPS operator/(FPS a, Mint b) { return a /= b;\
    \ }\n};\n\nNTT ntt;\nusing fps = FPS<mint>;\ntemplate<>\nfunction<vector<mint>(vector<mint>,\
    \ vector<mint>)> fps::conv = ntt.conv;\n"
  dependsOn: []
  isVerificationFile: false
  path: FPS.cpp
  requiredBy: []
  timestamp: '2024-01-13 20:11:08+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS.cpp
layout: document
redirect_from:
- /library/FPS.cpp
- /library/FPS.cpp.html
title: FPS.cpp
---
