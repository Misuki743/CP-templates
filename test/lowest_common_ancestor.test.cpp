#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../default/t.cpp"
#include "../ds/fastJump.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<vector<int>> g(n);
  for(int u = 1; u < n; u++) {
    int v; cin >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  fastJump jp(g);

  while(q--) {
    int u, v; cin >> u >> v;
    cout << jp.lca(u, v) << '\n';
  }

  return 0;
}
