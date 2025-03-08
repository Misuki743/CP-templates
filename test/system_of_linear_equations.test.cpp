#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../linalg/matrixMint.cpp"
#include "../linalg/solveLinear.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  matrix<mint> A(n, m);
  cin >> A;
  vector<mint> b(n);
  for(mint &x : b) cin >> x;

  auto [ans, basis] = solve_linear(A, b);
  if (ans.empty()) {
    cout << -1 << '\n';
  } else {
    cout << ssize(basis) << '\n';
    cout << ans << '\n';
    for(auto &v : basis)
      cout << v << '\n';
  }

  return 0;
}
