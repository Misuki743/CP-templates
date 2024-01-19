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
  bundledCode: "#line 1 \"segtree/segmentTree2D.cpp\"\n/**\n * template name: segmentTree2D\n\
    \ * author: Misuki\n * last update: 2022/05/08\n */\n\ntemplate<class T> \nstruct\
    \ segmentTree2D {\n  static const int MAXR = 2000;\n  static const int MAXC =\
    \ 2000;\n  function<T(const T&, const T&)> combine;\n  T UNIT;\n  T arr[2 * MAXR][2\
    \ * MAXC];\n  int szR, szC;\n\n  segmentTree2D(int _szR, int _szC, T _UNIT, function<T(const\
    \ T&, const T&)> _combine) {\n    szR = _szR, szC = _szC;\n    UNIT = _UNIT;\n\
    \    combine = _combine;\n    for(int i = 0; i < 2 * szR; i++)\n      fill(arr[i],\
    \ arr[i] + 2 * szC, UNIT);\n  }\n\n  void set(int x, int y, T val) {\n    x +=\
    \ szR;\n    set2(x, y, val);\n    x >>= 1;\n    while(x) {\n      set2(x, y, val);\n\
    \      x >>= 1;\n    }\n  }\n\n  void set2(int x, int y, T val) {\n    y += szC;\n\
    \    arr[x][y] = combine(arr[x][y], val);\n    y >>= 1;\n    while(y) {\n    \
    \  arr[x][y] = combine(arr[x][y<<1], arr[x][y<<1|1]);\n      y >>= 1;\n    }\n\
    \  }\n\n  T query(int x1, int x2, int y1, int y2) {\n    T L = UNIT, R = UNIT;\n\
    \    for(x1 += szR, x2 += szR; x1 < x2; x1 >>= 1, x2 >>= 1) {\n      if (x1 &\
    \ 1) L = combine(L, query2(x1++, y1, y2));\n      if (x2 & 1) R = combine(query2(--x2,\
    \ y1, y2), R);\n    }\n    return combine(L, R);\n  }\n  \n  T query2(int x, int\
    \ y1, int y2) {\n    T L = UNIT, R = UNIT;\n    for(y1 += szC, y2 += szC; y1 <\
    \ y2; y1 >>= 1, y2 >>= 1) {\n      if (y1 & 1) L = combine(L, arr[x][y1++]);\n\
    \      if (y2 & 1) R = combine(arr[x][--y2], R);\n    }\n    return combine(L,\
    \ R);\n  }\n};\n"
  code: "/**\n * template name: segmentTree2D\n * author: Misuki\n * last update:\
    \ 2022/05/08\n */\n\ntemplate<class T> \nstruct segmentTree2D {\n  static const\
    \ int MAXR = 2000;\n  static const int MAXC = 2000;\n  function<T(const T&, const\
    \ T&)> combine;\n  T UNIT;\n  T arr[2 * MAXR][2 * MAXC];\n  int szR, szC;\n\n\
    \  segmentTree2D(int _szR, int _szC, T _UNIT, function<T(const T&, const T&)>\
    \ _combine) {\n    szR = _szR, szC = _szC;\n    UNIT = _UNIT;\n    combine = _combine;\n\
    \    for(int i = 0; i < 2 * szR; i++)\n      fill(arr[i], arr[i] + 2 * szC, UNIT);\n\
    \  }\n\n  void set(int x, int y, T val) {\n    x += szR;\n    set2(x, y, val);\n\
    \    x >>= 1;\n    while(x) {\n      set2(x, y, val);\n      x >>= 1;\n    }\n\
    \  }\n\n  void set2(int x, int y, T val) {\n    y += szC;\n    arr[x][y] = combine(arr[x][y],\
    \ val);\n    y >>= 1;\n    while(y) {\n      arr[x][y] = combine(arr[x][y<<1],\
    \ arr[x][y<<1|1]);\n      y >>= 1;\n    }\n  }\n\n  T query(int x1, int x2, int\
    \ y1, int y2) {\n    T L = UNIT, R = UNIT;\n    for(x1 += szR, x2 += szR; x1 <\
    \ x2; x1 >>= 1, x2 >>= 1) {\n      if (x1 & 1) L = combine(L, query2(x1++, y1,\
    \ y2));\n      if (x2 & 1) R = combine(query2(--x2, y1, y2), R);\n    }\n    return\
    \ combine(L, R);\n  }\n  \n  T query2(int x, int y1, int y2) {\n    T L = UNIT,\
    \ R = UNIT;\n    for(y1 += szC, y2 += szC; y1 < y2; y1 >>= 1, y2 >>= 1) {\n  \
    \    if (y1 & 1) L = combine(L, arr[x][y1++]);\n      if (y2 & 1) R = combine(arr[x][--y2],\
    \ R);\n    }\n    return combine(L, R);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/segmentTree2D.cpp
  requiredBy: []
  timestamp: '2024-01-20 02:52:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segtree/segmentTree2D.cpp
layout: document
redirect_from:
- /library/segtree/segmentTree2D.cpp
- /library/segtree/segmentTree2D.cpp.html
title: segtree/segmentTree2D.cpp
---
