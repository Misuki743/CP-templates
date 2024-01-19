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
  bundledCode: "#line 1 \"geometry/geometryLine.cpp\"\n/**\n * template name: geometryLine\n\
    \ */\n\ntypedef Point<double> P;\ndouble segDist(P& s, P& e, P& p) {\n\tif (s==e)\
    \ return (p-s).dist();\n\tauto d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));\n\
    \treturn ((p-s)*d-(e-s)*t).dist()/d;\n}\n\ntemplate<class P>\ndouble lineDist(const\
    \ P& a, const P& b, const P& p) {\n\treturn (double)(b-a).cross(p-a)/(b-a).dist();\n\
    }\n\nP linearTransformation(const P& p0, const P& p1,\n\t\tconst P& q0, const\
    \ P& q1, const P& r) {\n\tP dp = p1-p0, dq = q1-q0, num(dp.cross(dq), dp.dot(dq));\n\
    \treturn q0 + P((r-p0).cross(num), (r-p0).dot(num))/dp.dist2();\n}\n\ntemplate<class\
    \ P> bool onSegment(P s, P e, P p) {\n\treturn p.cross(s, e) == 0 && (s - p).dot(e\
    \ - p) <= 0;\n}\n\ntemplate<class P>\nint sideOf(P s, P e, P p) { return sgn(s.cross(e,\
    \ p)); }\n\ntemplate<class P>\nint sideOf(const P& s, const P& e, const P& p,\
    \ double eps) {\n\tauto a = (e-s).cross(p-s);\n\tdouble l = (e-s).dist()*eps;\n\
    \treturn (a > l) - (a < -l);\n}\n\ntemplate<class P>\npair<int, P> lineInter(P\
    \ s1, P e1, P s2, P e2) {\n\tauto d = (e1 - s1).cross(e2 - s2);\n\tif (d == 0)\
    \ // if parallel\n\t\treturn {-(s1.cross(e1, s2) == 0), P(0, 0)};\n\tauto p =\
    \ s2.cross(e1, e2), q = s2.cross(e2, s1);\n\treturn {1, (s1 * p + e1 * q) / d};\n\
    }\n\ntemplate<class P> vector<P> segInter(P a, P b, P c, P d) {\n\tauto oa = c.cross(d,\
    \ a), ob = c.cross(d, b),\n\t     oc = a.cross(b, c), od = a.cross(b, d);\n\t\
    // Checks if intersection is single non-endpoint point.\n\tif (sgn(oa) * sgn(ob)\
    \ < 0 && sgn(oc) * sgn(od) < 0)\n\t\treturn {(a * ob - b * oa) / (ob - oa)};\n\
    \tset<P> s;\n\tif (onSegment(c, d, a)) s.insert(a);\n\tif (onSegment(c, d, b))\
    \ s.insert(b);\n\tif (onSegment(a, b, c)) s.insert(c);\n\tif (onSegment(a, b,\
    \ d)) s.insert(d);\n\treturn {all(s)};\n}\n\ntemplate<class P>\nP lineProj(P a,\
    \ P b, P p, bool refl=false) {\n\tP v = b - a;\n\treturn p - v.perp()*(1+refl)*v.cross(p-a)/v.dist2();\n\
    }\n"
  code: "/**\n * template name: geometryLine\n */\n\ntypedef Point<double> P;\ndouble\
    \ segDist(P& s, P& e, P& p) {\n\tif (s==e) return (p-s).dist();\n\tauto d = (e-s).dist2(),\
    \ t = min(d,max(.0,(p-s).dot(e-s)));\n\treturn ((p-s)*d-(e-s)*t).dist()/d;\n}\n\
    \ntemplate<class P>\ndouble lineDist(const P& a, const P& b, const P& p) {\n\t\
    return (double)(b-a).cross(p-a)/(b-a).dist();\n}\n\nP linearTransformation(const\
    \ P& p0, const P& p1,\n\t\tconst P& q0, const P& q1, const P& r) {\n\tP dp = p1-p0,\
    \ dq = q1-q0, num(dp.cross(dq), dp.dot(dq));\n\treturn q0 + P((r-p0).cross(num),\
    \ (r-p0).dot(num))/dp.dist2();\n}\n\ntemplate<class P> bool onSegment(P s, P e,\
    \ P p) {\n\treturn p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;\n}\n\ntemplate<class\
    \ P>\nint sideOf(P s, P e, P p) { return sgn(s.cross(e, p)); }\n\ntemplate<class\
    \ P>\nint sideOf(const P& s, const P& e, const P& p, double eps) {\n\tauto a =\
    \ (e-s).cross(p-s);\n\tdouble l = (e-s).dist()*eps;\n\treturn (a > l) - (a < -l);\n\
    }\n\ntemplate<class P>\npair<int, P> lineInter(P s1, P e1, P s2, P e2) {\n\tauto\
    \ d = (e1 - s1).cross(e2 - s2);\n\tif (d == 0) // if parallel\n\t\treturn {-(s1.cross(e1,\
    \ s2) == 0), P(0, 0)};\n\tauto p = s2.cross(e1, e2), q = s2.cross(e2, s1);\n\t\
    return {1, (s1 * p + e1 * q) / d};\n}\n\ntemplate<class P> vector<P> segInter(P\
    \ a, P b, P c, P d) {\n\tauto oa = c.cross(d, a), ob = c.cross(d, b),\n\t    \
    \ oc = a.cross(b, c), od = a.cross(b, d);\n\t// Checks if intersection is single\
    \ non-endpoint point.\n\tif (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)\n\
    \t\treturn {(a * ob - b * oa) / (ob - oa)};\n\tset<P> s;\n\tif (onSegment(c, d,\
    \ a)) s.insert(a);\n\tif (onSegment(c, d, b)) s.insert(b);\n\tif (onSegment(a,\
    \ b, c)) s.insert(c);\n\tif (onSegment(a, b, d)) s.insert(d);\n\treturn {all(s)};\n\
    }\n\ntemplate<class P>\nP lineProj(P a, P b, P p, bool refl=false) {\n\tP v =\
    \ b - a;\n\treturn p - v.perp()*(1+refl)*v.cross(p-a)/v.dist2();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometryLine.cpp
  requiredBy: []
  timestamp: '2024-01-20 02:52:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/geometryLine.cpp
layout: document
redirect_from:
- /library/geometry/geometryLine.cpp
- /library/geometry/geometryLine.cpp.html
title: geometry/geometryLine.cpp
---
