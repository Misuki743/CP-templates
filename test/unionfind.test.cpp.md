---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/DSU.cpp
    title: ds/DSU.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
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
    \ s)\n    os << x << ' ';\n  return os;\n}\n#line 1 \"ds/DSU.cpp\"\n/**\n * template\
    \ name: DSU\n * author: Misuki\n * last update: 2024/01/01\n * verify: Library\
    \ Checker - Unionfind\n */\n\nstruct DSU {\n  vector<int> bos, sz;\n  int size;\n\
    \n  DSU(int _size) : bos(_size), sz(_size, 1), size(_size) {\n    iota(bos.begin(),\
    \ bos.end(), 0);\n  }\n\n  int query(int v) {\n    if (bos[v] == v)\n      return\
    \ v;\n    else\n      return bos[v] = query(bos[v]);\n  }\n\n  bool merge(int\
    \ v1, int v2) {\n    int b1 = query(v1), b2 = query(v2);\n\n    if (b1 == b2)\n\
    \      return false;\n\n    if (sz[b1] > sz[b2])\n      swap(b1, b2);\n    bos[b1]\
    \ = b2, sz[b2] += sz[b1];\n\n    return true;\n  }\n};\n#line 5 \"test/unionfind.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ q; cin >> n >> q;\n  DSU dsu(n);\n  while(q--) {\n    int t, u, v; cin >> t\
    \ >> u >> v;\n    if (t == 0)\n      dsu.merge(u, v);\n    else\n      cout <<\
    \ (dsu.query(u) == dsu.query(v)) << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../default/t.cpp\"\n#include \"../ds/DSU.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  DSU dsu(n);\n  while(q--) {\n\
    \    int t, u, v; cin >> t >> u >> v;\n    if (t == 0)\n      dsu.merge(u, v);\n\
    \    else\n      cout << (dsu.query(u) == dsu.query(v)) << '\\n';\n  }\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - ds/DSU.cpp
  isVerificationFile: true
  path: test/unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-01-21 17:57:21+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/unionfind.test.cpp
- /verify/test/unionfind.test.cpp.html
title: test/unionfind.test.cpp
---
