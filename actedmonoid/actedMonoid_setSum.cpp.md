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
  bundledCode: "#line 1 \"actedmonoid/actedMonoid_setSum.cpp\"\ntemplate<class U,\
    \ U unused>\nstruct actedMonoid_setSum {\n  using M = pair<U, int>;\n  static\
    \ M Mid() { return make_pair(U(0), 0); }\n  static M Mop(const M &a, const M &b)\
    \ { return make_pair(a.first + b.first, a.second + b.second); }\n  using T = U;\n\
    \  static T Tid() { return unused; }\n  static T Top(const T &a, const T &b) {\
    \ return b == unused ? a : b; }\n  static M act(const M &a, const T &b) { return\
    \ b == unused ? a : make_pair(a.second * b, a.second); }\n};\n"
  code: "template<class U, U unused>\nstruct actedMonoid_setSum {\n  using M = pair<U,\
    \ int>;\n  static M Mid() { return make_pair(U(0), 0); }\n  static M Mop(const\
    \ M &a, const M &b) { return make_pair(a.first + b.first, a.second + b.second);\
    \ }\n  using T = U;\n  static T Tid() { return unused; }\n  static T Top(const\
    \ T &a, const T &b) { return b == unused ? a : b; }\n  static M act(const M &a,\
    \ const T &b) { return b == unused ? a : make_pair(a.second * b, a.second); }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: actedmonoid/actedMonoid_setSum.cpp
  requiredBy: []
  timestamp: '2024-02-09 21:58:48+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: actedmonoid/actedMonoid_setSum.cpp
layout: document
redirect_from:
- /library/actedmonoid/actedMonoid_setSum.cpp
- /library/actedmonoid/actedMonoid_setSum.cpp.html
title: actedmonoid/actedMonoid_setSum.cpp
---
