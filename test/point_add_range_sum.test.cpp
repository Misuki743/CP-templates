#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../default/t.cpp"
#include "../ds/fenwickTree.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<ll> a(n);
  for(ll &x : a)
    cin >> x;

  fenwickTree bit(a);
  while(q--) {
    int t, x, y; cin >> t >> x >> y;
    if (t == 0)
      bit.add(x, y);
    else
      cout << bit.query(x, y) << '\n';
  }

  return 0;
}
