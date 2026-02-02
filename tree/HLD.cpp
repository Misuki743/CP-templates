struct HLD {
  static const int MSK = (1 << 30);
  vi dep, p_head, tin, tout, inv_tin;

  inline int head(int v) const { return (p_head[v] & MSK) ? v : p_head[v]; }
  inline int head_parent(int v) const { return p_head[head(v)] & (MSK - 1); }

  HLD(vc<pii> e, int root = 0) {
    const int n = ssize(e) + 1;

    dep = p_head = tin = tout = vi(n);

    vi sz(n, 1), mx_child_sz(n, -1);
    {
      vi d(n);
      for(auto [u, v] : e)
        p_head[u] ^= v, p_head[v] ^= u, d[u]++, d[v]++;
      d[root] = 0;
      for(int i = 0; i < n; i++) {
        int v = i;
        while(d[v] == 1) {
          d[v] = 0, d[p_head[v]]--, p_head[p_head[v]] ^= v;
          sz[p_head[v]] += sz[v];
          chmax(mx_child_sz[p_head[v]], sz[v]);
          v = p_head[v];
        }
      }
    }

    vi ord(n);
    {
      vi f(n + 2);
      for(int x : sz) f[x + 1]++;
      pSum(f);
      for(int v = 0; v < n; v++)
        ord[n - 1 - (f[sz[v]]++)] = v;
    }

    {
      p_head[root] = (root | MSK), tout[root] = n;

      vi add(n, 1);
      for(int v : ord | views::drop(1)) {
        dep[v] = dep[p_head[v]] + 1;
        tin[v] = tin[p_head[v]] + add[p_head[v]];
        add[p_head[v]] += sz[v];
        tout[v] = tin[v] + sz[v];
        if (mx_child_sz[p_head[v]] == sz[v])
          mx_child_sz[p_head[v]] = 0, p_head[v] = head(p_head[v]);
        else
          p_head[v] |= MSK;
      }
    }

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
