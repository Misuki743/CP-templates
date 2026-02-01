auto centroid_tree(vvi &g) {
  int n = ssize(g);
  vvi tr(n);
  vi sz(n);
  vc<bool> block(n, false);

  auto calc = [&](int v, int p, auto &self) -> void {
    sz[v] = 1;
    for(int x : g[v]) {
      if (x == p or block[x]) continue;
      self(x, v, self);
      sz[v] += sz[x];
    }
  };

  auto dfs = [&](int v, auto &self) -> int {
    calc(v, -1, calc);

    int c = v, p = -1;
    bool move;
    do {
      move = false;
      for(int x : g[c]) {
        if (x == p or block[x] or 2 * sz[x] <= sz[v]) continue;
        move = true, p = c, c = x;
        break;
      }
    } while(move);

    block[c] = true;
    for(int x : g[c]) {
      if (block[x]) continue;
      x = self(x, self);
      tr[c].emplace_back(x);
      tr[x].emplace_back(c);
    }

    return c;
  };

  int root = dfs(0, dfs);

  return pair(tr, root);
}
