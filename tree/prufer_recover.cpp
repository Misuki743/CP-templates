//empty vector would be assumed to be n = 2
vector<pii> prufer_recover(vector<int> prufer_code) {
  const int n = ssize(prufer_code) + 2;
  assert(prufer_code.empty() or (ranges::min(prufer_code) >= 0 and ranges::max(prufer_code) < n));
  vector<int> d(n, 1);
  for(int x : prufer_code) d[x]++;
  min_heap<int> leaf;
  for(int v = 0; v < n; v++)
    if (d[v] == 1)
      leaf.emplace(v);
  vector<pii> edges;
  for(int x : prufer_code) {
    int v = leaf.top(); leaf.pop();
    edges.emplace_back(v, x);
    if (--d[x] == 1)
      leaf.emplace(x);
  }
  int v = leaf.top(); leaf.pop();
  edges.emplace_back(v, leaf.top());
  return edges;
}
