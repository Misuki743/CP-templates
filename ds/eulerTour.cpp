//#include<ds/fastJump.cpp>
//#include<segtree/dualSegmentTree.cpp>

template<class M, class T, M(*Mid)(), T(*Tid)(), M(*Mop)(const M&, const M&), 
T(*Top)(const T&, const T&), M(*comp)(const M&, const T&), M(*Minv)(const M&)>
struct eulerTour {
  vector<int> tin, tout, p;
  dualSegmentTree<M, Mid, T, Tid, Top, comp> st;
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
    M res = Mop(st.get(tin[u]), st.get(tin[v]));
    res = Mop(res, Minv(st.get(tin[lca])));
    if (p[lca] != -1)
      res = Mop(res, Minv(st.get(tin[p[lca]])));
    return res;
  }
};
