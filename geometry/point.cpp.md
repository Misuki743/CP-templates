---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/closest_pair.test.cpp
    title: test/closest_pair.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/static_convex_hull.test.cpp
    title: test/static_convex_hull.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/point.cpp\"\n//source: KACTL\n/**\n * Author: Ulf\
    \ Lundstrom\n * Date: 2009-02-26\n * License: CC0\n * Source: My head with inspiration\
    \ from tinyKACTL\n * Description: Class to handle points in the plane.\n *  T\
    \ can be e.g. double or long long. (Avoid int.)\n * Status: Works fine, used a\
    \ lot\n */\n\ntemplate <class T> int sgn(T x) { return (x > 0) - (x < 0); }\n\
    template<class T>\nstruct Point {\n  typedef Point P;\n  T x, y;\n  explicit Point(T\
    \ x=0, T y=0) : x(x), y(y) {}\n  bool operator<(P p) const { return tie(x,y) <\
    \ tie(p.x,p.y); }\n  bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y);\
    \ }\n  P operator+(P p) const { return P(x+p.x, y+p.y); }\n  P operator-(P p)\
    \ const { return P(x-p.x, y-p.y); }\n  P operator*(T d) const { return P(x*d,\
    \ y*d); }\n  P operator/(T d) const { return P(x/d, y/d); }\n  T dot(P p) const\
    \ { return x*p.x + y*p.y; }\n  T cross(P p) const { return x*p.y - y*p.x; }\n\
    \  T cross(P a, P b) const { return (a-*this).cross(b-*this); }\n  T dist2() const\
    \ { return x*x + y*y; }\n  double dist() const { return sqrt((double)dist2());\
    \ }\n  // angle to x-axis in interval [-pi, pi]\n  double angle() const { return\
    \ atan2(y, x); }\n  P unit() const { return *this/dist(); } // makes dist()=1\n\
    \  P perp() const { return P(-y, x); } // rotates +90 degrees\n  P normal() const\
    \ { return perp().unit(); }\n  // returns point rotated 'a' radians ccw around\
    \ the origin\n  P rotate(double a) const {\n    return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));\
    \ }\n  friend ostream& operator<<(ostream& os, P p) {\n    return os << \"(\"\
    \ << p.x << \",\" << p.y << \")\"; }\n};\n"
  code: "//source: KACTL\n/**\n * Author: Ulf Lundstrom\n * Date: 2009-02-26\n * License:\
    \ CC0\n * Source: My head with inspiration from tinyKACTL\n * Description: Class\
    \ to handle points in the plane.\n *  T can be e.g. double or long long. (Avoid\
    \ int.)\n * Status: Works fine, used a lot\n */\n\ntemplate <class T> int sgn(T\
    \ x) { return (x > 0) - (x < 0); }\ntemplate<class T>\nstruct Point {\n  typedef\
    \ Point P;\n  T x, y;\n  explicit Point(T x=0, T y=0) : x(x), y(y) {}\n  bool\
    \ operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }\n  bool operator==(P\
    \ p) const { return tie(x,y)==tie(p.x,p.y); }\n  P operator+(P p) const { return\
    \ P(x+p.x, y+p.y); }\n  P operator-(P p) const { return P(x-p.x, y-p.y); }\n \
    \ P operator*(T d) const { return P(x*d, y*d); }\n  P operator/(T d) const { return\
    \ P(x/d, y/d); }\n  T dot(P p) const { return x*p.x + y*p.y; }\n  T cross(P p)\
    \ const { return x*p.y - y*p.x; }\n  T cross(P a, P b) const { return (a-*this).cross(b-*this);\
    \ }\n  T dist2() const { return x*x + y*y; }\n  double dist() const { return sqrt((double)dist2());\
    \ }\n  // angle to x-axis in interval [-pi, pi]\n  double angle() const { return\
    \ atan2(y, x); }\n  P unit() const { return *this/dist(); } // makes dist()=1\n\
    \  P perp() const { return P(-y, x); } // rotates +90 degrees\n  P normal() const\
    \ { return perp().unit(); }\n  // returns point rotated 'a' radians ccw around\
    \ the origin\n  P rotate(double a) const {\n    return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));\
    \ }\n  friend ostream& operator<<(ostream& os, P p) {\n    return os << \"(\"\
    \ << p.x << \",\" << p.y << \")\"; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/point.cpp
  requiredBy: []
  timestamp: '2025-03-21 23:27:46+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/static_convex_hull.test.cpp
  - test/closest_pair.test.cpp
documentation_of: geometry/point.cpp
layout: document
redirect_from:
- /library/geometry/point.cpp
- /library/geometry/point.cpp.html
title: geometry/point.cpp
---
