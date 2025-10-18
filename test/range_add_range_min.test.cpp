#define PROBLEM "https://judge.yosupo.jp/problem/range_add_range_min"

#include "../default/t.cpp"
#include "../segtree/lazySegmentTree.cpp"
#include "../segtree/ultraLazySegmentTree.cpp"
#include "../actedmonoid/actedMonoid_addMin.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<ll> a(n);
  for(ll &x : a) cin >> x;
  ultraLazySegmentTree<actedMonoid_addMin<ll>> st(a);

  while(q--) {
    int op, l, r; cin >> op >> l >> r;
    if (op == 0) {
      int x; cin >> x;
      st.modify(l, r, x);
    } else {
      cout << st.query(l, r) << '\n';
    }
  }

  return 0;
}

