template<class T>
pair<T, vector<int>> steiner_tree(int n, vector<int> s, vector<tuple<int, int, T>> e) {
  int k = 0;
  {
    vector<bool> in_s(n, false);
    for(int x : s) in_s[x] = true;
    for(int v = 0; v < n; v++) k += in_s[v];
    vector<int> f(n);
    int nxt = 0;
    for(bool x : {true, false})
      for(int v = 0; v < n; v++)
        if (in_s[v] == x)
          f[v] = nxt++;
    for(auto &[u, v, _] : e)
      u = f[u], v = f[v];
  }

  vector<vector<tuple<int, int, T>>> g(n);
  for(int i = 0; auto [u, v, w] : e) {
    g[u].emplace_back(v, i, w);
    g[v].emplace_back(u, i++, w);
  }

  vector dp(1 << k, vector<T>(n, numeric_limits<T>::max()));
  vector pre(1 << k, vector<array<int, 2>>(n, {-1, -1}));

  for(unsigned x = 1; x < (1 << k); x++) {
    if (popcount(x) == 1) {
      dp[x][countr_zero(x)] = 0;
    } else {
      for(int r = 0; r < n; r++)
        for(int y = (x - 1) & x; y > 0; y = (y - 1) & x)
          if (T tmp = dp[y][r] + dp[x^y][r]; tmp < dp[x][r])
            dp[x][r] = tmp, pre[x][r] = {y, -1};
    }
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
    for(int r = 0; r < n; r++)
      pq.emplace(dp[x][r], r);
    while(!pq.empty()) {
      auto [d, v] = pq.top(); pq.pop();
      if (d != dp[x][v]) continue;
      for(auto [to, i, w] : g[v]) {
        if (d + w < dp[x][to]) {
          dp[x][to] = d + w, pre[x][to] = {v, i};
          pq.emplace(d + w, to);
        }
      }
    }
  }

  vector<bool> in_t(size(e));
  auto dfs = [&](int x, int r, auto &&self) -> void {
    auto [a, b] = pre[x][r];
    if (a == -1) return;
    if (b == -1) {
      self(a, r, self);
      self(x ^ a, r, self);
    } else {
      in_t[b] = true;
      self(x, a, self);
    }
  };

  int r = ranges::min_element(dp.back()) - dp.back().begin();
  dfs((1 << k) - 1, r, dfs);

  vector<int> t;
  for(int i = 0; i < ssize(e); i++)
    if (in_t[i])
      t.emplace_back(i);

  return make_pair(dp.back()[r], t);
}
