template<bool directed = false, bool circuit = false>
array<vector<int>, 2> eulerianTrail(int n, vector<array<int, 2>> &e) {
  vector<int> indeg(n), outdeg(n);
  vector<vector<int>> g(n);
  for(int i = 0; auto [u, v] : e) {
    outdeg[u] += 1, indeg[v] += 1;
    if constexpr (!directed)
      g[v].emplace_back(i);
    g[u].emplace_back(i++);
  }

  int s = -1;
  if constexpr (directed) {
    for(int v = 0; v < n; v++) {
      if (abs(indeg[v] - outdeg[v]) >= 2) return {};
      if (outdeg[v] <= indeg[v]) continue;
      if (s != -1) return {};
      s = v;
    }
  } else {
    for(int v = 0, t = -1; v < n; v++) {
      if ((indeg[v] + outdeg[v]) % 2 == 0) continue;
      if (s != -1 and t != -1) return {};
      if (s == -1) s = v;
      else t = v;
    }
  }

  if constexpr (circuit)
    if (s != -1) 
      return {};

  if (s == -1)
    for(int v = 0; v < n; v++)
      if (indeg[v] | outdeg[v])
        s = v;

  if (s == -1)
    s = 0;

  vector<int> vid, eid, ptr(n);
  vector<bool> visE(ssize(e), false);
  auto dfs = [&](int v, auto self) -> void {
    for(int &i = ptr[v]; i < ssize(g[v]); i++) {
      if (visE[g[v][i]]) continue;
      int tmp = g[v][i];
      int x = v ^ e[tmp][0] ^ e[tmp][1];
      visE[tmp] = true;
      self(x, self);
      vid.emplace_back(x);
      eid.emplace_back(tmp);
    }
  };

  dfs(s, dfs);
  vid.emplace_back(s);

  ranges::reverse(vid);
  ranges::reverse(eid);

  if (ssize(eid) != ssize(e))
    return {};
  else
    return {vid, eid};
}
