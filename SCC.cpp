//////////////////////////////////////////////////
//template name: SCC
//author: __Shioko(Misuki)
//last update: 2023/01/07
//verify: Library Checker - Strongly Connected Components

struct SCC {
  int sz;
  vector<int> group_id;
  vector<vector<int>> group;
  vector<vector<int>> G;

  SCC(vector<vector<int>> &g) : group_id(g.size()), sz(0) {
    vector<vector<int>> gr(g.size());
    for(int i = 0; i < g.size(); i++)
      for(int X : g[i])
        gr[X].emplace_back(i);

    int t = 0;
    vector<bool> vis(g.size(), false);
    vector<int> tout(g.size());
    auto dfs = [&](int V, auto self) -> void {
      vis[V] = true;
      for(int X : gr[V])
        if (!vis[X])
          self(X, self);
      tout[t++] = V;
    };

    for(int i = 0; i < g.size(); i++)
      if (!vis[i])
        dfs(i, dfs);

    auto dfs2 = [&](int V, auto self) -> void {
      vis[V] = true;
      for(int X : g[V])
        if (!vis[X])
          self(X, self);
      group_id[V] = sz;
    };
    for(int i = 0; i < g.size(); i++)
      vis[i] = false;
    for(int i = (int)g.size() - 1; i >= 0; i--) {
      if (!vis[tout[i]]) {
        dfs2(tout[i], dfs2);
        sz += 1;
      }
    }

    for(int i = 0; i < g.size(); i++)
      group_id[i] = sz - 1 - group_id[i];

    group.resize(sz);
    for(int i = 0; i < g.size(); i++)
      group[group_id[i]].emplace_back(i);

    G.resize(sz);
    for(int i = 0; i < g.size(); i++)
      for(int X : g[i])
        if (group_id[i] != group_id[X])
          G[group_id[i]].emplace_back(group_id[X]);
  }
};
//////////////////////////////////////////////////
