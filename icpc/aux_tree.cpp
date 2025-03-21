//#include<short_lca.cpp>

auto aux_tree(vector<vector<int>> g, vector<int> c) {
  int n = ssize(g);
  LCA fj(g);
  vector<int> p(n << 1), top(n, -1), mp(n << 1);
  vector<vector<int>> h((n << 1) - 1);
  auto add = [&](int u, int v) {
    h[u].emplace_back(v), h[v].emplace_back(u);
  };
  auto dfs = [&](int v, auto &self) -> void {
    if (top[c[v]] != -1) {
      int t = fj.lca(mp[top[c[v]]], v), s;
      if (t != mp[top[c[v]]]) {
        while((s = p[top[c[v]]]) != -1 and fj.d[mp[s]] >= fj.d[t])
          add(top[c[v]], s), top[c[v]] = s;
        if (mp[top[c[v]]] != t) {
          add(top[c[v]], n);
          p[n] = s, top[c[v]] = n, mp[n++] = t;
        }
      }
    }
    p[v] = top[c[v]], top[c[v]] = v;
    for(int x : g[v]) if (x != fj.p[v]) self(x, self);
  };

  iota(mp.begin(), mp.end(), 0);
  dfs(0, dfs);

  for(int &x : top)
    while(x != -1 and p[x] != -1)
      add(x, p[x]), x = p[x];

  return pair(h, top);
}
