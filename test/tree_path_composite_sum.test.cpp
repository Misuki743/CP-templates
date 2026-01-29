#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../dp/rerooting_DP.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  vector<mint> a(n), b(n - 1), c(n - 1);
  for(mint &x : a) cin >> x;
  vector<array<int, 2>> e(n - 1);
  for(int i = 0; i < n - 1; i++)
    cin >> e[i][0] >> e[i][1] >> b[i] >> c[i];

  using V = array<mint, 2>;
  using E = array<mint, 2>;
  auto base = [&](int i) { return V{a[i], 1}; };
  auto add_edge = [&](const V &v, int i) { return E{b[i] * v[0] + c[i] * v[1], v[1]}; };
  auto op = [&](const E &l, const E &r) { return E{l[0] + r[0], l[1] + r[1]}; };
  auto add_vertex = [&](const E &e, int i) { return V{e[0] + a[i], e[1] + 1}; };

  auto ans = rerooting_DP<V, E>(e, base, add_edge, op, add_vertex);
  for(int i = 0; i < n; i++)
    cout << ans[i][0] << " \n"[i + 1 == n];

  return 0;
}
