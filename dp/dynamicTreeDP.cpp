//#include "ds/staticTopTree.cpp"
template<class M, M(*rake)(const M&, const M&), M(*compress)(const M&, const M&)>
struct dynamic_tree_dp {
  vector<M> dp;
  static_top_tree stt;

  void pull(int v) {
    if (stt.rake[v]) dp[v] = rake(dp[stt.lc[v]], dp[stt.rc[v]]);
    else dp[v] = compress(dp[stt.lc[v]], dp[stt.rc[v]]);
  }

  dynamic_tree_dp(vector<vector<int>> &g, vector<M> &init)
    : dp(2 * ssize(g) - 1), stt(g) {
    for(int i = 0; i < ssize(g); i++)
      dp[i] = init[i];
    for(int i = ssize(g); i < 2 * ssize(g) - 1; i++)
      pull(i);
  }

  void set(int v, M x) {
    dp[v] = x;
    while((v = stt.pa[v]) != -1) pull(v);
  }

  M query() { return dp.back(); }
};
