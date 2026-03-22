struct HLD {
  int n, root;
  vi dep, sz, p, head, tin, tout, inv_tin, child_list, c;
  vc<int32_t> lb;

  inline int head_parent(int v) const { return p[head[v]]; }

  HLD(vc<pii> e, int _root = 0) : root(_root) { precompute(e); }
  HLD(vi _p) {
    vc<pii> e;
    root = -1;
    for(int v = 0; v < ssize(_p); v++) {
      if (_p[v] == -1 or _p[v] == v)
        root = v;
      else
        e.eb(v, _p[v]);
    }
    assert(root != -1);
    precompute(e);
  }

  void precompute(vc<pii> &e) {
    n = ssize(e) + 1;

    dep = p = head = tin = tout = vi(n);
    sz = vi(n, 1);

    vi mx_child_sz(n, -1);
    {
      vi d(n);
      for(auto [u, v] : e)
        p[u] ^= v, p[v] ^= u, d[u]++, d[v]++;
      d[root] = 0;
      for(int i = 0; i < n; i++) {
        int v = i;
        while(d[v] == 1) {
          d[v] = 0, d[p[v]]--, p[p[v]] ^= v;
          sz[p[v]] += sz[v];
          chmax(mx_child_sz[p[v]], sz[v]);
          v = p[v];
        }
      }
      p[root] = root;
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
      head[root] = root, tout[root] = n;

      vi add(n, 1);
      for(int v : ord | views::drop(1)) {
        dep[v] = dep[p[v]] + 1;
        tin[v] = tin[p[v]] + add[p[v]];
        add[p[v]] += sz[v];
        tout[v] = tin[v] + sz[v];
        if (mx_child_sz[p[v]] == sz[v])
          mx_child_sz[p[v]] = 0, head[v] = head[p[v]];
        else
          head[v] = v;
      }
    }

    inv_tin = invPerm(tin);

    lb = vc<int32_t>(n + 1);
    child_list = vi(n + 1);
    for(int v = 0; v < n; v++)
      if (v != root)
        lb[p[v]]++;
    pSum(lb);
    for(int v = 0; v < n; v++)
      if (v != root and head[v] == v)
        child_list[--lb[p[v]]] = v;
    for(int v = 0; v < n; v++)
      if (v != root and head[v] != v)
        child_list[--lb[p[v]]] = v;
  }

  auto query_path(int u, int v, bool edge = false) {
    vc<pii> lr;
    while(head[u] != head[v]) {
      if (dep[head[u]] > dep[head[v]])
        swap(u, v);
      lr.emplace_back(tin[head[v]], tin[v] + 1);
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
    while(head[u] != head[v]) {
      if (dep[head[u]] > dep[head[v]]) {
        lr1.emplace_back(tin[u] + 1, tin[head[u]]);
        u = head_parent(u);
      } else {
        lr2.emplace_back(tin[head[v]], tin[v] + 1);
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
    while(head[u] != head[v]) {
      if (dep[head[u]] > dep[head[v]])
        swap(u, v);
      v = head_parent(v);
    }
    return tin[u] < tin[v] ? u : v;
  }

  int dis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
  }

  int kth(int s, int t, int k) {
    int l = lca(s, t);
    if (int d = dep[s] + dep[t] - 2 * dep[l]; k > d)
      return -1;
    else if (k > dep[s] - dep[l])
      k = d - k, swap(s, t);
    while(k > dep[s] - dep[head[s]]) {
      k -= dep[s] - dep[head[s]] + 1;
      s = head_parent(s);
    }
    return inv_tin[tin[s] - k];
  }

  int median(int u, int v, int w) {
    return lca(u, v) ^ lca(u, w) ^ lca(v, w);
  }

  template<class M>
  vc<M> reorder_init(vc<M> init) {
    assert(ssize(init) == ssize(dep));
    auto r = init;
    for(int i = 0; i < ssize(init); i++)
      r[tin[i]] = init[i];
    return r;
  }

  const span<int> childs(int v) {
    return span(child_list.begin() + lb[v], lb[v + 1] - lb[v]);
  }
  const span<int> light_childs(int v) {
    return span(child_list.begin() + lb[v] + 1, max(lb[v + 1] - lb[v] - 1, 0));
  }
  inline int heavy_child(int v) {
    return lb[v] == lb[v + 1] ? -1 : child_list[lb[v]];
  }
  inline int parent(int v) {
    return p[v];
  }

  inline int depth(int v) { return dep[v]; }
  inline int size(int v) { return sz[v]; }
  bool in_subtree_of(int a, int b) { return tin[b] <= tin[a] and tout[a] <= tout[b]; }
  const span<int> centroid() {
    if (c.empty()) {
      vc<bool> ok(n, true);
      for(int v = 0; v < n; v++) {
        if (2 * (n - sz[v]) > n)
          ok[v] = false;
        if (v != root and 2 * sz[v] > n)
          ok[p[v]] = false;
      }
      for(int v = 0; v < n; v++)
        if (ok[v])
          c.eb(v);
    }
    return c;
  }
};
