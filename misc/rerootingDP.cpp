template<class V, V(*base)(int), class E, E(*addEdge)(const V&, int eid),
E(*op)(const E&, const E&), V(*addVertex)(const E&, int vid)>
vector<V> rerootingDP(vector<array<int, 2>> e) {
  int n = ssize(e) + 1;
  vector<vector<int>> g(n);
  for(int i = 0; auto [u, v] : e)
    g[u].emplace_back(i), g[v].emplace_back(i++);

  vector<V> data(n);
  for(int v = 0; v < n; v++) data[v] = base(v);
  auto precalc = [&](int v, int p, auto &&self) -> void {
    bool leaf = true;
    E prod;
    for(int eid : g[v]) {
      int x = e[eid][0] ^ e[eid][1] ^ v;
      if (x == p) continue;
      self(x, v, self);
      if (leaf)
        prod = addEdge(data[x], eid), leaf = false;
      else
        prod = op(prod, addEdge(data[x], eid));
    }
    if (!leaf) data[v] = addVertex(prod, v);
  };

  precalc(0, -1, precalc);

  vector<V> ret(n);
  auto reroot = [&](int v, int p, auto &&self) -> void {
    int deg = ssize(g[v]);
    vector<E> pre(deg), suf(deg);
    for(int i = 0; int eid : g[v]) {
      int x = e[eid][0] ^ e[eid][1] ^ v;
      pre[i] = suf[i] = addEdge(data[x], eid), i++;
    }
    for(int i = 1; i < deg; i++) pre[i] = op(pre[i - 1], pre[i]);
    for(int i = deg - 2; i >= 0; i--) suf[i] = op(suf[i], suf[i + 1]);
    V tmp = data[v];
    ret[v] = data[v] = (deg ? addVertex(suf[0], v) : base(v));
    for(int i = 0; int eid : g[v]) {
      int x = e[eid][0] ^ e[eid][1] ^ v;
      if (x != p) {
        bool leaf = true;
        E prod;
        if (i > 0) prod = pre[i - 1], leaf = false;
        if (i + 1 < deg) prod = (leaf ? suf[i + 1] : op(prod, suf[i + 1])), leaf = false;
        V tmp2 = data[v];
        data[v] = (leaf ? base(v) : addVertex(prod, v));
        self(x, v, self);
        data[v] = tmp2;
      }
      i++;
    }
    data[v] = tmp;
  };

  reroot(0, -1, reroot);

  return ret;
}
