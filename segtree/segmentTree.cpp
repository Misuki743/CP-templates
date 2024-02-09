template<class M, M(*id)(), M(*op)(const M&, const M&)>
struct segmentTree {
  vector<M> data;
  int size;

  segmentTree(int _size) : data(2 * _size, id()), size(_size) {}

  segmentTree(vector<M> init) : data(2 * ssize(init), id()), size(ssize(init)) {
    copy(init.begin(), init.end(), data.begin() + size);
    for(int i = size - 1; i > 0; i--)
      data[i] = op(data[i << 1], data[i << 1 | 1]);
  }

  void set(int i, M x) {
    data[i += size] = x;
    while(i >>= 1)
      data[i] = op(data[i << 1], data[i << 1 | 1]);
  }

  M get(int i) { return data[i + size]; }

  M query(int l, int r) {
    M L = id(), R = id();
    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {
      if (l & 1) L = op(L, data[l++]);
      if (r & 1) R = op(data[--r], R);
    }
    return op(L, R);
  }
};
