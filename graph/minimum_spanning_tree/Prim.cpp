template<integral T>
auto Prim(int n, vector<tuple<int, int, T>> e, int s = 0) {
  constexpr T INF = numeric_limits<T>::max();
  auto weight = [&](int id) { return get<2>(e[id]); };

  e.emplace_back(0, 0, INF);

  vvi id(n, vi(n, ssize(e) - 1));
  for(int i = -1; auto [u, v, w] : e) {
    i++;
    if (w < weight(id[u][v]))
      id[u][v] = id[v][u] = i;
  }

  T cost = 0;
  vc<bool> vis(n, false);
  vi eid, mn_id = id[s];
  vis[s] = true;
  for(int i = 0; i < n - 1; i++) {
    int v = -1;
    T mn = INF;
    for(int x = 0; x < n; x++)
      if (!vis[x] and chmin(mn, weight(mn_id[x])))
        v = x;
    if (v == -1) break;
    vis[v] = true, cost += weight(mn_id[v]);
    eid.emplace_back(mn_id[v]);
    for(int x = 0; x < n; x++)
      if (weight(id[v][x]) < weight(mn_id[x]))
        mn_id[x] = id[v][x];
  }

  return pair(cost, eid);
}
