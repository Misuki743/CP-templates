template<class T>
struct Dinic {
  struct edge {
    int to, rev;
    T cap;
    edge(int _to, T _cap, int _rev)
     : to(_to), rev(_rev), cap(_cap) {}
  };

  int n;
  const T CAP_MAX = numeric_limits<T>::max();
  vector<vector<edge>> g;
  vector<int> lev, iter;

  Dinic(int _n) : n(_n), g(n), lev(n), iter(n) {}

  void addEdge(int from, int to, T cap) {
    g[from].emplace_back(to, cap, ssize(g[to]));
    g[to].emplace_back(from, 0, ssize(g[from]) - 1);
  }

  bool bfs(int s, int t) {
    fill(lev.begin(), lev.end(), INT_MAX);
    lev[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
      int v = q.front(); q.pop();
      for(edge &e : g[v]) if (e.cap > 0 and lev[e.to] == INT_MAX) {
        lev[e.to] = lev[v] + 1;
        q.push(e.to);
      }
    }
    return lev[t] != INT_MAX;
  }

  T runFlow(int s, int t) {
    auto dfs = [&](int v, T f, auto &&self) -> T {
      if (v == s) return f;
      for(int &i = iter[v]; i < ssize(g[v]); i++) {
        edge &e = g[v][i];
        if (T tmp; lev[e.to] == lev[v] - 1 and g[e.to][e.rev].cap > 0) {
          if ((tmp = self(e.to, min(f, g[e.to][e.rev].cap), self)) > 0) {
            e.cap += tmp, g[e.to][e.rev].cap -= tmp;
            return tmp;
          }
        }
      }
      return 0;
    };
    T flow = 0, del;
    while(bfs(s, t)) {
      fill(iter.begin(), iter.end(), 0);
      while((del = dfs(t, CAP_MAX, dfs)) > 0)
        flow = (flow >= CAP_MAX - del ? CAP_MAX : flow + del);
    }

    return flow;
  }

  bool left(int idx) { return lev[idx] != INT_MAX; }
};
