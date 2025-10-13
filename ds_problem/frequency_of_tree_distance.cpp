template<int32_t k = 23, int32_t c = 119, int32_t r = 3, class Mint = MontgomeryModInt<998244353>>
vector<Mint> frequency_of_tree_distance(vector<vector<int>> g) {
  const int n = ssize(g);
  NTT<k, c, r, Mint> Ntt;

  auto [T, R] = centroidTree(g);
  vector<bool> vis(n, false);
  auto calc = [&](int s, int d0) {
    vector<Mint> freq(1);
    auto dfs = [&](int v, int p, int d, auto &self) -> void {
      if (ssize(freq) <= d) freq.emplace_back(0);
      if (d > 0) freq[d] += 1;
      for(int x : g[v])
        if (x != p and !vis[x])
          self(x, v, d + 1, self);
    };
    dfs(s, -1, d0, dfs);
    return freq;
  };

  auto self_conv = [&](vector<Mint> f) {
    int sz = bit_ceil(2 * f.size());
    f.resize(sz);
    Ntt.ntt(f, false);
    for(Mint &x : f) x *= x;
    Ntt.ntt(f, true);
    return f;
  };

  vector<Mint> ans(n);
  auto dfs = [&](int v, int p, auto &self) -> void {
    {
      auto freq_all = calc(v, 0);
      freq_all[0] = 1;
      auto F = self_conv(freq_all);
      for(int i = 0; i < n and i < ssize(F); i++)
        ans[i] += F[i];
      vis[v] = true;
      for(int x : g[v]) {
        if (vis[x]) continue;
        auto G = self_conv(calc(x, 1));
        for(int i = 0; i < n and i < ssize(G); i++)
          ans[i] -= G[i];
      }
    }
    for(int x : T[v])
      if (x != p)
        self(x, v, self);
  };
  dfs(R, -1, dfs);

  ans.erase(ans.begin());
  for(Mint &x : ans) x *= (Mint::get_mod() + 1) / 2;
  return ans;
}
