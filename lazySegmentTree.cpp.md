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
  bundledCode: "#line 1 \"lazySegmentTree.cpp\"\n/**\n * template name: lazySegmentTree\n\
    \ * author: Misuki\n * last update: 2024/01/01\n * verify: Library Checker - Range\
    \ Affine Point Get\n *         Library Checker - Range Affine Range Sum\n *  \
    \       Codeforces Edu Segment Tree part 2 step 3 pC - Addition and First element\
    \ at least X\n */\n\ntemplate<class M, class T, M(*Munit)(), T(*Tunit)(), M(*Mope)(const\
    \ M&, const M&), T(*Tope)(const T&, const T&), M(*comp)(const M&, const T&)>\n\
    struct lazySegmentTree {\n  vector<M> data;\n  vector<T> tag;\n  int size, h;\n\
    \n  lazySegmentTree(int _size) : data(2 * _size, Munit()), tag(_size, Tunit()),\
    \ size(_size), h(bit_width((unsigned)_size)) {}\n\n  lazySegmentTree(vector<M>\
    \ init) : data(2 * ssize(init), Munit()), tag(ssize(init), Tunit()), size(ssize(init)),\
    \ h(bit_width(init.size())) {\n    copy(init.begin(), init.end(), data.begin()\
    \ + size);\n    for(int i = size - 1; i > 0; i--)\n      data[i] = Mope(data[i\
    \ << 1], data[i << 1 | 1]);\n  }\n\n  void apply(int i, T x) {\n    data[i] =\
    \ comp(data[i], x);\n    if (i < size)\n      tag[i] = Tope(tag[i], x);\n  }\n\
    \n  void push(int i) {\n    if (i < size or i >= 2 * size) return;\n    for(int\
    \ s = h - 1; s > 0; s--) {\n      if (tag[i >> s] != Tunit()) {\n        apply(i\
    \ >> (s - 1), tag[i >> s]);\n        apply(i >> (s - 1) ^ 1, tag[i >> s]);\n \
    \       tag[i >> s] = Tunit();\n      }\n    }\n  }\n\n  void pull(int i) {\n\
    \    if (i < size or i >= 2 * size) return;\n    i >>= 1;\n    while(i) {\n  \
    \    data[i] = Mope(data[i << 1], data[i << 1 | 1]);\n      if (tag[i] != Tunit())\n\
    \        data[i] = comp(data[i], tag[i]);\n      i >>= 1;\n    }\n  }\n\n  void\
    \ set(int i, M x) {\n    push(i + size);\n    data[i + size] = x;\n    pull(i\
    \ + size);\n  }\n\n  M get(int i) {\n    push(i + size);\n    return data[i +\
    \ size];\n  }\n\n  void modify(int l, int r, T x) {\n    if (x == Tunit()) return;\n\
    \    int l0 = l + size, r0 = r + size - 1;\n    push(l0), push(r0);\n    for(l\
    \ += size, r += size; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) apply(l++,\
    \ x);\n      if (r & 1) apply(--r, x);\n    }\n    pull(l0), pull(r0);\n  }\n\n\
    \  M query(int l, int r) {\n    M L = Munit(), R = Munit();\n    push(l + size),\
    \ push(r + size - 1);\n    for(l += size, r += size; l < r; l >>= 1, r >>= 1)\
    \ {\n      if (l & 1) L = Mope(L, data[l++]);\n      if (r & 1) R = Mope(data[--r],\
    \ R);\n    }\n    return Mope(L, R);\n  }\n\n  int firstTrue(int l, int r, function<bool(const\
    \ M&)> f) {\n    vector<int> idL, idR;\n    int r0 = r;\n    push(l + size), push(r\
    \ + size - 1);\n    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {\n   \
    \   if (l & 1) idL.emplace_back(l++);\n      if (r & 1) idR.emplace_back(--r);\n\
    \    }\n    while(!idR.empty()) {\n      idL.emplace_back(idR.back());\n     \
    \ idR.pop_back();\n    }\n    M pre = Munit();\n    int v = -1;\n    for(int i\
    \ : idL) {\n      if (f(Mope(pre, data[i]))) {\n        v = i;\n        break;\n\
    \      } else {\n        pre = Mope(pre, data[i]);\n      }\n    }\n    if (v\
    \ == -1)\n      return r0;\n    while(v < size) {\n      if (tag[v] != Tunit())\
    \ {\n        apply(v << 1, tag[v]);\n        apply(v << 1 | 1, tag[v]);\n    \
    \    tag[v] = Tunit();\n      }\n      if (f(Mope(pre, data[v << 1])))\n     \
    \   v = v << 1;\n      else\n        pre = Mope(pre, data[v << 1]), v = v << 1\
    \ | 1;\n    }\n    return v - size;\n  }\n};\n"
  code: "/**\n * template name: lazySegmentTree\n * author: Misuki\n * last update:\
    \ 2024/01/01\n * verify: Library Checker - Range Affine Point Get\n *        \
    \ Library Checker - Range Affine Range Sum\n *         Codeforces Edu Segment\
    \ Tree part 2 step 3 pC - Addition and First element at least X\n */\n\ntemplate<class\
    \ M, class T, M(*Munit)(), T(*Tunit)(), M(*Mope)(const M&, const M&), T(*Tope)(const\
    \ T&, const T&), M(*comp)(const M&, const T&)>\nstruct lazySegmentTree {\n  vector<M>\
    \ data;\n  vector<T> tag;\n  int size, h;\n\n  lazySegmentTree(int _size) : data(2\
    \ * _size, Munit()), tag(_size, Tunit()), size(_size), h(bit_width((unsigned)_size))\
    \ {}\n\n  lazySegmentTree(vector<M> init) : data(2 * ssize(init), Munit()), tag(ssize(init),\
    \ Tunit()), size(ssize(init)), h(bit_width(init.size())) {\n    copy(init.begin(),\
    \ init.end(), data.begin() + size);\n    for(int i = size - 1; i > 0; i--)\n \
    \     data[i] = Mope(data[i << 1], data[i << 1 | 1]);\n  }\n\n  void apply(int\
    \ i, T x) {\n    data[i] = comp(data[i], x);\n    if (i < size)\n      tag[i]\
    \ = Tope(tag[i], x);\n  }\n\n  void push(int i) {\n    if (i < size or i >= 2\
    \ * size) return;\n    for(int s = h - 1; s > 0; s--) {\n      if (tag[i >> s]\
    \ != Tunit()) {\n        apply(i >> (s - 1), tag[i >> s]);\n        apply(i >>\
    \ (s - 1) ^ 1, tag[i >> s]);\n        tag[i >> s] = Tunit();\n      }\n    }\n\
    \  }\n\n  void pull(int i) {\n    if (i < size or i >= 2 * size) return;\n   \
    \ i >>= 1;\n    while(i) {\n      data[i] = Mope(data[i << 1], data[i << 1 | 1]);\n\
    \      if (tag[i] != Tunit())\n        data[i] = comp(data[i], tag[i]);\n    \
    \  i >>= 1;\n    }\n  }\n\n  void set(int i, M x) {\n    push(i + size);\n   \
    \ data[i + size] = x;\n    pull(i + size);\n  }\n\n  M get(int i) {\n    push(i\
    \ + size);\n    return data[i + size];\n  }\n\n  void modify(int l, int r, T x)\
    \ {\n    if (x == Tunit()) return;\n    int l0 = l + size, r0 = r + size - 1;\n\
    \    push(l0), push(r0);\n    for(l += size, r += size; l < r; l >>= 1, r >>=\
    \ 1) {\n      if (l & 1) apply(l++, x);\n      if (r & 1) apply(--r, x);\n   \
    \ }\n    pull(l0), pull(r0);\n  }\n\n  M query(int l, int r) {\n    M L = Munit(),\
    \ R = Munit();\n    push(l + size), push(r + size - 1);\n    for(l += size, r\
    \ += size; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) L = Mope(L, data[l++]);\n\
    \      if (r & 1) R = Mope(data[--r], R);\n    }\n    return Mope(L, R);\n  }\n\
    \n  int firstTrue(int l, int r, function<bool(const M&)> f) {\n    vector<int>\
    \ idL, idR;\n    int r0 = r;\n    push(l + size), push(r + size - 1);\n    for(l\
    \ += size, r += size; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) idL.emplace_back(l++);\n\
    \      if (r & 1) idR.emplace_back(--r);\n    }\n    while(!idR.empty()) {\n \
    \     idL.emplace_back(idR.back());\n      idR.pop_back();\n    }\n    M pre =\
    \ Munit();\n    int v = -1;\n    for(int i : idL) {\n      if (f(Mope(pre, data[i])))\
    \ {\n        v = i;\n        break;\n      } else {\n        pre = Mope(pre, data[i]);\n\
    \      }\n    }\n    if (v == -1)\n      return r0;\n    while(v < size) {\n \
    \     if (tag[v] != Tunit()) {\n        apply(v << 1, tag[v]);\n        apply(v\
    \ << 1 | 1, tag[v]);\n        tag[v] = Tunit();\n      }\n      if (f(Mope(pre,\
    \ data[v << 1])))\n        v = v << 1;\n      else\n        pre = Mope(pre, data[v\
    \ << 1]), v = v << 1 | 1;\n    }\n    return v - size;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lazySegmentTree.cpp
  requiredBy: []
  timestamp: '2024-01-06 18:21:41+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lazySegmentTree.cpp
layout: document
redirect_from:
- /library/lazySegmentTree.cpp
- /library/lazySegmentTree.cpp.html
title: lazySegmentTree.cpp
---
