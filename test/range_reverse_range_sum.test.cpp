#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"

#include "../default/t.cpp"
#include "../ds/treap.cpp"
#include "../actedmonoid/actedMonoid_affineSum.cpp"

using am = actedMonoid_affineSum<ll>;
using Treap = treap<am::M, am::Mid, am::Mop, am::T, am::Tid, am::Top, am::act>;

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<ll> a(n);
  for(ll &x : a)
    cin >> x;

  Treap::node* tr = Treap::build(a);

  while(q--) {
    int t, l, r; cin >> t >> l >> r;
    if (t == 0)
      Treap::modify(tr, l, r, Tunit(), true);
    else
      cout << Treap::query(tr, l, r) << '\n';
  }

  return 0;
}
