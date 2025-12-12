#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include "../default/t.cpp"
#include "../numtheory/factorize_pollard_rho.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int q; cin >> q;
  while(q--) {
    ull x; cin >> x;
    cout << (isPrime(x) ? "Yes\n" : "No\n");
  }

  return 0;
}
