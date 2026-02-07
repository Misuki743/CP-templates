class tree {
  using i32 = int32_t;

  vc<i32> ord;

  public:

  int n, root;
  vc<int> p, sz, dep, jp;

  tree(vc<pii> e, int _root = 0) : n(size(e) + 1), root(_root) {
    vc<i32> d(n), adj(n);
    for(auto [u, v] : e)
      d[u]++, d[v]++, adj[u] ^= v, adj[v] ^= u;
    d[root] = 0;
    calc(d, adj);
  }

  tree(vi pa) : n(size(pa)) {
    root = ranges::find(pa, -1) - pa.begin();
    vc<i32> d(n), adj(n);
    for(int v = 0; v < n; v++)
      if (pa[v] != -1)
        d[v]++, d[pa[v]]++, adj[v] ^= pa[v], adj[pa[v]] ^= v;
    d[root] = 0;
    calc(d, adj);
  }

  void calc(vc<i32> d, vc<i32> adj) {
    sz = vi(n, 1);
    p = dep = jp = vi(n);

    ord.reserve(n - 1);
    for(int i = 0; i < n; i++) {
      int v = i;
      while(d[v] == 1) {
        ord.emplace_back(v);
        p[v] = adj[v], sz[p[v]] += sz[v];
        d[v] = 0, d[p[v]]--, adj[p[v]] ^= v;
        v = p[v];
      }
    }

    assert(ssize(ord) == n - 1);

    p[root] = jp[root] = root;
    for(i32 v : ord | views::reverse) {
      dep[v] = dep[p[v]] + 1;
      if (dep[p[v]] + dep[jp[jp[p[v]]]] == 2 * dep[jp[p[v]]])
        jp[v] = jp[jp[p[v]]];
      else
        jp[v] = p[v];
    }
  }

  int jump(int v, int k) {
    k = min(k, dep[v]);
    while(k) {
      if (int d = dep[v] - dep[jp[v]]; d <= k)
        v = jp[v], k -= d;
      else
        v = p[v], k -= 1;
    }
    return v;
  }

  int lca(int u, int v) {
    if (dep[u] < dep[v])
      swap(u, v);
    u = jump(u, dep[u] - dep[v]);
    if (u == v) return u;
    while(p[u] != p[v]) {
      if (jp[u] != jp[v]) u = jp[u], v = jp[v];
      else u = p[u], v = p[v];
    }
    return p[u];
  }

  int kth(int s, int t, int k) {
    int m = lca(s, t);
    if (dep[s] + dep[t] - 2 * dep[m] < k)
      return -1;
    else if (dep[s] - dep[m] >= k)
      return jump(s, k);
    else
      return jump(t, dep[s] + dep[t] - 2 * dep[m] - k);
  }

  int dis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
  }

  int median(int u, int v, int w) {
    return lca(u, v) ^ lca(u, w) ^ lca(v, w);
  }

  auto centroid() {
    array<int, 2> r = {-1, -1};
    vector<bool> ok(n, true);
    for(int v = 0; v < n; v++) {
      if (2 * (n - sz[v]) > n)
        ok[v] = false;
      if (v != root and 2 * sz[v] > n)
        ok[p[v]] = false;
    }
    for(int v = 0; v < n; v++)
      if (ok[v])
        r[1] = v, swap(r[0], r[1]);
    return r;
  }
};
