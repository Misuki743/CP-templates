#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../default/t.cpp"
#include "../ds/RMQ.cpp"
#include "../tree/LCA.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vc<pii> e(n - 1);
  for(int v = 1; auto &[x, y] : e) {
    x = v++;
    cin >> y;
  }

  LCA lc(e, 0);

  while(q--) {
    int u, v; cin >> u >> v;
    cout << lc.lca(u, v) << '\n';
  }

  return 0;
}
