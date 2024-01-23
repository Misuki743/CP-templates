template<class T>
pair<vector<T>, vector<int>> Dijkstra(vector<vector<pair<int, T>>> &g, int s) {
  int n = ssize(g);
  vector<T> dis(n, -1);
  vector<int> pre(n, -1);
  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;

  dis[s] = 0;
  pq.push({0, s});

  while(!pq.empty()) {
    auto [d, v] = pq.top(); pq.pop();
    if (dis[v] != d) continue;
    for(auto [x, w] : g[v]) {
      if (dis[x] != -1 and d + w >= dis[x]) continue;
      dis[x] = d + w, pre[x] = v;
      pq.push(make_pair(d + w, x));
    }
  }

  return make_pair(dis, pre);
}

vector<int> recover(vector<int> &pre, int t) {
  if (pre[t] == -1) return {};
  vector<int> path(1, t);
  while(pre[t] != -1)
    path.emplace_back(t = pre[t]);
  R::reverse(path);
  return path;
}
