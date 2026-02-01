template<bool ordered = false>
auto tree_hash(vvi &g, int root = 0) {
  int nxt = 0;
  static map<vi, int> seq_to_id;
  vi subtree_id(size(g));
  auto dfs = [&](int v, int p, auto self) -> int {
    vi seq;
    seq.reserve(ssize(g[v]));
    for(int x : g[v]) if (x != p)
      seq.emplace_back(self(x, v, self));
    if constexpr (!ordered)
      ranges::sort(seq);
    if (!seq_to_id.contains(seq))
      seq_to_id[seq] = nxt++;
    return subtree_id[v] = seq_to_id[seq];
  };

  dfs(root, -1, dfs);

  return pair(nxt, subtree_id);
}
