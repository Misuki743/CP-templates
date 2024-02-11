#define PROBLEM "https://judge.yosupo.jp/problem/range_set_range_composite"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../segtree/rangeSetSegmentTree.cpp"
#include "../actedmonoid/actedMonoid_affineSum.cpp"

using am = actedMonoid_affineSum<mint>;

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<am::T> ab(n);
  for(auto &[a, b] : ab)
    cin >> a >> b;

  rangeSetSegmentTree<am::T, am::Tid, am::Top> st(ab);
  while(q--) {
    int t; cin >> t;
    if (t == 0) {
      int l, r, c, d; cin >> l >> r >> c >> d;
      st.set(l, r, am::T{c, d});
    } else {
      int l, r, x; cin >> l >> r >> x;
      cout << am::Top(am::T{0, x}, st.query(l, r))[1] << '\n';
    }
  }

  return 0;
}
