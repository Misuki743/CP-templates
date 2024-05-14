---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: graph/hungarian.cpp
    title: graph/hungarian.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/assignment
    links:
    - https://judge.yosupo.jp/problem/assignment
  bundledCode: "#line 1 \"test/assignment_problem.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\
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
    \ \"graph/hungarian.cpp\"\n//source: KACTL\n\n/**\n * Author: Benjamin Qi, chilli\n\
    \ * Date: 2020-04-04\n * License: CC0\n * Source: https://github.com/bqi343/USACO/blob/master/Implementations/content/graphs%20(12)/Matching/Hungarian.h\n\
    \ * Description: Given a weighted bipartite graph, matches every node on\n * the\
    \ left with a node on the right such that no\n * nodes are in two matchings and\
    \ the sum of the edge weights is minimal. Takes\n * cost[N][M], where cost[i][j]\
    \ = cost for L[i] to be matched with R[j] and\n * returns (min cost, match), where\
    \ L[i] is matched with\n * R[match[i]]. Negate costs for max cost. Requires $N\
    \ \\le M$.\n * Time: O(N^2M)\n * Status: Tested on kattis:cordonbleu, stress-tested\n\
    \ */\n\ntemplate<class T, T inf>\npair<T, vector<T>> hungarian(const vector<vector<T>>\
    \ &a) {\n  if (a.empty()) return {0, {}};\n  int n = ssize(a) + 1, m = ssize(a[0])\
    \ + 1;\n  vector<int> p(m);\n  vector<T> u(n), v(m), ans(n - 1);\n  for(int i\
    \ = 1; i < n; i++) {\n    p[0] = i;\n    int j0 = 0;\n    vector<T> dist(m, inf),\
    \ pre(m, -1);\n    vector<bool> done(m + 1);\n    do {\n      done[j0] = true;\n\
    \      int i0 = p[j0], j1;\n      T delta = inf;\n      for(int j = 1; j < m;\
    \ j++) if (!done[j]) {\n\t\t\t\tauto cur = a[i0 - 1][j - 1] - u[i0] - v[j];\n\t\
    \t\t\tif (cur < dist[j]) dist[j] = cur, pre[j] = j0;\n\t\t\t\tif (dist[j] < delta)\
    \ delta = dist[j], j1 = j;\n      }\n      for(int j = 0; j < m; j++) {\n\t\t\t\
    \tif (done[j]) u[p[j]] += delta, v[j] -= delta;\n\t\t\t\telse dist[j] -= delta;\n\
    \      }\n      j0 = j1;\n    } while(p[j0]);\n    while(j0) {\n      int j1 =\
    \ pre[j0];\n      p[j0] = p[j1], j0 = j1;\n    }\n  }\n  for(int j = 1; j < m;\
    \ j++) if (p[j]) ans[p[j] - 1] = j - 1;\n  return {-v[0], ans};\n}\n#line 5 \"\
    test/assignment_problem.test.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n; cin >> n;\n  vector a(n, vector<ll>(n));\n  for(auto\
    \ &v : a)\n    for(ll &x : v)\n      cin >> x;\n\n  auto [cost, tob] = hungarian<ll,\
    \ LLONG_MAX>(a);\n  cout << cost << '\\n';\n  cout << tob << '\\n';\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n\n#include\
    \ \"../default/t.cpp\"\n#include \"../graph/hungarian.cpp\"\n\nsigned main() {\n\
    \  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n; cin >> n;\n  vector\
    \ a(n, vector<ll>(n));\n  for(auto &v : a)\n    for(ll &x : v)\n      cin >> x;\n\
    \n  auto [cost, tob] = hungarian<ll, LLONG_MAX>(a);\n  cout << cost << '\\n';\n\
    \  cout << tob << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - graph/hungarian.cpp
  isVerificationFile: true
  path: test/assignment_problem.test.cpp
  requiredBy: []
  timestamp: '2024-04-05 18:02:52+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/assignment_problem.test.cpp
layout: document
redirect_from:
- /verify/test/assignment_problem.test.cpp
- /verify/test/assignment_problem.test.cpp.html
title: test/assignment_problem.test.cpp
---
