#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../segtree/dualSegmentTree.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<mint> a(n);
  for(mint &x : a)
    cin >> x;

  dualSegmentTree<mint, Mid, array<mint, 2>, Tid, op, act> st(a);
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
