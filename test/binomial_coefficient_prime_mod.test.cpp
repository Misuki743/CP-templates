#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include "../default/t.cpp"
#include "../modint/dynamicSimpleMint.cpp"
#include "../combi/binom.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int t, p; cin >> t >> p;
  mint::set_mod(p);
  binomial<mint> bn(min(p, 10000000));
  while(t--) {
    int n, k; cin >> n >> k;
    cout << bn.binom(n, k) << '\n';
  }

  return 0;
}
