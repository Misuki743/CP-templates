#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "../default/t.cpp"
#include "../numtheory/factorize_pollard_rho.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int q; cin >> q;
  while(q--) {
    ull x; cin >> x;
    auto ans = factor(x);
    ranges::sort(ans);
    cout << ssize(ans) << ' ' << ans << '\n';
  }

  return 0;
}
