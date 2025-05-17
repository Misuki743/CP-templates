#define PROBLEM "https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root"

#include "../default/t.cpp"
#define eb emplace_back
#define pb push_back
#include "../modint/MontgomeryModInt.cpp"
#include "../ds/staticTopTree.cpp"
#include "../dp/dynamicTreeDP.cpp"

struct M {
  mint a, b, ans, sz;
};

M rake(const M &a, const M &b) {
  return M{a.a, a.b, a.ans + b.ans, a.sz + b.sz};
}
M compress(const M &a, const M &b) {
  return M{a.a * b.a, a.a * b.b + a.b, a.ans + b.ans * a.a + a.b * b.sz, a.sz + b.sz};
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<mint> a(n);
  for(mint &x : a) cin >> x;

  vector<array<int, 4>> uvbc(n - 1);
  for(auto &[u, v, b, c] : uvbc)
    cin >> u >> v >> b >> c;

  vector<vector<int>> g(n);
  for(auto [u, v, _, __] : uvbc)
    g[u].eb(v), g[v].eb(u);
  uvbc.pb({-1, 0, 1, 0});

  static_top_tree stt(g);

  vector<int> eid(n);
  for(int i = 0; auto &[u, v, _, __] : uvbc) {
    if (stt.r[v] == u) swap(u, v);
    eid[u] = i++;
  }

  auto get = [&](int v) {
    auto [_, __, b, c] = uvbc[eid[v]];
    return M{b, c, a[v] * b + c, 1};
  };

  vector<M> init(n);
  for(int i = 0; i < n; i++)
    init[i] = get(i);

  dynamic_tree_dp<M, rake, compress> ddp(g, init);

  while(q--) {
    int op; cin >> op;
    if (op == 0) {
      int w, x; cin >> w >> x;
      a[w] = x;
      ddp.set(w, get(w));
    } else {
      int e, y, z; cin >> e >> y >> z;
      auto &[u, _, b, c] = uvbc[e];
      b = y, c = z;
      ddp.set(u, get(u));
    }
    cout << ddp.query().ans << '\n';
  }

  return 0;
}
