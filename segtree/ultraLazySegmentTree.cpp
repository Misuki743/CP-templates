//#include<segtree/lazySegmentTree.cpp>

template<class AM>
struct ultraLazySegmentTree : lazySegmentTree<typename AM::M, AM::Mid, AM::Mop, typename AM::T, AM::Tid, AM::Top, AM::act> {
  using base = lazySegmentTree<typename AM::M, AM::Mid, AM::Mop, typename AM::T, AM::Tid, AM::Top, AM::act>;
  ultraLazySegmentTree(vector<typename AM::M> init) : base(init) {}
  ultraLazySegmentTree(int size) : base(size) {}
};
