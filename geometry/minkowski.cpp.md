---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://cp-algorithms.com/geometry/minkowski.html#implementation
  bundledCode: "#line 1 \"geometry/minkowski.cpp\"\n//source: https://cp-algorithms.com/geometry/minkowski.html#implementation\n\
    \ntemplate<class pt>\nvoid reorder_polygon(vector<pt> & P){\n  size_t pos = 0;\n\
    \  for(size_t i = 1; i < P.size(); i++){\n    if(P[i].y < P[pos].y || (P[i].y\
    \ == P[pos].y && P[i].x < P[pos].x))\n      pos = i;\n  }\n  rotate(P.begin(),\
    \ P.begin() + pos, P.end());\n}\n\ntemplate<class pt>\nvector<pt> minkowski(vector<pt>\
    \ P, vector<pt> Q){\n  reorder_polygon(P);\n  reorder_polygon(Q);\n  P.push_back(P[0]);\n\
    \  P.push_back(P[1]);\n  Q.push_back(Q[0]);\n  Q.push_back(Q[1]);\n  vector<pt>\
    \ result;\n  size_t i = 0, j = 0;\n  while(i < P.size() - 2 || j < Q.size() -\
    \ 2){\n    result.push_back(P[i] + Q[j]);\n    auto cross = (P[i + 1] - P[i]).cross(Q[j\
    \ + 1] - Q[j]);\n    if(cross >= 0 && i < P.size() - 2)\n      ++i;\n    if(cross\
    \ <= 0 && j < Q.size() - 2)\n      ++j;\n  }\n  return result;\n}\n"
  code: "//source: https://cp-algorithms.com/geometry/minkowski.html#implementation\n\
    \ntemplate<class pt>\nvoid reorder_polygon(vector<pt> & P){\n  size_t pos = 0;\n\
    \  for(size_t i = 1; i < P.size(); i++){\n    if(P[i].y < P[pos].y || (P[i].y\
    \ == P[pos].y && P[i].x < P[pos].x))\n      pos = i;\n  }\n  rotate(P.begin(),\
    \ P.begin() + pos, P.end());\n}\n\ntemplate<class pt>\nvector<pt> minkowski(vector<pt>\
    \ P, vector<pt> Q){\n  reorder_polygon(P);\n  reorder_polygon(Q);\n  P.push_back(P[0]);\n\
    \  P.push_back(P[1]);\n  Q.push_back(Q[0]);\n  Q.push_back(Q[1]);\n  vector<pt>\
    \ result;\n  size_t i = 0, j = 0;\n  while(i < P.size() - 2 || j < Q.size() -\
    \ 2){\n    result.push_back(P[i] + Q[j]);\n    auto cross = (P[i + 1] - P[i]).cross(Q[j\
    \ + 1] - Q[j]);\n    if(cross >= 0 && i < P.size() - 2)\n      ++i;\n    if(cross\
    \ <= 0 && j < Q.size() - 2)\n      ++j;\n  }\n  return result;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/minkowski.cpp
  requiredBy: []
  timestamp: '2025-03-21 23:27:46+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/minkowski.cpp
layout: document
redirect_from:
- /library/geometry/minkowski.cpp
- /library/geometry/minkowski.cpp.html
title: geometry/minkowski.cpp
---
