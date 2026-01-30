#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../default/t.cpp"
#include "../tree/weighted_tree_diameter.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vector<vector<pair<int, ll>>> g(n);
  for(int i = 1; i < n; i++) {
    int u, v, w; cin >> u >> v >> w;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  auto [d, _, __, vs] = weighted_tree_diameter<ll>(g);
  cout << d << ' ' << ssize(vs) << '\n';
  cout << vs << '\n';

  return 0;
}
