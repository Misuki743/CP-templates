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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ geometry/point.cpp: line 10: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Ulf Lundstrom\n * Date: 2009-02-26\n * License: CC0\n * Source:\
    \ My head with inspiration from tinyKACTL\n * Description: Class to handle points\
    \ in the plane.\n * \tT can be e.g. double or long long. (Avoid int.)\n * Status:\
    \ Works fine, used a lot\n */\n#pragma once\n\ntemplate <class T> int sgn(T x)\
    \ { return (x > 0) - (x < 0); }\ntemplate<class T>\nstruct Point {\n\ttypedef\
    \ Point P;\n\tT x, y;\n\texplicit Point(T x=0, T y=0) : x(x), y(y) {}\n\tbool\
    \ operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }\n\tbool operator==(P\
    \ p) const { return tie(x,y)==tie(p.x,p.y); }\n\tP operator+(P p) const { return\
    \ P(x+p.x, y+p.y); }\n\tP operator-(P p) const { return P(x-p.x, y-p.y); }\n\t\
    P operator*(T d) const { return P(x*d, y*d); }\n\tP operator/(T d) const { return\
    \ P(x/d, y/d); }\n\tT dot(P p) const { return x*p.x + y*p.y; }\n\tT cross(P p)\
    \ const { return x*p.y - y*p.x; }\n\tT cross(P a, P b) const { return (a-*this).cross(b-*this);\
    \ }\n\tT dist2() const { return x*x + y*y; }\n\tdouble dist() const { return sqrt((double)dist2());\
    \ }\n\t// angle to x-axis in interval [-pi, pi]\n\tdouble angle() const { return\
    \ atan2(y, x); }\n\tP unit() const { return *this/dist(); } // makes dist()=1\n\
    \tP perp() const { return P(-y, x); } // rotates +90 degrees\n\tP normal() const\
    \ { return perp().unit(); }\n\t// returns point rotated 'a' radians ccw around\
    \ the origin\n\tP rotate(double a) const {\n\t\treturn P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));\
    \ }\n\tfriend ostream& operator<<(ostream& os, P p) {\n\t\treturn os << \"(\"\
    \ << p.x << \",\" << p.y << \")\"; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/point.cpp
  requiredBy: []
  timestamp: '2025-03-16 20:32:54+08:00'
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
