---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: string/Manacher.cpp
    title: string/Manacher.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"test/enumerate_palindromes.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\n#line 1 \"default/t.cpp\"\
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
    \ \"string/Manacher.cpp\"\nvector<int> Manacher(string &s) {\n  vector<int> p(ssize(s));\n\
    \  for(int i = 0, l = -1, r = -1; i < ssize(s); i++) {\n    if (i <= r)\n    \
    \  p[i] = min(p[2 * l - i], r - i + 1);\n    while(i + p[i] < ssize(s) and i -\
    \ p[i] >= 0 and s[i + p[i]] == s[i - p[i]])\n      l = i, r = i + p[i], p[i] +=\
    \ 1;\n  }\n\n  return p;\n}\n\nvector<int> enumeratePalindrome(string &s) {\n\
    \  string t = \"#\";\n  for(char c : s)\n    t += c, t += '#';\n  vector<int>\
    \ p = Manacher(t);\n  for(int &x : p)\n    x -= 1;\n  return vector<int>(p.begin()\
    \ + 1, p.end() - 1);\n}\n#line 5 \"test/enumerate_palindromes.test.cpp\"\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  string s; cin >>\
    \ s;\n  cout << enumeratePalindrome(s) << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../string/Manacher.cpp\"\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  string s; cin >>\
    \ s;\n  cout << enumeratePalindrome(s) << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - string/Manacher.cpp
  isVerificationFile: true
  path: test/enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2024-04-05 18:02:52+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/test/enumerate_palindromes.test.cpp
- /verify/test/enumerate_palindromes.test.cpp.html
title: test/enumerate_palindromes.test.cpp
---
