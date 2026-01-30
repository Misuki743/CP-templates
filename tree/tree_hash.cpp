template<bool ordered = false>
pair<int, vector<int>> tree_hash(vector<vector<int>> &g, int root = 0) {
  int nxt = 0;
  static map<vector<int>, int> toId;
  vector<int> id(ssize(g));
  auto dfs = [&](int v, int p, auto self) -> int {
    vector<int> seq;
    seq.reserve(ssize(g[v]));
    for(int x : g[v]) if (x != p)
      seq.emplace_back(self(x, v, self));
    if constexpr (!ordered)
      ranges::sort(seq);
    if (!toId.contains(seq))
      toId[seq] = nxt++;
    return id[v] = toId[seq];
  };

  dfs(root, -1, dfs);

  return make_pair(nxt, id);
}
