---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':x:'
    path: ds/eulerTour2.cpp
    title: ds/eulerTour2.cpp
  - icon: ':question:'
    path: segtree/segmentTree.cpp
    title: segtree/segmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/vertex_add_subtree_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n#line 1 \"default/t.cpp\"\
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
    \nnamespace R = std::ranges;\nnamespace V = std::views;\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing ull = unsigned long long;\nusing ldb = long double;\n\
    using pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate<class T>\n\
    ostream& operator<<(ostream& os, const pair<T, T> pr) {\n  return os << pr.first\
    \ << ' ' << pr.second;\n}\ntemplate<class T, size_t N>\nostream& operator<<(ostream&\
    \ os, const array<T, N> &arr) {\n  for(const T &X : arr)\n    os << X << ' ';\n\
    \  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const vector<T>\
    \ &vec) {\n  for(const T &X : vec)\n    os << X << ' ';\n  return os;\n}\ntemplate<class\
    \ T>\nostream& operator<<(ostream& os, const set<T> &s) {\n  for(const T &x :\
    \ s)\n    os << x << ' ';\n  return os;\n}\n#line 1 \"segtree/segmentTree.cpp\"\
    \n/**\n * template name: segmentTree\n * author: Misuki\n * last update: 2024/01/01\n\
    \ * verify: library checker - Point Add Range Sum, Static RMQ\n */\n\ntemplate<class\
    \ M, M(*unit)(), M(*combine)(const M&, const M&)>\nstruct segmentTree {\n  vector<M>\
    \ data;\n  int size;\n\n  segmentTree(int _size) : data(2 * _size, unit()), size(_size)\
    \ {}\n\n  segmentTree(vector<M> init) : data(2 * ssize(init), unit()), size(ssize(init))\
    \ {\n    copy(init.begin(), init.end(), data.begin() + size);\n    for(int i =\
    \ size - 1; i > 0; i--)\n      data[i] = combine(data[i << 1], data[i << 1 | 1]);\n\
    \  }\n\n  void set(int i, M x) {\n    data[i += size] = x;\n    while(i >>= 1)\n\
    \      data[i] = combine(data[i << 1], data[i << 1 | 1]);\n  }\n\n  M get(int\
    \ i) { return data[i + size]; }\n\n  M query(int l, int r) {\n    M L = unit(),\
    \ R = unit();\n    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {\n    \
    \  if (l & 1) L = combine(L, data[l++]);\n      if (r & 1) R = combine(data[--r],\
    \ R);\n    }\n    return combine(L, R);\n  }\n};\n#line 1 \"ds/eulerTour2.cpp\"\
    \n//#include<segtree/segmentTree.cpp>\n\ntemplate<class M, M(*unit)(), M(*combine)(const\
    \ M&, const M&)>\nstruct eulerTour2 {\n  vector<int> tin, tout, p;\n  segmentTree<M,\
    \ unit, combine> st;\n\n  eulerTour2(vector<vector<int>> g, int root = 0) : tin(ssize(g)),\
    \ tout(ssize(g)), p(ssize(g), -1), st(ssize(g)) {\n    int t = 0;\n    auto dfs\
    \ = [&](int v, auto self) -> void {\n      tin[v] = t++;\n      for(int x : g[v])\
    \ {\n        if (x == p[v]) continue;\n        p[x] = v;\n        self(x, self);\n\
    \      }\n      tout[v] = t;\n    };\n\n    dfs(root, dfs);\n  }\n\n  void set(int\
    \ v, M x) { st.set(tin[v], x); }\n  M get(int v) { return st.get(tin[v]); }\n\
    \  M query(int v) { return st.query(tin[v], tout[v]); }\n};\n#line 6 \"test/vertex_add_subtree_sum.test.cpp\"\
    \n\nll unit() { return 0ll; }\nll add(const ll &a, const ll &b) { return a + b;\
    \ }\n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int\
    \ n, q; cin >> n >> q;\n  vector<ll> a(n);\n  for(ll &x : a)\n    cin >> x;\n\
    \  vector<vector<int>> g(n);\n  for(int u = 1; u < n; u++) {\n    int v; cin >>\
    \ v;\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n  }\n\n  eulerTour2<ll,\
    \ unit, add> eu(g);\n\n  for(int v = 0; v < n; v++)\n    eu.set(v, a[v]);\n\n\
    \  while(q--) {\n    int t; cin >> t;\n    if (t == 0) {\n      int x, y; cin\
    \ >> x >> y;\n      eu.set(x, eu.get(x) + y);\n    } else {\n      int x; cin\
    \ >> x;\n      cout << eu.query(x) << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../default/t.cpp\"\n#include \"../segtree/segmentTree.cpp\"\n#include\
    \ \"../ds/eulerTour2.cpp\"\n\nll unit() { return 0ll; }\nll add(const ll &a, const\
    \ ll &b) { return a + b; }\n\nsigned main() {\n  ios::sync_with_stdio(false),\
    \ cin.tie(NULL);\n\n  int n, q; cin >> n >> q;\n  vector<ll> a(n);\n  for(ll &x\
    \ : a)\n    cin >> x;\n  vector<vector<int>> g(n);\n  for(int u = 1; u < n; u++)\
    \ {\n    int v; cin >> v;\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n\
    \  }\n\n  eulerTour2<ll, unit, add> eu(g);\n\n  for(int v = 0; v < n; v++)\n \
    \   eu.set(v, a[v]);\n\n  while(q--) {\n    int t; cin >> t;\n    if (t == 0)\
    \ {\n      int x, y; cin >> x >> y;\n      eu.set(x, eu.get(x) + y);\n    } else\
    \ {\n      int x; cin >> x;\n      cout << eu.query(x) << '\\n';\n    }\n  }\n\
    \n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - segtree/segmentTree.cpp
  - ds/eulerTour2.cpp
  isVerificationFile: true
  path: test/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-21 17:57:06+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_add_subtree_sum.test.cpp
- /verify/test/vertex_add_subtree_sum.test.cpp.html
title: test/vertex_add_subtree_sum.test.cpp
---
