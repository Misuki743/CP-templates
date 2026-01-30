template<integral T>
auto BFS_01(vvc<pair<int, T>> &g, vi s) {
  const int n = ssize(g);
  constexpr T INF = numeric_limits<T>::max();

  vc<T> dis(n, INF);
  vi pre(n, -1);
  deque<int> dq(s.begin(), s.end());
  for(int v : s)
    dis[v] = 0, pre[v] = v;

  while(!dq.empty()) {
    int v = dq.front(); dq.pop_front();
    for(auto [x, w] : g[v]) {
      if (chmin(dis[x], dis[v] + w)) {
        pre[x] = v;
        if (w) dq.push_back(x);
        else dq.push_front(x);
      }
    }
  }

  return pair(dis, pre);
}

vi recover(vi &pre, int t) {
  if (pre[t] == -1) return {};
  vi path = {t};
  while(pre[path.back()] != path.back())
    path.emplace_back(pre[path.back()]);
  ranges::reverse(path);
  return path;
}
