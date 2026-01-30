template<integral T>
auto Dijkstra_sparse(vvc<pair<int, T>> &g, vi s) {
  constexpr T INF = numeric_limits<T>::max();
  const int n = ssize(g);

  vc<T> dis(n, INF);
  vi pre(n, -1);
  auto cmp = [](pair<T, int> &a, pair<T, int> &b) { return a.first > b.first; };
  priority_queue<pair<T, int>, vc<pair<T, int>>, decltype(cmp)> pq(cmp, [&]() {
    vc<pair<T, int>> init(size(s));
    for(int i = 0; int v : s) {
      dis[v] = 0, pre[v] = v;
      init[i++] = pair(T(0), v);
    }
    return init;
  }());

  while(!pq.empty()) {
    auto [d, v] = pq.top(); pq.pop();
    if (dis[v] != d) continue;
    for(auto [x, w] : g[v]) {
      if (chmin(dis[x], d + w)) {
        pre[x] = v;
        pq.emplace(dis[x], x);
      }
    }
  }

  return pair(dis, pre);
}

template<integral T>
auto Dijkstra_dense(vvc<T> &adj, vi s) {
  constexpr T INF = numeric_limits<T>::max();
  const int n = ssize(adj);

  vc<T> dis(n, INF);
  vi pre(n, -1);
  for(int v : s)
    dis[v] = 0, pre[v] = v;

  vc<bool> vis(n, false);
  for(int iter = 0; iter < n; iter++) {
    T d = INF;
    int v = -1;
    for(int u = 0; u < n; u++)
      if (!vis[u] and chmin(d, dis[u]))
        v = u;
    if (v == -1) break;
    vis[v] = true;
    for(int x = 0; x < n; x++)
      if (adj[v][x] != INF and chmin(dis[x], dis[v] + adj[v][x]))
        pre[x] = v;
  }

  return pair(dis, pre);
}
