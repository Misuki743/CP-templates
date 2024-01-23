---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: segtree/lichaoSegmentTree.cpp
    title: segtree/lichaoSegmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/line_add_get_min.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\
    \n\n#line 1 \"default/t.cpp\"\n#include <algorithm>\n#include <array>\n#include\
    \ <bit>\n#include <bitset>\n#include <cassert>\n#include <cctype>\n#include <cfenv>\n\
    #include <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include <climits>\n\
    #include <cmath>\n#include <compare>\n#include <complex>\n#include <concepts>\n\
    #include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include <cstdio>\n\
    #include <cstdlib>\n#include <cstring>\n#include <deque>\n#include <fstream>\n\
    #include <functional>\n#include <initializer_list>\n#include <iomanip>\n#include\
    \ <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n#include\
    \ <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include <new>\n\
    #include <numbers>\n#include <numeric>\n#include <ostream>\n#include <queue>\n\
    #include <random>\n#include <ranges>\n#include <set>\n#include <span>\n#include\
    \ <sstream>\n#include <stack>\n#include <streambuf>\n#include <string>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <variant>\n\n#define INT128_MAX (__int128)(((unsigned\
    \ __int128) 1 << ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN\
    \ (-INT128_MAX - 1)\n\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
    \nnamespace R = std::ranges;\nnamespace V = std::views;\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing ull = unsigned long long;\nusing ldb = long double;\n\
    using pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate<class T>\n\
    ostream& operator<<(ostream& os, const pair<T, T> pr) {\n  return os << pr.first\
    \ << ' ' << pr.second;\n}\ntemplate<class T, size_t N>\nostream& operator<<(ostream&\
    \ os, const array<T, N> &arr) {\n  for(const T &X : arr)\n    os << X << ' ';\n\
    \  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const vector<T>\
    \ &vec) {\n  for(const T &X : vec)\n    os << X << ' ';\n  return os;\n}\ntemplate<class\
    \ T>\nostream& operator<<(ostream& os, const set<T> &s) {\n  for(const T &x :\
    \ s)\n    os << x << ' ';\n  return os;\n}\n#line 1 \"segtree/lichaoSegmentTree.cpp\"\
    \n/**\n * template name: lichaoSegmentTree\n * author: Misuki\n * last update:\
    \ 2024/01/01\n * note: size should be power of 2\n *       finding min line in\
    \ default\n * verify: Library Checker - Line Add Get Min\n *         Library Checker\
    \ - Segment Add Get Min\n */\n\ntemplate<class M, M unit>\nstruct lichaoSegmentTree\
    \ {\n  vector<array<M, 2>> data;\n  vector<M> xMid;\n  unsigned size;\n\n  lichaoSegmentTree(unsigned\
    \ _size, vector<M> x = vector<M>()) : data(2 * _size, {0, unit}), xMid(2 * _size),\
    \ size(_size) {\n    assert(popcount(size) == 1);\n    if (x.empty()) {\n    \
    \  iota(xMid.begin() + size, xMid.end(), 0);\n    } else {\n      copy(x.begin(),\
    \ x.end(), xMid.begin() + size);\n      fill(xMid.begin() + size + ssize(x), xMid.end(),\
    \ x.back());\n    }\n    vector<int> r(2 * size);\n    iota(r.begin() + size,\
    \ r.end(), size);\n    for(int i = size - 1; i > 0; i--)\n      r[i] = r[i <<\
    \ 1 | 1];\n    for(int i = size - 1; i > 0; i--)\n      xMid[i] = (xMid[r[i <<\
    \ 1]] + xMid[r[i << 1] + 1]) / 2;\n  }\n\n  M eval(M a, M b, M x) { return a *\
    \ x + b; }\n\n  void insert(int v, M a, M b) {\n    if (a > data[v][0]) {\n  \
    \    swap(a, data[v][0]);\n      swap(b, data[v][1]);\n    }\n\n    if (v >= size)\
    \ {\n      if (eval(a, b, xMid[v]) < eval(data[v][0], data[v][1], xMid[v])) {\n\
    \        swap(a, data[v][0]);\n        swap(b, data[v][1]);\n      }\n      return;\n\
    \    }\n\n    if (eval(a, b, xMid[v]) > eval(data[v][0], data[v][1], xMid[v]))\
    \ {\n      insert(v << 1 | 1, a, b);\n    } else {\n      swap(a, data[v][0]);\n\
    \      swap(b, data[v][1]);\n      insert(v << 1, a, b);\n    }\n  }\n\n  M query(int\
    \ v) {\n    v += size;\n    M ans = unit;\n    int x = xMid[v];\n    while(v >=\
    \ 1)\n      ans = min(ans, eval(data[v][0], data[v][1], x)), v >>= 1;\n    return\
    \ ans;\n  }\n\n  void insertRange(int l, int r, M a, M b) {\n    for(l += size,\
    \ r += size; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) insert(l++, a, b);\n\
    \      if (r & 1) insert(--r, a, b);\n    }\n  }\n};\n#line 5 \"test/line_add_get_min.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ q; cin >> n >> q;\n  vector<array<ll, 2>> ab(n);\n  for(auto &[a, b] : ab)\n\
    \    cin >> a >> b;\n  vector<array<ll, 3>> query(q);\n  for(auto &[t, a, b] :\
    \ query) {\n    cin >> t >> a;\n    if (t == 0)\n      cin >> b;\n  }\n\n  vector<ll>\
    \ pt;\n  for(auto [t, a, b] : query)\n    if (t == 1)\n      pt.emplace_back(a);\n\
    \n  R::sort(pt);\n  pt.resize(unique(pt.begin(), pt.end()) - pt.begin());\n  for(auto\
    \ &[t, a, b] : query)\n    if (t == 1)\n      a = R::lower_bound(pt, a) - pt.begin();\n\
    \n  lichaoSegmentTree<ll, LLONG_MAX> st(bit_ceil((unsigned)q), pt);\n  for(auto\
    \ [a, b] : ab)\n    st.insert(1, a, b);\n  for(auto [t, a, b] : query) {\n   \
    \ if (t == 0)\n      st.insert(1, a, b);\n    else\n      cout << st.query(a)\
    \ << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include \"../default/t.cpp\"\n#include \"../segtree/lichaoSegmentTree.cpp\"\n\
    \nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q;\
    \ cin >> n >> q;\n  vector<array<ll, 2>> ab(n);\n  for(auto &[a, b] : ab)\n  \
    \  cin >> a >> b;\n  vector<array<ll, 3>> query(q);\n  for(auto &[t, a, b] : query)\
    \ {\n    cin >> t >> a;\n    if (t == 0)\n      cin >> b;\n  }\n\n  vector<ll>\
    \ pt;\n  for(auto [t, a, b] : query)\n    if (t == 1)\n      pt.emplace_back(a);\n\
    \n  R::sort(pt);\n  pt.resize(unique(pt.begin(), pt.end()) - pt.begin());\n  for(auto\
    \ &[t, a, b] : query)\n    if (t == 1)\n      a = R::lower_bound(pt, a) - pt.begin();\n\
    \n  lichaoSegmentTree<ll, LLONG_MAX> st(bit_ceil((unsigned)q), pt);\n  for(auto\
    \ [a, b] : ab)\n    st.insert(1, a, b);\n  for(auto [t, a, b] : query) {\n   \
    \ if (t == 0)\n      st.insert(1, a, b);\n    else\n      cout << st.query(a)\
    \ << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - segtree/lichaoSegmentTree.cpp
  isVerificationFile: true
  path: test/line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2024-01-21 17:57:21+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/line_add_get_min.test.cpp
- /verify/test/line_add_get_min.test.cpp.html
title: test/line_add_get_min.test.cpp
---
