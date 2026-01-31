vector<int> MIS(vector<ull> g, int n) {
  vector<unsigned> pre(1 << (n / 2));
  for(unsigned msk = 0; msk < (1 << (n / 2)); msk++) {
    int adj = 0;
    for(int v = 0; v < n / 2; v++)
      if (msk >> v & 1)
        adj |= g[v];
    if (!(adj & msk))
      pre[msk] = msk;
  }
  for(int i = 0; (1 << i) < ssize(pre); i++)
    for(int j = 0; j < ssize(pre); j++)
      if ((j >> i & 1) and popcount(pre[j ^ (1 << i)]) > popcount(pre[j]))
        pre[j] = pre[j ^ (1 << i)];

  ull best = 0;
  auto dfs = [&](int v, ull is, ull adj, auto self) -> void {
    if (v == n / 2 - 1) {
      is |= pre[~adj & ((1LL << (n / 2)) - 1)];
      if (popcount(is) > popcount(best))
        best = is;
    } else  {
      self(v - 1, is, adj, self);
      adj |= g[v];
      if (~adj >> v & 1)
        self(v - 1, is | (1LL << v), adj, self);
    }
  };

  dfs(n - 1, 0, 0, dfs);

  vector<int> mis;
  for(int v = 0; v < n; v++)
    if (best >> v & 1)
      mis.emplace_back(v);

  return mis;
}
