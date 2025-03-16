---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':heavy_check_mark:'
    path: graph/hopcroftKarp.cpp
    title: graph/hopcroftKarp.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/bipartitematching_2.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/bipartitematching\"\n\n#line 1 \"default/t.cpp\"\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include\
    \ <cinttypes>\n#include <climits>\n#include <cmath>\n#include <complex>\n#include\
    \ <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <deque>\n#include <fstream>\n#include\
    \ <functional>\n#include <initializer_list>\n#include <iomanip>\n#include <ios>\n\
    #include <iostream>\n#include <istream>\n#include <iterator>\n#include <limits>\n\
    #include <list>\n#include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n\
    #include <ostream>\n#include <queue>\n#include <random>\n#include <set>\n#include\
    \ <sstream>\n#include <stack>\n#include <streambuf>\n#include <string>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <variant>\n#include <bit>\n#include\
    \ <compare>\n#include <concepts>\n#include <numbers>\n#include <ranges>\n#include\
    \ <span>\n\n#define INT128_MAX (__int128)(((unsigned __int128) 1 << ((sizeof(__int128)\
    \ * __CHAR_BIT__) - 1)) - 1)\n#define INT128_MIN (-INT128_MAX - 1)\n\n#define\
    \ clock chrono::steady_clock::now().time_since_epoch().count()\n\nusing namespace\
    \ std;\n\ntemplate<class T1, class T2>\nostream& operator<<(ostream& os, const\
    \ pair<T1, T2> pr) {\n  return os << pr.first << ' ' << pr.second;\n}\ntemplate<class\
    \ T, size_t N>\nostream& operator<<(ostream& os, const array<T, N> &arr) {\n \
    \ for(size_t i = 0; T x : arr) {\n    os << x;\n    if (++i != N) os << ' ';\n\
    \  }\n  return os;\n}\ntemplate<class T>\nostream& operator<<(ostream& os, const\
    \ vector<T> &vec) {\n  for(size_t i = 0; T x : vec) {\n    os << x;\n    if (++i\
    \ != size(vec)) os << ' ';\n  }\n  return os;\n}\ntemplate<class T>\nostream&\
    \ operator<<(ostream& os, const set<T> &s) {\n  for(size_t i = 0; T x : s) {\n\
    \    os << x;\n    if (++i != size(s)) os << ' ';\n  }\n  return os;\n}\ntemplate<class\
    \ T1, class T2>\nostream& operator<<(ostream& os, const map<T1, T2> &m) {\n  for(size_t\
    \ i = 0; pair<T1, T2> x : m) {\n    os << x;\n    if (++i != size(m)) os << '\
    \ ';\n  }\n  return os;\n}\n\n#ifdef DEBUG\n#define dbg(...) cerr << '(', _do(#__VA_ARGS__),\
    \ cerr << \") = \", _do2(__VA_ARGS__)\ntemplate<typename T> void _do(T &&x) {\
    \ cerr << x; }\ntemplate<typename T, typename ...S> void _do(T &&x, S&&...y) {\
    \ cerr << x << \", \"; _do(y...); }\ntemplate<typename T> void _do2(T &&x) { cerr\
    \ << x << endl; }\ntemplate<typename T, typename ...S> void _do2(T &&x, S&&...y)\
    \ { cerr << x << \", \"; _do2(y...); }\n#else\n#define dbg(...)\n#endif\n\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing ldb = long double;\n\
    using pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate<typename T>\
    \ using min_heap = priority_queue<T, vector<T>, greater<T>>;\ntemplate<typename\
    \ T> using max_heap = priority_queue<T>;\n\ntemplate<ranges::forward_range rng,\
    \ class T = ranges::range_value_t<rng>, class OP = plus<T>>\nvoid pSum(rng &v)\
    \ {\n  if (!v.empty())\n    for(T p = v[0]; T &x : v | views::drop(1))\n     \
    \ x = p = OP()(p, x);\n}\ntemplate<ranges::forward_range rng, class T = ranges::range_value_t<rng>,\
    \ class OP>\nvoid pSum(rng &v, OP op) {\n  if (!v.empty())\n    for(T p = v[0];\
    \ T &x : v | views::drop(1))\n      x = p = op(p, x);\n}\n\ntemplate<ranges::forward_range\
    \ rng>\nvoid Unique(rng &v) {\n  ranges::sort(v);\n  v.resize(unique(v.begin(),\
    \ v.end()) - v.begin());\n}\n\ntemplate<ranges::random_access_range rng>\nrng\
    \ invPerm(rng p) {\n  rng ret = p;\n  for(int i = 0; i < ssize(p); i++)\n    ret[p[i]]\
    \ = i;\n  return ret;\n}\n\ntemplate<ranges::random_access_range rng, ranges::random_access_range\
    \ rng2>\nrng Permute(rng v, rng2 p) {\n  rng ret = v;\n  for(int i = 0; i < ssize(p);\
    \ i++)\n    ret[p[i]] = v[i];\n  return ret;\n}\n\ntemplate<bool directed>\nvector<vector<int>>\
    \ readGraph(int n, int m, int base) {\n  vector<vector<int>> g(n);\n  for(int\
    \ i = 0; i < m; i++) {\n    int u, v; cin >> u >> v;\n    u -= base, v -= base;\n\
    \    g[u].emplace_back(v);\n    if constexpr (!directed)\n      g[v].emplace_back(u);\n\
    \  }\n  return g;\n}\n\ntemplate<class T>\nvoid setBit(T &msk, int bit, bool x)\
    \ {\n  msk = (msk & ~(T(1) << bit)) | (T(x) << bit);\n}\ntemplate<class T> void\
    \ flipBit(T &msk, int bit) { msk ^= T(1) << bit; }\ntemplate<class T> bool getBit(T\
    \ msk, int bit) { return msk >> bit & T(1); }\n\ntemplate<class T>\nT floorDiv(T\
    \ a, T b) {\n  if (b < 0) a *= -1, b *= -1;\n  return a >= 0 ? a / b : (a - b\
    \ + 1) / b;\n}\ntemplate<class T>\nT ceilDiv(T a, T b) {\n  if (b < 0) a *= -1,\
    \ b *= -1;\n  return a >= 0 ? (a + b - 1) / b : a / b;\n}\n\ntemplate<class T>\
    \ bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }\ntemplate<class T> bool\
    \ chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"graph/hopcroftKarp.cpp\"\
    \n//source: KACTL\n\n/**\n * Author: Chen Xing\n * Date: 2009-10-13\n * License:\
    \ CC0\n * Source: N/A\n * Description: Fast bipartite matching algorithm. Graph\
    \ $g$ should be a list\n * of neighbors of the left partition, and $btoa$ should\
    \ be a vector full of\n * -1's of the same size as the right partition. Returns\
    \ the size of\n * the matching. $btoa[i]$ will be the match for vertex $i$ on\
    \ the right side,\n * or $-1$ if it's not matched.\n * Usage: vi btoa(m, -1);\
    \ hopcroftKarp(g, btoa);\n * Time: O(\\sqrt{V}E)\n * Status: stress-tested by\
    \ MinimumVertexCover, and tested on oldkattis.adkbipmatch and SPOJ:MATCHING\n\
    \ */\n\n#define rep(i, a, b) for(int i = a; i < (b); ++i)\n#define all(x) begin(x),\
    \ end(x)\n#define sz(x) (int)(x).size()\ntypedef vector<int> vi;\n\nbool dfs(int\
    \ a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {\n\tif (A[a] != L) return\
    \ 0;\n\tA[a] = -1;\n\tfor (int b : g[a]) if (B[b] == L + 1) {\n\t\tB[b] = 0;\n\
    \t\tif (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))\n\t\t\treturn btoa[b]\
    \ = a, 1;\n\t}\n\treturn 0;\n}\n\nint hopcroftKarp(vector<vi>& g, vi& btoa) {\n\
    \tint res = 0;\n\tvi A(g.size()), B(btoa.size()), cur, next;\n\tfor (;;) {\n\t\
    \tfill(all(A), 0);\n\t\tfill(all(B), 0);\n\t\t/// Find the starting nodes for\
    \ BFS (i.e. layer 0).\n\t\tcur.clear();\n\t\tfor (int a : btoa) if(a != -1) A[a]\
    \ = -1;\n\t\trep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);\n\t\t/// Find all\
    \ layers using bfs.\n\t\tfor (int lay = 1;; lay++) {\n\t\t\tbool islast = 0;\n\
    \t\t\tnext.clear();\n\t\t\tfor (int a : cur) for (int b : g[a]) {\n\t\t\t\tif\
    \ (btoa[b] == -1) {\n\t\t\t\t\tB[b] = lay;\n\t\t\t\t\tislast = 1;\n\t\t\t\t}\n\
    \t\t\t\telse if (btoa[b] != a && !B[b]) {\n\t\t\t\t\tB[b] = lay;\n\t\t\t\t\tnext.push_back(btoa[b]);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\tif (islast) break;\n\t\t\tif (next.empty()) return res;\n\
    \t\t\tfor (int a : next) A[a] = lay;\n\t\t\tcur.swap(next);\n\t\t}\n\t\t/// Use\
    \ DFS to scan for augmenting paths.\n\t\trep(a,0,sz(g))\n\t\t\tres += dfs(a, 0,\
    \ g, btoa, A, B);\n\t}\n}\n#line 5 \"test/bipartitematching_2.test.cpp\"\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int l, r, m; cin\
    \ >> l >> r >> m;\n  vector<vi> g(l);\n  vi btoa(r, -1);\n  for(int i = 0; i <\
    \ m; i++) {\n    int a, b; cin >> a >> b;\n    g[a].emplace_back(b);\n  }\n  cout\
    \ << hopcroftKarp(g, btoa) << '\\n';\n  for(int i = 0; i < r; i++)\n    if (btoa[i]\
    \ != -1)\n      cout << btoa[i] << ' ' << i << '\\n';\n\n  return 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include \"../default/t.cpp\"\n#include \"../graph/hopcroftKarp.cpp\"\n\nsigned\
    \ main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  int l, r, m; cin\
    \ >> l >> r >> m;\n  vector<vi> g(l);\n  vi btoa(r, -1);\n  for(int i = 0; i <\
    \ m; i++) {\n    int a, b; cin >> a >> b;\n    g[a].emplace_back(b);\n  }\n  cout\
    \ << hopcroftKarp(g, btoa) << '\\n';\n  for(int i = 0; i < r; i++)\n    if (btoa[i]\
    \ != -1)\n      cout << btoa[i] << ' ' << i << '\\n';\n\n  return 0;\n}\n\n"
  dependsOn:
  - default/t.cpp
  - graph/hopcroftKarp.cpp
  isVerificationFile: true
  path: test/bipartitematching_2.test.cpp
  requiredBy: []
  timestamp: '2025-03-16 13:02:37+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/bipartitematching_2.test.cpp
layout: document
redirect_from:
- /verify/test/bipartitematching_2.test.cpp
- /verify/test/bipartitematching_2.test.cpp.html
title: test/bipartitematching_2.test.cpp
---
