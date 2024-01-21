#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "../default/t.cpp"
#include "../ds/DSUrollback.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<array<int, 4>> query(q);
  for(auto &[t, k, u, v] : query) {
    cin >> t >> k >> u >> v;
    k += 1;
  }

  vector<vector<array<int, 3>>> g(q + 1);
  vector<vector<array<int, 3>>> qry(q + 1);
  for(int i = 1; auto &[t, k, u, v] : query) {
    if (t == 0)
      g[k].push_back({i, u, v});
    else
      qry[k].push_back({i, u, v});
    i++;
  }

  DSU dsu(n);
  vector<int> ans(q + 1, -1);
  auto dfs = [&](int v, auto self) -> void {
    int t = dsu.time();
    for(auto [i, a, b] : qry[v])
      ans[i] = dsu.query(a) == dsu.query(b);
    for(auto [x, a, b] : g[v]) {
      dsu.merge(a, b);
      self(x, self);
      dsu.rollback(t);
    }
  };

  dfs(0, dfs);

  for(int i = 0; i <= q; i++)
    if (ans[i] != -1)
      cout << ans[i] << '\n';

  return 0;
}
