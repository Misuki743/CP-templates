template<class M, M(*id)(), M(*op)(const M&, const M&)>
struct segmentTree {
  int size;
  vector<M> data;

  segmentTree(int _size) : size(_size), data(2 * size, id()) {}
  segmentTree(vector<M> init) : size(ssize(init)), data(2 * size, id()) {
    ranges::copy(init, data.begin() + size);
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

  int firstTrue(int l, int r, function<bool(const M&)> f) {
    vector<int> idL, idR;
    int r0 = r;
    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {
      if (l & 1) idL.emplace_back(l++);
      if (r & 1) idR.emplace_back(--r);
    }
    while(!idR.empty()) {
      idL.emplace_back(idR.back());
      idR.pop_back();
    }
    M pre = id();
    int v = -1;
    for(int i : idL) {
      if (f(op(pre, data[i]))) {
        v = i;
        break;
      } else {
        pre = op(pre, data[i]);
      }
    }
    if (v == -1)
      return r0;
    while(v < size) {
      if (f(op(pre, data[v << 1])))
        v = v << 1;
      else
        pre = op(pre, data[v << 1]), v = v << 1 | 1;
    }
    return v - size;
  }
};
