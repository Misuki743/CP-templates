#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../segtree/lazySegmentTree.cpp"

using monoid = array<mint, 2>;
using tag = array<mint, 2>;
monoid Munit() { return monoid{0, 0}; }
tag Tunit() { return tag{1, 0}; }
monoid Mope(const monoid &l, const monoid &r) { return {l[0] + r[0], l[1] + r[1]}; }
tag Tope(const tag &l, const tag &r) { return tag{l[0] * r[0], l[1] * r[0] + r[1]}; }
monoid comp(const monoid &l, const tag &r) { return {l[0] * r[0] + l[1] * r[1], l[1]}; }

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<monoid> a(n);
  for(auto &[x, s] : a) {
    cin >> x;
    s = 1;
  }

  lazySegmentTree<monoid, tag, Munit, Tunit, Mope, Tope, comp> st(a);
  while(q--) {
    int t; cin >> t;
    if (t == 0) {
      int l, r, b, c; cin >> l >> r >> b >> c;
      st.modify(l, r, tag{b, c});
    } else {
      int l, r; cin >> l >> r;
      cout << st.query(l, r)[0] << '\n';
    }
  }

  return 0;
}
