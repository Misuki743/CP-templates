#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../linalg/matrixMint.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  ll k; cin >> k;
  matrix<mint> a(n); cin >> a;
  cout << a.pow(k) << '\n';

  return 0;
}
