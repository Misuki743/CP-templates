//#include<ds/fastJump.cpp>
//#include<segtree/dualSegmentTree.cpp>

template<class M, class T, M(*Munit)(), T(*Tunit)(), M(*Mope)(const M&, const M&), 
T(*Tope)(const T&, const T&), M(*comp)(const M&, const T&), M(*inv)(const M&)>
struct eulerTour {
  vector<int> tin, tout, p;
  dualSegmentTree<M, T, Munit, Tunit, Tope, comp> st;
  fastJump jp;

  eulerTour(vector<vector<int>> g, int root = 0) : tin(ssize(g)), tout(ssize(g)), p(ssize(g), -1), st(ssize(g)), jp(g, root) {
    int t = 0;
    auto dfs = [&](int v, auto self) -> void {
      tin[v] = t++;
      for(int x : g[v]) {
        if (x == p[v]) continue;
        p[x] = v;
        self(x, self);
      }
      tout[v] = t;
    };

    dfs(root, dfs);
  }

  //for point modify, path query, inversion of monoid is needed
  void modify(int v, T x) { st.modify(tin[v], tout[v], x); }
  M query(int u, int v) {
    int lca = jp.lca(u, v);
    M res = Mope(st.get(tin[u]), st.get(tin[v]));
    res = Mope(res, inv(st.get(tin[lca])));
    if (p[lca] != -1)
      res = Mope(res, inv(st.get(tin[p[lca]])));
    return res;
  }
};
