#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/NTTmint.cpp"
#include "../poly/FPS.cpp"
#include "../poly/sparsePolyope.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, k; cin >> n >> k;
  fps f(n);
  for(int i = 0; i < k; i++) {
    int j, val; cin >> j >> val;
    f[j] = val;
  }

  cout << sparseInv(f, n) << '\n';

  return 0;
}
