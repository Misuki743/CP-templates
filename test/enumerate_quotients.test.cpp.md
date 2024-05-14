---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: numtheory/floorCeilSum.cpp
    title: numtheory/floorCeilSum.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_quotients
    links:
    - https://judge.yosupo.jp/problem/enumerate_quotients
  bundledCode: "#line 1 \"test/enumerate_quotients.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/enumerate_quotients\"\n\n#line 1 \"default/t.cpp\"\
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
    \ \"numtheory/floorCeilSum.cpp\"\n// note: g = floor(x / val) is the greatest\
    \ value s.t. floor(x / g) = val for floor sum, \n//       g = ceil(x / val) is\
    \ the least value s.t. ceil(x / g) = val for ceil sum. \n//\ntemplate<class T>\n\
    vector<array<T, 3>> calc_floor(T x) {\n  vector<T> v, rng;\n  for(T i = x; i;\
    \ ) {\n    T val = x / i;\n    v.emplace_back(val);\n    rng.emplace_back(x /\
    \ val);\n    i = x / (val + 1);\n  }\n  rng.emplace_back(0);\n\n  vector<array<T,\
    \ 3>> res;\n  for(int i = 0; i < ssize(v); i++)\n    res.push_back({v[i], rng[i\
    \ + 1] + 1, rng[i]}); //{q, [l, r]}\n\n  return res;\n}\n\ntemplate<class T>\n\
    vector<array<T, 3>> calc_ceil(T x) {\n  vector<T> v, rng;\n  for(T i = 1; ; )\
    \ {\n    T val = (x + i - 1) / i;\n    v.emplace_back(val);\n    rng.emplace_back((x\
    \ + val - 1) / val);\n    if (val == 1)\n      break;\n    i = (x + val - 2) /\
    \ (val - 1);\n  }\n  rng.emplace_back(x + 1);\n\n  vector<array<T, 3>> res;\n\
    \  for(int i = 0; i < ssize(v); i++)\n    res.push_back({v[i], rng[i], rng[i +\
    \ 1] - 1}); //{q, [l, r]}\n\n  return res;\n}\n#line 5 \"test/enumerate_quotients.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  ll n;\
    \ cin >> n;\n  auto tmp = calc_floor(n);\n  cout << ssize(tmp) << '\\n';\n  for(auto\
    \ [x, _, __] : tmp)\n    cout << x << ' ';\n  cout << '\\n';\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\
    \n#include \"../default/t.cpp\"\n#include \"../numtheory/floorCeilSum.cpp\"\n\n\
    signed main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  ll n; cin\
    \ >> n;\n  auto tmp = calc_floor(n);\n  cout << ssize(tmp) << '\\n';\n  for(auto\
    \ [x, _, __] : tmp)\n    cout << x << ' ';\n  cout << '\\n';\n\n  return 0;\n\
    }\n"
  dependsOn:
  - default/t.cpp
  - numtheory/floorCeilSum.cpp
  isVerificationFile: true
  path: test/enumerate_quotients.test.cpp
  requiredBy: []
  timestamp: '2024-04-05 18:02:52+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/enumerate_quotients.test.cpp
layout: document
redirect_from:
- /verify/test/enumerate_quotients.test.cpp
- /verify/test/enumerate_quotients.test.cpp.html
title: test/enumerate_quotients.test.cpp
---
