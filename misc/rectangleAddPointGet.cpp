//#include<ds/fenwickTree2D.cpp>
//#include<misc/compression.cpp>

template<class T1, class T2>
vector<T2> rectAddPointGet(vector<tuple<T1, T1, T1, T1, T2>> &rect, vector<array<T1, 2>> &query, vector<int> updT) {
  compression<T1> xs(ssize(query));
  xs.insert(query, [](auto &x) { return x[0]; });
  xs.precompute();
  xs.mapping(query, [](auto &x) -> T1& { return x[0]; });
  xs.mapping(rect, [](auto &x) -> T1& { return get<0>(x); });
  xs.mapping(rect, [](auto &x) -> T1& { return get<1>(x); });

  FT2<T1, T2> bit(xs.size());
  for(auto &[l, r, d, u, w] : rect) {
    bit.fakeUpdate(l, d);
    bit.fakeUpdate(r, u);
    bit.fakeUpdate(l, u);
    bit.fakeUpdate(r, d);
  }
  bit.init();

  vector<T2> ans(ssize(query));
  for(int i = 0, ptr = 0; auto &[x, y] : query) {
    while(ptr < ssize(rect) and updT[ptr] <= i) {
      auto [l, r, d, u, w] = rect[ptr++];
      bit.update(l, d, w);
      bit.update(r, u, w);
      bit.update(l, u, -w);
      bit.update(r, d, -w);
    }
    ans[i++] = bit.query(x + 1, y + 1);
  }

  return ans;
}
