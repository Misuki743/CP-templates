//#include<ds/fenwickTree.cpp>
//#include<misc/compression.cpp>

template<class T>
vector<int> rangeCountDistinct(vector<T> a, vector<array<int, 2>> query) {
  vector<int> b = [&]() {
    compression ys(a);
    return ys.ord;
  }();

  vector<int> qId(ssize(query));
  iota(qId.begin(), qId.end(), 0);
  ranges::sort(qId, less<int>{}, [&](auto &i) { return query[i][1]; });

  fenwickTree<int> ft(ssize(a));
  vector<int> ans(ssize(query)), pos(ssize(b), -1);
  for(int ptr = 0; int i : qId) {
    auto [l, r] = query[i];
    if (l == r) continue;
    while(ptr < r) {
      ft.add(pos[b[ptr]] + 1, 1);
      ft.add(ptr + 1, -1);
      pos[b[ptr]] = ptr, ptr++;
    }
    ans[i] = ft.query(l);
  }

  return ans;
}
