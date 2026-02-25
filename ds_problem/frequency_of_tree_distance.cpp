vll frequency_of_tree_distance(vvi g) {
  const int n = ssize(g);

  auto [T, R] = centroidTree(g);
  vector<bool> vis(n, false);
  auto calc = [&](int s, int d0) {
    vll freq(1);
    auto dfs = [&](int v, int p, int d, auto &self) -> void {
      if (ssize(freq) <= d) freq.eb(0);
      if (d > 0) freq[d] += 1;
      for(int x : g[v])
        if (x != p and !vis[x])
          self(x, v, d + 1, self);
    };
    dfs(s, -1, d0, dfs);
    return freq;
  };

  vll ans(n);
  auto dfs = [&](int v, int p, auto &self) -> void {
    {
      auto freq_all = calc(v, 0);
      freq_all[0] = 1;
      auto F = convolution_self_ll(freq_all);
      for(int i = 0; i < n and i < ssize(F); i++)
        ans[i] += F[i];
      vis[v] = true;
      for(int x : g[v]) {
        if (vis[x]) continue;
        auto G = convolution_self_ll(calc(x, 1));
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
  for(ll &x : ans) x /= 2;
  return ans;
}
