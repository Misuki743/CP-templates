---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':question:'
    path: ds/fenwickTree2D.cpp
    title: ds/fenwickTree2D.cpp
  - icon: ':question:'
    path: misc/compression.cpp
    title: compression
  - icon: ':x:'
    path: misc/rectangleAddPointGet.cpp
    title: misc/rectangleAddPointGet.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_add_point_get
    links:
    - https://judge.yosupo.jp/problem/rectangle_add_point_get
  bundledCode: "#line 1 \"test/rectangle_add_point_get.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/rectangle_add_point_get\"\n\n#line 1 \"default/t.cpp\"\
    \n#include <algorithm>\n#include <array>\n#include <bit>\n#include <bitset>\n\
    #include <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <compare>\n#include <complex>\n#include <concepts>\n#include <cstdarg>\n#include\
    \ <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include\
    \ <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
    \ <initializer_list>\n#include <iomanip>\n#include <ios>\n#include <iostream>\n\
    #include <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n\
    #include <map>\n#include <memory>\n#include <new>\n#include <numbers>\n#include\
    \ <numeric>\n#include <ostream>\n#include <queue>\n#include <random>\n#include\
    \ <ranges>\n#include <set>\n#include <span>\n#include <sstream>\n#include <stack>\n\
    #include <streambuf>\n#include <string>\n#include <tuple>\n#include <type_traits>\n\
    #include <variant>\n\n#define INT128_MAX (__int128)(((unsigned __int128) 1 <<\
    \ ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN (-INT128_MAX\
    \ - 1)\n\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
    \nnamespace R = std::ranges;\nnamespace V = std::views;\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing ull = unsigned long long;\nusing ldb = long double;\n\
    using pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate<class T>\n\
    ostream& operator<<(ostream& os, const pair<T, T> pr) {\n  return os << pr.first\
    \ << ' ' << pr.second;\n}\ntemplate<class T, size_t N>\nostream& operator<<(ostream&\
    \ os, const array<T, N> &arr) {\n  for(const T &X : arr)\n    os << X << ' ';\n\
    \  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const vector<T>\
    \ &vec) {\n  for(const T &X : vec)\n    os << X << ' ';\n  return os;\n}\ntemplate<class\
    \ T>\nostream& operator<<(ostream& os, const set<T> &s) {\n  for(const T &x :\
    \ s)\n    os << x << ' ';\n  return os;\n}\n#line 1 \"ds/fenwickTree2D.cpp\"\n\
    //source: KACTL\n\n/**\n * Author: Lukas Polacek\n * Date: 2009-10-30\n * License:\
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
    \ p = {}) { for(auto &x : v) val.emplace_back(p(x)); }\n};\n#line 1 \"misc/rectangleAddPointGet.cpp\"\
    \n//#include<ds/fenwickTree2D.cpp>\n//#include<misc/compression.cpp>\n\ntemplate<class\
    \ T1, class T2>\nvector<T2> rectAddPointGet(vector<tuple<T1, T1, T1, T1, T2>>\
    \ &rect, vector<array<T1, 2>> &query, vector<int> updT) {\n  compression<T1> xs(ssize(query));\n\
    \  xs.insert(query, [](auto &x) { return x[0]; });\n  xs.precompute();\n  xs.mapping(query,\
    \ [](auto &x) -> T1& { return x[0]; });\n  xs.mapping(rect, [](auto &x) -> T1&\
    \ { return get<0>(x); });\n  xs.mapping(rect, [](auto &x) -> T1& { return get<1>(x);\
    \ });\n\n  FT2<T1, T2> bit(xs.size());\n  for(auto &[l, r, d, u, w] : rect) {\n\
    \    bit.fakeUpdate(l, d);\n    bit.fakeUpdate(r, u);\n    bit.fakeUpdate(l, u);\n\
    \    bit.fakeUpdate(r, d);\n  }\n  bit.init();\n\n  vector<T2> ans(ssize(query));\n\
    \  for(int i = 0, ptr = 0; auto &[x, y] : query) {\n    while(ptr < ssize(rect)\
    \ and updT[ptr] <= i) {\n      auto [l, r, d, u, w] = rect[ptr++];\n      bit.update(l,\
    \ d, w);\n      bit.update(r, u, w);\n      bit.update(l, u, -w);\n      bit.update(r,\
    \ d, -w);\n    }\n    ans[i++] = bit.query(x + 1, y + 1);\n  }\n\n  return ans;\n\
    }\n#line 7 \"test/rectangle_add_point_get.test.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<tuple<int, int, int,\
    \ int, ll>> rect(n);\n  for(auto &[l, r, d, u, w] : rect)\n    cin >> l >> d >>\
    \ r >> u >> w;\n  vector<array<int, 2>> query;\n  vector<int> updT(n, 0);\n  while(q--)\
    \ {\n    int op; cin >> op;\n    if (op == 0) {\n      int l, d, r, u; cin >>\
    \ l >> d >> r >> u;\n      ll w; cin >> w;\n      rect.emplace_back(l, r, d, u,\
    \ w);\n      updT.emplace_back(ssize(query));\n    } else if (op == 1) {\n   \
    \   int x, y; cin >> x >> y;\n      query.push_back({x, y});\n    }\n  }\n\n \
    \ for(ll ans : rectAddPointGet<int, ll, INT_MAX>(rect, query, updT))\n    cout\
    \ << ans << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_add_point_get\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../ds/fenwickTree2D.cpp\"\n#include\
    \ \"../misc/compression.cpp\"\n#include \"../misc/rectangleAddPointGet.cpp\"\n\
    \nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q;\
    \ cin >> n >> q;\n  vector<tuple<int, int, int, int, ll>> rect(n);\n  for(auto\
    \ &[l, r, d, u, w] : rect)\n    cin >> l >> d >> r >> u >> w;\n  vector<array<int,\
    \ 2>> query;\n  vector<int> updT(n, 0);\n  while(q--) {\n    int op; cin >> op;\n\
    \    if (op == 0) {\n      int l, d, r, u; cin >> l >> d >> r >> u;\n      ll\
    \ w; cin >> w;\n      rect.emplace_back(l, r, d, u, w);\n      updT.emplace_back(ssize(query));\n\
    \    } else if (op == 1) {\n      int x, y; cin >> x >> y;\n      query.push_back({x,\
    \ y});\n    }\n  }\n\n  for(ll ans : rectAddPointGet<int, ll, INT_MAX>(rect, query,\
    \ updT))\n    cout << ans << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - ds/fenwickTree2D.cpp
  - misc/compression.cpp
  - misc/rectangleAddPointGet.cpp
  isVerificationFile: true
  path: test/rectangle_add_point_get.test.cpp
  requiredBy: []
  timestamp: '2024-01-28 23:19:06+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/rectangle_add_point_get.test.cpp
layout: document
redirect_from:
- /verify/test/rectangle_add_point_get.test.cpp
- /verify/test/rectangle_add_point_get.test.cpp.html
title: test/rectangle_add_point_get.test.cpp
---
