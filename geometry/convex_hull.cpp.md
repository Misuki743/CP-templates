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
    \ convexHull(vector<P> pts) {\n\tif (sz(pts) <= 1) return pts;\n\tsort(all(pts));\n\
    \tvector<P> h(sz(pts)+1);\n\tint s = 0, t = 0;\n\tfor (int it = 2; it--; s = --t,\
    \ reverse(all(pts)))\n\t\tfor (P p : pts) {\n\t\t\twhile (t >= s + 2 && h[t-2].cross(h[t-1],\
    \ p) <= 0) t--;\n\t\t\th[t++] = p;\n\t\t}\n\treturn {h.begin(), h.begin() + t\
    \ - (t == 2 && h[0] == h[1])};\n}\n"
  code: "//Returns a vector of the points of the convex hull in counter-clockwise\
    \ order.\ntypedef Point<ll> P;\nvector<P> convexHull(vector<P> pts) {\n\tif (sz(pts)\
    \ <= 1) return pts;\n\tsort(all(pts));\n\tvector<P> h(sz(pts)+1);\n\tint s = 0,\
    \ t = 0;\n\tfor (int it = 2; it--; s = --t, reverse(all(pts)))\n\t\tfor (P p :\
    \ pts) {\n\t\t\twhile (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;\n\t\t\t\
    h[t++] = p;\n\t\t}\n\treturn {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/convex_hull.cpp
  requiredBy: []
  timestamp: '2025-03-16 20:32:54+08:00'
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
