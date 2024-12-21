struct func_graph {
  vector<int> a;
  const int n;
  vector<bool> in_cyc;
  func_graph(vector<int> _a) : a(_a), n(size(a)), in_cyc(n, false) {
    vector<bool> in_s(n, false), vis(n, false);
    vector<int> s;
    auto dfs = [&](int v, auto &&self) -> void {
      vis[v] = true;
      s.emplace_back(v);
      in_s[v] = true;
      if (in_s[a[v]]) {
        in_cyc[a[v]] = true;
        while(s.back() != a[v]) {
          in_cyc[s.back()] = true;
          in_s[s.back()] = false;
          s.pop_back();
        }
      } else if (!vis[a[v]]) {
        self(a[v], self);
      }
    };

    for(int v = 0; v < n; v++) {
      if (vis[v]) continue;
      dfs(v, dfs);
      while(!s.empty()) {
        in_s[s.back()] = false;
        s.pop_back();
      }
    }
  }
};
