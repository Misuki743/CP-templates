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
  bundledCode: "#line 1 \"linalg/determinantInt.cpp\"\n/**\n * Author: Unknown\n *\
    \ Date: 2014-11-27\n * Source: somewhere on github\n * Description: Calculates\
    \ determinant using modular arithmetics.\n * Modulos can also be removed to get\
    \ a pure-integer version.\n * Time: $O(N^3)$\n * Status: bruteforce-tested for\
    \ N <= 3, mod <= 7\n */\n\nconst ll mod = 12345;\nll det(vector<vector<ll>>& a)\
    \ {\n\tint n = sz(a); ll ans = 1;\n\trep(i,0,n) {\n\t\trep(j,i+1,n) {\n\t\t\t\
    while (a[j][i] != 0) { // gcd step\n\t\t\t\tll t = a[i][i] / a[j][i];\n\t\t\t\t\
    if (t) rep(k,i,n)\n\t\t\t\t\ta[i][k] = (a[i][k] - a[j][k] * t) % mod;\n\t\t\t\t\
    swap(a[i], a[j]);\n\t\t\t\tans *= -1;\n\t\t\t}\n\t\t}\n\t\tans = ans * a[i][i]\
    \ % mod;\n\t\tif (!ans) return 0;\n\t}\n\treturn (ans + mod) % mod;\n}\n"
  code: "/**\n * Author: Unknown\n * Date: 2014-11-27\n * Source: somewhere on github\n\
    \ * Description: Calculates determinant using modular arithmetics.\n * Modulos\
    \ can also be removed to get a pure-integer version.\n * Time: $O(N^3)$\n * Status:\
    \ bruteforce-tested for N <= 3, mod <= 7\n */\n\nconst ll mod = 12345;\nll det(vector<vector<ll>>&\
    \ a) {\n\tint n = sz(a); ll ans = 1;\n\trep(i,0,n) {\n\t\trep(j,i+1,n) {\n\t\t\
    \twhile (a[j][i] != 0) { // gcd step\n\t\t\t\tll t = a[i][i] / a[j][i];\n\t\t\t\
    \tif (t) rep(k,i,n)\n\t\t\t\t\ta[i][k] = (a[i][k] - a[j][k] * t) % mod;\n\t\t\t\
    \tswap(a[i], a[j]);\n\t\t\t\tans *= -1;\n\t\t\t}\n\t\t}\n\t\tans = ans * a[i][i]\
    \ % mod;\n\t\tif (!ans) return 0;\n\t}\n\treturn (ans + mod) % mod;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/determinantInt.cpp
  requiredBy: []
  timestamp: '2024-01-20 02:52:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/determinantInt.cpp
layout: document
redirect_from:
- /library/linalg/determinantInt.cpp
- /library/linalg/determinantInt.cpp.html
title: linalg/determinantInt.cpp
---
