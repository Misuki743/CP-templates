---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: graph/eulerianTrail.cpp
    title: graph/eulerianTrail.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/eulerian_trail_directed
    links:
    - https://judge.yosupo.jp/problem/eulerian_trail_directed
  bundledCode: "#line 1 \"test/eulerian_trail_directed.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/eulerian_trail_directed\"\n\n#line 1 \"default/t.cpp\"\
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
    \ \"graph/eulerianTrail.cpp\"\ntemplate<bool directed = false, bool circuit =\
    \ false>\narray<vector<int>, 2> eulerianTrail(int n, vector<array<int, 2>> &e)\
    \ {\n  vector<int> indeg(n), outdeg(n);\n  vector<vector<int>> g(n);\n  for(int\
    \ i = 0; auto [u, v] : e) {\n    outdeg[u] += 1, indeg[v] += 1;\n    if constexpr\
    \ (!directed)\n      g[v].emplace_back(i);\n    g[u].emplace_back(i++);\n  }\n\
    \n  int s = -1;\n  if constexpr (directed) {\n    for(int v = 0; v < n; v++) {\n\
    \      if (abs(indeg[v] - outdeg[v]) >= 2) return {};\n      if (outdeg[v] <=\
    \ indeg[v]) continue;\n      if (s != -1) return {};\n      s = v;\n    }\n  }\
    \ else {\n    for(int v = 0, t = -1; v < n; v++) {\n      if ((indeg[v] + outdeg[v])\
    \ % 2 == 0) continue;\n      if (s != -1 and t != -1) return {};\n      if (s\
    \ == -1) s = v;\n      else t = v;\n    }\n  }\n\n  if constexpr (circuit)\n \
    \   if (s != -1) \n      return {};\n\n  if (s == -1)\n    for(int v = 0; v <\
    \ n; v++)\n      if (indeg[v] | outdeg[v])\n        s = v;\n\n  if (s == -1)\n\
    \    s = 0;\n\n  vector<int> vid, eid, ptr(n);\n  vector<bool> visE(ssize(e),\
    \ false);\n  auto dfs = [&](int v, auto self) -> void {\n    for(int &i = ptr[v];\
    \ i < ssize(g[v]); i++) {\n      if (visE[g[v][i]]) continue;\n      int tmp =\
    \ g[v][i];\n      int x = v ^ e[tmp][0] ^ e[tmp][1];\n      visE[tmp] = true;\n\
    \      self(x, self);\n      vid.emplace_back(x);\n      eid.emplace_back(tmp);\n\
    \    }\n  };\n\n  dfs(s, dfs);\n  vid.emplace_back(s);\n\n  ranges::reverse(vid);\n\
    \  ranges::reverse(eid);\n\n  if (ssize(eid) != ssize(e))\n    return {};\n  else\n\
    \    return {vid, eid};\n}\n#line 5 \"test/eulerian_trail_directed.test.cpp\"\n\
    \nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int t; cin\
    \ >> t;\n  while(t--) {\n    int n, m; cin >> n >> m;\n    vector<array<int, 2>>\
    \ e(m);\n    for(auto &[u, v] : e)\n      cin >> u >> v;\n    auto [vid, eid]\
    \ = eulerianTrail<true>(n, e);\n    if (vid.empty()) {\n      cout << \"No\\n\"\
    ; \n    } else {\n      cout << \"Yes\\n\";\n      cout << vid << '\\n';\n   \
    \   cout << eid << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/eulerian_trail_directed\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../graph/eulerianTrail.cpp\"\n\n\
    signed main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int t; cin\
    \ >> t;\n  while(t--) {\n    int n, m; cin >> n >> m;\n    vector<array<int, 2>>\
    \ e(m);\n    for(auto &[u, v] : e)\n      cin >> u >> v;\n    auto [vid, eid]\
    \ = eulerianTrail<true>(n, e);\n    if (vid.empty()) {\n      cout << \"No\\n\"\
    ; \n    } else {\n      cout << \"Yes\\n\";\n      cout << vid << '\\n';\n   \
    \   cout << eid << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - graph/eulerianTrail.cpp
  isVerificationFile: true
  path: test/eulerian_trail_directed.test.cpp
  requiredBy: []
  timestamp: '2024-04-05 18:02:52+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/eulerian_trail_directed.test.cpp
layout: document
redirect_from:
- /verify/test/eulerian_trail_directed.test.cpp
- /verify/test/eulerian_trail_directed.test.cpp.html
title: test/eulerian_trail_directed.test.cpp
---
