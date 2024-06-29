---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/bernoulli_number.test.cpp
    title: test/bernoulli_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/compositional_inverse_of_formal_power_series_large.test.cpp
    title: test/compositional_inverse_of_formal_power_series_large.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/division_of_polynomials.test.cpp
    title: test/division_of_polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/exp_of_formal_power_series.test.cpp
    title: test/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/exp_of_formal_power_series_sparse.test.cpp
    title: test/exp_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/inv_of_formal_power_series.test.cpp
    title: test/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/inv_of_formal_power_series_sparse.test.cpp
    title: test/inv_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/log_of_formal_power_series.test.cpp
    title: test/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/log_of_formal_power_series_sparse.test.cpp
    title: test/log_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/multipoint_evaluation.test.cpp
    title: test/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial_interpolation.test.cpp
    title: test/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial_taylor_shift.test.cpp
    title: test/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/pow_of_formal_power_series.test.cpp
    title: test/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/pow_of_formal_power_series_sparse.test.cpp
    title: test/pow_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/product_of_polynomial_sequence.test.cpp
    title: test/product_of_polynomial_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/sharp_p_subset_sum.test.cpp
    title: test/sharp_p_subset_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/sqrt_of_formal_power_series.test.cpp
    title: test/sqrt_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/sqrt_of_formal_power_series_sparse.test.cpp
    title: test/sqrt_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/stirling_number_of_the_first_kind.test.cpp
    title: test/stirling_number_of_the_first_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/subset_convolution.test.cpp
    title: test/subset_convolution.test.cpp
  - icon: ':x:'
    path: test/wildcard_pattern_matching.test.cpp
    title: test/wildcard_pattern_matching.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/FPS.cpp\"\n//#include \"modint/MontgomeryModInt.cpp\"\
    \n//#include \"poly/NTTmint.cpp\"\n\n//lagrange inversion formula:\n//  let f(x)\
    \ be composition inverse of g(x) (i.e. f(g(x)) = x) and [x^0]f(x) = [x^0]g(x)\
    \ = 0, [x^1]f(x) != 0, [x^1]g(x) != 0, then\n//  [x^n]g(x)^k = k/n [x^{n - k}]\
    \ (x / f(x))^n\n//  [x^n]g(x) = 1/n [x^{n - 1}] (x / f(x))^n (for k = 1)\n\ntemplate<class\
    \ Mint>\nstruct FPS : vector<Mint> {\n\n  static function<void(vector<Mint>&,\
    \ bool)> dft;\n  static function<vector<Mint>(vector<Mint>, vector<Mint>)> conv;\n\
    \n  FPS(vector<Mint> v) : vector<Mint>(v) {}\n\n  using vector<Mint>::vector;\n\
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
    \ *this;\n  }\n\n  FPS& operator<<=(int x) {\n    this -> resize(ssize(*this)\
    \ + x, Mint(0));\n    ranges::rotate(*this, this -> end() - x);\n    return *this;\n\
    \  }\n\n  FPS& operator>>=(int x) {\n    if (x >= ssize(*this)) {\n      this\
    \ -> resize(1);\n      (*this)[0] = 0;\n    } else {\n      ranges::rotate(*this,\
    \ this -> begin() + x);\n      this -> resize(ssize(*this) - x);\n    }\n    return\
    \ *this;\n  }\n\n  FPS shrink() {\n    FPS F = *this;\n    int size = ssize(F);\n\
    \    while(size and F[size - 1] == 0) size -= 1;\n    F.resize(size);\n    return\
    \ F;\n  }\n\n  FPS integral() {\n    if (this -> empty()) return {0};\n    vector<Mint>\
    \ Inv(ssize(*this) + 1);\n    Inv[1] = 1;\n    for(int i = 2; i < ssize(Inv);\
    \ i++)\n      Inv[i] = (Mint::get_mod() - Mint::get_mod() / i) * Inv[Mint::get_mod()\
    \ % i];\n    FPS Q(ssize(*this) + 1, 0);\n    for(int i = 0; i < ssize(*this);\
    \ i++)\n      Q[i + 1] = (*this)[i] * Inv[i + 1];\n    return Q;\n  }\n\n  FPS\
    \ derivative() {\n    assert(!this -> empty());\n    FPS Q(ssize(*this) - 1);\n\
    \    for(int i = 1; i < ssize(*this); i++)\n      Q[i - 1] = (*this)[i] * i;\n\
    \    return Q;\n  }\n\n  Mint eval(Mint x) {\n    Mint base = 1, res = 0;\n  \
    \  for(int i = 0; i < ssize(*this); i++, base *= x)\n      res += (*this)[i] *\
    \ base;\n    return res;\n  }\n\n  FPS inv(int k) { // 1 / FPS (mod x^k)\n   \
    \ assert(!this -> empty() and (*this)[0] != 0);\n    FPS Q(1, 1 / (*this)[0]);\n\
    \    for(int i = 1; (1 << (i - 1)) < k; i++) {\n      FPS P = (*this);\n     \
    \ P.resize(1 << i, 0);\n      Q = Q * (FPS(1, 2) - P * Q);\n      Q.resize(1 <<\
    \ i, 0);\n    }\n    Q.resize(k);\n    return Q;\n  }\n\n  array<FPS, 2> div(FPS\
    \ G) {\n    FPS F = this -> shrink();\n    G = G.shrink();\n    assert(!G.empty());\n\
    \    if (ssize(G) > ssize(F))\n      return {{{}, F}};\n    int n = ssize(F) -\
    \ ssize(G) + 1;\n    auto FR = F, GR = G;\n    ranges::reverse(FR);\n    ranges::reverse(GR);\n\
    \    FPS Q = FR * GR.inv(n);\n    Q.resize(n);\n    ranges::reverse(Q);\n    return\
    \ {Q, (F - G * Q).shrink()};\n  }\n\n  FPS log(int k) {\n    assert(!this -> empty()\
    \ and (*this)[0] == 1);\n    FPS Q = *this;\n    Q = (Q.derivative() * Q.inv(k));\n\
    \    Q.resize(k - 1);\n    return Q.integral();\n  }\n\n  FPS exp(int k) {\n \
    \   assert(!this -> empty() and (*this)[0] == 0);\n    FPS Q(1, 1);\n    for(int\
    \ i = 1; (1 << (i - 1)) < k; i++) {\n      FPS P = (*this);\n      P.resize(1\
    \ << i, 0);\n      Q = Q * (FPS(1, 1) + P - Q.log(1 << i));\n      Q.resize(1\
    \ << i, 0);\n    }\n    Q.resize(k);\n    return Q;\n  }\n\n  FPS pow(ll idx,\
    \ int k) {\n    if (idx == 0) {\n      FPS res(k, 0);\n      res[0] = 1;\n   \
    \   return res;\n    }\n    for(int i = 0; i < ssize(*this) and i * idx < k; i++)\
    \ {\n      if ((*this)[i] != 0) {\n        Mint Inv = 1 / (*this)[i];\n      \
    \  FPS Q(ssize(*this) - i);\n        for(int j = i; j < ssize(*this); j++)\n \
    \         Q[j - i] = (*this)[j] * Inv;\n        Q = (Q.log(k) * idx).exp(k);\n\
    \        FPS Q2(k, 0);\n        Mint Pow = (*this)[i].pow(idx);\n        for(int\
    \ j = 0; j + i * idx < k; j++)\n          Q2[j + i * idx] = Q[j] * Pow;\n    \
    \    return Q2;\n      }\n    } \n    return FPS(k, 0);\n  }\n\n  FPS pow(ll idx)\
    \ {\n    int mxDeg = (ssize(*this) - 1) * idx;\n    FPS a = (*this);\n    a.resize(bit_ceil((unsigned)(mxDeg\
    \ + 1)));\n    dft(a, false);\n    for(Mint &x : a) x = x.pow(idx);\n    dft(a,\
    \ true);\n    return FPS(a.begin(), a.begin() + mxDeg + 1);\n  }\n\n  vector<Mint>\
    \ multieval(vector<Mint> xs) {\n    int n = ssize(xs);\n    vector<FPS> data(2\
    \ * n);\n    for(int i = 0; i < n; i++)\n      data[n + i] = {-xs[i], 1};\n  \
    \  for(int i = n - 1; i > 0; i--)\n      data[i] = data[i << 1] * data[i << 1\
    \ | 1];\n    data[1] = (this -> div(data[1]))[1];\n    for(int i = 1; i < n; i++)\
    \ {\n      data[i << 1] = data[i].div(data[i << 1])[1];\n      data[i << 1 | 1]\
    \ = data[i].div(data[i << 1 | 1])[1];\n    }\n    vector<Mint> res(n);\n    for(int\
    \ i = 0; i < n; i++)\n      res[i] = data[n + i].empty() ? 0 : data[n + i][0];\n\
    \    return res;\n  }\n\n  static vector<Mint> interpolate(vector<Mint> xs, vector<Mint>\
    \ ys) {\n    assert(ssize(xs) == ssize(ys));\n    int n = ssize(xs);\n    vector<FPS>\
    \ data(2 * n), res(2 * n);\n    for(int i = 0; i < n; i++)\n      data[n + i]\
    \ = {-xs[i], 1};\n    for(int i = n - 1; i > 0; i--)\n      data[i] = data[i <<\
    \ 1] * data[i << 1 | 1];\n    res[1] = data[1].derivative().div(data[1])[1];\n\
    \    for(int i = 1; i < n; i++) {\n      res[i << 1] = res[i].div(data[i << 1])[1];\n\
    \      res[i << 1 | 1] = res[i].div(data[i << 1 | 1])[1];\n    }\n    for(int\
    \ i = 0; i < n; i++)\n      res[n + i][0] = ys[i] / res[n + i][0];\n    for(int\
    \ i = n - 1; i > 0; i--)\n      res[i] = res[i << 1] * data[i << 1 | 1] + res[i\
    \ << 1 | 1] * data[i << 1];\n    return res[1];\n  }\n\n  static vector<Mint>\
    \ allProd(vector<FPS> &fs) {\n    if (fs.empty()) return {1};\n    auto dfs =\
    \ [&](int l, int r, auto self) -> FPS {\n      if (l + 1 == r)\n        return\
    \ fs[l];\n      else\n        return self(l, (l + r) / 2, self) * self((l + r)\
    \ / 2, r, self);\n    };\n    return dfs(0, ssize(fs), dfs);\n  }\n\n  friend\
    \ FPS operator+(FPS a, FPS b) { return a += b; }\n  friend FPS operator-(FPS a,\
    \ FPS b) { return a -= b; }\n  friend FPS operator*(FPS a, FPS b) { return a *=\
    \ b; }\n  friend FPS operator*(FPS a, Mint b) { return a *= b; }\n  friend FPS\
    \ operator/(FPS a, Mint b) { return a /= b; }\n  friend FPS operator<<(FPS a,\
    \ int x) { return a <<= x; }\n  friend FPS operator>>(FPS a, int x) { return a\
    \ >>= x; }\n};\n\nNTT ntt;\nusing fps = FPS<mint>;\ntemplate<>\nfunction<vector<mint>(vector<mint>,\
    \ vector<mint>)> fps::conv = ntt.conv;\ntemplate<>\nfunction<void(vector<mint>&,\
    \ bool)> fps::dft = ntt.ntt;\n"
  code: "//#include \"modint/MontgomeryModInt.cpp\"\n//#include \"poly/NTTmint.cpp\"\
    \n\n//lagrange inversion formula:\n//  let f(x) be composition inverse of g(x)\
    \ (i.e. f(g(x)) = x) and [x^0]f(x) = [x^0]g(x) = 0, [x^1]f(x) != 0, [x^1]g(x)\
    \ != 0, then\n//  [x^n]g(x)^k = k/n [x^{n - k}] (x / f(x))^n\n//  [x^n]g(x) =\
    \ 1/n [x^{n - 1}] (x / f(x))^n (for k = 1)\n\ntemplate<class Mint>\nstruct FPS\
    \ : vector<Mint> {\n\n  static function<void(vector<Mint>&, bool)> dft;\n  static\
    \ function<vector<Mint>(vector<Mint>, vector<Mint>)> conv;\n\n  FPS(vector<Mint>\
    \ v) : vector<Mint>(v) {}\n\n  using vector<Mint>::vector;\n  FPS& operator+=(FPS\
    \ b) {\n    if (ssize(*this) < ssize(b)) this -> resize(ssize(b), 0);\n    for(int\
    \ i = 0; i < ssize(b); i++)\n      (*this)[i] += b[i];\n    return *this;\n  }\n\
    \n  FPS& operator-=(FPS b) {\n    if (ssize(*this) < ssize(b)) this -> resize(ssize(b),\
    \ 0);\n    for(int i = 0; i < ssize(b); i++)\n      (*this)[i] -= b[i];\n    return\
    \ *this;\n  }\n\n  FPS& operator*=(FPS b) {\n    auto c = conv(*this, b);\n  \
    \  this -> resize(ssize(*this) + ssize(b) - 1);\n    copy(c.begin(), c.end(),\
    \ this -> begin());\n    return *this;\n  }\n\n  FPS& operator*=(Mint b) {\n \
    \   for(int i = 0; i < ssize(*this); i++)\n      (*this)[i] *= b;\n    return\
    \ *this;\n  }\n\n  FPS& operator/=(Mint b) {\n    b = Mint(1) / b;\n    for(int\
    \ i = 0; i < ssize(*this); i++)\n      (*this)[i] *= b;\n    return *this;\n \
    \ }\n\n  FPS& operator<<=(int x) {\n    this -> resize(ssize(*this) + x, Mint(0));\n\
    \    ranges::rotate(*this, this -> end() - x);\n    return *this;\n  }\n\n  FPS&\
    \ operator>>=(int x) {\n    if (x >= ssize(*this)) {\n      this -> resize(1);\n\
    \      (*this)[0] = 0;\n    } else {\n      ranges::rotate(*this, this -> begin()\
    \ + x);\n      this -> resize(ssize(*this) - x);\n    }\n    return *this;\n \
    \ }\n\n  FPS shrink() {\n    FPS F = *this;\n    int size = ssize(F);\n    while(size\
    \ and F[size - 1] == 0) size -= 1;\n    F.resize(size);\n    return F;\n  }\n\n\
    \  FPS integral() {\n    if (this -> empty()) return {0};\n    vector<Mint> Inv(ssize(*this)\
    \ + 1);\n    Inv[1] = 1;\n    for(int i = 2; i < ssize(Inv); i++)\n      Inv[i]\
    \ = (Mint::get_mod() - Mint::get_mod() / i) * Inv[Mint::get_mod() % i];\n    FPS\
    \ Q(ssize(*this) + 1, 0);\n    for(int i = 0; i < ssize(*this); i++)\n      Q[i\
    \ + 1] = (*this)[i] * Inv[i + 1];\n    return Q;\n  }\n\n  FPS derivative() {\n\
    \    assert(!this -> empty());\n    FPS Q(ssize(*this) - 1);\n    for(int i =\
    \ 1; i < ssize(*this); i++)\n      Q[i - 1] = (*this)[i] * i;\n    return Q;\n\
    \  }\n\n  Mint eval(Mint x) {\n    Mint base = 1, res = 0;\n    for(int i = 0;\
    \ i < ssize(*this); i++, base *= x)\n      res += (*this)[i] * base;\n    return\
    \ res;\n  }\n\n  FPS inv(int k) { // 1 / FPS (mod x^k)\n    assert(!this -> empty()\
    \ and (*this)[0] != 0);\n    FPS Q(1, 1 / (*this)[0]);\n    for(int i = 1; (1\
    \ << (i - 1)) < k; i++) {\n      FPS P = (*this);\n      P.resize(1 << i, 0);\n\
    \      Q = Q * (FPS(1, 2) - P * Q);\n      Q.resize(1 << i, 0);\n    }\n    Q.resize(k);\n\
    \    return Q;\n  }\n\n  array<FPS, 2> div(FPS G) {\n    FPS F = this -> shrink();\n\
    \    G = G.shrink();\n    assert(!G.empty());\n    if (ssize(G) > ssize(F))\n\
    \      return {{{}, F}};\n    int n = ssize(F) - ssize(G) + 1;\n    auto FR =\
    \ F, GR = G;\n    ranges::reverse(FR);\n    ranges::reverse(GR);\n    FPS Q =\
    \ FR * GR.inv(n);\n    Q.resize(n);\n    ranges::reverse(Q);\n    return {Q, (F\
    \ - G * Q).shrink()};\n  }\n\n  FPS log(int k) {\n    assert(!this -> empty()\
    \ and (*this)[0] == 1);\n    FPS Q = *this;\n    Q = (Q.derivative() * Q.inv(k));\n\
    \    Q.resize(k - 1);\n    return Q.integral();\n  }\n\n  FPS exp(int k) {\n \
    \   assert(!this -> empty() and (*this)[0] == 0);\n    FPS Q(1, 1);\n    for(int\
    \ i = 1; (1 << (i - 1)) < k; i++) {\n      FPS P = (*this);\n      P.resize(1\
    \ << i, 0);\n      Q = Q * (FPS(1, 1) + P - Q.log(1 << i));\n      Q.resize(1\
    \ << i, 0);\n    }\n    Q.resize(k);\n    return Q;\n  }\n\n  FPS pow(ll idx,\
    \ int k) {\n    if (idx == 0) {\n      FPS res(k, 0);\n      res[0] = 1;\n   \
    \   return res;\n    }\n    for(int i = 0; i < ssize(*this) and i * idx < k; i++)\
    \ {\n      if ((*this)[i] != 0) {\n        Mint Inv = 1 / (*this)[i];\n      \
    \  FPS Q(ssize(*this) - i);\n        for(int j = i; j < ssize(*this); j++)\n \
    \         Q[j - i] = (*this)[j] * Inv;\n        Q = (Q.log(k) * idx).exp(k);\n\
    \        FPS Q2(k, 0);\n        Mint Pow = (*this)[i].pow(idx);\n        for(int\
    \ j = 0; j + i * idx < k; j++)\n          Q2[j + i * idx] = Q[j] * Pow;\n    \
    \    return Q2;\n      }\n    } \n    return FPS(k, 0);\n  }\n\n  FPS pow(ll idx)\
    \ {\n    int mxDeg = (ssize(*this) - 1) * idx;\n    FPS a = (*this);\n    a.resize(bit_ceil((unsigned)(mxDeg\
    \ + 1)));\n    dft(a, false);\n    for(Mint &x : a) x = x.pow(idx);\n    dft(a,\
    \ true);\n    return FPS(a.begin(), a.begin() + mxDeg + 1);\n  }\n\n  vector<Mint>\
    \ multieval(vector<Mint> xs) {\n    int n = ssize(xs);\n    vector<FPS> data(2\
    \ * n);\n    for(int i = 0; i < n; i++)\n      data[n + i] = {-xs[i], 1};\n  \
    \  for(int i = n - 1; i > 0; i--)\n      data[i] = data[i << 1] * data[i << 1\
    \ | 1];\n    data[1] = (this -> div(data[1]))[1];\n    for(int i = 1; i < n; i++)\
    \ {\n      data[i << 1] = data[i].div(data[i << 1])[1];\n      data[i << 1 | 1]\
    \ = data[i].div(data[i << 1 | 1])[1];\n    }\n    vector<Mint> res(n);\n    for(int\
    \ i = 0; i < n; i++)\n      res[i] = data[n + i].empty() ? 0 : data[n + i][0];\n\
    \    return res;\n  }\n\n  static vector<Mint> interpolate(vector<Mint> xs, vector<Mint>\
    \ ys) {\n    assert(ssize(xs) == ssize(ys));\n    int n = ssize(xs);\n    vector<FPS>\
    \ data(2 * n), res(2 * n);\n    for(int i = 0; i < n; i++)\n      data[n + i]\
    \ = {-xs[i], 1};\n    for(int i = n - 1; i > 0; i--)\n      data[i] = data[i <<\
    \ 1] * data[i << 1 | 1];\n    res[1] = data[1].derivative().div(data[1])[1];\n\
    \    for(int i = 1; i < n; i++) {\n      res[i << 1] = res[i].div(data[i << 1])[1];\n\
    \      res[i << 1 | 1] = res[i].div(data[i << 1 | 1])[1];\n    }\n    for(int\
    \ i = 0; i < n; i++)\n      res[n + i][0] = ys[i] / res[n + i][0];\n    for(int\
    \ i = n - 1; i > 0; i--)\n      res[i] = res[i << 1] * data[i << 1 | 1] + res[i\
    \ << 1 | 1] * data[i << 1];\n    return res[1];\n  }\n\n  static vector<Mint>\
    \ allProd(vector<FPS> &fs) {\n    if (fs.empty()) return {1};\n    auto dfs =\
    \ [&](int l, int r, auto self) -> FPS {\n      if (l + 1 == r)\n        return\
    \ fs[l];\n      else\n        return self(l, (l + r) / 2, self) * self((l + r)\
    \ / 2, r, self);\n    };\n    return dfs(0, ssize(fs), dfs);\n  }\n\n  friend\
    \ FPS operator+(FPS a, FPS b) { return a += b; }\n  friend FPS operator-(FPS a,\
    \ FPS b) { return a -= b; }\n  friend FPS operator*(FPS a, FPS b) { return a *=\
    \ b; }\n  friend FPS operator*(FPS a, Mint b) { return a *= b; }\n  friend FPS\
    \ operator/(FPS a, Mint b) { return a /= b; }\n  friend FPS operator<<(FPS a,\
    \ int x) { return a <<= x; }\n  friend FPS operator>>(FPS a, int x) { return a\
    \ >>= x; }\n};\n\nNTT ntt;\nusing fps = FPS<mint>;\ntemplate<>\nfunction<vector<mint>(vector<mint>,\
    \ vector<mint>)> fps::conv = ntt.conv;\ntemplate<>\nfunction<void(vector<mint>&,\
    \ bool)> fps::dft = ntt.ntt;\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/FPS.cpp
  requiredBy: []
  timestamp: '2024-05-11 22:13:26+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/multipoint_evaluation.test.cpp
  - test/sharp_p_subset_sum.test.cpp
  - test/log_of_formal_power_series_sparse.test.cpp
  - test/subset_convolution.test.cpp
  - test/inv_of_formal_power_series.test.cpp
  - test/compositional_inverse_of_formal_power_series_large.test.cpp
  - test/pow_of_formal_power_series_sparse.test.cpp
  - test/product_of_polynomial_sequence.test.cpp
  - test/polynomial_taylor_shift.test.cpp
  - test/exp_of_formal_power_series.test.cpp
  - test/stirling_number_of_the_first_kind.test.cpp
  - test/sqrt_of_formal_power_series.test.cpp
  - test/bernoulli_number.test.cpp
  - test/polynomial_interpolation.test.cpp
  - test/inv_of_formal_power_series_sparse.test.cpp
  - test/pow_of_formal_power_series.test.cpp
  - test/exp_of_formal_power_series_sparse.test.cpp
  - test/division_of_polynomials.test.cpp
  - test/sqrt_of_formal_power_series_sparse.test.cpp
  - test/log_of_formal_power_series.test.cpp
  - test/wildcard_pattern_matching.test.cpp
documentation_of: poly/FPS.cpp
layout: document
redirect_from:
- /library/poly/FPS.cpp
- /library/poly/FPS.cpp.html
title: poly/FPS.cpp
---
