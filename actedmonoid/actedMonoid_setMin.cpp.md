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
  bundledCode: "#line 1 \"actedmonoid/actedMonoid_setMin.cpp\"\ntemplate<class U,\
    \ U unused>\nstruct actedMonoid_setMin {\n  using M = U;\n  static M Mid() { return\
    \ numeric_limits<T>::max(); }\n  static M Mop(const M &a, const M &b) { return\
    \ min(a, b); }\n  using T = U;\n  static T Tid() { return unused; }\n  static\
    \ T Top(const T &a, const T &b) { return b == unused ? a : b; }\n  static M act(const\
    \ M &a, const T &b) { return b == unused ? a : b; }\n};\n"
  code: "template<class U, U unused>\nstruct actedMonoid_setMin {\n  using M = U;\n\
    \  static M Mid() { return numeric_limits<T>::max(); }\n  static M Mop(const M\
    \ &a, const M &b) { return min(a, b); }\n  using T = U;\n  static T Tid() { return\
    \ unused; }\n  static T Top(const T &a, const T &b) { return b == unused ? a :\
    \ b; }\n  static M act(const M &a, const T &b) { return b == unused ? a : b; }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: actedmonoid/actedMonoid_setMin.cpp
  requiredBy: []
  timestamp: '2024-02-09 21:58:48+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: actedmonoid/actedMonoid_setMin.cpp
layout: document
redirect_from:
- /library/actedmonoid/actedMonoid_setMin.cpp
- /library/actedmonoid/actedMonoid_setMin.cpp.html
title: actedmonoid/actedMonoid_setMin.cpp
---
