#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"

#include "../default/t.cpp"
#include "../tree/tree_hash.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vector<vector<int>> g(n);
  for(int u = 1; u < n; u++) {
    int v; cin >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  auto [cnt, id] = tree_hash(g);
  cout << cnt << '\n';
  cout << id << '\n';

  return 0;
}
