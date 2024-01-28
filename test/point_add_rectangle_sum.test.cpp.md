---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/fenwickTree2D.cpp
    title: ds/fenwickTree2D.cpp
  - icon: ':question:'
    path: misc/compression.cpp
    title: compression
  - icon: ':x:'
    path: misc/pointAddRectangleSum.cpp
    title: misc/pointAddRectangleSum.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/point_add_rectangle_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\n#line 1 \"ds/fenwickTree2D.cpp\"\
    \n//source: KACTL\n\n/**\n * Author: Lukas Polacek\n * Date: 2009-10-30\n * License:\
    \ CC0\n * Source: folklore/TopCoder\n * Description: Computes partial sums a[0]\
    \ + a[1] + ... + a[pos - 1], and updates single elements a[i],\n * taking the\
    \ difference between the old and new value.\n * Time: Both operations are $O(\\\
    log N)$.\n * Status: Stress-tested\n */\ntemplate<class T>\nstruct FT {\n\tvector<T>\
    \ s;\n\tFT(int n) : s(n) {}\n\tvoid update(int pos, T dif) { // a[pos] += dif\n\
    \t\tfor (; pos < ssize(s); pos |= pos + 1) s[pos] += dif;\n\t}\n\tT query(int\
    \ pos) { // sum of values in [0, pos)\n\t\tT res = 0;\n\t\tfor (; pos > 0; pos\
    \ &= pos - 1) res += s[pos-1];\n\t\treturn res;\n\t}\n\tint lower_bound(T sum)\
    \ {// min pos st sum of [0, pos] >= sum\n\t\t// Returns n if no sum is >= sum,\
    \ or -1 if empty sum is.\n\t\tif (sum <= 0) return -1;\n\t\tint pos = 0;\n\t\t\
    for (int pw = 1 << 25; pw; pw >>= 1) {\n\t\t\tif (pos + pw <= ssize(s) && s[pos\
    \ + pw-1] < sum)\n\t\t\t\tpos += pw, sum -= s[pos-1];\n\t\t}\n\t\treturn pos;\n\
    \t}\n};\n\n/**\n * Author: Simon Lindholm\n * Date: 2017-05-11\n * License: CC0\n\
    \ * Source: folklore\n * Description: Computes sums a[i,j] for all i<I, j<J, and\
    \ increases single elements a[i,j].\n *  Requires that the elements to be updated\
    \ are known in advance (call fakeUpdate() before init()).\n * Time: $O(\\log^2\
    \ N)$. (Use persistent segment trees for $O(\\log N)$.)\n * Status: stress-tested\n\
    \ */\ntemplate<class T1, class T2>\nstruct FT2 {\n\tvector<vector<T1>> ys; vector<FT<T2>>\
    \ ft;\n\tFT2(int limx) : ys(limx) {}\n\tvoid fakeUpdate(int x, T1 y) {\n\t\tfor\
    \ (; x < ssize(ys); x |= x + 1) ys[x].push_back(y);\n\t}\n\tvoid init() {\n\t\t\
    for (vector<T1>& v : ys) R::sort(v), ft.emplace_back(ssize(v));\n\t}\n\tint ind(int\
    \ x, T1 y) {\n\t\treturn (int)(R::lower_bound(ys[x], y) - ys[x].begin()); }\n\t\
    void update(int x, T1 y, T2 dif) {\n\t\tfor (; x < ssize(ys); x |= x + 1)\n\t\t\
    \tft[x].update(ind(x, y), dif);\n\t}\n\tT2 query(int x, T1 y) {\n\t\tT2 sum =\
    \ 0;\n\t\tfor (; x; x &= x - 1)\n\t\t\tsum += ft[x-1].query(ind(x-1, y));\n\t\t\
    return sum;\n\t}\n};\n#line 1 \"misc/compression.cpp\"\ntemplate<class T, bool\
    \ duplicate = false>\nstruct compression {\n  vector<int> ord;\n  vector<T> val;\n\
    \n  compression(vector<T> &init) : val(init) { precompute(); }\n  compression(int\
    \ size = 0) { val.reserve(size); }\n\n  void precompute() {\n    vector<T> init\
    \ = val;\n    ord.resize(ssize(val));\n    R::sort(val);\n    if constexpr (duplicate)\
    \ {\n      vector<int> cnt(ssize(init));\n      iota(cnt.begin(), cnt.end(), 0);\n\
    \      for(int i = 0; i < ssize(ord); i++)\n        ord[i] = cnt[lower_bound(init[i])]++;\n\
    \    } else {\n      val.resize(unique(val.begin(), val.end()) - val.begin());\n\
    \      for(int i = 0; i < ssize(ord); i++)\n        ord[i] = lower_bound(init[i]);\n\
    \    }\n  }\n\n  int lower_bound(T x) { return R::lower_bound(val, x) - val.begin();\
    \ }\n  int size() { return ssize(val); }\n  template<R::range rng, class proj\
    \ = identity>\n  void mapping(rng &v, proj p = {}) { for(auto &x : v) p(x) = lower_bound(p(x));\
    \ }\n  template<R::range rng, class proj = identity>\n  void insert(rng &v, proj\
    \ p = {}) { for(auto &x : v) val.emplace_back(p(x)); }\n};\n#line 1 \"misc/pointAddRectangleSum.cpp\"\
    \n//#include<ds/fenwickTree2D.cpp>\n//#include<misc/compression.cpp>\n\ntemplate<class\
    \ T1, class T2>\nvector<T2> pointAddRectSum(vector<tuple<T1, T1, T2>> pt, vector<array<T1,\
    \ 4>> query, vector<int> updT) {\n  compression<T1> xs(ssize(pt));\n  xs.insert(pt,\
    \ [](auto &x) { return get<0>(x); });\n  xs.precompute();\n  xs.mapping(pt, [](auto\
    \ &x) -> T1& { return get<0>(x); });\n  xs.mapping(query, [](auto &x) -> T1& {\
    \ return x[0]; });\n  xs.mapping(query, [](auto &x) -> T1& { return x[1]; });\n\
    \n  FT2<T1, T2> bit(xs.size());\n  for(auto [x, y, __] : pt)\n    bit.fakeUpdate(x,\
    \ y);\n  bit.init();\n\n  vector<T2> ans(ssize(query));\n  for(int i = 0, ptr\
    \ = 0; auto [l, r, d, u] : query) {\n    while(ptr < ssize(pt) and updT[ptr] <=\
    \ i) {\n      auto [x, y, w] = pt[ptr++];\n      bit.update(x, y, w);\n    }\n\
    \    ans[i++] = bit.query(r, u) - bit.query(l, u) - bit.query(r, d) + bit.query(l,\
    \ d);\n  }\n  \n  return ans;\n}\n#line 6 \"test/point_add_rectangle_sum.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ q; cin >> n >> q;\n  vector<tuple<int, int, ll>> pt(n);\n  for(auto &[x, y,\
    \ w] : pt)\n    cin >> x >> y >> w;\n  vector<array<int, 4>> query;\n  vector<int>\
    \ updT(n);\n  while(q--) {\n    int t; cin >> t;\n    if (t == 0) {\n      int\
    \ x, y, w; cin >> x >> y >> w;\n      updT.emplace_back(ssize(query));\n     \
    \ pt.emplace_back(x, y, w);\n    } else if (t == 1) {\n      int l, r, d, u; cin\
    \ >> l >> d >> r >> u;\n      query.push_back({l, r, d, u});\n    }\n  }\n\n \
    \ for(ll x : pointAddRectSum<int, ll>(pt, query, updT))\n    cout << x << '\\\
    n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"../ds/fenwickTree2D.cpp\"\n#include \"../misc/compression.cpp\"\
    \n#include \"../misc/pointAddRectangleSum.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<tuple<int, int, ll>>\
    \ pt(n);\n  for(auto &[x, y, w] : pt)\n    cin >> x >> y >> w;\n  vector<array<int,\
    \ 4>> query;\n  vector<int> updT(n);\n  while(q--) {\n    int t; cin >> t;\n \
    \   if (t == 0) {\n      int x, y, w; cin >> x >> y >> w;\n      updT.emplace_back(ssize(query));\n\
    \      pt.emplace_back(x, y, w);\n    } else if (t == 1) {\n      int l, r, d,\
    \ u; cin >> l >> d >> r >> u;\n      query.push_back({l, r, d, u});\n    }\n \
    \ }\n\n  for(ll x : pointAddRectSum<int, ll>(pt, query, updT))\n    cout << x\
    \ << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - ds/fenwickTree2D.cpp
  - misc/compression.cpp
  - misc/pointAddRectangleSum.cpp
  isVerificationFile: true
  path: test/point_add_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-28 22:59:51+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/point_add_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/point_add_rectangle_sum.test.cpp
- /verify/test/point_add_rectangle_sum.test.cpp.html
title: test/point_add_rectangle_sum.test.cpp
---
