//number of unlabel rooted tree (1-based)
//1, 1, 2, 4, 9,
//20, 48, 115, 286, 719,
//1842, 4766, 12486, 32973, 87811,
//235381, 634847, 1721159, 4688676, 12826228,
//35221832, 97055181, 268282855, 743724984, 2067174645

//root is 0
template<typename F>
requires invocable<F, vector<vector<int>>>
void enumerate_unlabel_rooted_tree(int n, F f) {
  const int LIM = 25;
  assert(0 < n and n <= LIM);

  vector hash(1, array<int, LIM>{-1});
  array<int, LIM + 2> st;
  fill(st.begin(), st.end(), INT_MAX);
  st[0] = -1, st[1] = 0;

  auto size = [&](int id) {
    int r = 1;
    while(st[r] <= id) r++;
    return r - 1;
  };

  for(int m = 2; m <= n; m++) {
    st[m] = ssize(hash);
    array<int, LIM> h;
    int nxt = 0;
    auto dfs = [&](int pre_id, int sum, auto &self) -> void {
      if (sum == 0) {
        h[nxt++] = -1;
        hash.emplace_back(h);
        nxt--;
      } else {
        for(int x = min(pre_id, st[sum + 1] - 1); x >= 0; x--) {
          h[nxt++] = x;
          self(x, sum - size(x), self);
          nxt--;
        }
      }
    };
    dfs(INT_MAX, m - 1, dfs);
  }
  st[n + 1] = ssize(hash);

  for(int id = st[n]; id < st[n + 1]; id++) {
    vector<vector<int>> g(n);
    int nxt = 0;
    auto dfs = [&](int v, int id, auto &self) -> void {
      if (id == 0) return;
      for(int i = 0; hash[id][i] != -1; i++) {
        g[v].emplace_back(nxt), g[nxt].emplace_back(v);
        self(nxt++, hash[id][i], self);
      }
    };
    dfs(nxt++, id, dfs);
    f(g);
  }
}
