#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/NTTmint.cpp"
#include "../poly/FPS.cpp"
#include "../setfunc/fastSubsetTransform.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  fps a(1 << n), b(1 << n);
  for(mint &x : a)
    cin >> x;
  for(mint &x : b)
    cin >> x;

  cout << conv(a, b) << '\n';

  return 0;
}
