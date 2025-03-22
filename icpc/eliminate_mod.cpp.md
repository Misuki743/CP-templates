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
  bundledCode: "#line 1 \"icpc/eliminate_mod.cpp\"\n//rank: size(prs), det: full_rank\
    \ ? sgn : 0\n//inv(LI): L == identity ? R : -1\n//Ax=b(Ab): b is pivot col ? -1\
    \ : x[c] = M[prs[i]].back\n//where c is pivot column of row prs[i]\n\nconst int\
    \ mod = 998244353;\nauto eliminate(vector<vector<int>> M) {\n  int n = ssize(M),\
    \ m = M.empty() ? 0 : ssize(M[0]), sgn = 1;\n  vector<int> prs;\n  for(int r =\
    \ 0, c = 0; r < n and c < m; c++) {\n    int pr = r;\n    while(pr < n and M[pr][c]\
    \ == 0) pr++;\n    if (pr == n) continue;\n    prs.emplace_back(r);\n    if (r\
    \ != pr)\n      M[r].swap(M[pr]), sgn = (mod - sgn) % mod;\n    ll inv = 1, b\
    \ = M[r][c];\n    sgn = (ll)sgn * b % mod;\n    for(int i = 0; i < 30; i++, b\
    \ = b * b % mod)\n      if ((mod - 2) >> i & 1)\n        inv = inv * b % mod;\n\
    \    for(int i = 0; i < m; i++)\n      M[r][i] = M[r][i] * inv % mod;\n    for(int\
    \ i = 0; i < n; i++) {\n      if (i == r or M[i][c] == 0) continue;\n      ll\
    \ x = M[i][c];\n      for(int j = c; j < m; j++)\n        M[i][j] = (M[i][j] +\
    \ mod - M[r][j] * x % mod) % mod;\n    }\n    r++;\n  }\n  return tuple(M, prs,\
    \ sgn);\n}\n"
  code: "//rank: size(prs), det: full_rank ? sgn : 0\n//inv(LI): L == identity ? R\
    \ : -1\n//Ax=b(Ab): b is pivot col ? -1 : x[c] = M[prs[i]].back\n//where c is\
    \ pivot column of row prs[i]\n\nconst int mod = 998244353;\nauto eliminate(vector<vector<int>>\
    \ M) {\n  int n = ssize(M), m = M.empty() ? 0 : ssize(M[0]), sgn = 1;\n  vector<int>\
    \ prs;\n  for(int r = 0, c = 0; r < n and c < m; c++) {\n    int pr = r;\n   \
    \ while(pr < n and M[pr][c] == 0) pr++;\n    if (pr == n) continue;\n    prs.emplace_back(r);\n\
    \    if (r != pr)\n      M[r].swap(M[pr]), sgn = (mod - sgn) % mod;\n    ll inv\
    \ = 1, b = M[r][c];\n    sgn = (ll)sgn * b % mod;\n    for(int i = 0; i < 30;\
    \ i++, b = b * b % mod)\n      if ((mod - 2) >> i & 1)\n        inv = inv * b\
    \ % mod;\n    for(int i = 0; i < m; i++)\n      M[r][i] = M[r][i] * inv % mod;\n\
    \    for(int i = 0; i < n; i++) {\n      if (i == r or M[i][c] == 0) continue;\n\
    \      ll x = M[i][c];\n      for(int j = c; j < m; j++)\n        M[i][j] = (M[i][j]\
    \ + mod - M[r][j] * x % mod) % mod;\n    }\n    r++;\n  }\n  return tuple(M, prs,\
    \ sgn);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: icpc/eliminate_mod.cpp
  requiredBy: []
  timestamp: '2025-03-22 15:11:28+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc/eliminate_mod.cpp
layout: document
redirect_from:
- /library/icpc/eliminate_mod.cpp
- /library/icpc/eliminate_mod.cpp.html
title: icpc/eliminate_mod.cpp
---
