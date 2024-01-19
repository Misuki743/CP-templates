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
  bundledCode: "#line 1 \"ds/treap.cpp\"\n/**\n * template name: treap\n * author:\
    \ Misuki\n * last update: 2022/07/19\n * split(now, x, l, r): split treap into\
    \ first x element and last (now.sz - x) element.\n */\n\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
    mt19937 rng(clock);\n\nstruct node {\n  int pri;\n  node *l = nullptr, *r = nullptr;\n\
    \  node() : pri(rng()) {}\n  int sz = 1;\n};\n\nint size(node *now) {\n  return\
    \ now ? now -> sz : 0;\n}\nvoid update(node *now) {\n  if (!now) return;\n  now\
    \ -> sz = size(now -> l) + size(now -> r) + 1;\n}\n\nvoid push(node *now) {\n\
    \  if (!now) return;\n}\n\nvoid split(node *now, int x, node *&l, node *&r, int\
    \ add = 0) {\n  if (!now) {\n    l = r = nullptr;\n    return;\n  }\n  push(now);\n\
    \  int key = add + size(now -> l);\n  if (key < x)\n    split(now -> r, x, now\
    \ -> r, r, add + size(now -> l) + 1), l = now;\n  else\n    split(now -> l, x,\
    \ l, now -> l, add), r = now;\n  update(now);\n}\n\nnode* merge(node *l, node\
    \ *r) {\n  if (!l) return r;\n  if (!r) return l;\n\n  push(l);\n  push(r);\n\
    \  if (l -> pri < r -> pri) {\n    l -> r = merge(l -> r, r);\n    update(l);\n\
    \    return l;\n  } else {\n    r -> l = merge(l, r -> l);\n    update(r);\n \
    \   return r;\n  }\n}\n"
  code: "/**\n * template name: treap\n * author: Misuki\n * last update: 2022/07/19\n\
    \ * split(now, x, l, r): split treap into first x element and last (now.sz - x)\
    \ element.\n */\n\n#define clock chrono::steady_clock::now().time_since_epoch().count()\n\
    mt19937 rng(clock);\n\nstruct node {\n  int pri;\n  node *l = nullptr, *r = nullptr;\n\
    \  node() : pri(rng()) {}\n  int sz = 1;\n};\n\nint size(node *now) {\n  return\
    \ now ? now -> sz : 0;\n}\nvoid update(node *now) {\n  if (!now) return;\n  now\
    \ -> sz = size(now -> l) + size(now -> r) + 1;\n}\n\nvoid push(node *now) {\n\
    \  if (!now) return;\n}\n\nvoid split(node *now, int x, node *&l, node *&r, int\
    \ add = 0) {\n  if (!now) {\n    l = r = nullptr;\n    return;\n  }\n  push(now);\n\
    \  int key = add + size(now -> l);\n  if (key < x)\n    split(now -> r, x, now\
    \ -> r, r, add + size(now -> l) + 1), l = now;\n  else\n    split(now -> l, x,\
    \ l, now -> l, add), r = now;\n  update(now);\n}\n\nnode* merge(node *l, node\
    \ *r) {\n  if (!l) return r;\n  if (!r) return l;\n\n  push(l);\n  push(r);\n\
    \  if (l -> pri < r -> pri) {\n    l -> r = merge(l -> r, r);\n    update(l);\n\
    \    return l;\n  } else {\n    r -> l = merge(l, r -> l);\n    update(r);\n \
    \   return r;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/treap.cpp
  requiredBy: []
  timestamp: '2024-01-20 02:52:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/treap.cpp
layout: document
redirect_from:
- /library/ds/treap.cpp
- /library/ds/treap.cpp.html
title: ds/treap.cpp
---
