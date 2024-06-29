---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: graph/BCC.cpp
    title: graph/BCC.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/biconnected_components
    links:
    - https://judge.yosupo.jp/problem/biconnected_components
  bundledCode: "#line 1 \"test/biconnected_components.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/biconnected_components\"\n\n#line 1 \"default/t.cpp\"\
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
    \ \"graph/BCC.cpp\"\nstruct BCC {\n  vector<int> f, vb, eb, gv, ge, eid, vid;\n\
    \  int size = -1;\n\n  BCC(vector<array<int, 2>> &e, int n)\n  : f(n), eid(ssize(e)),\
    \ vid(n) {\n\n    auto newComp = [&]() {\n      vb.emplace_back(ssize(gv));\n\
    \      eb.emplace_back(ssize(ge));\n      size++;\n    };\n\n    vector<vector<int>>\
    \ g(n);\n    for(int i = 0; auto [u, v] : e) {\n      g[u].emplace_back(i);\n\
    \      g[v].emplace_back(i++);\n    }\n\n    int t = 0;\n    vector<int> tin(n,\
    \ -1), low(n), cnt(n), s;\n    vector<bool> vis(ssize(e), false);\n    auto dfs\
    \ = [&](int v, auto &&self) -> void {\n      tin[v] = low[v] = t++;\n      for(int\
    \ i : g[v]) if (!vis[i]) {\n        int x = e[i][0] ^ e[i][1] ^ v;\n        vis[i]\
    \ = true, s.emplace_back(i);\n        if (tin[x] != -1) {\n          low[v] =\
    \ min(low[v], tin[x]);\n        } else {\n          self(x, self);\n         \
    \ low[v] = min(low[v], low[x]);\n          if (low[x] >= tin[v]) {\n         \
    \   newComp();\n            do {\n              int j = s.back(); s.pop_back();\n\
    \              for(int u : e[j])\n                if (++cnt[u] == 1)\n       \
    \           gv.emplace_back(u);\n              eid[j] = size;\n              ge.emplace_back(j);\n\
    \            } while(ge.back() != i);\n            for(int u : gv | views::drop(vb.back()))\n\
    \              cnt[u] = 0, f[u]++, vid[u] = size;\n          }\n        }\n  \
    \    }\n      if (g[v].empty()) newComp(), gv.emplace_back(v);\n    };\n\n   \
    \ for(int v = 0; v < n; v++)\n      if (tin[v] == -1)\n        dfs(v, dfs);\n\
    \    newComp();\n  }\n\n  vector<int> vertexGroup(int id) {\n    return {gv.begin()\
    \ + vb[id], gv.begin() + vb[id + 1]};\n  }\n  vector<int> edgeGroup(int id) {\n\
    \    return {ge.begin() + eb[id], ge.begin() + eb[id + 1]};\n  }\n  bool isCutVertex(int\
    \ v) { return f[v] > 1; }\n  pair<vector<vector<int>>, vector<int>> blockCutTree()\
    \ {\n    int n = ssize(f);\n    vector<vector<int>> g(n + size);\n    vector<int>\
    \ mp = vid;\n    for(int &x : mp) x += n;\n    for(int i = 0; i < size; i++)\n\
    \      for(int v : vertexGroup(i))\n        if (isCutVertex(v)) {\n          g[i\
    \ + n].emplace_back(v);\n          g[v].emplace_back(i + n);\n          mp[v]\
    \ = v;\n        }\n    return make_pair(g, mp);\n  }\n};\n#line 5 \"test/biconnected_components.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ m; cin >> n >> m;\n  vector<array<int, 2>> e(m);\n  for(auto &[u, v] : e) cin\
    \ >> u >> v;\n\n  BCC bcc(e, n);\n\n  cout << bcc.size << '\\n';\n  for(int g\
    \ = 0; g < bcc.size; g++) {\n    auto gv = bcc.vertexGroup(g);\n    cout << ssize(gv);\n\
    \    for(int v : gv)\n      cout << ' ' << v;\n    cout << '\\n';\n  }\n\n  return\
    \ 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/biconnected_components\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../graph/BCC.cpp\"\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, m; cin >> n >>\
    \ m;\n  vector<array<int, 2>> e(m);\n  for(auto &[u, v] : e) cin >> u >> v;\n\n\
    \  BCC bcc(e, n);\n\n  cout << bcc.size << '\\n';\n  for(int g = 0; g < bcc.size;\
    \ g++) {\n    auto gv = bcc.vertexGroup(g);\n    cout << ssize(gv);\n    for(int\
    \ v : gv)\n      cout << ' ' << v;\n    cout << '\\n';\n  }\n\n  return 0;\n}\n\
    \n"
  dependsOn:
  - default/t.cpp
  - graph/BCC.cpp
  isVerificationFile: true
  path: test/biconnected_components.test.cpp
  requiredBy: []
  timestamp: '2024-05-14 17:31:22+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/biconnected_components.test.cpp
layout: document
redirect_from:
- /verify/test/biconnected_components.test.cpp
- /verify/test/biconnected_components.test.cpp.html
title: test/biconnected_components.test.cpp
---
