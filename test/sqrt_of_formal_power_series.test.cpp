#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/NTTmint.cpp"
#include "../poly/FPS.cpp"
#include "../numtheory/sqrtMod.cpp"
#include "../poly/FPSsqrt.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  fps f(n);
  for(mint &x : f)
    cin >> x;

  auto g = FPSsqrt(f, n);
  if (g.empty())
    cout << -1 << '\n';
  else
    cout << g << '\n';

  return 0;
}
