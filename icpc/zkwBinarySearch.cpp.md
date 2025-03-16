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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ icpc/zkwBinarySearch.cpp: line 15: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Nalime\n * Date: 2023-09-04\n * License: CC0\n * Source:\
    \ Myself\n * Description: A general way to tree walk on ZKW lazy segment tree.\n\
    \ *\tThis implementation requires $N$ to be\n *\tan \\textbf{integral power of}\
    \ $\\mathbf{2}$.\n *\tYou need to separate out the single node pushdown logic\n\
    \ *\tfrom \\texttt{push} to \\texttt{push0}.\n *\t\\texttt{operator<} also needs\
    \ to be defined for \\texttt{T1}.\n * Time: O(\\log N).\n * Status: AC on Codeforces\
    \ EDU segment tree 2-3-C\n */\n#pragma once\n\n#include \"homemade/segmentTreeLazy.h\"\
    \n\nint first(int i, M x) {\n\tM y = Mid();\n\tfor (push(i += size);; i >>= 1)\
    \ if (i & 1) { // if is necessary\n\t\tif (M z = Mop(y, data[i]); z < x) {\n\t\
    \t\tif ((i & (i + 1)) == 0) return -1; // fail on rightmost\n\t\t\ty = z, i++;\n\
    \t\t} else break;\n\t}\n\twhile (i < size) {\n\t\tif (tag[i] != Tid()) {\n\t\t\
    \tapply(i << 1, tag[i]), apply(i << 1 | 1, tag[i]);\n\t\t\ttag[i] = Tid();\n\t\
    \t}\n\t\tif (M z = Mop(y, data[i <<= 1]); z < x) y = z, i++;\n\t}\n\treturn i\
    \ - size;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: icpc/zkwBinarySearch.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc/zkwBinarySearch.cpp
layout: document
redirect_from:
- /library/icpc/zkwBinarySearch.cpp
- /library/icpc/zkwBinarySearch.cpp.html
title: icpc/zkwBinarySearch.cpp
---
