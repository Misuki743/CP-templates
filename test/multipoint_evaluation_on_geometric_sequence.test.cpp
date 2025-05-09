#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation_on_geometric_sequence"

#include "../default/t.cpp"
#include "modint/MontgomeryModInt.cpp"
#include "poly/NTTmint.cpp"
#include "poly/chirp_Z_transform.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m, a, r; cin >> n >> m >> a >> r;
  vector<mint> c(n);
  for(mint &x : c) cin >> x;

  cout << chirp_Z_transform<ntt, mint>(c, a, r, m) << '\n';

  return 0;
}

