---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/factorize.test.cpp
    title: test/factorize.test.cpp
  - icon: ':x:'
    path: test/primality_test.test.cpp
    title: test/primality_test.test.cpp
  - icon: ':x:'
    path: test/primitive_root.test.cpp
    title: test/primitive_root.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/kth-competitive-programming/kactl)
  bundledCode: "#line 1 \"numtheory/fastFactorize.cpp\"\n//source: KACTL(https://github.com/kth-competitive-programming/kactl)\n\
    \null modmul(ull a, ull b, ull M) {\n\tll ret = a * b - M * ull(1.L / M * a *\
    \ b);\n\treturn ret + M * (ret < 0) - M * (ret >= (ll)M);\n}\n\null modpow(ull\
    \ b, ull e, ull mod) {\n\tull ans = 1;\n\tfor (; e; b = modmul(b, b, mod), e /=\
    \ 2)\n\t\tif (e & 1) ans = modmul(ans, b, mod);\n\treturn ans;\n}\n\nbool isPrime(ull\
    \ n) {\n\tif (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n\tull A[] = {2, 325,\
    \ 9375, 28178, 450775, 9780504, 1795265022},\n\t    s = __builtin_ctzll(n-1),\
    \ d = n >> s;\n\tfor (ull a : A) {   // ^ count trailing zeroes\n\t\tull p = modpow(a%n,\
    \ d, n), i = s;\n\t\twhile (p != 1 && p != n - 1 && a % n && i--)\n\t\t\tp = modmul(p,\
    \ p, n);\n\t\tif (p != n-1 && i != s) return 0;\n\t}\n\treturn 1;\n}\n\null pollard(ull\
    \ n) {\n  static mt19937_64 rng(clock);\n  uniform_int_distribution<ull> unif(0,\
    \ n - 1);\n  ull c = 1;\n\tauto f = [n, &c](ull x) { return modmul(x, x, n) +\
    \ c % n; };\n\tull x = 0, y = 0, t = 30, prd = 2, i = 1, q;\n\twhile (t++ % 40\
    \ || __gcd(prd, n) == 1) {\n\t\tif (x == y) c = unif(rng), x = ++i, y = f(x);\n\
    \t\tif ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;\n\t\tx = f(x), y =\
    \ f(f(y));\n\t}\n\treturn __gcd(prd, n);\n}\n\nvector<ull> factor(ull n) {\n\t\
    if (n == 1) return {};\n\tif (isPrime(n)) return {n};\n\tull x = pollard(n);\n\
    \tauto l = factor(x), r = factor(n / x);\n\tl.insert(l.end(), r.begin(), r.end());\n\
    \treturn l;\n}\n"
  code: "//source: KACTL(https://github.com/kth-competitive-programming/kactl)\n\n\
    ull modmul(ull a, ull b, ull M) {\n\tll ret = a * b - M * ull(1.L / M * a * b);\n\
    \treturn ret + M * (ret < 0) - M * (ret >= (ll)M);\n}\n\null modpow(ull b, ull\
    \ e, ull mod) {\n\tull ans = 1;\n\tfor (; e; b = modmul(b, b, mod), e /= 2)\n\t\
    \tif (e & 1) ans = modmul(ans, b, mod);\n\treturn ans;\n}\n\nbool isPrime(ull\
    \ n) {\n\tif (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n\tull A[] = {2, 325,\
    \ 9375, 28178, 450775, 9780504, 1795265022},\n\t    s = __builtin_ctzll(n-1),\
    \ d = n >> s;\n\tfor (ull a : A) {   // ^ count trailing zeroes\n\t\tull p = modpow(a%n,\
    \ d, n), i = s;\n\t\twhile (p != 1 && p != n - 1 && a % n && i--)\n\t\t\tp = modmul(p,\
    \ p, n);\n\t\tif (p != n-1 && i != s) return 0;\n\t}\n\treturn 1;\n}\n\null pollard(ull\
    \ n) {\n  static mt19937_64 rng(clock);\n  uniform_int_distribution<ull> unif(0,\
    \ n - 1);\n  ull c = 1;\n\tauto f = [n, &c](ull x) { return modmul(x, x, n) +\
    \ c % n; };\n\tull x = 0, y = 0, t = 30, prd = 2, i = 1, q;\n\twhile (t++ % 40\
    \ || __gcd(prd, n) == 1) {\n\t\tif (x == y) c = unif(rng), x = ++i, y = f(x);\n\
    \t\tif ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;\n\t\tx = f(x), y =\
    \ f(f(y));\n\t}\n\treturn __gcd(prd, n);\n}\n\nvector<ull> factor(ull n) {\n\t\
    if (n == 1) return {};\n\tif (isPrime(n)) return {n};\n\tull x = pollard(n);\n\
    \tauto l = factor(x), r = factor(n / x);\n\tl.insert(l.end(), r.begin(), r.end());\n\
    \treturn l;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numtheory/fastFactorize.cpp
  requiredBy: []
  timestamp: '2024-01-23 02:14:10+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/factorize.test.cpp
  - test/primitive_root.test.cpp
  - test/primality_test.test.cpp
documentation_of: numtheory/fastFactorize.cpp
layout: document
redirect_from:
- /library/numtheory/fastFactorize.cpp
- /library/numtheory/fastFactorize.cpp.html
title: numtheory/fastFactorize.cpp
---
