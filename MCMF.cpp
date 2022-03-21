//////////////////////////////////////////////////
//template name: MCMF
//author: __Shioko(Misuki)
//last update: 2021/11/11
struct MCMF {
  struct Edge {
    int to, rev;
    long long cap, cos;
    Edge(int _to, long long _cap, long long _cos, int _rev) :
        to(_to), cap(_cap), cos(_cos), rev(_rev) {}
  };

  static const int SIZE = 3502;
  int n, s, t;
  vector<Edge> G[SIZE];
  array<int, SIZE> par, idx;
  array<long long, SIZE> pot, dis, f; 

  void init(int _n, int _s, int _t) {
    n = _n, s = _s, t = _t;
    for(int i = 0; i < n; i++)
      G[i].clear();
  }

  void addEdge(int from, int to, long long cap, long long cos) {
    G[from].emplace_back(Edge(to, cap, cos, G[to].size()));
    G[to].emplace_back(Edge(from, 0, -cos, (int)G[from].size() - 1));
  }

  void initPotential() {
    fill(dis.begin(), dis.end(), LLONG_MAX);
    dis[s] = 0;
    for(int i = 1; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if (dis[j] == LLONG_MAX)
          continue;
        for(Edge E : G[j]) {
          if (E.cap == 0)
            continue;
          if (dis[j] + E.cos < dis[E.to])
            dis[E.to] = dis[j] + E.cos;
        }
      }
    }
    pot.swap(dis);
  }

  pll flow() {
    long long Cost = 0, Flow = 0;
    while(true) {
      priority_queue<pii, vector<pii>, greater<pii> > pq;
      fill(dis.begin(), dis.end(), LLONG_MAX);
      dis[s] = 0, f[s] = LLONG_MAX;
      pq.push(make_pair(0, s));
      while(!pq.empty()) {
        pii now = pq.top(); pq.pop();
        if (dis[now.second] != now.first)
          continue;

        int V = now.second;
        for(Edge E : G[V]) {
          if (E.cap == 0)
            continue;
          if (dis[V] + E.cos + pot[V] - pot[E.to] < dis[E.to]) {
            dis[E.to] = dis[V] + E.cos + pot[V] - pot[E.to];
            f[E.to] = min(f[V], E.cap);
            par[E.to] = V;
            idx[E.to] = G[E.to][E.rev].rev;
            pq.push(make_pair(dis[E.to], E.to));
          }
        }
      }

      if (dis[t] == LLONG_MAX)
        break;

      long long bot = f[t];
      int now = t;
      while(now != s) {
        Edge &E = G[par[now]][idx[now]];
        E.cap -= bot;
        G[now][E.rev].cap += bot;
        now = par[now];
      }
      Flow += bot, Cost += bot * (dis[t] - pot[s] + pot[t]);

      for(int i = 0; i < n; i++) {
        dis[i] += pot[i] - pot[s];
      }
      pot.swap(dis);
    }

    return make_pair(Flow, Cost);
  }
};
//////////////////////////////////////////////////
