array<vector<int>, 2> BFS(vector<vector<int>> &g, int s) {
  int n = ssize(g);
  vector<int> dis(n, -1), pre(n, -1);
  queue<int> q;

  dis[s] = 0;
  q.push(s);

  while(!q.empty()) {
    int v = q.front(); q.pop();
    for(int x : g[v]) {
      if (dis[x] != -1) continue;
      dis[x] = dis[v] + 1, pre[x] = v;
      q.push(x);
    }
  }

  return {dis, pre};
}
