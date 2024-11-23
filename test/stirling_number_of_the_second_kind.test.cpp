#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/NTTmint.cpp"
#include "../poly/FPS.cpp"
#include "../combi/binom.cpp"
#include "../combi/stirlingSecond.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  cout << stirling_number_second<mint>(n) << '\n';

  return 0;
}
