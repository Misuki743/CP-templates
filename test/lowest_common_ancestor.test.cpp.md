---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/fastJump.cpp
    title: ds/fastJump.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/lowest_common_ancestor.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\n\n#line 1 \"default/t.cpp\"\n#include\
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
    \ntemplate<class T>\nostream& operator<<(ostream& os, const pair<T, T> pr) {\n\
    \  return os << pr.first << ' ' << pr.second;\n}\ntemplate<class T, size_t N>\n\
    ostream& operator<<(ostream& os, const array<T, N> &arr) {\n  for(const T &X :\
    \ arr)\n    os << X << ' ';\n  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream&\
    \ os, const vector<T> &vec) {\n  for(const T &X : vec)\n    os << X << ' ';\n\
    \  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const set<T>\
    \ &s) {\n  for(const T &x : s)\n    os << x << ' ';\n  return os;\n}\n#line 1\
    \ \"ds/fastJump.cpp\"\nstruct fastJump {\n  vector<int> p, jp, dep;\n\n  fastJump(vector<vector<int>>\
    \ g, int root = 0) : p(ssize(g)), jp(ssize(g)), dep(ssize(g)) {\n    auto dfs\
    \ = [&](int v, auto self) -> void {\n      if (dep[p[v]] + dep[jp[jp[p[v]]]] ==\
    \ 2 * dep[jp[p[v]]])\n        jp[v] = jp[jp[p[v]]];\n      else\n        jp[v]\
    \ = p[v];\n\n      for(int x : g[v]) {\n        if (x == p[v]) continue;\n   \
    \     p[x] = v, dep[x] = dep[v] + 1;\n        self(x, self);\n      }\n    };\n\
    \n    p[root] = jp[root] = root;\n    dfs(root, dfs);\n  }\n\n  int jump(int v,\
    \ int k) {\n    k = min(k, dep[v]);\n    while(k) {\n      if (int d = dep[v]\
    \ - dep[jp[v]]; d <= k)\n        v = jp[v], k -= d;\n      else\n        v = p[v],\
    \ k -= 1;\n    }\n    return v;\n  }\n\n  int lca(int u, int v) {\n    if (dep[u]\
    \ < dep[v])\n      swap(u, v);\n    u = jump(u, dep[u] - dep[v]);\n    if (u ==\
    \ v) return u;\n    while(p[u] != p[v]) {\n      if (jp[u] != jp[v]) u = jp[u],\
    \ v = jp[v];\n      else u = p[u], v = p[v];\n    }\n    return p[u];\n  }\n\n\
    \  int kth(int s, int t, int k) {\n    int m = lca(s, t);\n    if (dep[s] + dep[t]\
    \ - 2 * dep[m] < k)\n      return -1;\n    else if (dep[s] - dep[m] >= k)\n  \
    \    return jump(s, k);\n    else\n      return jump(t, dep[s] + dep[t] - 2 *\
    \ dep[m] - k);\n  }\n\n  int dis(int u, int v) {\n    return dep[u] + dep[v] -\
    \ 2 * dep[lca(u, v)];\n  }\n};\n#line 5 \"test/lowest_common_ancestor.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ q; cin >> n >> q;\n  vector<vector<int>> g(n);\n  for(int u = 1; u < n; u++)\
    \ {\n    int v; cin >> v;\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n\
    \  }\n\n  fastJump jp(g);\n\n  while(q--) {\n    int u, v; cin >> u >> v;\n  \
    \  cout << jp.lca(u, v) << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../default/t.cpp\"\
    \n#include \"../ds/fastJump.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<vector<int>> g(n);\n\
    \  for(int u = 1; u < n; u++) {\n    int v; cin >> v;\n    g[u].emplace_back(v);\n\
    \    g[v].emplace_back(u);\n  }\n\n  fastJump jp(g);\n\n  while(q--) {\n    int\
    \ u, v; cin >> u >> v;\n    cout << jp.lca(u, v) << '\\n';\n  }\n\n  return 0;\n\
    }\n"
  dependsOn:
  - default/t.cpp
  - ds/fastJump.cpp
  isVerificationFile: true
  path: test/lowest_common_ancestor.test.cpp
  requiredBy: []
  timestamp: '2024-04-05 18:02:52+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/lowest_common_ancestor.test.cpp
layout: document
redirect_from:
- /verify/test/lowest_common_ancestor.test.cpp
- /verify/test/lowest_common_ancestor.test.cpp.html
title: test/lowest_common_ancestor.test.cpp
---
