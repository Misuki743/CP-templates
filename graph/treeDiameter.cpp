template<class T>
tuple<T, T, T, vector<int>> treeDiameter(vector<vector<pair<int, T>>> &g) {
  const T inf = numeric_limits<T>::max();
  const int n = ssize(g);
  auto bfs = [&](int s) {
    vector<T> dis(n, inf);
    vector<int> pre(n, -1);
    queue<int> q;
    dis[s] = 0;
    q.push(s);
    while(!q.empty()) {
      int v = q.front(); q.pop();
      for(auto [x, w] : g[v]) {
        if (dis[x] != inf) continue;
        pre[x] = v, dis[x] = dis[v] + w;
        q.push(x);
      }
    }
    return make_pair(dis, pre);
  };

  auto dis0 = bfs(0).first;
  int u = ranges::max_element(dis0) - dis0.begin();
  auto [dis1, pre1] = bfs(u);
  int v = ranges::max_element(dis1) - dis1.begin();
  T d = dis1[v];

  vector<int> diameter(1, v);
  while(pre1[v] != -1)
    diameter.emplace_back(v = pre1[v]);

  int radius = inf, center = -1;
  for(int y : diameter)
    if (int x = max(dis1[y], d - dis1[y]); x < radius)
      radius = x, center = y;

  return make_tuple(d, radius, center, diameter);
}
