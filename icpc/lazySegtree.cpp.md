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
  bundledCode: "#line 1 \"icpc/lazySegtree.cpp\"\n/**\n * Author: Misuki\n * Date:\
    \ 2024/01/01\n * Description: 0-indexed, range update, range query segment tree.\n\
    \ * Usage:\n *\\ M/T: type of monoid/tag\n *\tMope(M, M): return result of combining\
    \ two monoid\n *\tTope(T f, T g): return result of g(f)\n *\tcomp(M, T): return\
    \ result of T(M)\n *\tmodify(l, r, x): add tag to [l, r)\n *\tquery(l, r): query\
    \ result of [l, r)\n *\n * Status: tested on library checker - range affine range\
    \ sum\n */\n\ntemplate<class M, M(*Mid)(), M(*Mop)(const M&, const M&),\nclass\
    \ T, T(*Tid)(), T(*Top)(const T&, const T&),\nM(*act)(const M&, const T&)>\nstruct\
    \ lazySegmentTree {\n\tint size;\n\tvector<M> data;\n\tvector<T> tag;\n\n\tlazySegmentTree(int\
    \ _size) : size(_size),\n\tdata(2 * size, Mid()), tag(size, Tid()) {}\n\n\tlazySegmentTree(vector<M>\
    \ init) : size(ssize(init)),\n\tdata(2 * size, Mid()), tag(size, Tid()) {\n\t\t\
    ranges::copy(init, data.begin() + size);\n\t\tfor(int i = size - 1; i > 0; i--)\n\
    \t\t\tdata[i] = Mop(data[i << 1], data[i << 1 | 1]);\n\t}\n\n\tvoid apply(int\
    \ i, T x) {\n\t\tdata[i] = act(data[i], x);\n\t\tif (i < size) tag[i] = Top(tag[i],\
    \ x);\n\t}\n\n\tvoid push(unsigned i) {\n\t\tfor(int s = (int)bit_width(i) - 1;\
    \ s > 0; s--) {\n\t\t\tif (tag[i >> s] != Tid()) {\n\t\t\t\tapply(i >> (s - 1),\
    \ tag[i >> s]);\n\t\t\t\tapply(i >> (s - 1) ^ 1, tag[i >> s]);\n\t\t\t\ttag[i\
    \ >> s] = Tid();\n\t\t\t}\n\t\t}\n\t}\n\n\tvoid pull(int i) {\n\t\twhile(i >>=\
    \ 1) \n\t\t\tdata[i] = Mop(data[i << 1], data[i << 1 | 1]);\n\t}\n\n\tint trunc(unsigned\
    \ i) { return i >> countr_zero(i); }\n\n\tvoid set(int i, M x) {\n\t\tpush(i +=\
    \ size);\n\t\tdata[i] = x;\n\t\tpull(i);\n\t}\n\n\tM get(int i) { push(i += size);\
    \ return data[i]; }\n\n\tvoid modify(int l, int r, T x) {\n\t\tif (l >= r or x\
    \ == Tid()) return;\n\t\tpush(trunc(l += size)), push(trunc(r += size) - 1);\n\
    \t\tint l0 = l, r0 = r;\n\t\tfor(; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1)\
    \ apply(l++, x);\n\t\t\tif (r & 1) apply(--r, x);\n\t\t}\n\t\tpull(trunc(l0)),\
    \ pull(trunc(r0) - 1);\n\t}\n\n\tM query(int l, int r) {\n\t\tif (l >= r) return\
    \ Mid();\n\t\tM L = Mid(), R = Mid();\n\t\tpush(trunc(l += size)), push(trunc(r\
    \ += size) - 1);\n\t\tfor(; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) L = Mop(L,\
    \ data[l++]);\n\t\t\tif (r & 1) R = Mop(data[--r], R);\n\t\t}\n\t\treturn Mop(L,\
    \ R);\n\t}\n};\n"
  code: "/**\n * Author: Misuki\n * Date: 2024/01/01\n * Description: 0-indexed, range\
    \ update, range query segment tree.\n * Usage:\n *\\ M/T: type of monoid/tag\n\
    \ *\tMope(M, M): return result of combining two monoid\n *\tTope(T f, T g): return\
    \ result of g(f)\n *\tcomp(M, T): return result of T(M)\n *\tmodify(l, r, x):\
    \ add tag to [l, r)\n *\tquery(l, r): query result of [l, r)\n *\n * Status: tested\
    \ on library checker - range affine range sum\n */\n\ntemplate<class M, M(*Mid)(),\
    \ M(*Mop)(const M&, const M&),\nclass T, T(*Tid)(), T(*Top)(const T&, const T&),\n\
    M(*act)(const M&, const T&)>\nstruct lazySegmentTree {\n\tint size;\n\tvector<M>\
    \ data;\n\tvector<T> tag;\n\n\tlazySegmentTree(int _size) : size(_size),\n\tdata(2\
    \ * size, Mid()), tag(size, Tid()) {}\n\n\tlazySegmentTree(vector<M> init) : size(ssize(init)),\n\
    \tdata(2 * size, Mid()), tag(size, Tid()) {\n\t\tranges::copy(init, data.begin()\
    \ + size);\n\t\tfor(int i = size - 1; i > 0; i--)\n\t\t\tdata[i] = Mop(data[i\
    \ << 1], data[i << 1 | 1]);\n\t}\n\n\tvoid apply(int i, T x) {\n\t\tdata[i] =\
    \ act(data[i], x);\n\t\tif (i < size) tag[i] = Top(tag[i], x);\n\t}\n\n\tvoid\
    \ push(unsigned i) {\n\t\tfor(int s = (int)bit_width(i) - 1; s > 0; s--) {\n\t\
    \t\tif (tag[i >> s] != Tid()) {\n\t\t\t\tapply(i >> (s - 1), tag[i >> s]);\n\t\
    \t\t\tapply(i >> (s - 1) ^ 1, tag[i >> s]);\n\t\t\t\ttag[i >> s] = Tid();\n\t\t\
    \t}\n\t\t}\n\t}\n\n\tvoid pull(int i) {\n\t\twhile(i >>= 1) \n\t\t\tdata[i] =\
    \ Mop(data[i << 1], data[i << 1 | 1]);\n\t}\n\n\tint trunc(unsigned i) { return\
    \ i >> countr_zero(i); }\n\n\tvoid set(int i, M x) {\n\t\tpush(i += size);\n\t\
    \tdata[i] = x;\n\t\tpull(i);\n\t}\n\n\tM get(int i) { push(i += size); return\
    \ data[i]; }\n\n\tvoid modify(int l, int r, T x) {\n\t\tif (l >= r or x == Tid())\
    \ return;\n\t\tpush(trunc(l += size)), push(trunc(r += size) - 1);\n\t\tint l0\
    \ = l, r0 = r;\n\t\tfor(; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) apply(l++,\
    \ x);\n\t\t\tif (r & 1) apply(--r, x);\n\t\t}\n\t\tpull(trunc(l0)), pull(trunc(r0)\
    \ - 1);\n\t}\n\n\tM query(int l, int r) {\n\t\tif (l >= r) return Mid();\n\t\t\
    M L = Mid(), R = Mid();\n\t\tpush(trunc(l += size)), push(trunc(r += size) - 1);\n\
    \t\tfor(; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) L = Mop(L, data[l++]);\n\
    \t\t\tif (r & 1) R = Mop(data[--r], R);\n\t\t}\n\t\treturn Mop(L, R);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: icpc/lazySegtree.cpp
  requiredBy: []
  timestamp: '2025-03-16 13:02:37+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc/lazySegtree.cpp
layout: document
redirect_from:
- /library/icpc/lazySegtree.cpp
- /library/icpc/lazySegtree.cpp.html
title: icpc/lazySegtree.cpp
---
