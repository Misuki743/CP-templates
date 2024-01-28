//#include<ds/fenwickTree2D.cpp>
//#include<misc/compression.cpp>

template<class T1, class T2>
vector<T2> pointAddRectSum(vector<tuple<T1, T1, T2>> pt, vector<array<T1, 4>> query, vector<int> updT) {
  compression<T1> xs(ssize(pt));
  xs.insert(pt, [](auto &x) { return get<0>(x); });
  xs.precompute();
  xs.mapping(pt, [](auto &x) -> T1& { return get<0>(x); });
  xs.mapping(query, [](auto &x) -> T1& { return x[0]; });
  xs.mapping(query, [](auto &x) -> T1& { return x[1]; });

  FT2<T1, T2> bit(xs.size());
  for(auto [x, y, __] : pt)
    bit.fakeUpdate(x, y);
  bit.init();

  vector<T2> ans(ssize(query));
  for(int i = 0, ptr = 0; auto [l, r, d, u] : query) {
    while(ptr < ssize(pt) and updT[ptr] <= i) {
      auto [x, y, w] = pt[ptr++];
      bit.update(x, y, w);
    }
    ans[i++] = bit.query(r, u) - bit.query(l, u) - bit.query(r, d) + bit.query(l, d);
  }
  
  return ans;
}
