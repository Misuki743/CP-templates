#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "../default/t.cpp"
#include "../ds/fastJump.cpp"
#include "../segtree/segmentTree.cpp"
#include "../ds/eulerTour2.cpp"

ll unit() { return 0ll; }
ll add(const ll &a, const ll &b) { return a + b; }

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<ll> a(n);
  for(ll &x : a)
    cin >> x;
  vector<vector<int>> g(n);
  for(int u = 1; u < n; u++) {
    int v; cin >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  eulerTour2<ll, unit, add> eu(g);

  for(int v = 0; v < n; v++)
    eu.set(v, a[v]);

  while(q--) {
    int t; cin >> t;
    if (t == 0) {
      int x, y; cin >> x >> y;
      eu.set(x, eu.get(x) + y);
    } else {
      int x; cin >> x;
      cout << eu.query(x) << '\n';
    }
  }

  return 0;
}
