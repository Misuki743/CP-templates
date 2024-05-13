#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"

#include "../default/t.cpp"
#include "../graph/BCC.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<array<int, 2>> e(m);
  for(auto &[u, v] : e) cin >> u >> v;

  BCC bcc(e, n);

  cout << bcc.size << '\n';
  for(int g = 0; g < bcc.size; g++) {
    auto gv = bcc.vertexGroup(g);
    cout << ssize(gv);
    for(int v : gv)
      cout << ' ' << v;
    cout << '\n';
  }

  return 0;
}

