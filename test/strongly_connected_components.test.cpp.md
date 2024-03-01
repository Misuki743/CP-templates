---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: graph/SCC.cpp
    title: graph/SCC.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/strongly_connected_components.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/scc\"\n\n#line 1 \"default/t.cpp\"\n#include\
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
    \nnamespace R = std::ranges;\nnamespace V = std::views;\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing ull = unsigned long long;\nusing ldb = long double;\n\
    using pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate<class T>\n\
    ostream& operator<<(ostream& os, const pair<T, T> pr) {\n  return os << pr.first\
    \ << ' ' << pr.second;\n}\ntemplate<class T, size_t N>\nostream& operator<<(ostream&\
    \ os, const array<T, N> &arr) {\n  for(const T &X : arr)\n    os << X << ' ';\n\
    \  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const vector<T>\
    \ &vec) {\n  for(const T &X : vec)\n    os << X << ' ';\n  return os;\n}\ntemplate<class\
    \ T>\nostream& operator<<(ostream& os, const set<T> &s) {\n  for(const T &x :\
    \ s)\n    os << x << ' ';\n  return os;\n}\n#line 1 \"graph/SCC.cpp\"\nstruct\
    \ SCC {\n  vector<int> groupId;\n  vector<vector<int>> group, G;\n  int size;\n\
    \n  SCC(vector<vector<int>> &g) : groupId(ssize(g)), size(0) {\n    vector<vector<int>>\
    \ gr(g.size());\n    for(int u = 0; u < ssize(g); u++)\n      for(int v : g[u])\n\
    \        gr[v].emplace_back(u);\n\n    int t = 0;\n    vector<bool> vis(ssize(g),\
    \ false);\n    vector<int> tout(ssize(g));\n    auto dfs = [&](int v, auto self)\
    \ -> void {\n      vis[v] = true;\n      for(int x : gr[v])\n        if (!vis[x])\n\
    \          self(x, self);\n      tout[t++] = v;\n    };\n\n    for(int v = 0;\
    \ v < ssize(g); v++)\n      if (!vis[v])\n        dfs(v, dfs);\n\n    auto dfs2\
    \ = [&](int v, auto self) -> void {\n      vis[v] = true;\n      for(int x : g[v])\n\
    \        if (!vis[x])\n          self(x, self);\n      groupId[v] = size;\n  \
    \  };\n    fill(vis.begin(), vis.end(), false);\n    for(int v = ssize(g) - 1;\
    \ v >= 0; v--) {\n      if (!vis[tout[v]]) {\n        dfs2(tout[v], dfs2);\n \
    \       size += 1;\n      }\n    }\n\n    for(int &x : groupId)\n      x = size\
    \ - x - 1;\n\n    group.resize(size);\n    for(int v = 0; v < ssize(g); v++)\n\
    \      group[groupId[v]].emplace_back(v);\n\n    G.resize(size);\n    for(int\
    \ v = 0; v < ssize(g); v++)\n      for(int x : g[v])\n        if (groupId[v] !=\
    \ groupId[x])\n          G[groupId[v]].emplace_back(groupId[x]);\n  }\n};\n#line\
    \ 5 \"test/strongly_connected_components.test.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, m; cin >> n >> m;\n  vector<vector<int>> g(n);\n\
    \  for(; m--; ) {\n    int u, v; cin >> u >> v;\n    g[u].emplace_back(v);\n \
    \ }\n\n  SCC scc(g);\n\n  cout << scc.size << '\\n';\n  for(int i = 0; i < scc.size;\
    \ i++)\n    cout << ssize(scc.group[i]) << ' ' << scc.group[i] << '\\n';\n\n \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"../default/t.cpp\"\
    \n#include \"../graph/SCC.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, m; cin >> n >> m;\n  vector<vector<int>> g(n);\n\
    \  for(; m--; ) {\n    int u, v; cin >> u >> v;\n    g[u].emplace_back(v);\n \
    \ }\n\n  SCC scc(g);\n\n  cout << scc.size << '\\n';\n  for(int i = 0; i < scc.size;\
    \ i++)\n    cout << ssize(scc.group[i]) << ' ' << scc.group[i] << '\\n';\n\n \
    \ return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - graph/SCC.cpp
  isVerificationFile: true
  path: test/strongly_connected_components.test.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/strongly_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/strongly_connected_components.test.cpp
- /verify/test/strongly_connected_components.test.cpp.html
title: test/strongly_connected_components.test.cpp
---
