#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"

#include "../default/t.cpp"
#include "../ds/treap.cpp"

ll Mid() { return 0ll; }
bool Tid() { return true; }
ll Mop(const ll &a, const ll &b) { return a + b; }
bool Top(const bool&, const bool&) { return true; }
ll act(const ll &a, const bool&) { return a; }

using Treap = treap<ll, Mid, Mop, bool, Tid, Top, act>;

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
      Treap::modify(tr, l, r, Tid(), true);
    else
      cout << Treap::query(tr, l, r) << '\n';
  }

  return 0;
}
