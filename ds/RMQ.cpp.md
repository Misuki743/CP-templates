---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/lca_2.test.cpp
    title: test/lca_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lca_3.test.cpp
    title: test/lca_3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest_auxiliary_tree.test.cpp
    title: test/mytest_auxiliary_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/static_RMQ_2.test.cpp
    title: test/static_RMQ_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/RMQ.cpp\"\ntemplate<class T>\nstruct RMQ {\n  uint64_t\
    \ size;\n  vector<T> base;\n  vector<vector<T>> table;\n  vector<uint32_t> msk;\n\
    \n  static const int lgw = 5;\n  static const int w = 1 << lgw;\n  RMQ(vector<T>\
    \ _base) : size(ssize(_base)), base(_base), msk(size) {\n    msk.back() = 1;\n\
    \    for(int i = size - 2; i >= 0; i--) {\n      msk[i] = msk[i + 1] << 1;\n \
    \     while(msk[i] != 0 and base[i + countr_zero(msk[i])] >= base[i])\n      \
    \  msk[i] ^= 1u << countr_zero(msk[i]);\n      msk[i] |= 1u;\n    }\n\n    table\
    \ = vector(bit_width(size >> lgw), vector<T>(size >> lgw));\n    if (!table.empty())\n\
    \      for(uint64_t i = 0; i + w <= size; i += w)\n        table[0][i >> lgw]\
    \ = base[i + bit_width(msk[i]) - 1];\n    for(int i = 1; i < ssize(table); i++)\n\
    \      for(uint64_t j = 0; j < (size >> lgw); j++)\n        if (j + (1 << (i -\
    \ 1)) < (size >> lgw))\n          table[i][j] = min(table[i - 1][j], table[i -\
    \ 1][j + (1 << (i - 1))]);\n        else\n          table[i][j] = table[i - 1][j];\n\
    \  }\n\n  T query(int l, int r) {\n    if (l >= r) {\n      return numeric_limits<T>::max();\n\
    \    } else if (r - l <= w) {\n      return base[l + bit_width(msk[l] & (~0u >>\
    \ (w - (r - l)))) - 1];\n    } else {\n      T ret = min(query(l, l + w), query(r\
    \ - w, r));\n      l = (l + w) >> lgw, r >>= lgw;\n      if (l == r) return ret;\n\
    \      int range = bit_width((unsigned)(r - l)) - 1;\n      return min({ret, table[range][l],\
    \ table[range][r - (1 << range)]});\n    }\n  }\n};\n"
  code: "template<class T>\nstruct RMQ {\n  uint64_t size;\n  vector<T> base;\n  vector<vector<T>>\
    \ table;\n  vector<uint32_t> msk;\n\n  static const int lgw = 5;\n  static const\
    \ int w = 1 << lgw;\n  RMQ(vector<T> _base) : size(ssize(_base)), base(_base),\
    \ msk(size) {\n    msk.back() = 1;\n    for(int i = size - 2; i >= 0; i--) {\n\
    \      msk[i] = msk[i + 1] << 1;\n      while(msk[i] != 0 and base[i + countr_zero(msk[i])]\
    \ >= base[i])\n        msk[i] ^= 1u << countr_zero(msk[i]);\n      msk[i] |= 1u;\n\
    \    }\n\n    table = vector(bit_width(size >> lgw), vector<T>(size >> lgw));\n\
    \    if (!table.empty())\n      for(uint64_t i = 0; i + w <= size; i += w)\n \
    \       table[0][i >> lgw] = base[i + bit_width(msk[i]) - 1];\n    for(int i =\
    \ 1; i < ssize(table); i++)\n      for(uint64_t j = 0; j < (size >> lgw); j++)\n\
    \        if (j + (1 << (i - 1)) < (size >> lgw))\n          table[i][j] = min(table[i\
    \ - 1][j], table[i - 1][j + (1 << (i - 1))]);\n        else\n          table[i][j]\
    \ = table[i - 1][j];\n  }\n\n  T query(int l, int r) {\n    if (l >= r) {\n  \
    \    return numeric_limits<T>::max();\n    } else if (r - l <= w) {\n      return\
    \ base[l + bit_width(msk[l] & (~0u >> (w - (r - l)))) - 1];\n    } else {\n  \
    \    T ret = min(query(l, l + w), query(r - w, r));\n      l = (l + w) >> lgw,\
    \ r >>= lgw;\n      if (l == r) return ret;\n      int range = bit_width((unsigned)(r\
    \ - l)) - 1;\n      return min({ret, table[range][l], table[range][r - (1 << range)]});\n\
    \    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/RMQ.cpp
  requiredBy: []
  timestamp: '2024-07-24 13:33:23+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lca_2.test.cpp
  - test/lca_3.test.cpp
  - test/static_RMQ_2.test.cpp
  - test/mytest_auxiliary_tree.test.cpp
documentation_of: ds/RMQ.cpp
layout: document
redirect_from:
- /library/ds/RMQ.cpp
- /library/ds/RMQ.cpp.html
title: ds/RMQ.cpp
---
