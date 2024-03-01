#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include "../default/t.cpp"
#include "../modint/mintAnyMod.cpp"
#include "../combi/binom.cpp"

ll mint::MOD;

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int t; cin >> t >> mint::MOD;
  binomial<mint> bn(min(mint::MOD, 10000000ll));
  while(t--) {
    int n, k; cin >> n >> k;
    cout << bn.binom(n, k) << '\n';
  }

  return 0;
}
