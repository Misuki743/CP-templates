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
  bundledCode: "#line 1 \"setfunc/FWHT.cpp\"\n//source: KACTL\n\n/**\n * Author: Lucian\
    \ Bicsi\n * Date: 2015-06-25\n * License: GNU Free Documentation License 1.2\n\
    \ * Source: csacademy\n * Description: Transform to a basis with fast convolutions\
    \ of the form\n * $\\displaystyle c[z] = \\sum\\nolimits_{z = x \\oplus y} a[x]\
    \ \\cdot b[y]$,\n * where $\\oplus$ is one of AND, OR, XOR. The size of $a$ must\
    \ be a power of two.\n * Time: O(N \\log N)\n * Status: stress-tested\n */\n\n\
    template<class T>\nvoid FST(vector<T>& a, bool inv) {\n\tfor (int n = sz(a), step\
    \ = 1; step < n; step *= 2) {\n\t\tfor (int i = 0; i < n; i += 2 * step) rep(j,i,i+step)\
    \ {\n\t\t\tT &u = a[j], &v = a[j + step]; tie(u, v) =\n\t\t\t\t//inv ? pii(v -\
    \ u, u) : pii(v, u + v); // AND\n\t\t\t\t// inv ? pii(v, u - v) : pii(u + v, u);\
    \ // OR /// include-line\n\t\t\t\tpair<T, T>(u + v, u - v);                  \
    \ // XOR /// include-line\n\t\t}\n\t}\n\t if (inv) for (T& x : a) x /= sz(a);\
    \ // XOR only /// include-line\n}\n\ntemplate<class T>\nvector<T> conv(vector<T>\
    \ a, vector<T> b) {\n\tFST(a, 0); FST(b, 0);\n\trep(i,0,sz(a)) a[i] *= b[i];\n\
    \tFST(a, 1); return a;\n}\n"
  code: "//source: KACTL\n\n/**\n * Author: Lucian Bicsi\n * Date: 2015-06-25\n *\
    \ License: GNU Free Documentation License 1.2\n * Source: csacademy\n * Description:\
    \ Transform to a basis with fast convolutions of the form\n * $\\displaystyle\
    \ c[z] = \\sum\\nolimits_{z = x \\oplus y} a[x] \\cdot b[y]$,\n * where $\\oplus$\
    \ is one of AND, OR, XOR. The size of $a$ must be a power of two.\n * Time: O(N\
    \ \\log N)\n * Status: stress-tested\n */\n\ntemplate<class T>\nvoid FST(vector<T>&\
    \ a, bool inv) {\n\tfor (int n = sz(a), step = 1; step < n; step *= 2) {\n\t\t\
    for (int i = 0; i < n; i += 2 * step) rep(j,i,i+step) {\n\t\t\tT &u = a[j], &v\
    \ = a[j + step]; tie(u, v) =\n\t\t\t\t//inv ? pii(v - u, u) : pii(v, u + v); //\
    \ AND\n\t\t\t\t// inv ? pii(v, u - v) : pii(u + v, u); // OR /// include-line\n\
    \t\t\t\tpair<T, T>(u + v, u - v);                   // XOR /// include-line\n\t\
    \t}\n\t}\n\t if (inv) for (T& x : a) x /= sz(a); // XOR only /// include-line\n\
    }\n\ntemplate<class T>\nvector<T> conv(vector<T> a, vector<T> b) {\n\tFST(a, 0);\
    \ FST(b, 0);\n\trep(i,0,sz(a)) a[i] *= b[i];\n\tFST(a, 1); return a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/FWHT.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: setfunc/FWHT.cpp
layout: document
redirect_from:
- /library/setfunc/FWHT.cpp
- /library/setfunc/FWHT.cpp.html
title: setfunc/FWHT.cpp
---
