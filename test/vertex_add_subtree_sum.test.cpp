#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "../default/t.cpp"
#include "../tree/HLD.cpp"
#include "../ds/fenwickTree.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vll a(n);
  for(ll &x : a) cin >> x;
  vc<pii> e;
  for(int v = 1; v < n; v++) {
    int p; cin >> p;
    e.emplace_back(p, v);
  }

  HLD hld(std::move(e));
  fenwickTree ft(hld.reorder_init(a));
  while(q--) {
    int op; cin >> op;
    if (op == 0) {
      int p, x; cin >> p >> x;
      ft.add(hld.query_point(p), x);
    } else {
      int v; cin >> v;
      auto [l, r] = hld.query_subtree(v);
      cout << ft.query(l, r) << '\n';
    }
  }

  return 0;
}
