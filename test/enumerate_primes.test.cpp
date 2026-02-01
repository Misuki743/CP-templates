#define PROBLEM "https://judge.yosupo.jp/problem/addition_of_big_integers"

#include "../default/t.cpp"
#include "../numtheory/prime_table.cpp"

prime_table<500'000'001> pt;

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, a, b; cin >> n >> a >> b;
  auto &prime = pt.prime_array();
  int pi = ranges::upper_bound(prime, n) - prime.begin();
  cout << pi << ' ' << (pi - 1 - b) / a + 1 << '\n';
  for(int i = b; i < pi; i += a)
    cout << prime[i] << ' ';
  cout << '\n';

  return 0;
}

