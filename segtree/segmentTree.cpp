/**
 * template name: segmentTree
 * author: Misuki
 * last update: 2024/01/01
 * verify: library checker - Point Add Range Sum, Static RMQ
 */

template<class M, M(*unit)(), M(*combine)(const M&, const M&)>
struct segmentTree {
  vector<M> data;
  int size;

  segmentTree(int _size) : data(2 * _size, unit()), size(_size) {}

  segmentTree(vector<M> init) : data(2 * ssize(init), unit()), size(ssize(init)) {
    copy(init.begin(), init.end(), data.begin() + size);
    for(int i = size - 1; i > 0; i--)
      data[i] = combine(data[i << 1], data[i << 1 | 1]);
  }

  void set(int i, M x) {
    data[i += size] = x;
    while(i >>= 1)
      data[i] = combine(data[i << 1], data[i << 1 | 1]);
  }

  M get(int i) { return data[i + size]; }

  M query(int l, int r) {
    M L = unit(), R = unit();
    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {
      if (l & 1) L = combine(L, data[l++]);
      if (r & 1) R = combine(data[--r], R);
    }
    return combine(L, R);
  }
};
