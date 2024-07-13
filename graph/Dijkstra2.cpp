template<class T>
vector<T> Dijkstra2(vector<vector<T>> &g, int s) {
  int n = ssize(g);
  vector<bool> vis(n, false);
  vector<T> dis(n, numeric_limits<T>::max());
  dis[s] = 0;
  while(true) {
    array<int, 2> dv = {numeric_limits<T>::max(), -1};
    for(int v = 0; v < n; v++)
      if (!vis[v])
        chmin(dv, {dis[v], v});
    int v = dv[1];
    if (v == -1) break;
    vis[v] = true;
    for(int x = 0; x < n; x++)
      if (g[v][x] != numeric_limits<T>::max())
        chmin(dis[x], dis[v] + g[v][x]);
  }
  return dis;
}
