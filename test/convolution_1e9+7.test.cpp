#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/NTTmint.cpp"
#include "../poly/NTTanymod.cpp"

using Mint = MontgomeryModInt<1000000007>;

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<Mint> a(n), b(m);
  for(Mint &x : a)
    cin >> x;
  for(Mint &x : b)
    cin >> x;

  cout << convAnyMod(a, b) << '\n';

  return 0;
}
