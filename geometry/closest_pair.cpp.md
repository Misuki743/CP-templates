---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/closest_pair.test.cpp
    title: test/closest_pair.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/closest_pair.cpp\"\ntypedef Point<ll> P;\npair<P,\
    \ P> closest(vector<P> v) {\n  assert(sz(v) > 1);\n  set<P> S;\n  sort(all(v),\
    \ [](P a, P b) { return a.y < b.y; });\n  pair<ll, pair<P, P>> ret{LLONG_MAX,\
    \ {P(), P()}};\n  int j = 0;\n  for (P p : v) {\n    P d{1 + (ll)sqrt(ret.first),\
    \ 0};\n    while (v[j].y <= p.y - d.x) S.erase(v[j++]);\n    auto lo = S.lower_bound(p\
    \ - d), hi = S.upper_bound(p + d);\n    for (; lo != hi; ++lo)\n      ret = min(ret,\
    \ {(*lo - p).dist2(), {*lo, p}});\n    S.insert(p);\n  }\n  return ret.second;\n\
    }\n"
  code: "typedef Point<ll> P;\npair<P, P> closest(vector<P> v) {\n  assert(sz(v) >\
    \ 1);\n  set<P> S;\n  sort(all(v), [](P a, P b) { return a.y < b.y; });\n  pair<ll,\
    \ pair<P, P>> ret{LLONG_MAX, {P(), P()}};\n  int j = 0;\n  for (P p : v) {\n \
    \   P d{1 + (ll)sqrt(ret.first), 0};\n    while (v[j].y <= p.y - d.x) S.erase(v[j++]);\n\
    \    auto lo = S.lower_bound(p - d), hi = S.upper_bound(p + d);\n    for (; lo\
    \ != hi; ++lo)\n      ret = min(ret, {(*lo - p).dist2(), {*lo, p}});\n    S.insert(p);\n\
    \  }\n  return ret.second;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/closest_pair.cpp
  requiredBy: []
  timestamp: '2025-03-16 20:37:06+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/closest_pair.test.cpp
documentation_of: geometry/closest_pair.cpp
layout: document
redirect_from:
- /library/geometry/closest_pair.cpp
- /library/geometry/closest_pair.cpp.html
title: geometry/closest_pair.cpp
---
