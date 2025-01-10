pair<vector<int>, vector<int>> BFS(vector<vector<int>> &g, int s) {
  int n = ssize(g);
  vector<int> dis(n, -1), pre(n, -1);
  vector<bool> vis(n, false);
  queue<int> q;

  dis[s] = 0;
  q.push(s);

  while(!q.empty()) {
    int v = q.front(); q.pop();
    if (vis[v]) continue;
    vis[v] = true;
    for(int x : g[v]) {
      if (dis[x] == -1) {
        dis[x] = dis[v] + 1, pre[x] = v;
        q.push(x);
      }
    }
  }

  return make_pair(dis, pre);
}
