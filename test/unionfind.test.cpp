#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../default/t.cpp"
#include "../ds/DSU.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  DSU dsu(n);
  while(q--) {
    int t, u, v; cin >> t >> u >> v;
    if (t == 0)
      dsu.merge(u, v);
    else
      cout << (dsu.query(u) == dsu.query(v)) << '\n';
  }

  return 0;
}
