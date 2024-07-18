#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group"

#include "../default/t.cpp"
#include "../ds/potentialDSU.cpp"
#include "../modint/MontgomeryModInt.cpp"

using matrix = array<array<mint, 2>, 2>;
matrix id() {
  matrix m;
  m[0][0] = m[1][1] = 1;
  return m;
}
matrix op(const matrix &m1, const matrix &m2) {
  matrix m;
  for(int i : {0, 1})
    for(int k : {0, 1})
      for(int j : {0, 1})
        m[i][j] += m1[i][k] * m2[k][j];
  return m;
}
matrix inv(const matrix &m) {
  matrix a = m;
  swap(a[0][0], a[1][1]);
  a[0][1] = -a[0][1], a[1][0] = -a[1][0];
  return a;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  DSU<matrix, id, op, inv> dsu(n);
  while(q--) {
    int t, u, v; cin >> t >> u >> v;
    swap(u, v);
    if (t == 0) {
      matrix m;
      for(auto &v : m) for(mint &x : v) cin >> x;
      cout << dsu.merge(u, v, m) << '\n';
    } else {
      if (dsu.query(u) != dsu.query(v))
        cout << -1 << '\n';
      else
        cout << dsu.query(u, v) << '\n';
    }
  }

  return 0;
}
