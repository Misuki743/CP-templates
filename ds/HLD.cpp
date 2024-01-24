const int MAXN = 200000;
vector<int> G[MAXN];
int mxChild[MAXN], dep[MAXN], sz[MAXN], fa[MAXN];
int head[MAXN], idx[MAXN];
//int tout[MAXN];
//for subtree query/modify

struct HLD {
  void addEdge(int u, int v) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void build(vector<int> root = vector<int>(1, 0)) {
    fill(mxChild, mxChild + MAXN, -1);
    fill(fa, fa + MAXN, -1);
    for(int X : root) {
      DFS(X, -1);
      cut(X, X);
    }
  }

  void DFS(int V, int P) {
    sz[V] = 1;
    for(int X : G[V]) {
      if (X != P) {
        fa[X] = V, dep[X] = dep[V] + 1;
        DFS(X, V);
        sz[V] += sz[X];
        if (mxChild[V] == -1 or sz[X] > sz[mxChild[V]])
          mxChild[V] = X;
      }
    }
  }

  int t = 0;
  void cut(int V, int H) {
    idx[V] = t++, head[V] = H;
    if (mxChild[V] == -1)
      return;

    cut(mxChild[V], H);
    for(int X : G[V]) 
      if (X != mxChild[V] and X != fa[V])
        cut(X, X);
  }

  vector<pii> query(int u, int v, bool edge = false) {
    vector<pii> res;
    while(head[u] != head[v]) {
      if (dep[head[u]] > dep[head[v]])
        swap(u, v);
      res.emplace_back(idx[head[v]], idx[v]);
      v = fa[head[v]];
    }
    if (idx[u] > idx[v])
      swap(u, v);
    if (idx[u] + edge <= idx[v])
      res.emplace_back(idx[u] + edge, idx[v]);

    return res;
  }

  int LCA(int u, int v) {
    while(head[u] != head[v]) {
      if (dep[head[u]] > dep[head[v]])
        swap(u, v);
      v = fa[head[v]];
    }
    return dep[u] > dep[v] ? v : u;
  }
};
