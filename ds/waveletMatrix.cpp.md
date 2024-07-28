---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/range_kth_smallest.test.cpp
    title: test/range_kth_smallest.test.cpp
  - icon: ':x:'
    path: test/static_range_frequency.test.cpp
    title: test/static_range_frequency.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/waveletMatrix.cpp\"\ntemplate<class T, int H>\nstruct\
    \ waveletMatrix {\n  using uint = uint32_t;\n  struct bitvec {\n    static constexpr\
    \ uint W = 64;\n    int cnt0 = 0, size;\n    vector<ull> bv;\n    vector<int>\
    \ pre;\n\n    bitvec(uint _size) : size(_size), bv(size / W + 1), pre(size / W\
    \ + 1) {};\n    void set(uint i) { bv[i / W] |= 1LL << (i % W); }\n    uint get(uint\
    \ i) { return bv[i / W] >> (i % W) & 1; }\n    void build() {\n      for(int i\
    \ = 1; i < ssize(pre); i++)\n        pre[i] = pre[i - 1] + popcount(bv[i - 1]);\n\
    \      cnt0 = rank0(size);\n    }\n    int rank1(uint i) { return pre[i / W] +\
    \ popcount(bv[i / W] & ((1LL << i) - 1)); }\n    int rank0(uint i) { return i\
    \ - rank1(i); }\n  };\n\n  vector<bitvec> data;\n  waveletMatrix(vector<T> init)\
    \ : data(H + 1, bitvec(init.size())) {\n    for(int bit = H; auto &v : data) {\n\
    \      for(int i = 0; i < ssize(init); i++)\n        if (init[i] >> bit & 1)\n\
    \          v.set(i);\n      v.build();\n      vector<T> tmp(ssize(init));\n  \
    \    int ptr[2] = {0, v.cnt0};\n      for(int i = 0; i < ssize(init); i++)\n \
    \       tmp[ptr[v.get(i)]++] = init[i];\n      init.swap(tmp);\n      bit--;\n\
    \    }\n  }\n\n  T kth(int l, int r, int k) {\n    T res = 0;\n    for(int bit\
    \ = H; auto &v : data) {\n      if (int l0 = v.rank0(l), r0 = v.rank0(r); r0 -\
    \ l0 <= k) {\n        res |= T(1) << bit, k -= r0 - l0;\n        l = v.cnt0 +\
    \ v.rank1(l), r = v.cnt0 + v.rank1(r);\n      } else {\n        l = l0, r = r0;\n\
    \      }\n      bit--;\n    }\n    return res;\n  }\n\n  int less(int l, int r,\
    \ T u) {\n    if (u >= (T(2) << H)) return r - l;\n    int cnt = 0;\n    for(int\
    \ bit = H; auto &v : data) {\n      if (u >> bit & 1) {\n        cnt += v.rank0(r)\
    \ - v.rank0(l);\n        l = v.cnt0 + v.rank1(l), r = v.cnt0 + v.rank1(r);\n \
    \     } else {\n        l = v.rank0(l), r = v.rank0(r);\n      }\n      bit--;\n\
    \    }\n    return cnt;\n  }\n\n  int rectQuery(int l, int r, T d, T u) {\n  \
    \  return less(l, r, u) - less(l, r, d);\n  }\n};\n"
  code: "template<class T, int H>\nstruct waveletMatrix {\n  using uint = uint32_t;\n\
    \  struct bitvec {\n    static constexpr uint W = 64;\n    int cnt0 = 0, size;\n\
    \    vector<ull> bv;\n    vector<int> pre;\n\n    bitvec(uint _size) : size(_size),\
    \ bv(size / W + 1), pre(size / W + 1) {};\n    void set(uint i) { bv[i / W] |=\
    \ 1LL << (i % W); }\n    uint get(uint i) { return bv[i / W] >> (i % W) & 1; }\n\
    \    void build() {\n      for(int i = 1; i < ssize(pre); i++)\n        pre[i]\
    \ = pre[i - 1] + popcount(bv[i - 1]);\n      cnt0 = rank0(size);\n    }\n    int\
    \ rank1(uint i) { return pre[i / W] + popcount(bv[i / W] & ((1LL << i) - 1));\
    \ }\n    int rank0(uint i) { return i - rank1(i); }\n  };\n\n  vector<bitvec>\
    \ data;\n  waveletMatrix(vector<T> init) : data(H + 1, bitvec(init.size())) {\n\
    \    for(int bit = H; auto &v : data) {\n      for(int i = 0; i < ssize(init);\
    \ i++)\n        if (init[i] >> bit & 1)\n          v.set(i);\n      v.build();\n\
    \      vector<T> tmp(ssize(init));\n      int ptr[2] = {0, v.cnt0};\n      for(int\
    \ i = 0; i < ssize(init); i++)\n        tmp[ptr[v.get(i)]++] = init[i];\n    \
    \  init.swap(tmp);\n      bit--;\n    }\n  }\n\n  T kth(int l, int r, int k) {\n\
    \    T res = 0;\n    for(int bit = H; auto &v : data) {\n      if (int l0 = v.rank0(l),\
    \ r0 = v.rank0(r); r0 - l0 <= k) {\n        res |= T(1) << bit, k -= r0 - l0;\n\
    \        l = v.cnt0 + v.rank1(l), r = v.cnt0 + v.rank1(r);\n      } else {\n \
    \       l = l0, r = r0;\n      }\n      bit--;\n    }\n    return res;\n  }\n\n\
    \  int less(int l, int r, T u) {\n    if (u >= (T(2) << H)) return r - l;\n  \
    \  int cnt = 0;\n    for(int bit = H; auto &v : data) {\n      if (u >> bit &\
    \ 1) {\n        cnt += v.rank0(r) - v.rank0(l);\n        l = v.cnt0 + v.rank1(l),\
    \ r = v.cnt0 + v.rank1(r);\n      } else {\n        l = v.rank0(l), r = v.rank0(r);\n\
    \      }\n      bit--;\n    }\n    return cnt;\n  }\n\n  int rectQuery(int l,\
    \ int r, T d, T u) {\n    return less(l, r, u) - less(l, r, d);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/waveletMatrix.cpp
  requiredBy: []
  timestamp: '2024-03-07 00:40:25+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/range_kth_smallest.test.cpp
  - test/static_range_frequency.test.cpp
documentation_of: ds/waveletMatrix.cpp
layout: document
title: waveletMatrix
---

## usage

- `waveletMatrix<T, mxBit>(init)` construct WM using init, whose value ranges from $0$ to $2^{\text{mxBit} + 1} - 1$, $O(n \cdot mxBit)$
- `kth(l, r, k)` return k-th smallest number in range $[l, r)$, $O(mxBit)$
- `rectQuery(l, r, d, u)` return number of elements with value in $[d, u)$ whose position in $[l, r)$, $O(mxBit)$
