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
  bundledCode: "#line 1 \"combi/comb.cpp\"\n// note: remember to call init() before\
    \ using it.\n\nconst int MAX = 2000001;\nmint fac[MAX], facInv[MAX];\nvoid init()\
    \ {\n  fac[0] = 1;\n  for(int i = 1; i < MAX; i++)\n    fac[i] = fac[i - 1] *\
    \ i;\n  facInv[MAX - 1] = 1 / fac[MAX - 1];\n  for(int i = MAX - 2; i >= 0; i--)\n\
    \    facInv[i] = facInv[i + 1] * (i + 1);\n}\n\nmint C(int a, int b) {\n  if (b\
    \ < 0 or a < b)\n    return 0;\n  else\n    return fac[a] * facInv[b] * facInv[a\
    \ - b];\n}\n"
  code: "// note: remember to call init() before using it.\n\nconst int MAX = 2000001;\n\
    mint fac[MAX], facInv[MAX];\nvoid init() {\n  fac[0] = 1;\n  for(int i = 1; i\
    \ < MAX; i++)\n    fac[i] = fac[i - 1] * i;\n  facInv[MAX - 1] = 1 / fac[MAX -\
    \ 1];\n  for(int i = MAX - 2; i >= 0; i--)\n    facInv[i] = facInv[i + 1] * (i\
    \ + 1);\n}\n\nmint C(int a, int b) {\n  if (b < 0 or a < b)\n    return 0;\n \
    \ else\n    return fac[a] * facInv[b] * facInv[a - b];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: combi/comb.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: combi/comb.cpp
layout: document
redirect_from:
- /library/combi/comb.cpp
- /library/combi/comb.cpp.html
title: combi/comb.cpp
---
