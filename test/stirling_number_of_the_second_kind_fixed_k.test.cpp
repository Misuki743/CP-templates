#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_fixed_k"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/NTTmint.cpp"
#include "../poly/FPS.cpp"
#include "../combi/stirlingSecondCol.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, k; cin >> n >> k;
  cout << stirling_number_second_col<mint>(n + 1, k) << '\n';

  return 0;
}
