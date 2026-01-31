#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../default/t.cpp"
#include "../tree/HLD.cpp"
#include "../ds/fenwickTree.cpp"

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vll a(n);
  for(ll &x : a) cin >> x;
  auto g = read_graph<false>(n, n - 1, 0);

  HLD hld(g);
  fenwickTree ft(hld.reorder_init(a));
  while(q--) {
    int op; cin >> op;
    if (op == 0) {
      int p, x; cin >> p >> x;
      ft.add(hld.query_point(p), x);
    } else {
      int u, v; cin >> u >> v;
      ll sum = 0;
      assert(hld.query_path(u, v).size() <= 100);
      for(auto [l, r] : hld.query_path(u, v))
        sum += ft.query(l, r);
      cout << sum << '\n';
    }
  }

  return 0;
}
