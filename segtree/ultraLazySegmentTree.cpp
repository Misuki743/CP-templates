//#include<segtree/lazySegmentTree.cpp>

namespace ultraLazySegmentTree {
  template<class T> T mn(const T &a, const T &b) { return min(a, b); }
  template<class T> T mx(const T &a, const T &b) { return max(a, b); }
  template<class T> T add(const T &a, const T &b) { return a + b; }
  template<class T> T upd(const T&, const T &b) { return b; }
  template<class T> T zero() { return T(0); }
  template<class T, T x> T val() { return x; }

  template<class M, M inf>
  struct addMinLazySegmentTree : lazySegmentTree<M, M, val<M, inf>, zero, mn<M>, add<M>, add<M>> {
    addMinLazySegmentTree(vector<M> init) : lazySegmentTree<M, M, val<M, inf>, zero, mn<M>, add<M>, add<M>>(init) {}
  };
  template<class M, M ninf>
  struct addMaxLazySegmentTree : lazySegmentTree<M, M, val<M, ninf>, zero, mx<M>, add<M>, add<M>> {
    addMaxLazySegmentTree(vector<M> init) : lazySegmentTree<M, M, val<M, ninf>, zero, mx<M>, add<M>, add<M>>(init) {}
  };
  template<class M, M inf>
  struct setMinLazySegmentTree : lazySegmentTree<M, M, val<M, inf>, val<M, inf>, mn<M>, upd<M>, upd<M>> {
    setMinLazySegmentTree(vector<M> init) : lazySegmentTree<M, M, val<M, inf>, val<M, inf>, mn<M>, upd<M>, upd<M>>(init) {}
  };
  template<class M, M ninf>
  struct setMaxLazySegmentTree : lazySegmentTree<M, M, val<M, ninf>, val<M, ninf>, mx<M>, upd<M>, upd<M>> {
    setMaxLazySegmentTree(vector<M> init) : lazySegmentTree<M, M, val<M, ninf>, val<M, ninf>, mx<M>, upd<M>, upd<M>>(init) {}
  };

  template<class T> pair<T, T> prAdd(const pair<T, T> &a, const pair<T, T> &b) { return make_pair(a.first + b.first, a.second + b.second); }
  template<class T> pair<T, T> prAddFirst(const pair<T, T> &a, const T &b) { return make_pair(a.first + b, a.second); }
  template<class T> pair<T, T> prMinSum(const pair<T, T> &a, const pair<T, T> &b) { return a.first != b.first ? mn(a, b) : make_pair(a.first, a.second + b.second); }
  template<class T> pair<T, T> addSumComp(const pair<T, T> &a, const T &b) { return make_pair(a.first + a.second * b, a.second); }
  template<class T> pair<T, T> setSumComp(const pair<T, T> &a, const T &b) { return make_pair(a.second * b, a.second); }
  template<class T> pair<T, T> prZero() { return make_pair(T(0), T(0)); }
  template<class T, T x, T y> pair<T, T> prVal() { return make_pair(x, y); }
  template<class T> vector<pair<T, T>> extend(vector<T> a) {
    vector<pair<T, T>> b(ssize(a));
    for(int i = 0; i < ssize(a); i++)
      b[i] = make_pair(a[i], T(1));
    return b;
  }

  template<class M>
  struct addSumLazySegmentTree : lazySegmentTree<pair<M, M>, M, prZero<M>, zero<M>, prAdd<M>, add<M>, addSumComp<M>> {
    addSumLazySegmentTree(vector<M> init) : lazySegmentTree<pair<M, M>, M, prZero<M>, zero<M>, prAdd<M>, add<M>, addSumComp<M>>(extend<M>(init)) {}
  };
  template<class M, M unuse>
  struct setSumLazySegmentTree : lazySegmentTree<pair<M, M>, M, prZero<M>, val<M, unuse>, prAdd<M>, upd<M>, setSumComp<M>> {
    setSumLazySegmentTree(vector<M> init) : lazySegmentTree<pair<M, M>, M, prZero<M>, val<M, unuse>, prAdd<M>, upd<M>, setSumComp<M>>(extend<M>(init)) {}
  };
  template<class M, M inf>
  struct addMinCntLazySegmentTree : lazySegmentTree<pair<M, M>, M, prVal<M, inf, M(0)>, zero<M>, prMinSum<M>, add<M>, prAddFirst<M>> {
    using base = lazySegmentTree<pair<M, M>, M, prVal<M, inf, M(0)>, zero<M>, prMinSum<M>, add<M>, prAddFirst<M>>;
    addMinCntLazySegmentTree(vector<M> init) : base(extend<M>(init)) {}
    addMinCntLazySegmentTree(vector<pair<M, M>> init) : base(init) {}
  };
}

using namespace ultraLazySegmentTree;
