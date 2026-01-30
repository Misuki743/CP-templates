#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../default/t.cpp"
#include "../graph/flow/Dinic.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int l, r, m; cin >> l >> r >> m;
  const int s = l + r, t = l + r + 1;
  Dinic<int> dinic(l + r + 2);
  for(int i = 0; i < l; i++) dinic.addEdge(s, i, 1);
  for(int i = l; i < l + r; i++) dinic.addEdge(i, t, 1);
  for(int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    dinic.addEdge(u, v + l, 1);
  }

  cout << dinic.runFlow(s, t) << '\n';
  for(int v = 0; v < l; v++)
    for(auto &e : dinic.g[v])
      if (e.cap == 0 and e.to != s)
        cout << v << ' ' << e.to - l << '\n';

  return 0;
}

