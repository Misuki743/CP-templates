---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':x:'
    path: graph/ECC.cpp
    title: graph/ECC.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"test/two_edge_connected_components.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\n\n#line 1\
    \ \"default/t.cpp\"\n#include <algorithm>\n#include <array>\n#include <bit>\n\
    #include <bitset>\n#include <cassert>\n#include <cctype>\n#include <cfenv>\n#include\
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
    \ x << ' ';\n  return os;\n}\n#line 1 \"graph/ECC.cpp\"\nstruct ECC {\n  vector<int>\
    \ vb, gv, vid;\n  vector<array<int, 2>> e;\n  int size = -1;\n\n  ECC(vector<array<int,\
    \ 2>> &_e, int n) : vid(n), e(_e) {\n    auto newComp = [&]() { vb.emplace_back(ssize(gv)),\
    \ size++; };\n\n    vector<vector<int>> g(n);\n    for(int i = 0; auto [u, v]\
    \ : e) {\n      g[u].emplace_back(i);\n      g[v].emplace_back(i++);\n    }\n\n\
    \    int t = 0, root;\n    vector<int> tin(n, -1), low(n), s;\n    vector<bool>\
    \ vis(ssize(e), false);\n\n    auto extract = [&](int v) {\n      newComp();\n\
    \      do {\n        int u = s.back(); s.pop_back();\n        vid[u] = size;\n\
    \        gv.emplace_back(u);\n      } while(gv.back() != v);\n    };\n\n    auto\
    \ dfs = [&](int v, auto &&self) -> void {\n      tin[v] = low[v] = t++;\n    \
    \  s.emplace_back(v);\n      for(int i : g[v]) if (!vis[i]) {\n        int x =\
    \ e[i][0] ^ e[i][1] ^ v;\n        vis[i] = true;\n        if (tin[x] != -1) {\n\
    \          low[v] = min(low[v], tin[x]);\n        } else {\n          self(x,\
    \ self);\n          low[v] = min(low[v], low[x]);\n          if (low[x] > tin[v])\
    \ extract(x);\n        }\n      }\n      if (v == root) extract(root);\n    };\n\
    \n    for(int v = 0; v < n; v++)\n      if (tin[v] == -1)\n        dfs(root =\
    \ v, dfs);\n\n    newComp();\n  }\n\n  vector<int> vertexGroup(int id) {\n   \
    \ return {gv.begin() + vb[id], gv.begin() + vb[id + 1]};\n  }\n  bool isBridge(int\
    \ id) { return vid[e[id][0]] != vid[e[id][1]]; }\n  vector<vector<int>> bridgeTree()\
    \ {\n    vector<vector<int>> g(size);\n    for(auto [u, v] : e) {\n      if ((u\
    \ = vid[u]) != (v = vid[v])) {\n        g[u].emplace_back(v);\n        g[v].emplace_back(u);\n\
    \      }\n    }\n    return g;\n  }\n};\n#line 5 \"test/two_edge_connected_components.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n,\
    \ m; cin >> n >> m;\n  vector<array<int, 2>> e(m);\n  for(auto &[u, v] : e) cin\
    \ >> u >> v;\n\n  ECC ecc(e, n);\n\n  cout << ecc.size << '\\n';\n  for(int g\
    \ = 0; g < ecc.size; g++) {\n    auto gv = ecc.vertexGroup(g);\n    cout << ssize(gv);\n\
    \    for(int x : gv) cout << ' ' << x;\n    cout << '\\n';\n  }\n\n  return 0;\n\
    }\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../graph/ECC.cpp\"\n\nsigned main()\
    \ {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, m; cin >> n >>\
    \ m;\n  vector<array<int, 2>> e(m);\n  for(auto &[u, v] : e) cin >> u >> v;\n\n\
    \  ECC ecc(e, n);\n\n  cout << ecc.size << '\\n';\n  for(int g = 0; g < ecc.size;\
    \ g++) {\n    auto gv = ecc.vertexGroup(g);\n    cout << ssize(gv);\n    for(int\
    \ x : gv) cout << ' ' << x;\n    cout << '\\n';\n  }\n\n  return 0;\n}\n\n"
  dependsOn:
  - default/t.cpp
  - graph/ECC.cpp
  isVerificationFile: true
  path: test/two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2024-06-29 18:02:37+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/two_edge_connected_components.test.cpp
- /verify/test/two_edge_connected_components.test.cpp.html
title: test/two_edge_connected_components.test.cpp
---
