array<int, 2> centroid(vector<vector<int>> &g) {
  int n = ssize(g);
  vector<int> sz(n, 1);
  auto dfs = [&](int v, int p, auto &&self) -> void {
    for(int x : g[v]) {
      if (x == p) continue;
      self(x, v, self);
      sz[v] += sz[x];
    }
  };
  dfs(0, -1, dfs);
  bool done = false;
  int c = 0, p = -1;
  while(!done) {
    done = true;
    for(int x : g[c]) {
      if (x == p or 2 * sz[x] <= n) continue;
      p = c, c = x, done = false;
      break;
    }
  }
  int c2 = -1;
  for(int x : g[c])
    if (x != p and 2 * sz[x] == n)
      c2 = x;
  return {c, c2};
}
