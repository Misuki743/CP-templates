#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../poly/NTTmint.cpp"
#include "../poly/BostanMori.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int d; cin >> d;
  ll k; cin >> k;
  vector<mint> a(d), c(d);
  for(mint &x : a)
    cin >> x;
  for(mint &x : c) {
    cin >> x;
    x *= -1;
  }

  c.insert(c.begin(), mint(1));
  NTT<23, 119, 3, mint> ntt;
  a = ntt.conv(a, c);
  a.resize(d);

  cout << BostanMori<ntt, mint>(a, c, k) << '\n';

  return 0;
}
