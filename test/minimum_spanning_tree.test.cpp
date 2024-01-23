#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"

#include "../default/t.cpp"
#include "../ds/DSU.cpp"
#include "../graph/Kruskal.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<array<ll, 3>> e(m);
  for(auto &[u, v, w] : e)
    cin >> u >> v >> w;

  auto [cost, eid] = Kruskal(e, n);
  cout << cost << '\n';
  cout << eid << '\n';

  return 0;
}
