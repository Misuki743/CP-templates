#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"

#include "../default/t.cpp"
#include "../ds/DSU/potentialDSU.cpp"
#include "../modint/MontgomeryModInt.cpp"

mint id() { return 0; }
mint op(const mint &a, const mint &b) { return a + b; }
mint inv(const mint &a) { return mint(0) - a; }

int main() {
  int n, q; cin >> n >> q;

  DSU<mint, id, op, inv> dsu(n);
  while(q--) {
    int t, u, v; cin >> t >> u >> v;
    if (t == 0) {
      int x; cin >> x;
      cout << dsu.merge(v, u, x) << '\n';
    } else {
      if (dsu.query(u) != dsu.query(v))
        cout << -1 << '\n';
      else
        cout << dsu.query(v, u) << '\n';
    }
  }

  return 0;
}
