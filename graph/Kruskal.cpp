//#include "ds/DSU.cpp"

template<class T, bool sorted = false>
pair<T, vector<int>> Kruskal(vector<array<T, 3>> &e, int n) {
  vector<int> id(ssize(e));
  iota(id.begin(), id.end(), 0);
  if constexpr (!sorted)
    ranges::sort(id, {}, [&e](int i) { return e[i][2]; });

  T cost = 0;
  DSU dsu(n);
  vector<int> res;
  for(int i : id) {
    auto [u, v, w] = e[i];
    if (dsu.merge(u, v)) {
      cost += w;
      res.emplace_back(i);
    }
  }
  return make_pair(cost, res);
}
