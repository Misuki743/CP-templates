#define PROBLEM "https://judge.yosupo.jp/problem/bell_number"

#include "../default/t.cpp"
#include "modint/MontgomeryModInt.cpp"
#include "poly/NTTmint.cpp"
#include "poly/FPS.cpp"
#include "combi/binom.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  cout << bell_number<mint>(n + 1) << '\n';

  return 0;
}

