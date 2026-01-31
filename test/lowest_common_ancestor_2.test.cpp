#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../default/t.cpp"
#include "../ds/RMQ.cpp"
#include "../tree/LCA.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<vector<int>> g(n);
  for(int u = 1; u < n; u++) {
    int v; cin >> v;
    g[v].emplace_back(u);
  }

  LCA lc(g);

  while(q--) {
    int u, v; cin >> u >> v;
    cout << lc.lca(u, v) << '\n';
  }

  return 0;
}
