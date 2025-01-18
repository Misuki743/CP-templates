#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_small_p_large_n"

#include "../default/t.cpp"
#include "../modint/dynamicSimpleMint.cpp"
#include "../combi/stirlingSecondModP.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int t, p; cin >> t >> p;
  mint::set_mod(p);
  stirlingSecondModP<mint> stir;
  while(t--) {
    ll n, k; cin >> n >> k;
    cout << stir.S(n, k) << '\n';
  }

  return 0;
}
