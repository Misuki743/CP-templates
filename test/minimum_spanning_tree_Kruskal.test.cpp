#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"

#include "../default/t.cpp"
#include "../ds/DSU/DSU.cpp"
#include "../graph/minimum_spanning_tree/Kruskal.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<tuple<int, int, ll>> e(m);
  for(auto &[u, v, w] : e)
    cin >> u >> v >> w;

  auto [cost, eid] = Kruskal(n, e);
  cout << cost << '\n';
  cout << eid << '\n';

  return 0;
}
