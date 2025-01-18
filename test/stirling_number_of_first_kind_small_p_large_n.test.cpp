#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_small_p_large_n"

#include "../default/t.cpp"
#include "../modint/dynamicSimpleMint.cpp"
#include "../combi/stirlingFirstModP.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int t, p; cin >> t >> p;
  mint::set_mod(p);
  stirlingFirstModP<mint> stir;
  while(t--) {
    ll n, k; cin >> n >> k;
    cout << stir.s(n, k) << '\n';
  }

  return 0;
}
