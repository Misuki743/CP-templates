#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../segtree/dualSegmentTree.cpp"

mint Munit() { return mint(0); }
array<mint, 2> Tunit() { return {1, 0}; }
array<mint, 2> ope(const array<mint, 2> &l, const array<mint, 2> &r) { return {l[0] * r[0], l[1] * r[0] + r[1]}; }
mint comp(const mint &l, const array<mint, 2> &r) { return r[0] * l + r[1]; }

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<mint> a(n);
  for(mint &x : a)
    cin >> x;

  dualSegmentTree<mint, array<mint, 2>, Munit, Tunit, ope, comp> st(a);
  while(q--) {
    int t; cin >> t;
    if (t == 0) {
      int l, r, b, c; cin >> l >> r >> b >> c;
      st.modify(l, r, {b, c});
    } else {
      int i; cin >> i;
      cout << st.get(i) << '\n';
    }
  }

  return 0;
}
