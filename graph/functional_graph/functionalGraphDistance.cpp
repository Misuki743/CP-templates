struct functionalGraphDistance {
  int n;
  vector<int> ccId, dep, treeId, l, tin, tout, cycSize;
  vector<bool> onCycle;
  functionalGraphDistance(vector<int> f) : n(ssize(f)), ccId(n, -1), 
  dep(n), treeId(n, -1), l(n), tin(n), tout(n), cycSize(n), onCycle(n, false) {
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++) {
      g[f[i]].emplace_back(i);
      g[i].emplace_back(f[i]);
    }

    vector<bool> inSta(n, false);
    int nxt = 0;
    auto calc = [&](int s) -> void {
      {
        auto dfs = [&](int v, auto self) -> void {
          ccId[v] = nxt;
          for(int x : g[v])
            if (ccId[x] == -1)
              self(x, self);
        };
        dfs(s, dfs);
      }

      vector<int> cycle;
      {
        vector<int> sta;
        auto dfs = [&](int v, auto self) -> void {
          if (inSta[v]) {
            while(sta.back() != v) {
              cycle.emplace_back(sta.back());
              sta.pop_back();
            }
            cycle.emplace_back(sta.back());
            ranges::reverse(cycle);
          } else {
            sta.emplace_back(v);
            inSta[v] = true;
            self(f[v], self);
          }
        };
        dfs(s, dfs);
      }

      for(int i = 0; i < ssize(cycle); i++)
        onCycle[cycle[i]] = true, l[cycle[i]] = i, cycSize[cycle[i]] = ssize(cycle);

      {
        int t = 0;
        auto dfs = [&](int v, int p, int id, auto self) -> void {
          tin[v] = t++;
          for(int x : g[v]) if (!onCycle[x] and x != p) {
            treeId[x] = id, dep[x] = dep[v] + 1;
            self(x, v, id, self);
          }
          tout[v] = t++;
        };
        for(int x : cycle) dfs(x, -1, x, dfs);
      }
    };

    for(int v = 0; v < n; v++) {
      if (ccId[v] == -1) {
        calc(v);
        nxt++;
      }
    }
  }

  int dis(int u, int v) {
    if (ccId[u] != ccId[v]) return INT_MAX;
    if (!onCycle[u] and !onCycle[v]) {
      if (treeId[u] == treeId[v] and tin[v] <= tin[u] and tout[u] <= tout[v])
        return dep[u] - dep[v];
      else
        return INT_MAX;
    } else if (onCycle[u] and !onCycle[v]) {
      return INT_MAX;
    } else if (!onCycle[u] and onCycle[v]) {
      return dep[u] + (l[v] - l[treeId[u]] + cycSize[v]) % cycSize[v];
    } else {
      return (l[v] - l[u] + cycSize[v]) % cycSize[v];
    }
  }
};
