//#include<ds/fenwickTree.cpp>
//#include<misc/compression.cpp>

template<class T1, class T2>
vector<T2> rectangleSum(vector<tuple<T1, T1, T2>> pt, vector<array<T1, 4>> query) {
  compression<T1> ys(ssize(pt));
  ys.insert(pt, [](auto &x) { return get<1>(x); });
  ys.precompute();
  ys.mapping(pt, [](auto &x) -> T1& { return get<1>(x); });
  ys.mapping(query, [](auto &x) -> T1& { return x[2]; });
  ys.mapping(query, [](auto &x) -> T1& { return x[3]; });

  R::sort(pt, less<T1>{}, [](auto x) { return get<0>(x); });

  vector<tuple<T1, int, int>> qry;
  qry.reserve(2 * ssize(query));
  for(int i = 0; i < ssize(query); i++) {
    qry.emplace_back(query[i][0] - 1, -1, i);
    qry.emplace_back(query[i][1] - 1, 1, i);
  }
  R::sort(qry, {}, [](auto &x) { return get<0>(x); });

  fenwickTree<T2> bit(ys.size());
  vector<T2> ans(ssize(query));
  for(int ptr = 0; auto [x, r, i] : qry) {
    while(ptr < ssize(pt) and get<0>(pt[ptr]) <= x) {
      auto [_, y, w] = pt[ptr++];
      bit.add(y, w);
    }
    ans[i] += r * bit.query(query[i][2], query[i][3]);
  }

  return ans;
}
