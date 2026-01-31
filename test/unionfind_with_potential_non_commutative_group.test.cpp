#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../ds/DSU/potential_DSU.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  using M = array<mint, 4>;
  potential_DSU dsu(n, M{1, 0, 0, 1},
    [](M a, M b) { return M{a[0] * b[0] + a[1] * b[2], a[0] * b[1] + a[1] * b[3],
                            a[2] * b[0] + a[3] * b[2], a[2] * b[1] + a[3] * b[3]}; },
    [](M &a) { return M{a[3], -a[1], -a[2], a[0]}; }
  );

  while(q--) {
    int op; cin >> op;
    if (op == 0) {
      int u, v; cin >> u >> v;
      M m;
      for(mint &x : m) cin >> x;
      cout << dsu.merge(v, u, m) << '\n';
    } else {
      int u, v; cin >> u >> v;
      if (dsu.query(u) != dsu.query(v))
        cout << -1 << '\n';
      else
        cout << dsu.query(v, u) << '\n';
    }
  }

  return 0;
}
