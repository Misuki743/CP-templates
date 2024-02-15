---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/range_kth_smallest.test.cpp
    title: test/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/static_range_frequency.test.cpp
    title: test/static_range_frequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/waveletMatrix.cpp\"\ntemplate<class T, int mxBit>\nstruct\
    \ waveletMatrix {\n  using uint = uint32_t;\n  struct bitvector {\n    static\
    \ constexpr uint W = 64;\n    int cnt0 = 0, size;\n    vector<ull> bv;\n    vector<int>\
    \ pre;\n\n    bitvector(uint _size) : size(_size), bv(_size / W + 1), pre(_size\
    \ / W + 1) {};\n    void set(uint i) { bv[i / W] |= 1LL << (i % W); }\n    uint\
    \ get(uint i) { return bv[i / W] >> (i % W) & 1; }\n    void build() {\n     \
    \ for(int i = 1; i < ssize(pre); i++)\n        pre[i] = pre[i - 1] + popcount(bv[i\
    \ - 1]);\n      cnt0 = rank0(size);\n    }\n    int rank1(uint i) { return pre[i\
    \ / W] + popcount(bv[i / W] & ((1LL << i) - 1)); }\n    int rank0(uint i) { return\
    \ i - rank1(i); }\n  };\n\n  vector<bitvector> level;\n  waveletMatrix(vector<T>\
    \ init) : level(mxBit + 1, bitvector(init.size())){\n    for(int bit = mxBit;\
    \ bit >= 0; bit--) {\n      for(int i = 0; i < ssize(init); i++)\n        if (init[i]\
    \ >> bit & 1)\n          level[bit].set(i);\n      level[bit].build();\n     \
    \ vector<T> tmp(ssize(init));\n      array<int, 2> ptr = {0, level[bit].cnt0};\n\
    \      for(int i = 0; i < ssize(init); i++) {\n        assert(ptr[level[bit].get(i)]\
    \ < ssize(tmp));\n        tmp[ptr[level[bit].get(i)]++] = init[i];\n      }\n\
    \      init.swap(tmp);\n    }\n  }\n\n  T kth(int l, int r, int k) {\n    T res\
    \ = 0;\n    for(int bit = mxBit; bit >= 0; bit--) {\n      if (int l0 = level[bit].rank0(l),\
    \ r0 = level[bit].rank0(r); r0 - l0 <= k) {\n        res |= T(1) << bit, k -=\
    \ r0 - l0;\n        l = level[bit].cnt0 + level[bit].rank1(l), r = level[bit].cnt0\
    \ + level[bit].rank1(r);\n      } else {\n        l = l0, r = r0;\n      }\n \
    \   }\n    return res;\n  }\n\n  int rangeLess(int l, int r, T u) {\n    if (u\
    \ >= (T(2) << mxBit)) return r - l;\n    int cnt = 0;\n    for(int bit = mxBit;\
    \ bit >= 0; bit--) {\n      if (u >> bit & 1) {\n        cnt += level[bit].rank0(r)\
    \ - level[bit].rank0(l);\n        l = level[bit].cnt0 + level[bit].rank1(l), r\
    \ = level[bit].cnt0 + level[bit].rank1(r);\n      } else {\n        l = level[bit].rank0(l),\
    \ r = level[bit].rank0(r);\n      }\n    }\n    return cnt;\n  }\n\n  int rectQuery(int\
    \ l, int r, T d, T u) {\n    return rangeLess(l, r, u) - rangeLess(l, r, d);\n\
    \  }\n};\n"
  code: "template<class T, int mxBit>\nstruct waveletMatrix {\n  using uint = uint32_t;\n\
    \  struct bitvector {\n    static constexpr uint W = 64;\n    int cnt0 = 0, size;\n\
    \    vector<ull> bv;\n    vector<int> pre;\n\n    bitvector(uint _size) : size(_size),\
    \ bv(_size / W + 1), pre(_size / W + 1) {};\n    void set(uint i) { bv[i / W]\
    \ |= 1LL << (i % W); }\n    uint get(uint i) { return bv[i / W] >> (i % W) & 1;\
    \ }\n    void build() {\n      for(int i = 1; i < ssize(pre); i++)\n        pre[i]\
    \ = pre[i - 1] + popcount(bv[i - 1]);\n      cnt0 = rank0(size);\n    }\n    int\
    \ rank1(uint i) { return pre[i / W] + popcount(bv[i / W] & ((1LL << i) - 1));\
    \ }\n    int rank0(uint i) { return i - rank1(i); }\n  };\n\n  vector<bitvector>\
    \ level;\n  waveletMatrix(vector<T> init) : level(mxBit + 1, bitvector(init.size())){\n\
    \    for(int bit = mxBit; bit >= 0; bit--) {\n      for(int i = 0; i < ssize(init);\
    \ i++)\n        if (init[i] >> bit & 1)\n          level[bit].set(i);\n      level[bit].build();\n\
    \      vector<T> tmp(ssize(init));\n      array<int, 2> ptr = {0, level[bit].cnt0};\n\
    \      for(int i = 0; i < ssize(init); i++) {\n        assert(ptr[level[bit].get(i)]\
    \ < ssize(tmp));\n        tmp[ptr[level[bit].get(i)]++] = init[i];\n      }\n\
    \      init.swap(tmp);\n    }\n  }\n\n  T kth(int l, int r, int k) {\n    T res\
    \ = 0;\n    for(int bit = mxBit; bit >= 0; bit--) {\n      if (int l0 = level[bit].rank0(l),\
    \ r0 = level[bit].rank0(r); r0 - l0 <= k) {\n        res |= T(1) << bit, k -=\
    \ r0 - l0;\n        l = level[bit].cnt0 + level[bit].rank1(l), r = level[bit].cnt0\
    \ + level[bit].rank1(r);\n      } else {\n        l = l0, r = r0;\n      }\n \
    \   }\n    return res;\n  }\n\n  int rangeLess(int l, int r, T u) {\n    if (u\
    \ >= (T(2) << mxBit)) return r - l;\n    int cnt = 0;\n    for(int bit = mxBit;\
    \ bit >= 0; bit--) {\n      if (u >> bit & 1) {\n        cnt += level[bit].rank0(r)\
    \ - level[bit].rank0(l);\n        l = level[bit].cnt0 + level[bit].rank1(l), r\
    \ = level[bit].cnt0 + level[bit].rank1(r);\n      } else {\n        l = level[bit].rank0(l),\
    \ r = level[bit].rank0(r);\n      }\n    }\n    return cnt;\n  }\n\n  int rectQuery(int\
    \ l, int r, T d, T u) {\n    return rangeLess(l, r, u) - rangeLess(l, r, d);\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/waveletMatrix.cpp
  requiredBy: []
  timestamp: '2024-02-06 18:26:29+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/range_kth_smallest.test.cpp
  - test/static_range_frequency.test.cpp
documentation_of: ds/waveletMatrix.cpp
layout: document
redirect_from:
- /library/ds/waveletMatrix.cpp
- /library/ds/waveletMatrix.cpp.html
title: ds/waveletMatrix.cpp
---
