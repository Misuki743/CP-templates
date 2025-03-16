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
  bundledCode: "#line 1 \"geometry/manhattanMST.cpp\"\ntypedef Point<int> P;\nvector<array<int,\
    \ 3>> manhattanMST(vector<P> ps) {\n\tvi id(sz(ps));\n\tiota(all(id), 0);\n\t\
    vector<array<int, 3>> edges;\n\trep(k,0,4) {\n\t\tsort(all(id), [&](int i, int\
    \ j) {\n\t\t     return (ps[i]-ps[j]).x < (ps[j]-ps[i]).y;});\n\t\tmap<int, int>\
    \ sweep;\n\t\tfor (int i : id) {\n\t\t\tfor (auto it = sweep.lower_bound(-ps[i].y);\n\
    \t\t\t\t        it != sweep.end(); sweep.erase(it++)) {\n\t\t\t\tint j = it->second;\n\
    \t\t\t\tP d = ps[i] - ps[j];\n\t\t\t\tif (d.y > d.x) break;\n\t\t\t\tedges.push_back({d.y\
    \ + d.x, i, j});\n\t\t\t}\n\t\t\tsweep[-ps[i].y] = i;\n\t\t}\n\t\tfor (P& p :\
    \ ps) if (k & 1) p.x = -p.x; else swap(p.x, p.y);\n\t}\n\treturn edges;\n}\n"
  code: "typedef Point<int> P;\nvector<array<int, 3>> manhattanMST(vector<P> ps) {\n\
    \tvi id(sz(ps));\n\tiota(all(id), 0);\n\tvector<array<int, 3>> edges;\n\trep(k,0,4)\
    \ {\n\t\tsort(all(id), [&](int i, int j) {\n\t\t     return (ps[i]-ps[j]).x <\
    \ (ps[j]-ps[i]).y;});\n\t\tmap<int, int> sweep;\n\t\tfor (int i : id) {\n\t\t\t\
    for (auto it = sweep.lower_bound(-ps[i].y);\n\t\t\t\t        it != sweep.end();\
    \ sweep.erase(it++)) {\n\t\t\t\tint j = it->second;\n\t\t\t\tP d = ps[i] - ps[j];\n\
    \t\t\t\tif (d.y > d.x) break;\n\t\t\t\tedges.push_back({d.y + d.x, i, j});\n\t\
    \t\t}\n\t\t\tsweep[-ps[i].y] = i;\n\t\t}\n\t\tfor (P& p : ps) if (k & 1) p.x =\
    \ -p.x; else swap(p.x, p.y);\n\t}\n\treturn edges;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/manhattanMST.cpp
  requiredBy: []
  timestamp: '2025-03-16 20:32:54+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/manhattanMST.cpp
layout: document
redirect_from:
- /library/geometry/manhattanMST.cpp
- /library/geometry/manhattanMST.cpp.html
title: geometry/manhattanMST.cpp
---
