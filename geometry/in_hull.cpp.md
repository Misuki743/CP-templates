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
  bundledCode: "#line 1 \"geometry/in_hull.cpp\"\n//soucre: KACTL\ntemplate<class\
    \ P>\nint sideOf(P s, P e, P p) { return sgn(s.cross(e, p)); }\n\ntemplate<class\
    \ P>\nint sideOf(const P& s, const P& e, const P& p, double eps) {\n\tauto a =\
    \ (e-s).cross(p-s);\n\tdouble l = (e-s).dist()*eps;\n\treturn (a > l) - (a < -l);\n\
    }\n\ntypedef Point<ll> P;\n\nbool inHull(const vector<P>& l, P p, bool strict\
    \ = true) {\n\tint a = 1, b = sz(l) - 1, r = !strict;\n\tif (sz(l) < 3) return\
    \ r && onSegment(l[0], l.back(), p);\n\tif (sideOf(l[0], l[a], l[b]) > 0) swap(a,\
    \ b);\n\tif (sideOf(l[0], l[a], p) >= r || sideOf(l[0], l[b], p)<= -r)\n\t\treturn\
    \ false;\n\twhile (abs(a - b) > 1) {\n\t\tint c = (a + b) / 2;\n\t\t(sideOf(l[0],\
    \ l[c], p) > 0 ? b : a) = c;\n\t}\n\treturn sgn(l[a].cross(l[b], p)) < r;\n}\n"
  code: "//soucre: KACTL\ntemplate<class P>\nint sideOf(P s, P e, P p) { return sgn(s.cross(e,\
    \ p)); }\n\ntemplate<class P>\nint sideOf(const P& s, const P& e, const P& p,\
    \ double eps) {\n\tauto a = (e-s).cross(p-s);\n\tdouble l = (e-s).dist()*eps;\n\
    \treturn (a > l) - (a < -l);\n}\n\ntypedef Point<ll> P;\n\nbool inHull(const vector<P>&\
    \ l, P p, bool strict = true) {\n\tint a = 1, b = sz(l) - 1, r = !strict;\n\t\
    if (sz(l) < 3) return r && onSegment(l[0], l.back(), p);\n\tif (sideOf(l[0], l[a],\
    \ l[b]) > 0) swap(a, b);\n\tif (sideOf(l[0], l[a], p) >= r || sideOf(l[0], l[b],\
    \ p)<= -r)\n\t\treturn false;\n\twhile (abs(a - b) > 1) {\n\t\tint c = (a + b)\
    \ / 2;\n\t\t(sideOf(l[0], l[c], p) > 0 ? b : a) = c;\n\t}\n\treturn sgn(l[a].cross(l[b],\
    \ p)) < r;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/in_hull.cpp
  requiredBy: []
  timestamp: '2025-03-21 23:27:46+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/in_hull.cpp
layout: document
redirect_from:
- /library/geometry/in_hull.cpp
- /library/geometry/in_hull.cpp.html
title: geometry/in_hull.cpp
---
