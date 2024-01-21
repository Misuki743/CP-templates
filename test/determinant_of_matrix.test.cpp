#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../linalg/matrixMint.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  matrix<mint> a(n);
  cin >> a;
  cout << a.det() << '\n';

  return 0;
}
