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
  bundledCode: "#line 1 \"geometryCircle.cpp\"\n/**\n * template name: geometry circle\n\
    \ */\n\n#define arg(p, q) atan2(p.cross(q), p.dot(q))\n\ntypedef Point<double>\
    \ P;\nbool circleInter(P a,P b,double r1,double r2,pair<P, P>* out) {\n\tif (a\
    \ == b) { assert(r1 != r2); return false; }\n\tP vec = b - a;\n\tdouble d2 = vec.dist2(),\
    \ sum = r1+r2, dif = r1-r2,\n\t       p = (d2 + r1*r1 - r2*r2)/(d2*2), h2 = r1*r1\
    \ - p*p*d2;\n\tif (sum*sum < d2 || dif*dif > d2) return false;\n\tP mid = a +\
    \ vec*p, per = vec.perp() * sqrt(fmax(0, h2) / d2);\n\t*out = {mid + per, mid\
    \ - per};\n\treturn true;\n}\n\ntemplate<class P>\nvector<P> circleLine(P c, double\
    \ r, P a, P b) {\n\tP ab = b - a, p = a + ab * (c-a).dot(ab) / ab.dist2();\n\t\
    double s = a.cross(b, c), h2 = r*r - s*s / ab.dist2();\n\tif (h2 < 0) return {};\n\
    \tif (h2 == 0) return {p};\n\tP h = ab.unit() * sqrt(h2);\n\treturn {p - h, p\
    \ + h};\n}\n\ndouble circlePoly(P c, double r, vector<P> ps) {\n\tauto tri = [&](P\
    \ p, P q) {\n\t\tauto r2 = r * r / 2;\n\t\tP d = q - p;\n\t\tauto a = d.dot(p)/d.dist2(),\
    \ b = (p.dist2()-r*r)/d.dist2();\n\t\tauto det = a * a - b;\n\t\tif (det <= 0)\
    \ return arg(p, q) * r2;\n\t\tauto s = max(0., -a-sqrt(det)), t = min(1., -a+sqrt(det));\n\
    \t\tif (t < 0 || 1 <= s) return arg(p, q) * r2;\n\t\tP u = p + d * s, v = p +\
    \ d * t;\n\t\treturn arg(p,u) * r2 + u.cross(v)/2 + arg(v,q) * r2;\n\t};\n\tauto\
    \ sum = 0.0;\n\trep(i,0,sz(ps))\n\t\tsum += tri(ps[i] - c, ps[(i + 1) % sz(ps)]\
    \ - c);\n\treturn sum;\n}\n\ntemplate<class P>\nvector<pair<P, P>> tangents(P\
    \ c1, double r1, P c2, double r2) {\n\tP d = c2 - c1;\n\tdouble dr = r1 - r2,\
    \ d2 = d.dist2(), h2 = d2 - dr * dr;\n\tif (d2 == 0 || h2 < 0)  return {};\n\t\
    vector<pair<P, P>> out;\n\tfor (double sign : {-1, 1}) {\n\t\tP v = (d * dr +\
    \ d.perp() * sqrt(h2) * sign) / d2;\n\t\tout.push_back({c1 + v * r1, c2 + v *\
    \ r2});\n\t}\n\tif (h2 == 0) out.pop_back();\n\treturn out;\n}\n\ndouble ccRadius(const\
    \ P& A, const P& B, const P& C) {\n\treturn (B-A).dist()*(C-B).dist()*(A-C).dist()/\n\
    \t\t\tabs((B-A).cross(C-A))/2;\n}\nP ccCenter(const P& A, const P& B, const P&\
    \ C) {\n\tP b = C-A, c = B-A;\n\treturn A + (b*c.dist2()-c*b.dist2()).perp()/b.cross(c)/2;\n\
    }\n\npair<P, double> mec(vector<P> ps) {\n\tshuffle(all(ps), mt19937(time(0)));\n\
    \tP o = ps[0];\n\tdouble r = 0, EPS = 1 + 1e-8;\n\trep(i,0,sz(ps)) if ((o - ps[i]).dist()\
    \ > r * EPS) {\n\t\to = ps[i], r = 0;\n\t\trep(j,0,i) if ((o - ps[j]).dist() >\
    \ r * EPS) {\n\t\t\to = (ps[i] + ps[j]) / 2;\n\t\t\tr = (o - ps[i]).dist();\n\t\
    \t\trep(k,0,j) if ((o - ps[k]).dist() > r * EPS) {\n\t\t\t\to = ccCenter(ps[i],\
    \ ps[j], ps[k]);\n\t\t\t\tr = (o - ps[i]).dist();\n\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ {o, r};\n}\n"
  code: "/**\n * template name: geometry circle\n */\n\n#define arg(p, q) atan2(p.cross(q),\
    \ p.dot(q))\n\ntypedef Point<double> P;\nbool circleInter(P a,P b,double r1,double\
    \ r2,pair<P, P>* out) {\n\tif (a == b) { assert(r1 != r2); return false; }\n\t\
    P vec = b - a;\n\tdouble d2 = vec.dist2(), sum = r1+r2, dif = r1-r2,\n\t     \
    \  p = (d2 + r1*r1 - r2*r2)/(d2*2), h2 = r1*r1 - p*p*d2;\n\tif (sum*sum < d2 ||\
    \ dif*dif > d2) return false;\n\tP mid = a + vec*p, per = vec.perp() * sqrt(fmax(0,\
    \ h2) / d2);\n\t*out = {mid + per, mid - per};\n\treturn true;\n}\n\ntemplate<class\
    \ P>\nvector<P> circleLine(P c, double r, P a, P b) {\n\tP ab = b - a, p = a +\
    \ ab * (c-a).dot(ab) / ab.dist2();\n\tdouble s = a.cross(b, c), h2 = r*r - s*s\
    \ / ab.dist2();\n\tif (h2 < 0) return {};\n\tif (h2 == 0) return {p};\n\tP h =\
    \ ab.unit() * sqrt(h2);\n\treturn {p - h, p + h};\n}\n\ndouble circlePoly(P c,\
    \ double r, vector<P> ps) {\n\tauto tri = [&](P p, P q) {\n\t\tauto r2 = r * r\
    \ / 2;\n\t\tP d = q - p;\n\t\tauto a = d.dot(p)/d.dist2(), b = (p.dist2()-r*r)/d.dist2();\n\
    \t\tauto det = a * a - b;\n\t\tif (det <= 0) return arg(p, q) * r2;\n\t\tauto\
    \ s = max(0., -a-sqrt(det)), t = min(1., -a+sqrt(det));\n\t\tif (t < 0 || 1 <=\
    \ s) return arg(p, q) * r2;\n\t\tP u = p + d * s, v = p + d * t;\n\t\treturn arg(p,u)\
    \ * r2 + u.cross(v)/2 + arg(v,q) * r2;\n\t};\n\tauto sum = 0.0;\n\trep(i,0,sz(ps))\n\
    \t\tsum += tri(ps[i] - c, ps[(i + 1) % sz(ps)] - c);\n\treturn sum;\n}\n\ntemplate<class\
    \ P>\nvector<pair<P, P>> tangents(P c1, double r1, P c2, double r2) {\n\tP d =\
    \ c2 - c1;\n\tdouble dr = r1 - r2, d2 = d.dist2(), h2 = d2 - dr * dr;\n\tif (d2\
    \ == 0 || h2 < 0)  return {};\n\tvector<pair<P, P>> out;\n\tfor (double sign :\
    \ {-1, 1}) {\n\t\tP v = (d * dr + d.perp() * sqrt(h2) * sign) / d2;\n\t\tout.push_back({c1\
    \ + v * r1, c2 + v * r2});\n\t}\n\tif (h2 == 0) out.pop_back();\n\treturn out;\n\
    }\n\ndouble ccRadius(const P& A, const P& B, const P& C) {\n\treturn (B-A).dist()*(C-B).dist()*(A-C).dist()/\n\
    \t\t\tabs((B-A).cross(C-A))/2;\n}\nP ccCenter(const P& A, const P& B, const P&\
    \ C) {\n\tP b = C-A, c = B-A;\n\treturn A + (b*c.dist2()-c*b.dist2()).perp()/b.cross(c)/2;\n\
    }\n\npair<P, double> mec(vector<P> ps) {\n\tshuffle(all(ps), mt19937(time(0)));\n\
    \tP o = ps[0];\n\tdouble r = 0, EPS = 1 + 1e-8;\n\trep(i,0,sz(ps)) if ((o - ps[i]).dist()\
    \ > r * EPS) {\n\t\to = ps[i], r = 0;\n\t\trep(j,0,i) if ((o - ps[j]).dist() >\
    \ r * EPS) {\n\t\t\to = (ps[i] + ps[j]) / 2;\n\t\t\tr = (o - ps[i]).dist();\n\t\
    \t\trep(k,0,j) if ((o - ps[k]).dist() > r * EPS) {\n\t\t\t\to = ccCenter(ps[i],\
    \ ps[j], ps[k]);\n\t\t\t\tr = (o - ps[i]).dist();\n\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ {o, r};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometryCircle.cpp
  requiredBy: []
  timestamp: '2023-06-16 02:10:58+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometryCircle.cpp
layout: document
redirect_from:
- /library/geometryCircle.cpp
- /library/geometryCircle.cpp.html
title: geometryCircle.cpp
---
