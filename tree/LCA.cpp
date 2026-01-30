//#include "ds/RMQ.cpp"

struct LCA {
  vector<int> dep, tin, tout, mp;
  RMQ<int> rmq;

  LCA(vector<vector<int>> g, int root = 0)
  : dep(size(g)), tin(size(g)), tout(size(g)), mp(size(g)), rmq(vector<int>(1)) {

    int t = 0;
    vector<int> init(2 * ssize(g) - 1);
    auto dfs = [&](int v, int p, auto &&self) -> void {
      init[t] = v;
      tin[v] = t++;
      for(int x : g[v]) {
        if (x == p) continue;
        dep[x] = dep[v] + 1;
        self(x, v, self);
        init[t++] = v;
      }
      tout[v] = t;
    };

    dfs(root, -1, dfs);

    vector<int> f(size(g));
    for(int x : dep) f[x]++;
    for(int i = 1; i < ssize(g); i++)
      f[i] += f[i - 1];
    vector<int> toOrd(size(g));
    for(int i = 0; i < ssize(g); i++) {
      toOrd[i] = --f[dep[i]];
      mp[f[dep[i]]] = i;
    }
    for(int &x : init) x = toOrd[x];
    rmq = RMQ(init);
  }

  int lca(int u, int v) {
    if (tin[u] > tin[v]) swap(u, v);
    return mp[rmq.query(tin[u], tout[v])];
  }

  int dis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
  }
};
