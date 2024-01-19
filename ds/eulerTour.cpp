/**
 * template name: eulerTour
 * author: Misuki
 * last update: 2024/01/06
 * include: sparseTable, lazySegmentTree
 * verify: Library Checker - Vertex Add Path Sum
 * verify: Library Checker - Vertex Add Subtree Sum
 * note: monoid should be commutative, otherwise use HLD
 */

template<class M, class T, M(*Munit)(), T(*Tunit)(), M(*Mope)(const M&, const M&), T(*Tope)(const T&, const T&), M(*comp)(const M&, const T&), M(*inv)(const M&)>
struct eulerTour {
  using segTree = lazySegmentTree<M, T, Munit, Tunit, Mope, Tope, comp>;

  vector<int> tin, tout, p;
  sparseTable<array<int, 2>> st;
  segTree seg;

  vector<array<int, 2>> precalc(vector<vector<int>> &g, int root = 0) {
    vector<int> dep(ssize(g));
    vector<array<int, 2>> res;
    res.reserve(2 * ssize(g) - 1);
    auto dfs = [&](int v, auto self) -> void {
      tin[v] = ssize(res);
      res.push_back({dep[v], v});
      for(int x : g[v]) {
        if (x == p[v]) continue;
        dep[x] = dep[v] + 1, p[x] = v;
        self(x, self);
        res.push_back({dep[v], v});
      }
      tout[v] = ssize(res);
    };

    dfs(root, dfs);

    return res;
  }

  eulerTour(vector<vector<int>> &g, int root = 0) : tin(ssize(g)), tout(ssize(g)), p(ssize(g), -1),
  st(precalc(g, root), [](const array<int, 2> &l, const array<int, 2> &r) { return min(l, r); }), seg(2 * ssize(g) - 1) {}

  int lca(int u, int v) { return st.query(min(tin[u], tin[v]), max(tout[u], tout[v]))[1]; }

  //for point modify, path query, inversion of monoid is needed
  void modify(int v, T x) { seg.modify(tin[v], tout[v], x); }
  M query(int u, int v) {
    int tmp = lca(u, v);
    M res = Mope(seg.get(tin[u]), seg.get(tin[v]));
    res = Mope(res, inv(seg.get(tin[tmp])));
    if (p[tmp] != -1)
      res = Mope(res, inv(seg.get(tin[p[tmp]])));
    return res;
  }

  //for point modify, subtree query
  void modify2(int v, T x) { seg.modify(tin[v], tin[v] + 1, x); }
  M query2(int v) { return seg.query(tin[v], tout[v]); }
};
