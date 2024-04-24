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
  bundledCode: "#line 1 \"default/tt.cpp\"\n#pragma GCC optimize(\"O2\")\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include <cinttypes>\n\
    #include <climits>\n#include <cmath>\n#include <complex>\n#include <cstdarg>\n\
    #include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n\
    #include <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n\
    #include <initializer_list>\n#include <iomanip>\n#include <ios>\n#include <iostream>\n\
    #include <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n\
    #include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n#include\
    \ <ostream>\n#include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <streambuf>\n#include <string>\n#include <tuple>\n\
    #include <type_traits>\n#include <variant>\n\n#if __cplusplus >= 202002L\n\n#include\
    \ <bit>\n#include <compare>\n#include <concepts>\n#include <numbers>\n#include\
    \ <ranges>\n#include <span>\n\n#else\n\n#define ssize(v) (int)(v).size()\n#define\
    \ popcount(x) __builtin_popcountll(x)\nconstexpr int bit_width(const unsigned\
    \ int x) { return x == 0 ? 0 : ((sizeof(unsigned int) * CHAR_BIT) - __builtin_clz(x));\
    \ }\nconstexpr int bit_width(const unsigned long long x) { return x == 0 ? 0 :\
    \ ((sizeof(unsigned long long) * CHAR_BIT) - __builtin_clzll(x)); }\nconstexpr\
    \ int countr_zero(const unsigned int x) { return x == 0 ? sizeof(unsigned int)\
    \ * CHAR_BIT : __builtin_ctz(x); }\nconstexpr int countr_zero(const unsigned long\
    \ long x) { return x == 0 ? sizeof(unsigned long long) * CHAR_BIT : __builtin_ctzll(x);\
    \ }\nconstexpr unsigned int bit_ceil(const unsigned int x) { return x == 0 ? 1\
    \ : (popcount(x) == 1 ? x : (1u << bit_width(x))); }\nconstexpr unsigned long\
    \ long bit_ceil(const unsigned long long x) { return x == 0 ? 1 : (popcount(x)\
    \ == 1 ? x : (1ull << bit_width(x))); }\n\n#endif\n\n#define int ll\n#define INT128_MAX\
    \ (__int128)(((unsigned __int128) 1 << ((sizeof(__int128) * __CHAR_BIT__) - 1))\
    \ - 1)\n#define INT128_MIN (-INT128_MAX - 1)\n\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
    \n#ifdef DEBUG\n#define dbg(x) cout << (#x) << \" = \" << (x) << '\\n'\n#else\n\
    #define dbg(x)\n#endif\n\nusing namespace std;\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing ldb = long double;\nusing pii = pair<int, int>;\n\
    using pll = pair<ll, ll>;\n//#define double ldb\n\ntemplate<class T>\nostream&\
    \ operator<<(ostream& os, const pair<T, T> pr) {\n  return os << pr.first << '\
    \ ' << pr.second;\n}\ntemplate<class T, size_t N>\nostream& operator<<(ostream&\
    \ os, const array<T, N> &arr) {\n  for(const T &X : arr)\n    os << X << ' ';\n\
    \  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const vector<T>\
    \ &vec) {\n  for(const T &X : vec)\n    os << X << ' ';\n  return os;\n}\ntemplate<class\
    \ T>\nostream& operator<<(ostream& os, const set<T> &s) {\n  for(const T &x :\
    \ s)\n    os << x << ' ';\n  return os;\n}\n\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  \n\n  return 0;\n}\n"
  code: "#pragma GCC optimize(\"O2\")\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cctype>\n#include <cfenv>\n#include\
    \ <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include <climits>\n#include\
    \ <cmath>\n#include <complex>\n#include <cstdarg>\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <initializer_list>\n\
    #include <iomanip>\n#include <ios>\n#include <iostream>\n#include <istream>\n\
    #include <iterator>\n#include <limits>\n#include <list>\n#include <map>\n#include\
    \ <memory>\n#include <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n\
    #include <random>\n#include <set>\n#include <sstream>\n#include <stack>\n#include\
    \ <streambuf>\n#include <string>\n#include <tuple>\n#include <type_traits>\n#include\
    \ <variant>\n\n#if __cplusplus >= 202002L\n\n#include <bit>\n#include <compare>\n\
    #include <concepts>\n#include <numbers>\n#include <ranges>\n#include <span>\n\n\
    #else\n\n#define ssize(v) (int)(v).size()\n#define popcount(x) __builtin_popcountll(x)\n\
    constexpr int bit_width(const unsigned int x) { return x == 0 ? 0 : ((sizeof(unsigned\
    \ int) * CHAR_BIT) - __builtin_clz(x)); }\nconstexpr int bit_width(const unsigned\
    \ long long x) { return x == 0 ? 0 : ((sizeof(unsigned long long) * CHAR_BIT)\
    \ - __builtin_clzll(x)); }\nconstexpr int countr_zero(const unsigned int x) {\
    \ return x == 0 ? sizeof(unsigned int) * CHAR_BIT : __builtin_ctz(x); }\nconstexpr\
    \ int countr_zero(const unsigned long long x) { return x == 0 ? sizeof(unsigned\
    \ long long) * CHAR_BIT : __builtin_ctzll(x); }\nconstexpr unsigned int bit_ceil(const\
    \ unsigned int x) { return x == 0 ? 1 : (popcount(x) == 1 ? x : (1u << bit_width(x)));\
    \ }\nconstexpr unsigned long long bit_ceil(const unsigned long long x) { return\
    \ x == 0 ? 1 : (popcount(x) == 1 ? x : (1ull << bit_width(x))); }\n\n#endif\n\n\
    #define int ll\n#define INT128_MAX (__int128)(((unsigned __int128) 1 << ((sizeof(__int128)\
    \ * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN (-INT128_MAX - 1)\n\n#define\
    \ clock chrono::steady_clock::now().time_since_epoch().count()\n\n#ifdef DEBUG\n\
    #define dbg(x) cout << (#x) << \" = \" << (x) << '\\n'\n#else\n#define dbg(x)\n\
    #endif\n\nusing namespace std;\n\nusing ll = long long;\nusing ull = unsigned\
    \ long long;\nusing ldb = long double;\nusing pii = pair<int, int>;\nusing pll\
    \ = pair<ll, ll>;\n//#define double ldb\n\ntemplate<class T>\nostream& operator<<(ostream&\
    \ os, const pair<T, T> pr) {\n  return os << pr.first << ' ' << pr.second;\n}\n\
    template<class T, size_t N>\nostream& operator<<(ostream& os, const array<T, N>\
    \ &arr) {\n  for(const T &X : arr)\n    os << X << ' ';\n  return os;\n}\ntemplate<class\
    \ T>\nostream& operator<<(ostream& os, const vector<T> &vec) {\n  for(const T\
    \ &X : vec)\n    os << X << ' ';\n  return os;\n}\ntemplate<class T>\nostream&\
    \ operator<<(ostream& os, const set<T> &s) {\n  for(const T &x : s)\n    os <<\
    \ x << ' ';\n  return os;\n}\n\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  \n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: default/tt.cpp
  requiredBy: []
  timestamp: '2024-04-24 23:34:37+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: default/tt.cpp
layout: document
redirect_from:
- /library/default/tt.cpp
- /library/default/tt.cpp.html
title: default/tt.cpp
---
