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
  bundledCode: "#line 1 \"geometry/manhattanMST.cpp\"\n//source:KACTL\n\ntypedef Point<int>\
    \ P;\nvector<array<int, 3>> manhattanMST(vector<P> ps) {\n  vi id(sz(ps));\n \
    \ iota(all(id), 0);\n  vector<array<int, 3>> edges;\n  rep(k,0,4) {\n    sort(all(id),\
    \ [&](int i, int j) {\n         return (ps[i]-ps[j]).x < (ps[j]-ps[i]).y;});\n\
    \    map<int, int> sweep;\n    for (int i : id) {\n      for (auto it = sweep.lower_bound(-ps[i].y);\n\
    \                it != sweep.end(); sweep.erase(it++)) {\n        int j = it->second;\n\
    \        P d = ps[i] - ps[j];\n        if (d.y > d.x) break;\n        edges.push_back({d.y\
    \ + d.x, i, j});\n      }\n      sweep[-ps[i].y] = i;\n    }\n    for (P& p :\
    \ ps) if (k & 1) p.x = -p.x; else swap(p.x, p.y);\n  }\n  return edges;\n}\n"
  code: "//source:KACTL\n\ntypedef Point<int> P;\nvector<array<int, 3>> manhattanMST(vector<P>\
    \ ps) {\n  vi id(sz(ps));\n  iota(all(id), 0);\n  vector<array<int, 3>> edges;\n\
    \  rep(k,0,4) {\n    sort(all(id), [&](int i, int j) {\n         return (ps[i]-ps[j]).x\
    \ < (ps[j]-ps[i]).y;});\n    map<int, int> sweep;\n    for (int i : id) {\n  \
    \    for (auto it = sweep.lower_bound(-ps[i].y);\n                it != sweep.end();\
    \ sweep.erase(it++)) {\n        int j = it->second;\n        P d = ps[i] - ps[j];\n\
    \        if (d.y > d.x) break;\n        edges.push_back({d.y + d.x, i, j});\n\
    \      }\n      sweep[-ps[i].y] = i;\n    }\n    for (P& p : ps) if (k & 1) p.x\
    \ = -p.x; else swap(p.x, p.y);\n  }\n  return edges;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/manhattanMST.cpp
  requiredBy: []
  timestamp: '2025-03-17 19:48:27+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/manhattanMST.cpp
layout: document
redirect_from:
- /library/geometry/manhattanMST.cpp
- /library/geometry/manhattanMST.cpp.html
title: geometry/manhattanMST.cpp
---
