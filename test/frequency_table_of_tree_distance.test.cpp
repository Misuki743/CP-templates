#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/NTTmint.cpp"
#include "../poly/convolution_ll.cpp"
#include "../tree/centroid_tree.cpp"
#include "../ds_problem/frequency_of_tree_distance.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vector<vector<int>> g(n);
  for(int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
  }

  cout << frequency_of_tree_distance(g) << '\n';

  return 0;
}

