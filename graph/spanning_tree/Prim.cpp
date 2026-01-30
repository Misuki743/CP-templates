template<class T>
pair<T, vector<int>> Prim(vector<array<T, 3>> &e, int n) {
  vector id(n, vector<int>(n, -1));
  for(int i = 0; auto [u, v, w] : e) {
    if (id[u][v] == -1 or w < e[id[u][v]][2])
      id[u][v] = id[v][u] = i;
    i++;
  }

  T cost = 0;
  vector<bool> inT(n, false);
  vector<int> eid, mn = id[0];
  inT[0] = true;
  for(int i = 0; i < n - 1; i++) {
    int v = -1;
    for(int x = 0; x < n; x++)
      if (!inT[x] and mn[x] != -1 and (v == -1 or e[mn[x]][2] < e[mn[v]][2]))
        v = x;
    if (v == -1) break;
    inT[v] = true, cost += e[mn[v]][2];
    eid.emplace_back(mn[v]);
    for(int x = 0; x < n; x++)
      if (id[v][x] != -1 and (mn[x] == -1 or e[id[v][x]][2] < e[mn[x]][2]))
        mn[x] = id[v][x];
  }

  if (ssize(eid) == n - 1)
    return make_pair(cost, eid);
  else
    return make_pair(numeric_limits<T>::max(), vector<int>());
}
