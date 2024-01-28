#define PROBLEM "https://judge.yosupo.jp/problem/mul_modp_convolution"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/NTTmint.cpp"
#include "../poly/mulConvolution.cpp"

NTT ntt;

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int p; cin >> p;
  vector<mint> a(p), b(p);
  for(mint &x : a)
    cin >> x;
  for(mint &x : b)
    cin >> x;

  mulConvolution mu(p);
  cout << mu.mulConv(a, b, ntt.conv) << '\n';

  return 0;
}
