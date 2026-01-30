template<class capT, class cosT>
struct MCMF {
  struct edge {
    int to, rev;
    capT cap;
    cosT cos;
    edge(int _to, capT _cap, cosT _cos, int _rev) :
        to(_to), rev(_rev), cap(_cap), cos(_cos) {}
  };

  int n;
  const capT CAP_MAX = numeric_limits<capT>::max();
  const cosT COS_MAX = numeric_limits<cosT>::max();
  vector<vector<edge>> g;
  vector<int> par, idx;
  vector<capT> f;
  vector<cosT> pot, dis;

  MCMF(int _n) : n(_n), g(n), par(n),
    idx(n), f(n), pot(n), dis(n) {}

  void addEdge(int from, int to, capT cap, cosT cos) {
    g[from].emplace_back(to, cap, cos, ssize(g[to]));
    g[to].emplace_back(from, 0, -cos, ssize(g[from]) - 1);
  }

  void initPotential(int s) {
    fill(dis.begin(), dis.end(), COS_MAX);
    dis[s] = 0;
    for(int i = 1; i < n; i++) {
      for(int v = 0; v < n; v++) {
        if (dis[v] == COS_MAX) continue;
        for(edge e : g[v])
          if (e.cap != 0 and dis[v] + e.cos < dis[e.to])
            dis[e.to] = dis[v] + e.cos;
      }
    }
    pot.swap(dis);
  }

  void initPotentialDAG(int s) {
    fill(dis.begin(), dis.end(), COS_MAX);
    dis[s] = 0;
    vector<int> topo = [&]() {
      vector<int> topo;
      vector<bool> vis(n, false);
      auto dfs = [&](int v, auto &&self) -> void {
        vis[v] = true;
        for(edge e : g[v])
          if (e.cap != 0 and !vis[e.to])
            self(e.to, self);
        topo.emplace_back(v);
      };
      for(int v = 0; v < n; v++)
        if (!vis[v])
          dfs(v, dfs);
      return topo;
    }();
    for(int v : topo | views::reverse)
      if (dis[v] != COS_MAX)
        for(edge e : g[v])
          if (e.cap != 0)
            chmin(dis[e.to], dis[v] + e.cos);
    pot.swap(dis);
  }

  pair<capT, cosT> runFlow(int s, int t, bool dense = false) {
    cosT cost = 0;
    capT flow = 0;
    while(true) {
      fill(dis.begin(), dis.end(), COS_MAX);
      dis[s] = 0, f[s] = CAP_MAX;
      if (dense) {
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++) {
          int v = -1;
          for(int j = 0; j < n; j++)
            if (!vis[j] and (v == -1 or dis[j] < dis[v]))
              v = j;
          if (v == -1 or dis[v] == COS_MAX) break;
          vis[v] = true;
          for(edge e : g[v]) {
            if (e.cap == 0) continue;
            if (cosT x = dis[v] + e.cos + pot[v] - pot[e.to]; x < dis[e.to]) {
              dis[e.to] = x, f[e.to] = min(f[v], e.cap);
              par[e.to] = v, idx[e.to] = g[e.to][e.rev].rev;
            }
          }
        }
      } else {
        using T = pair<cosT, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push(make_pair(dis[s], s));
        while(!pq.empty()) {
          auto [d, v] = pq.top(); pq.pop();
          if (dis[v] != d) continue;
          for(edge e : g[v]) {
            if (e.cap == 0) continue;
            if (cosT x = dis[v] + e.cos + pot[v] - pot[e.to]; x < dis[e.to]) {
              dis[e.to] = x, f[e.to] = min(f[v], e.cap);
              par[e.to] = v, idx[e.to] = g[e.to][e.rev].rev;
              pq.push(make_pair(dis[e.to], e.to));
            }
          }
        }
      }

      if (dis[t] == COS_MAX) break;

      int v = t;
      while(v != s) {
        edge &e = g[par[v]][idx[v]];
        e.cap -= f[t], g[v][e.rev].cap += f[t];
        v = par[v];
      }
      flow += f[t], cost += f[t] * (dis[t] - pot[s] + pot[t]);
      for(int i = 0; i < n; i++)
        if (dis[i] != COS_MAX)
          dis[i] += pot[i] - pot[s];
      pot.swap(dis);
    }

    return {flow, cost};
  }
};
