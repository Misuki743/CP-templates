//#include "segtree/lazySegmentTree.cpp"
//#include "segtree/ultraLazySegmentTree.cpp"
//#include "actedMonoid/actedMonoid_addMinCnt.cpp"

template<class coordinate_type, class answer_type>
answer_type area_of_union_of_rectangles(vector<array<coordinate_type, 4>> rect) {
  vector<coordinate_type> xs(2 * size(rect)), ys(2 * size(rect));
  for(int i = 0; auto [a, b, c, d] : rect)
    tie(xs[2 * i], ys[2 * i], xs[2 * i + 1], ys[2 * i + 1]) = make_tuple(a, b, c, d), i++;
  Unique(xs), Unique(ys);

  vector<array<int, 4>> event(2 * size(rect));
  for(int i = 0; i < ssize(rect); i++) {
    event[2 * i] = {rect[i][0], rect[i][1], rect[i][3], 1};
    event[2 * i + 1] = {rect[i][2], rect[i][1], rect[i][3], -1};
  }
  ranges::sort(event, {}, [](auto &x) { return x[0]; });

  using AM = actedMonoid_addMinCnt<coordinate_type>;
  ultraLazySegmentTree<AM> st([&]() {
    vector<typename AM::M> init(ssize(ys) - 1);
    for(int i = 0; i + 1 < ssize(ys); i++)
      init[i] = make_pair(0, ys[i + 1] - ys[i]);
    return init;
  }());

  auto to_id = [&](int y) { return ranges::lower_bound(ys, y) - ys.begin(); };

  answer_type ans = 0;
  for(int i = 0, j = 0; ; i = j) {
    while(j < ssize(event) and event[i][0] == event[j][0]) j++;
    if (j == ssize(event)) break;
    for(int k = i; k < j; k++) {
      auto [_, l, r, d] = event[k];
      st.modify(to_id(l), to_id(r), d);
    }
    auto [mn, cnt] = st.query(0, st.size);
    answer_type w = event[j][0] - event[i][0];
    ans += (ys.back() - ys[0] - (mn == 0 ? cnt : 0)) * w;
  }

  return ans;
}
