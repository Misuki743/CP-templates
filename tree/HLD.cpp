struct HLD {
  static const int MSK = (1 << 30);
  vi dep, p_head, tin, tout, inv_tin;

  inline int head(int v) const { return (p_head[v] & MSK) ? v : p_head[v]; }
  inline int head_parent(int v) const { return p_head[head(v)] & (MSK - 1); }

  HLD(vvi g, int root = 0) {
    dep = p_head = tin = tout = inv_tin = vi(size(g));

    vi sz(size(g), 1);
    auto dfs = [&](int v, auto &self) -> void {
      int mx_id = -1, p_id = -1;
      for(int i = -1; int x : g[v]) {
        i++;
        if ((x | MSK) == p_head[v]) {
          p_id = i;
        } else {
          p_head[x] = (v | MSK), dep[x] = dep[v] + 1;
          self(x, self);
          sz[v] += sz[x];
          if (mx_id == -1 or sz[x] > sz[g[v][mx_id]])
            mx_id = i;
        }
      }
      if (mx_id != -1) swap(g[v][p_id == 0], g[v][mx_id]);
      if (p_id != -1) g[v].erase(g[v].begin() + p_id);
    };

    p_head[root] = (root | MSK);
    dfs(root, dfs);

    int nxt = 0;
    auto dfs2 = [&](int v, auto &self) -> void {
      tin[v] = nxt++;
      if (!g[v].empty())
        p_head[g[v][0]] = head(v);
      if (!g[v].empty()) {
        vi sz_seq;
        for(int x : g[v]) sz_seq.eb(sz[x]);
        assert(ranges::max(sz_seq) == sz_seq[0]);
      }
      for(int x : g[v])
        self(x, self);
      tout[v] = nxt;
    };

    dfs2(root, dfs2);

    inv_tin = invPerm(tin);
  }

  auto query_path(int u, int v, bool edge = false) {
    vc<pii> lr;
    while(head(u) != head(v)) {
      if (dep[head(u)] > dep[head(v)])
        swap(u, v);
      lr.emplace_back(tin[head(v)], tin[v] + 1);
      v = head_parent(v);
    }

    if (tin[u] > tin[v]) swap(u, v);
    if (tin[u] + edge <= tin[v])
      lr.emplace_back(tin[u] + edge, tin[v] + 1);

    return lr;
  }

  //l < r: op(l, op(l + 1, ...))
  //l > r: op(r - 1, op(r - 2, ...))
  auto query_path_non_commutative(int u, int v, bool edge = false) {
    vc<pii> lr1, lr2;
    while(head(u) != head(v)) {
      if (dep[head(u)] > dep[head(v)]) {
        lr1.emplace_back(tin[u] + 1, tin[head(u)]);
        u = head_parent(u);
      } else {
        lr2.emplace_back(tin[head(v)], tin[v] + 1);
        v = head_parent(v);
      }
    }

    if (tin[u] + edge <= tin[v])
      lr2.emplace_back(tin[u] + edge, tin[v] + 1);
    else if (tin[v] + edge <= tin[u])
      lr1.emplace_back(tin[u] + 1, tin[v] + edge);

    lr1.insert(end(lr1), lr2.rbegin(), lr2.rend());

    return lr1;
  }

  auto query_subtree(int v) { return pii(tin[v], tout[v]); }

  int query_point(int v) { return tin[v]; }

  int lca(int u, int v) {
    while(head(u) != head(v)) {
      if (dep[head(u)] > dep[head(v)])
        swap(u, v);
      v = head_parent(v);
    }
    return tin[u] < tin[v] ? u : v;
  }

  int kth(int s, int t, int k) {
    int l = lca(s, t);
    if (int d = dep[s] + dep[t] - 2 * dep[l]; k > d)
      return -1;
    else if (k > dep[s] - dep[l])
      k = d - k, swap(s, t);
    while(k > dep[s] - dep[head(s)]) {
      k -= dep[s] - dep[head(s)] + 1;
      s = head_parent(s);
    }
    return inv_tin[tin[s] - k];
  }

  template<class M>
  vc<M> reorder_init(vc<M> init) {
    assert(ssize(init) == ssize(dep));
    auto r = init;
    for(int i = 0; i < ssize(init); i++)
      r[tin[i]] = init[i];
    return r;
  }
};
