//#include<ds/fastJump.cpp>

pair<vector<vector<int>>, vector<int>> virtualTree(vector<vector<int>> g, vector<int> c) {
  int n = ssize(g), nxt = ssize(g);
  fastJump fj(g);
  vector<vector<int>> stk(n), res(2 * n - 1);
  vector<int> mp(2 * n - 1);
  iota(mp.begin(), mp.begin() + n, 0);
  auto addEdge = [&](int u, int v) {
    res[u].emplace_back(v);
    res[v].emplace_back(u);
  };
  auto dfs = [&](int v, int p, auto self) -> void {
    if (auto &stkV = stk[c[v]]; stkV.empty() or fj.lca(mp[stkV.back()], v) == mp[stkV.back()]) {
      stkV.emplace_back(v);
    } else {
      int x = fj.lca(mp[stkV.back()], v);
      while(ssize(stkV) > 1 and fj.dep[mp[end(stkV)[-2]]] >= fj.dep[x]) {
        addEdge(stkV.back(), end(stkV)[-2]);
        stkV.pop_back();
      }
      if (mp[stkV.back()] != x) {
        addEdge(stkV.back(), nxt);
        stkV.back() = nxt, mp[nxt++] = x;
      }
      stkV.emplace_back(v);
    }
    for(int x : g[v])
      if (x != p)
        self(x, v, self);
  };

  dfs(0, -1, dfs);

  vector<int> root(n, -1);
  for(int i = 0; i < n; i++) {
    while(ssize(stk[i]) > 1) {
      addEdge(stk[i].back(), end(stk[i])[-2]);
      stk[i].pop_back();
    }
    if (!stk[i].empty())
      root[i] = stk[i][0];
  }

  return make_pair(res, root);
}
