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
  bundledCode: "#line 1 \"ds/CHT.cpp\"\nusing ldb = long double;\nstruct line {\n\
    \  ldb m, b;\n  ldb inter(line l) { return (b - l.b) / (l.m - m); }\n};\n\nvector<line>\
    \ build_hull(vector<line> v) {\n  {\n    ranges::sort(v, {}, [](line &l) { return\
    \ pair(-l.m, l.b); });\n    vector<line> tmp;\n    for(int i = 0, j = 0; i < ssize(v);\
    \ i = j) {\n      while(j < ssize(v) and v[i].m == v[j].m) j++;\n      tmp.emplace_back(v[i]);\n\
    \    }\n    v.swap(tmp);\n  }\n  vector<line> h;\n  for(auto l : v) {\n    while(ssize(h)\
    \ >= 2 and l.inter(end(h)[-2]) <= h.back().inter(end(h)[-2]))\n      h.pop_back();\n\
    \    h.emplace_back(l);\n  }\n  return h;\n}\n\nldb query_hull(vector<line> &h,\
    \ ldb x) {\n  auto pred = [&](int i) { return h[i].inter(h[i + 1]) < x; };\n \
    \ int i = *ranges::partition_point(views::iota(0, ssize(h) - 1), pred);\n  return\
    \ h[i].m * x + h[i].b;\n}\n"
  code: "using ldb = long double;\nstruct line {\n  ldb m, b;\n  ldb inter(line l)\
    \ { return (b - l.b) / (l.m - m); }\n};\n\nvector<line> build_hull(vector<line>\
    \ v) {\n  {\n    ranges::sort(v, {}, [](line &l) { return pair(-l.m, l.b); });\n\
    \    vector<line> tmp;\n    for(int i = 0, j = 0; i < ssize(v); i = j) {\n   \
    \   while(j < ssize(v) and v[i].m == v[j].m) j++;\n      tmp.emplace_back(v[i]);\n\
    \    }\n    v.swap(tmp);\n  }\n  vector<line> h;\n  for(auto l : v) {\n    while(ssize(h)\
    \ >= 2 and l.inter(end(h)[-2]) <= h.back().inter(end(h)[-2]))\n      h.pop_back();\n\
    \    h.emplace_back(l);\n  }\n  return h;\n}\n\nldb query_hull(vector<line> &h,\
    \ ldb x) {\n  auto pred = [&](int i) { return h[i].inter(h[i + 1]) < x; };\n \
    \ int i = *ranges::partition_point(views::iota(0, ssize(h) - 1), pred);\n  return\
    \ h[i].m * x + h[i].b;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/CHT.cpp
  requiredBy: []
  timestamp: '2025-03-22 00:42:23+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/CHT.cpp
layout: document
redirect_from:
- /library/ds/CHT.cpp
- /library/ds/CHT.cpp.html
title: ds/CHT.cpp
---
