#define PROBLEM "https://judge.yosupo.jp/problem/incremental_scc"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../ds/DSU/DSU.cpp"
#include "../graph/connectivity/SCC.cpp"
#include "../graph/connectivity/incrementalSCC.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<mint> x(n);
  for(int i = 0; i < n; i++) cin >> x[i];
  vector<array<int, 2>> e(m);
  for(auto &[u, v] : e) cin >> u >> v;

  auto t = incrementalSCC(e, n);
  vector<mint> sum = x, cost(n, 0);
  DSU dsu(n);
  mint ans = 0;
  for(int i = 0, j = 0; i < m; i++) {
    while(j < ssize(t) and t[j][2] == i) {
      auto [u, v, _] = t[j++];
      u = dsu.query(u), v = dsu.query(v);
      mint sump = sum[u] + sum[v], costp = cost[u] + cost[v] + sum[u] * sum[v];
      ans += costp - (cost[u] + cost[v]);
      sum[u] = sum[v] = sump, cost[u] = cost[v] = costp;
      dsu.merge(u, v);
    }
    cout << ans << '\n';
  }

  return 0;
}

