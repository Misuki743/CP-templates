#define PROBLEM "https://judge.yosupo.jp/problem/bernoulli_number"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/NTTmint.cpp"
#include "../poly/FPS.cpp"
#include "../combi/bernoulliNumber.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  cout << bernoulliNumber<mint>(n) << '\n';

  return 0;
}
