struct bipartite_DSU {
  vi sz_par;
  vc<bool> d;

  bipartite_DSU(int n) : sz_par(n, -1), d(n, false) {}

  int query(int v) {
    int r = v, sum = 0;
    while(sz_par[r] >= 0)
      sum ^= d[r], r = sz_par[r];
    while(v != r) {
      int nxt = sz_par[v], tmp = d[v];
      d[v] = sum, sum ^= tmp;
      sz_par[v] = r, v = nxt;
    }
    return r;
  }

  bool merge(int v1, int v2, bool diff) {
    int b1 = query(v1), b2 = query(v2);

    if (b1 == b2)
      return (d[v1] ^ d[v2]) == diff;

    if (-sz_par[b1] > -sz_par[b2])
      swap(b1, b2);

    d[b1] = d[v1] ^ d[v2] ^ diff;
    sz_par[b2] += sz_par[b1];
    sz_par[b1] = b2;

    return true;
  }

  int size(int v) { return v = query(v), -sz_par[v]; }
  bool color(int v) { return query(v), d[v]; }
};
