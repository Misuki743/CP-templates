#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../segtree/lazySegmentTree.cpp"
#include "../actedmonoid/actedMonoid_affineSum.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<array<mint, 2>> a(n);
  for(auto &[x, s] : a) {
    cin >> x;
    s = 1;
  }

  ultraLazySegmentTree<actedMonoid_affineSum<mint>> st(a);
  while(q--) {
    int t; cin >> t;
    if (t == 0) {
      int l, r, b, c; cin >> l >> r >> b >> c;
      st.modify(l, r, array<mint, 2>{b, c});
    } else {
      int l, r; cin >> l >> r;
      cout << st.query(l, r)[0] << '\n';
    }
  }

  return 0;
}
