#define PROBLEM "https://judge.yosupo.jp/problem/compositional_inverse_of_formal_power_series_large"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/NTTmint.cpp"
#include "../poly/FPS.cpp"
#include "../poly/kthTermOfPowers.cpp"
#include "../poly/compositionalInverse.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  fps f(n);
  for(mint &x : f)
    cin >> x;
  cout << compositionalInverse(f, n) << '\n';

  return 0;
}
