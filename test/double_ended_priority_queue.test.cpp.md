---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/doubleEndedPQ.cpp
    title: ds/doubleEndedPQ.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
  bundledCode: "#line 1 \"test/double_ended_priority_queue.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\n\n#line 1 \"\
    default/t.cpp\"\n#include <algorithm>\n#include <array>\n#include <bit>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cctype>\n#include <cfenv>\n#include\
    \ <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include <climits>\n#include\
    \ <cmath>\n#include <compare>\n#include <complex>\n#include <concepts>\n#include\
    \ <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <deque>\n#include <fstream>\n#include\
    \ <functional>\n#include <initializer_list>\n#include <iomanip>\n#include <ios>\n\
    #include <iostream>\n#include <istream>\n#include <iterator>\n#include <limits>\n\
    #include <list>\n#include <map>\n#include <memory>\n#include <new>\n#include <numbers>\n\
    #include <numeric>\n#include <ostream>\n#include <queue>\n#include <random>\n\
    #include <ranges>\n#include <set>\n#include <span>\n#include <sstream>\n#include\
    \ <stack>\n#include <streambuf>\n#include <string>\n#include <tuple>\n#include\
    \ <type_traits>\n#include <variant>\n\n#define INT128_MAX (__int128)(((unsigned\
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
    \ s)\n    os << x << ' ';\n  return os;\n}\n#line 1 \"ds/doubleEndedPQ.cpp\"\n\
    template<class T>\nstruct doubleEndedPQ {\n  priority_queue<pair<T, int>> mx;\n\
    \  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> mn;\n\
    \  vector<bool> inPQ;\n  int t = 0, _size = 0;\n  void push(T x) {\n    mn.push(make_pair(x,\
    \ t)), mx.push(make_pair(x, t));\n    inPQ.emplace_back(true);\n    _size++, t++;\n\
    \  }\n  void clean() {\n    while(!mn.empty() and !inPQ[mn.top().second]) mn.pop();\n\
    \    while(!mx.empty() and !inPQ[mx.top().second]) mx.pop();\n  }\n  T min() {\
    \ return mn.top().first; }\n  T max() { return mx.top().first; }\n  void popMin()\
    \ {\n    inPQ[mn.top().second] = false, _size--;\n    clean();\n  }\n  void popMax()\
    \ {\n    inPQ[mx.top().second] = false, _size--;\n    clean();\n  }\n  int size()\
    \ { return _size; }\n  bool empty() { return _size == 0; }\n};\n#line 5 \"test/double_ended_priority_queue.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ q; cin >> n >> q;\n  vector<int> a(n);\n  for(int &x : a)\n    cin >> x;\n\n\
    \  doubleEndedPQ<int> pq;\n  for(int x : a)\n    pq.push(x);\n\n  while(q--) {\n\
    \    int op; cin >> op;\n    if (op == 0) {\n      int x; cin >> x;\n      pq.push(x);\n\
    \    } else if (op == 1) {\n      cout << pq.min() << '\\n';\n      pq.popMin();\n\
    \    } else {\n      cout << pq.max() << '\\n';\n      pq.popMax();\n    }\n \
    \ }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../ds/doubleEndedPQ.cpp\"\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin >>\
    \ n >> q;\n  vector<int> a(n);\n  for(int &x : a)\n    cin >> x;\n\n  doubleEndedPQ<int>\
    \ pq;\n  for(int x : a)\n    pq.push(x);\n\n  while(q--) {\n    int op; cin >>\
    \ op;\n    if (op == 0) {\n      int x; cin >> x;\n      pq.push(x);\n    } else\
    \ if (op == 1) {\n      cout << pq.min() << '\\n';\n      pq.popMin();\n    }\
    \ else {\n      cout << pq.max() << '\\n';\n      pq.popMax();\n    }\n  }\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - ds/doubleEndedPQ.cpp
  isVerificationFile: true
  path: test/double_ended_priority_queue.test.cpp
  requiredBy: []
  timestamp: '2024-03-19 02:05:55+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/double_ended_priority_queue.test.cpp
layout: document
redirect_from:
- /verify/test/double_ended_priority_queue.test.cpp
- /verify/test/double_ended_priority_queue.test.cpp.html
title: test/double_ended_priority_queue.test.cpp
---
