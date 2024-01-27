#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/NTTmint.cpp"
#include "../poly/FPS.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vector<fps> fs(n);
  for(int i = 0; i < n; i++) {
    int d; cin >> d;
    fs[i].resize(d + 1);
    for(mint &x : fs[i])
      cin >> x;
  }

  cout << fps::allProd(fs) << '\n';

  return 0;
}
