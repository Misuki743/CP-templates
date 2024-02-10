struct heavyLightDecomposition {
  vector<int> dep, p, head, id;

  heavyLightDecomposition(vector<vector<int>> &g, vector<int> root = vector<int>(1, 0)) {
    int n = ssize(g);
    vector<int> sz(n, 1);
    dep.resize(n);
    p.resize(n, -1);
    head.resize(n);
    id.resize(n);

    auto dfs = [&](int v, auto self) -> void {
      int mxChild = -1;
      for(int i = -1; int x : g[v]) {
        i++;
        if (x == p[v]) continue;
        p[x] = v, dep[x] = dep[v] + 1;
        self(x, self);
        sz[v] += sz[x];
        if (mxChild == -1 or sz[x] > sz[g[v][mxChild]])
          mxChild = i;
      }
      if (mxChild != -1)
        swap(g[v][0], g[v][mxChild]);
    };

    int nxt = 0;
    auto cut = [&](int v, int h, auto self) -> void {
      id[v] = nxt++, head[v] = h;
      if (!g[v].empty() and g[v][0] != p[v])
        self(g[v][0], h, self);
      for(int x : g[v] | V::drop(1))
        if (x != p[v])
          self(x, x, self);
    };

    for(int x : root) {
      dfs(x, dfs);
      cut(x, x, cut);
    }
  }

  //(l, r, rev)
  vector<tuple<int, int, bool>> query(int u, int v, bool edge = false) {
    vector<array<int, 2>> resL, resR;
    while(head[u] != head[v]) {
      if (dep[head[u]] >= dep[head[v]]) {
        resL.push_back({id[head[u]], id[u] + 1});
        u = p[head[u]];
      } else {
        resR.push_back({id[head[v]], id[v] + 1});
        v = p[head[v]];
      }
    }
    if (id[v] + edge <= id[u])
      resL.push_back({id[v] + edge, id[u] + 1});
    else if (id[u] + edge <= id[v])
      resR.push_back({id[u] + edge, id[v] + 1});
    vector<tuple<int, int, bool>> res;
    for(auto [l, r] : resL)
      res.push_back({l, r, true});
    for(auto [l, r] : resR | V::reverse)
      res.push_back({l, r, false});
    return res;
  }
};
