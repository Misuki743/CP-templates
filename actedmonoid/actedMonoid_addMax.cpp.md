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
  bundledCode: "#line 1 \"actedmonoid/actedMonoid_addMax.cpp\"\ntemplate<class U>\n\
    struct actedMonoid_addMax {\n  using M = U;\n  static M Mid() { return numeric_limits<T>::min();\
    \ }\n  static M Mop(const M &a, const M &b) { return max(a, b); }\n  using T =\
    \ U;\n  static T Tid() { return T(0); }\n  static T Top(const T &a, const T &b)\
    \ { return a + b; }\n  static M act(const M &a, const T &b) { return a + b; }\n\
    };\n"
  code: "template<class U>\nstruct actedMonoid_addMax {\n  using M = U;\n  static\
    \ M Mid() { return numeric_limits<T>::min(); }\n  static M Mop(const M &a, const\
    \ M &b) { return max(a, b); }\n  using T = U;\n  static T Tid() { return T(0);\
    \ }\n  static T Top(const T &a, const T &b) { return a + b; }\n  static M act(const\
    \ M &a, const T &b) { return a + b; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: actedmonoid/actedMonoid_addMax.cpp
  requiredBy: []
  timestamp: '2024-02-09 21:58:48+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: actedmonoid/actedMonoid_addMax.cpp
layout: document
redirect_from:
- /library/actedmonoid/actedMonoid_addMax.cpp
- /library/actedmonoid/actedMonoid_addMax.cpp.html
title: actedmonoid/actedMonoid_addMax.cpp
---
