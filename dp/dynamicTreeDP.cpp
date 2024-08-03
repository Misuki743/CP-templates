//#include "ds/staticTopTree.cpp"

template<class T, T(*vertex)(int), T(*addEdge)(const T&, int eid),
T(*rake)(const T&, const T&), T(*addVertex)(const T&, int vid), T(*compress)(const T&, const T&)>
struct dynamicTreeDP {
  int n;
  staticTopTree stt;
  vector<T> dp;

  dynamicTreeDP(vector<vector<int>> &g)
  : n(size(g)),stt(g), dp(4 * n) {
    for(int v : stt.ord)
      update(v);
  }

  void update(int v) {
    if (auto type = stt.vt[v]; type == 0)
      dp[v] = vertex(v);
    else if (type == 1)
      dp[v] = rake(dp[stt.lc[v]], dp[stt.rc[v]]);
    else if (type == 2)
      dp[v] = compress(dp[stt.rc[v]], dp[stt.lc[v]]);
    else if (type == 3)
      dp[v] = addEdge(dp[stt.lc[v]], v - n);
    else if (type == 4)
      dp[v] = addVertex(dp[stt.lc[v]], v);
  }

  void pull(int v) {
    while(v != -1) {
      update(v);
      v = stt.p[v];
    }
  }

  void updateVertex(int v) { pull(v); }
  void updateEdge(int e) { pull(e + n); }
  T get() { return dp[stt.stt_rt]; }
};
