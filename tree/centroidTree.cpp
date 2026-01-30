pair<vector<vector<int>>, int> centroidTree(vector<vector<int>> &g) {
  int n = ssize(g);
  vector<vector<int>> g2(n);
  vector<int> sz(n);
  vector<bool> block(n, false);

  auto calc = [&](int v, int p, auto self) -> void {
    sz[v] = 1;
    for(int x : g[v]) {
      if (x == p or block[x]) continue;
      self(x, v, self);
      sz[v] += sz[x];
    }
  };

  auto dfs = [&](int v, auto self) -> int {
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
      g2[c].emplace_back(x);
      g2[x].emplace_back(c);
    }

    return c;
  };

  int root = dfs(0, dfs);

  return make_pair(g2, root);
}
