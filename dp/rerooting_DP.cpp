template<typename R, typename F, typename... Args>
concept R_invocable = requires(F&& f, Args&&... args) {
  { std::invoke(std::forward<F>(f), std::forward<Args>(args)...) } -> std::same_as<R>;
};

template<class V, class E, typename BASE, typename ADD_EDGE, typename OP, typename ADD_VERTEX>
requires
  R_invocable<V, BASE, int> &&
  R_invocable<E, ADD_EDGE, const V, int> &&
  R_invocable<E, OP, const E, const E> &&
  R_invocable<V, ADD_VERTEX, const E, int>
vector<V> rerooting_DP(vector<array<int, 2>> e, BASE base, ADD_EDGE add_edge, OP op, ADD_VERTEX add_vertex) {
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
        prod = add_edge(data[x], eid), leaf = false;
      else
        prod = op(prod, add_edge(data[x], eid));
    }
    if (!leaf) data[v] = add_vertex(prod, v);
  };

  precalc(0, -1, precalc);

  vector<V> ret(n);
  auto reroot = [&](int v, int p, auto &&self) -> void {
    int deg = ssize(g[v]);
    vector<E> pre(deg), suf(deg);
    for(int i = 0; int eid : g[v]) {
      int x = e[eid][0] ^ e[eid][1] ^ v;
      pre[i] = suf[i] = add_edge(data[x], eid), i++;
    }
    for(int i = 1; i < deg; i++) pre[i] = op(pre[i - 1], pre[i]);
    for(int i = deg - 2; i >= 0; i--) suf[i] = op(suf[i], suf[i + 1]);
    V tmp = data[v];
    ret[v] = data[v] = (deg ? add_vertex(suf[0], v) : base(v));
    for(int i = 0; int eid : g[v]) {
      int x = e[eid][0] ^ e[eid][1] ^ v;
      if (x != p) {
        bool leaf = true;
        E prod;
        if (i > 0) prod = pre[i - 1], leaf = false;
        if (i + 1 < deg) prod = (leaf ? suf[i + 1] : op(prod, suf[i + 1])), leaf = false;
        V tmp2 = data[v];
        data[v] = (leaf ? base(v) : add_vertex(prod, v));
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
