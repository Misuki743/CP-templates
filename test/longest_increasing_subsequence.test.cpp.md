---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: misc/LIS.cpp
    title: misc/LIS.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"test/longest_increasing_subsequence.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\n\
    \n#line 1 \"default/t.cpp\"\n#include <algorithm>\n#include <array>\n#include\
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
    \ s)\n    os << x << ' ';\n  return os;\n}\n#line 1 \"misc/LIS.cpp\"\ntemplate<class\
    \ T, T inf, bool strict = true>\nvector<int> LIS(vector<T> &a) {\n  vector<T>\
    \ dp(ssize(a), inf);\n  vector<int> id(ssize(a)), pre(ssize(a), -1);\n  for(int\
    \ i = 0; i < ssize(a); i++) {\n    int j;\n    if constexpr (strict)\n      j\
    \ = R::lower_bound(dp, a[i]) - dp.begin();\n    else\n      j = R::upper_bound(dp,\
    \ a[i]) - dp.begin();\n    if (a[i] < dp[j])\n      dp[j] = a[i], id[j] = i;\n\
    \    if (j >= 1)\n      pre[i] = id[j - 1];\n  }\n\n  vector<T> lis;\n  int i\
    \ = id[R::lower_bound(dp, inf) - dp.begin() - 1];\n  while(i != -1) {\n    lis.emplace_back(i);\n\
    \    i = pre[i];\n  }\n  R::reverse(lis);\n\n  return lis;\n}\n#line 5 \"test/longest_increasing_subsequence.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n;\
    \ cin >> n;\n  vector<int> a(n);\n  for(int &x : a)\n    cin >> x;\n\n  auto lis\
    \ = LIS<int, INT_MAX>(a);\n  cout << ssize(lis) << '\\n';\n  cout << lis << '\\\
    n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../misc/LIS.cpp\"\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n; cin >> n;\n  vector<int>\
    \ a(n);\n  for(int &x : a)\n    cin >> x;\n\n  auto lis = LIS<int, INT_MAX>(a);\n\
    \  cout << ssize(lis) << '\\n';\n  cout << lis << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - misc/LIS.cpp
  isVerificationFile: true
  path: test/longest_increasing_subsequence.test.cpp
  requiredBy: []
  timestamp: '2024-01-28 22:59:51+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/longest_increasing_subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/longest_increasing_subsequence.test.cpp
- /verify/test/longest_increasing_subsequence.test.cpp.html
title: test/longest_increasing_subsequence.test.cpp
---
