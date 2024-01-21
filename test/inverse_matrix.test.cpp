#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../linalg/matrixMint.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  matrix<mint> a(n);
  cin >> a;

  auto b = a.inv();
  if (b.n() == 0)
    cout << -1 << '\n';
  else
    cout << b << '\n';

  return 0;
}
