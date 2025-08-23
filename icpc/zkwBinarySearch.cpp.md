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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ icpc/zkwBinarySearch.cpp: line 15: #pragma once found in a non-first line\n"
  code: "/**\n * Author: Nalime\n * Date: 2023-09-04\n * License: CC0\n * Source:\
    \ Myself\n * Description: A general way to tree walk on ZKW lazy segment tree.\n\
    \ *  This implementation requires $N$ to be\n *  an \\textbf{integral power of}\
    \ $\\mathbf{2}$.\n *  You need to separate out the single node pushdown logic\n\
    \ *  from \\texttt{push} to \\texttt{push0}.\n *  \\texttt{operator<} also needs\
    \ to be defined for \\texttt{T1}.\n * Time: O(\\log N).\n * Status: AC on Codeforces\
    \ EDU segment tree 2-3-C\n */\n#pragma once\n\n//#include \"homemade/segmentTreeLazy.h\"\
    \n\nint first(int i, M x) {\n  M y = Mid();\n  for (push(i += size);; i >>= 1)\
    \ if (i & 1) { // if is necessary\n    if (M z = Mop(y, data[i]); z < x) {\n \
    \     if ((i & (i + 1)) == 0) return -1; // fail on rightmost\n      y = z, i++;\n\
    \    } else break;\n  }\n  while (i < size) {\n    if (tag[i] != Tid()) {\n  \
    \    apply(i << 1, tag[i]), apply(i << 1 | 1, tag[i]);\n      tag[i] = Tid();\n\
    \    }\n    if (M z = Mop(y, data[i <<= 1]); z < x) y = z, i++;\n  }\n  return\
    \ i - size;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: icpc/zkwBinarySearch.cpp
  requiredBy: []
  timestamp: '2025-08-23 17:44:45+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc/zkwBinarySearch.cpp
layout: document
redirect_from:
- /library/icpc/zkwBinarySearch.cpp
- /library/icpc/zkwBinarySearch.cpp.html
title: icpc/zkwBinarySearch.cpp
---
