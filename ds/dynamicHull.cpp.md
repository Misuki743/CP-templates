---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/112458
  bundledCode: "#line 1 \"ds/dynamicHull.cpp\"\n/**\n * template name: dynamicHull\n\
    \ * source: https://codeforces.com/blog/entry/112458\n * last update: 2023/03/18\n\
    \ */\n\nstruct pt {\n\tint x, y;\n\tpt(int x_ = 0, int y_ = 0) : x(x_), y(y_)\
    \ {}\n\tbool operator < (const pt p) const {\n\t\tif (x != p.x) return x < p.x;\n\
    \t\treturn y < p.y;\n\t}\n\tbool operator == (const pt p) const {\n\t\treturn\
    \ x == p.x and y == p.y;\n\t}\n\tpt operator + (const pt p) const { return pt(x+p.x,\
    \ y+p.y); }\n\tpt operator - (const pt p) const { return pt(x-p.x, y-p.y); }\n\
    \tpt operator * (const int c) const { return pt(x*c, y*c); }\n\tll operator *\
    \ (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }\n\tll operator ^ (const\
    \ pt p) const { return x*(ll)p.y - y*(ll)p.x; }\n\tfriend istream& operator >>\
    \ (istream& in, pt& p) {\n\t\treturn in >> p.x >> p.y;\n\t}\n};\n\nbool ccw(pt\
    \ p, pt q, pt r) { // counter-clockwise\n\treturn (q-p)^(r-q) > 0;\n}\n\nstruct\
    \ upper {\n\tset<pt> se;\n\tset<pt>::iterator it;\n\n\tint is_under(pt p) { //\
    \ 1 -> inside ; 2 -> border\n\t\tit = se.lower_bound(p);\n\t\tif (it == se.end())\
    \ return 0;\n\t\tif (it == se.begin()) return p == *it ? 2 : 0;\n\t\tif (ccw(p,\
    \ *it, *prev(it))) return 1;\n\t\treturn ccw(p, *prev(it), *it) ? 0 : 2;\n\t}\n\
    \tvoid insert(pt p) {\n\t\tif (is_under(p)) return;\n\n\t\tif (it != se.end())\
    \ while (next(it) != se.end() and !ccw(*next(it), *it, p))\n\t\t\tit = se.erase(it);\n\
    \t\tif (it != se.begin()) while (--it != se.begin() and !ccw(p, *it, *prev(it)))\n\
    \t\t\tit = se.erase(it);\n\n\t\tse.insert(p);\n\t}\n};\n\nstruct dyn_hull { //\
    \ 1 -> inside ; 2 -> border\n\tupper U, L;\n\n\tint is_inside(pt p) {\n\t\tint\
    \ u = U.is_under(p), l = L.is_under({-p.x, -p.y});\n\t\tif (!u or !l) return 0;\n\
    \t\treturn max(u, l);\n\t}\n\tvoid insert(pt p) {\n\t\tU.insert(p);\n\t\tL.insert({-p.x,\
    \ -p.y});\n\t}\n\tint size() {\n\t\tint ans = U.se.size() + L.se.size();\n\t\t\
    return ans <= 2 ? ans/2 : ans-2;\n\t}\n};\n"
  code: "/**\n * template name: dynamicHull\n * source: https://codeforces.com/blog/entry/112458\n\
    \ * last update: 2023/03/18\n */\n\nstruct pt {\n\tint x, y;\n\tpt(int x_ = 0,\
    \ int y_ = 0) : x(x_), y(y_) {}\n\tbool operator < (const pt p) const {\n\t\t\
    if (x != p.x) return x < p.x;\n\t\treturn y < p.y;\n\t}\n\tbool operator == (const\
    \ pt p) const {\n\t\treturn x == p.x and y == p.y;\n\t}\n\tpt operator + (const\
    \ pt p) const { return pt(x+p.x, y+p.y); }\n\tpt operator - (const pt p) const\
    \ { return pt(x-p.x, y-p.y); }\n\tpt operator * (const int c) const { return pt(x*c,\
    \ y*c); }\n\tll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y;\
    \ }\n\tll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }\n\t\
    friend istream& operator >> (istream& in, pt& p) {\n\t\treturn in >> p.x >> p.y;\n\
    \t}\n};\n\nbool ccw(pt p, pt q, pt r) { // counter-clockwise\n\treturn (q-p)^(r-q)\
    \ > 0;\n}\n\nstruct upper {\n\tset<pt> se;\n\tset<pt>::iterator it;\n\n\tint is_under(pt\
    \ p) { // 1 -> inside ; 2 -> border\n\t\tit = se.lower_bound(p);\n\t\tif (it ==\
    \ se.end()) return 0;\n\t\tif (it == se.begin()) return p == *it ? 2 : 0;\n\t\t\
    if (ccw(p, *it, *prev(it))) return 1;\n\t\treturn ccw(p, *prev(it), *it) ? 0 :\
    \ 2;\n\t}\n\tvoid insert(pt p) {\n\t\tif (is_under(p)) return;\n\n\t\tif (it !=\
    \ se.end()) while (next(it) != se.end() and !ccw(*next(it), *it, p))\n\t\t\tit\
    \ = se.erase(it);\n\t\tif (it != se.begin()) while (--it != se.begin() and !ccw(p,\
    \ *it, *prev(it)))\n\t\t\tit = se.erase(it);\n\n\t\tse.insert(p);\n\t}\n};\n\n\
    struct dyn_hull { // 1 -> inside ; 2 -> border\n\tupper U, L;\n\n\tint is_inside(pt\
    \ p) {\n\t\tint u = U.is_under(p), l = L.is_under({-p.x, -p.y});\n\t\tif (!u or\
    \ !l) return 0;\n\t\treturn max(u, l);\n\t}\n\tvoid insert(pt p) {\n\t\tU.insert(p);\n\
    \t\tL.insert({-p.x, -p.y});\n\t}\n\tint size() {\n\t\tint ans = U.se.size() +\
    \ L.se.size();\n\t\treturn ans <= 2 ? ans/2 : ans-2;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/dynamicHull.cpp
  requiredBy: []
  timestamp: '2024-01-20 02:52:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/dynamicHull.cpp
layout: document
redirect_from:
- /library/ds/dynamicHull.cpp
- /library/ds/dynamicHull.cpp.html
title: ds/dynamicHull.cpp
---
