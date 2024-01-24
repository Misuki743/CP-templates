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
  bundledCode: "#line 1 \"segtree/ultraLazySegmentTree.cpp\"\n//#include<segtree/lazySegmentTree.cpp>\n\
    \nnamespace ultraLazySegmentTree {\n  template<class T> T mn(const T &a, const\
    \ T &b) { return min(a, b); }\n  template<class T> T mx(const T &a, const T &b)\
    \ { return max(a, b); }\n  template<class T> T add(const T &a, const T &b) { return\
    \ a + b; }\n  template<class T> T upd(const T&, const T &b) { return b; }\n  template<class\
    \ T> T zero() { return T(0); }\n  template<class T, T x> T val() { return x; }\n\
    \n  template<class M, M inf>\n  struct addMinLazySegmentTree : lazySegmentTree<M,\
    \ M, val<M, inf>, zero, mn<M>, add<M>, add<M>> {\n    addMinLazySegmentTree(vector<M>\
    \ init) : lazySegmentTree<M, M, val<M, inf>, zero, mn<M>, add<M>, add<M>>(init)\
    \ {}\n  };\n  template<class M, M ninf>\n  struct addMaxLazySegmentTree : lazySegmentTree<M,\
    \ M, val<M, ninf>, zero, mx<M>, add<M>, add<M>> {\n    addMaxLazySegmentTree(vector<M>\
    \ init) : lazySegmentTree<M, M, val<M, ninf>, zero, mx<M>, add<M>, add<M>>(init)\
    \ {}\n  };\n  template<class M, M inf>\n  struct setMinLazySegmentTree : lazySegmentTree<M,\
    \ M, val<M, inf>, val<M, inf>, mn<M>, upd<M>, upd<M>> {\n    setMinLazySegmentTree(vector<M>\
    \ init) : lazySegmentTree<M, M, val<M, inf>, val<M, inf>, mn<M>, upd<M>, upd<M>>(init)\
    \ {}\n  };\n  template<class M, M ninf>\n  struct setMaxLazySegmentTree : lazySegmentTree<M,\
    \ M, val<M, ninf>, val<M, ninf>, mx<M>, upd<M>, upd<M>> {\n    setMaxLazySegmentTree(vector<M>\
    \ init) : lazySegmentTree<M, M, val<M, ninf>, val<M, ninf>, mx<M>, upd<M>, upd<M>>(init)\
    \ {}\n  };\n\n  template<class T> pair<T, T> prAdd(const pair<T, T> &a, const\
    \ pair<T, T> &b) { return make_pair(a.first + b.first, a.second + b.second); }\n\
    \  template<class T> pair<T, T> prAddFirst(const pair<T, T> &a, const T &b) {\
    \ return make_pair(a.first + b, a.second); }\n  template<class T> pair<T, T> prMinSum(const\
    \ pair<T, T> &a, const pair<T, T> &b) { return a.first != b.first ? mn(a, b) :\
    \ make_pair(a.first, a.second + b.second); }\n  template<class T> pair<T, T> addSumComp(const\
    \ pair<T, T> &a, const T &b) { return make_pair(a.first + a.second * b, a.second);\
    \ }\n  template<class T> pair<T, T> setSumComp(const pair<T, T> &a, const T &b)\
    \ { return make_pair(a.second * b, a.second); }\n  template<class T> pair<T, T>\
    \ prZero() { return make_pair(T(0), T(0)); }\n  template<class T, T x, T y> pair<T,\
    \ T> prVal() { return make_pair(x, y); }\n  template<class T> vector<pair<T, T>>\
    \ extend(vector<T> a) {\n    vector<pair<T, T>> b(ssize(a));\n    for(int i =\
    \ 0; i < ssize(a); i++)\n      b[i] = make_pair(a[i], T(1));\n    return b;\n\
    \  }\n\n  template<class M>\n  struct addSumLazySegmentTree : lazySegmentTree<pair<M,\
    \ M>, M, prZero<M>, zero<M>, prAdd<M>, add<M>, addSumComp<M>> {\n    addSumLazySegmentTree(vector<M>\
    \ init) : lazySegmentTree<pair<M, M>, M, prZero<M>, zero<M>, prAdd<M>, add<M>,\
    \ addSumComp<M>>(extend<M>(init)) {}\n  };\n  template<class M, M unuse>\n  struct\
    \ setSumLazySegmentTree : lazySegmentTree<pair<M, M>, M, prZero<M>, val<M, unuse>,\
    \ prAdd<M>, upd<M>, setSumComp<M>> {\n    setSumLazySegmentTree(vector<M> init)\
    \ : lazySegmentTree<pair<M, M>, M, prZero<M>, val<M, unuse>, prAdd<M>, upd<M>,\
    \ setSumComp<M>>(extend<M>(init)) {}\n  };\n  template<class M, M inf>\n  struct\
    \ addMinCntLazySegmentTree : lazySegmentTree<pair<M, M>, M, prVal<M, inf, M(0)>,\
    \ zero<M>, prMinSum<M>, add<M>, prAddFirst<M>> {\n    using base = lazySegmentTree<pair<M,\
    \ M>, M, prVal<M, inf, M(0)>, zero<M>, prMinSum<M>, add<M>, prAddFirst<M>>;\n\
    \    addMinCntLazySegmentTree(vector<M> init) : base(extend<M>(init)) {}\n   \
    \ addMinCntLazySegmentTree(vector<pair<M, M>> init) : base(init) {}\n  };\n}\n\
    \nusing namespace ultraLazySegmentTree;\n"
  code: "//#include<segtree/lazySegmentTree.cpp>\n\nnamespace ultraLazySegmentTree\
    \ {\n  template<class T> T mn(const T &a, const T &b) { return min(a, b); }\n\
    \  template<class T> T mx(const T &a, const T &b) { return max(a, b); }\n  template<class\
    \ T> T add(const T &a, const T &b) { return a + b; }\n  template<class T> T upd(const\
    \ T&, const T &b) { return b; }\n  template<class T> T zero() { return T(0); }\n\
    \  template<class T, T x> T val() { return x; }\n\n  template<class M, M inf>\n\
    \  struct addMinLazySegmentTree : lazySegmentTree<M, M, val<M, inf>, zero, mn<M>,\
    \ add<M>, add<M>> {\n    addMinLazySegmentTree(vector<M> init) : lazySegmentTree<M,\
    \ M, val<M, inf>, zero, mn<M>, add<M>, add<M>>(init) {}\n  };\n  template<class\
    \ M, M ninf>\n  struct addMaxLazySegmentTree : lazySegmentTree<M, M, val<M, ninf>,\
    \ zero, mx<M>, add<M>, add<M>> {\n    addMaxLazySegmentTree(vector<M> init) :\
    \ lazySegmentTree<M, M, val<M, ninf>, zero, mx<M>, add<M>, add<M>>(init) {}\n\
    \  };\n  template<class M, M inf>\n  struct setMinLazySegmentTree : lazySegmentTree<M,\
    \ M, val<M, inf>, val<M, inf>, mn<M>, upd<M>, upd<M>> {\n    setMinLazySegmentTree(vector<M>\
    \ init) : lazySegmentTree<M, M, val<M, inf>, val<M, inf>, mn<M>, upd<M>, upd<M>>(init)\
    \ {}\n  };\n  template<class M, M ninf>\n  struct setMaxLazySegmentTree : lazySegmentTree<M,\
    \ M, val<M, ninf>, val<M, ninf>, mx<M>, upd<M>, upd<M>> {\n    setMaxLazySegmentTree(vector<M>\
    \ init) : lazySegmentTree<M, M, val<M, ninf>, val<M, ninf>, mx<M>, upd<M>, upd<M>>(init)\
    \ {}\n  };\n\n  template<class T> pair<T, T> prAdd(const pair<T, T> &a, const\
    \ pair<T, T> &b) { return make_pair(a.first + b.first, a.second + b.second); }\n\
    \  template<class T> pair<T, T> prAddFirst(const pair<T, T> &a, const T &b) {\
    \ return make_pair(a.first + b, a.second); }\n  template<class T> pair<T, T> prMinSum(const\
    \ pair<T, T> &a, const pair<T, T> &b) { return a.first != b.first ? mn(a, b) :\
    \ make_pair(a.first, a.second + b.second); }\n  template<class T> pair<T, T> addSumComp(const\
    \ pair<T, T> &a, const T &b) { return make_pair(a.first + a.second * b, a.second);\
    \ }\n  template<class T> pair<T, T> setSumComp(const pair<T, T> &a, const T &b)\
    \ { return make_pair(a.second * b, a.second); }\n  template<class T> pair<T, T>\
    \ prZero() { return make_pair(T(0), T(0)); }\n  template<class T, T x, T y> pair<T,\
    \ T> prVal() { return make_pair(x, y); }\n  template<class T> vector<pair<T, T>>\
    \ extend(vector<T> a) {\n    vector<pair<T, T>> b(ssize(a));\n    for(int i =\
    \ 0; i < ssize(a); i++)\n      b[i] = make_pair(a[i], T(1));\n    return b;\n\
    \  }\n\n  template<class M>\n  struct addSumLazySegmentTree : lazySegmentTree<pair<M,\
    \ M>, M, prZero<M>, zero<M>, prAdd<M>, add<M>, addSumComp<M>> {\n    addSumLazySegmentTree(vector<M>\
    \ init) : lazySegmentTree<pair<M, M>, M, prZero<M>, zero<M>, prAdd<M>, add<M>,\
    \ addSumComp<M>>(extend<M>(init)) {}\n  };\n  template<class M, M unuse>\n  struct\
    \ setSumLazySegmentTree : lazySegmentTree<pair<M, M>, M, prZero<M>, val<M, unuse>,\
    \ prAdd<M>, upd<M>, setSumComp<M>> {\n    setSumLazySegmentTree(vector<M> init)\
    \ : lazySegmentTree<pair<M, M>, M, prZero<M>, val<M, unuse>, prAdd<M>, upd<M>,\
    \ setSumComp<M>>(extend<M>(init)) {}\n  };\n  template<class M, M inf>\n  struct\
    \ addMinCntLazySegmentTree : lazySegmentTree<pair<M, M>, M, prVal<M, inf, M(0)>,\
    \ zero<M>, prMinSum<M>, add<M>, prAddFirst<M>> {\n    using base = lazySegmentTree<pair<M,\
    \ M>, M, prVal<M, inf, M(0)>, zero<M>, prMinSum<M>, add<M>, prAddFirst<M>>;\n\
    \    addMinCntLazySegmentTree(vector<M> init) : base(extend<M>(init)) {}\n   \
    \ addMinCntLazySegmentTree(vector<pair<M, M>> init) : base(init) {}\n  };\n}\n\
    \nusing namespace ultraLazySegmentTree;\n"
  dependsOn: []
  isVerificationFile: false
  path: segtree/ultraLazySegmentTree.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segtree/ultraLazySegmentTree.cpp
layout: document
redirect_from:
- /library/segtree/ultraLazySegmentTree.cpp
- /library/segtree/ultraLazySegmentTree.cpp.html
title: segtree/ultraLazySegmentTree.cpp
---
