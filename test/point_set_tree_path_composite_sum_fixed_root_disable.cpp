#define PROBLEM "https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../ds/staticTopTree.cpp"
#include "../dp/dynamicTreeDP.cpp"

using V = array<mint, 2>;
using E = array<mint, 4>;

vector<mint> a, b, c;

V base(int i) { return {a[i], 1}; }
E addEdge(const V &v, int i) { return {b[i] * v[0] + c[i] * v[1], v[1], b[i], c[i]}; }
E op(const E &l, const E &r) { return {l[0] + r[0], l[1] + r[1], 0, 0}; }
V addVertex(const E &e, int i) { return {e[0] + a[i], e[1] + 1}; }
E compress(const E &l, const E &r) {
  auto [c, d, i, j] = l;
  auto [e, f, g, h] = r;
  return {c * g + d * h + e, d + f, i * g, (j * g + h)};
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  a.resize(n);
  for(mint &x : a) cin >> x;
  vector<array<int, 4>> e(n - 1);
  for(auto &[u, v, b, c] : e)
    cin >> u >> v >> b >> c;

  vector<vector<int>> g(n);
  for(auto [u, v, _, __] : e) {
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  vector<int> dep(n);
  auto dfs = [&](int v, int p, auto &&self) -> void {
    for(int x : g[v]) if (x != p) {
      dep[x] = dep[v] + 1;
      self(x, v, self);
    }
  };
  dfs(0, -1, dfs);

  b.resize(n, 1), c.resize(n);
  for(auto &[u, v, bb, cc] : e) {
    if (dep[u] > dep[v]) swap(u, v);
    b[v] = bb, c[v] = cc;
  }

  dynamicTreeDP<V, base, E, addEdge, op, addVertex, compress> ddp(g);

  while(q--) {
    int op; cin >> op;
    if (op == 0) {
      int w, x; cin >> w >> x;
      a[w] = x;
      ddp.updateVertex(w);
    } else if (op == 1) {
      int i, y, z; cin >> i >> y >> z;
      int id = e[i][1];
      b[id] = y, c[id] = z;
      ddp.updateEdge(id);
    }
    cout << ddp.get()[0] << '\n';
  }

  return 0;
}
