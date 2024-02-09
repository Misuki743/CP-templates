#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../ds/treap.cpp"
#include "../actedmonoid/actedMonoid_affineSum.cpp"

using am = actedMonoid_affineSum<mint>;
using Treap = treap<am::M, am::Mid, am::Mop, am::T, am::Tid, am::Top, am::act>;

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<array<mint, 2>> a(n, {0, 1});
  for(auto &[x, _] : a)
    cin >> x;

  Treap::node* tr = Treap::build(a);

  while(q--) {
    int t; cin >> t;
    if (t == 0) {
      int i, x; cin >> i >> x;
      Treap::insert(tr, i, {x, 1});
    } else if (t == 1) {
      int i; cin >> i;
      Treap::erase(tr, i);
    } else if (t == 2) {
      int l, r; cin >> l >> r;
      Treap::modify(tr, l, r, am::Tid(), true);
    } else if (t == 3) {
      int l, r, b, c; cin >> l >> r >> b >> c;
      Treap::modify(tr, l, r, {b, c});
    } else if (t == 4) {
      int l, r; cin >> l >> r;
      cout << Treap::query(tr, l, r)[0] << '\n';
    }
  }

  return 0;
}
