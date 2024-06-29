//#include "modint/MontgomeryModInt.cpp"
//#include "linalg/matrixMint.cpp"
//#include "combi/countSpanningForest.cpp"
//#include "combi/binom.cpp"

template<class Mint>
Mint countEulerianCircuit(vector<array<int, 2>> e, int n) {
  vector<int> deg(n);
  vector<vector<int>> g(n);
  for(auto [u, v] : e) {
    deg[v]++;
    g[u].emplace_back(v);
  }

  for(int v = 0; v < n; v++)
    if (deg[v] != ssize(g[v]))
      return Mint(0);

  vector<bool> vis(n, false);
  auto dfs = [&](int v, auto &&self) -> void {
    vis[v] = true;
    for(int x : g[v])
      if (!vis[x])
        self(x, self);
  };

  int s = 0;
  while(s < n and deg[s] == 0) s++;
  s %= n;
  dfs(s, dfs);

  vector<int> r(1, s);
  for(int v = 0; v < n; v++) if (!vis[v]) {
    if (deg[v] != 0) return Mint(0);
    else r.emplace_back(v);
  }

  vector<tuple<int, int, Mint>> ep(ssize(e));
  for(int i = 0; auto [u, v] : e)
    ep[i++] = {u, v, Mint(1)};
  
  Mint c = 1;
  binomial<Mint> bn(ssize(e));
  for(int v = 0; v < n; v++)
    c *= bn.fac(max(deg[v] - 1, 0));

  return c * countSpanningForest<Mint, true>(ep, n, r);
}
