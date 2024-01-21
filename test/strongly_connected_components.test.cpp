#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../default/t.cpp"
#include "../graph/SCC.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<vector<int>> g(n);
  for(; m--; ) {
    int u, v; cin >> u >> v;
    g[u].emplace_back(v);
  }

  SCC scc(g);

  cout << scc.size << '\n';
  for(int i = 0; i < scc.size; i++)
    cout << ssize(scc.group[i]) << ' ' << scc.group[i] << '\n';

  return 0;
}
