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
  bundledCode: "#line 1 \"geometry/geometryBasic.cpp\"\n//source: KACTL\n\ntemplate\
    \ <class T> int sgn(T x) { return (x > 0) - (x < 0); }\ntemplate<class T>\nstruct\
    \ Point {\n\ttypedef Point P;\n\tT x, y;\n\texplicit Point(T x=0, T y=0) : x(x),\
    \ y(y) {}\n\tbool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }\n\t\
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }\n\tP operator+(P\
    \ p) const { return P(x+p.x, y+p.y); }\n\tP operator-(P p) const { return P(x-p.x,\
    \ y-p.y); }\n\tP operator*(T d) const { return P(x*d, y*d); }\n\tP operator/(T\
    \ d) const { return P(x/d, y/d); }\n\tT dot(P p) const { return x*p.x + y*p.y;\
    \ }\n\tT cross(P p) const { return x*p.y - y*p.x; }\n\tT cross(P a, P b) const\
    \ { return (a-*this).cross(b-*this); }\n\tT dist2() const { return x*x + y*y;\
    \ }\n\tdouble dist() const { return sqrt((double)dist2()); }\n\t// angle to x-axis\
    \ in interval [-pi, pi]\n\tdouble angle() const { return atan2(y, x); }\n\tP unit()\
    \ const { return *this/dist(); } // makes dist()=1\n\tP perp() const { return\
    \ P(-y, x); } // rotates +90 degrees\n\tP normal() const { return perp().unit();\
    \ }\n\t// returns point rotated 'a' radians ccw around the origin\n\tP rotate(double\
    \ a) const {\n\t\treturn P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }\n\tfriend ostream&\
    \ operator<<(ostream& os, P p) {\n\t\treturn os << \"(\" << p.x << \",\" << p.y\
    \ << \")\"; }\n};\n\nstruct Angle {\n\tint x, y;\n\tint t;\n\tAngle(int x, int\
    \ y, int t=0) : x(x), y(y), t(t) {}\n\tAngle operator-(Angle b) const { return\
    \ {x-b.x, y-b.y, t}; }\n\tint half() const {\n\t\tassert(x || y);\n\t\treturn\
    \ y < 0 || (y == 0 && x < 0);\n\t}\n\tAngle t90() const { return {-y, x, t + (half()\
    \ && x >= 0)}; }\n\tAngle t180() const { return {-x, -y, t + half()}; }\n\tAngle\
    \ t360() const { return {x, y, t + 1}; }\n};\nbool operator<(Angle a, Angle b)\
    \ {\n\t// add a.dist2() and b.dist2() to also compare distances\n\treturn make_tuple(a.t,\
    \ a.half(), a.y * (ll)b.x) <\n\t       make_tuple(b.t, b.half(), a.x * (ll)b.y);\n\
    }\n\n// Given two points, this calculates the smallest angle between\n// them,\
    \ i.e., the angle that covers the defined line segment.\npair<Angle, Angle> segmentAngles(Angle\
    \ a, Angle b) {\n\tif (b < a) swap(a, b);\n\treturn (b < a.t180() ?\n\t      \
    \  make_pair(a, b) : make_pair(b, a.t360()));\n}\nAngle operator+(Angle a, Angle\
    \ b) { // point a + vector b\n\tAngle r(a.x + b.x, a.y + b.y, a.t);\n\tif (a.t180()\
    \ < r) r.t--;\n\treturn r.t180() < a ? r.t360() : r;\n}\nAngle angleDiff(Angle\
    \ a, Angle b) { // angle b - angle a\n\tint tu = b.t - a.t; a.t = b.t;\n\treturn\
    \ {a.x*b.x + a.y*b.y, a.x*b.y - a.y*b.x, tu - (b < a)};\n}\n"
  code: "//source: KACTL\n\ntemplate <class T> int sgn(T x) { return (x > 0) - (x\
    \ < 0); }\ntemplate<class T>\nstruct Point {\n\ttypedef Point P;\n\tT x, y;\n\t\
    explicit Point(T x=0, T y=0) : x(x), y(y) {}\n\tbool operator<(P p) const { return\
    \ tie(x,y) < tie(p.x,p.y); }\n\tbool operator==(P p) const { return tie(x,y)==tie(p.x,p.y);\
    \ }\n\tP operator+(P p) const { return P(x+p.x, y+p.y); }\n\tP operator-(P p)\
    \ const { return P(x-p.x, y-p.y); }\n\tP operator*(T d) const { return P(x*d,\
    \ y*d); }\n\tP operator/(T d) const { return P(x/d, y/d); }\n\tT dot(P p) const\
    \ { return x*p.x + y*p.y; }\n\tT cross(P p) const { return x*p.y - y*p.x; }\n\t\
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }\n\tT dist2() const\
    \ { return x*x + y*y; }\n\tdouble dist() const { return sqrt((double)dist2());\
    \ }\n\t// angle to x-axis in interval [-pi, pi]\n\tdouble angle() const { return\
    \ atan2(y, x); }\n\tP unit() const { return *this/dist(); } // makes dist()=1\n\
    \tP perp() const { return P(-y, x); } // rotates +90 degrees\n\tP normal() const\
    \ { return perp().unit(); }\n\t// returns point rotated 'a' radians ccw around\
    \ the origin\n\tP rotate(double a) const {\n\t\treturn P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));\
    \ }\n\tfriend ostream& operator<<(ostream& os, P p) {\n\t\treturn os << \"(\"\
    \ << p.x << \",\" << p.y << \")\"; }\n};\n\nstruct Angle {\n\tint x, y;\n\tint\
    \ t;\n\tAngle(int x, int y, int t=0) : x(x), y(y), t(t) {}\n\tAngle operator-(Angle\
    \ b) const { return {x-b.x, y-b.y, t}; }\n\tint half() const {\n\t\tassert(x ||\
    \ y);\n\t\treturn y < 0 || (y == 0 && x < 0);\n\t}\n\tAngle t90() const { return\
    \ {-y, x, t + (half() && x >= 0)}; }\n\tAngle t180() const { return {-x, -y, t\
    \ + half()}; }\n\tAngle t360() const { return {x, y, t + 1}; }\n};\nbool operator<(Angle\
    \ a, Angle b) {\n\t// add a.dist2() and b.dist2() to also compare distances\n\t\
    return make_tuple(a.t, a.half(), a.y * (ll)b.x) <\n\t       make_tuple(b.t, b.half(),\
    \ a.x * (ll)b.y);\n}\n\n// Given two points, this calculates the smallest angle\
    \ between\n// them, i.e., the angle that covers the defined line segment.\npair<Angle,\
    \ Angle> segmentAngles(Angle a, Angle b) {\n\tif (b < a) swap(a, b);\n\treturn\
    \ (b < a.t180() ?\n\t        make_pair(a, b) : make_pair(b, a.t360()));\n}\nAngle\
    \ operator+(Angle a, Angle b) { // point a + vector b\n\tAngle r(a.x + b.x, a.y\
    \ + b.y, a.t);\n\tif (a.t180() < r) r.t--;\n\treturn r.t180() < a ? r.t360() :\
    \ r;\n}\nAngle angleDiff(Angle a, Angle b) { // angle b - angle a\n\tint tu =\
    \ b.t - a.t; a.t = b.t;\n\treturn {a.x*b.x + a.y*b.y, a.x*b.y - a.y*b.x, tu -\
    \ (b < a)};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometryBasic.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/geometryBasic.cpp
layout: document
redirect_from:
- /library/geometry/geometryBasic.cpp
- /library/geometry/geometryBasic.cpp.html
title: geometry/geometryBasic.cpp
---
