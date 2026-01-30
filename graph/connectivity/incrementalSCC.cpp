//#include "ds/DSU.cpp"
//#include "graph/SCC.cpp"

vector<array<int, 3>> incrementalSCC(vector<array<int, 2>> _e, int n) {
  vector<array<int, 3>> e(ssize(_e));
  for(int i = 0; auto [u, v] : _e)
    e[i] = {u, v, i}, i++;

  DSU dsu(n);
  vector<array<int, 3>> ret;
  vector<int> mp(n, -1);
  auto calc = [&](int l, int r, vector<array<int, 3>> e, auto &&self) -> void {
    if (l + 1 == r) return;

    int mid = (l + r) / 2;

    vector<array<int, 3>> el, er;
    {
      auto ep = e;
      int nxt = 0;
      for(auto &x : ep) for(int &v : x | views::take(2)) {
        v = dsu.query(v);
        if (mp[v] == -1) mp[v] = nxt++;
        v = mp[v];
      }
      for(auto &x : e) for(int &v : x | views::take(2)) mp[dsu.query(v)] = -1;
      vector<vector<int>> g(nxt);
      for(auto &[u, v, t] : ep)
        if (t <= mid)
          g[u].emplace_back(v);
      auto gId = SCC(g).groupId;
      for(int i = 0; auto &[u, v, t] : ep)
        (gId[u] == gId[v] ? el : er).push_back(e[i++]);
    }

    self(l, mid, el, self);

    for(auto [u, v, t] : el)
      if (dsu.merge(u, v))
        ret.push_back({u, v, mid});

    self(mid, r, er, self);
  };

  calc(0, ssize(e), e, calc);

  return ret;
}
