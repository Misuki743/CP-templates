---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/62393
  bundledCode: "#line 1 \"segmentTreeLazyDynamic.cpp\"\n/**\n * template name: segmentTreeLazyDynamic\n\
    \ * reference: https://codeforces.com/blog/entry/62393\n * author: Misuki\n *\
    \ last update: 2022/11/30\n */\n\nstruct custom_hash {\n    static uint64_t splitmix64(uint64_t\
    \ x) {\n        x += 0x9e3779b97f4a7c15;\n        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n        return x ^ (x >> 31);\n\
    \    }\n\n    size_t operator()(uint64_t x) const {\n        static const uint64_t\
    \ FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n   \
    \     return splitmix64(x + FIXED_RANDOM);\n    }\n};\n\nusing namespace __gnu_pbds;\n\
    \ntemplate<class T1, class T2>\nstruct segmentTree {\n  T1 NODEUNIT;\n  T2 TAGUNIT;\n\
    \  gp_hash_table<ll, T1, custom_hash> arr;\n  gp_hash_table<ll, T2, custom_hash>\
    \ tag;\n  int sz, h;\n\n  void createNode(int idx) {\n    if (arr.find(idx) ==\
    \ arr.end()) {\n      arr[idx] = NODEUNIT;\n      tag[idx] = TAGUNIT;\n    }\n\
    \  }\n\n  segmentTree(int _sz, T1 _NODEUNIT, T2 _TAGUNIT) {\n    NODEUNIT = _NODEUNIT,\
    \ TAGUNIT = _TAGUNIT;\n    sz = _sz, h = bit_width((unsigned)sz);\n  }\n\n  T1\
    \ combineNode(const T1 &l, const T1 &r) {\n    return l + r;\n  }\n\n  //b(a(T1))\n\
    \  T2 combineTag(const T2 &a, const T2 &b) {\n    if (b == TAGUNIT)\n      return\
    \ a;\n    return a + b;\n  }\n\n  T1 combineNT(const T1 &a, const T2 &b) {\n \
    \   if (b == TAGUNIT)\n      return a;\n    return a + b;\n  }\n\n  void apply(int\
    \ idx, T2 &val) {\n    createNode(idx);\n    arr[idx] = combineNT(arr[idx], val);\n\
    \    if (idx < sz)\n      tag[idx] = combineTag(tag[idx], val);\n  }\n\n  void\
    \ push(int idx) {\n    if (idx >= 2 * sz or idx < sz)\n      return;\n    for(int\
    \ i = h - 1; i > 0; i--) {\n      int pos = idx >> i;\n      createNode(pos);\n\
    \      if (!(tag[pos] == TAGUNIT)) {\n        createNode(pos<<1);\n        apply(pos<<1,\
    \ tag[pos]);\n        createNode(pos<<1|1);\n        apply(pos<<1|1, tag[pos]);\n\
    \        tag[pos] = TAGUNIT;\n      }\n    }\n  }\n\n  void pull(int idx) {\n\
    \    if (idx >= 2 * sz or idx < sz)\n      return;\n    idx >>= 1;\n    while(idx)\
    \ {\n      createNode(idx);\n      createNode(idx<<1);\n      createNode(idx<<1|1);\n\
    \      arr[idx] = combineNT(combineNode(arr[idx<<1], arr[idx<<1|1]), tag[idx]);\n\
    \      idx >>= 1;\n    }\n  }\n\n  void modify(int l, int r, T2 val) {\n    int\
    \ l0 = l + sz, r0 = r + sz - 1;\n    push(l0);\n    push(r0);\n    for(l += sz,\
    \ r += sz; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) apply(l++, val);\n   \
    \   if (r & 1) apply(--r, val);\n    }\n    pull(l0);\n    pull(r0);\n  }\n\n\
    \  T1 query(int l, int r) {\n    T1 L = NODEUNIT, R = NODEUNIT;\n    push(l +\
    \ sz);\n    push(r + sz - 1);\n    for(l += sz, r += sz; l < r; l >>= 1, r >>=\
    \ 1) {\n      if (l & 1) {\n        createNode(arr[l]);\n        L = combineNode(L,\
    \ arr[l++]);\n      }\n      if (r & 1) {\n        createNode(arr[r - 1]);\n \
    \       R = combineNode(arr[--r], R);\n      }\n    }\n    return combineNode(L,\
    \ R);\n  }\n};\n"
  code: "/**\n * template name: segmentTreeLazyDynamic\n * reference: https://codeforces.com/blog/entry/62393\n\
    \ * author: Misuki\n * last update: 2022/11/30\n */\n\nstruct custom_hash {\n\
    \    static uint64_t splitmix64(uint64_t x) {\n        x += 0x9e3779b97f4a7c15;\n\
    \        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n        x = (x ^ (x >> 27))\
    \ * 0x94d049bb133111eb;\n        return x ^ (x >> 31);\n    }\n\n    size_t operator()(uint64_t\
    \ x) const {\n        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n\
    \        return splitmix64(x + FIXED_RANDOM);\n    }\n};\n\nusing namespace __gnu_pbds;\n\
    \ntemplate<class T1, class T2>\nstruct segmentTree {\n  T1 NODEUNIT;\n  T2 TAGUNIT;\n\
    \  gp_hash_table<ll, T1, custom_hash> arr;\n  gp_hash_table<ll, T2, custom_hash>\
    \ tag;\n  int sz, h;\n\n  void createNode(int idx) {\n    if (arr.find(idx) ==\
    \ arr.end()) {\n      arr[idx] = NODEUNIT;\n      tag[idx] = TAGUNIT;\n    }\n\
    \  }\n\n  segmentTree(int _sz, T1 _NODEUNIT, T2 _TAGUNIT) {\n    NODEUNIT = _NODEUNIT,\
    \ TAGUNIT = _TAGUNIT;\n    sz = _sz, h = bit_width((unsigned)sz);\n  }\n\n  T1\
    \ combineNode(const T1 &l, const T1 &r) {\n    return l + r;\n  }\n\n  //b(a(T1))\n\
    \  T2 combineTag(const T2 &a, const T2 &b) {\n    if (b == TAGUNIT)\n      return\
    \ a;\n    return a + b;\n  }\n\n  T1 combineNT(const T1 &a, const T2 &b) {\n \
    \   if (b == TAGUNIT)\n      return a;\n    return a + b;\n  }\n\n  void apply(int\
    \ idx, T2 &val) {\n    createNode(idx);\n    arr[idx] = combineNT(arr[idx], val);\n\
    \    if (idx < sz)\n      tag[idx] = combineTag(tag[idx], val);\n  }\n\n  void\
    \ push(int idx) {\n    if (idx >= 2 * sz or idx < sz)\n      return;\n    for(int\
    \ i = h - 1; i > 0; i--) {\n      int pos = idx >> i;\n      createNode(pos);\n\
    \      if (!(tag[pos] == TAGUNIT)) {\n        createNode(pos<<1);\n        apply(pos<<1,\
    \ tag[pos]);\n        createNode(pos<<1|1);\n        apply(pos<<1|1, tag[pos]);\n\
    \        tag[pos] = TAGUNIT;\n      }\n    }\n  }\n\n  void pull(int idx) {\n\
    \    if (idx >= 2 * sz or idx < sz)\n      return;\n    idx >>= 1;\n    while(idx)\
    \ {\n      createNode(idx);\n      createNode(idx<<1);\n      createNode(idx<<1|1);\n\
    \      arr[idx] = combineNT(combineNode(arr[idx<<1], arr[idx<<1|1]), tag[idx]);\n\
    \      idx >>= 1;\n    }\n  }\n\n  void modify(int l, int r, T2 val) {\n    int\
    \ l0 = l + sz, r0 = r + sz - 1;\n    push(l0);\n    push(r0);\n    for(l += sz,\
    \ r += sz; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) apply(l++, val);\n   \
    \   if (r & 1) apply(--r, val);\n    }\n    pull(l0);\n    pull(r0);\n  }\n\n\
    \  T1 query(int l, int r) {\n    T1 L = NODEUNIT, R = NODEUNIT;\n    push(l +\
    \ sz);\n    push(r + sz - 1);\n    for(l += sz, r += sz; l < r; l >>= 1, r >>=\
    \ 1) {\n      if (l & 1) {\n        createNode(arr[l]);\n        L = combineNode(L,\
    \ arr[l++]);\n      }\n      if (r & 1) {\n        createNode(arr[r - 1]);\n \
    \       R = combineNode(arr[--r], R);\n      }\n    }\n    return combineNode(L,\
    \ R);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: segmentTreeLazyDynamic.cpp
  requiredBy: []
  timestamp: '2024-01-06 18:21:41+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segmentTreeLazyDynamic.cpp
layout: document
redirect_from:
- /library/segmentTreeLazyDynamic.cpp
- /library/segmentTreeLazyDynamic.cpp.html
title: segmentTreeLazyDynamic.cpp
---
