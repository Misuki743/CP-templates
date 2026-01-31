struct rollback_DSU {
  vi sz_par;
  vc<pii> his;
  int nxt;

  rollback_DSU(int n) : sz_par(n, -1), his(2 * (n - 1)), nxt(0) {}

  int query(int v) {
    int r = v;
    while(sz_par[r] >= 0) r = sz_par[r];
    return r;
  }

  bool merge(int v1, int v2) {
    int b1 = query(v1), b2 = query(v2);

    if (b1 == b2)
      return false;

    if (-sz_par[b1] > -sz_par[b2])
      swap(b1, b2);

    his[nxt++] = pair(b2, sz_par[b2]);
    his[nxt++] = pair(b1, sz_par[b1]);
    sz_par[b2] += sz_par[b1];
    sz_par[b1] = b2;

    return true;
  }

  int time() { return nxt; }
  int size(int v) { return -sz_par[query(v)]; }

  void rollback(int t) {
    chmin(t, nxt);
    for(auto [i, x] : views::counted(his.begin() + t, nxt - t)
                    | views::reverse)
      sz_par[i] = x;
    nxt = t;
  }
};
