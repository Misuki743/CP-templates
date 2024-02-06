#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/NTTmint.cpp"
#include "../poly/FPS.cpp"
#include "../misc/sharpPSubsetSum.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, t; cin >> n >> t;
  vector<int> w(n);
  for(int &x : w)
    cin >> x;

  auto f = sharpPSubsetSum<mint>(w, t);
  f.erase(f.begin());
  cout << f << '\n';

  return 0;
}
