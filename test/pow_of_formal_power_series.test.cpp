#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/NTTmint.cpp"
#include "../poly/FPS.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  ll k; cin >> k;
  fps f(n);
  for(mint &x : f)
    cin >> x;

  cout << f.pow(k, n) << '\n';

  return 0;
}
