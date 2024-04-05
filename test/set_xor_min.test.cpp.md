---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: default/t.cpp
    title: default/t.cpp
  - icon: ':x:'
    path: ds/binaryTrie.cpp
    title: ds/binaryTrie.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/set_xor_min.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\
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
    \ \"ds/binaryTrie.cpp\"\ntemplate<int mxBit, bool duplicate = false>\nstruct binaryTrie\
    \ {\n  vector<array<int, 2>> nxt;\n  vector<int> cnt;\n\n  binaryTrie(int size\
    \ = 0) : nxt(1, {-1, -1}), cnt(1) {\n    nxt.reserve(size);\n    cnt.reserve(size);\n\
    \  }\n\n  int count(ull x) {\n    int v = 0;\n    for(int bit = mxBit; bit >=\
    \ 0; bit--) {\n      ull to = x >> bit & 1;\n      if (nxt[v][to] == -1) return\
    \ 0;\n      v = nxt[v][to];\n    }\n    return cnt[v];\n  }\n\n  void insert(ull\
    \ x) {\n    if constexpr (!duplicate) {\n      if (count(x)) return;\n    }\n\
    \    int v = 0;\n    cnt[0] += 1;\n    for(int bit = mxBit; bit >= 0; bit--) {\n\
    \      ull to = x >> bit & 1;\n      if (nxt[v][to] == -1) {\n        nxt[v][to]\
    \ = ssize(nxt);\n        nxt.push_back({-1, -1});\n        cnt.emplace_back();\n\
    \      }\n      v = nxt[v][to], cnt[v] += 1;\n    }\n  }\n\n  void erase(ull x)\
    \ {\n    if (!count(x)) return;\n    int v = 0;\n    cnt[0] -= 1;\n    for(int\
    \ bit = mxBit; bit >= 0; bit--)\n      v = nxt[v][x >> bit & 1], cnt[v] -= 1;\n\
    \  }\n\n  ull queryMin(ull Xor = 0LL) {\n    assert(cnt[0] > 0);\n    ull res\
    \ = 0;\n    int v = 0;\n    for(int bit = mxBit; bit >= 0; bit--) {\n      ull\
    \ to = Xor >> bit & 1;\n      if (nxt[v][to] != -1 and cnt[nxt[v][to]] >= 1)\n\
    \        v = nxt[v][to];\n      else\n        res |= 1LL << bit, v = nxt[v][to\
    \ ^ 1];\n    }\n    return res;\n  }\n};\n#line 5 \"test/set_xor_min.test.cpp\"\
    \n\nsigned main() {\n  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  binaryTrie<29>\
    \ tr(500000 * 30);\n\n  int q; cin >> q;\n  while(q--) {\n    int t, x; cin >>\
    \ t >> x;\n    if (t == 0)\n      tr.insert(x);\n    else if (t == 1)\n      tr.erase(x);\n\
    \    else if (t == 2)\n      cout << tr.queryMin(x) << '\\n';\n  }\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ \"../default/t.cpp\"\n#include \"../ds/binaryTrie.cpp\"\n\nsigned main() {\n\
    \  ios::sync_with_stdio(false), cin.tie(NULL);\n\n  binaryTrie<29> tr(500000 *\
    \ 30);\n\n  int q; cin >> q;\n  while(q--) {\n    int t, x; cin >> t >> x;\n \
    \   if (t == 0)\n      tr.insert(x);\n    else if (t == 1)\n      tr.erase(x);\n\
    \    else if (t == 2)\n      cout << tr.queryMin(x) << '\\n';\n  }\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - default/t.cpp
  - ds/binaryTrie.cpp
  isVerificationFile: true
  path: test/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2024-04-05 18:02:52+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/test/set_xor_min.test.cpp
- /verify/test/set_xor_min.test.cpp.html
title: test/set_xor_min.test.cpp
---
