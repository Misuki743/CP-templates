struct ECC {
  vector<int> vb, gv, vid;
  vector<array<int, 2>> e;
  int size = -1;

  ECC(vector<array<int, 2>> &_e, int n) : vid(n), e(_e) {
    auto newComp = [&]() { vb.emplace_back(ssize(gv)), size++; };

    vector<vector<int>> g(n);
    for(int i = 0; auto [u, v] : e) {
      g[u].emplace_back(i);
      g[v].emplace_back(i++);
    }

    int t = 0, root;
    vector<int> tin(n, -1), low(n), s;
    vector<bool> vis(ssize(e), false);

    auto extract = [&](int v) {
      newComp();
      do {
        int u = s.back(); s.pop_back();
        vid[u] = size;
        gv.emplace_back(u);
      } while(gv.back() != v);
    };

    auto dfs = [&](int v, auto &&self) -> void {
      tin[v] = low[v] = t++;
      s.emplace_back(v);
      for(int i : g[v]) if (!vis[i]) {
        int x = e[i][0] ^ e[i][1] ^ v;
        vis[i] = true;
        if (tin[x] != -1) {
          low[v] = min(low[v], tin[x]);
        } else {
          self(x, self);
          low[v] = min(low[v], low[x]);
          if (low[x] > tin[v]) extract(x);
        }
      }
      if (v == root) extract(root);
    };

    for(int v = 0; v < n; v++)
      if (tin[v] == -1)
        dfs(root = v, dfs);

    newComp();
  }

  vector<int> vertexGroup(int id) {
    return {gv.begin() + vb[id], gv.begin() + vb[id + 1]};
  }
  bool isBridge(int id) { return vid[e[id][0]] != vid[e[id][1]]; }
  vector<vector<int>> bridgeTree() {
    vector<vector<int>> g(size);
    for(auto [u, v] : e) {
      if ((u = vid[u]) != (v = vid[v])) {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
      }
    }
    return g;
  }
};
