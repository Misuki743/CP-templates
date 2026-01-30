//#include "ds/DSU/DSU.cpp"

template<bool sorted, integral T>
auto Kruskal(int n, vector<tuple<int, int, T>> &e) {
  vi ord;
  if constexpr (sorted) {
    ord.resize(n);
    iota(ord.begin(), ord.end(), 0ll);
  } else {
    ord = argSort(e, [](tuple<int, int, T> &t) { return get<2>(t); });
  }

  T cost = 0;
  vi eid;
  DSU dsu(n);
  for(int i : ord) {
    auto [u, v, w] = e[i];
    if (dsu.merge(u, v))
      cost += w, eid.emplace_back(i);
  }

  return pair(cost, eid);
}
