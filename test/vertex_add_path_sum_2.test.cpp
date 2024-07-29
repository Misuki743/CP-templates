#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../default/t.cpp"
#include "../ds/staticTopTree2.cpp"
#include "../ds/STT_pathAggregate.cpp"

ll id() { return 0ll; }
ll op(const ll &a, const ll &b) { return a + b; }

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<ll> a(n);
  for(ll &x : a) cin >> x;
  auto g = readGraph<false>(n, n - 1, 0);

  STT_pathAggregate<ll, id, op> stt(g, a);

  while(q--) {
    int op; cin >> op;
    if (op == 0) {
      int p, x; cin >> p >> x;
      stt.set(p, a[p] += x);
    } else {
      int u, v; cin >> u >> v;
      cout << stt.query(u, v) << '\n';
    }
  }

  return 0;
}
