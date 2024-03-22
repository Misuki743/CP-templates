#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../combi/binom.cpp"
#include "../poly/NTTmint.cpp"
#include "../poly/FPS.cpp"
#include "../poly/taylorShift.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, c; cin >> n >> c;
  fps a(n);
  for(mint &x : a)
    cin >> x;
  cout << taylorShift(a, mint(c)) << '\n';

  return 0;
}
