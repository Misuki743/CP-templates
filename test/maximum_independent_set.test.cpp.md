---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: graph/MIS.cpp
    title: graph/MIS.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/maximum_independent_set
    links:
    - https://judge.yosupo.jp/problem/maximum_independent_set
  bundledCode: "#line 1 \"test/maximum_independent_set.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/maximum_independent_set\"\n\n#line 1 \"default/t.cpp\"\
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
    \nusing namespace std;\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ldb = long double;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\
    \ntemplate<class T>\nostream& operator<<(ostream& os, const pair<T, T> pr) {\n\
    \  return os << pr.first << ' ' << pr.second;\n}\ntemplate<class T, size_t N>\n\
    ostream& operator<<(ostream& os, const array<T, N> &arr) {\n  for(const T &X :\
    \ arr)\n    os << X << ' ';\n  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream&\
    \ os, const vector<T> &vec) {\n  for(const T &X : vec)\n    os << X << ' ';\n\
    \  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const set<T>\
    \ &s) {\n  for(const T &x : s)\n    os << x << ' ';\n  return os;\n}\n#line 1\
    \ \"graph/MIS.cpp\"\nvector<int> MIS(vector<ull> g, int n) {\n  vector<unsigned>\
    \ pre(1 << (n / 2));\n  for(unsigned msk = 0; msk < (1 << (n / 2)); msk++) {\n\
    \    int adj = 0;\n    for(int v = 0; v < n / 2; v++)\n      if (msk >> v & 1)\n\
    \        adj |= g[v];\n    if (!(adj & msk))\n      pre[msk] = msk;\n  }\n  for(int\
    \ i = 0; (1 << i) < ssize(pre); i++)\n    for(int j = 0; j < ssize(pre); j++)\n\
    \      if ((j >> i & 1) and popcount(pre[j ^ (1 << i)]) > popcount(pre[j]))\n\
    \        pre[j] = pre[j ^ (1 << i)];\n\n  ull best = 0;\n  auto dfs = [&](int\
    \ v, ull is, ull adj, auto self) -> void {\n    if (v == n / 2 - 1) {\n      is\
    \ |= pre[~adj & ((1LL << (n / 2)) - 1)];\n      if (popcount(is) > popcount(best))\n\
    \        best = is;\n    } else  {\n      self(v - 1, is, adj, self);\n      adj\
    \ |= g[v];\n      if (~adj >> v & 1)\n        self(v - 1, is | (1LL << v), adj,\
    \ self);\n    }\n  };\n\n  dfs(n - 1, 0, 0, dfs);\n\n  vector<int> mis;\n  for(int\
    \ v = 0; v < n; v++)\n    if (best >> v & 1)\n      mis.emplace_back(v);\n\n \
    \ return mis;\n}\n#line 5 \"test/maximum_independent_set.test.cpp\"\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, m; cin >>\
    \ n >> m;\n  vector<ull> g(n);\n  while(m--) {\n    int u, v; cin >> u >> v;\n\
    \    g[u] |= 1LL << v, g[v] |= 1LL << u;\n  }\n\n  auto mis = MIS(g, n);\n  cout\
    \ << ssize(mis) << '\\n';\n  cout << mis << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../graph/MIS.cpp\"\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, m; cin >> n >>\
    \ m;\n  vector<ull> g(n);\n  while(m--) {\n    int u, v; cin >> u >> v;\n    g[u]\
    \ |= 1LL << v, g[v] |= 1LL << u;\n  }\n\n  auto mis = MIS(g, n);\n  cout << ssize(mis)\
    \ << '\\n';\n  cout << mis << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - graph/MIS.cpp
  isVerificationFile: true
  path: test/maximum_independent_set.test.cpp
  requiredBy: []
  timestamp: '2024-04-05 18:02:52+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/maximum_independent_set.test.cpp
layout: document
redirect_from:
- /verify/test/maximum_independent_set.test.cpp
- /verify/test/maximum_independent_set.test.cpp.html
title: test/maximum_independent_set.test.cpp
---
