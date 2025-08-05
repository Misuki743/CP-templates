template<class M, M(*id)(), M(*op)(const M&, const M&), bool edge = true>
struct commutative_path_composition {
  const int n, m;
  vector<vector<int>> jp, dat;
  vector<int> dep;

  commutative_path_composition(vector<vector<int>> &g, vector<int> init)
  : n(bit_width(size(g))), m(size(g)), jp(n, vector<int>(m, -1)), dat(n, vector(m, id())), dep(m) {
    auto dfs = [&](int v, auto &self) -> void {
      for(int x : g[v]) {
        if (x == jp[0][v]) continue;
        jp[0][x] = v, dep[x] = dep[v] + 1;
        self(x, self);
      }
    };
    dfs(0, dfs);

    dat[0] = init;
    for(int i = 1; i < n; i++)
      for(int j = 0; j < m; j++)
        if (jp[i - 1][j] != -1 and jp[i - 1][jp[i - 1][j]] != -1)
          jp[i][j] = jp[i - 1][jp[i - 1][j]], dat[i][j] = op(dat[i - 1][j], dat[i - 1][jp[i - 1][j]]);
  }

  M query(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    M res = id();
    for(int i = 0, dif = dep[u] - dep[v]; i < n; i++)
      if (dif >> i & 1)
        res = op(res, dat[i][u]), u = jp[i][u];
    if (u == v) return edge ? res : op(res, dat[0][u]);
    for(int i = n - 1; i >= 0; i--)
      if (jp[i][u] != jp[i][v])
        res = op(res, op(dat[i][u], dat[i][v])), u = jp[i][u], v = jp[i][v];
    return op(res, op(dat[0][u], dat[!edge][v]));
  }
};
