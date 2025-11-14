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
  bundledCode: "#line 1 \"icpc/multieval_and_interpolate.cpp\"\n//#include \"polyope\"\
    \ (conv, inv, deriv)\nvoid shrink(vl &f) { while(!f.empty() and f.back() == 0)\
    \ f.pop_back(); }\narray<vl, 2> long_division(vl f, vl g) {\n  shrink(f), shrink(g);\n\
    \  assert(!g.empty());\n  int n = ssize(f) - ssize(g) + 1;\n  if (n <= 0) return\
    \ {{{}, f}};\n  auto fr = f, gr = g;\n  ranges::reverse(fr), ranges::reverse(gr);\n\
    \  auto q = conv(fr, inv(gr, n));\n  q.resize(n);\n  ranges::reverse(q);\n\n \
    \ g = conv(g, q);\n  f.resize(max(size(f), size(g)), 0);\n  for(int i = 0; i <\
    \ ssize(g); i++)\n    f[i] = (f[i] + mod - g[i]) % mod;\n  shrink(f);\n  return\
    \ {q, f};\n}\n\nvector<ll> multipoint_evaluation(vl f, vl xs) {\n  int n = ssize(xs);\n\
    \  vector<vl> prod(2 * n);\n  for(int i = 0; i < n; i++)\n    prod[n + i] = {(mod\
    \ - xs[i]) % mod, 1};\n  for(int i = n - 1; i > 0; i--)\n    prod[i] = conv(prod[i\
    \ << 1], prod[i << 1 | 1]);\n  prod[1] = long_division(f, prod[1])[1];\n  for(int\
    \ i = 1; i < n; i++) {\n    prod[i << 1] = long_division(prod[i], prod[i << 1])[1];\n\
    \    prod[i << 1 | 1] = long_division(prod[i], prod[i << 1 | 1])[1];\n  }\n  vector<ll>\
    \ ys(n);\n  for(int i = 0; i < n; i++)\n    ys[i] = prod[n + i].empty() ? 0 :\
    \ prod[n + i][0];\n  return ys;\n}\n\nvector<ll> polynomial_interpolation(vl xs,\
    \ vl ys) {\n  assert(size(xs) == size(ys));\n  int n = ssize(xs);\n  vector<vl>\
    \ prod(2 * n), res(2 * n);\n  for(int i = 0; i < n; i++)\n    prod[n + i] = {mod\
    \ - xs[i], 1};\n  for(int i = n - 1; i > 0; i--)\n    prod[i] = conv(prod[i <<\
    \ 1], prod[i << 1 | 1]);\n  res[1] = long_division(deriv(prod[1]), prod[1])[1];\n\
    \  for(int i = 1; i < n; i++) {\n    res[i << 1] = long_division(res[i], prod[i\
    \ << 1])[1];\n    res[i << 1 | 1] = long_division(res[i], prod[i << 1 | 1])[1];\n\
    \  }\n  for(int i = 0; i < n; i++)\n    res[n + i][0] = ys[i] * modpow(res[n +\
    \ i][0], mod - 2) % mod;\n  for(int i = n - 1; i > 0; i--) {\n    auto A = conv(res[i\
    \ << 1], prod[i << 1 | 1]);\n    auto B = conv(res[i << 1 | 1], prod[i << 1]);\n\
    \    if (size(A) < size(B)) swap(A, B);\n    for(int j = 0; j < ssize(B); j++)\n\
    \      (A[j] += B[j]) %= mod;\n    res[i].swap(A);\n  }\n  return res[1];\n}\n"
  code: "//#include \"polyope\" (conv, inv, deriv)\nvoid shrink(vl &f) { while(!f.empty()\
    \ and f.back() == 0) f.pop_back(); }\narray<vl, 2> long_division(vl f, vl g) {\n\
    \  shrink(f), shrink(g);\n  assert(!g.empty());\n  int n = ssize(f) - ssize(g)\
    \ + 1;\n  if (n <= 0) return {{{}, f}};\n  auto fr = f, gr = g;\n  ranges::reverse(fr),\
    \ ranges::reverse(gr);\n  auto q = conv(fr, inv(gr, n));\n  q.resize(n);\n  ranges::reverse(q);\n\
    \n  g = conv(g, q);\n  f.resize(max(size(f), size(g)), 0);\n  for(int i = 0; i\
    \ < ssize(g); i++)\n    f[i] = (f[i] + mod - g[i]) % mod;\n  shrink(f);\n  return\
    \ {q, f};\n}\n\nvector<ll> multipoint_evaluation(vl f, vl xs) {\n  int n = ssize(xs);\n\
    \  vector<vl> prod(2 * n);\n  for(int i = 0; i < n; i++)\n    prod[n + i] = {(mod\
    \ - xs[i]) % mod, 1};\n  for(int i = n - 1; i > 0; i--)\n    prod[i] = conv(prod[i\
    \ << 1], prod[i << 1 | 1]);\n  prod[1] = long_division(f, prod[1])[1];\n  for(int\
    \ i = 1; i < n; i++) {\n    prod[i << 1] = long_division(prod[i], prod[i << 1])[1];\n\
    \    prod[i << 1 | 1] = long_division(prod[i], prod[i << 1 | 1])[1];\n  }\n  vector<ll>\
    \ ys(n);\n  for(int i = 0; i < n; i++)\n    ys[i] = prod[n + i].empty() ? 0 :\
    \ prod[n + i][0];\n  return ys;\n}\n\nvector<ll> polynomial_interpolation(vl xs,\
    \ vl ys) {\n  assert(size(xs) == size(ys));\n  int n = ssize(xs);\n  vector<vl>\
    \ prod(2 * n), res(2 * n);\n  for(int i = 0; i < n; i++)\n    prod[n + i] = {mod\
    \ - xs[i], 1};\n  for(int i = n - 1; i > 0; i--)\n    prod[i] = conv(prod[i <<\
    \ 1], prod[i << 1 | 1]);\n  res[1] = long_division(deriv(prod[1]), prod[1])[1];\n\
    \  for(int i = 1; i < n; i++) {\n    res[i << 1] = long_division(res[i], prod[i\
    \ << 1])[1];\n    res[i << 1 | 1] = long_division(res[i], prod[i << 1 | 1])[1];\n\
    \  }\n  for(int i = 0; i < n; i++)\n    res[n + i][0] = ys[i] * modpow(res[n +\
    \ i][0], mod - 2) % mod;\n  for(int i = n - 1; i > 0; i--) {\n    auto A = conv(res[i\
    \ << 1], prod[i << 1 | 1]);\n    auto B = conv(res[i << 1 | 1], prod[i << 1]);\n\
    \    if (size(A) < size(B)) swap(A, B);\n    for(int j = 0; j < ssize(B); j++)\n\
    \      (A[j] += B[j]) %= mod;\n    res[i].swap(A);\n  }\n  return res[1];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: icpc/multieval_and_interpolate.cpp
  requiredBy: []
  timestamp: '2025-11-14 17:40:41+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc/multieval_and_interpolate.cpp
layout: document
redirect_from:
- /library/icpc/multieval_and_interpolate.cpp
- /library/icpc/multieval_and_interpolate.cpp.html
title: icpc/multieval_and_interpolate.cpp
---
