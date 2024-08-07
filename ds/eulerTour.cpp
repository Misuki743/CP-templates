//#include<ds/RMQ.cpp>
//#include<ds/LCA.cpp>
//#include<segtree/dualSegmentTree.cpp>

template<class M, M(*Mid)(), M(*Mop)(const M&, const M&), M(*Minv)(const M&), 
class T, T(*Tid)(), T(*Top)(const T&, const T&), M(*act)(const M&, const T&)>
struct eulerTour {
  vector<int> tin, tout, p;
  dualSegmentTree<M, Mid, T, Tid, Top, act> st;
  LCA lc;

  eulerTour(vector<vector<int>> g, int root = 0) : tin(ssize(g)), tout(ssize(g)), p(ssize(g), -1), st(ssize(g)), lc(g, root) {
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
    int Lca = lc.lca(u, v);
    M res = Mop(st.get(tin[u]), st.get(tin[v]));
    res = Mop(res, Minv(st.get(tin[Lca])));
    if (p[Lca] != -1)
      res = Mop(res, Minv(st.get(tin[p[Lca]])));
    return res;
  }
};
