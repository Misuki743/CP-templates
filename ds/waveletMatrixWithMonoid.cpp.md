---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/waveletMatrixWithMonoid.cpp\"\ntemplate<class T, int\
    \ mxBit, class M, M(*id)(), M(*op)(const M&, const M&), M(*inv)(const M&)>\nstruct\
    \ waveletMatrix {\n  using uint = uint32_t;\n  struct bitvector {\n    static\
    \ constexpr uint W = 64;\n    int cnt0 = 0, size;\n    vector<ull> bv;\n    vector<int>\
    \ pre;\n\n    bitvector(uint _size) : size(_size), bv(_size / W + 1), pre(_size\
    \ / W + 1) {};\n    void set(uint i) { bv[i / W] |= 1LL << (i % W); }\n    uint\
    \ get(uint i) { return bv[i / W] >> (i % W) & 1; }\n    void build() {\n     \
    \ for(int i = 1; i < ssize(pre); i++)\n        pre[i] = pre[i - 1] + popcount(bv[i\
    \ - 1]);\n      cnt0 = rank0(size);\n    }\n    int rank1(uint i) { return pre[i\
    \ / W] + popcount(bv[i / W] & ((1LL << i) - 1)); }\n    int rank0(uint i) { return\
    \ i - rank1(i); }\n  };\n\n  vector<bitvector> level;\n  vector<vector<M>> data;\n\
    \  waveletMatrix(vector<T> valInit, vector<M> mInit) : level(mxBit + 1, bitvector(valInit.size())),\
    \ data(mxBit + 1, vector(mInit.size() + 1, id())) {\n    for(int bit = mxBit;\
    \ bit >= 0; bit--) {\n      for(int i = 0; i < ssize(valInit); i++) {\n      \
    \  if (valInit[i] >> bit & 1)\n          level[bit].set(i);\n        else\n  \
    \        data[bit][i + 1] = mInit[i];\n      }\n      level[bit].build();\n  \
    \    for(int i = 1; i < ssize(data[bit]); i++)\n        data[bit][i] = op(data[bit][i\
    \ - 1], data[bit][i]);\n      vector<T> tmp(ssize(valInit));\n      vector<M>\
    \ tmp2(ssize(mInit));\n      array<int, 2> ptr = {0, level[bit].cnt0};\n     \
    \ for(int i = 0; i < ssize(valInit); i++) {\n        assert(ptr[level[bit].get(i)]\
    \ < ssize(tmp));\n        tmp[ptr[level[bit].get(i)]] = valInit[i];\n        tmp2[ptr[level[bit].get(i)]++]\
    \ = mInit[i];\n      }\n      valInit.swap(tmp);\n      mInit.swap(tmp2);\n  \
    \  }\n  }\n\n  T kth(int l, int r, int k) {\n    T res = 0;\n    for(int bit =\
    \ mxBit; bit >= 0; bit--) {\n      if (int l0 = level[bit].rank0(l), r0 = level[bit].rank0(r);\
    \ r0 - l0 <= k) {\n        res |= T(1) << bit, k -= r0 - l0;\n        l = level[bit].cnt0\
    \ + level[bit].rank1(l), r = level[bit].cnt0 + level[bit].rank1(r);\n      } else\
    \ {\n        l = l0, r = r0;\n      }\n    }\n    return res;\n  }\n\n  pair<int,\
    \ M> rangeLess(int l, int r, T u) {\n    if (u >= (T(2) << mxBit)) u = (2 << mxBit)\
    \ - 1;\n    int cnt = 0;\n    M res = id();\n    for(int bit = mxBit; bit >= 0;\
    \ bit--) {\n      if (u >> bit & 1) {\n        cnt += level[bit].rank0(r) - level[bit].rank0(l);\n\
    \        res = op(res, op(data[bit][r], inv(data[bit][l])));\n        l = level[bit].cnt0\
    \ + level[bit].rank1(l), r = level[bit].cnt0 + level[bit].rank1(r);\n      } else\
    \ {\n        l = level[bit].rank0(l), r = level[bit].rank0(r);\n      }\n    }\n\
    \    return make_pair(cnt, res);\n  }\n\n  pair<int, M> rectQuery(int l, int r,\
    \ T d, T u) {\n    auto [cnt1, res1] = rangeLess(l, r, u);\n    auto [cnt2, res2]\
    \ = rangeLess(l, r, d);\n    return make_pair(cnt1 - cnt2, op(res1, inv(res2)));\n\
    \  }\n};\n"
  code: "template<class T, int mxBit, class M, M(*id)(), M(*op)(const M&, const M&),\
    \ M(*inv)(const M&)>\nstruct waveletMatrix {\n  using uint = uint32_t;\n  struct\
    \ bitvector {\n    static constexpr uint W = 64;\n    int cnt0 = 0, size;\n  \
    \  vector<ull> bv;\n    vector<int> pre;\n\n    bitvector(uint _size) : size(_size),\
    \ bv(_size / W + 1), pre(_size / W + 1) {};\n    void set(uint i) { bv[i / W]\
    \ |= 1LL << (i % W); }\n    uint get(uint i) { return bv[i / W] >> (i % W) & 1;\
    \ }\n    void build() {\n      for(int i = 1; i < ssize(pre); i++)\n        pre[i]\
    \ = pre[i - 1] + popcount(bv[i - 1]);\n      cnt0 = rank0(size);\n    }\n    int\
    \ rank1(uint i) { return pre[i / W] + popcount(bv[i / W] & ((1LL << i) - 1));\
    \ }\n    int rank0(uint i) { return i - rank1(i); }\n  };\n\n  vector<bitvector>\
    \ level;\n  vector<vector<M>> data;\n  waveletMatrix(vector<T> valInit, vector<M>\
    \ mInit) : level(mxBit + 1, bitvector(valInit.size())), data(mxBit + 1, vector(mInit.size()\
    \ + 1, id())) {\n    for(int bit = mxBit; bit >= 0; bit--) {\n      for(int i\
    \ = 0; i < ssize(valInit); i++) {\n        if (valInit[i] >> bit & 1)\n      \
    \    level[bit].set(i);\n        else\n          data[bit][i + 1] = mInit[i];\n\
    \      }\n      level[bit].build();\n      for(int i = 1; i < ssize(data[bit]);\
    \ i++)\n        data[bit][i] = op(data[bit][i - 1], data[bit][i]);\n      vector<T>\
    \ tmp(ssize(valInit));\n      vector<M> tmp2(ssize(mInit));\n      array<int,\
    \ 2> ptr = {0, level[bit].cnt0};\n      for(int i = 0; i < ssize(valInit); i++)\
    \ {\n        assert(ptr[level[bit].get(i)] < ssize(tmp));\n        tmp[ptr[level[bit].get(i)]]\
    \ = valInit[i];\n        tmp2[ptr[level[bit].get(i)]++] = mInit[i];\n      }\n\
    \      valInit.swap(tmp);\n      mInit.swap(tmp2);\n    }\n  }\n\n  T kth(int\
    \ l, int r, int k) {\n    T res = 0;\n    for(int bit = mxBit; bit >= 0; bit--)\
    \ {\n      if (int l0 = level[bit].rank0(l), r0 = level[bit].rank0(r); r0 - l0\
    \ <= k) {\n        res |= T(1) << bit, k -= r0 - l0;\n        l = level[bit].cnt0\
    \ + level[bit].rank1(l), r = level[bit].cnt0 + level[bit].rank1(r);\n      } else\
    \ {\n        l = l0, r = r0;\n      }\n    }\n    return res;\n  }\n\n  pair<int,\
    \ M> rangeLess(int l, int r, T u) {\n    if (u >= (T(2) << mxBit)) u = (2 << mxBit)\
    \ - 1;\n    int cnt = 0;\n    M res = id();\n    for(int bit = mxBit; bit >= 0;\
    \ bit--) {\n      if (u >> bit & 1) {\n        cnt += level[bit].rank0(r) - level[bit].rank0(l);\n\
    \        res = op(res, op(data[bit][r], inv(data[bit][l])));\n        l = level[bit].cnt0\
    \ + level[bit].rank1(l), r = level[bit].cnt0 + level[bit].rank1(r);\n      } else\
    \ {\n        l = level[bit].rank0(l), r = level[bit].rank0(r);\n      }\n    }\n\
    \    return make_pair(cnt, res);\n  }\n\n  pair<int, M> rectQuery(int l, int r,\
    \ T d, T u) {\n    auto [cnt1, res1] = rangeLess(l, r, u);\n    auto [cnt2, res2]\
    \ = rangeLess(l, r, d);\n    return make_pair(cnt1 - cnt2, op(res1, inv(res2)));\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/waveletMatrixWithMonoid.cpp
  requiredBy: []
  timestamp: '2024-02-10 14:50:46+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/waveletMatrixWithMonoid.cpp
layout: document
redirect_from:
- /library/ds/waveletMatrixWithMonoid.cpp
- /library/ds/waveletMatrixWithMonoid.cpp.html
title: ds/waveletMatrixWithMonoid.cpp
---