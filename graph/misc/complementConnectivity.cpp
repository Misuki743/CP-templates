pair<vector<vector<int>>, vector<int>> complementConnectivity(vector<vector<int>> &g) {
  int n = ssize(g);
  vector<bool> vis(n, false), adj(n, false);
  vector<int> unvis(n);
  iota(unvis.begin(), unvis.end(), 0);

  auto bfs = [&]() -> vector<int> {
    vector<int> cc;
    queue<int> q;
    q.push(unvis.back());
    vis[unvis.back()] = true;
    unvis.pop_back();
    while(!q.empty()) {
      int v = q.front(); q.pop();
      cc.emplace_back(v);
      vector<int> nxt;
      for(int x : g[v]) adj[x] = true;
      for(int x : unvis) {
        if (adj[x]) {
          nxt.emplace_back(x);
        } else {
          q.push(x);
          vis[x] = true;
        }
      }
      for(int x : g[v]) adj[x] = false;
      unvis.swap(nxt);
    }

    return cc;
  };

  vector<int> group(n, -1);
  vector<vector<int>> ccs;
  while(!unvis.empty()) {
    auto vs = bfs();
    for(int x : vs) group[x] = ssize(ccs);
    ccs.emplace_back(vs);
  }

  return make_pair(ccs, group);
}
