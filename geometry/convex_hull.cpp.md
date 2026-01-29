---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/static_convex_hull.test.cpp
    title: test/static_convex_hull.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/convex_hull.cpp\"\n//soucre: KACTL\n//Returns a\
    \ vector of the points of the convex hull in counter-clockwise order.\ntypedef\
    \ Point<ll> P;\nvector<P> convexHull(vector<P> pts) {\n  if (sz(pts) <= 1) return\
    \ pts;\n  sort(all(pts));\n  vector<P> h(sz(pts)+1);\n  int s = 0, t = 0;\n  for\
    \ (int it = 2; it--; s = --t, reverse(all(pts)))\n    for (P p : pts) {\n    \
    \  while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;\n      h[t++] = p;\n\
    \    }\n  return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};\n}\n"
  code: "//soucre: KACTL\n//Returns a vector of the points of the convex hull in counter-clockwise\
    \ order.\ntypedef Point<ll> P;\nvector<P> convexHull(vector<P> pts) {\n  if (sz(pts)\
    \ <= 1) return pts;\n  sort(all(pts));\n  vector<P> h(sz(pts)+1);\n  int s = 0,\
    \ t = 0;\n  for (int it = 2; it--; s = --t, reverse(all(pts)))\n    for (P p :\
    \ pts) {\n      while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;\n    \
    \  h[t++] = p;\n    }\n  return {h.begin(), h.begin() + t - (t == 2 && h[0] ==\
    \ h[1])};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/convex_hull.cpp
  requiredBy: []
  timestamp: '2025-03-17 19:48:27+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/static_convex_hull.test.cpp
documentation_of: geometry/convex_hull.cpp
layout: document
redirect_from:
- /library/geometry/convex_hull.cpp
- /library/geometry/convex_hull.cpp.html
title: geometry/convex_hull.cpp
---
