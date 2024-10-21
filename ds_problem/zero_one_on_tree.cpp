//#include<ds/monoidDSU>

struct min_monoid {
  using M = array<int, 2>;
  static M id() { return {INT_MAX, -1}; }
  static M op(const M& a, const M& b) {
    return min(a, b);
  }
};

template<class T>
T zero_one_on_tree(vector<vector<int>> g, vector<T> l, vector<T> a, int r = 0) {
  int n = ssize(g);

  vector<int> p(n, -1), d(n);
  {
    auto dfs = [&](int v, auto &&self) -> void {
      for(int x : g[v]) {
        if (x == p[v]) continue;
        d[x] = d[v] + 1, p[x] = v;
        self(x, self);
      }
    };
    dfs(r, dfs);
  }

  DSU<min_monoid::M, min_monoid::id, min_monoid::op> dsu([&]() {
    vector<min_monoid::M> init(n);
    for(int i = 0; i < n; i++)
      init[i] = {d[i], i};
    return init;
  }());

  using D = tuple<T, T, int>; //(l_v, a_v, v)
  auto cmp = [](D a, D b) {
    return get<1>(a) * get<0>(b) < get<0>(a) * get<1>(b);
  };
  priority_queue<D, vector<D>, decltype(cmp)> pq;
  for(int i = 0; i < n; i++)
    pq.push({l[i], a[i], i});

  T cost = 0, lsum = 0;
  vector<bool> vis(n, false);
  while(!pq.empty()) {
    auto [l_v, a_v, v] = pq.top(); pq.pop();
    if (l[v] != l_v or a[v] != a_v) continue;
    if (p[v] != -1 and !vis[dsu.get(p[v])[1]]) {
      dsu.merge(v, p[v]);
      int b = dsu.get(v)[1];
      cost += l[b] * a[v];
      l[b] += l[v], a[b] += a[v];
      pq.push({l[b], a[b], b});
    } else {
      vis[v] = true, cost += lsum * a[v], lsum += l[v];
    }
  }

  return cost;
}
