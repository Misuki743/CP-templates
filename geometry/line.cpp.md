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
  bundledCode: "#line 1 \"geometry/line.cpp\"\n//source: KACTL\n\ntemplate<class P>\
    \ bool onSegment(P s, P e, P p) {\n  return p.cross(s, e) == 0 && (s - p).dot(e\
    \ - p) <= 0;\n} //Use segDist(s,e,p)<=epsilon instead when using Point<double>.\n\
    \ntemplate<class P>\nP lineProj(P a, P b, P p, bool refl=false) {\n  P v = b -\
    \ a;\n  return p - v.perp()*(1+refl)*v.cross(p-a)/v.dist2();\n}\n\ntemplate<class\
    \ P> vector<P> segInter(P a, P b, P c, P d) {\n  auto oa = c.cross(d, a), ob =\
    \ c.cross(d, b),\n       oc = a.cross(b, c), od = a.cross(b, d);\n  // Checks\
    \ if intersection is single non-endpoint point.\n  if (sgn(oa) * sgn(ob) < 0 &&\
    \ sgn(oc) * sgn(od) < 0)\n    return {(a * ob - b * oa) / (ob - oa)};\n  set<P>\
    \ s;\n  if (onSegment(c, d, a)) s.insert(a);\n  if (onSegment(c, d, b)) s.insert(b);\n\
    \  if (onSegment(a, b, c)) s.insert(c);\n  if (onSegment(a, b, d)) s.insert(d);\n\
    \  return {all(s)};\n}\n\ntypedef Point<double> P;\ndouble segDist(P& s, P& e,\
    \ P& p) {\n  if (s==e) return (p-s).dist();\n  auto d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));\n\
    \  return ((p-s)*d-(e-s)*t).dist()/d;\n}\n\ntemplate<class P>\ndouble lineDist(const\
    \ P& a, const P& b, const P& p) {\n  return (double)(b-a).cross(p-a)/(b-a).dist();\n\
    } //signed distance\n\n//If a unique intersection point of the lines going through\
    \ s1,e1 and s2,e2 exists \\{1, point\\} is returned.\n//If no intersection point\
    \ exists \\{0, (0,0)\\} is returned and if infinitely many exists \\{-1, (0,0)\\\
    } is returned.\ntemplate<class P>\npair<int, P> lineInter(P s1, P e1, P s2, P\
    \ e2) {\n  auto d = (e1 - s1).cross(e2 - s2);\n  if (d == 0) // if parallel\n\
    \    return {-(s1.cross(e1, s2) == 0), P(0, 0)};\n  auto p = s2.cross(e1, e2),\
    \ q = s2.cross(e2, s1);\n  return {1, (s1 * p + e1 * q) / d};\n}\n"
  code: "//source: KACTL\n\ntemplate<class P> bool onSegment(P s, P e, P p) {\n  return\
    \ p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;\n} //Use segDist(s,e,p)<=epsilon\
    \ instead when using Point<double>.\n\ntemplate<class P>\nP lineProj(P a, P b,\
    \ P p, bool refl=false) {\n  P v = b - a;\n  return p - v.perp()*(1+refl)*v.cross(p-a)/v.dist2();\n\
    }\n\ntemplate<class P> vector<P> segInter(P a, P b, P c, P d) {\n  auto oa = c.cross(d,\
    \ a), ob = c.cross(d, b),\n       oc = a.cross(b, c), od = a.cross(b, d);\n  //\
    \ Checks if intersection is single non-endpoint point.\n  if (sgn(oa) * sgn(ob)\
    \ < 0 && sgn(oc) * sgn(od) < 0)\n    return {(a * ob - b * oa) / (ob - oa)};\n\
    \  set<P> s;\n  if (onSegment(c, d, a)) s.insert(a);\n  if (onSegment(c, d, b))\
    \ s.insert(b);\n  if (onSegment(a, b, c)) s.insert(c);\n  if (onSegment(a, b,\
    \ d)) s.insert(d);\n  return {all(s)};\n}\n\ntypedef Point<double> P;\ndouble\
    \ segDist(P& s, P& e, P& p) {\n  if (s==e) return (p-s).dist();\n  auto d = (e-s).dist2(),\
    \ t = min(d,max(.0,(p-s).dot(e-s)));\n  return ((p-s)*d-(e-s)*t).dist()/d;\n}\n\
    \ntemplate<class P>\ndouble lineDist(const P& a, const P& b, const P& p) {\n \
    \ return (double)(b-a).cross(p-a)/(b-a).dist();\n} //signed distance\n\n//If a\
    \ unique intersection point of the lines going through s1,e1 and s2,e2 exists\
    \ \\{1, point\\} is returned.\n//If no intersection point exists \\{0, (0,0)\\\
    } is returned and if infinitely many exists \\{-1, (0,0)\\} is returned.\ntemplate<class\
    \ P>\npair<int, P> lineInter(P s1, P e1, P s2, P e2) {\n  auto d = (e1 - s1).cross(e2\
    \ - s2);\n  if (d == 0) // if parallel\n    return {-(s1.cross(e1, s2) == 0),\
    \ P(0, 0)};\n  auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);\n  return {1,\
    \ (s1 * p + e1 * q) / d};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/line.cpp
  requiredBy: []
  timestamp: '2025-05-10 02:31:09+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/line.cpp
layout: document
redirect_from:
- /library/geometry/line.cpp
- /library/geometry/line.cpp.html
title: geometry/line.cpp
---
