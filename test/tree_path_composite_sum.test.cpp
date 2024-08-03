#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../dp/rerootingDP.cpp"

using V = array<mint, 2>;
using E = array<mint, 2>;

vector<mint> a, b, c;

V base(int i) { return {a[i], 1}; }
E addEdge(const V &v, int i) { return {b[i] * v[0] + c[i] * v[1], v[1]}; }
E op(const E &l, const E &r) { return {l[0] + r[0], l[1] + r[1]}; }
V addVertex(const E &e, int i) { return {e[0] + a[i], e[1] + 1}; }

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n; cin >> n;
  a.resize(n);
  for(mint &x : a) cin >> x;
  vector<array<int, 2>> e(n - 1);
  b.resize(n - 1), c.resize(n - 1);
  for(int i = 0; i < n - 1; i++)
    cin >> e[i][0] >> e[i][1] >> b[i] >> c[i];

  auto ans = rerootingDP<V, base, E, addEdge, op, addVertex>(e);
  for(int i = 0; i < n; i++)
    cout << ans[i][0] << " \n"[i + 1 == n];

  return 0;
}
