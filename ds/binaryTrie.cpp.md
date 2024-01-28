---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/set_xor_min.test.cpp
    title: test/set_xor_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/binaryTrie.cpp\"\ntemplate<int mxBit, bool duplicate\
    \ = false>\nstruct binaryTrie {\n  vector<array<int, 2>> nxt;\n  vector<int> cnt;\n\
    \n  binaryTrie(int size = 0) : nxt(1, {-1, -1}), cnt(1) {\n    nxt.reserve(size);\n\
    \    cnt.reserve(size);\n  }\n\n  int count(ull x) {\n    int v = 0;\n    for(int\
    \ bit = mxBit; bit >= 0; bit--) {\n      ull to = x >> bit & 1;\n      if (nxt[v][to]\
    \ == -1) return 0;\n      v = nxt[v][to];\n    }\n    return cnt[v];\n  }\n\n\
    \  void insert(ull x) {\n    if constexpr (!duplicate) {\n      if (count(x))\
    \ return;\n    }\n    int v = 0;\n    cnt[0] += 1;\n    for(int bit = mxBit; bit\
    \ >= 0; bit--) {\n      ull to = x >> bit & 1;\n      if (nxt[v][to] == -1) {\n\
    \        nxt[v][to] = ssize(nxt);\n        nxt.push_back({-1, -1});\n        cnt.emplace_back();\n\
    \      }\n      v = nxt[v][to], cnt[v] += 1;\n    }\n  }\n\n  void erase(ull x)\
    \ {\n    if (!count(x)) return;\n    int v = 0;\n    cnt[0] -= 1;\n    for(int\
    \ bit = mxBit; bit >= 0; bit--)\n      v = nxt[v][x >> bit & 1], cnt[v] -= 1;\n\
    \  }\n\n  ull queryMin(ull Xor = 0LL) {\n    assert(cnt[0] > 0);\n    ull res\
    \ = 0;\n    int v = 0;\n    for(int bit = mxBit; bit >= 0; bit--) {\n      ull\
    \ to = Xor >> bit & 1;\n      if (nxt[v][to] != -1 and cnt[nxt[v][to]] >= 1)\n\
    \        v = nxt[v][to];\n      else\n        res |= 1LL << bit, v = nxt[v][to\
    \ ^ 1];\n    }\n    return res;\n  }\n};\n"
  code: "template<int mxBit, bool duplicate = false>\nstruct binaryTrie {\n  vector<array<int,\
    \ 2>> nxt;\n  vector<int> cnt;\n\n  binaryTrie(int size = 0) : nxt(1, {-1, -1}),\
    \ cnt(1) {\n    nxt.reserve(size);\n    cnt.reserve(size);\n  }\n\n  int count(ull\
    \ x) {\n    int v = 0;\n    for(int bit = mxBit; bit >= 0; bit--) {\n      ull\
    \ to = x >> bit & 1;\n      if (nxt[v][to] == -1) return 0;\n      v = nxt[v][to];\n\
    \    }\n    return cnt[v];\n  }\n\n  void insert(ull x) {\n    if constexpr (!duplicate)\
    \ {\n      if (count(x)) return;\n    }\n    int v = 0;\n    cnt[0] += 1;\n  \
    \  for(int bit = mxBit; bit >= 0; bit--) {\n      ull to = x >> bit & 1;\n   \
    \   if (nxt[v][to] == -1) {\n        nxt[v][to] = ssize(nxt);\n        nxt.push_back({-1,\
    \ -1});\n        cnt.emplace_back();\n      }\n      v = nxt[v][to], cnt[v] +=\
    \ 1;\n    }\n  }\n\n  void erase(ull x) {\n    if (!count(x)) return;\n    int\
    \ v = 0;\n    cnt[0] -= 1;\n    for(int bit = mxBit; bit >= 0; bit--)\n      v\
    \ = nxt[v][x >> bit & 1], cnt[v] -= 1;\n  }\n\n  ull queryMin(ull Xor = 0LL) {\n\
    \    assert(cnt[0] > 0);\n    ull res = 0;\n    int v = 0;\n    for(int bit =\
    \ mxBit; bit >= 0; bit--) {\n      ull to = Xor >> bit & 1;\n      if (nxt[v][to]\
    \ != -1 and cnt[nxt[v][to]] >= 1)\n        v = nxt[v][to];\n      else\n     \
    \   res |= 1LL << bit, v = nxt[v][to ^ 1];\n    }\n    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/binaryTrie.cpp
  requiredBy: []
  timestamp: '2024-01-28 22:59:51+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/set_xor_min.test.cpp
documentation_of: ds/binaryTrie.cpp
layout: document
redirect_from:
- /library/ds/binaryTrie.cpp
- /library/ds/binaryTrie.cpp.html
title: ds/binaryTrie.cpp
---
