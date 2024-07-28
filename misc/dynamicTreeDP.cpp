//#include "ds/staticTopTree.cpp"

template<class V, V(*base)(int), class E, E(*addEdge)(const V&, int eid),
E(*op)(const E&, const E&), V(*addVertex)(const E&, int vid), E(*rake)(const E&, const E&)>
struct dynamicTreeDP {
  int n;
  staticTopTree stt;
  vector<V> dpV;
  vector<E> dpE;

  dynamicTreeDP(vector<vector<int>> &g)
  : n(size(g)),stt(g), dpV(n), dpE(3 * n) {
    for(int v : stt.ord)
      update(v);
  }

  void update(int v) {
    if (auto type = stt.vt[v]; type == 0)
      dpV[v] = base(v);
    else if (type == 1)
      dpE[v - n] = op(dpE[stt.lc[v] - n], dpE[stt.rc[v] - n]);
    else if (type == 2)
      dpE[v - n] = rake(dpE[stt.rc[v] - n], dpE[stt.lc[v] - n]);
    else if (type == 3)
      dpE[v - n] = addEdge(dpV[stt.lc[v]], v - n);
    else if (type == 4)
      dpV[v] = addVertex(dpE[stt.lc[v] - n], v);
  }

  void pull(int v) {
    while(v != -1) {
      update(v);
      v = stt.p[v];
    }
  }

  void updateVertex(int v) { pull(v); }
  void updateEdge(int e) { pull(e + n); }
  E get() { return dpE[stt.stt_rt - n]; }
};
