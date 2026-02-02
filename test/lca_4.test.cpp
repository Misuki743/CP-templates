#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../default/t.cpp"
#include "../tree/HLD.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vc<pii> e;
  e.reserve(n - 1);
  for(int v = 1; v < n; v++) {
    int p; cin >> p;
    e.emplace_back(p, v);
  }

  HLD hld(e);
  while(q--) {
    int u, v; cin >> u >> v;
    cout << hld.lca(u, v) << '\n';
  }

  return 0;
}
