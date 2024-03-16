#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"

#include "../default/t.cpp"
#include "../ds/DSU.cpp"
#include "../graph/Kruskal.cpp"
#include "../graph/Prim.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  ll n, m; cin >> n >> m;
  vector<array<ll, 3>> e(m);
  for(auto &[u, v, w] : e)
    cin >> u >> v >> w;

  ll cost;
  vector<int> eid;
  if (n * n < m * (int)bit_width((unsigned)m))
    tie(cost, eid) = Prim(e, n);
  else
    tie(cost, eid) = Kruskal(e, n);

  cout << cost << '\n';
  cout << eid << '\n';

  return 0;
}
