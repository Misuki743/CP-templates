#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "../default/t.cpp"
#include "../ds/DSU/rollback_DSU.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<array<int, 4>> qry(q);
  for(auto &[t, k, u, v] : qry) {
    cin >> t >> k >> u >> v;
    k++;
  }

  vvc<tuple<int, int, int>> g(q + 1), event(q + 1);
  for(int i = 0; auto [t, k, u, v] : qry) {
    i++;
    if (t == 0) g[k].eb(i, u, v);
    else event[k].eb(i, u, v);
  }

  rollback_DSU dsu(n);
  vi sol(q + 1, -1);
  auto dfs = [&](int v, auto &self) -> void {
    int t = dsu.time();
    for(auto [i, x, y] : event[v])
      sol[i] = (dsu.query(x) == dsu.query(y));
    for(auto [to, x, y] : g[v]) {
      dsu.merge(x, y);
      self(to, self);
      dsu.rollback(t);
    }
  };

  dfs(0, dfs);

  for(int x : sol)
    if (x != -1)
      cout << x << '\n';

  return 0;
}
