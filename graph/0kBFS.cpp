pair<vector<int>, vector<int>> BFS01(vector<vector<pair<int, bool>>> &g, int s) {
  int n = ssize(g);
  vector<int> dis(n, INT_MAX), pre(n, -1);
  deque<int> dq;

  dis[s] = 0;
  dq.push_back(s);

  while(!dq.empty()) {
    int v = dq.front(); dq.pop_front();
    for(auto [x, w] : g[v]) {
      if (dis[v] + w < dis[x]) {
        dis[x] = dis[v] + w, pre[x] = v;
        if (w) dq.push_back(x);
        else dq.push_front(x);
      }
    }
  }

  return make_pair(dis, pre);
}
