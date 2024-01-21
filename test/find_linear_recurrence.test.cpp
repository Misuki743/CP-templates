#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/BerlekampMassey.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vector<mint> a(n);
  for(mint &x : a)
    cin >> x;

  auto c = BerlekampMassey(a);
  cout << ssize(c) - 1 << '\n';
  for(int i = 1; i < ssize(c); i++)
    cout << c[i] << " \n"[i + 1 == ssize(c)];

  return 0;
}
