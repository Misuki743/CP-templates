#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../linalg/matrixMint.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m, k; cin >> n >> m >> k;
  matrix<mint> a(n, m), b(m, k);
  cin >> a >> b;
  cout << a * b << '\n';

  return 0;
}
