struct BCC {
  vector<int> f, vb, eb, gv, ge, eid, vid;
  int size = -1;

  BCC(vector<array<int, 2>> &e, int n)
  : f(n), eid(ssize(e)), vid(n) {

    auto newComp = [&]() {
      vb.emplace_back(ssize(gv));
      eb.emplace_back(ssize(ge));
      size++;
    };

    vector<vector<int>> g(n);
    for(int i = 0; auto [u, v] : e) {
      g[u].emplace_back(i);
      g[v].emplace_back(i++);
    }

    int t = 0;
    vector<int> tin(n, -1), low(n), cnt(n), s;
    vector<bool> vis(ssize(e), false);
    auto dfs = [&](int v, auto &&self) -> void {
      tin[v] = low[v] = t++;
      for(int i : g[v]) if (!vis[i]) {
        int x = e[i][0] ^ e[i][1] ^ v;
        vis[i] = true, s.emplace_back(i);
        if (tin[x] != -1) {
          low[v] = min(low[v], tin[x]);
        } else {
          self(x, self);
          low[v] = min(low[v], low[x]);
          if (low[x] >= tin[v]) {
            newComp();
            do {
              int j = s.back(); s.pop_back();
              for(int u : e[j])
                if (++cnt[u] == 1)
                  gv.emplace_back(u);
              eid[j] = size;
              ge.emplace_back(j);
            } while(ge.back() != i);
            for(int u : gv | views::drop(vb.back()))
              cnt[u] = 0, f[u]++, vid[u] = size;
          }
        }
      }
      if (g[v].empty()) newComp(), gv.emplace_back(v);
    };

    for(int v = 0; v < n; v++)
      if (tin[v] == -1)
        dfs(v, dfs);
    newComp();
  }

  vector<int> vertexGroup(int id) {
    return {gv.begin() + vb[id], gv.begin() + vb[id + 1]};
  }
  vector<int> edgeGroup(int id) {
    return {ge.begin() + eb[id], ge.begin() + eb[id + 1]};
  }
  bool isCutVertex(int v) { return f[v] > 1; }
  pair<vector<vector<int>>, vector<int>> blockCutTree() {
    int n = ssize(f);
    vector<vector<int>> g(n + size);
    vector<int> mp = vid;
    for(int &x : mp) x += n;
    for(int i = 0; i < size; i++)
      for(int v : vertexGroup(i))
        if (isCutVertex(v)) {
          g[i + n].emplace_back(v);
          g[v].emplace_back(i + n);
          mp[v] = v;
        }
    return make_pair(g, mp);
  }
};
