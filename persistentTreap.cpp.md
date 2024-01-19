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
  bundledCode: "#line 1 \"persistentTreap.cpp\"\n/**\n * template name: dynamicTreap\n\
    \ */\n\nconst int TN = 5000000;\nstruct Treap {\n  static Treap mem[TN], *pmem;\n\
    \  Treap *l, *r;\n  char val;\n  int size;\n  Treap() {}\n  Treap(char _val) :\
    \ l(NULL), r(NULL), val(_val), size(1) {}\n}Treap::mem[TN], *Treap::pmem = Treap::mem;\n\
    \nint size(Treap *t) {\n  return t ? t -> size : 0;\n}\nvoid pull(Treap *t) {\n\
    \  t -> size = size(t -> l) + size(t -> r) + 1;\n}\n\nTreap* merge(Treap *a, Treap\
    \ *b) {\n  if (!a || !b) return a ? a : b;\n  Treap *t;\n  if (rng() % (a -> size\
    \ + b -> size) < a -> size) {\n    t = new (Treap::pmem++) Treap(*a);\n    t ->\
    \ r = merge(a -> r, b);\n  } else {\n    t = new (Treap::pmem++) Treap(*b);\n\
    \    t -> l = merge(a, b -> l);\n  }\n  pull(t);\n  return t;\n}\n\nvoid split(Treap\
    \ *t, int k, Treap *&a, Treap *&b) {\n  if (!t) a = b = NULL;\n  else if (size(t\
    \ -> l) + 1 <= k) {\n    a = new (Treap::pmem++) Treap(*t);\n    split(t -> r,\
    \ k - size(t -> l) - 1, a -> r, b);\n    pull(a);\n  } else {\n    b = new (Treap::pmem++)\
    \ Treap(*t);\n    split(t -> l, k, a, b -> l);\n    pull(b);\n  }\n}\n"
  code: "/**\n * template name: dynamicTreap\n */\n\nconst int TN = 5000000;\nstruct\
    \ Treap {\n  static Treap mem[TN], *pmem;\n  Treap *l, *r;\n  char val;\n  int\
    \ size;\n  Treap() {}\n  Treap(char _val) : l(NULL), r(NULL), val(_val), size(1)\
    \ {}\n}Treap::mem[TN], *Treap::pmem = Treap::mem;\n\nint size(Treap *t) {\n  return\
    \ t ? t -> size : 0;\n}\nvoid pull(Treap *t) {\n  t -> size = size(t -> l) + size(t\
    \ -> r) + 1;\n}\n\nTreap* merge(Treap *a, Treap *b) {\n  if (!a || !b) return\
    \ a ? a : b;\n  Treap *t;\n  if (rng() % (a -> size + b -> size) < a -> size)\
    \ {\n    t = new (Treap::pmem++) Treap(*a);\n    t -> r = merge(a -> r, b);\n\
    \  } else {\n    t = new (Treap::pmem++) Treap(*b);\n    t -> l = merge(a, b ->\
    \ l);\n  }\n  pull(t);\n  return t;\n}\n\nvoid split(Treap *t, int k, Treap *&a,\
    \ Treap *&b) {\n  if (!t) a = b = NULL;\n  else if (size(t -> l) + 1 <= k) {\n\
    \    a = new (Treap::pmem++) Treap(*t);\n    split(t -> r, k - size(t -> l) -\
    \ 1, a -> r, b);\n    pull(a);\n  } else {\n    b = new (Treap::pmem++) Treap(*t);\n\
    \    split(t -> l, k, a, b -> l);\n    pull(b);\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: persistentTreap.cpp
  requiredBy: []
  timestamp: '2023-06-16 02:10:58+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: persistentTreap.cpp
layout: document
redirect_from:
- /library/persistentTreap.cpp
- /library/persistentTreap.cpp.html
title: persistentTreap.cpp
---
