#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"

#include "../default/t.cpp"
#include "../tree/tree_hash.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vvi g(n);
  for(int v = 1; v < n; v++) {
    int p; cin >> p;
    g[v].eb(p), g[p].eb(v);
  }

  auto [K, subtree_id] = tree_hash(g);
  cout << K << '\n';
  cout << subtree_id << '\n';

  return 0;
}
