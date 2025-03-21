struct LCA {
  vector<int> p, j, d;

  LCA(vector<vector<int>> g, int r = 0)
  : p(size(g), r), j(size(g), r), d(size(g)) {
    auto dfs = [&](int v, auto &self) -> void {
      if (d[p[v]] + d[j[j[p[v]]]] == 2 * d[j[p[v]]])
        j[v] = j[j[p[v]]];
      for(int x : g[v]) if (x != p[v]) {
        j[x] = p[x] = v, d[x] = d[v] + 1;
        self(x, self);
      }
    };
    dfs(r, dfs);
  }

  int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    while(d[u] > d[v]) u = d[j[u]] < d[v] ? p[u] :j[u];
    while(p[u] != p[v])
      tie(u, v) = j[u] != j[v] ? 
                  tie(j[u], j[v]) : tie(p[u], p[v]);
    return u == v ? u : p[u];
  }
};
