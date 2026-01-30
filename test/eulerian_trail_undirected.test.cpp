#define PROBLEM "https://judge.yosupo.jp/problem/eulerian_trail_undirected"

#include "../default/t.cpp"
#include "../graph/misc/eulerianTrail.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    vector<array<int, 2>> e(m);
    for(auto &[u, v] : e)
      cin >> u >> v;
    auto [vid, eid] = eulerianTrail(n, e);
    if (vid.empty()) {
      cout << "No\n"; 
    } else {
      cout << "Yes\n";
      cout << vid << '\n';
      cout << eid << '\n';
    }
  }

  return 0;
}
