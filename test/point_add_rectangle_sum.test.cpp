#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "../ds/fenwickTree2D.cpp"
#include "../misc/compression.cpp"
#include "../misc/pointAddRectangleSum.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<tuple<int, int, ll>> pt(n);
  for(auto &[x, y, w] : pt)
    cin >> x >> y >> w;
  vector<array<int, 4>> query;
  vector<int> updT(n);
  while(q--) {
    int t; cin >> t;
    if (t == 0) {
      int x, y, w; cin >> x >> y >> w;
      updT.emplace_back(ssize(query));
      pt.emplace_back(x, y, w);
    } else if (t == 1) {
      int l, r, d, u; cin >> l >> d >> r >> u;
      query.push_back({l, r, d, u});
    }
  }

  for(ll x : pointAddRectSum<int, ll>(pt, query, updT))
    cout << x << '\n';

  return 0;
}
