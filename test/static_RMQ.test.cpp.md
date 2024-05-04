---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/sparseTable.cpp
    title: ds/sparseTable.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/static_RMQ.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
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
    \nusing namespace std;\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ldb = long double;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\
    \ntemplate<class T>\nostream& operator<<(ostream& os, const pair<T, T> pr) {\n\
    \  return os << pr.first << ' ' << pr.second;\n}\ntemplate<class T, size_t N>\n\
    ostream& operator<<(ostream& os, const array<T, N> &arr) {\n  for(const T &X :\
    \ arr)\n    os << X << ' ';\n  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream&\
    \ os, const vector<T> &vec) {\n  for(const T &X : vec)\n    os << X << ' ';\n\
    \  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const set<T>\
    \ &s) {\n  for(const T &x : s)\n    os << x << ' ';\n  return os;\n}\n#line 1\
    \ \"ds/sparseTable.cpp\"\ntemplate<class T>\nstruct sparseTable{\n  vector<vector<T>\
    \ > table;\n  function<T(const T&, const T&)> comb;\n  int size = 0;\n\n  sparseTable(vector<T>\
    \ base, function<T(const T&, const T&)> _comb) {\n    comb = _comb;\n    size\
    \ = base.size();\n    table.resize(bit_width((unsigned)size), std::vector<T>(size));\n\
    \    \n    table[0] = base;\n    for(int i = 1; i < ssize(table); i++) {\n   \
    \   for(int j = 0; j < size; j++) {\n        if (j + (1 << (i - 1)) < size)\n\
    \          table[i][j] = comb(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n\
    \        else\n          table[i][j] = table[i - 1][j];\n      }\n    }\n  }\n\
    \n  T query(int l, int r) {\n    int range = bit_width((unsigned)(r - l)) - 1;\n\
    \    return comb(table[range][l], table[range][r - (1 << range)]);\n  }\n};\n\
    #line 5 \"test/static_RMQ.test.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<int> a(n);\n  for(int\
    \ &x : a)\n    cin >> x;\n  sparseTable<int> st(a, [](const int &x, const int\
    \ &y) { return min(x, y); });\n  while(q--) {\n    int l, r; cin >> l >> r;\n\
    \    cout << st.query(l, r) << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../default/t.cpp\"\n#include \"../ds/sparseTable.cpp\"\n\nsigned main() {\n\
    \  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n\
    \  vector<int> a(n);\n  for(int &x : a)\n    cin >> x;\n  sparseTable<int> st(a,\
    \ [](const int &x, const int &y) { return min(x, y); });\n  while(q--) {\n   \
    \ int l, r; cin >> l >> r;\n    cout << st.query(l, r) << '\\n';\n  }\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - ds/sparseTable.cpp
  isVerificationFile: true
  path: test/static_RMQ.test.cpp
  requiredBy: []
  timestamp: '2024-04-05 18:02:52+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/static_RMQ.test.cpp
layout: document
redirect_from:
- /verify/test/static_RMQ.test.cpp
- /verify/test/static_RMQ.test.cpp.html
title: test/static_RMQ.test.cpp
---
