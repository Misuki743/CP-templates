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
  bundledCode: "#line 1 \"comb.cpp\"\n/**\n * template name: comb\n * author: Misuki\n\
    \ * last update: 2023/01/22\n * note: remember to call init() before using it.\n\
    \ */\n\nconst int MAX = 2000001;\nmint fac[MAX], facInv[MAX];\nvoid init() {\n\
    \  fac[0] = 1;\n  for(int i = 1; i < MAX; i++)\n    fac[i] = fac[i - 1] * i;\n\
    \  facInv[MAX - 1] = 1 / fac[MAX - 1];\n  for(int i = MAX - 2; i >= 0; i--)\n\
    \    facInv[i] = facInv[i + 1] * (i + 1);\n}\n\nmint C(int a, int b) {\n  if (b\
    \ < 0 or a < b)\n    return 0;\n  else\n    return fac[a] * facInv[b] * facInv[a\
    \ - b];\n}\n"
  code: "/**\n * template name: comb\n * author: Misuki\n * last update: 2023/01/22\n\
    \ * note: remember to call init() before using it.\n */\n\nconst int MAX = 2000001;\n\
    mint fac[MAX], facInv[MAX];\nvoid init() {\n  fac[0] = 1;\n  for(int i = 1; i\
    \ < MAX; i++)\n    fac[i] = fac[i - 1] * i;\n  facInv[MAX - 1] = 1 / fac[MAX -\
    \ 1];\n  for(int i = MAX - 2; i >= 0; i--)\n    facInv[i] = facInv[i + 1] * (i\
    \ + 1);\n}\n\nmint C(int a, int b) {\n  if (b < 0 or a < b)\n    return 0;\n \
    \ else\n    return fac[a] * facInv[b] * facInv[a - b];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: comb.cpp
  requiredBy: []
  timestamp: '2023-06-16 02:10:58+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: comb.cpp
layout: document
redirect_from:
- /library/comb.cpp
- /library/comb.cpp.html
title: comb.cpp
---
