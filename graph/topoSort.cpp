vector<int> topoSort(vector<vector<int>> g) {
  int n = ssize(g);
  vector<int> deg(n);
  for(auto &e : g)
    for(int x : e)
      deg[x]++;
  vector<int> topo;
  topo.reserve(n);
  for(int i = 0; i < n; i++)
    if (deg[i] == 0)
      topo.emplace_back(i);
  for(int i = 0; i < ssize(topo); i++)
    for(int x : g[topo[i]])
      if (--deg[x] == 0)
        topo.emplace_back(x);
  return ssize(topo) != n ? vector<int>() : topo;
}
