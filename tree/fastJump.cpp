struct fastJump {
  vector<int> p, jp, dep;

  fastJump(vector<vector<int>> g, int root = 0) : p(ssize(g)), jp(ssize(g)), dep(ssize(g)) {
    auto dfs = [&](int v, auto self) -> void {
      if (dep[p[v]] + dep[jp[jp[p[v]]]] == 2 * dep[jp[p[v]]])
        jp[v] = jp[jp[p[v]]];
      else
        jp[v] = p[v];

      for(int x : g[v]) {
        if (x == p[v]) continue;
        p[x] = v, dep[x] = dep[v] + 1;
        self(x, self);
      }
    };

    p[root] = jp[root] = root;
    dfs(root, dfs);
  }

  int jump(int v, int k) {
    k = min(k, dep[v]);
    while(k) {
      if (int d = dep[v] - dep[jp[v]]; d <= k)
        v = jp[v], k -= d;
      else
        v = p[v], k -= 1;
    }
    return v;
  }

  int lca(int u, int v) {
    if (dep[u] < dep[v])
      swap(u, v);
    u = jump(u, dep[u] - dep[v]);
    if (u == v) return u;
    while(p[u] != p[v]) {
      if (jp[u] != jp[v]) u = jp[u], v = jp[v];
      else u = p[u], v = p[v];
    }
    return p[u];
  }

  int kth(int s, int t, int k) {
    int m = lca(s, t);
    if (dep[s] + dep[t] - 2 * dep[m] < k)
      return -1;
    else if (dep[s] - dep[m] >= k)
      return jump(s, k);
    else
      return jump(t, dep[s] + dep[t] - 2 * dep[m] - k);
  }

  int dis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
  }
};
