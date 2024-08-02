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

  //return first j in [i, size) s.t. f(op([l, j])) is true,
  //assume f(id()) is false.
  int firstTrue(int i, function<bool(const M&)> f) {
    vector<int> idL, idR;
    for(int l = i + size, r = size << 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) idL.emplace_back(l++);
      if (r & 1) idR.emplace_back(--r);
    }
    idL.insert(idL.end(), idR.rbegin(), idR.rend());
    M pre = id();
    int v = -1;
    for(int j : idL) {
      if (f(op(pre, data[j]))) {
        v = j;
        break;
      } else {
        pre = op(pre, data[j]);
      }
    }
    if (v == -1) return size;
    while(v < size) {
      if (f(op(pre, data[v << 1])))
        v = v << 1;
      else
        pre = op(pre, data[v << 1]), v = v << 1 | 1;
    }
    return v - size;
  }

  int lastTrue(int i, function<bool(const M&)> f) {
    vector<int> idL, idR;
    for(int l = size, r = (i + 1) + size; l < r; l >>= 1, r >>= 1) {
      if (l & 1) idL.emplace_back(l++);
      if (r & 1) idR.emplace_back(--r);
    }
    idR.insert(idR.end(), idL.rbegin(), idL.rend());
    M suf = id();
    int v = -1;
    for(int j : idR) {
      if (f(op(data[j], suf))) {
        v = j;
        break;
      } else {
        suf = op(data[j], suf);
      }
    }
    if (v == -1) return -1;
    while(v < size) {
      if (f(op(data[v << 1 | 1], suf)))
        v = v << 1 | 1;
      else
        suf = op(data[v << 1 | 1], suf), v = v << 1;
    }
    return v - size;
  }
};
