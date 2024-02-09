---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dynamic_sequence_range_affine_range_sum.test.cpp
    title: test/dynamic_sequence_range_affine_range_sum.test.cpp
  - icon: ':x:'
    path: test/range_reverse_range_sum.test.cpp
    title: test/range_reverse_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/treap.cpp\"\nmt19937 rng(clock);\n\ntemplate<class M,\
    \ M(*Mid)(), M(*Mop)(const M&, const M&), class T, T(*Tid)(), T(*Top)(const T&,\
    \ const T&), M(*act)(const M&, const T&)>\nstruct treap {\n  struct node {\n \
    \   int pri, size = 1;\n    bool rev = false;\n    node *l = nullptr, *r = nullptr;\n\
    \    M data, prod;\n    T tag;\n    node() : pri(rng()), data(Mid()), prod(Mid()),\
    \ tag(Tid()) {}\n    node(M init) : pri(rng()), data(init), prod(init), tag(Tid())\
    \ {}\n  };\n\n  static int size(node *v) { return v ? v -> size : 0; }\n  static\
    \ M get(node *v) { return v ? v -> prod : Mid(); }\n\n  static node* build(vector<M>\
    \ init) {\n    node* res = nullptr;\n    for(M &x : init)\n      res = merge(res,\
    \ new node(x));\n    return res;\n  }\n\n  static void apply(node *v, T x, bool\
    \ rev) {\n    if (!v) return;\n    if (x != Tid()) {\n      v -> data = act(v\
    \ -> data, x);\n      v -> prod = act(v -> prod, x);\n      v -> tag = Top(v ->\
    \ tag, x);\n    }\n    if (rev) {\n      v -> rev ^= 1;\n      swap(v -> l, v\
    \ -> r);\n    }\n  }\n\n  static void push(node *v) {\n    if (!v) return;\n \
    \   for(node* c : {v -> l, v -> r})\n      apply(c, v -> tag, v -> rev);\n   \
    \ v -> tag = Tid(), v -> rev = false;\n  }\n\n  static void pull(node *v) {\n\
    \    if (!v) return;\n    v -> size = 1, v -> prod = v -> data;\n    if (node*\
    \ lc = v -> l; lc) {\n      v -> size += lc -> size;\n      v -> prod = Mop(lc\
    \ -> prod, v -> prod);\n    }\n    if (node* rc = v -> r; rc) {\n      v -> size\
    \ += rc -> size;\n      v -> prod = Mop(v -> prod, rc -> prod);\n    }\n  }\n\n\
    \  static void split(node *v, int x, node *&l, node *&r, int add = 0) {\n    if\
    \ (!v) {\n      l = r = nullptr;\n      return;\n    }\n    push(v);\n    if (int\
    \ key = add + size(v -> l); key < x)\n      split(v -> r, x, v -> r, r, add +\
    \ size(v -> l) + 1), l = v;\n    else\n      split(v -> l, x, l, v -> l, add),\
    \ r = v;\n    pull(v);\n  }\n\n  static node* merge(node *l, node *r) {\n    if\
    \ (!l or !r) return l ? l : r;\n    push(l), push(r);\n    if (l -> pri < r ->\
    \ pri) {\n      l -> r = merge(l -> r, r);\n      pull(l);\n      return l;\n\
    \    } else {\n      r -> l = merge(l, r -> l);\n      pull(r);\n      return\
    \ r;\n    }\n  }\n\n  static array<node*, 3> cut(node *root, int l, int r) {\n\
    \    array<node*, 3> tmp = {};\n    split(root, l, tmp[0], tmp[1]);\n    split(tmp[1],\
    \ r - l, tmp[1], tmp[2]);\n    return tmp;\n  }\n\n  static node* uncut(array<node*,\
    \ 3> roots) {\n    return merge(roots[0], merge(roots[1], roots[2]));\n  }\n\n\
    \  static void modify(node *root, int l, int r, T x, bool rev = false) {\n   \
    \ auto tmp = cut(root, l, r);\n    apply(tmp[1], x, rev);\n    uncut(tmp);\n \
    \ }\n\n  static M query(node *root, int l, int r) {\n    auto tmp = cut(root,\
    \ l, r);\n    M res = get(tmp[1]);\n    uncut(tmp);\n    return res;\n  }\n\n\
    \  static void insert(node *&root, int i, M x) {\n    array<node*, 3> tmp = {};\n\
    \    tmp[1] = new node(x);\n    split(root, i, tmp[0], tmp[2]);\n    root = uncut(tmp);\n\
    \  }\n\n  static void erase(node *&root, int i) {\n    auto tmp = cut(root, i,\
    \ i + 1);\n    delete tmp[1];\n    tmp[1] = nullptr;\n    root = uncut(tmp);\n\
    \  }\n};\n"
  code: "mt19937 rng(clock);\n\ntemplate<class M, M(*Mid)(), M(*Mop)(const M&, const\
    \ M&), class T, T(*Tid)(), T(*Top)(const T&, const T&), M(*act)(const M&, const\
    \ T&)>\nstruct treap {\n  struct node {\n    int pri, size = 1;\n    bool rev\
    \ = false;\n    node *l = nullptr, *r = nullptr;\n    M data, prod;\n    T tag;\n\
    \    node() : pri(rng()), data(Mid()), prod(Mid()), tag(Tid()) {}\n    node(M\
    \ init) : pri(rng()), data(init), prod(init), tag(Tid()) {}\n  };\n\n  static\
    \ int size(node *v) { return v ? v -> size : 0; }\n  static M get(node *v) { return\
    \ v ? v -> prod : Mid(); }\n\n  static node* build(vector<M> init) {\n    node*\
    \ res = nullptr;\n    for(M &x : init)\n      res = merge(res, new node(x));\n\
    \    return res;\n  }\n\n  static void apply(node *v, T x, bool rev) {\n    if\
    \ (!v) return;\n    if (x != Tid()) {\n      v -> data = act(v -> data, x);\n\
    \      v -> prod = act(v -> prod, x);\n      v -> tag = Top(v -> tag, x);\n  \
    \  }\n    if (rev) {\n      v -> rev ^= 1;\n      swap(v -> l, v -> r);\n    }\n\
    \  }\n\n  static void push(node *v) {\n    if (!v) return;\n    for(node* c :\
    \ {v -> l, v -> r})\n      apply(c, v -> tag, v -> rev);\n    v -> tag = Tid(),\
    \ v -> rev = false;\n  }\n\n  static void pull(node *v) {\n    if (!v) return;\n\
    \    v -> size = 1, v -> prod = v -> data;\n    if (node* lc = v -> l; lc) {\n\
    \      v -> size += lc -> size;\n      v -> prod = Mop(lc -> prod, v -> prod);\n\
    \    }\n    if (node* rc = v -> r; rc) {\n      v -> size += rc -> size;\n   \
    \   v -> prod = Mop(v -> prod, rc -> prod);\n    }\n  }\n\n  static void split(node\
    \ *v, int x, node *&l, node *&r, int add = 0) {\n    if (!v) {\n      l = r =\
    \ nullptr;\n      return;\n    }\n    push(v);\n    if (int key = add + size(v\
    \ -> l); key < x)\n      split(v -> r, x, v -> r, r, add + size(v -> l) + 1),\
    \ l = v;\n    else\n      split(v -> l, x, l, v -> l, add), r = v;\n    pull(v);\n\
    \  }\n\n  static node* merge(node *l, node *r) {\n    if (!l or !r) return l ?\
    \ l : r;\n    push(l), push(r);\n    if (l -> pri < r -> pri) {\n      l -> r\
    \ = merge(l -> r, r);\n      pull(l);\n      return l;\n    } else {\n      r\
    \ -> l = merge(l, r -> l);\n      pull(r);\n      return r;\n    }\n  }\n\n  static\
    \ array<node*, 3> cut(node *root, int l, int r) {\n    array<node*, 3> tmp = {};\n\
    \    split(root, l, tmp[0], tmp[1]);\n    split(tmp[1], r - l, tmp[1], tmp[2]);\n\
    \    return tmp;\n  }\n\n  static node* uncut(array<node*, 3> roots) {\n    return\
    \ merge(roots[0], merge(roots[1], roots[2]));\n  }\n\n  static void modify(node\
    \ *root, int l, int r, T x, bool rev = false) {\n    auto tmp = cut(root, l, r);\n\
    \    apply(tmp[1], x, rev);\n    uncut(tmp);\n  }\n\n  static M query(node *root,\
    \ int l, int r) {\n    auto tmp = cut(root, l, r);\n    M res = get(tmp[1]);\n\
    \    uncut(tmp);\n    return res;\n  }\n\n  static void insert(node *&root, int\
    \ i, M x) {\n    array<node*, 3> tmp = {};\n    tmp[1] = new node(x);\n    split(root,\
    \ i, tmp[0], tmp[2]);\n    root = uncut(tmp);\n  }\n\n  static void erase(node\
    \ *&root, int i) {\n    auto tmp = cut(root, i, i + 1);\n    delete tmp[1];\n\
    \    tmp[1] = nullptr;\n    root = uncut(tmp);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/treap.cpp
  requiredBy: []
  timestamp: '2024-02-09 22:57:04+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/range_reverse_range_sum.test.cpp
  - test/dynamic_sequence_range_affine_range_sum.test.cpp
documentation_of: ds/treap.cpp
layout: document
redirect_from:
- /library/ds/treap.cpp
- /library/ds/treap.cpp.html
title: ds/treap.cpp
---
