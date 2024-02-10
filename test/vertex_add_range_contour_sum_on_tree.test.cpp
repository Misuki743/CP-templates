#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree"

#include <bits/extc++.h>
#include "../default/t.cpp"
#include "../ds/pbdsSet.cpp"
#include "../ds/fenwickTree.cpp"
#include "../ds/fastJump.cpp"

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(int &x : a)
    cin >> x;
  vector<vector<int>> g(n);
  for(int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  auto [g2, r] = centroidTree(g);

  vector<int> p(n, -1);
  auto dfs = [&](int v, auto self) -> void {
    for(int x : g2[v]) {
      if (x == p[v]) continue;
      p[x] = v;
      self(x, self);
    }
  };
  dfs(r, dfs);

  gp_hash_table<ll, int, custom_hash> toId;
  vector<vector<array<int, 2>>> cand(2 * n);
  vector<int> base(2 * n);
  vector<ll> init;
  fastJump fj(g);
  for(int s = 0; s < n; s++) {
    auto dfs = [&](int v, auto self) -> void {
      cand[s].push_back({fj.dis(s, v), v});
      if (p[s] != -1)
        cand[s + n].push_back({fj.dis(p[s], v), v});
      for(int x : g2[v]) {
        if (x == p[v]) continue;
        self(x, self);
      }
    };
    dfs(s, dfs);
    for(int d : {0, n}) {
      base[s + d] = ssize(init);
      R::sort(cand[s + d]);
      for(auto [_, v] : cand[s + d]) {
        toId[(ll)v << 32 | (s + d)] = ssize(init);
        init.emplace_back(a[v]);
      }
    }
  }

  fenwickTree<ll> ft(init);
  auto query = [&](int v, int l, int r) {
    int ql = base[v] + (R::lower_bound(cand[v], array<int, 2>{l, -1}) - cand[v].begin());
    int qr = base[v] + (R::lower_bound(cand[v], array<int, 2>{r, -1}) - cand[v].begin());
    return ft.query(ql, qr);
  };

  while(q--) {
    int op; cin >> op;
    if (op == 0) {
      int x, d; cin >> x >> d;
      int v = x;
      while(v != -1) {
        ft.add(toId[(ll)x << 32 | v], d);
        if (p[v] != -1)
          ft.add(toId[(ll)x << 32 | (v + n)], d);
        v = p[v];
      }
    } else {
      int x, l, r; cin >> x >> l >> r;
      int v = x, pv = -1;
      ll ans = 0;
      while(v != -1) {
        int d = fj.dis(v, x);
        ans += query(v, l - d, r - d);
        if (pv != -1)
          ans -= query(pv + n, l - d, r - d);
        pv = v, v = p[v];
      }

      cout << ans << '\n';
    }
  }

  return 0;
}
