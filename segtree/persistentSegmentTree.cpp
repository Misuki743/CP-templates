template<class M, M(*id)(), M(*op)(const M&, const M&)>
struct persistentSegmentTree {
  vector<int> lc, rc;
  vector<M> data, init;
  int nxt = 0;

  //sz >= (2n - 1) + q * (bit_width(n) + 1) should be satisfied
  persistentSegmentTree(int sz, vector<M> _init = vector<M>())
  : lc(sz, -1), rc(sz, -1), data(sz, id()), init(_init) {}

  int build(int l, int r) {
    int i = nxt++;
    if (l + 1 == r) {
      if (!init.empty()) data[i] = init[l];
    } else {
      int mid = (l + r) / 2;
      lc[i] = build(l, mid), rc[i] = build(mid, r);
      data[i] = op(data[lc[i]], data[rc[i]]);
    }
    return i;
  }

  int set(int v, int l, int r, int i, M x) {  
    int vv = nxt++;
    if (l + 1 == r) {
      data[vv] = x;
    } else {
      if (int mid = (l + r) / 2; i < mid)
        lc[vv] = set(lc[v], l, mid, i, x), rc[vv] = rc[v];
      else
        lc[vv] = lc[v], rc[vv] = set(rc[v], mid, r, i, x);
      data[vv] = op(data[lc[vv]], data[rc[vv]]);
    }
    return vv;
  }

  M query(int i, int l, int r, int ql, int qr) {
    if (ql == qr or i == -1 or r <= ql or l >= qr) return id();
    if (ql <= l and r <= qr) return data[i];
    return op(query(lc[i], l, (l + r) / 2, ql, qr), 
              query(rc[i], (l + r) / 2, r, ql, qr));
  }
};
