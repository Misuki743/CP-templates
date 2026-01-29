#define PROBLEM "https://judge.yosupo.jp/problem/lcm_convolution"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../numtheory/linear_sieve.cpp"
#include "../numtheory/zeta_mobius_on_divisibility_lattice.cpp"
#include "../numtheory/lcm_convolution.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  linear_sieve<1'000'001> ls;

  int n; cin >> n;
  vector<mint> a(n), b(n);
  for(mint &x : a) cin >> x;
  for(mint &x : b) cin >> x;
  a.insert(a.begin(), mint(0));
  b.insert(b.begin(), mint(0));
  auto c = lcm_convolution(ls, a, b);
  c.erase(c.begin());
  cout << c << '\n';

  return 0;
}

