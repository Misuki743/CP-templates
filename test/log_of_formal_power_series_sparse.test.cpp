#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series_sparse"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/NTTmint.cpp"
#include "../poly/FPS.cpp"
#include "../combi/binom.cpp"
#include "../numtheory/sqrt_mod.cpp"
#include "../poly/sparsePolyope.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, k; cin >> n >> k;
  fps f(n);
  for(int i = 0; i < k; i++) {
    int j, val; cin >> j >> val;
    f[j] = val;
  }

  cout << sparseLog(f, n) << '\n';

  return 0;
}
