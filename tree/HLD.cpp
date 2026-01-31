struct HLD {
  static const int MSK = (1 << 30);
  vi dep, p_head, tin, tout;

  HLD(vvi g, int root = 0) {
    dep = p_head = tin = tout = vi(size(g));

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
        p_head[g[v][0]] = ((p_head[v] & MSK) ? v : p_head[v]);
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
  }

  auto query_path(int u, int v, bool edge = false) {
    vc<pii> lr;
    int head_u = ((p_head[u] & MSK) ? u : p_head[u]);
    int head_v = ((p_head[v] & MSK) ? v : p_head[v]);
    while(head_u != head_v) {
      if (dep[head_u] > dep[head_v])
        swap(u, v), swap(head_u, head_v);
      lr.emplace_back(tin[head_v], tin[v] + 1);
      v = (p_head[head_v] & (MSK - 1));
      head_v = ((p_head[v] & MSK) ? v : p_head[v]);
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
    int head_u = ((p_head[u] & MSK) ? u : p_head[u]);
    int head_v = ((p_head[v] & MSK) ? v : p_head[v]);
    while(head_u != head_v) {
      if (dep[head_u] > dep[head_v]) {
        lr1.emplace_back(tin[u] + 1, tin[head_u]);
        u = (p_head[head_u] & (MSK - 1));
        head_u = ((p_head[u] & MSK) ? u : p_head[u]);
      } else {
        lr2.emplace_back(tin[head_v], tin[v] + 1);
        v = (p_head[head_v] & (MSK - 1));
        head_v = ((p_head[v] & MSK) ? v : p_head[v]);
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

  template<class M>
  vc<M> reorder_init(vc<M> init) {
    assert(ssize(init) == ssize(dep));
    auto r = init;
    for(int i = 0; i < ssize(init); i++)
      r[tin[i]] = init[i];
    return r;
  }
};
