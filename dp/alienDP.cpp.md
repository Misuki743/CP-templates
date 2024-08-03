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
  bundledCode: "#line 1 \"dp/alienDP.cpp\"\n//evaluate convex(concave) function f(x),\
    \ where g(p) := min(max)(f(x) - px) is easy to evaluate.\n//tips: think p as the\
    \ slope of line L(x) = px and g(p) is the signed distance from line L(x) to f(x)\
    \ is less confusing.\ntemplate<class T, T(*g)(T), bool convex>\nT alienDP(T x,\
    \ T Pl, T Pr) {\n  while(Pl < Pr) {\n    T mid = floorDiv(Pl + Pr, T(2));\n  \
    \  if constexpr (convex) {\n      if (g(mid) - g(mid + 1) <= x) Pl = mid + 1;\n\
    \      else Pr = mid;\n    } else {\n      if (g(mid) - g(mid + 1) >= x) Pl =\
    \ mid + 1;\n      else Pr = mid;\n    }\n  }\n  return g(Pl) + Pl * x;\n}\n"
  code: "//evaluate convex(concave) function f(x), where g(p) := min(max)(f(x) - px)\
    \ is easy to evaluate.\n//tips: think p as the slope of line L(x) = px and g(p)\
    \ is the signed distance from line L(x) to f(x) is less confusing.\ntemplate<class\
    \ T, T(*g)(T), bool convex>\nT alienDP(T x, T Pl, T Pr) {\n  while(Pl < Pr) {\n\
    \    T mid = floorDiv(Pl + Pr, T(2));\n    if constexpr (convex) {\n      if (g(mid)\
    \ - g(mid + 1) <= x) Pl = mid + 1;\n      else Pr = mid;\n    } else {\n     \
    \ if (g(mid) - g(mid + 1) >= x) Pl = mid + 1;\n      else Pr = mid;\n    }\n \
    \ }\n  return g(Pl) + Pl * x;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/alienDP.cpp
  requiredBy: []
  timestamp: '2024-08-04 01:36:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/alienDP.cpp
layout: document
redirect_from:
- /library/dp/alienDP.cpp
- /library/dp/alienDP.cpp.html
title: dp/alienDP.cpp
---
