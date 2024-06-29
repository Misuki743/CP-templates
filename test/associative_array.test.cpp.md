---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':question:'
    path: ds/hashTable.cpp
    title: ds/hashTable.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"test/associative_array.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\
    \n\n#include <ext/pb_ds/assoc_container.hpp>\n#line 1 \"default/t.cpp\"\n#include\
    \ <algorithm>\n#include <array>\n#include <bit>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include\
    \ <cinttypes>\n#include <climits>\n#include <cmath>\n#include <compare>\n#include\
    \ <complex>\n#include <concepts>\n#include <cstdarg>\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <initializer_list>\n\
    #include <iomanip>\n#include <ios>\n#include <iostream>\n#include <istream>\n\
    #include <iterator>\n#include <limits>\n#include <list>\n#include <map>\n#include\
    \ <memory>\n#include <new>\n#include <numbers>\n#include <numeric>\n#include <ostream>\n\
    #include <queue>\n#include <random>\n#include <ranges>\n#include <set>\n#include\
    \ <span>\n#include <sstream>\n#include <stack>\n#include <streambuf>\n#include\
    \ <string>\n#include <tuple>\n#include <type_traits>\n#include <variant>\n\n#define\
    \ INT128_MAX (__int128)(((unsigned __int128) 1 << ((sizeof(__int128) * __CHAR_BIT__)\
    \ - 1)) - 1)\n#define INT128_MIN (-INT128_MAX - 1)\n\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ldb = long double;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\
    \ntemplate<ranges::forward_range rng, class T = ranges::range_value_t<rng>, class\
    \ OP = plus<T>>\nvoid pSum(rng &&v) {\n  if (!v.empty())\n    for(T p = v[0];\
    \ T &x : v | views::drop(1))\n      x = p = OP()(p, x);\n}\ntemplate<ranges::forward_range\
    \ rng, class T = ranges::range_value_t<rng>, class OP>\nvoid pSum(rng &&v, OP\
    \ op) {\n  if (!v.empty())\n    for(T p = v[0]; T &x : v | views::drop(1))\n \
    \     x = p = op(p, x);\n}\ntemplate<class T>\nT floorDiv(T a, T b) {\n  if (b\
    \ < 0) a *= -1, b *= -1;\n  return a >= 0 ? a / b : (a - b + 1) / b;\n}\ntemplate<class\
    \ T>\nT ceilDiv(T a, T b) {\n  if (b < 0) a *= -1, b *= -1;\n  return a >= 0 ?\
    \ (a + b - 1) / b : a / b;\n}\ntemplate<class T>\nostream& operator<<(ostream&\
    \ os, const pair<T, T> pr) {\n  return os << pr.first << ' ' << pr.second;\n}\n\
    template<class T, size_t N>\nostream& operator<<(ostream& os, const array<T, N>\
    \ &arr) {\n  for(const T &X : arr)\n    os << X << ' ';\n  return os;\n}\ntemplate<class\
    \ T>\nostream& operator<<(ostream& os, const vector<T> &vec) {\n  for(const T\
    \ &X : vec)\n    os << X << ' ';\n  return os;\n}\ntemplate<class T>\nostream&\
    \ operator<<(ostream& os, const set<T> &s) {\n  for(const T &x : s)\n    os <<\
    \ x << ' ';\n  return os;\n}\n#line 1 \"ds/hashTable.cpp\"\n//source: https://codeforces.com/blog/entry/62393\n\
    //#include<ext/pb_ds/assoc_container.hpp>\n//#include<ext/pb_ds/tree_policy.hpp>\n\
    \nstruct custom_hash {\n    static uint64_t splitmix64(uint64_t x) {\n       \
    \ x += 0x9e3779b97f4a7c15;\n        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n        return x ^ (x >> 31);\n\
    \    }\n\n    size_t operator()(uint64_t x) const {\n        static const uint64_t\
    \ FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n   \
    \     return splitmix64(x + FIXED_RANDOM);\n    }\n};\n\nusing namespace __gnu_pbds;\n\
    \n//gp_hash_table<ll, int, custom_hash> m;\n#line 6 \"test/associative_array.test.cpp\"\
    \n\ngp_hash_table<ll, ll, custom_hash> m({}, {}, {}, {}, {1 << 20});\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int q; cin >> q;\n\
    \  while(q--) {\n    int t; cin >> t;\n    ll k; cin >> k;\n    if (t == 0) {\n\
    \      ll v; cin >> v;\n      m[k] = v;\n    } else {\n      cout << m[k] << '\\\
    n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n\
    #include <ext/pb_ds/assoc_container.hpp>\n#include \"../default/t.cpp\"\n#include\
    \ \"../ds/hashTable.cpp\"\n\ngp_hash_table<ll, ll, custom_hash> m({}, {}, {},\
    \ {}, {1 << 20});\n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\
    \n  int q; cin >> q;\n  while(q--) {\n    int t; cin >> t;\n    ll k; cin >> k;\n\
    \    if (t == 0) {\n      ll v; cin >> v;\n      m[k] = v;\n    } else {\n   \
    \   cout << m[k] << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - ds/hashTable.cpp
  isVerificationFile: true
  path: test/associative_array.test.cpp
  requiredBy: []
  timestamp: '2024-06-29 18:02:37+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/associative_array.test.cpp
layout: document
redirect_from:
- /verify/test/associative_array.test.cpp
- /verify/test/associative_array.test.cpp.html
title: test/associative_array.test.cpp
---
