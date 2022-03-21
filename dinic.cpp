//////////////////////////////////////////////////
//template name: dinic
//author: __Shioko(Misuki)
//last update: 2021/11/04

struct Dinic {
  const static int N = 5001;
  struct Edge {
    int to, cap, rev;
    Edge(int _to, int _cap, int _rev) : to(_to), cap(_cap), rev(_rev) {}
  };
  vector<Edge> G[N];
  void addEdge(int from, int to, int cap) {
    G[from].emplace_back(Edge(to, cap, G[to].size()));
    G[to].emplace_back(Edge(from, 0, (int)G[from].size() - 1));
  }
  int n, s, t;
  void init(int _n, int _s, int _t) {
    n = _n, s = _s, t = _t;
    for(int i = 0; i < n; i++)
      G[i].clear();
  }
  int level[N], iter[N];
  void BFS() {
    fill(level, level + n, INT_MAX);
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
      int now = q.front(); q.pop();
      for(Edge &E : G[now]) {
        if (E.cap > 0 and level[E.to] == INT_MAX) {
          level[E.to] = level[now] + 1;
          q.push(E.to);
        }
      }
    }
  }
  int DFS(int V, int flow) {
    if (V == t)
      return flow;

    for(int &i = iter[V]; i < G[V].size(); i++) {
      Edge &E = G[V][i];
      if (level[E.to] == level[V] + 1 and E.cap > 0) {
        int tmp;
        if ((tmp = DFS(E.to, min(flow, E.cap))) > 0) {
          E.cap -= tmp, G[E.to][E.rev].cap += tmp;
          return tmp;
        }    
      } 
    }

    return 0;
  }

  int flow() {
    int res = 0;
    while(true) {
      BFS();
      if (level[t] == INT_MAX)
        break;
      fill(iter, iter + n, 0);
      int del;
      while((del = DFS(s, INT_MAX)) > 0) {
        res += del;
      }
    }

    return res;
  }
};
//////////////////////////////////////////////////
