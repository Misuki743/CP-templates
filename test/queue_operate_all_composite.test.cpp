#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../ds/slidingWindowAggregation.cpp"
#include "../actedmonoid/actedMonoid_affineSum.cpp"

using am = actedMonoid_affineSum<mint>;

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  SWAG<am::T, am::Tid, am::Top> swag;

  int q; cin >> q;
  while(q--) {
    int t; cin >> t;
    if (t == 0) {
      mint a, b; cin >> a >> b;
      swag.push(am::T{a, b});
    } else if (t == 1) {
      swag.pop();
    } else if (t == 2) {
      mint x; cin >> x;
      cout << am::Top(am::T{0, x}, swag.query())[1] << '\n';
    }
  }

  return 0;
}
