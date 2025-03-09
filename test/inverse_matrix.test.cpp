#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../linalg/matrixMint.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  matrix<mint> M(n, n);
  cin >> M;
  auto [ok, MI] = M.inv();
  if (ok) cout << MI << '\n';
  else cout << -1 << '\n';

  return 0;
}
