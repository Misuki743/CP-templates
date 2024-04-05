template<bool directed = false>
array<vector<int>, 2> cycleDetection(vector<array<int, 2>> &e) {
  int n = 0;
  for(auto [u, v] : e) n = max({n, u + 1, v + 1});
  vector<vector<int>> g(n);
  for(int i = 0; auto [u, v] : e) {
    if (u == v) return {{{u}, {i}}};
    if constexpr (!directed)
      g[v].emplace_back(i);
    g[u].emplace_back(i++);
  }

  vector<bool> vis(n, false), inStack(n, false);
  vector<int> vs, es;
  auto dfs = [&](int v, int p, auto self) -> bool {
    vis[v] = inStack[v] = true;
    vs.emplace_back(v);
    for(int i : g[v]) {
      if (i == p) continue;
      int x = v ^ e[i][0] ^ e[i][1];
      es.emplace_back(i);
      if (inStack[x]) {
        vs = vector<int>(ranges::find(vs, x), vs.end());
        es = vector<int>(es.end() - ssize(vs), es.end());
        return true;
      } else if (!vis[x] and self(x, i, self)) {
        return true;
      }
      es.pop_back();
    }
    vs.pop_back();
    inStack[v] = false;
    return false;
  };

  for(int v = 0; v < n; v++)
    if (!vis[v] and dfs(v, -1, dfs))
      return {vs, es};

  return {};
}
