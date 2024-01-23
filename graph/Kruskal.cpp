//#include "ds/DSU.cpp"

template<class T>
pair<T, vector<int>> Kruskal(vector<array<T, 3>> &e, int n) {
  vector<int> id(ssize(e));
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&e](int i, int j) { return e[i][2] < e[j][2]; });

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
