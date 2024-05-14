---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: graph/treeHash.cpp
    title: graph/treeHash.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
    links:
    - https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
  bundledCode: "#line 1 \"test/rooted_tree_isomorphism_classification.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
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
    \ \"graph/treeHash.cpp\"\ntemplate<bool ordered = false>\npair<int, vector<int>>\
    \ treeHash(vector<vector<int>> &g, int root = 0) {\n  int nxt = 0;\n  static map<vector<int>,\
    \ int> toId;\n  vector<int> id(ssize(g));\n  auto dfs = [&](int v, int p, auto\
    \ self) -> int {\n    vector<int> seq;\n    seq.reserve(ssize(g[v]));\n    for(int\
    \ x : g[v]) if (x != p)\n      seq.emplace_back(self(x, v, self));\n    if constexpr\
    \ (!ordered)\n      ranges::sort(seq);\n    if (!toId.contains(seq))\n      toId[seq]\
    \ = nxt++;\n    return id[v] = toId[seq];\n  };\n\n  dfs(root, -1, dfs);\n\n \
    \ return make_pair(nxt, id);\n}\n#line 5 \"test/rooted_tree_isomorphism_classification.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n;\
    \ cin >> n;\n  vector<vector<int>> g(n);\n  for(int u = 1; u < n; u++) {\n   \
    \ int v; cin >> v;\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n  }\n\
    \n  auto [cnt, id] = treeHash(g);\n  cout << cnt << '\\n';\n  cout << id << '\\\
    n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../graph/treeHash.cpp\"\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int n; cin >> n;\n\
    \  vector<vector<int>> g(n);\n  for(int u = 1; u < n; u++) {\n    int v; cin >>\
    \ v;\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n  }\n\n  auto [cnt,\
    \ id] = treeHash(g);\n  cout << cnt << '\\n';\n  cout << id << '\\n';\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - graph/treeHash.cpp
  isVerificationFile: true
  path: test/rooted_tree_isomorphism_classification.test.cpp
  requiredBy: []
  timestamp: '2024-04-05 19:44:35+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/rooted_tree_isomorphism_classification.test.cpp
layout: document
redirect_from:
- /verify/test/rooted_tree_isomorphism_classification.test.cpp
- /verify/test/rooted_tree_isomorphism_classification.test.cpp.html
title: test/rooted_tree_isomorphism_classification.test.cpp
---
