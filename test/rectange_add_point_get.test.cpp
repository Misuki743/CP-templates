#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_add_point_get"

#include "../ds/fenwickTree2D.cpp"
#include "../misc/compression.cpp"
#include "../misc/rectangleAddPointGet.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<tuple<int, int, int, int, ll>> rect(n);
  for(auto &[l, r, d, u, w] : rect)
    cin >> l >> d >> r >> u >> w;
  vector<array<int, 2>> query;
  vector<int> updT(n, 0);
  while(q--) {
    int op; cin >> op;
    if (op == 0) {
      int l, d, r, u; cin >> l >> d >> r >> u;
      ll w; cin >> w;
      rect.emplace_back(l, r, d, u, w);
      updT.emplace_back(ssize(query));
    } else if (op == 1) {
      int x, y; cin >> x >> y;
      query.push_back({x, y});
    }
  }

  for(ll ans : rectAddPointGet<int, ll, INT_MAX>(rect, query, updT))
    cout << ans << '\n';

  return 0;
}
