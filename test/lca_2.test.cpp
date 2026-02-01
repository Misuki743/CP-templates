#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../default/t.cpp"
#include "../ds/RMQ.cpp"
#include "../tree/LCA.cpp"
#include "../misc/random.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vc<pii> e(n - 1);
  for(int v = 1; auto &[x, y] : e) {
    x = v++;
    cin >> y;
  }

  vi p = RNG::rand_perm(n);
  for(auto &[u, v] : e)
    u = p[u], v = p[v];
  LCA lc(e, p[0]);

  vi inv_p = invPerm(p);

  while(q--) {
    int u, v; cin >> u >> v;
    cout << inv_p[lc.lca(p[u], p[v])] << '\n';
  }

  return 0;
}
