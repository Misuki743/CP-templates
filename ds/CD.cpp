struct CentroidDecomposition {
  vector<bool> vis;
  vector<int> sz;
  vector<vector<int>> G;

  CentroidDecomposition(vector<vector<int>> &g) : G(g), sz(g.size()), vis(g.size(), false) {}

  int calc(int V, int P) {
    sz[V] = 1;
    for(int X : G[V])
      if (X != P and !vis[X])
        sz[V] += calc(X, V);
    return sz[V];
  }

  void dfs(int V, int P, int dep, vector<int> &cnt) {
    if (dep >= (int)cnt.size())
      cnt.emplace_back();
    cnt[dep] += 1;
    for(int X : G[V])
      if (X != P and !vis[X])
        dfs(X, V, dep + 1, cnt);
  }

  void CD(int V) {
    calc(V, -1);

    int C = V, P = -1;
    bool move = true;
    do {
      move = false;
      for(int X : G[C]) {
        if (X != P and !vis[X] and sz[X] * 2 > sz[V]) {
          move = true, P = C, C = X;
          break;
        }
      }
    } while(move);

    vis[C] = true;

    for(int X : G[C])
      if (!vis[X])
        CD(X);
  }
};
