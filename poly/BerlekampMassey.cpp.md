---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/find_linear_recurrence.test.cpp
    title: test/find_linear_recurrence.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/BerlekampMassey.cpp\"\nvector<mint> BerlekampMassey(vector<mint>\
    \ s) {\n  vector<mint> c(1, 0), oldC(1, 0);\n  int f = -1;\n  for(int i = 0; i\
    \ < ssize(s); i++) {\n    mint delta = s[i];\n    for(int j = 1; j < ssize(c);\
    \ j++)\n      delta -= s[i - j] * c[j];\n\n    if (delta == 0) continue;\n\n \
    \   if (f == -1) {\n      f = i;\n      c.resize(i + 2, 0);\n    } else {\n  \
    \    vector<mint> d = oldC;\n      int fp = f;\n      if (i - ssize(c) > f - ssize(oldC))\n\
    \        oldC = c, fp = i;\n      for(mint &x : d)\n        x *= -1;\n      d.insert(d.begin()\
    \ + 1, 1);\n      mint div = 0;\n      for(int j = 1; j < ssize(d); j++)\n   \
    \     div += s[f - j + 1] * d[j];\n      mint coef = delta / div;\n      for(mint\
    \ &x : d)\n        x *= coef;\n      d.insert(d.begin() + 1, i - f - 1, 0);\n\
    \      if (ssize(c) < ssize(d))\n        c.resize(d.size(), 0);\n      for(int\
    \ j = 1; j < ssize(d); j++)\n        c[j] += d[j];\n      f = fp;\n    }\n  }\n\
    \n  return c;\n}\n"
  code: "vector<mint> BerlekampMassey(vector<mint> s) {\n  vector<mint> c(1, 0), oldC(1,\
    \ 0);\n  int f = -1;\n  for(int i = 0; i < ssize(s); i++) {\n    mint delta =\
    \ s[i];\n    for(int j = 1; j < ssize(c); j++)\n      delta -= s[i - j] * c[j];\n\
    \n    if (delta == 0) continue;\n\n    if (f == -1) {\n      f = i;\n      c.resize(i\
    \ + 2, 0);\n    } else {\n      vector<mint> d = oldC;\n      int fp = f;\n  \
    \    if (i - ssize(c) > f - ssize(oldC))\n        oldC = c, fp = i;\n      for(mint\
    \ &x : d)\n        x *= -1;\n      d.insert(d.begin() + 1, 1);\n      mint div\
    \ = 0;\n      for(int j = 1; j < ssize(d); j++)\n        div += s[f - j + 1] *\
    \ d[j];\n      mint coef = delta / div;\n      for(mint &x : d)\n        x *=\
    \ coef;\n      d.insert(d.begin() + 1, i - f - 1, 0);\n      if (ssize(c) < ssize(d))\n\
    \        c.resize(d.size(), 0);\n      for(int j = 1; j < ssize(d); j++)\n   \
    \     c[j] += d[j];\n      f = fp;\n    }\n  }\n\n  return c;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/BerlekampMassey.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/find_linear_recurrence.test.cpp
documentation_of: poly/BerlekampMassey.cpp
layout: document
redirect_from:
- /library/poly/BerlekampMassey.cpp
- /library/poly/BerlekampMassey.cpp.html
title: poly/BerlekampMassey.cpp
---