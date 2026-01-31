#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/NTTmint.cpp"
#include "../tree/centroidTree.cpp"
#include "../numtheory/crt.cpp"
#include "../ds_problem/frequency_of_tree_distance.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vector<vector<int>> g(n);
  for(int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].emplace_back(v), g[v].emplace_back(u);
  }

  auto ans1 = frequency_of_tree_distance(g);
  auto ans2 = frequency_of_tree_distance<26, 7, 3, MontgomeryModInt<(7 << 26) | 1>>(g);
  for(int i = 0; i < n - 1; i++) {
    vector<ll> r = {ans1[i].get(), ans2[i].get()};
    vector<ll> m = {998244353, (7 << 26) | 1};
    cout << crt(r, m).first << " \n"[i + 1 == n - 1];
  }

  return 0;
}

