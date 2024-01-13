/**
 * template name: SCC
 * author: Misuki
 * last update: 2024/01/11
 * verify: Library Checker - Strongly Connected Components
 */

struct SCC {
  vector<int> groupId;
  vector<vector<int>> group, G;
  int size;

  SCC(vector<vector<int>> &g) : groupId(ssize(g)), size(0) {
    vector<vector<int>> gr(g.size());
    for(int u = 0; u < ssize(g); u++)
      for(int v : g[u])
        gr[v].emplace_back(u);

    int t = 0;
    vector<bool> vis(ssize(g), false);
    vector<int> tout(ssize(g));
    auto dfs = [&](int v, auto self) -> void {
      vis[v] = true;
      for(int x : gr[v])
        if (!vis[x])
          self(x, self);
      tout[t++] = v;
    };

    for(int v = 0; v < ssize(g); v++)
      if (!vis[v])
        dfs(v, dfs);

    auto dfs2 = [&](int v, auto self) -> void {
      vis[v] = true;
      for(int x : g[v])
        if (!vis[x])
          self(x, self);
      groupId[v] = size;
    };
    fill(vis.begin(), vis.end(), false);
    for(int v = ssize(g) - 1; v >= 0; v--) {
      if (!vis[tout[v]]) {
        dfs2(tout[v], dfs2);
        size += 1;
      }
    }

    for(int &x : groupId)
      x = size - x - 1;

    group.resize(size);
    for(int v = 0; v < ssize(g); v++)
      group[groupId[v]].emplace_back(v);

    G.resize(size);
    for(int v = 0; v < ssize(g); v++)
      for(int x : g[v])
        if (groupId[v] != groupId[x])
          G[groupId[v]].emplace_back(groupId[x]);
  }
};
