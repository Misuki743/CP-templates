#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../ds/treap.cpp"

using monoid = array<mint, 2>;
using tag = array<mint, 2>;

monoid Munit() { return monoid{0, 0}; }
tag Tunit() { return tag{1, 0}; }
monoid Mope(const monoid &l, const monoid &r) { return {l[0] + r[0], l[1] + r[1]}; }
tag Tope(const tag &l, const tag &r) { return tag{l[0] * r[0], l[1] * r[0] + r[1]}; }
monoid comp(const monoid &l, const tag &r) { return {l[0] * r[0] + l[1] * r[1], l[1]}; }

using Treap = treap<monoid, tag, Munit, Tunit, Mope, Tope, comp>;

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
      Treap::modify(tr, l, r, Tunit(), true);
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
