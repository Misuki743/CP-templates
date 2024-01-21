#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/NTTmint.cpp"
#include "../poly/FPS.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  fps f(n), g(m);
  for(mint &x : f)
    cin >> x;
  for(mint &x : g)
    cin >> x;

  auto [q, r] = f.div(g);
  cout << ssize(q) << ' ' << ssize(r) << '\n';
  cout << q << '\n';
  cout << r << '\n';

  return 0;
}

