#define PROBLEM "https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree"

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

  gp_hash_table<ll, int, custom_hash> toId({}, {}, {}, {}, {1 << 19});
  vector<vector<array<int, 2>>> cand(2 * n);
  vector<int> base(2 * n);
  vector<ll> init;
  init.reserve(1 << 19);
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

  adjacent_difference(init.begin(), init.end(), init.begin());
  fenwickTree<ll> ft(init);
  auto modify = [&](int v, int l, int r, int d) {
    int ql = base[v] + (R::lower_bound(cand[v], array<int, 2>{l, -1}) - cand[v].begin());
    int qr = base[v] + (R::lower_bound(cand[v], array<int, 2>{r, -1}) - cand[v].begin());
    ft.add(ql, d), ft.add(qr, -d);
  };

  while(q--) {
    int op; cin >> op;
    if (op == 0) {
      int x, l, r, d; cin >> x >> l >> r >> d;
      int v = x, pv = -1;
      while(v != -1) {
        int di = fj.dis(v, x);
        modify(v, l - di, r - di, d);
        if (pv != -1) {
          modify(pv + n, l - di, r - di, d);
        }
        pv = v, v = p[v];
      }
    } else {
      int x; cin >> x;
      int v = x, pv = -1;
      ll ans = 0;
      while(v != -1) {
        ans += ft.query(toId[(ll)x << 32 | v]);
        if (pv != -1)
          ans -= ft.query(toId[(ll)x << 32 | (pv + n)]);
        pv = v, v = p[v];
      }
      cout << ans << '\n';
    }
  }

  return 0;
}

