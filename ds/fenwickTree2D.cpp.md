---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/point_add_rectangle_sum.test.cpp
    title: test/point_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/rectangle_add_point_get.test.cpp
    title: test/rectangle_add_point_get.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/fenwickTree2D.cpp\"\n//source: KACTL\n\n/**\n * Author:\
    \ Lukas Polacek\n * Date: 2009-10-30\n * License: CC0\n * Source: folklore/TopCoder\n\
    \ * Description: Computes partial sums a[0] + a[1] + ... + a[pos - 1], and updates\
    \ single elements a[i],\n * taking the difference between the old and new value.\n\
    \ * Time: Both operations are $O(\\log N)$.\n * Status: Stress-tested\n */\ntemplate<class\
    \ T>\nstruct FT {\n\tvector<T> s;\n\tFT(int n) : s(n) {}\n\tvoid update(int pos,\
    \ T dif) { // a[pos] += dif\n\t\tfor (; pos < ssize(s); pos |= pos + 1) s[pos]\
    \ += dif;\n\t}\n\tT query(int pos) { // sum of values in [0, pos)\n\t\tT res =\
    \ 0;\n\t\tfor (; pos > 0; pos &= pos - 1) res += s[pos-1];\n\t\treturn res;\n\t\
    }\n\tint lower_bound(T sum) {// min pos st sum of [0, pos] >= sum\n\t\t// Returns\
    \ n if no sum is >= sum, or -1 if empty sum is.\n\t\tif (sum <= 0) return -1;\n\
    \t\tint pos = 0;\n\t\tfor (int pw = 1 << 25; pw; pw >>= 1) {\n\t\t\tif (pos +\
    \ pw <= ssize(s) && s[pos + pw-1] < sum)\n\t\t\t\tpos += pw, sum -= s[pos-1];\n\
    \t\t}\n\t\treturn pos;\n\t}\n};\n\n/**\n * Author: Simon Lindholm\n * Date: 2017-05-11\n\
    \ * License: CC0\n * Source: folklore\n * Description: Computes sums a[i,j] for\
    \ all i<I, j<J, and increases single elements a[i,j].\n *  Requires that the elements\
    \ to be updated are known in advance (call fakeUpdate() before init()).\n * Time:\
    \ $O(\\log^2 N)$. (Use persistent segment trees for $O(\\log N)$.)\n * Status:\
    \ stress-tested\n */\ntemplate<class T1, class T2>\nstruct FT2 {\n\tvector<vector<T1>>\
    \ ys; vector<FT<T2>> ft;\n\tFT2(int limx) : ys(limx) {}\n\tvoid fakeUpdate(int\
    \ x, T1 y) {\n\t\tfor (; x < ssize(ys); x |= x + 1) ys[x].push_back(y);\n\t}\n\
    \tvoid init() {\n\t\tfor (vector<T1>& v : ys) R::sort(v), ft.emplace_back(ssize(v));\n\
    \t}\n\tint ind(int x, T1 y) {\n\t\treturn (int)(R::lower_bound(ys[x], y) - ys[x].begin());\
    \ }\n\tvoid update(int x, T1 y, T2 dif) {\n\t\tfor (; x < ssize(ys); x |= x +\
    \ 1)\n\t\t\tft[x].update(ind(x, y), dif);\n\t}\n\tT2 query(int x, T1 y) {\n\t\t\
    T2 sum = 0;\n\t\tfor (; x; x &= x - 1)\n\t\t\tsum += ft[x-1].query(ind(x-1, y));\n\
    \t\treturn sum;\n\t}\n};\n"
  code: "//source: KACTL\n\n/**\n * Author: Lukas Polacek\n * Date: 2009-10-30\n *\
    \ License: CC0\n * Source: folklore/TopCoder\n * Description: Computes partial\
    \ sums a[0] + a[1] + ... + a[pos - 1], and updates single elements a[i],\n * taking\
    \ the difference between the old and new value.\n * Time: Both operations are\
    \ $O(\\log N)$.\n * Status: Stress-tested\n */\ntemplate<class T>\nstruct FT {\n\
    \tvector<T> s;\n\tFT(int n) : s(n) {}\n\tvoid update(int pos, T dif) { // a[pos]\
    \ += dif\n\t\tfor (; pos < ssize(s); pos |= pos + 1) s[pos] += dif;\n\t}\n\tT\
    \ query(int pos) { // sum of values in [0, pos)\n\t\tT res = 0;\n\t\tfor (; pos\
    \ > 0; pos &= pos - 1) res += s[pos-1];\n\t\treturn res;\n\t}\n\tint lower_bound(T\
    \ sum) {// min pos st sum of [0, pos] >= sum\n\t\t// Returns n if no sum is >=\
    \ sum, or -1 if empty sum is.\n\t\tif (sum <= 0) return -1;\n\t\tint pos = 0;\n\
    \t\tfor (int pw = 1 << 25; pw; pw >>= 1) {\n\t\t\tif (pos + pw <= ssize(s) &&\
    \ s[pos + pw-1] < sum)\n\t\t\t\tpos += pw, sum -= s[pos-1];\n\t\t}\n\t\treturn\
    \ pos;\n\t}\n};\n\n/**\n * Author: Simon Lindholm\n * Date: 2017-05-11\n * License:\
    \ CC0\n * Source: folklore\n * Description: Computes sums a[i,j] for all i<I,\
    \ j<J, and increases single elements a[i,j].\n *  Requires that the elements to\
    \ be updated are known in advance (call fakeUpdate() before init()).\n * Time:\
    \ $O(\\log^2 N)$. (Use persistent segment trees for $O(\\log N)$.)\n * Status:\
    \ stress-tested\n */\ntemplate<class T1, class T2>\nstruct FT2 {\n\tvector<vector<T1>>\
    \ ys; vector<FT<T2>> ft;\n\tFT2(int limx) : ys(limx) {}\n\tvoid fakeUpdate(int\
    \ x, T1 y) {\n\t\tfor (; x < ssize(ys); x |= x + 1) ys[x].push_back(y);\n\t}\n\
    \tvoid init() {\n\t\tfor (vector<T1>& v : ys) R::sort(v), ft.emplace_back(ssize(v));\n\
    \t}\n\tint ind(int x, T1 y) {\n\t\treturn (int)(R::lower_bound(ys[x], y) - ys[x].begin());\
    \ }\n\tvoid update(int x, T1 y, T2 dif) {\n\t\tfor (; x < ssize(ys); x |= x +\
    \ 1)\n\t\t\tft[x].update(ind(x, y), dif);\n\t}\n\tT2 query(int x, T1 y) {\n\t\t\
    T2 sum = 0;\n\t\tfor (; x; x &= x - 1)\n\t\t\tsum += ft[x-1].query(ind(x-1, y));\n\
    \t\treturn sum;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/fenwickTree2D.cpp
  requiredBy: []
  timestamp: '2024-01-28 03:46:27+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/point_add_rectangle_sum.test.cpp
  - test/rectangle_add_point_get.test.cpp
documentation_of: ds/fenwickTree2D.cpp
layout: document
redirect_from:
- /library/ds/fenwickTree2D.cpp
- /library/ds/fenwickTree2D.cpp.html
title: ds/fenwickTree2D.cpp
---
