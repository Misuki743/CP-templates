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
  bundledCode: "#line 1 \"generalApproach.cpp\"\n/**\n * template name: generalApproach\n\
    \ * author: Misuki\n * last update: 2023/04/22\n * note: these may be useful when\
    \ I have completely no idea on a problem D:\n *\n * think recursively\n *\n *\
    \ draw a graph, observe the process\n *\n * try to model the problem in the most\
    \ general way\n *\n * find invariant\n *\n * find equivalent condition\n *\n *\
    \ observe a lower/upper bound, and try to achieve that bound\n *\n * observe optimal\
    \ structure (consider brute force small case to see the structure may be a good\
    \ choice)\n *\n * invent subtask\n *\n * think what is important in the problem\
    \ model\n *\n * think reversely\n *\n * brute force small cases\n *\n * think\
    \ of trivial solution than try to optimize(especially for dp, atleast see the\
    \ transition and try to optimize)\n *\n * Problem Specific technique:\n * \n *\
    \ expectation: linearity of expectation to decompose problem into easier ones\n\
    \ *\n * game theory: start from the end state, bruteforce patterns, and observe\
    \ the transition\n *\n * counting: try to find one to one bijection to get an\
    \ object that is easier to count\n *\n *           sum of x * f(x) = sum of f(>\
    \ x) over x (cool trick!)\n *\n *           double counting principle\n *\n *\
    \           try to enumerate some parameters, and solve for each fix parameters\n\
    \ *\n *           group the objects by some characteristic and count for each\
    \ group\n *\n * sorting(?): adjacent swap(i, i + 1) -> inversion\n *\n *     \
    \        permutation swap(i, j) -> # of cycle\n *\n *             take then insert\
    \ -> LIS\n *\n * interactive: # of query may be a hint\n *\n *              try\
    \ to fix some element may be useful\n *\n * \"consider all pair\" problems: divide\
    \ and conquer, iterate R and maintain for all L\n */\n"
  code: "/**\n * template name: generalApproach\n * author: Misuki\n * last update:\
    \ 2023/04/22\n * note: these may be useful when I have completely no idea on a\
    \ problem D:\n *\n * think recursively\n *\n * draw a graph, observe the process\n\
    \ *\n * try to model the problem in the most general way\n *\n * find invariant\n\
    \ *\n * find equivalent condition\n *\n * observe a lower/upper bound, and try\
    \ to achieve that bound\n *\n * observe optimal structure (consider brute force\
    \ small case to see the structure may be a good choice)\n *\n * invent subtask\n\
    \ *\n * think what is important in the problem model\n *\n * think reversely\n\
    \ *\n * brute force small cases\n *\n * think of trivial solution than try to\
    \ optimize(especially for dp, atleast see the transition and try to optimize)\n\
    \ *\n * Problem Specific technique:\n * \n * expectation: linearity of expectation\
    \ to decompose problem into easier ones\n *\n * game theory: start from the end\
    \ state, bruteforce patterns, and observe the transition\n *\n * counting: try\
    \ to find one to one bijection to get an object that is easier to count\n *\n\
    \ *           sum of x * f(x) = sum of f(> x) over x (cool trick!)\n *\n *   \
    \        double counting principle\n *\n *           try to enumerate some parameters,\
    \ and solve for each fix parameters\n *\n *           group the objects by some\
    \ characteristic and count for each group\n *\n * sorting(?): adjacent swap(i,\
    \ i + 1) -> inversion\n *\n *             permutation swap(i, j) -> # of cycle\n\
    \ *\n *             take then insert -> LIS\n *\n * interactive: # of query may\
    \ be a hint\n *\n *              try to fix some element may be useful\n *\n *\
    \ \"consider all pair\" problems: divide and conquer, iterate R and maintain for\
    \ all L\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: generalApproach.cpp
  requiredBy: []
  timestamp: '2024-01-06 18:21:41+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: generalApproach.cpp
layout: document
redirect_from:
- /library/generalApproach.cpp
- /library/generalApproach.cpp.html
title: generalApproach.cpp
---
