#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../default/t.cpp"
#include "../tree/HLD.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vvi g(n);
  for(int v = 1; v < n; v++) {
    int p; cin >> p;
    g[v].eb(p), g[p].eb(v);
  }

  HLD hld(g);
  while(q--) {
    int u, v; cin >> u >> v;
    cout << hld.lca(u, v) << '\n';
  }

  return 0;
}
