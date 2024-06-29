#define PROBLEM "https://judge.yosupo.jp/problem/counting_spanning_tree_undirected"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../linalg/matrixMint.cpp"
#include "../combi/countSpanningForest.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<tuple<int, int, mint>> e(m);
  for(auto &[u, v, w] : e) {
    cin >> u >> v;
    w = 1;
  }

  cout << countSpanningForest(e, n) << '\n';

  return 0;
}
