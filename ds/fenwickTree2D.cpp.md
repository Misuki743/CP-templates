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
  bundledCode: "#line 1 \"ds/fenwickTree2D.cpp\"\n/**\n * Author: Lukas Polacek\n\
    \ * Date: 2009-10-30\n * License: CC0\n * Source: folklore/TopCoder\n * Description:\
    \ Computes partial sums a[0] + a[1] + ... + a[pos - 1], and updates single elements\
    \ a[i],\n * taking the difference between the old and new value.\n * Time: Both\
    \ operations are $O(\\log N)$.\n * Status: Stress-tested\n */\nstruct FT {\n\t\
    vector<ll> s;\n\tFT(int n) : s(n) {}\n\tvoid update(int pos, ll dif) { // a[pos]\
    \ += dif\n\t\tfor (; pos < sz(s); pos |= pos + 1) s[pos] += dif;\n\t}\n\tll query(int\
    \ pos) { // sum of values in [0, pos)\n\t\tll res = 0;\n\t\tfor (; pos > 0; pos\
    \ &= pos - 1) res += s[pos-1];\n\t\treturn res;\n\t}\n\tint lower_bound(ll sum)\
    \ {// min pos st sum of [0, pos] >= sum\n\t\t// Returns n if no sum is >= sum,\
    \ or -1 if empty sum is.\n\t\tif (sum <= 0) return -1;\n\t\tint pos = 0;\n\t\t\
    for (int pw = 1 << 25; pw; pw >>= 1) {\n\t\t\tif (pos + pw <= sz(s) && s[pos +\
    \ pw-1] < sum)\n\t\t\t\tpos += pw, sum -= s[pos-1];\n\t\t}\n\t\treturn pos;\n\t\
    }\n};\n\n/**\n * Author: Simon Lindholm\n * Date: 2017-05-11\n * License: CC0\n\
    \ * Source: folklore\n * Description: Computes sums a[i,j] for all i<I, j<J, and\
    \ increases single elements a[i,j].\n *  Requires that the elements to be updated\
    \ are known in advance (call fakeUpdate() before init()).\n * Time: $O(\\log^2\
    \ N)$. (Use persistent segment trees for $O(\\log N)$.)\n * Status: stress-tested\n\
    \ */\nstruct FT2 {\n\tvector<vi> ys; vector<FT> ft;\n\tFT2(int limx) : ys(limx)\
    \ {}\n\tvoid fakeUpdate(int x, int y) {\n\t\tfor (; x < sz(ys); x |= x + 1) ys[x].push_back(y);\n\
    \t}\n\tvoid init() {\n\t\tfor (vi& v : ys) sort(all(v)), ft.emplace_back(sz(v));\n\
    \t}\n\tint ind(int x, int y) {\n\t\treturn (int)(lower_bound(all(ys[x]), y) -\
    \ ys[x].begin()); }\n\tvoid update(int x, int y, ll dif) {\n\t\tfor (; x < sz(ys);\
    \ x |= x + 1)\n\t\t\tft[x].update(ind(x, y), dif);\n\t}\n\tll query(int x, int\
    \ y) {\n\t\tll sum = 0;\n\t\tfor (; x; x &= x - 1)\n\t\t\tsum += ft[x-1].query(ind(x-1,\
    \ y));\n\t\treturn sum;\n\t}\n};\n"
  code: "/**\n * Author: Lukas Polacek\n * Date: 2009-10-30\n * License: CC0\n * Source:\
    \ folklore/TopCoder\n * Description: Computes partial sums a[0] + a[1] + ... +\
    \ a[pos - 1], and updates single elements a[i],\n * taking the difference between\
    \ the old and new value.\n * Time: Both operations are $O(\\log N)$.\n * Status:\
    \ Stress-tested\n */\nstruct FT {\n\tvector<ll> s;\n\tFT(int n) : s(n) {}\n\t\
    void update(int pos, ll dif) { // a[pos] += dif\n\t\tfor (; pos < sz(s); pos |=\
    \ pos + 1) s[pos] += dif;\n\t}\n\tll query(int pos) { // sum of values in [0,\
    \ pos)\n\t\tll res = 0;\n\t\tfor (; pos > 0; pos &= pos - 1) res += s[pos-1];\n\
    \t\treturn res;\n\t}\n\tint lower_bound(ll sum) {// min pos st sum of [0, pos]\
    \ >= sum\n\t\t// Returns n if no sum is >= sum, or -1 if empty sum is.\n\t\tif\
    \ (sum <= 0) return -1;\n\t\tint pos = 0;\n\t\tfor (int pw = 1 << 25; pw; pw >>=\
    \ 1) {\n\t\t\tif (pos + pw <= sz(s) && s[pos + pw-1] < sum)\n\t\t\t\tpos += pw,\
    \ sum -= s[pos-1];\n\t\t}\n\t\treturn pos;\n\t}\n};\n\n/**\n * Author: Simon Lindholm\n\
    \ * Date: 2017-05-11\n * License: CC0\n * Source: folklore\n * Description: Computes\
    \ sums a[i,j] for all i<I, j<J, and increases single elements a[i,j].\n *  Requires\
    \ that the elements to be updated are known in advance (call fakeUpdate() before\
    \ init()).\n * Time: $O(\\log^2 N)$. (Use persistent segment trees for $O(\\log\
    \ N)$.)\n * Status: stress-tested\n */\nstruct FT2 {\n\tvector<vi> ys; vector<FT>\
    \ ft;\n\tFT2(int limx) : ys(limx) {}\n\tvoid fakeUpdate(int x, int y) {\n\t\t\
    for (; x < sz(ys); x |= x + 1) ys[x].push_back(y);\n\t}\n\tvoid init() {\n\t\t\
    for (vi& v : ys) sort(all(v)), ft.emplace_back(sz(v));\n\t}\n\tint ind(int x,\
    \ int y) {\n\t\treturn (int)(lower_bound(all(ys[x]), y) - ys[x].begin()); }\n\t\
    void update(int x, int y, ll dif) {\n\t\tfor (; x < sz(ys); x |= x + 1)\n\t\t\t\
    ft[x].update(ind(x, y), dif);\n\t}\n\tll query(int x, int y) {\n\t\tll sum = 0;\n\
    \t\tfor (; x; x &= x - 1)\n\t\t\tsum += ft[x-1].query(ind(x-1, y));\n\t\treturn\
    \ sum;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/fenwickTree2D.cpp
  requiredBy: []
  timestamp: '2024-01-20 02:52:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/fenwickTree2D.cpp
layout: document
redirect_from:
- /library/ds/fenwickTree2D.cpp
- /library/ds/fenwickTree2D.cpp.html
title: ds/fenwickTree2D.cpp
---
