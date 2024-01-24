//#include<graph/hopcroftKarp.cpp>

array<vector<int>, 2> MVC(vector<vi> &g, vi& btoa) {
  int n1 = sz(g), n2 = sz(btoa);
  vector<bool> ml(n1, false);
  for(int i = 0; i < n2; i++)
    if (btoa[i] != -1)
      ml[btoa[i]] = true;

  vector<bool> vis(n1 + n2, false);
  vector<vector<int>> g2(n1 + n2);
  for(int u = 0; u < n1; u++) {
    for(int v : g[u]) {
      if (btoa[v] == u)
        g2[v + n1].emplace_back(u);
      else
        g2[u].emplace_back(v + n1);
    }
  }
  auto dfs = [&](int v, auto self) -> void {
    vis[v] = true;
    for(int x : g2[v])
      if (!vis[x])
        self(x, self);
  };
  for(int i = 0; i < n1; i++)
    if (!ml[i] and !vis[i])
      dfs(i, dfs);

  array<vector<int>, 2> vc;
  for(int i = 0; i < n1; i++)
    if (!vis[i])
      vc[0].push_back(i);
  for(int i = 0; i < n2; i++)
    if (vis[i + n1])
      vc[1].push_back(i);

  return vc;
}
