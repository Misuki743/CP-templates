#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../linalg/matrixMint.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  matrix<mint> M(n, m);
  cin >> M;
  cout << M.rank() << '\n';

  return 0;
}
