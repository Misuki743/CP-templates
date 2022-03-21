//////////////////////////////////////////////////
//template name: HLD
//author: __Shioko(Misuki)
//last update: 2022/02/01

const int MAXN = 200000;
vector<int> G[MAXN];
int mxChild[MAXN], dep[MAXN], sz[MAXN], fa[MAXN];
int head[MAXN], idx[MAXN];

struct HLD {
  void addEdge(int u, int v) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void build() {
    for(int i = 0; i < MAXN; i++)
      mxChild[i] = dep[i] = sz[i] = fa[i] = head[i] = idx[i] = 0;
    DFS(0, -1);
    cut(0, 0);
  }

  void DFS(int V, int P) {
    sz[V] = 1;
    for(int X : G[V]) {
      if (X != P) {
        fa[X] = V, dep[X] = dep[V] + 1;
        DFS(X, V);
        sz[V] += sz[X];
        if (mxChild[V] == 0 or sz[X] > sz[mxChild[V]])
          mxChild[V] = X;
      }
    }
  }

  int t;
  void cut(int V, int H) {
    idx[V] = t++, head[V] = H;
    if (mxChild[V] == 0)
      return;

    cut(mxChild[V], H);
    for(int X : G[V]) 
      if (X != mxChild[V] and X != fa[V])
        cut(X, X);
  }

  vector<pii> query(int u, int v) {
    vector<pii> res;
    while(head[u] != head[v]) {
      if (dep[head[u]] > dep[head[v]])
        swap(u, v);
      res.emplace_back(idx[head[v]], idx[v]);
      v = fa[head[v]];
    }
    if (idx[u] > idx[v])
      swap(u, v);
    res.emplace_back(idx[u], idx[v]);

    return res;
  }
};
//////////////////////////////////////////////////
