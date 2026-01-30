template<integral T>
auto Bellman_Ford(const int n, vc<tuple<int, int, T>> &e, vi s) {
  constexpr T INF = numeric_limits<T>::max();
  constexpr T NINF = numeric_limits<T>::min();

  vc<T> dis(n, INF);
  vi pre(n, -1);
  for(int v : s)
    dis[v] = 0, pre[v] = v;

  for(int iter = 0; ; iter++) {
    bool done = true;
    for(auto [u, v, w] : e) {
      if (dis[u] == INF) continue;
      if (dis[u] == NINF and dis[v] != NINF) {
        pre[v] = u, dis[v] = NINF, done = false;
      } else if (chmin(dis[v], dis[u] + w)) {
        pre[v] = u, done = false;
        if (iter >= n) dis[v] = NINF;
      }
    }
    if (done) break;
  }

  return pair(dis, pre);
}
