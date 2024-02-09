//#include<segtree/lazySegmentTree.cpp>
//#include<segtree/ultraLazySegmentTree.cpp>
//#include<actedmonoid/actedMonoid_addMinCnt.cpp>
//#include<misc/compression.cpp>

template<class T1, class T2>
T2 areaOfUnionOfRectangles(vector<array<T1, 4>> rect) {
  compression<T1> xs(2 * ssize(rect)), ys(2 * ssize(rect));
  xs.insert(rect, [](auto &x) { return x[0]; });
  xs.insert(rect, [](auto &x) { return x[1]; });
  ys.insert(rect, [](auto &x) { return x[2]; });
  ys.insert(rect, [](auto &x) { return x[3]; });
  xs.precompute();
  ys.precompute();
  xs.mapping(rect, [](auto &x) -> T1& { return x[0]; });
  xs.mapping(rect, [](auto &x) -> T1& { return x[1]; });
  ys.mapping(rect, [](auto &x) -> T1& { return x[2]; });
  ys.mapping(rect, [](auto &x) -> T1& { return x[3]; });

  vector<tuple<T1, int, int>> add;
  add.reserve(ssize(rect));
  for(int i = 0; auto &[l, r, _, __] : rect) {
    add.emplace_back(l, 1, i);
    add.emplace_back(r, -1, i++);
  }
  R::sort(add, {}, [](auto &x) { return get<0>(x); });

  vector<pair<T1, T1>> init(ys.size() - 1);
  for(int i = 0; i + 1 < ys.size(); i++)
    init[i] = make_pair(T1(0), ys.val[i + 1] - ys.val[i]);
  ultraLazySegmentTree<actedMonoid_addMinCnt<T1>> st(init);

  T2 ans = 0;
  for(int i = 1, ptr = 0; i < xs.size(); i++) {
    while(ptr < ssize(add) and get<0>(add[ptr]) < i) {
      auto [x, r, i] = add[ptr++];
      auto [_, __, d, u] = rect[i];
      st.modify(d, u, r);
    }
    ans += T2(xs.val[i] - xs.val[i - 1]) * ((ys.val.back() - ys.val[0]) - actedMonoid_addMinCnt<T1>::Mop(st.query(0, st.size), make_pair(0, 0)).second);
  }

  return ans;
}
