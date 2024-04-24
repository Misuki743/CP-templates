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
  bundledCode: "#line 1 \"ds/lineContainer.cpp\"\n//source: KACTL\n\nstruct Line {\n\
    \tmutable ll k, m, p;\n\tbool operator<(const Line& o) const { return k < o.k;\
    \ }\n\tbool operator<(ll x) const { return p < x; }\n};\n\nstruct LineContainer\
    \ : multiset<Line, less<>> {\n\t// (for doubles, use inf = 1/.0, div(a,b) = a/b)\n\
    \tstatic const ll inf = LLONG_MAX;\n\tll div(ll a, ll b) { // floored division\n\
    \t\treturn a / b - ((a ^ b) < 0 && a % b); }\n\tbool isect(iterator x, iterator\
    \ y) {\n\t\tif (y == end()) return x->p = inf, 0;\n\t\tif (x->k == y->k) x->p\
    \ = x->m > y->m ? inf : -inf;\n\t\telse x->p = div(y->m - x->m, x->k - y->k);\n\
    \t\treturn x->p >= y->p;\n\t}\n\tvoid add(ll k, ll m) { //add L : kx + m\n\t\t\
    auto z = insert({k, m, 0}), y = z++, x = y;\n\t\twhile (isect(y, z)) z = erase(z);\n\
    \t\tif (x != begin() && isect(--x, y)) isect(x, y = erase(y));\n\t\twhile ((y\
    \ = x) != begin() && (--x)->p >= y->p)\n\t\t\tisect(x, erase(y));\n\t}\n\tll query(ll\
    \ x) { //query max at x\n\t\tassert(!empty());\n\t\tauto l = *lower_bound(x);\n\
    \t\treturn l.k * x + l.m;\n\t}\n};\n"
  code: "//source: KACTL\n\nstruct Line {\n\tmutable ll k, m, p;\n\tbool operator<(const\
    \ Line& o) const { return k < o.k; }\n\tbool operator<(ll x) const { return p\
    \ < x; }\n};\n\nstruct LineContainer : multiset<Line, less<>> {\n\t// (for doubles,\
    \ use inf = 1/.0, div(a,b) = a/b)\n\tstatic const ll inf = LLONG_MAX;\n\tll div(ll\
    \ a, ll b) { // floored division\n\t\treturn a / b - ((a ^ b) < 0 && a % b); }\n\
    \tbool isect(iterator x, iterator y) {\n\t\tif (y == end()) return x->p = inf,\
    \ 0;\n\t\tif (x->k == y->k) x->p = x->m > y->m ? inf : -inf;\n\t\telse x->p =\
    \ div(y->m - x->m, x->k - y->k);\n\t\treturn x->p >= y->p;\n\t}\n\tvoid add(ll\
    \ k, ll m) { //add L : kx + m\n\t\tauto z = insert({k, m, 0}), y = z++, x = y;\n\
    \t\twhile (isect(y, z)) z = erase(z);\n\t\tif (x != begin() && isect(--x, y))\
    \ isect(x, y = erase(y));\n\t\twhile ((y = x) != begin() && (--x)->p >= y->p)\n\
    \t\t\tisect(x, erase(y));\n\t}\n\tll query(ll x) { //query max at x\n\t\tassert(!empty());\n\
    \t\tauto l = *lower_bound(x);\n\t\treturn l.k * x + l.m;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/lineContainer.cpp
  requiredBy: []
  timestamp: '2024-04-24 23:34:37+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/lineContainer.cpp
layout: document
redirect_from:
- /library/ds/lineContainer.cpp
- /library/ds/lineContainer.cpp.html
title: ds/lineContainer.cpp
---
