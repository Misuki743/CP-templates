template<integral T>
auto weighted_tree_diameter(vc<tuple<int, int, T>> &e) {
  const int n = ssize(e) + 1;
  constexpr T NINF = numeric_limits<T>::min();

  vi adj0(n), d0(n);
  vc<T> w0(n);
  for(auto [u, v, w] : e) {
    adj0[u] ^= v, adj0[v] ^= u;
    d0[u]++, d0[v]++;
    w0[u] ^= w, w0[v] ^= w;
  }

  auto xor_link_traversal = [&](int s) {
    vi adj = adj0, d = d0, p(n, -1), ord;
    vc<T> w = w0;

    d[s] = 0;
    ord.reserve(n);
    for(int i = 0; i < n; i++) {
      int v = i;
      while(d[v] == 1) {
        ord.emplace_back(v);
        p[v] = adj[v], d[v] = 0, d[p[v]]--;
        adj[p[v]] ^= v, w[p[v]] ^= w[v];
        v = p[v];
      }
    }

    auto far = pair(NINF, -1);
    for(int v : ord | views::reverse) {
      w[v] += w[p[v]];
      if (w[v] > far.first)
        far = pair(w[v], v);
    }

    return pair(far, p);
  };

  int u = xor_link_traversal(0).first.second;
  auto [far, p] = xor_link_traversal(u);
  auto [diameter, v] = far;
  vi path = {v};
  while(path.back() != u)
    path.emplace_back(p[path.back()]);

  return pair(diameter, path);
}
