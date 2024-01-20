#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../default/t.cpp"
#include "../ds/fastJump.cpp"
#include "../segtree/dualSegmentTree.cpp"
#include "../ds/eulerTour.cpp"

ll add(const ll &a, const ll &b) { return a + b; }
ll zero() { return 0ll; }
ll inv(const ll &x) { return -x; }

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<ll> a(n);
  for(ll &x : a)
    cin >> x;
  vector<vector<int>> g(n);
  for(int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  eulerTour<ll, ll, zero, zero, add, add, add, inv> eu(g);

  for(int v = 0; v < n; v++)
    eu.modify(v, a[v]);

  while(q--) {
    int t, x, y; cin >> t >> x >> y;
    if (t == 0)
      eu.modify(x, y);
    else
      cout << eu.query(x, y) << '\n';
  }

  return 0;
}
