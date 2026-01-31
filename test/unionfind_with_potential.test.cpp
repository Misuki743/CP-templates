#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../ds/DSU/potential_DSU.cpp"

int main() {
  int n, q; cin >> n >> q;
  potential_DSU dsu(n, mint(0),
    [](mint a, mint b) { return a + b; },
    [](mint &a) { return -a; }
  );

  while(q--) {
    int op; cin >> op;
    if (op == 0) {
      int u, v, x; cin >> u >> v >> x;
      cout << dsu.merge(v, u, x) << '\n';
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
