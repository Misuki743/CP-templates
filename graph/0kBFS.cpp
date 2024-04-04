template<class T>
pair<vector<T>, vector<int>> BFS0k(vector<vector<pair<int, bool>>> &g, T k, int s) {
  int n = ssize(g);
  vector<T> dis(n, -1);
  vector<int> pre(n, -1);
  vector<bool> vis(n, false);
  deque<int> dq;

  dis[s] = 0;
  dq.push_back(s);

  while(!dq.empty()) {
    int v = dq.front(); dq.pop_front();
    if (vis[v]) continue;
    vis[v] = true;
    for(auto [x, w] : g[v]) {
      if (dis[x] == -1 or dis[v] + (w ? k : T(0)) < dis[x]) {
        dis[x] = dis[v] + (w ? k : T(0)), pre[x] = v;
        if (w) dq.push_back(x);
        else dq.push_front(x);
      }
    }
  }

  return make_pair(dis, pre);
}
