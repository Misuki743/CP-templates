---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/static_convex_hull.test.cpp
    title: test/static_convex_hull.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/convex_hull.cpp\"\n//Returns a vector of the points\
    \ of the convex hull in counter-clockwise order.\ntypedef Point<ll> P;\nvector<P>\
    \ convexHull(vector<P> pts) {\n  if (sz(pts) <= 1) return pts;\n  sort(all(pts));\n\
    \  vector<P> h(sz(pts)+1);\n  int s = 0, t = 0;\n  for (int it = 2; it--; s =\
    \ --t, reverse(all(pts)))\n    for (P p : pts) {\n      while (t >= s + 2 && h[t-2].cross(h[t-1],\
    \ p) <= 0) t--;\n      h[t++] = p;\n    }\n  return {h.begin(), h.begin() + t\
    \ - (t == 2 && h[0] == h[1])};\n}\n"
  code: "//Returns a vector of the points of the convex hull in counter-clockwise\
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
  timestamp: '2025-03-16 20:37:06+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/static_convex_hull.test.cpp
documentation_of: geometry/convex_hull.cpp
layout: document
redirect_from:
- /library/geometry/convex_hull.cpp
- /library/geometry/convex_hull.cpp.html
title: geometry/convex_hull.cpp
---
