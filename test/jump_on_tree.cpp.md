---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/fastJump.cpp
    title: ds/fastJump.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/jump_on_tree
  bundledCode: "#line 1 \"test/jump_on_tree.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\
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
    \nnamespace R = std::ranges;\nnamespace V = std::views;\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing ull = unsigned long long;\nusing ldb = long double;\n\
    using pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate<class T>\n\
    ostream& operator<<(ostream& os, const pair<T, T> pr) {\n  return os << pr.first\
    \ << ' ' << pr.second;\n}\ntemplate<class T, size_t N>\nostream& operator<<(ostream&\
    \ os, const array<T, N> &arr) {\n  for(const T &X : arr)\n    os << X << ' ';\n\
    \  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const vector<T>\
    \ &vec) {\n  for(const T &X : vec)\n    os << X << ' ';\n  return os;\n}\ntemplate<class\
    \ T>\nostream& operator<<(ostream& os, const set<T> &s) {\n  for(const T &x :\
    \ s)\n    os << x << ' ';\n  return os;\n}\n#line 1 \"ds/fastJump.cpp\"\nstruct\
    \ fastJump {\n  vector<int> p, jp, dep;\n\n  fastJump(vector<vector<int>> g, int\
    \ root = 0) : p(ssize(g)), jp(ssize(g)), dep(ssize(g)) {\n    auto dfs = [&](int\
    \ v, auto self) -> void {\n      if (dep[p[v]] + dep[jp[jp[p[v]]]] == 2 * dep[jp[p[v]]])\n\
    \        jp[v] = jp[jp[p[v]]];\n      else\n        jp[v] = p[v];\n\n      for(int\
    \ x : g[v]) {\n        if (x == p[v]) continue;\n        p[x] = v, dep[x] = dep[v]\
    \ + 1;\n        self(x, self);\n      }\n    };\n\n    p[root] = jp[root] = root;\n\
    \    dfs(root, dfs);\n  }\n\n  int jump(int v, int k) {\n    k = min(k, dep[v]);\n\
    \    while(k) {\n      if (int d = dep[v] - dep[jp[v]]; d <= k)\n        v = jp[v],\
    \ k -= d;\n      else\n        v = p[v], k -= 1;\n    }\n    return v;\n  }\n\n\
    \  int lca(int u, int v) {\n    if (dep[u] < dep[v])\n      swap(u, v);\n    u\
    \ = jump(u, dep[u] - dep[v]);\n    if (u == v) return u;\n    while(p[u] != p[v])\
    \ {\n      if (jp[u] != jp[v]) u = jp[u], v = jp[v];\n      else u = p[u], v =\
    \ p[v];\n    }\n    return p[u];\n  }\n\n  int kth(int s, int t, int k) {\n  \
    \  int m = lca(s, t);\n    if (dep[s] + dep[t] - 2 * dep[m] < k)\n      return\
    \ -1;\n    else if (dep[s] - dep[m] >= k)\n      return jump(s, k);\n    else\n\
    \      return jump(t, dep[s] + dep[t] - 2 * dep[m] - k);\n  }\n};\n#line 5 \"\
    test/jump_on_tree.cpp\"\n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\
    \n  int n, q; cin >> n >> q;\n  vector<vector<int>> g(n);\n  for(int i = 1; i\
    \ < n; i++) {\n    int u, v; cin >> u >> v;\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n\
    \  }\n\n  fastJump jp(g);\n\n  while(q--) {\n    int s, t, i; cin >> s >> t >>\
    \ i;\n    cout << jp.kth(s, t, i) << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\n\n#include\
    \ \"../default/t.cpp\"\n#include \"../ds/fastJump.cpp\"\n\nsigned main() {\n \
    \ ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n\
    \  vector<vector<int>> g(n);\n  for(int i = 1; i < n; i++) {\n    int u, v; cin\
    \ >> u >> v;\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n  }\n\n  fastJump\
    \ jp(g);\n\n  while(q--) {\n    int s, t, i; cin >> s >> t >> i;\n    cout <<\
    \ jp.kth(s, t, i) << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - ds/fastJump.cpp
  isVerificationFile: false
  path: test/jump_on_tree.cpp
  requiredBy: []
  timestamp: '2024-01-21 01:13:07+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/jump_on_tree.cpp
layout: document
redirect_from:
- /library/test/jump_on_tree.cpp
- /library/test/jump_on_tree.cpp.html
title: test/jump_on_tree.cpp
---
