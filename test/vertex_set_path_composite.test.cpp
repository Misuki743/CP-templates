#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "../default/t.cpp"
#include "../modint/MontgomeryModInt.cpp"
#include "../segtree/segmentTree.cpp"
#include "../actedmonoid/actedMonoid_affineSum.cpp"
#include "../tree/heavyLightDecomposition.cpp"

using am = actedMonoid_affineSum<mint>;

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<am::T> ab(n);
  for(auto &[a, b] : ab)
    cin >> a >> b;
  vector<vector<int>> g(n);
  for(int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  HLD hld(g);
  vector<am::T> init(n);
  for(int i = 0; i < n; i++)
    init[hld.id[i]] = ab[i];
  segmentTree<am::T, am::Tid, am::Top> st(init);
  ranges::reverse(init);
  segmentTree<am::T, am::Tid, am::Top> str(init);

  while(q--) {
    int t, a, b, c; cin >> t >> a >> b >> c;
    if (t == 0) {
      st.set(hld.id[a], am::T{b, c});
      str.set((n - 1) - hld.id[a], am::T{b, c});
    } else {
      auto res = am::T{0, c};
      for(auto [l, r, rev] : hld.query(a, b)) {
        if (rev)
          res = am::Top(res, str.query(n - r, n - l));
        else
          res = am::Top(res, st.query(l, r));
      }
      cout << res[1] << '\n';
    }
  }

  return 0;
}
