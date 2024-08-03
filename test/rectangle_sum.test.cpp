#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "../default/t.cpp"
#include "../ds/fenwickTree.cpp"
#include "../misc/compression.cpp"
#include "../ds_problem/rectangleSum.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<tuple<int, int, ll>> pts(n);
  for(auto &[x, y, w] : pts)
    cin >> x >> y >> w;
  vector<array<int, 4>> query(q);
  for(auto &[l, d, r, u] : query)
    cin >> l >> r >> d >> u;

  for(ll ans : rectangleSum(pts, query))
    cout << ans << '\n';

  return 0;
}
