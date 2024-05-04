#define PROBLEM "https://judge.yosupo.jp/problem/connected_components_of_complement_graph"

#include "../default/t.cpp"
#include "../graph/complementConnectivity.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<vector<int>> g(n);
  for(int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  auto [ccs, _] = complementConnectivity(g);
  cout << ssize(ccs) << '\n';
  for(auto &v : ccs) {
    cout << ssize(v) << ' ';
    for(int i = 0; i < ssize(v); i++)
      cout << v[i] << " \n"[i + 1 == ssize(v)];
  }

  return 0;
}
