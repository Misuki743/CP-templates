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
  bundledCode: "#line 1 \"icpc/eliminate_mod2.cpp\"\ntemplate<uint32_t m_max = 1>\n\
    pair<vector<string>, vector<int>> eliminate(vector<string> M) {\n  if (m_max <\
    \ size(M[0]))\n    return eliminate<min(m_max << 1, 1u << 13)>(std::move(M));\n\
    \  int n = ssize(M), m = ssize(M[0]);\n  vector<bitset<m_max>> N;\n  for(auto\
    \ &s : M) {\n    ranges::reverse(s);\n    N.emplace_back(s);\n  }\n  vector<int>\
    \ prs;\n  for(int r = 0, c = 0; r < n and c < m; c++) {\n    int pr = r;\n   \
    \ while(pr < n and !N[pr][c]) pr++;\n    if (pr == n) continue;\n    prs.emplace_back(r);\n\
    \    if (r != pr) swap(N[r], N[pr]);\n    for(int i = 0; i < n; i++)\n      if\
    \ (i != r and N[i][c])\n        N[i] ^= N[r];\n    r++;\n  }\n  for(int i = 0;\
    \ i < n; i++) {\n    string s = N[i].to_string().substr(m_max - m);\n    ranges::reverse(s);\n\
    \    M[i] = s;\n  }\n  return pair(M, prs);\n}\n"
  code: "template<uint32_t m_max = 1>\npair<vector<string>, vector<int>> eliminate(vector<string>\
    \ M) {\n  if (m_max < size(M[0]))\n    return eliminate<min(m_max << 1, 1u <<\
    \ 13)>(std::move(M));\n  int n = ssize(M), m = ssize(M[0]);\n  vector<bitset<m_max>>\
    \ N;\n  for(auto &s : M) {\n    ranges::reverse(s);\n    N.emplace_back(s);\n\
    \  }\n  vector<int> prs;\n  for(int r = 0, c = 0; r < n and c < m; c++) {\n  \
    \  int pr = r;\n    while(pr < n and !N[pr][c]) pr++;\n    if (pr == n) continue;\n\
    \    prs.emplace_back(r);\n    if (r != pr) swap(N[r], N[pr]);\n    for(int i\
    \ = 0; i < n; i++)\n      if (i != r and N[i][c])\n        N[i] ^= N[r];\n   \
    \ r++;\n  }\n  for(int i = 0; i < n; i++) {\n    string s = N[i].to_string().substr(m_max\
    \ - m);\n    ranges::reverse(s);\n    M[i] = s;\n  }\n  return pair(M, prs);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: icpc/eliminate_mod2.cpp
  requiredBy: []
  timestamp: '2025-03-22 15:11:28+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc/eliminate_mod2.cpp
layout: document
redirect_from:
- /library/icpc/eliminate_mod2.cpp
- /library/icpc/eliminate_mod2.cpp.html
title: icpc/eliminate_mod2.cpp
---
