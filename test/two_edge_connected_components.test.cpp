#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "../default/t.cpp"
#include "../graph/connectivity/ECC.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<array<int, 2>> e(m);
  for(auto &[u, v] : e) cin >> u >> v;

  ECC ecc(e, n);

  cout << ecc.size << '\n';
  for(int g = 0; g < ecc.size; g++) {
    auto gv = ecc.vertexGroup(g);
    cout << ssize(gv);
    for(int x : gv) cout << ' ' << x;
    cout << '\n';
  }

  return 0;
}

