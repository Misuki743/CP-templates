//rake keep left child as exposed path
//compress keep left child as higher path
struct static_top_tree {
  vector<vector<int>> g;
  int n;
  vector<int> l, r, lc, rc, pa;
  vector<bool> rake;

  using a2 = array<int, 2>;

  static_top_tree(vector<vector<int>> &_g, int R = 0)
    : g(_g), n(size(g)), l(n, -1), r(l), lc(l), rc(l), pa(l), rake(n) {
    vector<int> sz(n, 1);
    auto dfs = [&](int v, int p, auto &self) -> void {
      l[v] = v, r[v] = p;
      int mx_c = -1;
      for(int x : g[v]) {
        if (x == p) continue;
        self(x, v, self);
        sz[v] += sz[x];
        if (mx_c == -1 or sz[x] > sz[mx_c])
          mx_c = x;
      }
      if (auto ite = ranges::find(g[v], p); ite != g[v].end())
        g[v].erase(ite);
      if (mx_c != -1)
        swap(g[v][0], *ranges::find(g[v], mx_c));
    };

    dfs(R, -1, dfs);
    build(R);
  }

  int new_node(int _lc, int _rc, int _l, int _r, bool _rake) {
    lc.eb(_lc), rc.eb(_rc), l.eb(_l), r.eb(_r), pa.eb(-1), rake.eb(_rake);
    return pa[_lc] = pa[_rc] = ssize(lc) - 1;
  }

  a2 build(int s) {
    vector<int> path = {s};
    while(!g[path.back()].empty())
      path.eb(g[path.back()][0]);
    vector<a2> exposed = {{0, s}};
    for(int i = 0; int v : path | views::drop(1)) {
      priority_queue<a2, vector<a2>, greater<a2>> pq;
      pq.push({0, v});
      for(int x : g[path[i++]] | views::drop(1))
        pq.push(build(x));
      while(ssize(pq) > 1) {
        auto [h1, v1] = pq.top(); pq.pop();
        auto [h2, v2] = pq.top(); pq.pop();
        if (v2 == v) swap(v1, v2);
        int v3 = new_node(v1, v2, l[v1], r[v1], true);
        pq.push({max(h1, h2) + 1, v3});
        if (v1 == v) v = v3;
      }
      exposed.eb(pq.top());
    }
    auto dc = [&](int ql, int qr, auto &self) -> a2 {
      if (ql + 1 == qr) return exposed[ql];
      int mid = (ql + qr) / 2;
      auto [hl, vl] = self(ql, mid, self);
      auto [hr, vr] = self(mid, qr, self);
      int v = new_node(vl, vr, l[vr], r[vl], false);
      return {max(hl, hr) + 1, v};
    };
    return dc(0, ssize(exposed), dc);
  }
};
