template<class M, M(*id)(), M(*op)(const M&, const M&)>
struct DSU {
  int size;
  vector<int> bos, sz;
  vector<M> data;

  DSU(vector<M> init) : size(init.size()), bos(size), sz(size, 1), data(init) {
    iota(bos.begin(), bos.end(), 0);
  }
  DSU(int _size) : size(_size), bos(size), sz(size, 1), data(size, id()) {
    iota(bos.begin(), bos.end(), 0);
  }

  int query(int v) {
    if (bos[v] == v)
      return v;
    else
      return bos[v] = query(bos[v]);
  }

  bool merge(int v1, int v2) {
    int b1 = query(v1), b2 = query(v2);

    if (b1 == b2)
      return false;

    if (sz[b1] > sz[b2])
      swap(b1, b2);
    bos[b1] = b2, sz[b2] += sz[b1];
    data[b2] = op(data[b1], data[b2]);

    return true;
  }

  M get(int v) { return data[query(v)]; }
};
