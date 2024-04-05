---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: ds/eulerTour.cpp
    title: ds/eulerTour.cpp
  - icon: ':heavy_check_mark:'
    path: ds/fastJump.cpp
    title: ds/fastJump.cpp
  - icon: ':heavy_check_mark:'
    path: segtree/dualSegmentTree.cpp
    title: segtree/dualSegmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/vertex_add_path_sum.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#line 1 \"default/t.cpp\"\
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
    \ 2 * dep[lca(u, v)];\n  }\n};\n#line 1 \"segtree/dualSegmentTree.cpp\"\ntemplate<class\
    \ M, M(*Mid)(), class T, T(*Tid)(), T(*Top)(const T&, const T&), M(*act)(const\
    \ M&, const T&)>\nstruct dualSegmentTree {\n  vector<M> data;\n  vector<T> tag;\n\
    \  int size;\n\n  dualSegmentTree(int _size) : data(_size, Mid()), tag(_size,\
    \ Tid()), size(_size) {}\n  dualSegmentTree(vector<M> init) : data(init), tag(ssize(init),\
    \ Tid()), size(ssize(init)) {}\n\n  void apply(int i, T x) {\n    if (i < size)\n\
    \      tag[i] = Top(tag[i], x);\n    else\n      data[i - size] = act(data[i -\
    \ size], x);\n  }\n\n  int trunc(unsigned i) { return i >> countr_zero(i); }\n\
    \n  void push(int i) {\n    for(int s = bit_width((unsigned)i) - 1; s > 0; s--)\
    \ {\n      if (tag[i >> s] != Tid()) {\n        apply(i >> (s - 1), tag[i >> s]);\n\
    \        apply(i >> (s - 1) ^ 1, tag[i >> s]);\n        tag[i >> s] = Tid();\n\
    \      }\n    }\n  }\n\n  void set(int i, M x) {\n    push(i + size);\n    data[i]\
    \ = x;\n  }\n\n  M get(int i) {\n    push(i + size);\n    return data[i];\n  }\n\
    \n  void modify(int l, int r, T x) {\n    if (l >= r or x == Tid()) return;\n\
    \    push(trunc(l + size)), push(trunc(r + size) - 1);\n    for(l += size, r +=\
    \ size; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) apply(l++, x);\n      if\
    \ (r & 1) apply(--r, x);\n    }\n  }\n};\n#line 1 \"ds/eulerTour.cpp\"\n//#include<ds/fastJump.cpp>\n\
    //#include<segtree/dualSegmentTree.cpp>\n\ntemplate<class M, M(*Mid)(), M(*Mop)(const\
    \ M&, const M&), M(*Minv)(const M&), \nclass T, T(*Tid)(), T(*Top)(const T&, const\
    \ T&), M(*act)(const M&, const T&)>\nstruct eulerTour {\n  vector<int> tin, tout,\
    \ p;\n  dualSegmentTree<M, Mid, T, Tid, Top, act> st;\n  fastJump jp;\n\n  eulerTour(vector<vector<int>>\
    \ g, int root = 0) : tin(ssize(g)), tout(ssize(g)), p(ssize(g), -1), st(ssize(g)),\
    \ jp(g, root) {\n    int t = 0;\n    auto dfs = [&](int v, auto self) -> void\
    \ {\n      tin[v] = t++;\n      for(int x : g[v]) {\n        if (x == p[v]) continue;\n\
    \        p[x] = v;\n        self(x, self);\n      }\n      tout[v] = t;\n    };\n\
    \n    dfs(root, dfs);\n  }\n\n  //for point modify, path query, inversion of monoid\
    \ is needed\n  void modify(int v, T x) { st.modify(tin[v], tout[v], x); }\n  M\
    \ query(int u, int v) {\n    int lca = jp.lca(u, v);\n    M res = Mop(st.get(tin[u]),\
    \ st.get(tin[v]));\n    res = Mop(res, Minv(st.get(tin[lca])));\n    if (p[lca]\
    \ != -1)\n      res = Mop(res, Minv(st.get(tin[p[lca]])));\n    return res;\n\
    \  }\n};\n#line 7 \"test/vertex_add_path_sum.test.cpp\"\n\nll add(const ll &a,\
    \ const ll &b) { return a + b; }\nll zero() { return 0ll; }\nll inv(const ll &x)\
    \ { return -x; }\n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\
    \n  int n, q; cin >> n >> q;\n  vector<ll> a(n);\n  for(ll &x : a)\n    cin >>\
    \ x;\n  vector<vector<int>> g(n);\n  for(int i = 1; i < n; i++) {\n    int u,\
    \ v; cin >> u >> v;\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n  }\n\
    \n  eulerTour<ll, zero, add, inv, ll, zero, add, add> eu(g);\n\n  for(int v =\
    \ 0; v < n; v++)\n    eu.modify(v, a[v]);\n\n  while(q--) {\n    int t, x, y;\
    \ cin >> t >> x >> y;\n    if (t == 0)\n      eu.modify(x, y);\n    else\n   \
    \   cout << eu.query(x, y) << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../default/t.cpp\"\n#include \"../ds/fastJump.cpp\"\n#include \"\
    ../segtree/dualSegmentTree.cpp\"\n#include \"../ds/eulerTour.cpp\"\n\nll add(const\
    \ ll &a, const ll &b) { return a + b; }\nll zero() { return 0ll; }\nll inv(const\
    \ ll &x) { return -x; }\n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\
    \n  int n, q; cin >> n >> q;\n  vector<ll> a(n);\n  for(ll &x : a)\n    cin >>\
    \ x;\n  vector<vector<int>> g(n);\n  for(int i = 1; i < n; i++) {\n    int u,\
    \ v; cin >> u >> v;\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n  }\n\
    \n  eulerTour<ll, zero, add, inv, ll, zero, add, add> eu(g);\n\n  for(int v =\
    \ 0; v < n; v++)\n    eu.modify(v, a[v]);\n\n  while(q--) {\n    int t, x, y;\
    \ cin >> t >> x >> y;\n    if (t == 0)\n      eu.modify(x, y);\n    else\n   \
    \   cout << eu.query(x, y) << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - ds/fastJump.cpp
  - segtree/dualSegmentTree.cpp
  - ds/eulerTour.cpp
  isVerificationFile: true
  path: test/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2024-04-05 18:02:52+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_add_path_sum.test.cpp
- /verify/test/vertex_add_path_sum.test.cpp.html
title: test/vertex_add_path_sum.test.cpp
---
