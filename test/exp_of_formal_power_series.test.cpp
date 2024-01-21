#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/NTTmint.cpp"
#include "../poly/FPS.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  fps f(n);
  for(mint &x : f)
    cin >> x;

  cout << f.exp(n) << '\n';

  return 0;
}
