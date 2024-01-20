//#include<segtree/segmentTree.cpp>

template<class M, M(*unit)(), M(*combine)(const M&, const M&)>
struct eulerTour2 {
  vector<int> tin, tout, p;
  segmentTree<M, unit, combine> st;

  eulerTour2(vector<vector<int>> g, int root = 0) : tin(ssize(g)), tout(ssize(g)), p(ssize(g), -1), st(ssize(g)) {
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

  void set(int v, M x) { st.set(tin[v], x); }
  M get(int v) { return st.get(tin[v]); }
  M query(int v) { return st.query(tin[v], tout[v]); }
};
